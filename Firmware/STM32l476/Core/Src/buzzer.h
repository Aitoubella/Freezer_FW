/*
 * buzzer.h
 *
 *  Created on: Sep 26, 2023
 *      Author: Loc
 */

#ifndef SRC_BUZZER_H_
#define SRC_BUZZER_H_
#include <stdint.h>
#include "led.h"
extern led_t buzzer;
void buzzer_init(void);

#endif /* SRC_BUZZER_H_ */
