/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#ifdef __GNUC__
	#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
	#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */



#define G3 5102
#define GS3 4816
#define AF3 4816
#define A3 4545
#define AS3 4290
#define BF3 4290
#define B3 4050
#define C4 3822
#define CS4 3608
#define DF4 3608
#define D4 3405
#define DS4 3214
#define EF4 3214
#define E4 3034
#define F4 2863
#define FS4 2703
#define GF4 2703
#define G4 2551
#define GS4 2408
#define AF4 2408
#define A4 2273
#define AS4 2145
#define BF4 2145
#define B4 2025
#define C5 1911
#define CS5 1804
#define DF5 1804
#define D5 1703
#define DS5 1607
#define EF5 1607
#define E5 1517
#define F5 1432
#define FS5 1351
#define GF5 1351
#define G5 1276
#define GS5 1204
#define AF5 1204
#define A5 1136
#define AS5 1073
#define BF5 1073
#define B5 1012
#define C6 956
#define CS6 902
#define DF6 902
#define D6 851
#define DS6 804
#define EF6 804
#define E6 758
#define F6 716
#define FS6 676
#define GF6 676
#define G6 638
#define GS6 602
#define AF6 602
#define A6 568
#define AS6 536
#define BF6 536
#define B6 506
#define C7 478
#define CS7 451
#define DF7 451
#define D7 426
#define DS7 402
#define EF7 402
#define E7 379
#define F7 358
#define FS7 338
#define GF7 338
#define G7 319
#define GS7 301
#define AF7 301
#define A7 284
#define R 0

#define S 250
#define E 400
#define DE 600
#define Q 800
#define DQ 1200




/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;

/* Definitions for transDataTask */
osThreadId_t transDataTaskHandle;
const osThreadAttr_t transDataTask_attributes = {
  .name = "transDataTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal,
};
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM2_Init(void);
void StartTransferDataTask(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);
	return ch;
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

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  //HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of transDataTask */
  transDataTaskHandle = osThreadNew(StartTransferDataTask, NULL, &transDataTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_ADC;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
  PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_HSI;
  PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
  PeriphClkInit.PLLSAI1.PLLSAI1N = 8;
  PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
  PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_ADC1CLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 80 - 1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 80 - 1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int16_t notes[] = {
			AF3, DF4,	F4,
			EF4,	DF4,	AF3,	BF3,	C4,		DF4,
			EF4,	F4, GF4,
			F4, 	EF4, 	AF4,	AF4,
			AF4, 	BF4, 	GF4, 	F4, 	EF4, 	BF3,
			EF4, 	DF4, 	BF3, 	C4,
			DF4, 	EF4, 	F4, 	AF4, 	C5, 	BF4,
			G4,		G4,		AF4,	A4
	};



	int16_t count[] = {
			Q,	DQ,	E,
			DE,	S,	E,	E,	E,	E,
			Q,	DQ,	E,
			E,	E,	DQ,	E,
			E,	E,	E,	E,	DE,	S,
			E,	E,	DQ,	E,
			E,	E,	E,	E,	DE,	S,
			Q,	E,	Q,	E
	};



	/*
	int16_t notesD[] = {
			R,		R,		R,		R,		GF5,	F5,
			F5,		EF5,	B4,		DF5,	C5,		R,	GF4,
			BF4,	AF4,	E4,		GF4,	F4,		R,	AF4,
			AF4,	G4,		C4,		EF4,	DF4,	F4,
			AF4,	G4,		BF4,	EF5,	DF5,
			DF5,	C5,		R,		F4,		AF4,	GF4,
			BF4,	DF5,	C5,		EF5,	AF5,	GF5,
			R,

			R,	R,	R
	};


	int16_t notesA[] = {
			GF5,	AF5,	A5,		BF5,	EF6,	DF6,
			DF6,	C6,		G5,		BF5,	AF5,	R,		EF5,
			GF5,	F5,		C5,		EF5,	DF5,	R,		F5,
			F5,		EF5,	A4,		C5,		BF4,	DF5,
			F5,		EF5,	G5,		C6,		BF5,
			BF5,	AF5,	R,		D5,		F5,		EF5,
			GF5,	BF5,	AF5,	C6,		F6,		EF6,
			AF5,



			R,	R,	R
	};


	int16_t count[] = {
			E,	E,	E,	E,	DE,	S,
			E,	E,	E,	E,	E,	S,	S,
			E,	E,	E,	E,	S,	S,	E,
			E,	E,	E,	E,	DE,	S,
			E,	E,	E,	Q,	E,
			E,	E,	E,	E,	E,	E,
			DE,	S,	E,	E,	E,	E,
			Q,

			Q,	Q,	Q
	};
	*/


	/*
	int16_t vibrato[] = {
			F5,
			F5 + 4*2, F5 + 8*2, F5 + 12*2, F5 + 16*2, F5 + 12*2, F5 + 8*2, F5 + 4*2,
			F5 - 4*2, F5 - 8*2, F5 - 12*2, F5 - 16*2, F5 - 12*2, F5 - 8*2, F5 - 4*2,
			F5,
	};
	*/


	int16_t vibrato[] = {
			DF4,
			DF4 + 4*3, DF4 + 8*3, DF4 + 12*3, DF4 + 16*3, DF4 + 12*3, DF4 + 8*3, DF4 + 4*3,
			DF4 - 4*3, DF4 - 8*3, DF4 - 12*3, DF4 - 16*3, DF4 - 12*3, DF4 - 8*3, DF4 - 4*3,
			DF4,
	};




float movingAverage(float avg, float new)
{
	return (avg - avg/50.0 + new/50.0);
}


int16_t getPeriod(float v, float sLength, int16_t raw_adc)
{
	// scale = 5.772727
	// Need to recalibrate the starting and end adc
	if (raw_adc < 300 || raw_adc > 2205) return 0;
	return (int16_t)( ((2*(sLength - (raw_adc/(7.816666666f)) + 51.9685f))/v) * 1000000 );
	//return (int16_t)( ((2*(sLength - raw_adc/(5.772727f)))/v) * 1000000 );
}


volatile uint16_t prevPeriod = 0;
volatile uint16_t period = 0;


/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartTransferDataTask */
/**
  * @brief  Function implementing the transferDataTas thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartTransferDataTask */
void StartTransferDataTask(void *argument)
{
  /* USER CODE BEGIN 5 */

	uint16_t prevData = 0;
	uint16_t data = 0;



	int32_t j = 0;

	uint16_t prevMovAvg = 0;
	uint16_t movAvg = 0;

	float avg = 0;
	float new = 0;
	uint8_t count = 0;



	/* Infinite loop */
  for(;;)
  {


  	HAL_ADC_Start(&hadc1);
  	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
  	data = HAL_ADC_GetValue(&hadc1);
  	//HAL_UART_Transmit(&huart2, (uint8_t *)&adc_raw, 2, HAL_MAX_DELAY);
    //		osDelay(10);
    new = (float)data;
    //avg = movingAverage(avg, new);

    if (count < 20)
    {
    	if (count > 9)
    	{
    		avg = new;
    	}
    	if (count > 10)
    	{
    		avg = movingAverage(avg, new);
    	}
    	count++;
    	if (TIM1->ARR == 0 && count == 20)
    	{
  			period = getPeriod(128772.0f, 328.5f, movAvg);
				__HAL_TIM_SET_COUNTER(&htim1, MIN(__HAL_TIM_GET_COUNTER(&htim1), period/2 - 1));
				TIM1->ARR = (period);
				htim1.Instance->CCR1 = TIM1->ARR/2;


				__HAL_TIM_SET_COUNTER(&htim3, MIN(__HAL_TIM_GET_COUNTER(&htim3), period/2 - 1));
				TIM3->ARR = (period);
				htim3.Instance->CCR1 = TIM3->ARR/2;
    	}
    }
    else
    {
  		avg = movingAverage(avg, new);
      movAvg = (uint16_t)(avg);
    }

    //printf("ADC: %u\r\n", movAvg);
    //printf("mm: %u\r\n", (uint16_t)(movAvg * (6.0f/35.0f)));
    //printf("mm: %u\r\n", (uint16_t)(movAvg * (6.75f/35.0f)));
    //printf("mm: %u\r\n", (uint16_t)(movAvg * (6.875f/35.0f)));
    //printf("mm: %u\r\n", (uint16_t)(movAvg * (6.8125f/35.0f))); real longer than digital

    //printf("mm: %u\r\n", (uint16_t)(movAvg * (6.84735f/35.0f)));
    //printf("mm: %u\r\n", (uint16_t)(movAvg * (6.859375f/35.0f)));
    //printf("mm: %u\r\n", (uint16_t)(movAvg * (6.9375f/35.0f)));




    //printf("mm: %u\r\n", (uint16_t)(movAvg/7.816666666f));

		printf("Period: %u\r\n", period);


		//period = getPeriod(128772.0f, 328.5f, movAvg);
		//printf("HZ: %u\r\n", (uint16_t)(1000000.0/(float)period));
		//printf("Period: %u\r\n", period);


		if ((prevMovAvg - movAvg) > 1 || (prevMovAvg - movAvg) < -1)
		{
			if (count >= 20)
			{
				period = getPeriod(128772.0f, 328.5f, movAvg);
			}
			else
			{
				period = 0;
			}
			//printf("HZ: %u\r\n", (uint16_t)(1000000.0/(float)period));


			/*
			//period = getPeriod(128772.0f, 328.5f, movAvg);
			//printf("HZ: %u\r\n", (uint16_t)(1000000.0/(float)period));
			//printf("Period: %u\r\n", period);


			if (count >= 20)
			{
  			//HAL_TIM_Base_Stop(&htim1);
				//htim1.Instance->CR1 &= ~TIM_CR1_CEN; // pause tim
				__HAL_TIM_SET_COUNTER(&htim1, MIN(__HAL_TIM_GET_COUNTER(&htim1), period/2 - 1));
				TIM1->ARR = (period);
				htim1.Instance->CCR1 = TIM1->ARR/2;
  			//HAL_TIM_Base_Start(&htim1);
				//htim1.Instance->CR1 |= TIM_CR1_CEN;


  			//HAL_TIM_Base_Stop(&htim3);
				//htim3.Instance->CR1 &= ~TIM_CR1_CEN; // pause tim
				__HAL_TIM_SET_COUNTER(&htim3, MIN(__HAL_TIM_GET_COUNTER(&htim3), period/2 - 1));
				TIM3->ARR = (period);
				htim3.Instance->CCR1 = TIM3->ARR/2;
  			//HAL_TIM_Base_Start(&htim3);
				//htim3.Instance->CR1 |= TIM_CR1_CEN;

			}
			else
			{
				TIM1->ARR = (0);
				TIM3->ARR = (0);

			}
			*/


			//prevPeriod = period;
			//prevData = data;
			prevMovAvg = movAvg;
		}
		osDelay(1);

		if (data == 0)
		{
			movAvg = 0;
			count = 0;
		}
		else if ((data - prevData) > 100 || (data - prevData) < -100)
    {
    	movAvg = data;
    	count = 0;
    }
    prevData = data;


		/*
    if (data == 0 || (data - prevData) > 40 || (data - prevData) < -40)
    {
    	movAvg = data;
    	count = 0;
    }
    prevData = data;
		*/



  	/*
  	HAL_ADC_Start(&hadc1);
  	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
  	data = HAL_ADC_GetValue(&hadc1);
  	//HAL_UART_Transmit(&huart2, (uint8_t *)&data, 2, 0xFFFF);
    printf("%u\r\n", data);
  	//printf("Hello\r\n");
    */


    // Move Average
    //if (prevData != data)



    /*
    //if (prevMovAvg != movAvg)
		if ((prevMovAvg - movAvg) > 5 || (prevMovAvg - movAvg) < -5)
		{
			//__HAL_TIM_SET_COUNTER(&htim1, MIN(__HAL_TIM_GET_COUNTER(&htim1), (data*2)/2 - 1));

			__HAL_TIM_SET_COUNTER(&htim1, 0);
			TIM1->ARR = (movAvg);
			htim1.Instance->CCR1 = TIM1->ARR/2;

			//__HAL_TIM_SET_COUNTER(&htim3, 0);
			TIM3->ARR = (movAvg);
			htim3.Instance->CCR1 = TIM3->ARR/2;
			prevMovAvg = movAvg;

		}

		osDelay(100);


    if (data == 0)
    {
    	movAvg = 0;
    }
    */

    /*
  	if (prevData != data)
  	//if ((prevData - data) > 100 || (prevData - data) < -100)
  	{
    	//__HAL_TIM_SET_COUNTER(&htim1, MIN(__HAL_TIM_GET_COUNTER(&htim1), (data*2)/2 - 1));

  		__HAL_TIM_SET_COUNTER(&htim1, 0);
    	TIM1->ARR = (data*2);
    	htim1.Instance->CCR1 = TIM1->ARR/2;



    	__HAL_TIM_SET_COUNTER(&htim2, MIN(__HAL_TIM_GET_COUNTER(&htim2), (data*2*80)/2 - 1));
    	TIM2->ARR = (data*2)*80;
    	htim2.Instance->CCR1 = TIM2->ARR/2;




  		//__HAL_TIM_SET_COUNTER(&htim3, 0);
    	TIM3->ARR = (data);
    	htim3.Instance->CCR1 = TIM3->ARR/2;

  	}
  	prevData = data;

    osDelay(10);
		*/


  	/*
  	j = (j + 1) % (sizeof(notes)/sizeof(notes[0]));
  	__HAL_TIM_SET_COUNTER(&htim1, MIN(__HAL_TIM_GET_COUNTER(&htim1), notes[j]/2 - 1));
  	TIM1->ARR = notes[j];
  	htim1.Instance->CCR1 = TIM1->ARR/2;

  	__HAL_TIM_SET_COUNTER(&htim3, MIN(__HAL_TIM_GET_COUNTER(&htim3), notes[j] - 1));
  	TIM3->ARR = notes[j];
  	htim3.Instance->CCR1 = TIM3->ARR/2;

    osDelay(count[j]);
		*/

  	/*
  	j = (j + 1) % (sizeof(notesD)/sizeof(notesD[0]));
  	__HAL_TIM_SET_COUNTER(&htim1, MIN(__HAL_TIM_GET_COUNTER(&htim1), notesD[j]/2 - 1));
  	TIM1->ARR = notesD[j];
  	htim1.Instance->CCR1 = TIM1->ARR/2;

  	__HAL_TIM_SET_COUNTER(&htim3, MIN(__HAL_TIM_GET_COUNTER(&htim3), notesA[j] - 1));
  	TIM3->ARR = notesA[j];
  	htim3.Instance->CCR1 = TIM3->ARR/2;

    osDelay(count[j]);
    */








  	/*
  	j = (j + 1) % (sizeof(vibrato)/sizeof(vibrato[0]));
		__HAL_TIM_SET_COUNTER(&htim1, MIN(__HAL_TIM_GET_COUNTER(&htim1), vibrato[j] - 1));
		TIM1->ARR = vibrato[j];
		htim1.Instance->CCR1 = TIM1->ARR/2;

		__HAL_TIM_SET_COUNTER(&htim3, MIN(__HAL_TIM_GET_COUNTER(&htim3), vibrato[j] - 1));
		TIM3->ARR = vibrato[j];
		htim3.Instance->CCR1 = TIM3->ARR/2;
		*/

  }
  /* USER CODE END 5 */
}

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

	if (htim->Instance == TIM1)
	{
		TIM1->ARR = (period);
		htim1.Instance->CCR1 = TIM1->ARR/2;

		TIM3->ARR = (period);
		htim3.Instance->CCR1 = TIM3->ARR/2;
	}

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
