/*
 * RTD.h
 *
 */

#ifndef SRC_RTD_H_
#define SRC_RTD_H_
typedef enum
{
	RTD5 = 0,
	RTD6,
	RTD1,
	RTD2,
	RTD3,
	RTD4,
}rtd_t;
void rtd_init(void);
double rtd_get_temperature(rtd_t rtd);
#endif /* SRC_RTD_H_ */
