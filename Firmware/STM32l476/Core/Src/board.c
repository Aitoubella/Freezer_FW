/*
 * board.c
 *
 *  Created on: Oct 23, 2023
 *
 */


#include "board.h"
#include "event.h"
#include "DS1307.h"
#include "lcd_ui.h"

event_id test_id;
volatile uint8_t second, min, hour;
date_time_t datetime;
void test_task(void)
{
	DS1307_GetDate(&datetime.day, &datetime.month, &datetime.year);
	DS1307_GetTime(&datetime.hour, &datetime.minute, &datetime.second);
}

void board_test_init(void)
{
	DS1307_SetDay(23);
	DS1307_SetMonth(10);
	DS1307_SetYear(2023);
	DS1307_SetHour(16);
	DS1307_SetMinute(16);
	DS1307_SetSecond(20);
	event_add(test_task, &test_id, 1000);
	event_active(&test_id);
}
