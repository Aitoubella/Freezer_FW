
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



HAL_StatusTypeDef bq25731_set_charge_current(void)
{
	uint8_t data[2] = {0};
	data[0] = CHARGE_CURRENT_256_MA_BIT;
	data[1] = CHARGE_CURRENT_8192_MA_BIT;
	return bq25731_write_reg(CHARGE_CURRENT_REG, data, 2);
}

HAL_StatusTypeDef bq25731_get_charge_current_reg(uint8_t* data)
{
	return bq25731_read_reg(CHARGE_CURRENT_REG, data, 2);
}

HAL_StatusTypeDef bq25731_get_sys_and_bat_voltage(bq25731_t* bq, uint16_t *vbat, uint16_t *vsys)
{
	HAL_StatusTypeDef result = bq25731_read_reg(ADC_SYS_AND_BAT_VOLTAGE_REG, (uint8_t *)&bq->ADCVSYS_VBAT, 2);
	if(result != HAL_OK) return result;
	uint32_t charge_voltage = 8*(BIT_TO_DEC(bq->ChargeVoltage.BIT,0) +  BIT_TO_DEC(bq->ChargeVoltage.BIT,1) +  BIT_TO_DEC(bq->ChargeVoltage.BIT,2) + BIT_TO_DEC(bq->ChargeVoltage.BIT,3) + \
			  BIT_TO_DEC(bq->ChargeVoltage.BIT,4) +  BIT_TO_DEC(bq->ChargeVoltage.BIT,5) +  BIT_TO_DEC(bq->ChargeVoltage.BIT,6) +  BIT_TO_DEC(bq->ChargeVoltage.BIT,7) +  BIT_TO_DEC(bq->ChargeVoltage.BIT,8) +
			  BIT_TO_DEC(bq->ChargeVoltage.BIT,9) +  BIT_TO_DEC(bq->ChargeVoltage.BIT,10) +  BIT_TO_DEC(bq->ChargeVoltage.BIT,10) +  BIT_TO_DEC(bq->ChargeVoltage.BIT,11));

	if(charge_voltage <= 16800) //4cell bat
	{
		*vbat = bq->ADCVSYS_VBAT.VBAT * 64 + 2880;
		*vsys = bq->ADCVSYS_VBAT.VSYS * 64 + 2880;
	}else//Rsense = 10 mOhm
	{
		*vbat = bq->ADCVSYS_VBAT.VBAT * 64 + 8160;
		*vsys = bq->ADCVSYS_VBAT.VSYS * 64 + 8160;
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
