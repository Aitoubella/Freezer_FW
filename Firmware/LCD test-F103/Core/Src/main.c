/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../lvgl/lvgl.h"



#include "../ili9341/core.h"
#include "../ili9341/lv_driver.h"

#include "logo.h"

#include "../lvgl/examples/lv_examples.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
static lv_disp_draw_buf_t disp_buf;
 //The second buffer is optional*/

#define ILI_SCR_HORIZONTAL 320
#define ILI_SCR_VERTICAL   240
#define BUFFOR_SCR_ROWS 40

 static lv_color_t buf_1[ILI_SCR_HORIZONTAL * BUFFOR_SCR_ROWS] ;

 	 	 	 	 	 	 	 	 	 	 	 	 	 	 //DMA don't have acces to CCMRAM :(
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 //I don't have so too much time on experiments
 static lv_disp_drv_t disp_drv;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
	ILI9341_Init();
//	XPT2046_Init(&hspi1, EXTI9_5_IRQn);
	HAL_Delay(30);

	lv_init();
	lv_disp_draw_buf_init(&disp_buf, buf_1, buf_2, ILI_SCR_HORIZONTAL * BUFFOR_SCR_ROWS);
	lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
	disp_drv.draw_buf = &disp_buf;          /*Set an initialized buffer*/
	disp_drv.flush_cb = ILI9341_flush;        /*Set a flush callback to draw to the display*/
	disp_drv.hor_res = ILI_SCR_HORIZONTAL;                 /*Set the horizontal resolution in pixels*/
	disp_drv.ver_res = ILI_SCR_VERTICAL;                 /*Set the vertical resolution in pixels*/
	lv_disp_drv_register(&disp_drv); /*Register the driver and save the created display objects*/


//	lv_indev_drv_t indev_drv;
//	lv_indev_drv_init(&indev_drv);
//	indev_drv.type =LV_INDEV_TYPE_POINTER;
//	indev_drv.read_cb = lvXPT2064_Read;
//	lv_indev_drv_register(&indev_drv);
	HAL_Delay(10);

	//lv_example_get_started_1();
	lv_example_textarea_2();
	//lv_example_win_1();
	//lv_example_animimg_1();
	//lv_example_flex_1();
	//lv_example_scroll_6();
	//lv_example_chart_7();
	//lv_example_btnmatrix_3();
	//lv_example_label_1(); //ciekawe przesuwanie tekstu!
	//lv_example_img_3();  //o to jest mocne :D sporo zasobów musi zrec

	uint32_t LedTim0;
	uint32_t lvglTime=0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(HAL_GetTick()-lvglTime >= 5)
	  {
		  lvglTime=HAL_GetTick();
		  lv_task_handler();
		  lv_tick_inc(5);
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
