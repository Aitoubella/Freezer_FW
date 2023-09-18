/*******************************************************************************
  GPIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_gpio.h UUUUUUUUU

  Summary:
    GPIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (GPIO) module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#ifndef PLIB_GPIO_H
#define PLIB_GPIO_H

#include <device.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************


/*** Macros for AUDIO_EN pin ***/
#define AUDIO_EN_Set()               (LATASET = (1U<<7))
#define AUDIO_EN_Clear()             (LATACLR = (1U<<7))
#define AUDIO_EN_Toggle()            (LATAINV= (1U<<7))
#define AUDIO_EN_OutputEnable()      (TRISACLR = (1U<<7))
#define AUDIO_EN_InputEnable()       (TRISASET = (1U<<7))
#define AUDIO_EN_Get()               ((PORTA >> 7) & 0x1U)
#define AUDIO_EN_PIN                  GPIO_PIN_RA7

/*** Macros for USBPWREN pin ***/
#define USBPWREN_Get()               ((PORTB >> 14) & 0x1U)
#define USBPWREN_PIN                  GPIO_PIN_RB14

/*** Macros for CMPRSR_FAN pin ***/
#define CMPRSR_FAN_Set()               (LATBSET = (1U<<15))
#define CMPRSR_FAN_Clear()             (LATBCLR = (1U<<15))
#define CMPRSR_FAN_Toggle()            (LATBINV= (1U<<15))
#define CMPRSR_FAN_OutputEnable()      (TRISBCLR = (1U<<15))
#define CMPRSR_FAN_InputEnable()       (TRISBSET = (1U<<15))
#define CMPRSR_FAN_Get()               ((PORTB >> 15) & 0x1U)
#define CMPRSR_FAN_PIN                  GPIO_PIN_RB15

/*** Macros for CMPRSR_D pin ***/
#define CMPRSR_D_Set()               (LATGSET = (1U<<6))
#define CMPRSR_D_Clear()             (LATGCLR = (1U<<6))
#define CMPRSR_D_Toggle()            (LATGINV= (1U<<6))
#define CMPRSR_D_OutputEnable()      (TRISGCLR = (1U<<6))
#define CMPRSR_D_InputEnable()       (TRISGSET = (1U<<6))
#define CMPRSR_D_Get()               ((PORTG >> 6) & 0x1U)
#define CMPRSR_D_PIN                  GPIO_PIN_RG6

/*** Macros for SCL pin ***/
#define SCL_Set()               (LATGSET = (1U<<7))
#define SCL_Clear()             (LATGCLR = (1U<<7))
#define SCL_Toggle()            (LATGINV= (1U<<7))
#define SCL_OutputEnable()      (TRISGCLR = (1U<<7))
#define SCL_InputEnable()       (TRISGSET = (1U<<7))
#define SCL_Get()               ((PORTG >> 7) & 0x1U)
#define SCL_PIN                  GPIO_PIN_RG7

/*** Macros for SDA pin ***/
#define SDA_Set()               (LATGSET = (1U<<8))
#define SDA_Clear()             (LATGCLR = (1U<<8))
#define SDA_Toggle()            (LATGINV= (1U<<8))
#define SDA_OutputEnable()      (TRISGCLR = (1U<<8))
#define SDA_InputEnable()       (TRISGSET = (1U<<8))
#define SDA_Get()               ((PORTG >> 8) & 0x1U)
#define SDA_PIN                  GPIO_PIN_RG8

/*** Macros for FAN_CTL1 pin ***/
#define FAN_CTL1_Set()               (LATGSET = (1U<<9))
#define FAN_CTL1_Clear()             (LATGCLR = (1U<<9))
#define FAN_CTL1_Toggle()            (LATGINV= (1U<<9))
#define FAN_CTL1_OutputEnable()      (TRISGCLR = (1U<<9))
#define FAN_CTL1_InputEnable()       (TRISGSET = (1U<<9))
#define FAN_CTL1_Get()               ((PORTG >> 9) & 0x1U)
#define FAN_CTL1_PIN                  GPIO_PIN_RG9

/*** Macros for CHRG_OK pin ***/
#define CHRG_OK_Set()               (LATASET = (1U<<12))
#define CHRG_OK_Clear()             (LATACLR = (1U<<12))
#define CHRG_OK_Toggle()            (LATAINV= (1U<<12))
#define CHRG_OK_OutputEnable()      (TRISACLR = (1U<<12))
#define CHRG_OK_InputEnable()       (TRISASET = (1U<<12))
#define CHRG_OK_Get()               ((PORTA >> 12) & 0x1U)
#define CHRG_OK_PIN                  GPIO_PIN_RA12

/*** Macros for PWR_CTL pin ***/
#define PWR_CTL_Set()               (LATASET = (1U<<11))
#define PWR_CTL_Clear()             (LATACLR = (1U<<11))
#define PWR_CTL_Toggle()            (LATAINV= (1U<<11))
#define PWR_CTL_OutputEnable()      (TRISACLR = (1U<<11))
#define PWR_CTL_InputEnable()       (TRISASET = (1U<<11))
#define PWR_CTL_Get()               ((PORTA >> 11) & 0x1U)
#define PWR_CTL_PIN                  GPIO_PIN_RA11

/*** Macros for HTR_CTL pin ***/
#define HTR_CTL_Set()               (LATASET = (1U<<0))
#define HTR_CTL_Clear()             (LATACLR = (1U<<0))
#define HTR_CTL_Toggle()            (LATAINV= (1U<<0))
#define HTR_CTL_OutputEnable()      (TRISACLR = (1U<<0))
#define HTR_CTL_InputEnable()       (TRISASET = (1U<<0))
#define HTR_CTL_Get()               ((PORTA >> 0) & 0x1U)
#define HTR_CTL_PIN                  GPIO_PIN_RA0

/*** Macros for BTN_D pin ***/
#define BTN_D_Set()               (LATASET = (1U<<1))
#define BTN_D_Clear()             (LATACLR = (1U<<1))
#define BTN_D_Toggle()            (LATAINV= (1U<<1))
#define BTN_D_OutputEnable()      (TRISACLR = (1U<<1))
#define BTN_D_InputEnable()       (TRISASET = (1U<<1))
#define BTN_D_Get()               ((PORTA >> 1) & 0x1U)
#define BTN_D_PIN                  GPIO_PIN_RA1
#define BTN_D_InterruptEnable()   (CNENASET = (1U<<1))
#define BTN_D_InterruptDisable()  (CNENACLR = (1U<<1))

/*** Macros for BTN2_R pin ***/
#define BTN2_R_Set()               (LATBSET = (1U<<0))
#define BTN2_R_Clear()             (LATBCLR = (1U<<0))
#define BTN2_R_Toggle()            (LATBINV= (1U<<0))
#define BTN2_R_OutputEnable()      (TRISBCLR = (1U<<0))
#define BTN2_R_InputEnable()       (TRISBSET = (1U<<0))
#define BTN2_R_Get()               ((PORTB >> 0) & 0x1U)
#define BTN2_R_PIN                  GPIO_PIN_RB0
#define BTN2_R_InterruptEnable()   (CNENBSET = (1U<<0))
#define BTN2_R_InterruptDisable()  (CNENBCLR = (1U<<0))

/*** Macros for BTN3_R pin ***/
#define BTN3_R_Set()               (LATBSET = (1U<<1))
#define BTN3_R_Clear()             (LATBCLR = (1U<<1))
#define BTN3_R_Toggle()            (LATBINV= (1U<<1))
#define BTN3_R_OutputEnable()      (TRISBCLR = (1U<<1))
#define BTN3_R_InputEnable()       (TRISBSET = (1U<<1))
#define BTN3_R_Get()               ((PORTB >> 1) & 0x1U)
#define BTN3_R_PIN                  GPIO_PIN_RB1
#define BTN3_R_InterruptEnable()   (CNENBSET = (1U<<1))
#define BTN3_R_InterruptDisable()  (CNENBCLR = (1U<<1))

/*** Macros for VMAIN_VS_3V3 pin ***/
#define VMAIN_VS_3V3_Set()               (LATBSET = (1U<<2))
#define VMAIN_VS_3V3_Clear()             (LATBCLR = (1U<<2))
#define VMAIN_VS_3V3_Toggle()            (LATBINV= (1U<<2))
#define VMAIN_VS_3V3_OutputEnable()      (TRISBCLR = (1U<<2))
#define VMAIN_VS_3V3_InputEnable()       (TRISBSET = (1U<<2))
#define VMAIN_VS_3V3_Get()               ((PORTB >> 2) & 0x1U)
#define VMAIN_VS_3V3_PIN                  GPIO_PIN_RB2

/*** Macros for VBATT_VS_3V3 pin ***/
#define VBATT_VS_3V3_Set()               (LATBSET = (1U<<3))
#define VBATT_VS_3V3_Clear()             (LATBCLR = (1U<<3))
#define VBATT_VS_3V3_Toggle()            (LATBINV= (1U<<3))
#define VBATT_VS_3V3_OutputEnable()      (TRISBCLR = (1U<<3))
#define VBATT_VS_3V3_InputEnable()       (TRISBSET = (1U<<3))
#define VBATT_VS_3V3_Get()               ((PORTB >> 3) & 0x1U)
#define VBATT_VS_3V3_PIN                  GPIO_PIN_RB3

/*** Macros for ACDC_VS_3V3 pin ***/
#define ACDC_VS_3V3_Set()               (LATCSET = (1U<<0))
#define ACDC_VS_3V3_Clear()             (LATCCLR = (1U<<0))
#define ACDC_VS_3V3_Toggle()            (LATCINV= (1U<<0))
#define ACDC_VS_3V3_OutputEnable()      (TRISCCLR = (1U<<0))
#define ACDC_VS_3V3_InputEnable()       (TRISCSET = (1U<<0))
#define ACDC_VS_3V3_Get()               ((PORTC >> 0) & 0x1U)
#define ACDC_VS_3V3_PIN                  GPIO_PIN_RC0

/*** Macros for DCDC_VS_3V3 pin ***/
#define DCDC_VS_3V3_Set()               (LATCSET = (1U<<1))
#define DCDC_VS_3V3_Clear()             (LATCCLR = (1U<<1))
#define DCDC_VS_3V3_Toggle()            (LATCINV= (1U<<1))
#define DCDC_VS_3V3_OutputEnable()      (TRISCCLR = (1U<<1))
#define DCDC_VS_3V3_InputEnable()       (TRISCSET = (1U<<1))
#define DCDC_VS_3V3_Get()               ((PORTC >> 1) & 0x1U)
#define DCDC_VS_3V3_PIN                  GPIO_PIN_RC1

/*** Macros for EXT_PWR_ON_Z pin ***/
#define EXT_PWR_ON_Z_Set()               (LATCSET = (1U<<11))
#define EXT_PWR_ON_Z_Clear()             (LATCCLR = (1U<<11))
#define EXT_PWR_ON_Z_Toggle()            (LATCINV= (1U<<11))
#define EXT_PWR_ON_Z_OutputEnable()      (TRISCCLR = (1U<<11))
#define EXT_PWR_ON_Z_InputEnable()       (TRISCSET = (1U<<11))
#define EXT_PWR_ON_Z_Get()               ((PORTC >> 11) & 0x1U)
#define EXT_PWR_ON_Z_PIN                  GPIO_PIN_RC11

/*** Macros for RTD3 pin ***/
#define RTD3_Set()               (LATESET = (1U<<12))
#define RTD3_Clear()             (LATECLR = (1U<<12))
#define RTD3_Toggle()            (LATEINV= (1U<<12))
#define RTD3_OutputEnable()      (TRISECLR = (1U<<12))
#define RTD3_InputEnable()       (TRISESET = (1U<<12))
#define RTD3_Get()               ((PORTE >> 12) & 0x1U)
#define RTD3_PIN                  GPIO_PIN_RE12

/*** Macros for RTD4 pin ***/
#define RTD4_Set()               (LATESET = (1U<<13))
#define RTD4_Clear()             (LATECLR = (1U<<13))
#define RTD4_Toggle()            (LATEINV= (1U<<13))
#define RTD4_OutputEnable()      (TRISECLR = (1U<<13))
#define RTD4_InputEnable()       (TRISESET = (1U<<13))
#define RTD4_Get()               ((PORTE >> 13) & 0x1U)
#define RTD4_PIN                  GPIO_PIN_RE13

/*** Macros for RTD1 pin ***/
#define RTD1_Set()               (LATESET = (1U<<14))
#define RTD1_Clear()             (LATECLR = (1U<<14))
#define RTD1_Toggle()            (LATEINV= (1U<<14))
#define RTD1_OutputEnable()      (TRISECLR = (1U<<14))
#define RTD1_InputEnable()       (TRISESET = (1U<<14))
#define RTD1_Get()               ((PORTE >> 14) & 0x1U)
#define RTD1_PIN                  GPIO_PIN_RE14

/*** Macros for RTD5 pin ***/
#define RTD5_Set()               (LATESET = (1U<<15))
#define RTD5_Clear()             (LATECLR = (1U<<15))
#define RTD5_Toggle()            (LATEINV= (1U<<15))
#define RTD5_OutputEnable()      (TRISECLR = (1U<<15))
#define RTD5_InputEnable()       (TRISESET = (1U<<15))
#define RTD5_Get()               ((PORTE >> 15) & 0x1U)
#define RTD5_PIN                  GPIO_PIN_RE15

/*** Macros for RTD2 pin ***/
#define RTD2_Set()               (LATASET = (1U<<8))
#define RTD2_Clear()             (LATACLR = (1U<<8))
#define RTD2_Toggle()            (LATAINV= (1U<<8))
#define RTD2_OutputEnable()      (TRISACLR = (1U<<8))
#define RTD2_InputEnable()       (TRISASET = (1U<<8))
#define RTD2_Get()               ((PORTA >> 8) & 0x1U)
#define RTD2_PIN                  GPIO_PIN_RA8

/*** Macros for FAN_CTL2 pin ***/
#define FAN_CTL2_Set()               (LATBSET = (1U<<4))
#define FAN_CTL2_Clear()             (LATBCLR = (1U<<4))
#define FAN_CTL2_Toggle()            (LATBINV= (1U<<4))
#define FAN_CTL2_OutputEnable()      (TRISBCLR = (1U<<4))
#define FAN_CTL2_InputEnable()       (TRISBSET = (1U<<4))
#define FAN_CTL2_Get()               ((PORTB >> 4) & 0x1U)
#define FAN_CTL2_PIN                  GPIO_PIN_RB4

/*** Macros for RTD6 pin ***/
#define RTD6_Set()               (LATASET = (1U<<4))
#define RTD6_Clear()             (LATACLR = (1U<<4))
#define RTD6_Toggle()            (LATAINV= (1U<<4))
#define RTD6_OutputEnable()      (TRISACLR = (1U<<4))
#define RTD6_InputEnable()       (TRISASET = (1U<<4))
#define RTD6_Get()               ((PORTA >> 4) & 0x1U)
#define RTD6_PIN                  GPIO_PIN_RA4

/*** Macros for OSCI pin ***/
#define OSCI_Get()               ((PORTC >> 12) & 0x1U)
#define OSCI_PIN                  GPIO_PIN_RC12

/*** Macros for USB_ID pin ***/
#define USB_ID_Get()               ((PORTB >> 5) & 0x1U)
#define USB_ID_PIN                  GPIO_PIN_RB5

/*** Macros for FLASH_CLK pin ***/
#define FLASH_CLK_Get()               ((PORTB >> 6) & 0x1U)
#define FLASH_CLK_PIN                  GPIO_PIN_RB6

/*** Macros for AUDIO_SIG pin ***/
#define AUDIO_SIG_Set()               (LATCSET = (1U<<10))
#define AUDIO_SIG_Clear()             (LATCCLR = (1U<<10))
#define AUDIO_SIG_Toggle()            (LATCINV= (1U<<10))
#define AUDIO_SIG_OutputEnable()      (TRISCCLR = (1U<<10))
#define AUDIO_SIG_InputEnable()       (TRISCSET = (1U<<10))
#define AUDIO_SIG_Get()               ((PORTC >> 10) & 0x1U)
#define AUDIO_SIG_PIN                  GPIO_PIN_RC10

/*** Macros for RTC_CLK pin ***/
#define RTC_CLK_Get()               ((PORTB >> 7) & 0x1U)
#define RTC_CLK_PIN                  GPIO_PIN_RB7

/*** Macros for RTC_CLKOUT pin ***/
#define RTC_CLKOUT_Get()               ((PORTC >> 13) & 0x1U)
#define RTC_CLKOUT_PIN                  GPIO_PIN_RC13

/*** Macros for RTC_MISO pin ***/
#define RTC_MISO_Get()               ((PORTB >> 8) & 0x1U)
#define RTC_MISO_PIN                  GPIO_PIN_RB8

/*** Macros for RTC_MOSI pin ***/
#define RTC_MOSI_Get()               ((PORTB >> 9) & 0x1U)
#define RTC_MOSI_PIN                  GPIO_PIN_RB9

/*** Macros for FLASH_RST pin ***/
#define FLASH_RST_Set()               (LATCSET = (1U<<6))
#define FLASH_RST_Clear()             (LATCCLR = (1U<<6))
#define FLASH_RST_Toggle()            (LATCINV= (1U<<6))
#define FLASH_RST_OutputEnable()      (TRISCCLR = (1U<<6))
#define FLASH_RST_InputEnable()       (TRISCSET = (1U<<6))
#define FLASH_RST_Get()               ((PORTC >> 6) & 0x1U)
#define FLASH_RST_PIN                  GPIO_PIN_RC6

/*** Macros for TFT_BKLGHT pin ***/
#define TFT_BKLGHT_Set()               (LATCSET = (1U<<7))
#define TFT_BKLGHT_Clear()             (LATCCLR = (1U<<7))
#define TFT_BKLGHT_Toggle()            (LATCINV= (1U<<7))
#define TFT_BKLGHT_OutputEnable()      (TRISCCLR = (1U<<7))
#define TFT_BKLGHT_InputEnable()       (TRISCSET = (1U<<7))
#define TFT_BKLGHT_Get()               ((PORTC >> 7) & 0x1U)
#define TFT_BKLGHT_PIN                  GPIO_PIN_RC7

/*** Macros for TFT_RST pin ***/
#define TFT_RST_Set()               (LATCSET = (1U<<8))
#define TFT_RST_Clear()             (LATCCLR = (1U<<8))
#define TFT_RST_Toggle()            (LATCINV= (1U<<8))
#define TFT_RST_OutputEnable()      (TRISCCLR = (1U<<8))
#define TFT_RST_InputEnable()       (TRISCSET = (1U<<8))
#define TFT_RST_Get()               ((PORTC >> 8) & 0x1U)
#define TFT_RST_PIN                  GPIO_PIN_RC8

/*** Macros for FLASH_MOSI pin ***/
#define FLASH_MOSI_Get()               ((PORTD >> 5) & 0x1U)
#define FLASH_MOSI_PIN                  GPIO_PIN_RD5

/*** Macros for FLASH_MISO pin ***/
#define FLASH_MISO_Get()               ((PORTD >> 6) & 0x1U)
#define FLASH_MISO_PIN                  GPIO_PIN_RD6

/*** Macros for FLASH_CS pin ***/
#define FLASH_CS_Get()               ((PORTC >> 9) & 0x1U)
#define FLASH_CS_PIN                  GPIO_PIN_RC9

/*** Macros for CMPRSR_EN pin ***/
#define CMPRSR_EN_Set()               (LATFSET = (1U<<0))
#define CMPRSR_EN_Clear()             (LATFCLR = (1U<<0))
#define CMPRSR_EN_Toggle()            (LATFINV= (1U<<0))
#define CMPRSR_EN_OutputEnable()      (TRISFCLR = (1U<<0))
#define CMPRSR_EN_InputEnable()       (TRISFSET = (1U<<0))
#define CMPRSR_EN_Get()               ((PORTF >> 0) & 0x1U)
#define CMPRSR_EN_PIN                  GPIO_PIN_RF0

/*** Macros for TFT_MISO pin ***/
#define TFT_MISO_Get()               ((PORTF >> 1) & 0x1U)
#define TFT_MISO_PIN                  GPIO_PIN_RF1

/*** Macros for TFT_CLK pin ***/
#define TFT_CLK_Get()               ((PORTB >> 10) & 0x1U)
#define TFT_CLK_PIN                  GPIO_PIN_RB10

/*** Macros for TFT_WRX pin ***/
#define TFT_WRX_Set()               (LATBSET = (1U<<11))
#define TFT_WRX_Clear()             (LATBCLR = (1U<<11))
#define TFT_WRX_Toggle()            (LATBINV= (1U<<11))
#define TFT_WRX_OutputEnable()      (TRISBCLR = (1U<<11))
#define TFT_WRX_InputEnable()       (TRISBSET = (1U<<11))
#define TFT_WRX_Get()               ((PORTB >> 11) & 0x1U)
#define TFT_WRX_PIN                  GPIO_PIN_RB11

/*** Macros for TFT_MOSI pin ***/
#define TFT_MOSI_Get()               ((PORTB >> 12) & 0x1U)
#define TFT_MOSI_PIN                  GPIO_PIN_RB12

/*** Macros for TFT_CS pin ***/
#define TFT_CS_Get()               ((PORTB >> 13) & 0x1U)
#define TFT_CS_PIN                  GPIO_PIN_RB13

/*** Macros for CMPRSR_SPD pin ***/
#define CMPRSR_SPD_Set()               (LATASET = (1U<<10))
#define CMPRSR_SPD_Clear()             (LATACLR = (1U<<10))
#define CMPRSR_SPD_Toggle()            (LATAINV= (1U<<10))
#define CMPRSR_SPD_OutputEnable()      (TRISACLR = (1U<<10))
#define CMPRSR_SPD_InputEnable()       (TRISASET = (1U<<10))
#define CMPRSR_SPD_Get()               ((PORTA >> 10) & 0x1U)
#define CMPRSR_SPD_PIN                  GPIO_PIN_RA10


// *****************************************************************************
/* GPIO Port

  Summary:
    Identifies the available GPIO Ports.

  Description:
    This enumeration identifies the available GPIO Ports.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/


#define    GPIO_PORT_A  (0)
#define    GPIO_PORT_B  (1)
#define    GPIO_PORT_C  (2)
#define    GPIO_PORT_D  (3)
#define    GPIO_PORT_E  (4)
#define    GPIO_PORT_F  (5)
#define    GPIO_PORT_G  (6)
typedef uint32_t GPIO_PORT;

typedef enum
{
    GPIO_INTERRUPT_ON_MISMATCH,
    GPIO_INTERRUPT_ON_RISING_EDGE,
    GPIO_INTERRUPT_ON_FALLING_EDGE,
    GPIO_INTERRUPT_ON_BOTH_EDGES,
}GPIO_INTERRUPT_STYLE;

// *****************************************************************************
/* GPIO Port Pins

  Summary:
    Identifies the available GPIO port pins.

  Description:
    This enumeration identifies the available GPIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/


#define     GPIO_PIN_RA0  (0U)
#define     GPIO_PIN_RA1  (1U)
#define     GPIO_PIN_RA4  (4U)
#define     GPIO_PIN_RA7  (7U)
#define     GPIO_PIN_RA8  (8U)
#define     GPIO_PIN_RA10  (10U)
#define     GPIO_PIN_RA11  (11U)
#define     GPIO_PIN_RA12  (12U)
#define     GPIO_PIN_RB0  (16U)
#define     GPIO_PIN_RB1  (17U)
#define     GPIO_PIN_RB2  (18U)
#define     GPIO_PIN_RB3  (19U)
#define     GPIO_PIN_RB4  (20U)
#define     GPIO_PIN_RB5  (21U)
#define     GPIO_PIN_RB6  (22U)
#define     GPIO_PIN_RB7  (23U)
#define     GPIO_PIN_RB8  (24U)
#define     GPIO_PIN_RB9  (25U)
#define     GPIO_PIN_RB10  (26U)
#define     GPIO_PIN_RB11  (27U)
#define     GPIO_PIN_RB12  (28U)
#define     GPIO_PIN_RB13  (29U)
#define     GPIO_PIN_RB14  (30U)
#define     GPIO_PIN_RB15  (31U)
#define     GPIO_PIN_RC0  (32U)
#define     GPIO_PIN_RC1  (33U)
#define     GPIO_PIN_RC2  (34U)
#define     GPIO_PIN_RC6  (38U)
#define     GPIO_PIN_RC7  (39U)
#define     GPIO_PIN_RC8  (40U)
#define     GPIO_PIN_RC9  (41U)
#define     GPIO_PIN_RC10  (42U)
#define     GPIO_PIN_RC11  (43U)
#define     GPIO_PIN_RC12  (44U)
#define     GPIO_PIN_RC13  (45U)
#define     GPIO_PIN_RC15  (47U)
#define     GPIO_PIN_RD5  (53U)
#define     GPIO_PIN_RD6  (54U)
#define     GPIO_PIN_RE12  (76U)
#define     GPIO_PIN_RE13  (77U)
#define     GPIO_PIN_RE14  (78U)
#define     GPIO_PIN_RE15  (79U)
#define     GPIO_PIN_RF0  (80U)
#define     GPIO_PIN_RF1  (81U)
#define     GPIO_PIN_RG6  (102U)
#define     GPIO_PIN_RG7  (103U)
#define     GPIO_PIN_RG8  (104U)
#define     GPIO_PIN_RG9  (105U)

    /* This element should not be used in any of the GPIO APIs.
       It will be used by other modules or application to denote that none of the GPIO Pin is used */
#define    GPIO_PIN_NONE   (-1)

typedef uint32_t GPIO_PIN;

typedef  void (*GPIO_PIN_CALLBACK) ( GPIO_PIN pin, uintptr_t context);

void GPIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: GPIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

uint32_t GPIO_PortRead(GPIO_PORT port);

void GPIO_PortWrite(GPIO_PORT port, uint32_t mask, uint32_t value);

uint32_t GPIO_PortLatchRead ( GPIO_PORT port );

void GPIO_PortSet(GPIO_PORT port, uint32_t mask);

void GPIO_PortClear(GPIO_PORT port, uint32_t mask);

void GPIO_PortToggle(GPIO_PORT port, uint32_t mask);

void GPIO_PortInputEnable(GPIO_PORT port, uint32_t mask);

void GPIO_PortOutputEnable(GPIO_PORT port, uint32_t mask);

void GPIO_PortInterruptEnable(GPIO_PORT port, uint32_t mask);

void GPIO_PortInterruptDisable(GPIO_PORT port, uint32_t mask);

// *****************************************************************************
// *****************************************************************************
// Section: Local Data types and Prototypes
// *****************************************************************************
// *****************************************************************************

typedef struct {

    /* target pin */
    GPIO_PIN                 pin;

    /* Callback for event on target pin*/
    GPIO_PIN_CALLBACK        callback;

    /* Callback Context */
    uintptr_t               context;

} GPIO_PIN_CALLBACK_OBJ;

// *****************************************************************************
// *****************************************************************************
// Section: GPIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

static inline void GPIO_PinWrite(GPIO_PIN pin, bool value)
{
	 uint32_t xvalue = (uint32_t)value;
    GPIO_PortWrite((pin>>4U), (uint32_t)(0x1U) << (pin & 0xFU), (xvalue) << (pin & 0xFU));
}

static inline bool GPIO_PinRead(GPIO_PIN pin)
{
    return ((((GPIO_PortRead((GPIO_PORT)(pin>>4U))) >> (pin & 0xFU)) & 0x1U) != 0U);
}

static inline bool GPIO_PinLatchRead(GPIO_PIN pin)
{
    return (((GPIO_PortLatchRead((GPIO_PORT)(pin>>4U)) >> (pin & 0xFU)) & 0x1U) != 0U);
}

static inline void GPIO_PinToggle(GPIO_PIN pin)
{
    GPIO_PortToggle((pin>>4U), (uint32_t)0x1U << (pin & 0xFU));
}

static inline void GPIO_PinSet(GPIO_PIN pin)
{
    GPIO_PortSet((pin>>4U), (uint32_t)0x1U << (pin & 0xFU));
}

static inline void GPIO_PinClear(GPIO_PIN pin)
{
    GPIO_PortClear((pin>>4U), (uint32_t)0x1U << (pin & 0xFU));
}

static inline void GPIO_PinInputEnable(GPIO_PIN pin)
{
    GPIO_PortInputEnable((pin>>4U), (uint32_t)0x1U << (pin & 0xFU));
}

static inline void GPIO_PinOutputEnable(GPIO_PIN pin)
{
    GPIO_PortOutputEnable((pin>>4U), (uint32_t)0x1U << (pin & 0xFU));
}

#define GPIO_PinInterruptEnable(pin)       GPIO_PinIntEnable(pin, GPIO_INTERRUPT_ON_MISMATCH)
#define GPIO_PinInterruptDisable(pin)      GPIO_PinIntDisable(pin)

void GPIO_PinIntEnable(GPIO_PIN pin, GPIO_INTERRUPT_STYLE style);
void GPIO_PinIntDisable(GPIO_PIN pin);

bool GPIO_PinInterruptCallbackRegister(
    GPIO_PIN pin,
    const   GPIO_PIN_CALLBACK callback,
    uintptr_t context
);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // PLIB_GPIO_H
