/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.
  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

//DOM-IGNORE-BEGIN 
/*******************************************************************************
 * Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software
 * and any derivatives exclusively with Microchip products. It is your
 * responsibility to comply with third party license terms applicable to your
 * use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 * ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
//DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include <stdint.h>
#include "definitions.h"                // SYS function prototypes
#include "bme280_definitions.h"
#include "bme280_driver.h"
#include "freezer_i2c.h"
#include "bq25731_driver.h"
#include "bq25731_sm.h"
#include "app_timer.h"

/* Timer Counter Time period match values for input clock of 60000000 Hz */
#define PERIOD_500MS                            30000000U
#define PERIOD_1S                               60000000U
#define PERIOD_2S                               120000000U
#define PERIOD_4S                               240000000U

#define SWITCH_PRESSED_STATE                    0   // Active LOW switch

#define MAX_SPI_TX_BUFFER_SIZE                  100
#define MAX_SPI_RX_BUFFER_SIZE                  100

#define CMPRSR_ON()         (LATFSET = COMPRSR_PIN_VAL)
#define CMPRSR_OFF()        (LATFCLR = COMPRSR_PIN_VAL)
#define CMPRSR_INV()        (LATFINV = COMPRSR_PIN_VAL)

typedef struct {
    volatile bool isBufferCompleteEvent;
    uint8_t slaveID;
    int16_t temperature;
    uint8_t txBuffer[MAX_SPI_TX_BUFFER_SIZE];
    uint8_t rxBuffer[MAX_SPI_RX_BUFFER_SIZE];
} BME_SENSOR_DATA;
static BME_SENSOR_DATA BME280SensorData;

typedef enum {
    TEMP_SAMPLING_RATE_500MS = 0,
    TEMP_SAMPLING_RATE_1S = 1,
    TEMP_SAMPLING_RATE_2S = 2,
    TEMP_SAMPLING_RATE_4S = 3,
} TEMP_SAMPLING_RATE;
//static TEMP_SAMPLING_RATE tempSampleRate = TEMP_SAMPLING_RATE_500MS;

static volatile bool isTmr2Expired = false;
static volatile bool changeTempSamplingRate = false;
static volatile bool isUARTTxComplete = false;
//static uint16_t      temperatureVal;
//static uint8_t __attribute__ ((aligned (16))) uartTxBuffer[100] = {0};
//
//static void S1_User_Handler(GPIO_PIN pin, uintptr_t context)
//{
//    if(S1_Get() == SWITCH_PRESSED_STATE)
//    {
//        changeTempSamplingRate = true;      
//    }
//}

//unsigned char value;
//unsigned char status1;
//unsigned char status2;
//unsigned char chrg_opt_0A;
//unsigned char chrg_opt_0B;
//unsigned char chrg_opt_3A;
//unsigned char chrg_opt_3B;
//unsigned char chrg_opt_4B;
//unsigned char chrg_curr1;
//unsigned char chrg_curr2;
//
//app_timer_t tmrTest;

void set_performance_mode(void) {
    unsigned int cp0;

    // Unlock Sequence
    asm volatile("di"); // Disable all interrupts
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;

    // PB1DIV
    // Peripheral Bus 1 cannot be turned off, so there's no need to turn it on
    PB1DIVbits.PBDIV = 1; // Peripheral Bus 1 Clock Divisor Control (PBCLK1 is SYSCLK divided by 2)

    // PB2DIV
    PB2DIVbits.ON = 1; // Peripheral Bus 2 Output Clock Enable (Output clock is enabled)
    PB2DIVbits.PBDIV = 1; // Peripheral Bus 2 Clock Divisor Control (PBCLK2 is SYSCLK divided by 2)

    // PB3DIV
    PB3DIVbits.ON = 1; // Peripheral Bus 2 Output Clock Enable (Output clock is enabled)
    PB3DIVbits.PBDIV = 1; // Peripheral Bus 3 Clock Divisor Control (PBCLK3 is SYSCLK divided by 2)

    // PB4DIV
    PB4DIVbits.ON = 1; // Peripheral Bus 4 Output Clock Enable (Output clock is enabled)
    while (!PB4DIVbits.PBDIVRDY); // Wait until it is ready to write to
    PB4DIVbits.PBDIV = 0; // Peripheral Bus 4 Clock Divisor Control (PBCLK4 is SYSCLK divided by 1)

    // PB5DIV
    PB5DIVbits.ON = 1; // Peripheral Bus 5 Output Clock Enable (Output clock is enabled)
    PB5DIVbits.PBDIV = 1; // Peripheral Bus 5 Clock Divisor Control (PBCLK5 is SYSCLK divided by 2)

    // PB7DIV
    PB7DIVbits.ON = 1; // Peripheral Bus 7 Output Clock Enable (Output clock is enabled)
    PB7DIVbits.PBDIV = 0; // Peripheral Bus 7 Clock Divisor Control (PBCLK7 is SYSCLK divided by 1)

    // PB8DIV
    //    PB8DIVbits.ON = 1; // Peripheral Bus 8 Output Clock Enable (Output clock is enabled)
    //    PB8DIVbits.PBDIV = 1; // Peripheral Bus 8 Clock Divisor Control (PBCLK8 is SYSCLK divided by 2)

    // PRECON - Set up prefetch
    //    PRECONbits.PFMSECEN = 0; // Flash SEC Interrupt Enable (Do not generate an interrupt when the PFMSEC bit is set)
    //    PRECONbits.PREFEN = 0b11; // Predictive Prefetch Enable (Enable predictive prefetch for any address)
    //    PRECONbits.PFMWS = 0b010; // PFM Access Time Defined in Terms of SYSCLK Wait States (Two wait states)

    // Set up caching
    cp0 = _mfc0(16, 0);
    cp0 &= ~0x07;
    cp0 |= 0b011; // K0 = Cacheable, non-coherent, write-back, write allocate
    _mtc0(16, 0, cp0);

    // Lock Sequence
    SYSKEY = 0x33333333;

    asm volatile("ei"); // Enable all interrupts
}

void setup_ports(void) {
    // Turn off all analog inputs, make everything digital
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    //    ANSELD = 0;
    ANSELE = 0;
    //    ANSELF = 0;
    ANSELG = 0;
    //    ANSELH = 0;
    //    ANSELJ = 0;

    // Make all ports outputs initially
    TRISA = 0;
    TRISB = (4 | 8);
    TRISC = (1 | 2);
    TRISD = 0;
    TRISE = 0;
    TRISF = 0;
    TRISG = 0;
    //    TRISH = 0;
    //    TRISJ = 0;        

    // Set all port values low initially
    LATA = 0;
    LATB = 0;
    LATC = 0;
    LATD = 0;
    LATE = 0;
    LATF = 0;
    LATG = 0;
    //    LATH = 0;
    //    LATJ = 0;
}

//static void tmr2EventHandler(uint32_t intCause, uintptr_t context) {
//    //    isTmr2Expired = true;
//    //    LATAINV= (1<<7);
//
//    COMPRSR_INV();
//}
//
//static void SPIBufferEventHandler(uintptr_t context) {
//    SENSOR_CS_Set();
//    BME280SensorData.isBufferCompleteEvent = true;
//}
//
//static void UARTDmaChannelHandler(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle) {
//    if (event == DMAC_TRANSFER_EVENT_COMPLETE) {
//        isUARTTxComplete = true;
//    }
//}

static bool BME280Sensor_WriteReg(uint8_t wrAddr, uint8_t wrData) {
    BME280SensorData.txBuffer[0] = wrAddr & 0x7F;
    BME280SensorData.txBuffer[1] = wrData;
    BME280SensorData.isBufferCompleteEvent = false;

    SENSOR_CS_Clear();
    SPI6_Write(BME280SensorData.txBuffer, 2);

    while (false == BME280SensorData.isBufferCompleteEvent);

    return true;
}

static uint8_t BME280Sensor_ReadReg(uint8_t rAddr) {
    BME280SensorData.txBuffer[0] = rAddr;
    BME280SensorData.isBufferCompleteEvent = false;

    SENSOR_CS_Clear();
    SPI6_WriteRead(BME280SensorData.txBuffer, 1, BME280SensorData.rxBuffer, 2);

    while (false == BME280SensorData.isBufferCompleteEvent);

    return BME280SensorData.rxBuffer[1];
}

static bool BME280Sensor_Read(uint8_t rAddr, uint8_t * const pReadBuffer, uint8_t nBytes) {
    BME280SensorData.txBuffer[0] = rAddr;
    BME280SensorData.isBufferCompleteEvent = false;

    SENSOR_CS_Clear();
    SPI6_WriteRead(BME280SensorData.txBuffer, 1, BME280SensorData.rxBuffer, (nBytes + 1));

    while (false == BME280SensorData.isBufferCompleteEvent);
    memcpy(pReadBuffer, &BME280SensorData.rxBuffer[1], nBytes);

    return true;
}

void BME280Sensor_Initialize(void) {
    BME280SensorData.temperature = 0;
    BME280SensorData.slaveID = BME280_SPI_ADDRESS;
    BME280SensorData.isBufferCompleteEvent = false;

    /* Register with BME280 sensor */
    BME280_RegisterDrvWriteReg(BME280Sensor_WriteReg);
    BME280_RegisterDrvReadReg(BME280Sensor_ReadReg);
    BME280_RegisterDrvRead(BME280Sensor_Read);

    BME280_SoftReset();
    /* 100 m.sec delay */
    CORETIMER_DelayMs(100);

    if (BME280_CHIP_ID != BME280_ID_Get()) {
        while (1); /* Error Occurred */
    }
    BME280_CalibParams_Get();
    BME280_SetOversampling(BME280_PARAM_TEMP, BME280_OVERSAMPLING_1X);
    BME280_PowerMode_Set(BME280_NORMAL_MODE);
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main(void) {

//    unsigned int mode;
//    unsigned int next_mode;
//    unsigned int prev_mode;

    /* Initialize all modules */
    SYS_Initialize(NULL);

    //    SPI6_CallbackRegister(SPIBufferEventHandler, 0);
    //    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, UARTDmaChannelHandler, 0);
    //    TMR2_CallbackRegister(tmr2EventHandler, 0);
    //    GPIO_PinInterruptCallbackRegister(S1_PIN, S1_User_Handler, 0);
    //    GPIO_PinInterruptEnable(S1_PIN);

    //    U6STASET |= _U6STA_UTXISEL0_MASK;

    //    BME280Sensor_Initialize();
    /* Start the timer 2 */
    //TMR2_PeriodSet(80000U);
//    TMR2_CallbackRegister();
//    TMR2_Start();
    
    //    unsigned char value;
    //    unsigned char status1;
    //    unsigned char status2;

    // Set performance to ultra rad
    set_performance_mode();

    // Moved all the ANSEL, TRIS and LAT settings to their own function
    setup_ports();

    TFT_DISP_BKLIGHT_ON();
    
    // Enable multi-vectored interrupts mode
    INTCONbits.MVEC = 1;

    // No need to set up PPS, I2C hardware is fixed to certain pins. SCL1 = RA14, SDA1 = RA15

//    // Initialise I2C1 at 100kHz
    I2C_init(400000);

//    CMPRSR_ON();
//
//    bq25731_read(BQ25731_CHRGOPT_3A, &chrg_opt_3A);
//
//    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
//    delay_ms(10);
//
//    bq25731_write(BQ25731_CHRGOPT_3A, (chrg_opt_3A | (1 << 6)));
//
//    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
//    delay_ms(10);
//
//    bq25731_read(BQ25731_STATUS1, &status1);
//
//    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
//    delay_ms(10);
//
//    bq25731_read(BQ25731_STATUS2, &status2);
//
//    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
//    delay_ms(10);
//
//    bq25731_write_verify(BQ25731_STATUS2, (status2 & ~((1 << 3) | (1 << 4))), &status2);
//
//    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
//    delay_ms(10);
//
//    // IBAT_GAIN = 8, IADAPT_GAIN = 20
//    //bq25731_write_verify(BQ25731_CHRGOPT_0A, 0x07, &chrg_opt_0A);
//
//    // IBAT_GAIN = 16, IADAPT_GAIN = 40
//    bq25731_write_verify(BQ25731_CHRGOPT_0A, 0x1F, &chrg_opt_0A);
//
//    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
//    delay_ms(10);
//
//    // 400 kHz
//    bq25731_write_verify(BQ25731_CHRGOPT_0B, 0x5A, &chrg_opt_0B);
//
//    // 800 kHz
////    bq25731_write_verify(BQ25731_CHRGOPT_0A, 0x58, &chrg_opt_0B);
//
//    // Dither OFF
//    bq25731_write_verify(BQ25731_CHRGOPT_4B, 0x00, &chrg_opt_4B);
//
//    // Dither 6%
////    bq25731_write_verify(BQ25731_CHRGOPT_4B, 0x18, &chrg_opt_4B);
//
//    /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
//    delay_ms(10);
//    
//    delay_us(10);
//    tmr_set_period(&tmrTest, (unsigned short) 1000);
//    tmr_start(&tmrTest);
    
    while (1) {
        bq25731_sm();
//        switch (mode) {
//
//            case 0:
//                /* Read the value at register 0x75, the MPU9250's WHOAMI register. Should return 0x68, 0x71 or 0x73 depending on version. */
//                bq25731_read(BQ25731_ID, &value);
//                next_mode = 20;
//                mode = 10;
//                break;
//
//            case 10:
//                /* Wait 10ms before trying again so as not to overwhelm the MPU9250 or the PIC32MZ's I2C peripheral */
//                delay_ms(10);
//                mode = next_mode;
//                break;
//
//            case 20:
//                //        bq25731_write_verify(BQ25731_CHRGCURR2, 0xC0, &chrg_curr2);
//                bq25731_write(BQ25731_CHRGCURR2, 0xC0);
//                next_mode = 25;
//                mode = 10;
//                break;
//
//            case 25:
//                //        bq25731_write_verify(BQ25731_CHRGCURR1, 0x1F, &chrg_curr1);
//                bq25731_write(BQ25731_CHRGCURR1, 0x1F);
//                next_mode = 30;
//                mode = 10;
//                break;
//
//            case 30:
//                //        bq25731_write_verify(BQ25731_CHRGCURR2, 0xC0, &chrg_curr2);
//                bq25731_write(BQ25731_IIN_HOST_H, 0x64);
//                next_mode = 35;
//                mode = 10;
//                break;
//
//            case 35:
//                //        bq25731_write_verify(BQ25731_CHRGCURR1, 0x1F, &chrg_curr1);
////                bq25731_write(BQ25731_IIN_HOST_L, 0x1F);
//                next_mode = 40;
//                mode = 40;
//                break;
//
//            case 40:
//                bq25731_read(BQ25731_STATUS1, &status1);
//                next_mode = 50;
//                mode = 10;
//                break;
//
//            case 50:
//                bq25731_read(BQ25731_STATUS2, &status2);
//                next_mode = 60;
//                mode = 10;
//                break;
//
//            case 60:
//                bq25731_read(BQ25731_CHRGOPT_0A, &chrg_opt_0A);
//                next_mode = 70;
//                mode = 10;
//                break;
//
//            case 70:
//                bq25731_read(BQ25731_CHRGOPT_0B, &chrg_opt_0B);
//                next_mode = 80;
//                mode = 10;
//                break;
//
//            case 80:
//                bq25731_read(BQ25731_CHRGCURR1, &chrg_curr1);
//                next_mode = 90;
//                mode = 10;
//                break;
//
//            case 90:
//                bq25731_read(BQ25731_CHRGCURR2, &chrg_curr2);
//                next_mode = 0;
//                mode = 10;
//                break;
//
//                //            case 100:
//                //                bq25731_write(BQ25731_CHRGCURR1, 0x1F);
//                //                next_mode = 110;
//                //                mode = 10;
//                //                break;
//                //
//                //            case 110:
//                //                bq25731_write(BQ25731_CHRGCURR2, 0xC0);
//                //                next_mode = 0;
//                //                mode = 10;
//                //                break;
//
//            case 130:
//                bq25731_read(BQ25731_CHRGCURR1, &chrg_curr1);
//                next_mode = 0;
//                mode = 10;
//                break;
//
//            default:
//                mode = 0;
//        }
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE);
}

/*******************************************************************************
 End of File
 */

