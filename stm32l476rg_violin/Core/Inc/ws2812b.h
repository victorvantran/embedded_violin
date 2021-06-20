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


#define LED_COUNT 32
#define USE_BRIGHTNESS 1







extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim8;



volatile uint8_t ucDataSentFlag = 0;

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim3)
		{
			HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_1);
			HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_3);
			HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_4);
		}
		else if (htim == &htim8)
		{
			HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_2);
		}

		ucDataSentFlag = 1;
	/*
	switch ((intptr_t)htim)
	{
	case (intptr_t)(&htim3):
		HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_1);
		HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_3);
		HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_4);
		break;
	case (intptr_t)(&htim8):
		HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_2);
		break;
	default:
		break;
	}
	*/
}






/* IMPLEMENTATION */
#if LED_COUNT >= (126 - 1)
#error "LED COUNT should fit below an 8 bit signed number"
#endif

#define WS2812B_TRANSFER_PERIOD_MICRO_SECONDS 1.25
#define WS2812B_TRANSFER_FREQUENCY_HZ (uint32_t)((1/WS2812B_TRANSFER_PERIOD_MICRO_SECONDS)*1000000)
#define WS2812B_ARR (uint32_t)(FCPU_HZ)/(WS2812B_TRANSFER_FREQUENCY_HZ)
#define WS2812B_T0H (float)(0.4/1.25)
#define WS2812B_T0L	(float)(0.85/1.25)
#define WS2812B_T1H (float)(0.8/1.25)
#define WS2812B_T1L	(float)(0.45/1.25)
#define WS2812B_RES	(float)(50/1.25)
#define WS2812B_T0H_TICKS (uint32_t)(WS2812B_T0H*WS2812B_ARR)
#define WS2812B_T0L_TICKS (uint32_t)(WS2812B_T0L*WS2812B_ARR)
#define WS2812B_T1H_TICKS (uint32_t)(WS2812B_T1H*WS2812B_ARR)
#define WS2812B_T1L_TICKS (uint32_t)(WS2812B_T1L*WS2812B_ARR)



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


	uint16_t pwmData[24*LED_COUNT + 50];



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
	)
{
	pxWS28182B->pxTimer1 = pxTimer1;
	pxWS28182B->pxTimer2 = pxTimer2;
	pxWS28182B->pxTimer1->Instance->ARR = WS2812B_ARR;
	pxWS28182B->pxTimer2->Instance->ARR = WS2812B_ARR;

	pxWS28182B->pxDMA1Channel1 = pxDMA1Channel1;
	pxWS28182B->pxDMA1Channel2 = pxDMA1Channel2;
	pxWS28182B->pxDMA1Channel3 = pxDMA1Channel3;
	pxWS28182B->pxDMA2Channel1 = pxDMA2Channel1;
}


/*
void WS2812B_vSend(WS2812BHandle_t *pxWS28182B, uint8_t ucRed, uint8_t ucGreen, uint8_t ucBlue)
{
	// 24-bit data for the colors
	uint32_t ulData = ((uint32_t)ucBlue << 16) | ((uint32_t)ucRed << 8) | ((uint32_t)ucGreen << 0);

	// Check individual data bits (start from MSB)
	for (int8_t i = 23; i > 0; i--)
	{
		if (ulData & (1 << i))
		{
			// Bit is 1
			pxWS28182B->pwmData[i] = WS2812B_T1H_TICKS;
		}
		else
		{
			// Bit is 0
			pxWS28182B->pwmData[i] = WS2812B_T0H_TICKS;
		}
	}

	HAL_TIM_PWM_Start_DMA(pxWS28182B->pxTimer1, TIM_CHANNEL_1, (uint32_t *)pxWS28182B->pwmData, sizeof(pxWS28182B->pwmData));
}
*/






void WS2812B_vSetLED(WS2812BHandle_t *pxWS28182B, uint8_t ucLEDIndex, uint8_t ucRed, uint8_t ucGreen, uint8_t ucBlue)
{
	pxWS28182B->pxLEDData[ucLEDIndex].ucIndex = ucLEDIndex;
	pxWS28182B->pxLEDData[ucLEDIndex].ucGreen = ucGreen;
	pxWS28182B->pxLEDData[ucLEDIndex].ucRed = ucRed;
	pxWS28182B->pxLEDData[ucLEDIndex].ucBlue = ucBlue;
}


void WS2812B_vResetLED(WS2812BHandle_t *pxWS28182B, uint8_t ucLEDIndex)
{
	pxWS28182B->pxLEDData[ucLEDIndex].ucIndex = ucLEDIndex;
	pxWS28182B->pxLEDData[ucLEDIndex].ucGreen = 0;
	pxWS28182B->pxLEDData[ucLEDIndex].ucRed = 0;
	pxWS28182B->pxLEDData[ucLEDIndex].ucBlue = 0;
}


void WS2812B_vResetLEDs(WS2812BHandle_t *pxWS28182B)
{
	// [!] faster way to reset with memclr
	for (int8_t i = 0; i < LED_COUNT; i++)
	{
		WS2812B_vResetLED(pxWS28182B, i);
	}
}


// Credits to Controllers Tech
void WS2812B_vSetBrightness(WS2812BHandle_t *pxWS28182B, int brightness)
{
#if USE_BRIGHTNESS
	if (brightness > 45) brightness = 45;
	for (int i = 0; i < LED_COUNT; i++)
	{
		pxWS28182B->pxLEDBrightness[i].ucIndex = pxWS28182B->pxLEDData[i].ucIndex;

		float angle = 90 - brightness;
		angle = angle*M_PI / 180;
		pxWS28182B->pxLEDBrightness[i].ucGreen = (pxWS28182B->pxLEDData[i].ucGreen)/(tan(angle));
		pxWS28182B->pxLEDBrightness[i].ucRed = (pxWS28182B->pxLEDData[i].ucRed)/(tan(angle));
		pxWS28182B->pxLEDBrightness[i].ucBlue = (pxWS28182B->pxLEDData[i].ucBlue)/(tan(angle));
	}
#endif
}




void WS2812B_vSend(WS2812BHandle_t *pxWS28182B)
{
	uint32_t indx = 0;
	uint32_t color;

	for (int i = 0; i < LED_COUNT; i++)
	{
		color = ((pxWS28182B->pxLEDBrightness[i].ucGreen<<16) | (pxWS28182B->pxLEDBrightness[i].ucRed<<8) | (pxWS28182B->pxLEDBrightness[i].ucBlue));

		for (int i = 23; i >= 0; i--)
		{
			if (color & (1 << i))
			{
				pxWS28182B->pwmData[indx] = WS2812B_T1H_TICKS;
			}
			else
			{
				pxWS28182B->pwmData[indx] = WS2812B_T0H_TICKS;
			}
			indx++;
		}
	}

	for (int i = 0; i < 50; i++)
	{
		pxWS28182B->pwmData[indx] = 0;
		indx++;
	}

	HAL_TIM_PWM_Start_DMA(pxWS28182B->pxTimer1, TIM_CHANNEL_1, (uint32_t *)pxWS28182B->pwmData, indx);
	// [!] semaphore wait or osdelay
	//while (!ucDataSentFlag) {};
	ucDataSentFlag = 0;
}




void WS2812B_vSend2(WS2812BHandle_t *pxWS28182B)
{
	uint32_t indx = 0;
	uint32_t color;

	for (int i = 0; i < LED_COUNT; i++)
	{
		color = ((pxWS28182B->pxLEDBrightness[i].ucGreen<<16) | (pxWS28182B->pxLEDBrightness[i].ucRed<<8) | (pxWS28182B->pxLEDBrightness[i].ucBlue));

		for (int i = 23; i >= 0; i--)
		{
			if (color & (1 << i))
			{
				pxWS28182B->pwmData[indx] = WS2812B_T1H_TICKS;
			}
			else
			{
				pxWS28182B->pwmData[indx] = WS2812B_T0H_TICKS;
			}
			indx++;
		}
	}

	for (int i = 0; i < 50; i++)
	{
		pxWS28182B->pwmData[indx] = 0;
		indx++;
	}

	//HAL_TIM_PWM_Start_DMA(pxWS28182B->pxTimer1, TIM_CHANNEL_3, (uint32_t *)pxWS28182B->pwmData, indx);
	//HAL_TIM_PWM_Start_DMA(pxWS28182B->pxTimer1, TIM_CHANNEL_4, (uint32_t *)pxWS28182B->pwmData, indx);
	HAL_TIM_PWM_Start_DMA(pxWS28182B->pxTimer2, TIM_CHANNEL_2, (uint32_t *)pxWS28182B->pwmData, indx);
	// [!] semaphore wait or osdelay
	//while (!ucDataSentFlag) {};
	ucDataSentFlag = 0;
}








#endif /* INC_WS2812B_H_ */
