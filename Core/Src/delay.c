/**
 ******************************************************************************
 * @file    delay.c
 * @brief   This file provides code for the delay_us function.
 ******************************************************************************
 */

#include "delay.h"

void delay_us(uint32_t delay)
{
    int temp;
    while (delay != 0)
    {
        temp = delay > 9999 ? 9999 : delay;
        __HAL_TIM_SetCounter(&htim1, 0);
        __HAL_TIM_ENABLE(&htim1);
        while (__HAL_TIM_GetCounter(&htim1) < temp)
            ;
        __HAL_TIM_DISABLE(&htim1);
        delay -= temp;
    }
}
