 /*
 bms.c
 *
 *  Created on: Nov 21, 2023
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