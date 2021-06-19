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
#include "stm32l4xx_hal.h"
#define FCPU_HZ 80000000



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
	TIM_HandleTypeDef *pxTimer;
} WS2812BHandle_t;


void WS2812B_vInit(WS2812BHandle_t *pxWS28182B,
		TIM_HandleTypeDef *pxTimer)
{
	pxWS28182B->pxTimer = pxTimer;
	pxTimer->Instance->ARR = WS2812B_ARR;
}



#endif /* INC_WS2812B_H_ */
