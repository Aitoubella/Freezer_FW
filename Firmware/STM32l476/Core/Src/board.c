/*
 * board.c
 *

 */


#include "board.h"
#include "event.h"
#include "DS1307.h"
#include "lcd_ui.h"
#include "button.h"
#include "buzzer.h"
event_id test_id;
uint8_t arr_wr[] = {0,1,2,3,1,4,5,6,7,89};
uint8_t arr_rd[20] = {1};
date_time_t datetime;
void test_task(void)
{
	DS1307_GetDate(&datetime.day, &datetime.month, &datetime.year);
	DS1307_GetTime(&datetime.hour, &datetime.minute, &datetime.second);
}
void button_cb(uint8_t btn_num, btn_evt_t evt)
{
	switch(btn_num)
	{
	case BTN_ENTER:
		if(evt == BUTTON_SHORT_PRESS)
		{
			led_start_togle(&buzzer, 50, 300, 1);
		}
		break;
	case BTN_UP:
		if(evt == BUTTON_SHORT_PRESS)
		{
			led_start_togle(&buzzer, 50, 300, 2);
		}
		break;
	case BTN_DOWN:
		if(evt == BUTTON_SHORT_PRESS)
		{
			led_start_togle(&buzzer, 50, 300, 3);
		}
		break;
	}
}

void board_test_init(void)
{
	//Test DS1307
//	DS1307_SetDate(23, 10, 2023);
//	DS1307_SetTime(20, 39, 0);
//	event_add(test_task, &test_id, 1000);
//	event_active(&test_id);

	button_init(button_cb);

//	Flash_Write_Array(0, arr_wr, sizeof(arr_wr));
//	Flash_Read_Array(0, arr_rd, sizeof(arr_wr));
//
//	if(memcmp(arr_wr, arr_rd,sizeof(arr_wr)) == 0)
//		led_start_togle(&buzzer, 50, 300, 3);
}



