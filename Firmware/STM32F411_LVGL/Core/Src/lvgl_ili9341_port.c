/*
 * lvgl_ili9341_port.c
 *
 *  Created on: Oct 13, 2023
 *      Author: Loc
 */


#include "lvgl_ili9341_port.h"
#include "ili9341.h"
#include "ili9341_gfx.h"
#include "spi.h"
 ili9341_t *lcd;

 void ILI9341_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p)
 {

	  ili9341_color_t color = (uint16_t *)color_p;//(color_p->ch.red << 11) | (color_p->ch.green << 5) | (color_p->ch.blue);
	  ili9341_fill_rect(lcd, color, area->x1, area->y1, area->x2 - area->x1, area->y2 - area->y1);


	  /* IMPORTANT!!!
	  * Inform the graphics library that you are ready with the flushing*/
	  lv_disp_flush_ready(disp);
 }



void ILI9341_port_init(void)
{
	ili9341_bklight_on();
	lcd = ili9341_new(
		&hspi1,
		TFT_RST_GPIO_Port,   TFT_RST_Pin,
		TFT_CS_GPIO_Port,    TFT_CS_Pin,
		TFT_DC_GPIO_Port,    TFT_DC_Pin,
		isoLandscape,
		NULL,  0,
		NULL, 0,
	    itsNotSupported,
	    itnNONE);


}
