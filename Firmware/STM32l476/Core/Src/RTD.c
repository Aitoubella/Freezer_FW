/*
 * RTD.c
 *

 */


#include "RTD.h"
#include "main.h"
#include "adc.h"
#define ADC_VREF_mV 3300       //Voltage adc in mV
#include "event.h"
#define RTD_MAX_CHANNEL   6
uint32_t adc_buff[RTD_MAX_CHANNEL];
uint16_t temper[RTD_MAX_CHANNEL];
event_id rtd_id;

#define MAX_TEMPERATURE

uint32_t adc_to_mV(uint32_t input)
{
	return input * ADC_VREF_mV/4095;
}

uint32_t mV_to_ohm(uint32_t input)
{
	return input/2;
}

uint32_t ohm_to_temperature(uint32_t input)
{
	return input*375;
}
void rtd_task(void)
{
	for(uint8_t i = 0; i < RTD_MAX_CHANNEL; i++)
	{
		temper[i] =  ohm_to_temperature(mV_to_ohm(adc_to_mV(adc_buff[i])));
	}
}
void rtd_init(void)
{
	event_add(rtd_task, &rtd_id, 100);
	event_active(&rtd_id);
	HAL_ADC_Start_DMA(&hadc1, adc_buff, 6);
}



