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
#define Buzzer_Pin GPIO_PIN_0
#define Buzzer_GPIO_Port GPIOA
#define TFT_CS_Pin GPIO_PIN_4
#define TFT_CS_GPIO_Port GPIOA
#define BTN_1_Pin GPIO_PIN_9
#define BTN_1_GPIO_Port GPIOE
#define BTN_2_Pin GPIO_PIN_10
#define BTN_2_GPIO_Port GPIOE
#define BTN_3_Pin GPIO_PIN_11
#define BTN_3_GPIO_Port GPIOE
#define FLASH_CS_Pin GPIO_PIN_12
#define FLASH_CS_GPIO_Port GPIOE
#define SD_CS_Pin GPIO_PIN_12
#define SD_CS_GPIO_Port GPIOB
#define CMPRSR_SPD_Pin GPIO_PIN_9
#define CMPRSR_SPD_GPIO_Port GPIOD
#define CMPRSR_EN_Pin GPIO_PIN_10
#define CMPRSR_EN_GPIO_Port GPIOD
#define CMPRSR_FAN_GND_Pin GPIO_PIN_11
#define CMPRSR_FAN_GND_GPIO_Port GPIOD
#define CMPRSR_FAN_VCC_Pin GPIO_PIN_12
#define CMPRSR_FAN_VCC_GPIO_Port GPIOD
#define CMPRSR_D_Pin GPIO_PIN_13
#define CMPRSR_D_GPIO_Port GPIOD
#define CRG_OK_Pin GPIO_PIN_14
#define CRG_OK_GPIO_Port GPIOD
#define TFT_RST_Pin GPIO_PIN_7
#define TFT_RST_GPIO_Port GPIOC
#define TFT_BKLIGHT_Pin GPIO_PIN_8
#define TFT_BKLIGHT_GPIO_Port GPIOC
#define TFT_WRX_Pin GPIO_PIN_9
#define TFT_WRX_GPIO_Port GPIOC
#define FLASH_RST_Pin GPIO_PIN_8
#define FLASH_RST_GPIO_Port GPIOA
#define HTR_CTR_Pin GPIO_PIN_5
#define HTR_CTR_GPIO_Port GPIOD
#define FAN_CTR1_Pin GPIO_PIN_6
#define FAN_CTR1_GPIO_Port GPIOD
#define FAN_CTR2_Pin GPIO_PIN_7
#define FAN_CTR2_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
