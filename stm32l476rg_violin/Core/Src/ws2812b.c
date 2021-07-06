/*
 * ws2812b.c
 *
 *  Created on: Jun 18, 2021
 *      Author: victor
 */


#include "ws2812b.h"

extern TIM_HandleTypeDef htim3;

volatile uint8_t ucDataSentFlag = 0;

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim3)
	{
		HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_1);
	}
}



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




