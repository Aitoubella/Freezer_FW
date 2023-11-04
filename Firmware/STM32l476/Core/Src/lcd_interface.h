/*
 * lcd_interface.h
 *
 */

#ifndef SRC_LCD_INTERFACE_H_
#define SRC_LCD_INTERFACE_H_

typedef enum
{
	//level 1
	LCD_MAIN_STATE = 0,
	LCD_OPERATION_MODE_STATE,
	LCD_SETTING_STATE,
	LCD_SERVICE_STATE,
	//level 2
	LCD_OPERATION_MODE_DEFAULT_STATE,
	LCD_OPERATION_MODE_FREEZER_STATE,
	LCD_OPERATION_MODE_FRIDEGE_STATE,
	LCD_OPERATION_MODE_BACK_STATE,

	LCD_SETTING_DEFAULT_STATE,
	LCD_SETTING_DATETIME_STATE,
	LCD_SETTING_DOWNLOAD_DATA_STATE,
	LCD_SETTING_BACK_STATE,

	LCD_SERVICE_DEFAULT_STATE,
	LCD_SERVICE_TEMPERATURE_STATE,
	LCD_SERVICE_ALARM_STATE,
	LCD_SERVICE_DATA_LOGGING_STATE,
	LCD_SERVICE_CALIBRATION_STATE,
	LCD_SERVICE_BACK_STATE,
	//level 3
	LCD_SETTING_DATETIME_YEAR_STATE,
	LCD_SETTING_DATETIME_MONTH_STATE,
	LCD_SETTING_DATETIME_DAY_STATE,
	LCD_SETTING_DATETIME_HOUR_STATE,
	LCD_SETTING_DATETIME_MINUTE_STATE,
	LCD_SETTING_DATETIME_BACK_STATE,

	LCD_SETTING_DOWNLOAD_DATA_TO_USB_STATE,
	LCD_SETTING_DOWNLOAD_DATA_BACK_STATE,

	LCD_SERVICE_TEMPERATURE_FRIDGE_STATE,
	LCD_SERVICE_TEMPERATURE_FREEZER_STATE,
	LCD_SERVICE_TEMPERATURE_BACK_STATE,

	LCD_SERVICE_ALARMS_TEMPERATURE_STATE,
	LCD_SERVICE_ALARMS_BATTERY_STATE,
	LCD_SERVICE_ALARMS_LID_STATE,
	LCD_SERVICE_ALARMS_MUTE_AlARMS_STATE,
	LCD_SERVICE_ALARMS_BACK_STATE,

	LCD_SERVICE_DATA_LOGGING_INTERVAL_STATE,
	LCD_SERVICE_DATA_LOGGING_BACK_STATE,

	LCD_SERVICE_CALIBRATION_TEMP_OFFSET_STATE,
	LCD_SERVICE_CALIBRATION_BACK_STATE,

	//Level 4
	LCD_SETTING_DATETIME_YEAR_SET_STATE,
	LCD_SETTING_DATETIME_MONTH_SET_STATE,
	LCD_SETTING_DATETIME_DAY_SET_STATE,
	LCD_SETTING_DATETIME_HOUR_SET_STATE,
	LCD_SETTING_DATETIME_MIN_SET_STATE,

	LCD_SETTING_DOWNLOAD_DATA_CONTINUE_STATE,
	LCD_SETTING_DOWNLOAD_DATA_CANCEL_STATE,

	LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_STATE,
	LCD_SERVICE_TEMPERATURE_FRIDGE_BACK_STATE,


	LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_STATE,
	LCD_SERVICE_TEMPERATURE_FREEZER_BACK_STATE,

	LCD_SERVICE_TEMPERATURE_FRIDGE_VALUE_SET_STATE,
	LCD_SERVICE_TEMPERATURE_FREEZER_VALUE_SET_STATE,

	LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_STATE,
	LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_STATE,
	LCD_SERVICE_ALARM_TEMP_BACK_STATE,

	LCD_SERVICE_ALARM_TEMP_TEMP_DEVIATION_SET_STATE,
	LCD_SERVICE_ALARM_TEMP_ALARM_DELAY_SET_STATE,

	LCD_SERVICE_ALARM_BAT_VALUE_STATE,
	LCD_SERVICE_ALARM_BAT_BACK_STATE,

	LCD_SERVICE_ALARM_BAT_VALUE_SET_STATE,

	LCD_SERVICE_ALARM_LID_VALUE_STATE,
	LCD_SERVICE_ALARM_LID_BACK_STATE,

	LCD_SERVICE_ALARM_LID_VALUE_SET_STATE,

	LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_STATE,
	LCD_SERVICE_ALARM_MUTE_DURATION_BACK_STATE,

	LCD_SERVICE_ALARM_MUTE_DURATION_VALUE_SET_STATE,

}lcd_state_t;
void lcd_interface_show(lcd_state_t state, void* value);
#endif /* SRC_LCD_INTERFACE_H_ */