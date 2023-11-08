/*
 * main_app.c
 *
 */


#include "lcd_interface.h"
#include "lcd_ui.h"
#include "DS1307.h"
#include "RTD.h"
#include "event.h"
event_id main_app_id;
#define MAIN_TASK_TICK_MS    100 //ms
extern lcd_inter_t setting;



uint8_t lcd_get_set_cb(lcd_get_set_evt_t evt, void* value)
{
	switch((uint8_t)evt)
	{
	   case LCD_SET_OPERATION_MODE_EVT:
		   setting.op_mode = *((operation_mode_t *)value);
		   break;
		case LCD_SET_DATETIME_EVT:
			datetime_t* datetime = (datetime_t *)value;
			memcpy((uint8_t *)&setting.datetime,(uint8_t *)datetime,sizeof(datetime_t));
			break;

		case LCD_SET_TEMPERATURE_FRIDGE_EVT:
			setting.temperature_fridge = *((int8_t *)value);
			break;

		case LCD_SET_TEMPERATURE_FREEZER_EVT:
			setting.temperature_freezer = *((int8_t *)value);
			break;

		case LCD_SET_ALARM_TEMPERATURE_DEVIATION_EVT:
			setting.alarm_temperature_deviation = *((int8_t *)value);
			break;

		case LCD_SET_ALARM_TEMPERATURE_DELAY_EVT:
			setting.alarm_temperature_delay = *((uint8_t *)value);
			break;

		case LCD_SET_ALARM_BAT_EVT:
			setting.alarm_bat = *((uint8_t *)value);
			break;

		case LCD_SET_ALARM_LID_EVT:
			setting.alarm_lid = *((uint8_t *)value);
			break;

		case LCD_SET_LOGGING_INTERVAL_EVT:
			setting.logging_interval = *((uint8_t *)value);
			break;

		case LCD_SET_TEMP_OFFSET_EVT:
			setting.temp_offset = *((uint8_t *)value);
			break;
		case LCD_SET_LARM_MUTE_DURATION_EVT:
			setting.alarm_mute_duration = *((uint8_t *)value);
			break;

		case LCD_USB_INSERT_DOWNLOAD_EVT:
			return 1;
			break;
	}
	return 1;
}

void main_task(void)
{
	static lcd_inter_t* lcd_param;
	static lcd_state_t lcd_state;
	lcd_state = lcd_interface_get_state();

	setting.temperature = (int16_t) rtd_get_temperature();

	if(lcd_state == LCD_MAIN_STATE)
	{
		//Check current value is differ from lcd value -> update lcd
		lcd_param =  lcd_interface_get_param();
		if(lcd_param->op_mode != setting.op_mode || lcd_param->pwr_mode != setting.pwr_mode
		  || lcd_param->temperature != setting.temperature || lcd_param->bat_state != setting.bat_state
		  || lcd_param->bat_value != setting.bat_value || lcd_param->spk_mode != setting.spk_mode)
		{
			//Update lcd main frame
			lcd_param->op_mode = setting.op_mode;
			lcd_param->pwr_mode = setting.pwr_mode;
			lcd_param->temperature = setting.temperature;
			lcd_param->bat_state = setting.bat_state;
			lcd_param->bat_value = setting.bat_value;
			lcd_param->spk_mode = setting.spk_mode;
			//Reload main frame
			lcd_ui_clear();
			lcd_interface_show(lcd_state);
			lcd_ui_refresh();
		}
	}
}

void main_app_init(void)
{
	event_add(main_task, &main_app_id, MAIN_TASK_TICK_MS);
	event_active(&main_app_id);
}
