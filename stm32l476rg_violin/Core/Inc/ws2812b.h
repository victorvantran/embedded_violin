/*
 * ws2812b.h
 *
 *  Created on: Jun 18, 2021
 *      Author: victor
 */

#ifndef INC_WS2812B_H_
#define INC_WS2812B_H_



/* INCLUDE */
#include <stdint.h>
#include "math.h"



/* APPLICATION */
#include "stm32l4xx_hal.h" // TIM3 and TIM8 channels should be set for DMA; ideally 1 timer is needed, but 1 timer only has max 3 dma channels. so need 2
#define FCPU_HZ 80000000


// #define LED_COUNT 32
#define LED_COUNT 1
#define USE_BRIGHTNESS 1







extern TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;



volatile uint8_t ucDataSentFlag;

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);





/* IMPLEMENTATION */
#if LED_COUNT >= (126 - 1)
#error "LED COUNT should fit below an 8 bit signed number"
#endif


/*
#define WS2812B_TRANSFER_PERIOD_MICRO_SECONDS 1.25
#define WS2812B_TRANSFER_FREQUENCY_HZ (uint32_t)((1/WS2812B_TRANSFER_PERIOD_MICRO_SECONDS)*1000000)
#define WS2812B_ARR (uint32_t)(FCPU_HZ)/(WS2812B_TRANSFER_FREQUENCY_HZ)
#define WS2812B_T0H (float)(0.4/1.25)
#define WS2812B_T0L	(float)(0.85/1.25)
#define WS2812B_T1H (float)(0.8/1.25)
#define WS2812B_T1L	(float)(0.45/1.25)



#define WS2812B_RES	(float)(50/1.25)
#define WS2812B_RES_TICKS	100
#define WS2812B_T0H_TICKS (uint32_t)(WS2812B_T0H*WS2812B_ARR)
#define WS2812B_T0L_TICKS (uint32_t)(WS2812B_T0L*WS2812B_ARR)
#define WS2812B_T1H_TICKS (uint32_t)(WS2812B_T1H*WS2812B_ARR)
#define WS2812B_T1L_TICKS (uint32_t)(WS2812B_T1L*WS2812B_ARR)
*/



#define WS2812B_TRANSFER_PERIOD_MICRO_SECONDS 1.20
#define WS2812B_TRANSFER_FREQUENCY_HZ (uint32_t)((1/WS2812B_TRANSFER_PERIOD_MICRO_SECONDS)*1000000)
#define WS2812B_ARR (uint32_t)(FCPU_HZ)/(WS2812B_TRANSFER_FREQUENCY_HZ)
#define WS2812B_T0H (float)(0.3/1.20)
#define WS2812B_T0L	(float)(0.9/1.20)
#define WS2812B_T1H (float)(0.6/1.20)
#define WS2812B_T1L	(float)(0.6/1.20)
#define WS2812B_RES_TICKS	100
#define WS2812B_T0H_TICKS (uint32_t)(WS2812B_T0H*WS2812B_ARR)
#define WS2812B_T0L_TICKS (uint32_t)(WS2812B_T0L*WS2812B_ARR)
#define WS2812B_T1H_TICKS (uint32_t)(WS2812B_T1H*WS2812B_ARR)
#define WS2812B_T1L_TICKS (uint32_t)(WS2812B_T1L*WS2812B_ARR)



/*
#define WS2812B_TRANSFER_PERIOD_MICRO_SECONDS 1.50
#define WS2812B_TRANSFER_FREQUENCY_HZ (uint32_t)((1/WS2812B_TRANSFER_PERIOD_MICRO_SECONDS)*1000000)
#define WS2812B_ARR (uint32_t)(FCPU_HZ)/(WS2812B_TRANSFER_FREQUENCY_HZ)


#define WS2812B_T0H (float)(0.35/1.50)
#define WS2812B_T0L	(float)(1.15/1.50)
#define WS2812B_T1H (float)(0.8/1.50)
#define WS2812B_T1L	(float)(0.7/1.50)


#define WS2812B_RES_TICKS	96
#define WS2812B_T0H_TICKS (uint32_t)(WS2812B_T0H*WS2812B_ARR)
#define WS2812B_T0L_TICKS (uint32_t)(WS2812B_T0L*WS2812B_ARR)
#define WS2812B_T1H_TICKS (uint32_t)(WS2812B_T1H*WS2812B_ARR)
#define WS2812B_T1L_TICKS (uint32_t)(WS2812B_T1L*WS2812B_ARR)
*/

typedef struct
{
	uint8_t ucIndex;
	uint8_t ucGreen;
	uint8_t ucRed;
	uint8_t ucBlue;
} LEDData_t;


typedef struct
{
	uint8_t ucIndex;
	uint8_t ucGreen;
	uint8_t ucRed;
	uint8_t ucBlue;
} LEDBrightness_t;


typedef struct
{
	TIM_HandleTypeDef *pxTimer1;
	TIM_HandleTypeDef *pxTimer2;

	// DMA Timer 1
	DMA_HandleTypeDef *pxDMA1Channel1;
	DMA_HandleTypeDef *pxDMA1Channel2;
	DMA_HandleTypeDef *pxDMA1Channel3;

	// DMA Timer 2
	DMA_HandleTypeDef *pxDMA2Channel1;


	uint16_t pwmData[24*LED_COUNT + WS2812B_RES_TICKS];



	LEDData_t pxLEDData[LED_COUNT];
	LEDBrightness_t pxLEDBrightness[LED_COUNT];

	//uint8_t pucLEDData[LED_COUNT][4];
	//uint8_t pucLEDBrightness[LED_COUNT][4];


} WS2812BHandle_t;


void WS2812B_vInit(WS2812BHandle_t *pxWS28182B,
		TIM_HandleTypeDef *pxTimer1,
		TIM_HandleTypeDef *pxTimer2,
		DMA_HandleTypeDef *pxDMA1Channel1,
		DMA_HandleTypeDef *pxDMA1Channel2,
		DMA_HandleTypeDef *pxDMA1Channel3,
		DMA_HandleTypeDef *pxDMA2Channel1
	);





void WS2812B_vSetLED(WS2812BHandle_t *pxWS28182B, uint8_t ucLEDIndex, uint8_t ucRed, uint8_t ucGreen, uint8_t ucBlue);

void WS2812B_vResetLED(WS2812BHandle_t *pxWS28182B, uint8_t ucLEDIndex);

void WS2812B_vResetLEDs(WS2812BHandle_t *pxWS28182B);

// Credits to Controllers Tech
void WS2812B_vSetBrightness(WS2812BHandle_t *pxWS28182B, int brightness);



void WS2812B_vSend(WS2812BHandle_t *pxWS28182B);










#endif /* INC_WS2812B_H_ */
