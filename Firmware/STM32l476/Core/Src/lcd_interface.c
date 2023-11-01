/*
 * lcd_interface.c
 *
 *  Created on: Nov 1, 2023
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

lcd_inter_t lcd =
{
		.display_unit = DISPLAY_UINIT_ON,
		.bat_state = BATTERY_STATE_NOT_CHARGE,
};

void button_cb(uint8_t btn_num, btn_evt_t evt)
{
	switch(btn_num)
	{
	case BTN_ENTER:
		if(evt == BUTTON_SHORT_PRESS)
		{

		}else if(evt == BUTTON_HOLD_2_SEC)
		{
			lcd_turn_off_unit(lcd.display_unit);
		}
		break;
	case BTN_UP:
		if(evt == BUTTON_SHORT_PRESS)
		{

		}
		break;
	case BTN_DOWN:
		if(evt == BUTTON_SHORT_PRESS)
		{

		}
		break;
	}
}

//Menu Level 1

void lcd_main(void)
{
	lcd_main_screen_screen(lcd.spk_mode, lcd.temperature, lcd.pwr_mode, lcd.op_mode, lcd.bat_value, lcd.bat_state);
}

void lcd_menu_setting(void)
{
	lcd_setting(lcd.setting);
}

void lcd_menu_seting_datetime(void)
{
	lcd_setting_date_time(lcd.set_datetime, &lcd.datetime);
}

void lcd_menu_service(void)
{
	lcd_service(lcd.service);
}

//Menu Level 2
void lcd_menu_setting_download_data(void)
{
	lcd_setting_download_data(lcd.setting_download_data);
}


void lcd_interface_init(void)
{
	button_init(button_cb);
}
