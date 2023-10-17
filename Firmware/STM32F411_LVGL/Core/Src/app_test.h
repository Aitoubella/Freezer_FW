/*
 * app_test.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Loc
 */

#ifndef SRC_APP_TEST_H_
#define SRC_APP_TEST_H_
#include "ili9341.h"
void testScreenFill(ili9341_t *lcd);
void testScreenLines(ili9341_t *lcd);
void testScreenRects(ili9341_t *lcd);
void testScreenCircles(ili9341_t *lcd);
void testScreenText(ili9341_t *lcd);


void testBoing(ili9341_t *lcd);

#endif /* SRC_APP_TEST_H_ */
