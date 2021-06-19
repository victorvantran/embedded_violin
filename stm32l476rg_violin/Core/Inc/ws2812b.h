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



/* APPLICATION */
#include "stm32l4xx_hal.h" // TIM3 and TIM8 channels should be set for DMA; ideally 1 timer is needed, but 1 timer only has max 3 dma channels. so need 2
#define FCPU_HZ 80000000


extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim8;

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
	TIM_HandleTypeDef *pxTimer1;
	TIM_HandleTypeDef *pxTimer2;

	// DMA Timer 1
	DMA_HandleTypeDef *pxDMA1Channel1;
	DMA_HandleTypeDef *pxDMA1Channel2;
	DMA_HandleTypeDef *pxDMA1Channel3;

	// DMA Timer 2
	DMA_HandleTypeDef *pxDMA2Channel1;


	uint16_t pwmData[24];

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



#endif /* INC_WS2812B_H_ */
