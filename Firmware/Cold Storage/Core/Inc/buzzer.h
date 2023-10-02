/*
 * buzzer.h
 *
 *  Created on: Sep 26, 2023
 *      Author: Loc
 */

#ifndef SRC_BUZZER_H_
#define SRC_BUZZER_H_
#include <stdint.h>

typedef struct
{
	uint8_t on_count;
	uint8_t on_delay;  //ms
	uint16_t off_delay; //ms
}buzzer;

void buzzer_init(void);
void buzzer_start(void);
void buzzer_stop(void);
void buzzer_set_pattern(buzzer pattern_id);
#endif /* SRC_BUZZER_H_ */
