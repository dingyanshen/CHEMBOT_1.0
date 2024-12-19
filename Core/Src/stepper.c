/**
 ******************************************************************************
 * @file    stepper.c
 * @brief   This file provides code for the control of stepper motors.
 ******************************************************************************
 */

#include "stepper.h"

void stepperz_run(int dir, int step, int speed)
{
    EN1_LOW;
    if (dir == 1)
        DIR1_HIGH;
    else if (dir == -1)
        DIR1_LOW;
    for (int i = 0; i < step; i++)
    {
        STEP1_HIGH;
        delay_us(speed);
        STEP1_LOW;
        delay_us(speed);
    }
    EN1_HIGH;
}

void steppera_run(int dir, int step, int speed)
{
    EN2_LOW;
    if (dir == 1)
        DIR2_HIGH;
    else if (dir == -1)
        DIR2_LOW;
    for (int i = 0; i < step; i++)
    {
        STEP2_HIGH;
        delay_us(speed);
        STEP2_LOW;
        delay_us(speed);
    }
    EN2_HIGH;
}

void stepperb_run(int dir, int step, int speed)
{
    EN3_LOW;
    if (dir == 1)
        DIR3_HIGH;
    else if (dir == -1)
        DIR3_LOW;
    for (int i = 0; i < step; i++)
    {
        STEP3_HIGH;
        delay_us(speed);
        STEP3_LOW;
        delay_us(speed);
    }
    EN3_HIGH;
}

void stepperab_run(int dira, int dirb, int step, int speed)
{
    EN2_LOW;
    EN3_LOW;
    if (dira == 1)
        DIR2_HIGH;
    else if (dira == -1)
        DIR2_LOW;
    if (dirb == 1)
        DIR3_HIGH;
    else if (dirb == -1)
        DIR3_LOW;
    for (int i = 0; i < step; i++)
    {
        STEP2_HIGH;
        STEP3_HIGH;
        delay_us(speed);
        STEP2_LOW;
        STEP3_LOW;
        delay_us(speed);
    }
    EN2_HIGH;
    EN3_HIGH;
}

int stepperz_acc(double a, int dir, int current_width, int target_width)
{
    int step = 0;
    EN1_LOW;
    if (dir == 1)
        DIR1_HIGH;
    else if (dir == -1)
        DIR1_LOW;
    if (current_width < target_width)
    {
        double current_speed = 0.5 / current_width;
        double target_speed = 0.5 / target_width;
        step = (current_speed * current_speed - target_speed * target_speed) / (2.0 * a);
        double speed = current_speed;
        for (int i = 0; i < step; i++)
        {
            STEP1_HIGH;
            delay_us((int)(0.5 / speed));
            STEP1_LOW;
            delay_us((int)(0.5 / speed));
            speed = sqrt(speed * speed - 2.0 * a);
        }
    }
    else if (current_width > target_width)
    {
        double current_speed = 0.5 / current_width;
        double target_speed = 0.5 / target_width;
        step = (target_speed * target_speed - current_speed * current_speed) / (2.0 * a);
        double speed = current_speed;
        for (int i = 0; i < step; i++)
        {
            STEP1_HIGH;
            delay_us((int)(0.5 / speed));
            STEP1_LOW;
            delay_us((int)(0.5 / speed));
            speed = sqrt(speed * speed + 2.0 * a);
        }
    }
    EN1_HIGH;
    return step;
}

int steppera_acc(double a, int dir, int current_width, int target_width)
{
    int step = 0;
    EN2_LOW;
    if (dir == 1)
        DIR2_HIGH;
    else if (dir == -1)
        DIR2_LOW;
    if (current_width < target_width)
    {
        double current_speed = 0.5 / current_width;
        double target_speed = 0.5 / target_width;
        step = (current_speed * current_speed - target_speed * target_speed) / (2.0 * a);
        double speed = current_speed;
        for (int i = 0; i < step; i++)
        {
            STEP2_HIGH;
            delay_us((int)(0.5 / speed));
            STEP2_LOW;
            delay_us((int)(0.5 / speed));
            speed = sqrt(speed * speed - 2.0 * a);
        }
    }
    else if (current_width > target_width)
    {
        double current_speed = 0.5 / current_width;
        double target_speed = 0.5 / target_width;
        step = (target_speed * target_speed - current_speed * current_speed) / (2.0 * a);
        double speed = current_speed;
        for (int i = 0; i < step; i++)
        {
            STEP2_HIGH;
            delay_us((int)(0.5 / speed));
            STEP2_LOW;
            delay_us((int)(0.5 / speed));
            speed = sqrt(speed * speed + 2.0 * a);
        }
    }
    EN2_HIGH;
    return step;
}

int stepperb_acc(double a, int dir, int current_width, int target_width)
{
    int step = 0;
    EN3_LOW;
    if (dir == 1)
        DIR3_HIGH;
    else if (dir == -1)
        DIR3_LOW;
    if (current_width < target_width)
    {
        double current_speed = 0.5 / current_width;
        double target_speed = 0.5 / target_width;
        step = (current_speed * current_speed - target_speed * target_speed) / (2.0 * a);
        double speed = current_speed;
        for (int i = 0; i < step; i++)
        {
            STEP3_HIGH;
            delay_us((int)(0.5 / speed));
            STEP3_LOW;
            delay_us((int)(0.5 / speed));
            speed = sqrt(speed * speed - 2.0 * a);
        }
    }
    else if (current_width > target_width)
    {
        double current_speed = 0.5 / current_width;
        double target_speed = 0.5 / target_width;
        step = (target_speed * target_speed - current_speed * current_speed) / (2.0 * a);
        double speed = current_speed;
        for (int i = 0; i < step; i++)
        {
            STEP3_HIGH;
            delay_us((int)(0.5 / speed));
            STEP3_LOW;
            delay_us((int)(0.5 / speed));
            speed = sqrt(speed * speed + 2.0 * a);
        }
    }
    EN3_HIGH;
    return step;
}

void stepperab_acc(int acc, int dira, int dirb, int speed)
{
    EN2_LOW;
    EN3_LOW;
    if (dira == 1)
        DIR2_HIGH;
    else if (dira == -1)
        DIR2_LOW;
    if (dirb == 1)
        DIR3_HIGH;
    else if (dirb == -1)
        DIR3_LOW;
    if (acc == 1)
        for (int i = 500; i > speed; i--)
        {
            STEP2_HIGH;
            STEP3_HIGH;
            delay_us(i);
            STEP2_LOW;
            STEP3_LOW;
            delay_us(i);
        }
    else if (acc == -1)
        for (int i = speed; i < 500; i++)
        {
            STEP2_HIGH;
            STEP3_HIGH;
            delay_us(i);
            STEP2_LOW;
            STEP3_LOW;
            delay_us(i);
        }
    EN2_HIGH;
    EN3_HIGH;
}

void stepperz(int dir, int step, int speed, double a)
{
    int step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / MAX_WIDTHZ) * (0.5 / MAX_WIDTHZ)) / (2.0 * a);
    if (step - 2 * step_acc > 0)
    {
        stepperz_acc(a, dir, MAX_WIDTHZ, speed);
        stepperz_run(dir, step - 2 * step_acc, speed);
        stepperz_acc(a, dir, speed, MAX_WIDTHZ);
    }
}

void steppera(int dir, int step, int speed, double a)
{
    int step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / MAX_WIDTHA) * (0.5 / MAX_WIDTHA)) / (2.0 * a);
    if (step - 2 * step_acc > 0)
    {
        steppera_acc(a, dir, MAX_WIDTHA, speed);
        steppera_run(dir, step - 2 * step_acc, speed);
        steppera_acc(a, dir, speed, MAX_WIDTHA);
    }
}

void stepperb(int dir, int step, int speed, double a)
{
    int step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / MAX_WIDTHB) * (0.5 / MAX_WIDTHB)) / (2.0 * a);
    if (step - 2 * step_acc > 0)
    {
        stepperb_acc(a, dir, MAX_WIDTHB, speed);
        stepperb_run(dir, step - 2 * step_acc, speed);
        stepperb_acc(a, dir, speed, MAX_WIDTHB);
    }
}

void stepperab(int dira, int dirb, int step, int speed)
{
    stepperab_acc(1, dira, dirb, speed);
    stepperab_run(dira, dirb, step - 500 + speed, speed);
    stepperab_acc(-1, dira, dirb, speed);
}
