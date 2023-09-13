/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SD_MISO_Pin GPIO_PIN_2
#define SD_MISO_GPIO_Port GPIOC
#define Buzzer_Pin GPIO_PIN_0
#define Buzzer_GPIO_Port GPIOA
#define AUDIO_EN_Pin GPIO_PIN_3
#define AUDIO_EN_GPIO_Port GPIOA
#define AUDIO_SIG_Pin GPIO_PIN_5
#define AUDIO_SIG_GPIO_Port GPIOA
#define FLASH_MISO_Pin GPIO_PIN_6
#define FLASH_MISO_GPIO_Port GPIOA
#define FLASH_MOSI_Pin GPIO_PIN_7
#define FLASH_MOSI_GPIO_Port GPIOA
#define BTN1_D_Pin GPIO_PIN_9
#define BTN1_D_GPIO_Port GPIOE
#define BTN2_R_Pin GPIO_PIN_10
#define BTN2_R_GPIO_Port GPIOE
#define BTN3_R_Pin GPIO_PIN_11
#define BTN3_R_GPIO_Port GPIOE
#define FLASH_CS_Pin GPIO_PIN_12
#define FLASH_CS_GPIO_Port GPIOE
#define FLASH_CLK_Pin GPIO_PIN_13
#define FLASH_CLK_GPIO_Port GPIOE
#define FLASH_RST_Pin GPIO_PIN_14
#define FLASH_RST_GPIO_Port GPIOE
#define SD_SS_Pin GPIO_PIN_12
#define SD_SS_GPIO_Port GPIOB
#define SD_SCK_Pin GPIO_PIN_13
#define SD_SCK_GPIO_Port GPIOB
#define EXT_PWR_ON_Z_Pin GPIO_PIN_14
#define EXT_PWR_ON_Z_GPIO_Port GPIOB
#define SD_MOSI_Pin GPIO_PIN_15
#define SD_MOSI_GPIO_Port GPIOB
#define CMPRSR_SPD_Pin GPIO_PIN_9
#define CMPRSR_SPD_GPIO_Port GPIOD
#define CMPRSR_EN_Pin GPIO_PIN_10
#define CMPRSR_EN_GPIO_Port GPIOD
#define CMPRSR_FAN_N_Pin GPIO_PIN_11
#define CMPRSR_FAN_N_GPIO_Port GPIOD
#define CMPRSR_FAN__Pin GPIO_PIN_12
#define CMPRSR_FAN__GPIO_Port GPIOD
#define CHRG_OK_Pin GPIO_PIN_14
#define CHRG_OK_GPIO_Port GPIOD
#define Blink_Pin GPIO_PIN_15
#define Blink_GPIO_Port GPIOD
#define TFT_RST_Pin GPIO_PIN_7
#define TFT_RST_GPIO_Port GPIOC
#define TFT_BKLGHT_Pin GPIO_PIN_8
#define TFT_BKLGHT_GPIO_Port GPIOC
#define TFT_WRX_Pin GPIO_PIN_9
#define TFT_WRX_GPIO_Port GPIOC
#define TFT_CS_Pin GPIO_PIN_15
#define TFT_CS_GPIO_Port GPIOA
#define TFT_CLK_Pin GPIO_PIN_10
#define TFT_CLK_GPIO_Port GPIOC
#define TFT_MISO_Pin GPIO_PIN_11
#define TFT_MISO_GPIO_Port GPIOC
#define TFT_MOSI_Pin GPIO_PIN_12
#define TFT_MOSI_GPIO_Port GPIOC
#define VMAIN_VS_3_3_Pin GPIO_PIN_0
#define VMAIN_VS_3_3_GPIO_Port GPIOD
#define VBATT_VS_3_3_Pin GPIO_PIN_1
#define VBATT_VS_3_3_GPIO_Port GPIOD
#define DCDC_VS_3_3_Pin GPIO_PIN_2
#define DCDC_VS_3_3_GPIO_Port GPIOD
#define ACDC_VS_3_3_Pin GPIO_PIN_3
#define ACDC_VS_3_3_GPIO_Port GPIOD
#define HTR_CTL_Pin GPIO_PIN_5
#define HTR_CTL_GPIO_Port GPIOD
#define FAN_CTL1_Pin GPIO_PIN_6
#define FAN_CTL1_GPIO_Port GPIOD
#define FAN_CTL2_Pin GPIO_PIN_7
#define FAN_CTL2_GPIO_Port GPIOD
#define PWR_Pin GPIO_PIN_9
#define PWR_GPIO_Port GPIOB
#define EXT_PWR_ON_Pin GPIO_PIN_0
#define EXT_PWR_ON_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
