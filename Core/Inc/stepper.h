/**
 ******************************************************************************
 * @file    stepper.h
 * @brief   This file provides all the functions prototypes for
 *          the stepper.c file.
 ******************************************************************************
 */

#ifndef __STEPPER_H__
#define __STEPPER_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "delay.h"
#include "math.h"

#define EN1_HIGH HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET)
#define EN1_LOW HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET)
#define EN2_HIGH HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET)
#define EN2_LOW HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET)
#define EN3_HIGH HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET)
#define EN3_LOW HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET)

#define DIR1_HIGH HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_SET)
#define DIR1_LOW HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET)
#define DIR2_HIGH HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_SET)
#define DIR2_LOW HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET)
#define DIR3_HIGH HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_SET)
#define DIR3_LOW HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_RESET)

#define STEP1_HIGH HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET)
#define STEP1_LOW HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET)
#define STEP2_HIGH HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET)
#define STEP2_LOW HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET)
#define STEP3_HIGH HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET)
#define STEP3_LOW HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET)

#define MAX_WIDTHZ 2000
#define MAX_WIDTHA 1000
#define MAX_WIDTHB 1000

#define DIR_CW 1
#define DIR_CCW -1

#define DIR_UP 1
#define DIR_DOWN -1

    void stepperz_run(int dir, int step, int speed);
    void steppera_run(int dir, int step, int speed);
    void stepperb_run(int dir, int step, int speed);
    void stepperab_run(int dira, int dirb, int step, int speed);
    int stepperz_acc(double a, int dir, int current_speed, int target_speed);
    int steppera_acc(double a, int dir, int current_speed, int target_speed);
    int stepperb_acc(double a, int dir, int current_speed, int target_speed);
    void stepperab_acc(int acc, int dira, int dirb, int speed);
    void stepperz(int dir, int step, int speed, double a);
    void steppera(int dir, int step, int speed, double a);
    void stepperb(int dir, int step, int speed, double a);
    void stepperab(int dira, int dirb, int step, int speed);

#ifdef __cplusplus
}
#endif
#endif /*__ STEPPER_H__ */
