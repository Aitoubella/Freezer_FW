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
#include "adc.h"
#include "dac.h"
#include "i2c.h"
#include "spi.h"
#include "usb_otg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
#include "math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct {
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    bool am;
    uint8_t day_of_week;
    uint8_t date;
    uint8_t month;
    uint8_t year;
    bool clock_halt;
    bool out;
    bool sqwe;
    bool rs1;
    bool rs0;
} time;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define TIME_STRUCT_SIZE 0x08
#define RTC_ADDRESS (0x68 << 1)
uint8_t data[8];
uint8_t* get_time_array;
char msgBuffer[19]; //2017-02-23 10:10:10
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
/* USER CODE BEGIN PFP */
uint8_t* read_time(void);
void set_time(uint8_t sec, uint8_t min, uint8_t hr, uint8_t dy, uint8_t dat, uint8_t mnth, uint8_t yr);
void decodeTime(const uint8_t *data, time *s_time);
uint8_t* encodeData(const time *s_time);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t* read_time(void){

    data[0] = 0x00;
    HAL_I2C_Master_Transmit(&hi2c1, RTC_ADDRESS, data, 1, 50);
    HAL_I2C_Master_Receive(&hi2c1, RTC_ADDRESS|0x00, &get_time_array[0], 1, 50);

    data[0] = 0x01;
    HAL_I2C_Master_Transmit(&hi2c1, RTC_ADDRESS, data, 1, 50);
    HAL_I2C_Master_Receive(&hi2c1, RTC_ADDRESS|0x01, &get_time_array[1], 1, 50);

    data[0] = 0x02;
    HAL_I2C_Master_Transmit(&hi2c1, RTC_ADDRESS, data, 1, 50);
    HAL_I2C_Master_Receive(&hi2c1, RTC_ADDRESS|0x01, &get_time_array[2], 1, 50);

    data[0] = 0x03;
    HAL_I2C_Master_Transmit(&hi2c1, RTC_ADDRESS, data, 1, 50);
    HAL_I2C_Master_Receive(&hi2c1, RTC_ADDRESS|0x01, &get_time_array[3], 1, 50);

    data[0] = 0x04;
    HAL_I2C_Master_Transmit(&hi2c1, RTC_ADDRESS, data, 1, 50);
    HAL_I2C_Master_Receive(&hi2c1, RTC_ADDRESS|0x01, &get_time_array[4], 1, 50);

    data[0] = 0x05;
    HAL_I2C_Master_Transmit(&hi2c1, RTC_ADDRESS, data, 1, 50);
    HAL_I2C_Master_Receive(&hi2c1, RTC_ADDRESS|0x01, &get_time_array[5], 1, 50);

    data[0] = 0x06;
    HAL_I2C_Master_Transmit(&hi2c1, RTC_ADDRESS, data, 1, 50);
    HAL_I2C_Master_Receive(&hi2c1, RTC_ADDRESS|0x01, &get_time_array[6], 1, 50);

    data[0] = 0x07;
    HAL_I2C_Master_Transmit(&hi2c1, RTC_ADDRESS, data, 1, 50);
    HAL_I2C_Master_Receive(&hi2c1, RTC_ADDRESS|0x01, &get_time_array[7], 1, 50);


		return get_time_array;

}

void set_time(uint8_t sec, uint8_t min, uint8_t hr, uint8_t dy, uint8_t dat, uint8_t mnth, uint8_t yr){



		time *s_time;
		s_time->seconds=sec;
		s_time->minutes=min;
		s_time->hours=hr;
		s_time->day_of_week=dy;
		s_time->date=dat;
		s_time->month=mnth;
		s_time->year=yr;
		s_time->out=false;
		s_time->sqwe=false;
		s_time->rs0=false;
		s_time->rs1=false;

		uint8_t* data_set =encodeData(s_time);

  for(uint8_t i=0;i<8;i++){

		HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS,i,1, (uint8_t*)data_set , 1, 100);

	}



}



void decodeTime(const uint8_t *data, time *s_time) {

uint8_t msd = 0, lsd = 0;
    uint8_t /*am_pm = -1,*/_12h_mode = -1;

    lsd = (data[0] & 0x0F);
    msd = (data[0] & 0x70) >> 4;
    s_time->seconds = lsd + 10 * msd;

    lsd = (data[1] & 0x0F);
    msd = (data[1] & 0x70) >> 4;
    s_time->minutes = lsd + 10 * msd;

    // If 1, then 12-hour mode is enabled, 0 - 24-hour mode
    _12h_mode = (data[2] & 0x40) >> 6;

    // When 12-hour mode enabled, PM = 1, AM = 0, otherwise first bit of
    // hour_msd
    if (_12h_mode) {
        //am_pm = (data[2] & 0b00100000) >> 5;
        msd = (data[2] & 0x10) >> 4;
    } else {
        msd = (data[2] & 0x30) >> 4;
    }
    lsd = (data[2] & 0x0F);
    s_time->hours = lsd + 10 * msd;

    s_time->day_of_week = (data[3] & 0x07);

    lsd = (data[4] & 0x0F);
    msd = (data[4] & 0x30) >> 4;
    s_time->date = lsd + 10 * msd;

    lsd = (data[5] & 0x0F);
    msd = (data[5] & 0x10) >> 4;
    s_time->month = lsd + 10 * msd;

    lsd = (data[6] & 0x0F);
    msd = (data[6] & 0xF0) >> 4;
    s_time->year = lsd + 10 * msd;

    s_time->clock_halt = (data[0] & 0x70) >> 7;
    s_time->out = (data[7] & 0x70) >> 7;
    s_time->sqwe = (data[7] & 0x10) >> 4;
    s_time->rs1 = (data[7] & 0x02) >> 1;
    s_time->rs0 = (data[7] & 0x01);

}


uint8_t* encodeData(const time *s_time) {
    uint8_t *data = calloc(TIME_STRUCT_SIZE, sizeof(uint8_t));
    uint8_t msd, lsd;

    // 0x00 Clock halt and seconds
    msd = s_time->seconds / 10;
    lsd = s_time->seconds - msd * 10;
    data[0] = (s_time->clock_halt << 7) | (msd << 4) | (lsd);

    // 0x01 Minutes
    msd = s_time->minutes / 10;
    lsd = s_time->minutes - msd * 10;
    data[1] = (msd << 4) | (lsd);

    // 0x02 Hours
    msd = s_time->hours / 10;
    lsd = s_time->hours - msd * 10;
    data[2] = (0 << 6 /*24h mode*/) | (msd << 4) | (lsd);

    // 0x03 Day of week
    data[3] = s_time->day_of_week;

    // 0x04 Date (day of month)
    msd = s_time->date / 10;
    lsd = s_time->date - msd * 10;
    data[4] = (msd << 4) | (lsd);

    // 0x05 Month
    msd = s_time->month / 10;
    lsd = s_time->month - msd * 10;
    data[5] = (msd << 4) | (lsd);

    // 0x06 Year
    msd = s_time->year / 10;
    lsd = s_time->year - msd * 10;
    data[6] = (msd << 4) | (lsd);

    // 0x07 Control part:
    // OUT, SQWE, RS1 and RS0
    data[7] = (s_time->out << 7) | (s_time->sqwe << 4) | (s_time->rs1 << 1)
            | (s_time->rs0);

    return data;
}


time getTime(void) {
    uint8_t* datam = read_time();
    time s_time;
    decodeTime(datam, &s_time);
    free(data);
    return s_time;
}

void print_time(){

	time t1=getTime();
	sprintf(msgBuffer, "%04d-%02d-%02d %02d:%02d:%02d",
            t1.year,
            t1.month,
            t1.date,
            t1.hours,
            t1.minutes,
            t1.seconds);
}

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

/* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_SPI3_Init();
  MX_DAC1_Init();
  MX_USB_OTG_FS_USB_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 18;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB|RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLLSAI1;
  PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_HSE;
  PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
  PeriphClkInit.PLLSAI1.PLLSAI1N = 12;
  PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
  PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_48M2CLK|RCC_PLLSAI1_ADC1CLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
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
