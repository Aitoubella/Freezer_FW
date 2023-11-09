/*
 * power_board.c
 *
 */

#include "power_board.h"

void power_board_init(void)
{
	PI4IOE_GPIO_Mode_Input(&CMPRSR_D_I_GPIO,PWR_EN_PIN);
	PI4IOE_GPIO_Mode_Ouput(&PWR_EN_GPIO,PWR_EN_PIN);
	PI4IOE_GPIO_Mode_Ouput(&CMPRSR_FAN_VCC_GPIO,CMPRSR_FAN_VCC_PIN);
	PI4IOE_GPIO_Mode_Ouput(&CMPRSR_FAN_GND_GPIO,CMPRSR_FAN_GND_PIN);
	PI4IOE_GPIO_Mode_Ouput(&CMPRSR_EN_GPIO,CMPRSR_EN_PIN);
}

void cmprsr_fan_on(void)
{
	PI4IOE_GPIO_Write(&CMPRSR_FAN_VCC_GPIO,CMPRSR_FAN_VCC_PIN,PI4IO_PIN_SET);
	PI4IOE_GPIO_Write(&CMPRSR_FAN_GND_GPIO,CMPRSR_FAN_GND_PIN,PI4IO_PIN_SET);
}


void cmprsr_fan_off(void)
{
	PI4IOE_GPIO_Write(&CMPRSR_FAN_VCC_GPIO,CMPRSR_FAN_VCC_PIN,PI4IO_PIN_RESET);
	PI4IOE_GPIO_Write(&CMPRSR_FAN_GND_GPIO,CMPRSR_FAN_GND_PIN,PI4IO_PIN_RESET);
}

void cmprsr_power_on(void)
{
	PI4IOE_GPIO_Write(&CMPRSR_EN_GPIO,CMPRSR_EN_PIN,PI4IO_PIN_SET);
}

void cmprsr_pwer_off(void)
{
	PI4IOE_GPIO_Write(&CMPRSR_EN_GPIO,CMPRSR_EN_PIN,PI4IO_PIN_RESET);
}

HAL_StatusTypeDef cmprsr_get_fault(PI4IO_State_t* state)
{
	return PI4IOE_GPIO_Read_Input(&CMPRSR_D_I_GPIO,CMPRSR_D_I_PIN, state);
}


void ext_pwr_enable(void)
{
	HAL_GPIO_WritePin(EX_PWR_ON_GPIO, EX_PWR_ON_PIN, GPIO_PIN_SET);
}

void ext_pwr_disable(void)
{
	HAL_GPIO_WritePin(EX_PWR_ON_GPIO, EX_PWR_ON_PIN, GPIO_PIN_RESET);
}