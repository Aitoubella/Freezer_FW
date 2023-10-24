/*
 * DS1307.h
 *
 *  Created on: OCT 24, 2023
 *
 */

#ifndef SRC_DS1307_H_
#define SRC_DS1307_H_
#include "main.h"
/*----------------------------------------------------------------------------*/
#define DS1307_I2C_ADDR 	0x68
#define DS1307_REG_SECOND 	0x00
#define DS1307_REG_MINUTE 	0x01
#define DS1307_REG_HOUR  	0x02
#define DS1307_REG_DOW    	0x03
#define DS1307_REG_DATE   	0x04
#define DS1307_REG_MONTH  	0x05
#define DS1307_REG_YEAR   	0x06
#define DS1307_REG_CONTROL 	0x07
#define DS1307_REG_UTC_HR	0x08
#define DS1307_REG_UTC_MIN	0x09
#define DS1307_REG_CENT    	0x10
#define DS1307_REG_RAM   	0x11
#define DS1307_TIMEOUT		1000
/*----------------------------------------------------------------------------*/
extern I2C_HandleTypeDef *_ds1307_ui2c;

typedef enum DS1307_Rate{
	DS1307_1HZ, DS1307_4096HZ, DS1307_8192HZ, DS1307_32768HZ
} DS1307_Rate;

typedef enum DS1307_SquareWaveEnable{
	DS1307_DISABLED, DS1307_ENABLED
} DS1307_SquareWaveEnable;

void DS1307_Init(I2C_HandleTypeDef *hi2c);

void DS1307_SetClockHalt(uint8_t halt);
uint8_t DS1307_GetClockHalt(void);


uint8_t DS1307_SetRegByte(uint8_t regAddr, uint8_t val);
uint8_t DS1307_GetRegByte(uint8_t regAddr);

void DS1307_SetEnableSquareWave(DS1307_SquareWaveEnable mode);
void DS1307_SetInterruptRate(DS1307_Rate rate);

uint8_t DS1307_GetDayOfWeek(void);
uint8_t DS1307_GetDay(void);
uint8_t DS1307_GetMonth(void);
uint16_t DS1307_GetYear(void);

uint8_t DS1307_GetHour(void);
uint8_t DS1307_GetMinute(void);
uint8_t DS1307_GetSecond(void);
int8_t DS1307_GetTimeZoneHour(void);
uint8_t DS1307_GetTimeZoneMin(void);


#endif /* SRC_DS1307_H_ */
