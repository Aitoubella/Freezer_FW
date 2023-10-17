/*
 * app_test.c
 *
 *  Created on: Oct 13, 2023
 *      Author: Loc
 */


#include "app_test.h"
#include "ili9341.h"
#include "ili9341_gfx.h"
#include "boing.h"

#define TEST_BOING 1
static ili9341_bool_t _boingInitialized;

void testScreenFill(ili9341_t *lcd)
{
  ili9341_fill_screen(lcd, ILI9341_BLUE);
  HAL_Delay(500);
  ili9341_fill_screen(lcd, ILI9341_RED);
  HAL_Delay(500);
  ili9341_fill_screen(lcd, ILI9341_GREEN);
  HAL_Delay(500);
}

void testScreenLines(ili9341_t *lcd)
{
  ili9341_fill_screen(lcd, ILI9341_BLACK);

  ili9341_color_t color;
  uint8_t wheel = 0U;

  for (int32_t i = 0; i < lcd->screen_size.height; i += 10)
    { color = ili9341_color_wheel(&wheel); wheel += 3;
      ili9341_draw_line(lcd, color, 0, 0, lcd->screen_size.width, i); }
  for (int32_t i = lcd->screen_size.width; i >= 0; i -= 10)
    { color = ili9341_color_wheel(&wheel); wheel += 3;
      ili9341_draw_line(lcd, color, 0, 0, i, lcd->screen_size.height); }

  HAL_Delay(500);

  for (int32_t i = 0; i < lcd->screen_size.height; i += 10)
    { color = ili9341_color_wheel(&wheel); wheel += 3;
      ili9341_draw_line(lcd, color, lcd->screen_size.width, lcd->screen_size.height, 0, lcd->screen_size.height - i); }
  for (int32_t i = lcd->screen_size.width; i >= 0; i -= 10)
    { color = ili9341_color_wheel(&wheel); wheel += 3;
      ili9341_draw_line(lcd, color, lcd->screen_size.width, lcd->screen_size.height, lcd->screen_size.width - i, 0); }
}

void testScreenRects(ili9341_t *lcd)
{
  ili9341_fill_screen(lcd, ILI9341_BLACK);

  ili9341_color_t color;
  uint8_t wheel = 0U;

  for (uint16_t i = 0, in = 0; i < lcd->screen_size.width; i += 16, ++in) {
    for (uint16_t j = 0, jn = 0; j < lcd->screen_size.height; j += 16, ++jn) {
      color = ili9341_color_wheel(&wheel);
      if ((in & 1) == (jn & 1)) {
        ili9341_fill_rect(lcd, color, i, j, 16, 16);
      } else {
        ili9341_draw_rect(lcd, ~color, i+2, j+2, 12, 12);
      }
    }
  }
}

void testScreenCircles(ili9341_t *lcd)
{
  ili9341_fill_screen(lcd, ILI9341_BLACK);

  uint16_t x_mid = lcd->screen_size.width / 2;
  uint16_t y_mid = lcd->screen_size.height / 2;
  uint16_t radius = x_mid;
  if (radius < y_mid)
    { radius = y_mid; }

  ili9341_color_t color;
  uint8_t wheel = 0U;

  for (int16_t i = radius; i >= 0; i -= 6) {
    color = ili9341_color_wheel(&wheel);
    wheel += 9;
    ili9341_fill_circle(lcd, color, x_mid, y_mid, i);
  }

  HAL_Delay(500);

  for (int16_t i = 0, n = 0; i < lcd->screen_size.width; i += 24, ++n) {
    for (int16_t j = 0, m = 0; j < lcd->screen_size.height; j += 24, ++m) {

      color = ili9341_color_wheel(&wheel);
      wheel += 3;

      if ((n & 1) == (m & 1)) {
        ili9341_draw_circle(lcd, color, i + 12, j + 12, 16);
        ili9341_draw_circle(lcd, color, i + 12, j + 12, 10);
        ili9341_draw_circle(lcd, color, i + 12, j + 12, 4);
      }
      else {
        ili9341_draw_circle(lcd, color, i + 12, j + 12, 8);
      }
    }
  }
}

void testScreenText(ili9341_t *lcd)
{
  ili9341_fill_screen(lcd, ILI9341_BLACK);

  ili9341_text_attr_t textAttr = (ili9341_text_attr_t){
    .font = &ili9341_font_11x18,
    .fg_color = ILI9341_WHITE,
    .bg_color = ILI9341_RED,
    .origin_x = 10,
    .origin_y = 10
  };
  ili9341_draw_string(lcd, textAttr, "Hello world!");

}



#if defined(TEST_BOING)
void testBoing(ili9341_t *lcd)
{
  static boing_ball_t ball;

  if (ibNOT(_boingInitialized)) {
    ili9341_draw_bitmap_1b(lcd, BOING_COLOR_PLOT_SHADOW, BOING_COLOR_PLOT_COLOR,
        0, 0, 320, 240, (uint8_t *)BOING_PLOT);
    _boingInitialized = ibTrue;
    boing_init(&ball);
  }
  else {
    boing(lcd, &ball);
  }
}
#endif
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
