/*
 * lgvl_ili9341_port.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Loc
 */

#ifndef SRC_LVGL_ILI9341_PORT_H_
#define SRC_LVGL_ILI9341_PORT_H_
#include "../lvgl/lvgl.h"
void ILI9341_port_init(void);
void ILI9341_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);


#endif /* SRC_LVGL_ILI9341_PORT_H_ */
