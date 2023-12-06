/*
 * power_board.c
 *
 */


#include "power_board.h"

void power_board_init(void)
{
	PI4IOE_GPIO_Mode_Input(&CMPRSR_D_I_GPIO,PWR_EN_PIN);
	PI4IOE_GPIO_Mode_Ouput(&PWR_EN_GPIO,PWR_EN_PIN);
	PI4IOE_GPIO_Mode_Ouput(&CMPRSR_FAN_GPIO,CMPRSR_FAN_PIN);
	PI4IOE_GPIO_Mode_Ouput(&CMPRSR_EN_GPIO,CMPRSR_EN_PIN);
	cmprsr_fan_off();
	cmprsr_power_off();
}

void cmprsr_fan_on(void)
{
	PI4IOE_GPIO_Write(&CMPRSR_FAN_GPIO,CMPRSR_FAN_PIN,PI4IO_PIN_SET);
}


void cmprsr_fan_off(void)
{
	PI4IOE_GPIO_Write(&CMPRSR_FAN_GPIO,CMPRSR_FAN_PIN,PI4IO_PIN_RESET);
}

void cmprsr_power_on(void)
{
	PI4IOE_GPIO_Write(&CMPRSR_EN_GPIO,CMPRSR_EN_PIN,PI4IO_PIN_SET);
}

void cmprsr_power_off(void)
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


void fan1_on(void)
{
	HAL_GPIO_WritePin(FAN_CTL1_GPIO_Port, FAN_CTL1_Pin, GPIO_PIN_SET);
}

void fan1_off(void)
{
	HAL_GPIO_WritePin(FAN_CTL1_GPIO_Port, FAN_CTL1_Pin, GPIO_PIN_RESET);
}

void fan2_on(void)
{
	HAL_GPIO_WritePin(FAN_CTL2_GPIO_Port, FAN_CTL2_Pin, GPIO_PIN_SET);
}

void fan2_off(void)
{
	HAL_GPIO_WritePin(FAN_CTL2_GPIO_Port, FAN_CTL2_Pin, GPIO_PIN_RESET);
}

void htr_on(void)
{
	HAL_GPIO_WritePin(HTR_CTL_GPIO_Port, HTR_CTL_Pin, GPIO_PIN_SET);
}

void htr_off(void)
{
	HAL_GPIO_WritePin(HTR_CTL_GPIO_Port, HTR_CTL_Pin, GPIO_PIN_RESET);
}

