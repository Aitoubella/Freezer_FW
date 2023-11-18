
/*
 * main_app.c
 *
 */


#include "lcd_interface.h"
#include "lcd_ui.h"
#include "DS1307.h"
#include "RTD.h"
#include <stdbool.h>
#include "flash.h"
#include "event.h"
event_id main_app_id;
#define MAIN_TASK_TICK_MS    100 //ms
#define BAT_OUT_OF_VALUE     7 //in perent
#define MINUTE_TO_COUNT(x) (x*60*1000/MAIN_TASK_TICK_MS) //convert minute to tick count in main task

lcd_inter_t setting = {
	.op_mode = OPERATION_MODE_FREEZER,
	.pwr_mode = POWER_MODE_AC,
	.spk_mode = SPEAKER_MODE_ON,
	.bat_value = 100, //%
	.bat_state = BATTERY_STATE_NOT_CHARGE,
	.bat_signal = BATTER_WARNING_LOW,
	.alarm_bat = 15, //%
	.alarm_lid = 2,  //mins
	.alarm_temperature_delay = 3, //mins
	.alarm_temperature_deviation = 5, // Celcius
	.temperature = 31,//Celcius
	.logging_interval = 5,//Mins
	.temperature_fridge = 31,//Celcius
	.temperature_freezer = 31,//Celcius
	.temp_offset = 0, //Celcius
	.datetime.year = 2023,
	.datetime.month = 11,
	.datetime.day = 3,
};
extern lcd_inter_t lcd;

typedef enum
{
	NONE_SAVE_STATE = 0,
	CHANGE_DATA_STATE,
	NEED_SAVE_STATE,
}save_state_t;
save_state_t save_state = NONE_SAVE_STATE;
uint8_t lcd_get_set_cb(lcd_get_set_evt_t evt, void* value)
{

	switch((uint8_t)evt)
	{
	   case LCD_SET_OPERATION_MODE_EVT:
		   if(setting.op_mode != *((operation_mode_t *)value))
		   {
			   save_state = CHANGE_DATA_STATE;
			   setting.op_mode = *((operation_mode_t *)value);
		   }
		   break;
		case LCD_SET_DATETIME_EVT:
			datetime_t* dt = (datetime_t *)value;
			//Check save data to DS1307 ok
			if((DS1307_SetDate(dt->day, dt->month, dt->year) == HAL_OK) &&
				(DS1307_SetTime(dt->hour, dt->minute, dt->second) == HAL_OK))
			{
				memcpy((uint8_t *)&setting.datetime,(uint8_t *)dt,sizeof(datetime_t));
			}

			break;

		case LCD_SET_TEMPERATURE_FRIDGE_EVT:
			if(setting.temperature_fridge != *((int8_t *)value))
			{
				 save_state = CHANGE_DATA_STATE;
				setting.temperature_fridge = *((int8_t *)value);
			}
			break;

		case LCD_SET_TEMPERATURE_FREEZER_EVT:
			if(setting.temperature_freezer != *((int8_t *)value))
			{
				 save_state = CHANGE_DATA_STATE;
				setting.temperature_freezer = *((int8_t *)value);
			}
			break;

		case LCD_SET_ALARM_TEMPERATURE_DEVIATION_EVT:
			if(setting.alarm_temperature_deviation != *((int8_t *)value))
			{
				 save_state = CHANGE_DATA_STATE;
				setting.alarm_temperature_deviation = *((int8_t *)value);
			}

			break;

		case LCD_SET_ALARM_TEMPERATURE_DELAY_EVT:
			if(setting.alarm_temperature_delay != *((uint8_t *)value))
			{
				 save_state = CHANGE_DATA_STATE;
				setting.alarm_temperature_delay = *((uint8_t *)value);
			}
			break;

		case LCD_SET_ALARM_BAT_EVT:
			if(setting.alarm_bat != *((uint8_t *)value))
			{
				 save_state = CHANGE_DATA_STATE;
				setting.alarm_bat = *((uint8_t *)value);
			}

			break;

		case LCD_SET_ALARM_LID_EVT:
			if(setting.alarm_lid != *((uint8_t *)value))
			{
				save_state = CHANGE_DATA_STATE;
				setting.alarm_lid = *((uint8_t *)value);
			}

			break;

		case LCD_SET_LOGGING_INTERVAL_EVT:
			if(setting.logging_interval != *((uint8_t *)value))
			{
				 save_state = CHANGE_DATA_STATE;
				setting.logging_interval = *((uint8_t *)value);
			}

			break;

		case LCD_SET_TEMP_OFFSET_EVT:
			if(setting.temp_offset != *((uint8_t *)value))
			{
				 save_state = CHANGE_DATA_STATE;
				setting.temp_offset = *((uint8_t *)value);
			}
			break;
		case LCD_SET_LARM_MUTE_DURATION_EVT:
			if(setting.alarm_mute_duration != *((uint8_t *)value))
			{
				 save_state = CHANGE_DATA_STATE;
				setting.alarm_mute_duration = *((uint8_t *)value);
			}
			break;

		case LCD_USB_INSERT_DOWNLOAD_EVT:
			return 1;
			break;
		case LCD_MAIN_FRAME_EVT:
			if(save_state == CHANGE_DATA_STATE)
			{
				save_state = NEED_SAVE_STATE;
			}
			break;
	}
	if(save_state == NEED_SAVE_STATE)// setting param change?
	{
		__disable_irq(); //Disable all global interrupt to save data safety
		flash_mgt_save((uint32_t *)&setting, sizeof(lcd_inter_t)); //Save setting to flash if any change
		__enable_irq(); //Enable all global interrupt
		save_state = NONE_SAVE_STATE;
	}
	return 1;
}

uint8_t get_bat_value(void)
{
	return 100;
}

battery_state_t get_bat_state(void)
{
	return BATTERY_STATE_CHARGING;
}

power_mode_t get_power_mode(void)
{
	return POWER_MODE_DC;
}

typedef enum
{
	LID_CLOSE_STATE = 0,
	LID_OPEN_STATE,
}lid_state_t;

lid_state_t get_lid_state(void)
{
	return LID_CLOSE_STATE;
}

typedef struct
{
	uint32_t under_min_temp;
	uint32_t over_max_temp;
	uint32_t lid_open;
}alarm_count_t;
alarm_count_t alarm_count;


typedef enum
{
	MAIN_NORMAL_STATE = 0,
	MAIN_WARNING_LID_OPEN_STATE,
	MAIN_WARNING_UNDER_MINTEMP_STATE,
	MAIN_WARNING_OVER_MAXTEMP_STATE,
	MAIN_WARNING_WAITING_STATE,
}main_state_t;

main_state_t main_state = MAIN_NORMAL_STATE;

void main_task(void)
{
	static lcd_inter_t* lcd_param;
	static lcd_state_t lcd_state;
	lcd_state = lcd_interface_get_state();
	//Get temperature with temperature offset from setting
	setting.temperature = (int16_t) (rtd_get_temperature(RTD6)) + setting.temp_offset;
	//Get bat status
	setting.bat_value = get_bat_value();
	setting.bat_state = get_bat_state();
	//Get power status
	setting.pwr_mode = get_power_mode();


	//Check exeed temperature setting
	if(setting.op_mode == OPERATION_MODE_FRIDEGE)
	{
		if(setting.temperature <= (setting.temperature_fridge - setting.alarm_temperature_deviation))    //Check under min temperature
		{
			//Increase count for delay check later
			alarm_count.under_min_temp += 1;

		}else if(setting.temperature >= (setting.temperature_fridge + setting.alarm_temperature_deviation))//Check over max temperature
		{
			//Increase count for delay check later
			alarm_count.over_max_temp += 1;
		}else
		{
			alarm_count.over_max_temp = 0;
			alarm_count.under_min_temp = 0;
		}
	}else if(setting.op_mode == OPERATION_MODE_FREEZER)
	{
		if(setting.temperature <= (setting.temperature_freezer - setting.alarm_temperature_deviation))   //Check under min temperature
		{
			//Increase count for delay check later
			alarm_count.under_min_temp += 1;
		}else if (setting.temperature >= (setting.temperature_freezer + setting.alarm_temperature_deviation))   //Check over max temperature
        {
			//Increase count for delay check later
			alarm_count.over_max_temp += 1;
        }else
        {
        	alarm_count.over_max_temp = 0;
			alarm_count.under_min_temp = 0;
        }
	}
	//Lid check
	if(get_lid_state() == LID_OPEN_STATE)
	{
		//Increase count for delay check later
		alarm_count.lid_open += 1;
	}else
	{
		alarm_count.lid_open = 0;
	}



	//Check bat value in percent
	if(setting.bat_value <= BAT_OUT_OF_VALUE)
	{
		setting.bat_signal = BATTERY_OUT_OF_BAT;
	}else if(setting.bat_value <= setting.alarm_bat)
	{
		setting.bat_signal = BATTER_WARNING_LOW;

	}else
	{
		setting.bat_signal = BATTERY_NORMAL;
	}



	if(lcd_state == LCD_MAIN_STATE)
	{
		switch((uint8_t)main_state)
		{
			case MAIN_NORMAL_STATE:
			    //Check current value is differ from lcd value -> update lcd
				lcd_param =  lcd_interface_get_param();
				if(lcd_param->op_mode != setting.op_mode || lcd_param->pwr_mode != setting.pwr_mode
				  || lcd_param->temperature != setting.temperature || lcd_param->bat_state != setting.bat_state
				  || lcd_param->bat_value != setting.bat_value || lcd_param->spk_mode != setting.spk_mode
				  || lcd_param->bat_signal != setting.bat_signal)
				{
					//Update lcd main frame
					lcd_param->op_mode = setting.op_mode;
					lcd_param->pwr_mode = setting.pwr_mode;
					lcd_param->temperature = setting.temperature;
					lcd_param->bat_state = setting.bat_state;
					lcd_param->bat_value = setting.bat_value;
					lcd_param->spk_mode = setting.spk_mode;
					lcd_param->bat_signal = setting.bat_signal;
					//Reload main frame
					lcd_ui_clear();
					lcd_interface_show(lcd_state);
					lcd_ui_refresh();
				}
				//Change state warning
				if(alarm_count.lid_open >= MINUTE_TO_COUNT(setting.alarm_lid)) //Warning lid higher priority
				{
					main_state = MAIN_WARNING_LID_OPEN_STATE;
				}else if(alarm_count.over_max_temp >= MINUTE_TO_COUNT(setting.alarm_temperature_delay))
				{
					main_state = MAIN_WARNING_OVER_MAXTEMP_STATE;
				}else if(alarm_count.under_min_temp >= MINUTE_TO_COUNT(setting.alarm_temperature_delay))
				{
					main_state = MAIN_WARNING_UNDER_MINTEMP_STATE;
				}
			break;
			case MAIN_WARNING_LID_OPEN_STATE:
				main_state = MAIN_WARNING_WAITING_STATE;
				lcd_ui_clear();
				lcd_interface_show(LCD_WARNING_TYPE_LID_OPEN_STATE);
				lcd_ui_refresh();
				break;
			case MAIN_WARNING_UNDER_MINTEMP_STATE:
				main_state = MAIN_WARNING_WAITING_STATE;
				lcd_ui_clear();
				lcd_interface_show(LCD_WARNING_TYPE_UNDER_MIN_TEMP_STATE);
				lcd_ui_refresh();
				break;
			case MAIN_WARNING_OVER_MAXTEMP_STATE:
				main_state = MAIN_WARNING_WAITING_STATE;
				lcd_ui_clear();
				lcd_interface_show(LCD_WARNING_TYPE_OVER_MAX_TEMP_STATE);
				lcd_ui_refresh();
				break;
			case MAIN_WARNING_WAITING_STATE:
				if(alarm_count.lid_open == 0 && alarm_count.under_min_temp == 0 && alarm_count.over_max_temp == 0) //Wating for no warning
				{
					main_state = MAIN_NORMAL_STATE;
				}
				break;
			default:
				break;

		}
	}
}

void main_app_init(void)
{
	//Read setting from storage
	flash_mgt_read((uint32_t *)&setting, sizeof(lcd_inter_t));
	//Load all current param to lcd param
	memcpy((uint8_t *)&lcd,(uint8_t *)&setting, sizeof(lcd_inter_t));
	lcd_ui_init();
	lcd_interface_init();
	event_add(main_task, &main_app_id, MAIN_TASK_TICK_MS);
	event_active(&main_app_id);
}
