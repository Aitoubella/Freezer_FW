

#include "BQ25731.h"
#include "i2c.h"
#include "main.h"
#include <string.h>
#define BQ25731_I2C     hi2c1
#define BQ25731_ADDR    0x6B


HAL_StatusTypeDef bq25731_read_reg(uint8_t reg, uint8_t *data, uint8_t len)
#define BIT_TO_DEC(x,y) ((x##y) << y)
#define VOLTAGE_BATTERY     CHARGE_VOLTAGE_4200MV



HAL_StatusTypeDef bq25731_read_reg(uint8_t reg, uint8_t *data, uint16_t len)
{
	HAL_StatusTypeDef status = HAL_OK;
	status = HAL_I2C_Master_Transmit(&BQ25731_I2C, (BQ25731_ADDR << 1) | 0x01, &reg, 1, 100); //Send write operation to move to reg
	if(status != HAL_OK) return status;
	return HAL_I2C_Master_Receive(&BQ25731_I2C, (BQ25731_ADDR << 1), data, len, 100); //Read 1 data from current reg
}
HAL_StatusTypeDef bq25731_write_reg(uint8_t reg, uint8_t *data, uint16_t len)
{
	return  HAL_I2C_Mem_Read(&BQ25731_I2C, BQ25731_ADDR << 7, reg, 1 , data, len, 100);
#define MAX_LEN_WRITE            5
	if(len >= 5) return HAL_ERROR;
	uint8_t data_temp[MAX_LEN_WRITE] = {reg};
	memcpy(&data_temp[1], data, len);
	return HAL_I2C_Master_Transmit(&BQ25731_I2C, (BQ25731_ADDR << 1), data_temp, len + 1, 100);
}
HAL_StatusTypeDef bq25731_write_reg(uint8_t reg, uint8_t *data, uint8_t len)

HAL_StatusTypeDef bq25731_set_bit_reg(uint8_t reg, uint8_t lsb, uint8_t msb)
{
	uint8_t data[2] = {lsb,msb};
	uint8_t data[2] = {0};
	HAL_StatusTypeDef status = bq25731_read_reg(reg, data, 2);
	if(status != HAL_OK) return status;
	data[0] |= lsb;
	data[1] |= msb;
	return bq25731_write_reg(reg, data, 2);
}
HAL_StatusTypeDef bq25731_clear_bit_reg(uint8_t reg, uint8_t lsb, uint8_t msb)
{
	return HAL_I2C_Mem_Write(&BQ25731_I2C, BQ25731_ADDR << 7 | 0x01, reg, 1 , data, len, 100);
	uint8_t data[2] = {0};
	HAL_StatusTypeDef status = bq25731_read_reg(reg, data, 2);
	if(status != HAL_OK) return status;
	data[0] &= ~lsb;
	data[1] &= ~msb;
	return bq25731_write_reg(reg, data, 2);
}



HAL_StatusTypeDef bq25731_get_device_id(uint8_t* dev_id)
{
	return bq25731_read_reg(DEVICE_ID_REG, dev_id, 1);
@@ -31,6 +62,224 @@ HAL_StatusTypeDef bq25731_get_manufacture_id(uint8_t* man_id)
	return bq25731_read_reg(MANUFATURER_ID_REG, man_id, 1);
}

HAL_StatusTypeDef bq25731_set_charge_voltage(charge_voltage_t vol)
{
	uint8_t data[2] = {0};
	switch((uint8_t)vol)
	{
		case CHARGE_VOLTAGE_4200MV:
			data[0] =  CHARGE_VOLTAGE_8_MV_BIT | CHARGE_VOLTAGE_32_MV_BIT | CHARGE_VOLTAGE_64_MV_BIT;
			data[1] =  CHARGE_VOLTAGE_4096_MV_BIT;
			break;
		case CHARGE_VOLTAGE_8400MV:
			data[0] =  CHARGE_VOLTAGE_128_MV_BIT | CHARGE_VOLTAGE_16_MV_BIT | CHARGE_VOLTAGE_64_MV_BIT;
			data[1] =  CHARGE_VOLTAGE_8192_MV_BIT;
			break;
		case CHARGE_VOLTAGE_12600MV:
			data[0] =  CHARGE_VOLTAGE_32_MV_BIT | CHARGE_VOLTAGE_16_MV_BIT | CHARGE_VOLTAGE_8_MV_BIT;
			data[1] =  CHARGE_VOLTAGE_8192_MV_BIT | CHARGE_VOLTAGE_4096_MV_BIT | CHARGE_VOLTAGE_256_MV_BIT;
			break;
		case CHARGE_VOLTAGE_16800MV:
			data[0] =  CHARGE_VOLTAGE_128_MV_BIT | CHARGE_VOLTAGE_32_MV_BIT;
			data[1] =  CHARGE_VOLTAGE_16384_MV_BIT | CHARGE_VOLTAGE_256_MV_BIT ;
			break;
	}

	return bq25731_write_reg(CHARGE_VOLTAGE_REG, data, 2);
}


HAL_StatusTypeDef bq25731_set_charge_current(uint16_t mA)
{
	mA /= 128;
	uint8_t data[2] = {0};
	data[0] = CHARGE_CURRENT_256_MA_BIT;
	data[1] = CHARGE_CURRENT_8192_MA_BIT;
	data[0] = (mA & 0b11) << 6; //Get bit 0,1  to fit bit 6,7
	data[1] = mA >> 2; //Get bit 2->6 fit bit 0->5
	return bq25731_write_reg(CHARGE_CURRENT_REG, data, 2);
}
HAL_StatusTypeDef bq25731_get_charge_current_reg(uint8_t* data)
{
	return bq25731_read_reg(CHARGE_CURRENT_REG, data, 2);
}

HAL_StatusTypeDef bq25731_set_charge_voltage(charge_voltage_t vol)
{
	uint8_t data[2] = {0};
	switch((uint8_t)vol)
	switch((uint16_t)vol)
	{
		case CHARGE_VOLTAGE_4200MV:
			data[0] =  CHARGE_VOLTAGE_8_MV_BIT | CHARGE_VOLTAGE_32_MV_BIT | CHARGE_VOLTAGE_64_MV_BIT;
@@ -113,12 +113,38 @@ HAL_StatusTypeDef bq25731_get_sys_and_bat_voltage(bq25731_t* bq, uint16_t *vbat,

	if(charge_voltage <= 16800) //4cell bat
	{
		*vbat = bq->ADCVSYS_VBAT.VBAT * 64 + 2880;
		*vsys = bq->ADCVSYS_VBAT.VSYS * 64 + 2880;
	}else//Rsense = 10 mOhm
	{
		*vbat = bq->ADCVSYS_VBAT.VBAT * 64 + 8160;
		*vsys = bq->ADCVSYS_VBAT.VSYS * 64 + 8160;
		if(bq->ADCVSYS_VBAT.VBAT == 0)
		{
			*vbat = 0;
		}else
		{
			*vbat = bq->ADCVSYS_VBAT.VBAT * 64 + 2880;
		}
		if(bq->ADCVSYS_VBAT.VSYS == 0)
		{
			*vsys = 0;
		}else
		{
			*vsys = bq->ADCVSYS_VBAT.VSYS * 64 + 2880;
		}
	}else
	{ //5cels
		if(bq->ADCVSYS_VBAT.VBAT == 0)
		{
			*vbat = 0;
		}else
		{
			*vbat = bq->ADCVSYS_VBAT.VBAT * 64 + 8160;
		}
		if(bq->ADCVSYS_VBAT.VSYS == 0)
		{
			*vsys = 0;
		}else
		{
			*vsys = bq->ADCVSYS_VBAT.VSYS * 64 + 8160;
		}
		mv /= 8; //Each bit is 8mV
		data[0] = (mv & 0b11111) << 3; //Get bit 0->4  and fit bit 3->7 reg
		data[1] = mv >> 5; //Get bit 5->11 fit 0->6 reg
	}
	
	return result;
}

HAL_StatusTypeDef bq25731_get_charge_discharge_current(bq25731_t* bq, uint16_t *charge_current, uint16_t *discharge_current)
{
	HAL_StatusTypeDef result = bq25731_read_reg(ADC_BAT_CHARGE_DISCHARGE_CURRENT_REG,(uint8_t *)&bq->ADCIBAT, 2);
	if(result != HAL_OK) return result;
	if(bq->ChargeOption1.RSNS_RSR) //Rsense = 5 mOhm
	{
		*charge_current = bq->ADCIBAT.Charge_Current*128;
		*discharge_current = bq->ADCIBAT.Discharge_Current*512;
	}else//Rsense = 10 mOhm
	{
		*charge_current = bq->ADCIBAT.Charge_Current*64;
		*discharge_current = bq->ADCIBAT.Discharge_Current*256;
	}

	return result;
}


//Get Bus voltage and power system
HAL_StatusTypeDef bq25731_get_vbus_psys(bq25731_t* bq, uint16_t *vbus, uint16_t *psys)
{
	HAL_StatusTypeDef result = bq25731_read_reg(ADC_VBUS_PSYS_REG, (uint8_t *)&bq->ADCVBUS_PSYS, 2);
	*vbus = bq->ADCVBUS_PSYS.VBUS * 96;
	if(bq->ADCOption.ADC_FULLSCALE)
	{
		*psys =  bq->ADCVBUS_PSYS.PSYS * 12;
	}else
	{
		*psys =  bq->ADCVBUS_PSYS.PSYS * 8;
	}
	return result;
}

HAL_StatusTypeDef bq25731_get_input_current(uint8_t* data)
{
	return bq25731_read_reg(ADC_INPUT_CURRENT_CMPIN_VOLTAGE_REG, data, 2);
}


HAL_StatusTypeDef bq25731_get_charge_status(bq25731_t* bq)
{
	return bq25731_read_reg(CHARGE_STATUS_REG, (uint8_t *)&bq->ChargerStatus, 2);
}

HAL_StatusTypeDef bq25731_get_prochot_status(bq25731_t* bq)
{
	return bq25731_read_reg(PROCHOT_STATUS_REG, (uint8_t *)&bq->ProchotStatus, 2);
}

HAL_StatusTypeDef bq25731_charge_option_0(uint8_t lsb, uint8_t msb)
{
	uint8_t data[2] = {0};
	HAL_StatusTypeDef status = bq25731_read_reg(CHARGE_OPTION_0_REG, data, 2);
	if(status != HAL_OK) return status;
	data[0] |= lsb;
	data[1] |= msb;
	return bq25731_write_reg(CHARGE_OPTION_0_REG, data, 2);
}

HAL_StatusTypeDef bq25731_charge_option_0_clear_bit(uint8_t lsb, uint8_t msb)
{
	uint8_t data[2] = {0};
	HAL_StatusTypeDef status = bq25731_read_reg(CHARGE_OPTION_0_REG, data, 2);
	if(status != HAL_OK) return status;
	data[0] &=~ lsb;
	data[1] &=~ msb;
	return bq25731_write_reg(CHARGE_OPTION_0_REG, data, 2);
}

HAL_StatusTypeDef bq25731_read_charge_option_0(bq25731_t* bq)
{
	return bq25731_read_reg(CHARGE_OPTION_0_REG, (uint8_t*)&bq->ChargeOption0, 2);
}

HAL_StatusTypeDef bq25731_charge_option_1(uint8_t lsb,uint8_t msb)
{
	uint8_t data[2] = {0};
	HAL_StatusTypeDef status = bq25731_read_reg(CHARGE_OPTION_1_REG, data, 2);
	if(status != HAL_OK) return status;
	data[0] |= lsb;
	data[1] |= msb;
	return bq25731_write_reg(CHARGE_OPTION_1_REG, data, 2);
}

HAL_StatusTypeDef bq25731_charge_option_3(uint8_t lsb,uint8_t msb)
{
	uint8_t data[2] = {0};
	HAL_StatusTypeDef status = bq25731_read_reg(CHARGE_OPTION_3_REG, data, 2);
	if(status != HAL_OK) return status;
	data[0] |= lsb;
	data[1] |= msb;
	return bq25731_write_reg(CHARGE_OPTION_3_REG, data, 2);
}

HAL_StatusTypeDef bq25731_read_charge_option_1(bq25731_t* bq)
{
	return bq25731_read_reg(CHARGE_OPTION_1_REG, (uint8_t*)&bq->ChargeOption1, 2);
}
HAL_StatusTypeDef bq25731_read_charge_option_2(bq25731_t* bq)
{
	return bq25731_read_reg(CHARGE_OPTION_2_REG, (uint8_t*)&bq->ChargeOption2, 2);
}

HAL_StatusTypeDef bq25731_read_charge_option_3(bq25731_t* bq)
{
	return bq25731_read_reg(CHARGE_OPTION_3_REG, (uint8_t*)&bq->ChargeOption3, 2);
}

HAL_StatusTypeDef bq25731_set_adc_option(uint8_t lsb, uint8_t msb)
{
	uint8_t data[2] = {0};
	HAL_StatusTypeDef status = bq25731_read_reg(ADC_OPTION_REG, data, 2);
	if(status != HAL_OK) return status;
	data[0] |= lsb;
	data[1] |= msb;
	return bq25731_write_reg(ADC_OPTION_REG, data, 2);
}

HAL_StatusTypeDef bq25731_read_adc_option(uint8_t* data)
{
	return bq25731_read_reg(ADC_OPTION_REG, data, 2);
	return bq25731_read_reg(ADC_OPTION_REG, (uint8_t*)&bq->ADCOption, 2);
}
HAL_StatusTypeDef bq25731_disable_charge(bq25731_t* bq)
{
	return bq25731_clear_bit_reg(CHARGE_OPTION_0_REG, CHRG_INHIBIT_BIT , 0);
}

HAL_StatusTypeDef bq25731_init(bq25731_t* bq)
{
	HAL_StatusTypeDef status = 0;
	status = bq25731_charge_option_0_clear_bit(0, EN_LPWR_BIT); //Disable lowpower function for ADC convert block work
	if(status != HAL_OK) return status;
	status = bq25731_charge_option_1(0, EN_IBAT_BIT);   //Enable Ibat buffer
	if(status != HAL_OK) return status;
	status = bq25731_charge_option_3(0,EN_ICO_MODE_BIT); //Enable Auto mode
	if(status != HAL_OK) return status;
	status = bq25731_set_charge_voltage(VOLTAGE_BATTERY); //Set charge voltage
	if(status != HAL_OK) return status;
	status = bq25731_set_bit_reg(INPUT_CURRENT_LIMIT_USE_REG, 0,INPUT_CURRENT_6400_MA_BIT); //Set max current input of power source
	if(status != HAL_OK) return status;
	status = bq25731_set_bit_reg(INPUT_VOLTAGE_REG,0 ,INPUT_VOLTAGE_8192_MV_BIT|INPUT_VOLTAGE_1024_MV_BIT); //Set min input voltage to 12.2V
	if(status != HAL_OK) return status;
	status = bq25731_clear_bit_reg(CHARGE_OPTION_2_REG, EN_EXTILIM_BIT, 0); //Disable external limit current circuit pin
	if(status != HAL_OK) return status;
	status = bq25731_set_bit_reg(CHARGE_OPTION_2_REG,EN_ICHG_IDCHG_BIT,0); //Enable IBAT is charge current
	if(status != HAL_OK) return status;
	status = bq25731_clear_bit_reg(CHARGE_OPTION_3_REG, OTG_VAP_MODE_BIT, 0); //Disable control OTG/VAP use by external pin
	if(status != HAL_OK) return status;
	status = bq25731_clear_bit_reg(CHARGE_OPTION_0_REG,0,WDTMR_ADJ_ENABLE_175S_BIT);//Clear 2 bit  to disable watdog
	if(status != HAL_OK) return status;
	//Enable ADC VSYS,VBUS, VBAT ,I charge,I discharge and start ADC with continuous mode
	status = bq25731_set_adc_option(EN_ADC_IIN_BIT|EN_ADC_VBUS_BIT|EN_ADC_VSYS_BIT|EN_ADC_VBAT_BIT|EN_ADC_IDCHG_BIT|EN_ADC_ICHG_BIT, ADC_START_BIT|ADC_CONV_BIT);
	if(status != HAL_OK) return status;

	status = bq25731_read_charge_option_0(bq);
	status = bq25731_read_charge_option_1(bq);
	status = bq25731_read_charge_option_2(bq);
	status = bq25731_read_charge_option_3(bq);

	status = bq25731_read_reg(ADC_OPTION_REG, (uint8_t *)&bq->ADCOption, 2); //Read back ADC option

	status = bq25731_set_charge_current();
	return status;
}