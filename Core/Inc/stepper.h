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

    typedef struct
    {
        int id;
        int dir;
        double current_pos;
        double target_pos;
        double acc;
        double speed;
        int max_width;
    } stepper;

#include "main.h"
#include "delay.h"
#include "math.h"
#include "solution.h"

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
#define MAX_WIDTHAB 1000

#define STEPPERZ 1
#define STEPPERA 2
#define STEPPERB 3

#define DIR_CW 1
#define DIR_CCW -1

#define DIR_UP 1
#define DIR_DOWN -1

#define ACC_Z 2.0e-9
#define ACC_A 1.0e-8
#define ACC_B 1.0e-8
#define ACC_AB 1.0e-8

#define SPEED_Z 150
#define SPEED_A 60
#define SPEED_B 60
#define SPEED_AB 60

    void stepperz_run(int dir, int step, int speed);
    void steppera_run(int dir, int step, int speed);
    void stepperb_run(int dir, int step, int speed);
    void stepperab_run(int dira, int dirb, int step, int speed);
    void stepperz_acc(double a, int dir, int current_speed, int target_speed);
    void steppera_acc(double a, int dir, int current_speed, int target_speed);
    void stepperb_acc(double a, int dir, int current_speed, int target_speed);
    void stepperab_acc(double a, int dira, int dirb, int current_speed, int target_speed);
    void stepper_move(stepper *stepperx);
    void stepperab_move(stepper *steppera, stepper *stepperb);
    void moveto(double r, double theta, double h, stepper *steppera, stepper *stepperb, stepper *stepperz);
    void reset(stepper *steppera, stepper *stepperb, stepper *stepperz);
#ifdef __cplusplus
}
#endif
#endif /*__ STEPPER_H__ */
