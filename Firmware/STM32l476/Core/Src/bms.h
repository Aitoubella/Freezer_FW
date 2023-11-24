/*
 * bms.h
 *
 *  Created on: Nov 21, 2023
 *     
 */

#ifndef SRC_BMS_H_
#define SRC_BMS_H_
#include "BQ25731.h"
typedef struct
{
	uint16_t max_charge_voltage;
	uint16_t bat_min_voltage;
	uint16_t charge_current;
	uint16_t discharge_curret;
	uint16_t bat_voltage;
	uint16_t sys_voltage;
	uint16_t bus_voltage;
	uint16_t power_sys;
	uint16_t bat_max_discharg_voltage;
	ChargerStatus_t* status;
}charge_info_t;

HAL_StatusTypeDef bms_init(void);
charge_info_t* bms_get_charge_info(void);

#endif /* SRC_BMS_H_ */