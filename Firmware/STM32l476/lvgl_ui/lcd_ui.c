/*
 * lcd_ui.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Loc
 */


#include "lcd_ui.h"
#include <stdio.h>
#include "event.h"
#include "lvgl.h"
#include "LCDController.h"
#include <stdbool.h>
#define WHITE_COLOR             0xFFFFFF
#define RED_COLOR               0xFF0000
#define YELLOW_COLOR            0xFFFF00

#define MAX_LABEL              10
#define MAX_TEMP_CHAR          30
static char temp_buff[MAX_TEMP_CHAR] = {0};

lv_obj_t* screen;
lv_obj_t* label_list[MAX_LABEL];
uint8_t label_count;

event_id lcd_tick_id;

lv_obj_t* get_label(void)
{
	label_count ++;
	if(label_count >= MAX_LABEL) label_count = 0;
	return label_list[label_count];
}

void lcd_lgvl_tick_handler(void)
{
	lv_timer_handler();
}

void lcd_ui_init(void)
{
	//Init tick for lvgl run


	//Init lvgl library
	lv_init();
	//Init brigde port use SPI
	lv_port_disp_init();

	screen = lv_obj_create(NULL);
	lv_obj_clear_flag( screen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
	lv_obj_set_style_bg_color(screen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_opa(screen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
	//Create label in to main
	for(uint8_t i = 0; i < MAX_LABEL; i ++)
	{
		label_list[i] = lv_label_create(screen);
	}
	event_add(lcd_lgvl_tick_handler, &lcd_tick_id, 5);
	event_active(&lcd_tick_id);
}

void lcd_set_background_color(lv_obj_t* obj, uint32_t color)
{
	lv_obj_set_style_bg_color(obj, lv_color_hex(color), LV_PART_MAIN | LV_STATE_DEFAULT );
}

void lcd_ui_clear(void)
{
	for(uint8_t i = 0; i < MAX_LABEL; i ++)
	{
		lv_label_set_text(label_list[i],"");
	}
}
void lcd_ui_refesh(void)
{
	lv_disp_load_scr(screen);
}

void lcd_label_set_param(lv_obj_t* label, const char* txt, lv_coord_t x, lv_coord_t y, const lv_font_t * font, uint32_t color)
{
	lv_obj_set_width( label, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height( label, LV_SIZE_CONTENT);   /// 1
	lv_obj_set_x( label, x );
	lv_obj_set_y( label, y );
	lv_obj_set_align( label, LV_ALIGN_CENTER );
	lv_label_set_text(label, txt);
	lv_obj_set_style_text_color(label, lv_color_hex(color), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_text_opa(label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(label, font, LV_PART_MAIN| LV_STATE_DEFAULT);
}

void lcd_main_screen_screen(speaker_mode_t sp_mode, int16_t temperature, power_mode_t pwr_mode, operation_mode_t op_mode, uint8_t bat_value, battery_state_t bat_st)
{
	lcd_t speaker_symbol = FONT_VERDENA_24;
	lcd_t temper = FONT_VERDENA_24;
	lcd_t operation_mode = FONT_VERDENA_40;
	lcd_t power_mode = FONT_VERDENA_40;
	lcd_t bat_state = FONT_VERDENA_36;
	lcd_t bat_symbol = FONT_VERDENA_100;
	if(sp_mode ==  SPEAKER_MODE_ON)
	{

		lcd_label_set_param(speaker_symbol.obj, LV_SYMBOL_MUTE, -126, -89, speaker_symbol.font, WHITE_COLOR);
	}

	snprintf(temp_buff,MAX_TEMP_CHAR, "%d°C",temperature);
	lcd_label_set_param(temper.obj, temp_buff, 103, -89, temper.font, WHITE_COLOR);

	if(op_mode == OPERATION_MODE_FREEZER)
	{
		lcd_label_set_param(operation_mode.obj, "Freezer", -2, -18, operation_mode.font, WHITE_COLOR);
	}else
	{
		lcd_label_set_param(operation_mode.obj, "Fridge", -2, -18, operation_mode.font, WHITE_COLOR);
	}

	if(pwr_mode)
	{
		lcd_label_set_param(power_mode.obj, "AC", -104, 63,power_mode.font, WHITE_COLOR);
	}else
	{
		lcd_label_set_param(power_mode.obj, LV_SYMBOL_BATTERY_FULL, -104, 63, power_mode.font, WHITE_COLOR);
	}




	lcd_label_set_param(bat_symbol.obj,  LV_SYMBOL_BATTERY_EMPTY, 60, 62, bat_symbol.font, WHITE_COLOR);
	lcd_set_background_color(bat_symbol.obj, YELLOW_COLOR);
	if(bat_st == BATTERY_STATE_CHARGING)
	{
		snprintf(temp_buff, MAX_TEMP_CHAR, "%d%s",bat_value,LV_SYMBOL_CHARGE);

	}else
	{
		snprintf(temp_buff, MAX_TEMP_CHAR, "%d%%",bat_value);
	}
	lcd_label_set_param(bat_state.obj,temp_buff , 65, 62, bat_state.font, WHITE_COLOR);
	lcd_set_background_color(bat_state.obj, YELLOW_COLOR);
}

void lcd_operation_mode_screen(uint8_t operation_mode)
{
	lv_obj_t* operation_mode_text_obj = get_label();
	lcd_label_set_param(operation_mode_text_obj, "Operation Mode", 0, -96, &ui_font_verdana364, WHITE_COLOR);

	lv_obj_t* operation_mode_fridge_obj = get_label();
	lv_obj_t* operation_mode_freezer_obj = get_label();
	lv_obj_t* operation_mode_back_obj = get_label();
	if(operation_mode == OPERATION_MODE_FREEZER)
	{
		lcd_label_set_param(operation_mode_fridge_obj, "Fridge", 0, -28, &ui_font_verdana244, WHITE_COLOR);
		lcd_label_set_param(operation_mode_freezer_obj,"Freezer", 0, 10, &ui_font_verdana404, WHITE_COLOR);
		lcd_label_set_param(operation_mode_back_obj, "Back", 0, 51, &ui_font_verdana244, WHITE_COLOR);
	}else if(operation_mode == OPERATION_MODE_FRIDEGE)
	{
		lcd_label_set_param(operation_mode_fridge_obj, "Fridge", 0, -14, &ui_font_verdana404, WHITE_COLOR);
		lcd_label_set_param(operation_mode_freezer_obj,"Freezer", 0, 10, &ui_font_verdana244, WHITE_COLOR);
		lcd_label_set_param(operation_mode_back_obj, "Back", 0, 51, &ui_font_verdana244, WHITE_COLOR);
	}else
	{
		lcd_label_set_param(operation_mode_fridge_obj, "Fridge", 0, 10, &ui_font_verdana244, WHITE_COLOR);
		lcd_label_set_param(operation_mode_freezer_obj,"Freezer", 0, 10, &ui_font_verdana244, WHITE_COLOR);
		lcd_label_set_param(operation_mode_back_obj, "Back", 0, 51, &ui_font_verdana404, WHITE_COLOR);
	}
}

void lcd_turn_off_unit(display_unit_t value)
{
	lv_obj_t* turn_unit_obj = get_label();
	lcd_label_set_param(turn_unit_obj, "Turn off unit?", 0, -96, &ui_font_verdana364, WHITE_COLOR);
	lv_obj_t* yes_obj = get_label();
	lv_obj_t* no_obj = get_label();
	if(value == ON)
	{
		lcd_label_set_param(yes_obj, "YES", 0, -11, &ui_font_verdana404, WHITE_COLOR);
		lcd_label_set_param(no_obj, "NO", 0, 28, &ui_font_verdana244, WHITE_COLOR);
	}else
	{
		lcd_label_set_param(yes_obj, "YES", 0, -11, &ui_font_verdana244, WHITE_COLOR);
		lcd_label_set_param(no_obj, "NO", 0, 28, &ui_font_verdana404, WHITE_COLOR);
	}
	lcd_ui_refesh();
}

void lcd_setting(setting_t setting)
{
	lv_obj_t* setting_obj = get_label();
	lcd_label_set_param(setting_obj, "Setting", 0, -96, &ui_font_verdana364, WHITE_COLOR);
	lv_obj_t* datetime_obj = get_label();
	lv_obj_t* download_data_obj = get_label();
	lv_obj_t* back_obj = get_label();
	if(setting == SETTING_DATE_TIME)
	{
		lcd_label_set_param(datetime_obj, "Date/Time", 0, -47, &ui_font_verdana404, WHITE_COLOR);
		lcd_label_set_param(download_data_obj, "Download Data", 0, 0, &ui_font_verdana244, WHITE_COLOR);
		lcd_label_set_param(back_obj, "Back", 0, 47, &ui_font_verdana244, WHITE_COLOR);
	}else if(setting == SETTING_DOWNLOAD_DATA)
	{
		lcd_label_set_param(datetime_obj, "Date/Time", 0, -47, &ui_font_verdana244, WHITE_COLOR);
		lcd_label_set_param(download_data_obj, "Download Data", 0, 0, &ui_font_verdana404, WHITE_COLOR);
		lcd_label_set_param(back_obj, "Back", 0, 47, &ui_font_verdana244, WHITE_COLOR);
	}else
	{
		lcd_label_set_param(datetime_obj, "Date/Time", 0, -47, &ui_font_verdana244, WHITE_COLOR);
		lcd_label_set_param(download_data_obj, "Download Data", 0, 0, &ui_font_verdana244, WHITE_COLOR);
		lcd_label_set_param(back_obj, "Back", 0, 47, &ui_font_verdana404, WHITE_COLOR);
	}
}


void lcd_setting_date_time(setting_date_time_t index, date_time_t* time)
{
	lv_obj_t* year_obj = get_label();
	lv_obj_t* month_obj = get_label();
	lv_obj_t* day_obj = get_label();
	lv_obj_t* hour_obj = get_label();
	lv_obj_t* minute_obj = get_label();
	lv_obj_t* back_obj = get_label();
	const lv_font_t* year_font = &ui_font_verdana244;
	const lv_font_t* month_font = &ui_font_verdana244;
	const lv_font_t* day_font = &ui_font_verdana244;
	const lv_font_t* hour_font = &ui_font_verdana244;
	const lv_font_t* minute_font = &ui_font_verdana244;
	const lv_font_t* back_font = &ui_font_verdana244;


	if(index == SETTING_DATE_TIME_YEAR)
	{
		year_font = &ui_font_verdana404;
	}else if(index == SETTING_DATE_TIME_MONTH)
	{
		month_font = &ui_font_verdana404;
	}else if(index == SETTING_DATE_TIME_DAY)
	{
		day_font = &ui_font_verdana404;
	}else if(index == SETTING_DATE_TIME_HOUR)
	{
		hour_font = &ui_font_verdana404;
	}else if(index == SETTING_DATE_TIME_MINUTE)
	{
		minute_font = &ui_font_verdana404;
	}else if(index == SETTING_DATE_TIME_BACK)
	{
		back_font = &ui_font_verdana404;
	}


	snprintf(temp_buff,MAX_TEMP_CHAR,"Set Year: %2d", 2000 + time->year);
	lcd_label_set_param(year_obj, temp_buff, 0, -85, year_font, WHITE_COLOR);
	snprintf(temp_buff,MAX_TEMP_CHAR,"Set Month: %2d", time->month);
	lcd_label_set_param(month_obj, temp_buff, 0, -46, month_font, WHITE_COLOR);
	snprintf(temp_buff,MAX_TEMP_CHAR,"Set Day: %2d", time->day);
	lcd_label_set_param(day_obj, temp_buff, 0, -13, day_font, WHITE_COLOR);
	snprintf(temp_buff,MAX_TEMP_CHAR,"Set Hour: %2d", time->hour);
	lcd_label_set_param(hour_obj, temp_buff, 0, 19, hour_font, WHITE_COLOR);
	snprintf(temp_buff,MAX_TEMP_CHAR,"Set Minute: %2d", time->minute);
	lcd_label_set_param(minute_obj, temp_buff, 0, 52, minute_font, WHITE_COLOR);
	lcd_label_set_param(back_obj, "Back", 0, 84, back_font, WHITE_COLOR);
}


void lcd_service(service_t index)
{
	lcd_t service = FONT_VERDENA_36;
	lcd_t temperature = FONT_VERDENA_24;
	lcd_t alarm = FONT_VERDENA_24;
	lcd_t data_logging = FONT_VERDENA_24;
	lcd_t calibration = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;


	if(index == SERVICE_TEMPERATURE)
	{
		temperature.font = &ui_font_verdana404;
	}else if(index == SERVICE_ALARM)
	{
		alarm.font = &ui_font_verdana404;
	}else if(index == SERVICE_DATA_LOGGING)
	{
		data_logging.font = &ui_font_verdana404;
	}else if(index == SERVICE_CALIBRATION)
	{
		calibration.font = &ui_font_verdana404;
	}
	else if(index == SERVICE_BACK)
	{
		back.font = &ui_font_verdana404;
	}

	lcd_label_set_param(service.obj, "Service", 0, -96, service.font, WHITE_COLOR);
	lcd_label_set_param(temperature.obj, "Temperature", 0, -49, temperature.font, WHITE_COLOR);
	lcd_label_set_param(alarm.obj, "Alarms", 0, -17, alarm.font, WHITE_COLOR);
	lcd_label_set_param(data_logging.obj, "Data Logging", 0, 13, data_logging.font, WHITE_COLOR);
	lcd_label_set_param(calibration.obj, "Calibration", 0, 52, calibration.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 88, back.font, WHITE_COLOR);
}

void lcd_service_temperature(service_temperature_t index)
{
	lcd_t temperature = FONT_VERDENA_36;
	lcd_t fridge = FONT_VERDENA_24;
	lcd_t freezer = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;

	if(index == SERVICE_TEMPERATURE_FRIDGE)
	{
		fridge.font = &ui_font_verdana404;
	}else if(index == SERVICE_TEMPERATURE_FREEZER)
	{
		freezer.font = &ui_font_verdana404;
	}else if(index == SERVICE_TEMPERATURE_BACK)
	{
		back.font = &ui_font_verdana404;
	}

	lcd_label_set_param(temperature.obj, "Temperature", 0, -96, temperature.font, WHITE_COLOR);
	lcd_label_set_param(fridge.obj, "Fridge", 0, -29, fridge.font, WHITE_COLOR);
	lcd_label_set_param(freezer.obj, "Freezer", 0, 10, freezer.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 51, back.font, WHITE_COLOR);
	lcd_ui_refesh();
}

void lcd_service_alarms(service_alarm_t index)
{
	lcd_t alarm = FONT_VERDENA_36;
	lcd_t temperature = FONT_VERDENA_24;
	lcd_t bat = FONT_VERDENA_24;
	lcd_t lid = FONT_VERDENA_24;
	lcd_t mute = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;

	if(index == SERVICE_ALARMS_TEMPERATURE)
	{
		temperature.font = &ui_font_verdana404;
	}else if(index == SERVICE_ALARMS_BATTERY)
	{
		bat.font = &ui_font_verdana404;
	}else if(index == SERVICE_ALARMS_LID)
	{
		lid.font = &ui_font_verdana404;
	}else if(index == SERVICE_ALARMS_MUTE_AlARMS)
	{
		mute.font = &ui_font_verdana404;
	}else
	{
		back.font = &ui_font_verdana404;
	}

	lcd_label_set_param(alarm.obj, "Alarms", 0, -96, alarm.font, WHITE_COLOR);
	lcd_label_set_param(temperature.obj, "Temperature", 0, -54, temperature.font, WHITE_COLOR);
	lcd_label_set_param(bat.obj, "Battery", 0, -15, bat.font, WHITE_COLOR);
	lcd_label_set_param(lid.obj, "Lid", 0, 23, lid.font, WHITE_COLOR);
	lcd_label_set_param(mute.obj, "Alarms Duration", 0, 61, mute.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 96, back.font, WHITE_COLOR);
}

void lcd_service_data_logging(service_data_logging_t index)
{
	lcd_t data_logging = FONT_VERDENA_36;
	lcd_t logging_interval = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;


	if(index == SERVICE_DATA_LOGGING_INTERVAL)
	{
		logging_interval.font = &ui_font_verdana404;
	}else if(index == SERVICE_DATA_LOGGING_BACK)
	{
		back.font = &ui_font_verdana404;
	}

	lcd_label_set_param(data_logging.obj, "Data Logging", 0, -96, data_logging.font, WHITE_COLOR);
	lcd_label_set_param(logging_interval.obj, "Logging Interval", 0, 0, logging_interval.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 38, back.font, WHITE_COLOR);
	lcd_ui_refesh();
}

void lcd_service_data_logging_set(uint8_t value)
{
	lcd_t logging_interval = FONT_VERDENA_36;
	lcd_t time_1 = FONT_VERDENA_24;
	lcd_t time_2 = FONT_VERDENA_40;
	lcd_t time_3 = FONT_VERDENA_24;
	lcd_label_set_param(logging_interval.obj, "Logging Interval", 0, -70, logging_interval.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value + 1);
	lcd_label_set_param(time_1.obj, temp_buff, 0, 0, time_1.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value);
	lcd_label_set_param(time_2.obj, temp_buff, 0, 37, time_2.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value - 1);
	lcd_label_set_param(time_3.obj, temp_buff, 0, 74, time_3.font, WHITE_COLOR);
}

void lcd_service_data_calibration(service_calibration_t index)
{
	lcd_t calibration = FONT_VERDENA_36;
	lcd_t temp_offset = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;


	if(index == SERVICE_CALIBRATION_TEMP_OFFSET)
	{
		temp_offset.font = &ui_font_verdana404;
	}else if(index == SERVICE_CALIBRATION_BACK)
	{
		back.font = &ui_font_verdana404;
	}

	lcd_label_set_param(calibration.obj, "Calibration", 0, -96, calibration.font, WHITE_COLOR);
	lcd_label_set_param(temp_offset.obj, "Temp Offset", 0, 0, temp_offset.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 38, back.font, WHITE_COLOR);
}

void lcd_service_data_calibration_set(uint8_t value)
{
	lcd_t temp_offset = FONT_VERDENA_36;
	lcd_t temper_1 = FONT_VERDENA_24;
	lcd_t temper_2 = FONT_VERDENA_40;
	lcd_t temper_3 = FONT_VERDENA_24;
	lcd_label_set_param(temp_offset.obj, "Temp Offset", 0, -70, temp_offset.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value + 1);
	lcd_label_set_param(temper_1.obj, temp_buff, 0, 0, temper_1.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value);
	lcd_label_set_param(temper_2.obj, temp_buff, 0, 37, temper_2.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value - 1);
	lcd_label_set_param(temper_3.obj, temp_buff, 0, 74, temper_3.font, WHITE_COLOR);
}

void lcd_service_temperature_fridge(service_temperature_fridge_t index, int8_t value)
{
	lcd_t fridge = FONT_VERDENA_36;
	lcd_t set_point = FONT_VERDENA_36;
	lcd_t temper = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;

	if(index == SERVICE_TEMPERATURE_FRIDGE_VALUE)
	{
		temper.font = &ui_font_verdana364;
	}else
	{
		back.font = &ui_font_verdana364;
	}

	lcd_label_set_param(fridge.obj, "Fridge", 0, -96, fridge.font, WHITE_COLOR);
	lcd_label_set_param(set_point.obj, "Set Point", 0, -48, set_point.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value);
	lcd_label_set_param(temper.obj,temp_buff, 0, 8, temper.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 51, back.font, WHITE_COLOR);
}

void lcd_service_temperature_freezer(service_temperature_freezer_t index, int8_t value)
{
	lcd_t freezer = FONT_VERDENA_36;
	lcd_t set_point = FONT_VERDENA_36;
	lcd_t temper = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;

	if(index == SERVICE_TEMPERATURE_FREEZER_VALUE)
	{
		temper.font = &ui_font_verdana364;
	}else
	{
		back.font = &ui_font_verdana364;
	}

	lcd_label_set_param(freezer.obj, "Freezer", 0, -96, freezer.font, WHITE_COLOR);
	lcd_label_set_param(set_point.obj, "Set Point", 0, -48, set_point.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value);
	lcd_label_set_param(temper.obj, temp_buff, 0, 8, temper.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 51, back.font, WHITE_COLOR);
	lcd_ui_refesh();
}

void lcd_service_temperature_fridge_set(int8_t value)
{
	lcd_t mode = FONT_VERDENA_36;
	lcd_t set_point = FONT_VERDENA_36;
	lcd_t temper_1 = FONT_VERDENA_24;
	lcd_t temper_2 = FONT_VERDENA_40;
	lcd_t temper_3 = FONT_VERDENA_24;


	lcd_label_set_param(mode.obj, "Fridge", 0, -96, mode.font, WHITE_COLOR);

	lcd_label_set_param(set_point.obj, "Set Point", 0, -48, set_point.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value + 1);
	lcd_label_set_param(temper_1.obj, temp_buff, 0, 0, temper_1.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value);
	lcd_label_set_param(temper_2.obj, temp_buff, 0, 37, temper_2.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value - 1);
	lcd_label_set_param(temper_3.obj, temp_buff, 0, 74, temper_3.font, WHITE_COLOR);
}

void lcd_service_temperature_freezer_set(int8_t value)
{
	lcd_t mode = FONT_VERDENA_36;
	lcd_t set_point = FONT_VERDENA_36;
	lcd_t temper_1 = FONT_VERDENA_24;
	lcd_t temper_2 = FONT_VERDENA_40;
	lcd_t temper_3 = FONT_VERDENA_24;


	lcd_label_set_param(mode.obj, "Freezer", 0, -96, mode.font, WHITE_COLOR);

	lcd_label_set_param(set_point.obj, "Set Point", 0, -48, set_point.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value + 1);
	lcd_label_set_param(temper_1.obj, temp_buff, 0, 0, temper_1.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value);
	lcd_label_set_param(temper_2.obj, temp_buff, 0, 37, temper_2.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value - 1);
	lcd_label_set_param(temper_3.obj, temp_buff, 0, 74, temper_3.font, WHITE_COLOR);
}

void lcd_service_alarm_temperature(service_alarms_temperature_t index)
{
	lcd_t temp_deviation = FONT_VERDENA_24;
	lcd_t alarm_delay = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;
	if(index == SERVICE_ALARM_TEMP_TEMP_DEVIATION)
	{
		temp_deviation.font = &ui_font_verdana404;
	}else if(index == SERVICE_ALARM_TEMP_ALARM_DELAY)
	{
		alarm_delay.font = &ui_font_verdana404;
	}else
	{
		back.font = &ui_font_verdana404;
	}

	lcd_label_set_param(temp_deviation.obj, "Temp Deviation", 0, -60, temp_deviation.font, WHITE_COLOR);
	lcd_label_set_param(alarm_delay.obj, "Alarm Delay", 0, 0, alarm_delay.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 60, back.font, WHITE_COLOR);
}

void lcd_service_alarm_temperature_temp_deviation_set(int8_t value)
{
	lcd_t temp_deviation = FONT_VERDENA_36;

	lcd_t temper_1 = FONT_VERDENA_24;
	lcd_t temper_2 = FONT_VERDENA_40;
	lcd_t temper_3 = FONT_VERDENA_24;
	lcd_label_set_param(temp_deviation.obj, "Temp Deviation", 0, -70, temp_deviation.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value + 1);
	lcd_label_set_param(temper_1.obj, temp_buff, 0, 0, temper_1.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value);
	lcd_label_set_param(temper_2.obj, temp_buff, 0, 37, temper_2.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d°C",value - 1);
	lcd_label_set_param(temper_3.obj, temp_buff, 0, 74, temper_3.font, WHITE_COLOR);
}

void lcd_service_alarm_temperature_alarm_delay_set(uint8_t value)
{
	lcd_t temp_deviation = FONT_VERDENA_36;

	lcd_t temper_1 = FONT_VERDENA_24;
	lcd_t temper_2 = FONT_VERDENA_40;
	lcd_t temper_3 = FONT_VERDENA_24;
	lcd_label_set_param(temp_deviation.obj, "Alarm Delay", 0, -70, temp_deviation.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value + 1);
	lcd_label_set_param(temper_1.obj, temp_buff, 0, 0, temper_1.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value);
	lcd_label_set_param(temper_2.obj, temp_buff, 0, 37, temper_2.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value - 1);
	lcd_label_set_param(temper_3.obj, temp_buff, 0, 74, temper_3.font, WHITE_COLOR);
}

void lcd_service_alarm_bat(service_alarms_bat_t index, uint8_t value)
{
	lcd_t alarm_bat = FONT_VERDENA_36;
	lcd_t temp_value = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;

	if(index == SERVICE_ALARM_BAT_VALUE)
	{
		temp_value.font = &ui_font_verdana404;
	}else
	{
		back.font = &ui_font_verdana404;
	}
	lcd_label_set_param(alarm_bat.obj, "Battery Alarm", 0, -78, alarm_bat.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d%%",value);
	lcd_label_set_param(temp_value.obj, temp_buff, 0, 0, temp_value.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 44, back.font, WHITE_COLOR);
}

void lcd_service_alarm_bat_set(uint8_t value)
{
	lcd_t bat_alarm = FONT_VERDENA_36;

	lcd_t percent_1 = FONT_VERDENA_24;
	lcd_t percent_2 = FONT_VERDENA_40;
	lcd_t percent_3 = FONT_VERDENA_24;
	lcd_label_set_param(bat_alarm.obj, "Alarm Delay", 0, -70, bat_alarm.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d %%",value + 1);
	lcd_label_set_param(percent_1.obj, temp_buff, 0, 0, percent_1.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d %%",value);
	lcd_label_set_param(percent_2.obj, temp_buff, 0, 37, percent_2.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d %%",value - 1);
	lcd_label_set_param(percent_3.obj, temp_buff, 0, 74, percent_3.font, WHITE_COLOR);
}

void lcd_service_alarm_lid(service_alarms_lid_t index, uint8_t value)
{
	lcd_t alarm_lid = FONT_VERDENA_36;
	lcd_t time = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;

	if(index == SERVICE_ALARM_LID_VALUE)
	{
		time.font = &ui_font_verdana404;
	}else
	{
		back.font = &ui_font_verdana404;
	}
	lcd_label_set_param(alarm_lid.obj, "Lid Alarm", 0, -78, alarm_lid.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d%%",value);
	lcd_label_set_param(time.obj, temp_buff, 0, 0, time.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 44, back.font, WHITE_COLOR);
}

void lcd_service_alarm_lid_set(uint8_t value)
{
	lcd_t lid_alarm = FONT_VERDENA_36;

	lcd_t time_1 = FONT_VERDENA_24;
	lcd_t time_2 = FONT_VERDENA_40;
	lcd_t time_3 = FONT_VERDENA_24;
	lcd_label_set_param(lid_alarm.obj, "Lid Alarm", 0, -70, lid_alarm.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value + 1);
	lcd_label_set_param(time_1.obj, temp_buff, 0, 0, time_1.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value);
	lcd_label_set_param(time_2.obj, temp_buff, 0, 37, time_2.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value - 1);
	lcd_label_set_param(time_3.obj, temp_buff, 0, 74, time_3.font, WHITE_COLOR);
}


void lcd_service_alarms_mute_duration(service_alarms_mute_duration_t index, uint8_t value)
{
	lcd_t mute_duration = FONT_VERDENA_36;
	lcd_t time = FONT_VERDENA_24;
	lcd_t back = FONT_VERDENA_24;

	if(index == SERVICE_ALARM_MUTE_DURATION_VALUE)
	{
		time.font = &ui_font_verdana404;
	}else
	{
		back.font = &ui_font_verdana404;
	}
	lcd_label_set_param(mute_duration.obj, "Mute Duration", 0, -78, mute_duration.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d%%",value);
	lcd_label_set_param(time.obj, temp_buff, 0, 0, time.font, WHITE_COLOR);
	lcd_label_set_param(back.obj, "Back", 0, 44, back.font, WHITE_COLOR);
}

void lcd_service_alarms_mute_duration_set(uint8_t value)
{
	lcd_t mute_duration = FONT_VERDENA_36;
	lcd_t time_1 = FONT_VERDENA_24;
	lcd_t time_2 = FONT_VERDENA_40;
	lcd_t time_3 = FONT_VERDENA_24;
	lcd_label_set_param(mute_duration.obj, "Mute Duration", 0, -70, mute_duration.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value + 1);
	lcd_label_set_param(time_1.obj, temp_buff, 0, 0, time_1.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value);
	lcd_label_set_param(time_2.obj, temp_buff, 0, 37, time_2.font, WHITE_COLOR);
	snprintf(temp_buff, MAX_TEMP_CHAR, "%d mins",value - 1);
	lcd_label_set_param(time_3.obj, temp_buff, 0, 74, time_3.font, WHITE_COLOR);
}


void lcd_service_alarms_warning(warning_mode_t mode, warning_type_t type)
{

	lcd_t mode_obj = FONT_VERDENA_40;
	lcd_t type_obj = FONT_VERDENA_36;
	lcd_t warning_symbol = FONT_VERDENA_40;
	lcd_set_background_color(screen, RED_COLOR);
	if(mode == WARNING_MODE_FRIDGE)
	{
		lcd_label_set_param(mode_obj.obj, "Fridge", 0, -70, mode_obj.font, WHITE_COLOR);
	}else
	{
		lcd_label_set_param(mode_obj.obj, "Freezer", 0, -70, mode_obj.font, WHITE_COLOR);
	}

	if(type == WARNING_TYPE_UNDER_MIN_TEMP)
	{
		lcd_label_set_param(type_obj.obj, "Under Min\nTemp", 40, 45, type_obj.font, WHITE_COLOR);
	}else if(type == WARNING_TYPE_OVER_MAX_TEMP)
	{
		lcd_label_set_param(type_obj.obj, "Over Max\nTemp", 40, 45, type_obj.font, WHITE_COLOR);
	}else if(type == WARNING_TYPE_LID_OPEN)
	{
		lcd_label_set_param(type_obj.obj, "Lid Open", 40, 45, type_obj.font, WHITE_COLOR);
	}else
	{
		lcd_label_set_param(type_obj.obj, "Lid Close", 40, 45, type_obj.font, WHITE_COLOR);
	}

	lcd_label_set_param(warning_symbol.obj, LV_SYMBOL_WARNING, -108, 32, warning_symbol.font, WHITE_COLOR);
}


