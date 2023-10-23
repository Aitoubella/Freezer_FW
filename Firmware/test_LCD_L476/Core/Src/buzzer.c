#include "buzzer.h"
#include "event.h"
#include "main.h"
#define BUZZER_ON()          HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_SET);
#define BUZZER_OFF()         HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_SET);
#define BUZZER_TOGLE()       HAL_GPIO_TogglePin(Buzzer_GPIO_Port, Buzzer_Pin)
event_id buzz_id;
#define PATTERN_1               {1,100,500}


enum
{
	BUZZER_STATE_ON = 0,
	BUZZER_STATE_OFF,
};

buzzer buzz = PATTERN_1;
uint8_t count_temp = 0;
uint8_t buzzer_state = BUZZER_STATE_ON;

void buzzer_task(void)
{
	switch(buzzer_state)
	{
	case BUZZER_STATE_ON:
		BUZZER_TOGLE();
		count_temp++;
		if(count_temp >= (buzz.on_count*2)) //Reach max count
		{
			BUZZER_OFF(); //Off buzzer
			event_set_delay(&buzz_id, buzz.off_delay); //Off wating to next step
			count_temp = 0;
			buzzer_state = BUZZER_STATE_OFF;
		}
	case BUZZER_STATE_OFF:
		buzzer_state = BUZZER_STATE_ON;
		event_set_delay(&buzz_id, buzz.on_delay);
		break;
	}
}

void buzzer_init(void)
{
	event_add(buzzer_task,&buzz_id, 100);
}

void buzzer_set_pattern(buzzer pattern_id)
{
	buzz = pattern_id;
}

void buzzer_start(void)
{
	BUZZER_OFF();
	event_set_delay(&buzz_id, buzz.on_delay);
	buzzer_state = BUZZER_STATE_ON;
	event_active(&buzz_id);
}

void buzzer_stop(void)
{
	event_inactive(&buzz_id);
}
