/**
 ******************************************************************************
 * @file    delay.h
 * @brief   This file provides all the functions prototypes for
 *          the delay.c file.
 ******************************************************************************
 */

#ifndef __DELAY_H__
#define __DELAY_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "tim.h"

    void delay_us(uint32_t delay);

#ifdef __cplusplus
}
#endif
#endif /*__ DELAY_H__ */
