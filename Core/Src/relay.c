/**
 ******************************************************************************
 * @file    relay.c
 * @brief   This file provides code for the relay control.
 ******************************************************************************
 */

#include "relay.h"

void relay_attract(void)
{
    HAL_GPIO_WritePin(RECTR3_GPIO_Port, RECTR3_Pin, GPIO_PIN_SET);
}

void relay_release(void)
{
    HAL_GPIO_WritePin(RECTR3_GPIO_Port, RECTR3_Pin, GPIO_PIN_RESET);
}
