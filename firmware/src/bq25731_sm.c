/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "freezer_i2c.h"
#include "bq25731_driver.h"
#include "bq25731_sm.h"
#include "./config/pic32mk_gp_db/peripheral/gpio/plib_gpio.h"
//#include "app_timer.h"
//#include "../src/config/default/library/i2cbb/i2c_bb.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */
unsigned char value;
unsigned char status1;
unsigned char status2;
unsigned char chrg_opt_0A;
unsigned char chrg_opt_0B;
unsigned char chrg_opt_3A;
unsigned char chrg_opt_3B;
unsigned char chrg_opt_4B;
unsigned char chrg_curr1;
unsigned char chrg_curr2;


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */
//static int ExampleLocalFunction(int param1, int param2) {
//    return 0;
//}


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */

void bq25731_init()
{
    bq25731_read(BQ25731_CHRGOPT_3A, &chrg_opt_3A);
//    I2C_BB_Read(BQ25731_CHRGOPT_3A, &chrg_opt_3A);

    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
    delay_ms(10);

    bq25731_write(BQ25731_CHRGOPT_3A, (chrg_opt_3A | (1 << 6)));

    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
    delay_ms(10);

    bq25731_read(BQ25731_STATUS1, &status1);

    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
    delay_ms(10);

    bq25731_read(BQ25731_STATUS2, &status2);

    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
    delay_ms(10);

    bq25731_write_verify(BQ25731_STATUS2, (status2 & ~((1 << 3) | (1 << 4))), &status2);

    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
    delay_ms(10);

    // IBAT_GAIN = 8, IADAPT_GAIN = 20
    //bq25731_write_verify(BQ25731_CHRGOPT_0A, 0x07, &chrg_opt_0A);

    // IBAT_GAIN = 16, IADAPT_GAIN = 40
    bq25731_write_verify(BQ25731_CHRGOPT_0A, 0x1F, &chrg_opt_0A);

    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
    delay_ms(10);

    // 400 kHz
    bq25731_write_verify(BQ25731_CHRGOPT_0B, 0x5A, &chrg_opt_0B);

    // 800 kHz
//    bq25731_write_verify(BQ25731_CHRGOPT_0A, 0x58, &chrg_opt_0B);

    // Dither OFF
    bq25731_write_verify(BQ25731_CHRGOPT_4B, 0x00, &chrg_opt_4B);

    // Dither 6%
//    bq25731_write_verify(BQ25731_CHRGOPT_4B, 0x18, &chrg_opt_4B);

    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
    delay_ms(10);
    
}

void bq25731_sm()
{
void bq25731_sm()
{
    static bq25731_states_t mode = INIT;
    static bq25731_states_t next_mode;
    static unsigned int wait_period_ms = 10;
//    static app_timer_t tmr_wait;
    
    if(POW_ACDC_STATUS_PIN_GET() || POW_DCDC_STATUS_PIN_GET()){
        switch (mode) {

            case INIT:
                bq25731_init();
                mode = GET_ID;
                break;

            case START_TIMER:
                /* Start a timer */
    //            tmr_set_period_ms(&tmr_wait, wait_period_ms);
    //            tmr_set_recurring(&tmr_wait, 0);
    //            tmr_start(&tmr_wait);
                mode = WAIT_TIMER;
                break;

            case WAIT_TIMER:
                /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
    //            if(tmr_expired(&tmr_wait)){
    //                mode = next_mode; 
    //            }
                delay_ms(wait_period_ms);
                mode = next_mode; 
                break;

            case GET_ID:
                /* Read the value at register 0x75, the MPU9250's WHOAMI register. Should return 0x68, 0x71 or 0x73 depending on version. */
                bq25731_read(BQ25731_ID, &value);
                next_mode = SET_CHRGCURR2;
                mode = START_TIMER;
                break;

            case SET_CHRGCURR2:
                //        bq25731_write_verify(BQ25731_CHRGCURR2, 0xC0, &chrg_curr2);
                if(POW_ACDC_STATUS_PIN_GET()){
                    bq25731_write(BQ25731_CHRGCURR2, 0xC0);
                }else{
                    bq25731_write(BQ25731_CHRGCURR2, 0x00);
                }
                next_mode = SET_CHRGCURR1;
                mode = START_TIMER;
                break;

            case SET_CHRGCURR1:
                //        bq25731_write_verify(BQ25731_CHRGCURR1, 0x1F, &chrg_curr1);
                if(POW_ACDC_STATUS_PIN_GET()){
                    bq25731_write(BQ25731_CHRGCURR1, 0x1F);
                }else{
                    bq25731_write(BQ25731_CHRGCURR2, 0x18);
                }
               next_mode = SET_IIN_HOST_H;
                mode = START_TIMER;
                break;

            case SET_IIN_HOST_H:
                //        bq25731_write_verify(BQ25731_CHRGCURR2, 0xC0, &chrg_curr2);
                bq25731_write(BQ25731_IIN_HOST_H, 0x64);
                next_mode = SET_IIN_HOST_L;
                mode = START_TIMER;
                break;

            case SET_IIN_HOST_L:
                //        bq25731_write_verify(BQ25731_CHRGCURR1, 0x1F, &chrg_curr1);
    //                bq25731_write(BQ25731_IIN_HOST_L, 0x1F);
                next_mode = GET_STATUS1;
                mode = START_TIMER;
                break;

            case GET_STATUS1:
                bq25731_read(BQ25731_STATUS1, &status1);
                next_mode = GET_STATUS2;
                mode = START_TIMER;
                break;

            case GET_STATUS2:
                bq25731_read(BQ25731_STATUS2, &status2);
                next_mode = GET_CHRGOPT_0A;
                mode = START_TIMER;
                break;

            case GET_CHRGOPT_0A:
                bq25731_read(BQ25731_CHRGOPT_0A, &chrg_opt_0A);
                next_mode = GET_CHRGOPT_0B;
                mode = START_TIMER;
                break;

            case GET_CHRGOPT_0B:
                bq25731_read(BQ25731_CHRGOPT_0B, &chrg_opt_0B);
                next_mode = GET_CHRGCURR1;
                mode = START_TIMER;
                break;

            case GET_CHRGCURR1:
                bq25731_read(BQ25731_CHRGCURR1, &chrg_curr1);
                next_mode = GET_CHRGCURR2;
                mode = START_TIMER;
                break;

            case GET_CHRGCURR2:
                bq25731_read(BQ25731_CHRGCURR2, &chrg_curr2);
                next_mode = GET_ID;
                mode = START_TIMER;
                break;

            default:
                mode = INIT;
        }
    }else{
        mode = INIT;
    }
}


/* *****************************************************************************
 End of File
 */
