/*
 * lcd_interface.c
 *

 */


#include "lcd_interface.h"
#include "lcd_ui.h"
#include "button.h"
#include "buzzer.h"



typedef struct
{
	operation_mode_t op_mode;
	power_mode_t pwr_mode;
	speaker_mode_t spk_mode;
	battery_state_t bat_state;
	display_unit_t display_unit;
	setting_t setting;
	setting_download_data_t setting_download_data;
	setting_download_data_insert_t setting_download_data_insert;
	setting_datetime_t set_datetime;
	service_t service;
	service_temperature_t service_temperature;
	service_data_logging_t service_data_logging;
	service_alarm_t service_alarm;
	service_calibration_t service_calibration;
	service_temperature_fridge_t service_temperature_fridge;
	service_alarms_bat_t service_alarms_bat;
	service_alarms_lid_t service_alarms_lid;
	service_alarms_mute_duration_t service_alarms_mute_duration;
	servie_alarms_warning_mode_t servie_alarms_warning_mode;
	warning_mode_t warning_mode;
	datetime_t datetime;

	int16_t temperature;
	uint8_t bat_value;
	int8_t temperature_fidge;
	int8_t temperature_freezer;

	int8_t alarm_temperature_deviation;
	uint8_t alarm_temperature_delay;
	uint8_t alarm_bat;
	uint8_t alarm_lid;
}lcd_inter_t;



struct menu_t
{
	struct menu_t *parent;
	void* show;
	uint8_t index;
	uint8_t total;
	struct menu_t *next;
};

typedef struct menu_t menu_t_;
lcd_inter_t lcd =
{
	.display_unit = DISPLAY_UINIT_ON,
	.bat_state = BATTERY_STATE_NOT_CHARGE,
};

void button_cb(uint8_t btn_num, btn_evt_t evt)
{
	static uint8_t lcd_state = LCD_MAIN_STATE;
	int32_t value;
	switch(btn_num)
	{
	case BTN_ENTER:
		if(evt == BUTTON_SHORT_PRESS)
		{
			switch(lcd_state)
			{
			//level 1
			case LCD_MAIN_STATE:
				lcd_state = LCD_SERVICE_STATE;
				break;
			case LCD_OPERATION_MODE_STATE:
				lcd_state = LCD_SETTING_STATE;
				break;
			case LCD_SETTING_STATE:
				lcd_state = LCD_SERVICE_STATE;
				break;
			case LCD_SERVICE_STATE:
				lcd_state = LCD_MAIN_STATE;
				break;
			//level 2 enter to level 3
			//Operation mode
			case LCD_OPERATION_MODE_DEFAULT_STATE:
				lcd_state = LCD_SERVICE_STATE;
				break;
			case LCD_OPERATION_MODE_FREEZER_STATE:
				lcd_state = LCD_SERVICE_STATE;
				break;
			case LCD_OPERATION_MODE_FRIDEGE_STATE:
				lcd_state = LCD_SERVICE_STATE;
				break;
			case LCD_OPERATION_MODE_BACK_STATE:
				lcd_state = LCD_SERVICE_STATE;
				break;

			//setting date time
			case LCD_SETTING_DATETIME_STATE:
				lcd_state = LCD_SETTING_DATETIME_YEAR_STATE;
				break;
			//setting download data
			case LCD_SETTING_DOWNLOAD_DATA_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_TO_USB_STATE;
				break;
			case LCD_SETTING_BACK_STATE:
				lcd_state = LCD_SETTING_STATE;
				break;
			//service temperature
			case LCD_SERVICE_TEMPERATURE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_STATE;
				break;
			//service alarm
			case LCD_SERVICE_ALARM_STATE:
				lcd_state = LCD_SERVICE_ALARMS_TEMPERATURE_STATE;
				break;
			//service data loging
			case LCD_SERVICE_DATA_LOGGING_STATE:
				lcd_state = LCD_SERVICE_DATA_LOGGING_INTERVAL_STATE;
				break;
			//service calibration
			case LCD_SERVICE_CALIBRATION_STATE:
				lcd_state = LCD_SERVICE_CALIBRATION_TEMP_OFFSET_STATE;
				break;
			case LCD_SERVICE_BACK_STATE:
				lcd_state = LCD_SERVICE_STATE;
				break;
			//level 3 enter to level 4
			//date time
			case LCD_SETTING_DATETIME_YEAR_STATE:
				lcd_state = LCD_SETTING_DATETIME_YEAR_SET_STATE;
				break;
			case LCD_SETTING_DATETIME_MONTH_STATE:
				lcd_state = LCD_SETTING_DATETIME_MONTH_SET_STATE;
				break;
			case LCD_SETTING_DATETIME_DAY_STATE:
				lcd_state = LCD_SETTING_DATETIME_DAY_SET_STATE;
				break;
			case LCD_SETTING_DATETIME_HOUR_STATE:
				lcd_state = LCD_SETTING_DATETIME_HOUR_SET_STATE;
				break;
			case LCD_SETTING_DATETIME_MINUTE_STATE:
				lcd_state = LCD_SETTING_DATETIME_MIN_SET_STATE;
				break;
			case LCD_SETTING_DATETIME_BACK_STATE:
				lcd_state = LCD_SETTING_DATETIME_STATE;
				break;
			//Back datetime when set done
			case LCD_SETTING_DATETIME_YEAR_SET_STATE:
				lcd_state = LCD_SETTING_DATETIME_YEAR_STATE;
				break;
			case LCD_SETTING_DATETIME_MONTH_SET_STATE:
				lcd_state = LCD_SETTING_DATETIME_MONTH_STATE;
				break;
			case LCD_SETTING_DATETIME_DAY_SET_STATE:
				lcd_state = LCD_SETTING_DATETIME_DAY_STATE;
				break;
			case LCD_SETTING_DATETIME_HOUR_SET_STATE:
				lcd_state = LCD_SETTING_DATETIME_HOUR_STATE;
				break;
			case LCD_SETTING_DATETIME_MIN_SET_STATE:
				lcd_state = LCD_SETTING_DATETIME_MINUTE_STATE;
				break;
			//Download data
			case LCD_SETTING_DOWNLOAD_DATA_TO_USB_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_CONTINUE_STATE;
				break;
			case LCD_SETTING_DOWNLOAD_DATA_BACK_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_STATE;
				break;
			//Temperature go in set
			case LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_SET_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_SET_STATE;
				break;
			//Temperature back to previous
			case LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_SET_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FRIDGE_BACK_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_SET_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FREEZER_BACK_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FREEZER_STATE;
				break;
			//Alarm temp
			case LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_STATE:
				lcd_state = LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_SET_STATE;
				break;
			case LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_STATE:
				lcd_state = LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_SET_STATE;
				break;
			case LCD_SERVICE_ALARM_TEMP_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARMS_TEMPERATURE_STATE;
				break;
			//Alarm temp deviation set
			case LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_SET_STATE:
				lcd_state = LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_STATE;
				break;
			//Alarm delay set
			case LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_SET_STATE:
				//user cb
				lcd_state = LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_STATE;
				break;
			//Alarm bat
			case LCD_SERVICE_ALARM_BAT_VALUE_STATE:
				lcd_state = LCD_SERVICE_ALARM_BAT_VALUE_SET_STATE;
				break;
			case LCD_SERVICE_ALARM_BAT_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARMS_BATTERY_STATE;
				break;
			case LCD_SERVICE_ALARM_BAT_VALUE_SET_STATE:
				lcd_state = LCD_SERVICE_ALARM_BAT_VALUE_STATE;
				break;
			//Alarm Lid
			case LCD_SERVICE_ALARM_LID_VALUE_STATE:
				lcd_state = LCD_SERVICE_ALARM_LID_VALUE_SET_STATE;
				break;
			case LCD_SERVICE_ALARM_LID_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARMS_LID_STATE;
				break;
			case LCD_SERVICE_ALARM_LID_VALUE_SET_STATE:
				lcd_state = LCD_SERVICE_ALARM_LID_VALUE_STATE;
				break;
			//Alarm Mute
			case LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_STATE:
				lcd_state = LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_SET_STATE;
				break;
			case LCD_SERVICE_ALARM_MUTE_DURATION_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARMS_MUTE_AlARMS_STATE;
				break;
			case LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_SET_STATE:
				lcd_state = LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_STATE;
				break;

			}

		}else if(evt == BUTTON_HOLD_2_SEC)
		{
			lcd_turn_off_unit(lcd.display_unit);
		}
		break;
	case BTN_UP:
		if(evt == BUTTON_SHORT_PRESS)
		{
			switch(lcd_state)
			{
			//level 2
			//Operation
			case LCD_OPERATION_MODE_STATE:
				lcd_state = LCD_OPERATION_MODE_BACK_STATE;
				break;
			case LCD_OPERATION_MODE_BACK_STATE:
				lcd_state = LCD_OPERATION_MODE_FRIDEGE_STATE;
				break;
			case LCD_OPERATION_MODE_FRIDEGE_STATE:
				lcd_state = LCD_OPERATION_MODE_FREEZER_STATE;
				break;
			case LCD_OPERATION_MODE_FREEZER_STATE:
				lcd_state = LCD_OPERATION_MODE_BACK_STATE;
				break;

			//Setting
			case LCD_SETTING_STATE:
				lcd_state = LCD_SETTING_BACK_STATE;
				break;
			case LCD_SETTING_BACK_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_STATE;
				break;
			case LCD_SETTING_DOWNLOAD_DATA_STATE:
				lcd_state = LCD_SETTING_DATETIME_STATE;
				break;
			case LCD_SETTING_DATETIME_STATE:
				lcd_state = LCD_SETTING_BACK_STATE;
				break;
				//Service
			case LCD_SERVICE_STATE:
				lcd_state = LCD_SERVICE_BACK_STATE;
				break;
			case LCD_SERVICE_BACK_STATE:
				lcd_state = LCD_SERVICE_CALIBRATION_STATE;
				break;
			case LCD_SERVICE_CALIBRATION_STATE:
				lcd_state = LCD_SERVICE_DATA_LOGGING_STATE;
				break;
			case LCD_SERVICE_DATA_LOGGING_STATE:
				lcd_state = LCD_SERVICE_ALARM_STATE;
				break;
			case LCD_SERVICE_ALARM_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_STATE:
				lcd_state = LCD_SERVICE_BACK_STATE;
				break;
			//level 3
			//setting date time
			case LCD_SETTING_DATETIME_YEAR_STATE:
				lcd_state = LCD_SETTING_DATETIME_BACK_STATE;
				break;
			case LCD_SETTING_DATETIME_BACK_STATE:
				lcd_state = LCD_SETTING_DATETIME_MINUTE_STATE;
				break;
			case LCD_SETTING_DATETIME_MINUTE_STATE:
				lcd_state = LCD_SETTING_DATETIME_HOUR_STATE;
				break;
			case LCD_SETTING_DATETIME_HOUR_STATE:
				lcd_state = LCD_SETTING_DATETIME_DAY_STATE;
				break;
			case LCD_SETTING_DATETIME_DAY_STATE:
				lcd_state = LCD_SETTING_DATETIME_MONTH_STATE;
				break;
			case LCD_SETTING_DATETIME_MONTH_STATE:
				lcd_state = LCD_SETTING_DATETIME_YEAR_STATE;
				break;
			//setting  download data
			case LCD_SETTING_DOWNLOAD_DATA_TO_USB_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_BACK_STATE;
				break;
			case LCD_SETTING_DOWNLOAD_DATA_BACK_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_TO_USB_STATE;
				break;
			//service temperature
			case LCD_SERVICE_TEMPERATURE_FRIDGE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_BACK_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_BACK_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FREEZER_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FREEZER_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_STATE;
				break;
			//service alarms
			case LCD_SERVICE_ALARMS_TEMPERATURE_STATE:
				lcd_state = LCD_SERVICE_ALARMS_BATTERY_STATE;
				break;
			case LCD_SERVICE_ALARMS_BATTERY_STATE:
				lcd_state = LCD_SERVICE_ALARMS_LID_STATE;
				break;
			case LCD_SERVICE_ALARMS_LID_STATE:
				lcd_state = LCD_SERVICE_ALARMS_MUTE_AlARMS_STATE;
				break;
			case LCD_SERVICE_ALARMS_MUTE_AlARMS_STATE:
				lcd_state = LCD_SERVICE_ALARMS_BACK_STATE;
				break;
			case LCD_SERVICE_ALARMS_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARMS_TEMPERATURE_STATE;
				break;
			//service data logging
			case LCD_SERVICE_DATA_LOGGING_INTERVAL_STATE:
				lcd_state = LCD_SERVICE_DATA_LOGGING_BACK_STATE;
				break;
			case LCD_SERVICE_DATA_LOGGING_BACK_STATE:
				lcd_state = LCD_SERVICE_DATA_LOGGING_INTERVAL_STATE;
				break;
			//service calibration
			case LCD_SERVICE_CALIBRATION_TEMP_OFFSET_STATE:
				lcd_state = LCD_SERVICE_CALIBRATION_BACK_STATE;
				break;
			case LCD_SERVICE_CALIBRATION_BACK_STATE:
				lcd_state = LCD_SERVICE_CALIBRATION_TEMP_OFFSET_STATE;
				break;
			//level 4
			//setting date time  year,month,day,hour,min
			case LCD_SETTING_DATETIME_YEAR_SET_STATE:
				//User callback
				break;
			case LCD_SETTING_DATETIME_MONTH_SET_STATE:
				//User callback
				break;
			case LCD_SETTING_DATETIME_DAY_SET_STATE:
				//User callback
				break;
			case LCD_SETTING_DATETIME_HOUR_SET_STATE:
				//User callback
				break;
			case LCD_SETTING_DATETIME_MIN_SET_STATE:
				//User callback
				break;
			//download data
			case LCD_SETTING_DOWNLOAD_DATA_CONTINUE_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_CANCEL_STATE;
				break;
			case LCD_SETTING_DOWNLOAD_DATA_CANCEL_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_CONTINUE_STATE;
				break;
			//Temperature set
			case LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_BACK_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FRIDGE_BACK_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_SET_STATE:
				//user cb
				break;

			case LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FREEZER_BACK_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FREEZER_BACK_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_STATE;
				break;

			case LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_SET_STATE:
				//user cb
				break;
			//Alarm temp deviation set
			case LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_STATE:
				lcd_state = LCD_SERVICE_ALARM_TEMP_BACK_STATE;
				break;
			case LCD_SERVICE_ALARM_TEMP_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_STATE;
				break;
			case LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_STATE:
				lcd_state = LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_STATE;
				break;
			case LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_SET_STATE:
				//user cb
				break;
			//Alarm delay set
			case LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_SET_STATE:
				//user cb
				break;
			//Alarm bat
			case LCD_SERVICE_ALARM_BAT_VALUE_STATE:
				lcd_state = LCD_SERVICE_ALARM_BAT_BACK_STATE;
				break;
			case LCD_SERVICE_ALARM_BAT_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARM_BAT_VALUE_STATE;
				break;
			case LCD_SERVICE_ALARM_BAT_VALUE_SET_STATE:
				//user cb
				break;
			//Alarm Lid
			case LCD_SERVICE_ALARM_LID_VALUE_STATE:
				lcd_state = LCD_SERVICE_ALARM_LID_BACK_STATE;
				break;
			case LCD_SERVICE_ALARM_LID_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARM_LID_VALUE_STATE;
				break;
			case LCD_SERVICE_ALARM_LID_VALUE_SET_STATE:
				//user cb
				break;
			//Alarm mute duration
			case LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_STATE:
				lcd_state = LCD_SERVICE_ALARM_MUTE_DURATION_BACK_STATE;
				break;
			case LCD_SERVICE_ALARM_MUTE_DURATION_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_STATE;
				break;
			case LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_SET_STATE:
				//user cb
				break;
			}
		}
		break;
	case BTN_DOWN:
		if(evt == BUTTON_SHORT_PRESS)
		{
			switch(lcd_state)
			{
			//level 2
			//Operation
			case LCD_OPERATION_MODE_STATE:
				lcd_state = LCD_OPERATION_MODE_FREEZER_STATE;
				break;
			case LCD_OPERATION_MODE_FREEZER_STATE:
				lcd_state = LCD_OPERATION_MODE_FRIDEGE_STATE;
				break;
			case LCD_OPERATION_MODE_FRIDEGE_STATE:
				lcd_state = LCD_OPERATION_MODE_BACK_STATE;
				break;
			case LCD_OPERATION_MODE_BACK_STATE:
				lcd_state = LCD_OPERATION_MODE_FREEZER_STATE;
				break;
				//Setting
			case LCD_SETTING_STATE:
				lcd_state = LCD_SETTING_DATETIME_STATE;
				break;
			case LCD_SETTING_DATETIME_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_STATE;
				break;
			case LCD_SETTING_DOWNLOAD_DATA_STATE:
				lcd_state = LCD_SETTING_BACK_STATE;
				break;
			case LCD_SETTING_BACK_STATE:
				lcd_state = LCD_SETTING_DATETIME_STATE;
				break;
				//Service
			case LCD_SERVICE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_STATE:
				lcd_state = LCD_SERVICE_ALARM_STATE;
				break;
			case LCD_SERVICE_ALARM_STATE:
				lcd_state = LCD_SERVICE_DATA_LOGGING_STATE;
				break;
			case LCD_SERVICE_DATA_LOGGING_STATE:
				lcd_state = LCD_SERVICE_CALIBRATION_STATE;
				break;
			case LCD_SERVICE_CALIBRATION_STATE:
				lcd_state = LCD_SERVICE_BACK_STATE;
				break;
			case LCD_SERVICE_BACK_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_STATE;
				break;
			//level 3
			//setting date time
			case LCD_SETTING_DATETIME_YEAR_STATE:
				lcd_state = LCD_SETTING_DATETIME_MONTH_STATE;
				break;
			case LCD_SETTING_DATETIME_MONTH_STATE:
				lcd_state = LCD_SETTING_DATETIME_DAY_STATE;
				break;
			case LCD_SETTING_DATETIME_DAY_STATE:
				lcd_state = SETTING_DATETIME_HOUR;
				break;
			case LCD_SETTING_DATETIME_HOUR_STATE:
				lcd_state = LCD_SETTING_DATETIME_MINUTE_STATE;
				break;
			case SETTING_DATETIME_MINUTE:
				lcd_state = LCD_SERVICE_BACK_STATE;
				break;
			case LCD_SETTING_DATETIME_BACK_STATE:
				lcd_state = LCD_SETTING_DATETIME_YEAR_STATE;
				break;
			//setting  download data
			case LCD_SETTING_DOWNLOAD_DATA_TO_USB_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_BACK_STATE;
				break;
			case LCD_SETTING_DOWNLOAD_DATA_BACK_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_TO_USB_STATE;
				break;
			//service temperature
			case LCD_SERVICE_TEMPERATURE_FRIDGE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FREEZER_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FREEZER_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_BACK_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_BACK_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_STATE;
				break;
			//service alarms
			case LCD_SERVICE_ALARMS_TEMPERATURE_STATE:
				lcd_state = LCD_SERVICE_ALARMS_BATTERY_STATE;
				break;
			case LCD_SERVICE_ALARMS_BATTERY_STATE:
				lcd_state = LCD_SERVICE_ALARMS_LID_STATE;
				break;
			case LCD_SERVICE_ALARMS_LID_STATE:
				lcd_state = LCD_SERVICE_ALARMS_MUTE_AlARMS_STATE;
				break;
			case LCD_SERVICE_ALARMS_MUTE_AlARMS_STATE:
				lcd_state = LCD_SERVICE_ALARMS_BACK_STATE;
				break;
			case LCD_SERVICE_ALARMS_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARMS_TEMPERATURE_STATE;
				break;
			//service data logging
			case LCD_SERVICE_DATA_LOGGING_INTERVAL_STATE:
				lcd_state = LCD_SERVICE_DATA_LOGGING_BACK_STATE;
				break;
			case LCD_SERVICE_DATA_LOGGING_BACK_STATE:
				lcd_state = LCD_SERVICE_DATA_LOGGING_INTERVAL_STATE;
				break;
			//service calibration
			case LCD_SERVICE_CALIBRATION_TEMP_OFFSET_STATE:
				lcd_state = LCD_SERVICE_CALIBRATION_BACK_STATE;
				break;
			case LCD_SERVICE_CALIBRATION_BACK_STATE:
				lcd_state = LCD_SERVICE_CALIBRATION_TEMP_OFFSET_STATE;
				break;
			//Level 4
			//setting date time  year,month,day,hour,min
			case LCD_SETTING_DATETIME_YEAR_SET_STATE:
				//User callback
				break;
			case LCD_SETTING_DATETIME_MONTH_SET_STATE:
				//User callback
				break;
			case LCD_SETTING_DATETIME_DAY_SET_STATE:
				//User callback
				break;
			case LCD_SETTING_DATETIME_HOUR_SET_STATE:
				//User callback
				break;
			case LCD_SETTING_DATETIME_MIN_SET_STATE:
				//User callback
				break;
			//Download data continue or back
			case LCD_SETTING_DOWNLOAD_DATA_CONTINUE_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_CANCEL_STATE;
				break;
			case LCD_SETTING_DOWNLOAD_DATA_CANCEL_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_CONTINUE_STATE;
				break;
			//Temperature set
			case LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_BACK_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FRIDGE_BACK_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_SET_STATE:
				//user cb
				break;

			case LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FREEZER_BACK_STATE;
				break;
			case LCD_SERVICE_TEMPERATURE_FREEZER_BACK_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_STATE;
				break;

			case LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_SET_STATE:
				//user cb
				break;
			//Alarm temp deviation set
			case LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_STATE:
				lcd_state = LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_STATE;
				break;
			case LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_STATE:
				lcd_state = LCD_SERVICE_ALARM_TEMP_BACK_STATE;
				break;
			case LCD_SERVICE_ALARM_TEMP_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_STATE;
				break;
			case LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_SET_STATE:
				//user cb
				break;
			//Alarm delay set
			case LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_SET_STATE:
				//user cb
				break;
			//Alarm bat
			case LCD_SERVICE_ALARM_BAT_VALUE_STATE:
				lcd_state = LCD_SERVICE_ALARM_BAT_BACK_STATE;
				break;
			case LCD_SERVICE_ALARM_BAT_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARM_BAT_VALUE_STATE;
				break;
			case LCD_SERVICE_ALARM_BAT_VALUE_SET_STATE:
				//user cb
				break;
			//Alarm Lid
			case LCD_SERVICE_ALARM_LID_VALUE_STATE:
				lcd_state = LCD_SERVICE_ALARM_LID_BACK_STATE;
				break;
			case LCD_SERVICE_ALARM_LID_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARM_LID_VALUE_STATE;
				break;
			case LCD_SERVICE_ALARM_LID_VALUE_SET_STATE:
				//user cb
				break;
			//Alarm mute duration
			case LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_STATE:
				lcd_state = LCD_SERVICE_ALARM_MUTE_DURATION_BACK_STATE;
				break;
			case LCD_SERVICE_ALARM_MUTE_DURATION_BACK_STATE:
				lcd_state = LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_STATE;
				break;
			case LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_SET_STATE:
				//user cb
				break;

			}
		}
	}
	lcd_interface_show(lcd_state, (void *)&value);

}


void lcd_interface_show(lcd_state_t state, void* value)
{
	switch((uint8_t)state)
	{
	case LCD_MAIN_STATE:
		lcd_main_screen_screen(lcd.spk_mode, lcd.temperature, lcd.pwr_mode, lcd.op_mode, lcd.bat_value, lcd.bat_state);
		break;
	case LCD_OPERATION_MODE_STATE:
		lcd_operation_mode_screen(lcd.op_mode);
		break;
	case LCD_SETTING_STATE:
		lcd_setting(lcd.setting);
		break;
	case LCD_SERVICE_STATE:
		lcd_service(lcd.service);
		break;
	//Level 2
	case LCD_OPERATION_MODE_DEFAULT_STATE:
		lcd_operation_mode_screen(OPERATION_MODE_DEFAULT);
		break;
	case LCD_OPERATION_MODE_FREEZER_STATE:
		lcd_operation_mode_screen(OPERATION_MODE_FREEZER);
		break;
	case LCD_OPERATION_MODE_FRIDEGE_STATE:
		lcd_operation_mode_screen(OPERATION_MODE_FRIDEGE);
		break;
	case LCD_OPERATION_MODE_BACK_STATE:
		lcd_operation_mode_screen(OPERATION_MODE_BACK);
		break;

	case LCD_SETTING_DEFAULT_STATE:
		lcd_setting(SETTING_DEFAULT);
		break;
	case LCD_SETTING_DATETIME_STATE:
		lcd_setting(SETTING_DATETIME);
		break;
	case LCD_SETTING_DOWNLOAD_DATA_STATE:
		lcd_setting(SETTING_DOWNLOAD_DATA);
		break;
	case LCD_SETTING_BACK_STATE:
		lcd_setting(SETTING_BACK);
		break;

	case LCD_SERVICE_DEFAULT_STATE:
		lcd_service(SERVICE_DEFAULT);
		break;
	case LCD_SERVICE_TEMPERATURE_STATE:
		lcd_service(SERVICE_TEMPERATURE);
		break;
	case LCD_SERVICE_ALARM_STATE:
		lcd_service(SERVICE_ALARM);
		break;
	case LCD_SERVICE_DATA_LOGGING_STATE:
		lcd_service(SERVICE_DATA_LOGGING);
		break;
	case LCD_SERVICE_CALIBRATION_STATE:
		lcd_service(SERVICE_CALIBRATION);
		break;
	case LCD_SERVICE_BACK_STATE:
		lcd_service(SERVICE_BACK);
		break;

	//Level 3
	case LCD_SETTING_DATETIME_YEAR_STATE:
		lcd_setting_datetime(SETTING_DATETIME_YEAR, &lcd.datetime);
		break;
	case LCD_SETTING_DATETIME_MONTH_STATE:
		lcd_setting_datetime(SETTING_DATETIME_MONTH, &lcd.datetime);
		break;
	case LCD_SETTING_DATETIME_DAY_STATE:
		lcd_setting_datetime(SETTING_DATETIME_DAY, &lcd.datetime);
		break;
	case LCD_SETTING_DATETIME_HOUR_STATE:
		lcd_setting_datetime(SETTING_DATETIME_HOUR, &lcd.datetime);
		break;
	case LCD_SETTING_DATETIME_MINUTE_STATE:
		lcd_setting_datetime(SETTING_DATETIME_MINUTE, &lcd.datetime);
		break;
	case LCD_SETTING_DATETIME_BACK_STATE:
		lcd_setting_datetime(SETTING_DATETIME_BACK, &lcd.datetime);
		break;

	case LCD_SETTING_DOWNLOAD_DATA_TO_USB_STATE:
		lcd_setting_download_data(SETTING_DOWNLOAD_DATA_TO_USB);
		break;
	case LCD_SETTING_DOWNLOAD_DATA_BACK_STATE:
		lcd_setting_download_data(SETTING_DOWNLOAD_DATA_BACK);
		break;

	case LCD_SERVICE_TEMPERATURE_FRIDGE_STATE:
		lcd_service_temperature(SERVICE_TEMPERATURE_FRIDGE);
		break;
	case LCD_SERVICE_TEMPERATURE_FREEZER_STATE:
		lcd_service_temperature(SERVICE_TEMPERATURE_FREEZER);
		break;
	case LCD_SERVICE_TEMPERATURE_BACK_STATE:
		lcd_service_temperature(SERVICE_TEMPERATURE_BACK);
		break;

	case LCD_SERVICE_ALARMS_TEMPERATURE_STATE:
		lcd_service_alarms(SERVICE_ALARMS_TEMPERATURE);
		break;
	case LCD_SERVICE_ALARMS_BATTERY_STATE:
		lcd_service_alarms(SERVICE_ALARMS_BATTERY);
		break;
	case LCD_SERVICE_ALARMS_LID_STATE:
		lcd_service_alarms(SERVICE_ALARMS_LID);
		break;
	case LCD_SERVICE_ALARMS_MUTE_AlARMS_STATE:
		lcd_service_alarms(SERVICE_ALARMS_MUTE_AlARMS);
		break;
	case LCD_SERVICE_ALARMS_BACK_STATE:
		lcd_service_alarms(SERVICE_ALARMS_BACK);
		break;

	case LCD_SERVICE_DATA_LOGGING_INTERVAL_STATE:
		lcd_service_data_logging(SERVICE_DATA_LOGGING_INTERVAL);
		break;
	case LCD_SERVICE_DATA_LOGGING_BACK_STATE:
		lcd_service_data_logging(SERVICE_DATA_LOGGING_BACK);
		break;

	case LCD_SERVICE_CALIBRATION_TEMP_OFFSET_STATE:
		lcd_service_calibration(SERVICE_CALIBRATION_TEMP_OFFSET);
		break;
	case LCD_SERVICE_CALIBRATION_BACK_STATE:
		lcd_service_calibration(SERVICE_CALIBRATION_BACK);
		break;

	//Level 4
	case LCD_SETTING_DATETIME_YEAR_SET_STATE:
		lcd_setting_datetime_year_set(lcd.datetime.year);
		break;
	case LCD_SETTING_DATETIME_MONTH_SET_STATE:
		lcd_setting_datetime_month_set(lcd.datetime.month);
		break;
	case LCD_SETTING_DATETIME_DAY_SET_STATE:
		lcd_setting_datetime_day_set(lcd.datetime.day);
		break;
	case LCD_SETTING_DATETIME_HOUR_SET_STATE:
		lcd_setting_datetime_hour_set(lcd.datetime.hour);
		break;
	case LCD_SETTING_DATETIME_MIN_SET_STATE:
		lcd_setting_datetime_min_set(lcd.datetime.minute);
		break;

	case LCD_SETTING_DOWNLOAD_DATA_CONTINUE_STATE:
		lcd_setting_download_data_insert(SETTING_DOWNLOAD_DATA_CONTINUE);
		break;
	case LCD_SETTING_DOWNLOAD_DATA_CANCEL_STATE:
		lcd_setting_download_data_insert(SETTING_DOWNLOAD_DATA_CANCEL);
		break;

	case LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_STATE:
		lcd_service_temperature_fridge(SERVICE_TEMPERATURE_FRIDGE_VALUE, lcd.temperature_fidge);
		break;
	case LCD_SERVICE_TEMPERATURE_FRIDGE_BACK_STATE:
		lcd_service_temperature_fridge(SERVICE_TEMPERATURE_FRIDGE_BACK, lcd.temperature_fidge);
		break;
	case LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_SET_STATE:
		lcd_service_temperature_fridge_set(lcd.temperature_fidge);
		break;

	case LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_STATE:
		lcd_service_temperature_freezer(SERVICE_TEMPERATURE_FRIDGE_VALUE, lcd.temperature_freezer);
		break;
	case LCD_SERVICE_TEMPERATURE_FREEZER_BACK_STATE:
		lcd_service_temperature_freezer(SERVICE_TEMPERATURE_FRIDGE_BACK, lcd.temperature_freezer);
		break;
	case LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_SET_STATE:
		lcd_service_temperature_freezer_set(lcd.temperature_freezer);
		break;

	case LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_STATE:
		lcd_service_alarm_temperature(SERVICE_ALARM_TEMP_TEMP_DEVIATION);
		break;
	case LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_STATE:
		lcd_service_alarm_temperature(SERVICE_ALARM_TEMP_ALARM_DELAY);
		break;
	case LCD_SERVICE_ALARM_TEMP_BACK_STATE:
		lcd_service_alarm_temperature(SERVICE_ALARM_TEMP_BACK);
		break;

	case LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_SET_STATE:
		lcd_service_alarm_temperature_temp_deviation_set(lcd.alarm_temperature_deviation);
		break;
	case LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_SET_STATE:
		lcd_service_alarm_temperature_temp_deviation_set(lcd.alarm_temperature_delay);
		break;

	case LCD_SERVICE_ALARM_BAT_VALUE_STATE:
		lcd_service_alarm_bat(SERVICE_ALARM_BAT_VALUE,lcd.alarm_bat);
		break;
	case LCD_SERVICE_ALARM_BAT_BACK_STATE:
		lcd_service_alarm_bat(SERVICE_ALARM_BAT_BACK,lcd.alarm_bat);
		break;
	case LCD_SERVICE_ALARM_BAT_VALUE_SET_STATE:
		lcd_service_alarm_bat_set(lcd.alarm_bat);
		break;

	case LCD_SERVICE_ALARM_LID_VALUE_STATE:
		lcd_service_alarm_lid(SERVICE_ALARM_LID_VALUE,lcd.alarm_lid);
		break;
	case LCD_SERVICE_ALARM_LID_BACK_STATE:
		lcd_service_alarm_lid(SERVICE_ALARM_LID_VALUE, lcd.alarm_lid);
		break;
	case LCD_SERVICE_ALARM_LID_VALUE_SET_STATE:
		lcd_service_alarm_lid_set(lcd.alarm_lid);
		break;

	case LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_STATE:
		lcd_service_alarms_mute_duration(SERVICE_ALARM_MUTE_DURATION_VALUE,lcd.alarm_lid);
		break;
	case LCD_SERVICE_ALARM_MUTE_DURATION_BACK_STATE:
		lcd_service_alarms_mute_duration(SERVICE_ALARM_MUTE_DURATION_BACK,lcd.alarm_lid);
		break;
	case LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_SET_STATE:
		lcd_service_alarms_mute_duration_set(lcd.alarm_lid);
		break;
	}
}



void lcd_interface_init(void)
{
	button_init(button_cb);
}
