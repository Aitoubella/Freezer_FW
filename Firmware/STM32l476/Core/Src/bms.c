 /*
 bms.c
 *
 *  Created on: Nov 23, 2023
 *     
 */
#include "BQ25731.h"
#include "main.h"
#include "event.h"
#include "bms.h"
event_id bms_id;
#define BATTERY_CELL         1


#define VOLTAGE_BATTERY     (CHARGE_VOLTAGE_4200MV*BATTERY_CELL)
#define MIN_VOLTATE         (3700*BATTERY_CELL)

static bq25731_t bq25731;

static charge_info_t charge =
{
	.status = &bq25731.ChargerStatus,
	.max_charge_voltage = VOLTAGE_BATTERY,
	.bat_min_voltage = MIN_VOLTATE,
};


void bms_task(void)
{
	bq25731_get_charge_status(&bq25731);
	bq25731_get_charge_discharge_current(&bq25731, &charge.charge_current,&charge.discharge_curret);;
	bq25731_get_sys_and_bat_voltage(&bq25731, &charge.bat_voltage, &charge.sys_voltage);
	bq25731_get_vbus_psys(&bq25731,&charge.bus_voltage, &charge.power_sys);
}

HAL_StatusTypeDef bms_init(void)
{
	//Config battery param
	HAL_StatusTypeDef status = 0;
	status = bq25731_charge_option_0_clear_bit(0, EN_LPWR_BIT); //Disable low power function for ADC convert block work
	if(status != HAL_OK) return status;
	status = bq25731_charge_option_1(0, EN_IBAT_BIT);   //Enable Ibat buffer
	if(status != HAL_OK) return status;
	status = bq25731_charge_option_3(0,EN_ICO_MODE_BIT); //Enable Auto mode
	if(status != HAL_OK) return status;
	status = bq25731_set_charge_voltage(VOLTAGE_BATTERY); //Set charge voltage
	if(status != HAL_OK) return status;
	status = bq25731_set_bit_reg(INPUT_CURRENT_LIMIT_USE_REG, 0,INPUT_CURRENT_3200_MA_BIT); //Set max current input of power source
	if(status != HAL_OK) return status;
	status = bq25731_set_bit_reg(INPUT_VOLTAGE_REG, 0,INPUT_VOLTAGE_8192_MV_BIT); //Set min drop input voltage to 8192 mV
	if(status != HAL_OK) return status;
	status = bq25731_clear_bit_reg(CHARGE_OPTION_2_REG, EN_EXTILIM_BIT, 0); //Disable external limit current circuit pin
	if(status != HAL_OK) return status;
	status = bq25731_set_bit_reg(CHARGE_OPTION_2_REG,EN_ICHG_IDCHG_BIT,0); //Enable IBAT is charge current
	if(status != HAL_OK) return status;
	status = bq25731_clear_bit_reg(CHARGE_OPTION_3_REG, OTG_VAP_MODE_BIT, 0); //Disable control OTG/VAP use by external pin
	if(status != HAL_OK) return status;
	status = bq25731_clear_bit_reg(CHARGE_OPTION_0_REG, 0, WDTMR_ADJ_ENABLE_175S_BIT);//Clear 2 bit  to disable watchdog
	if(status != HAL_OK) return status;
	//Enable ADC VSYS,VBUS, VBAT ,I charge,I discharge and start ADC with continuous mode
	status = bq25731_set_adc_option(EN_ADC_IIN_BIT|EN_ADC_VBUS_BIT|EN_ADC_VSYS_BIT|EN_ADC_VBAT_BIT|EN_ADC_IDCHG_BIT|EN_ADC_ICHG_BIT, ADC_START_BIT|ADC_CONV_BIT);
	if(status != HAL_OK) return status;

	status = bq25731_read_charge_option_0(&bq25731);
	if(status != HAL_OK) return status;
	status = bq25731_read_charge_option_1(&bq25731);
	if(status != HAL_OK) return status;
	status = bq25731_read_charge_option_2(&bq25731);
	if(status != HAL_OK) return status;
	status = bq25731_read_charge_option_3(&bq25731);
	if(status != HAL_OK) return status;
	status = bq25731_read_reg(ADC_OPTION_REG, (uint8_t *)&bq25731.ADCOption, 2); //Read back ADC option
	if(status != HAL_OK) return status;
	status = bq25731_set_charge_current();
	if(status != HAL_OK) return status;


	//Add task run 1 second duty
	event_add(bms_task, &bms_id, 1000);
	event_active(&bms_id);

	return status;
}

charge_info_t* bms_get_charge_info(void)
{
	return &charge;
}
