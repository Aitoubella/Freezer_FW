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
	setting_date_time_t set_datetime;
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
	date_time_t datetime;

	int16_t temperature;
	uint8_t bat_value;
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

//level 1 funcion
//void lcd_main(void);
//void lcd_menu_setting(void);
//void lcd_menu_operation_mode(void);
//void lcd_menu_service(void);
////level 2 function
//void lcd_menu_seting_datetime(void);
//void lcd_menu_setting_download_data(void);
//void lcd_menu_service_temperature(void);
//void lcd_menu_service_alarm(void);
//void lcd_menu_service_data_logging(void);
//void lcd_menu_service_calibration(void);
//
//
//#define FRAME_BUILD(total,func)   {total,func,0}

//level 1
//menu_t_ main = FRAME_BUILD(0,lcd_main);
//menu_t_ setting = FRAME_BUILD(3,lcd_menu_setting);
//menu_t_ operation_mode = FRAME_BUILD(3,lcd_menu_operation_mode);
//menu_t_ service =  FRAME_BUILD(3,lcd_menu_service);
//
////level 2
//menu_t_ setting_datetime = FRAME_BUILD(6,lcd_menu_seting_datetime);
//menu_t_ setting_download_data = FRAME_BUILD(2,lcd_menu_setting_download_data);
//menu_t_ setting_service_temperature = FRAME_BUILD(3,lcd_menu_service_temperature);
//menu_t_ setting_service_alarm = FRAME_BUILD(3,lcd_menu_service_alarm);
//menu_t_ setting_service_data_logging = FRAME_BUILD(2,lcd_menu_service_data_logging);
//menu_t_ setting_service_calibration = FRAME_BUILD(2,lcd_menu_service_calibration);

//level 3


void button_cb(uint8_t btn_num, btn_evt_t evt)
{
	static uint8_t lcd_state = LCD_MAIN_STATE;
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
			case LCD_SETTING_STATE:
				lcd_state = LCD_OPERATION_MODE_STATE;
				break;
			case LCD_OPERATION_MODE_STATE:
				lcd_state = LCD_MAIN_STATE;
				break;
			case LCD_SERVICE_STATE:
				lcd_state = LCD_SETTING_STATE;
				break;
			//level 2 enter to level 3
			//setting date time
			case LCD_SETTING_DATETIME_STATE:
				lcd_state = LCD_SETTING_DATETIME_YEAR_STATE;
				break;
			//setting download data
			case LCD_SETTING_DOWNLOAD_DATA_STATE:
				lcd_state = LCD_SETTING_DOWNLOAD_DATA_TO_USB_STATE;
				break;
			//service temperature
			case LCD_SERVICE_TEMPERATURE_STATE:
				lcd_state = LCD_SERVICE_TEMPERATURE_FRIDGE_STATE;
				break;
			//service alarm
			case LCD_SERVICE_ALARM_STATE:
				lcd_state = LCD_SERVICE_ALARMS_TEMPERATURE_STATE;
				break;
			//service data login
			case LCD_SERVICE_DATA_LOGGING_STATE:
				lcd_state = LCD_SERVICE_DATA_LOGGING_INTERVAL_STATE;
				break;
			//service calibration
			case LCD_SERVICE_CALIBRATION_STATE:
				lcd_state = LCD_SERVICE_CALIBRATION_TEMP_OFFSET_STATE;
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
			}
		}
	}
	lcd_interface_show(lcd_state);

}


void lcd_interface_show(lcd_state_t state)
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
	}
}

//Menu Level 1

//void lcd_main(void)
//{
//	lcd_main_screen_screen(lcd.spk_mode, lcd.temperature, lcd.pwr_mode, lcd.op_mode, lcd.bat_value, lcd.bat_state);
//}
//
//void lcd_menu_setting(void)
//{
//	lcd_setting(lcd.setting);
//}
//
//void lcd_menu_operation_mode(void)
//{
//	lcd_operation_mode_screen(lcd.op_mode);
//}
//
//
//void lcd_menu_service(void)
//{
//	lcd_service(lcd.service);
//}
//
////Menu Level 2
//
//void lcd_menu_seting_datetime(void)
//{
//	lcd_setting_date_time(lcd.set_datetime, &lcd.datetime);
//}
//
//void lcd_menu_setting_download_data(void)
//{
//	lcd_setting_download_data(lcd.setting_download_data);
//}
//
//void lcd_menu_service_temperature(void)
//{
//	lcd_service_temperature(lcd.service_temperature);
//}
//
//void lcd_menu_service_alarm(void)
//{
//	lcd_service_alarms(lcd.service_alarm);
//}
//
//void lcd_menu_service_data_logging(void)
//{
//	lcd_service_data_logging(lcd.service_data_logging);
//}
//
//void lcd_menu_service_calibration(void)
//{
//	lcd_service_data_calibration(lcd.service_calibration);
//}



void lcd_interface_init(void)
{
	button_init(button_cb);
}
