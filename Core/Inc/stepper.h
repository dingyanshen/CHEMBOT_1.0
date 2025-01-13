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
#define EN4_HIGH HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET)
#define EN4_LOW HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET)
#define EN7_HIGH HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, GPIO_PIN_SET)
#define EN7_LOW HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, GPIO_PIN_RESET)
#define EN8_HIGH HAL_GPIO_WritePin(EN8_GPIO_Port, EN8_Pin, GPIO_PIN_SET)
#define EN8_LOW HAL_GPIO_WritePin(EN8_GPIO_Port, EN8_Pin, GPIO_PIN_RESET)

#define DIR1_HIGH HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_SET)
#define DIR1_LOW HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET)
#define DIR2_HIGH HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_SET)
#define DIR2_LOW HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET)
#define DIR3_HIGH HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_SET)
#define DIR3_LOW HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_RESET)
#define DIR4_HIGH HAL_GPIO_WritePin(DIR4_GPIO_Port, DIR4_Pin, GPIO_PIN_SET)
#define DIR4_LOW HAL_GPIO_WritePin(DIR4_GPIO_Port, DIR4_Pin, GPIO_PIN_RESET)
#define DIR7_HIGH HAL_GPIO_WritePin(DIR7_GPIO_Port, DIR7_Pin, GPIO_PIN_SET)
#define DIR7_LOW HAL_GPIO_WritePin(DIR7_GPIO_Port, DIR7_Pin, GPIO_PIN_RESET)
#define DIR8_HIGH HAL_GPIO_WritePin(DIR8_GPIO_Port, DIR8_Pin, GPIO_PIN_SET)
#define DIR8_LOW HAL_GPIO_WritePin(DIR8_GPIO_Port, DIR8_Pin, GPIO_PIN_RESET)

#define STEP1_HIGH HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET)
#define STEP1_LOW HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET)
#define STEP2_HIGH HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET)
#define STEP2_LOW HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET)
#define STEP3_HIGH HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET)
#define STEP3_LOW HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET)
#define STEP4_HIGH HAL_GPIO_WritePin(STEP4_GPIO_Port, STEP4_Pin, GPIO_PIN_SET)
#define STEP4_LOW HAL_GPIO_WritePin(STEP4_GPIO_Port, STEP4_Pin, GPIO_PIN_RESET)
#define STEP7_HIGH HAL_GPIO_WritePin(STEP7_GPIO_Port, STEP7_Pin, GPIO_PIN_SET)
#define STEP7_LOW HAL_GPIO_WritePin(STEP7_GPIO_Port, STEP7_Pin, GPIO_PIN_RESET)
#define STEP8_HIGH HAL_GPIO_WritePin(STEP8_GPIO_Port, STEP8_Pin, GPIO_PIN_SET)
#define STEP8_LOW HAL_GPIO_WritePin(STEP8_GPIO_Port, STEP8_Pin, GPIO_PIN_RESET)

#define SWITCH1_HIGH HAL_GPIO_ReadPin(SWITCH1_GPIO_Port, SWITCH1_Pin) == GPIO_PIN_SET
#define SWITCH1_LOW HAL_GPIO_ReadPin(SWITCH1_GPIO_Port, SWITCH1_Pin) == GPIO_PIN_RESET
#define SWITCH2_HIGH HAL_GPIO_ReadPin(SWITCH2_GPIO_Port, SWITCH2_Pin) == GPIO_PIN_SET
#define SWITCH2_LOW HAL_GPIO_ReadPin(SWITCH2_GPIO_Port, SWITCH2_Pin) == GPIO_PIN_RESET
#define SWITCH3_HIGH HAL_GPIO_ReadPin(SWITCH3_GPIO_Port, SWITCH3_Pin) == GPIO_PIN_SET
#define SWITCH3_LOW HAL_GPIO_ReadPin(SWITCH3_GPIO_Port, SWITCH3_Pin) == GPIO_PIN_RESET

#define MAX_WIDTHZ 2000
#define MAX_WIDTHA 1000
#define MAX_WIDTHB 1000
#define MAX_WIDTHAB 1000
#define MAX_WIDTH4 2000
#define MAX_WIDTH7 2000
#define MAX_WIDTH8 2000

#define MAX_WIDTHPUMP 2000
#define MIN_WIDTHPUMP 50

#define STEPPERZ 1
#define STEPPERA 2
#define STEPPERB 3
#define STEPPER4 4
#define STEPPER7 7
#define STEPPER8 8

#define DIR_CW 1
#define DIR_CCW -1

#define DIR_UP 1
#define DIR_DOWN -1

#define ACC_Z 2.0e-9
#define ACC_A 1.0e-8
#define ACC_B 1.0e-8
#define ACC_AB 1.0e-8
#define ACC_4 2.0e-9
#define ACC_7 2.0e-9
#define ACC_8 2.0e-9

#define SPEED_Z 150
#define SPEED_A 60
#define SPEED_B 60
#define SPEED_AB 60
#define SPEED_4 150
#define SPEED_7 150
#define SPEED_8 150
#define SPEED_Z_RESET 500
#define SPEED_A_RESET 200
#define SPEED_B_RESET 200

    void stepperz_run(int dir, int step, int speed);
    void steppera_run(int dir, int step, int speed);
    void stepperb_run(int dir, int step, int speed);
    void stepper4_run(int dir, int step, int speed);
    void stepper7_run(int dir, int step, int speed);
    void stepper8_run(int dir, int step, int speed);
    void stepperab_run(int dira, int dirb, int step, int speed);
    void stepperz_acc(double a, int dir, int current_speed, int target_speed);
    void steppera_acc(double a, int dir, int current_speed, int target_speed);
    void stepperb_acc(double a, int dir, int current_speed, int target_speed);
    void stepper4_acc(double a, int dir, int current_speed, int target_speed);
    void stepper7_acc(double a, int dir, int current_speed, int target_speed);
    void stepper8_acc(double a, int dir, int current_speed, int target_speed);
    void stepperab_acc(double a, int dira, int dirb, int current_speed, int target_speed);
    void stepperz_move(stepper *stepperx);
    void stepper4_move(stepper *stepperx);
    void stepper7_move(stepper *stepperx);
    void stepper8_move(stepper *stepperx);
    void stepperab_move(stepper *steppera, stepper *stepperb);
    void moveto(double r, double theta, double h, stepper *steppera, stepper *stepperb, stepper *stepperz);
    void pump(double volume, double velocity, stepper *stepperx);
    void reset(stepper *steppera, stepper *stepperb, stepper *stepperz);

#ifdef __cplusplus
}
#endif
#endif /*__ STEPPER_H__ */
