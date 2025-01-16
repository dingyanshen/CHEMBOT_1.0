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

void stepper4_run(int dir, int step, int speed)
{
    EN4_LOW;
    if (dir == 1)
        DIR4_HIGH;
    else if (dir == -1)
        DIR4_LOW;
    for (int i = 0; i < step; i++)
    {
        STEP4_HIGH;
        delay_us(speed);
        STEP4_LOW;
        delay_us(speed);
    }
    EN4_HIGH;
}

void stepper7_run(int dir, int step, int speed)
{
    EN7_LOW;
    if (dir == 1)
        DIR7_HIGH;
    else if (dir == -1)
        DIR7_LOW;
    for (int i = 0; i < step; i++)
    {
        STEP7_HIGH;
        delay_us(speed);
        STEP7_LOW;
        delay_us(speed);
    }
    EN7_HIGH;
}

void stepper8_run(int dir, int step, int speed)
{
    EN8_LOW;
    if (dir == 1)
        DIR8_HIGH;
    else if (dir == -1)
        DIR8_LOW;
    for (int i = 0; i < step; i++)
    {
        STEP8_HIGH;
        delay_us(speed);
        STEP8_LOW;
        delay_us(speed);
    }
    EN8_HIGH;
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

void stepperz_acc(double a, int dir, int current_width, int target_width)
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
}

void steppera_acc(double a, int dir, int current_width, int target_width)
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
}

void stepperb_acc(double a, int dir, int current_width, int target_width)
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
}

void stepper4_acc(double a, int dir, int current_width, int target_width)
{
    int step = 0;
    EN4_LOW;
    if (dir == 1)
        DIR4_HIGH;
    else if (dir == -1)
        DIR4_LOW;
    if (current_width < target_width)
    {
        double current_speed = 0.5 / current_width;
        double target_speed = 0.5 / target_width;
        step = (current_speed * current_speed - target_speed * target_speed) / (2.0 * a);
        double speed = current_speed;
        for (int i = 0; i < step; i++)
        {
            STEP4_HIGH;
            delay_us((int)(0.5 / speed));
            STEP4_LOW;
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
            STEP4_HIGH;
            delay_us((int)(0.5 / speed));
            STEP4_LOW;
            delay_us((int)(0.5 / speed));
            speed = sqrt(speed * speed + 2.0 * a);
        }
    }
    EN4_HIGH;
}

void stepper7_acc(double a, int dir, int current_width, int target_width)
{
    int step = 0;
    EN7_LOW;
    if (dir == 1)
        DIR7_HIGH;
    else if (dir == -1)
        DIR7_LOW;
    if (current_width < target_width)
    {
        double current_speed = 0.5 / current_width;
        double target_speed = 0.5 / target_width;
        step = (current_speed * current_speed - target_speed * target_speed) / (2.0 * a);
        double speed = current_speed;
        for (int i = 0; i < step; i++)
        {
            STEP7_HIGH;
            delay_us((int)(0.5 / speed));
            STEP7_LOW;
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
            STEP7_HIGH;
            delay_us((int)(0.5 / speed));
            STEP7_LOW;
            delay_us((int)(0.5 / speed));
            speed = sqrt(speed * speed + 2.0 * a);
        }
    }
    EN7_HIGH;
}

void stepper8_acc(double a, int dir, int current_width, int target_width)
{
    int step = 0;
    EN8_LOW;
    if (dir == 1)
        DIR8_HIGH;
    else if (dir == -1)
        DIR8_LOW;
    if (current_width < target_width)
    {
        double current_speed = 0.5 / current_width;
        double target_speed = 0.5 / target_width;
        step = (current_speed * current_speed - target_speed * target_speed) / (2.0 * a);
        double speed = current_speed;
        for (int i = 0; i < step; i++)
        {
            STEP8_HIGH;
            delay_us((int)(0.5 / speed));
            STEP8_LOW;
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
            STEP8_HIGH;
            delay_us((int)(0.5 / speed));
            STEP8_LOW;
            delay_us((int)(0.5 / speed));
            speed = sqrt(speed * speed + 2.0 * a);
        }
    }
    EN8_HIGH;
}

void stepperab_acc(double a, int dira, int dirb, int current_width, int target_width)
{
    int step = 0;
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
    if (current_width < target_width)
    {
        double current_speed = 0.5 / current_width;
        double target_speed = 0.5 / target_width;
        step = (current_speed * current_speed - target_speed * target_speed) / (2.0 * a);
        double speed = current_speed;
        for (int i = 0; i < step; i++)
        {
            STEP2_HIGH;
            STEP3_HIGH;
            delay_us((int)(0.5 / speed));
            STEP2_LOW;
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
            STEP2_HIGH;
            STEP3_HIGH;
            delay_us((int)(0.5 / speed));
            STEP2_LOW;
            STEP3_LOW;
            delay_us((int)(0.5 / speed));
            speed = sqrt(speed * speed + 2.0 * a);
        }
    }
    EN2_HIGH;
    EN3_HIGH;
}

void stepperz_move(stepper *stepperx)
{
    int dir = stepperx->dir;
    long step = calculate_steph(stepperx);
    double speed = stepperx->speed;
    double a = stepperx->acc;
    int max_width = stepperx->max_width;
    if (step < 0)
    {
        dir = -dir;
        step = -step;
    }
    int step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_width) * (0.5 / max_width)) / (2.0 * a);
    if (step - 2 * step_acc > 0)
    {
        stepperz_acc(a, dir, max_width, speed);
        stepperz_run(dir, step - 2 * step_acc, speed);
        stepperz_acc(a, dir, speed, max_width);
    }
    else if (step - 2 * step_acc <= 0)
    {
        speed = speed * 2;
        step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_width) * (0.5 / max_width)) / (2.0 * a);
        if (step - 2 * step_acc > 0)
        {
            stepperz_acc(a, dir, max_width, speed);
            stepperz_run(dir, step - 2 * step_acc, speed);
            stepperz_acc(a, dir, speed, max_width);
        }
        else if (step - 2 * step_acc <= 0)
            stepperz_run(dir, step, max_width);
    }
    stepperx->current_pos = stepperx->target_pos;
}

void stepper4_move(stepper *stepperx)
{
    int dir = stepperx->dir;
    long step = calculate_steppump(stepperx);
    double speed = stepperx->speed;
    double a = stepperx->acc;
    int max_width = stepperx->max_width;
    if (step < 0)
    {
        dir = -dir;
        step = -step;
    }
    int step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_width) * (0.5 / max_width)) / (2.0 * a);
    if (step - 2 * step_acc > 0)
    {
        stepper4_acc(a, dir, max_width, speed);
        stepper4_run(dir, step - 2 * step_acc, speed);
        stepper4_acc(a, dir, speed, max_width);
    }
    else if (step - 2 * step_acc <= 0)
    {
        speed = speed * 2;
        step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_width) * (0.5 / max_width)) / (2.0 * a);
        if (step - 2 * step_acc > 0)
        {
            stepper4_acc(a, dir, max_width, speed);
            stepper4_run(dir, step - 2 * step_acc, speed);
            stepper4_acc(a, dir, speed, max_width);
        }
        else if (step - 2 * step_acc <= 0)
            stepper4_run(dir, step, max_width);
    }
    stepperx->current_pos = stepperx->target_pos = 0;
}

void stepper7_move(stepper *stepperx)
{
    int dir = stepperx->dir;
    long step = calculate_steppump(stepperx);
    double speed = stepperx->speed;
    double a = stepperx->acc;
    int max_width = stepperx->max_width;
    if (step < 0)
    {
        dir = -dir;
        step = -step;
    }
    int step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_width) * (0.5 / max_width)) / (2.0 * a);
    if (step - 2 * step_acc > 0)
    {
        stepper7_acc(a, dir, max_width, speed);
        stepper7_run(dir, step - 2 * step_acc, speed);
        stepper7_acc(a, dir, speed, max_width);
    }
    else if (step - 2 * step_acc <= 0)
    {
        speed = speed * 2;
        step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_width) * (0.5 / max_width)) / (2.0 * a);
        if (step - 2 * step_acc > 0)
        {
            stepper7_acc(a, dir, max_width, speed);
            stepper7_run(dir, step - 2 * step_acc, speed);
            stepper7_acc(a, dir, speed, max_width);
        }
        else if (step - 2 * step_acc <= 0)
            stepper7_run(dir, step, max_width);
    }
    stepperx->current_pos = stepperx->target_pos = 0;
}

void stepper8_move(stepper *stepperx)
{
    int dir = stepperx->dir;
    long step = calculate_steppump(stepperx);
    double speed = stepperx->speed;
    double a = stepperx->acc;
    int max_width = stepperx->max_width;
    if (step < 0)
    {
        dir = -dir;
        step = -step;
    }
    int step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_width) * (0.5 / max_width)) / (2.0 * a);
    if (step - 2 * step_acc > 0)
    {
        stepper8_acc(a, dir, max_width, speed);
        stepper8_run(dir, step - 2 * step_acc, speed);
        stepper8_acc(a, dir, speed, max_width);
    }
    else if (step - 2 * step_acc <= 0)
    {
        speed = speed * 2;
        step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_width) * (0.5 / max_width)) / (2.0 * a);
        if (step - 2 * step_acc > 0)
        {
            stepper8_acc(a, dir, max_width, speed);
            stepper8_run(dir, step - 2 * step_acc, speed);
            stepper8_acc(a, dir, speed, max_width);
        }
        else if (step - 2 * step_acc <= 0)
            stepper8_run(dir, step, max_width);
    }
    stepperx->current_pos = stepperx->target_pos = 0;
}

void stepperab_move(stepper *steppera, stepper *stepperb)
{
    int dira = steppera->dir;
    int dirb = stepperb->dir;
    long stepa = calculate_stepab(steppera);
    long stepb = calculate_stepab(stepperb);
    double speeda = steppera->speed;
    double speedb = stepperb->speed;
    double speed = speeda > speedb ? speeda : speedb;
    double aa = steppera->acc;
    double ab = stepperb->acc;
    double a = aa > ab ? ab : aa;
    int max_widtha = steppera->max_width;
    int max_widthb = stepperb->max_width;
    int max_widthab = max_widtha > max_widthb ? max_widtha : max_widthb;
    if (stepa < 0)
    {
        dira = -dira;
        stepa = -stepa;
    }
    if (stepb < 0)
    {
        dirb = -dirb;
        stepb = -stepb;
    }
    if (stepa >= stepb)
    {
        long step = stepb;
        int step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_widthab) * (0.5 / max_widthab)) / (2.0 * a);
        if (step - 2 * step_acc > 0)
        {
            stepperab_acc(a, dira, dirb, max_widthab, speed);
            stepperab_run(dira, dirb, step - 2 * step_acc, speed);
            stepperab_acc(a, dira, dirb, speed, max_widthab);
        }
        else if (step - 2 * step_acc <= 0)
        {
            speed = speed * 2;
            step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_widthab) * (0.5 / max_widthab)) / (2.0 * a);
            if (step - 2 * step_acc > 0)
            {
                stepperab_acc(a, dira, dirb, max_widthab, speed);
                stepperab_run(dira, dirb, step - 2 * step_acc, speed);
                stepperab_acc(a, dira, dirb, speed, max_widthab);
            }
            else if (step - 2 * step_acc <= 0)
                stepperab_run(dira, dirb, step, max_widthab);
        }
        step = stepa - stepb;
        step_acc = ((0.5 / speeda) * (0.5 / speeda) - (0.5 / max_widtha) * (0.5 / max_widtha)) / (2.0 * aa);
        if (step - 2 * step_acc > 0)
        {
            steppera_acc(aa, dira, max_widtha, speeda);
            steppera_run(dira, step - 2 * step_acc, speeda);
            steppera_acc(aa, dira, speeda, max_widtha);
        }
        else if (step - 2 * step_acc <= 0)
        {
            speeda = speeda * 2;
            step_acc = ((0.5 / speeda) * (0.5 / speeda) - (0.5 / max_widtha) * (0.5 / max_widtha)) / (2.0 * aa);
            if (step - 2 * step_acc > 0)
            {
                steppera_acc(aa, dira, max_widtha, speeda);
                steppera_run(dira, step - 2 * step_acc, speeda);
                steppera_acc(aa, dira, speeda, max_widtha);
            }
            else if (step - 2 * step_acc <= 0)
                steppera_run(dira, step, max_widtha);
        }
    }
    else if (stepa < stepb)
    {
        long step = stepa;
        int step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_widthab) * (0.5 / max_widthab)) / (2.0 * a);
        if (step - 2 * step_acc > 0)
        {
            stepperab_acc(a, dira, dirb, max_widthab, speed);
            stepperab_run(dira, dirb, step - 2 * step_acc, speed);
            stepperab_acc(a, dira, dirb, speed, max_widthab);
        }
        else if (step - 2 * step_acc <= 0)
        {
            speed = speed * 2;
            step_acc = ((0.5 / speed) * (0.5 / speed) - (0.5 / max_widthab) * (0.5 / max_widthab)) / (2.0 * a);
            if (step - 2 * step_acc > 0)
            {
                stepperab_acc(a, dira, dirb, max_widthab, speed);
                stepperab_run(dira, dirb, step - 2 * step_acc, speed);
                stepperab_acc(a, dira, dirb, speed, max_widthab);
            }
            else if (step - 2 * step_acc <= 0)
                stepperab_run(dira, dirb, step, max_widthab);
        }
        step = stepb - stepa;
        step_acc = ((0.5 / speedb) * (0.5 / speedb) - (0.5 / max_widthb) * (0.5 / max_widthb)) / (2.0 * ab);
        if (step - 2 * step_acc > 0)
        {
            stepperb_acc(ab, dirb, max_widthb, speedb);
            stepperb_run(dirb, step - 2 * step_acc, speedb);
            stepperb_acc(ab, dirb, speedb, max_widthb);
        }
        else if (step - 2 * step_acc <= 0)
        {
            speedb = speedb * 2;
            step_acc = ((0.5 / speedb) * (0.5 / speedb) - (0.5 / max_widthb) * (0.5 / max_widthb)) / (2.0 * ab);
            if (step - 2 * step_acc > 0)
            {
                stepperb_acc(ab, dirb, max_widthb, speedb);
                stepperb_run(dirb, step - 2 * step_acc, speedb);
                stepperb_acc(ab, dirb, speedb, max_widthb);
            }
            else if (step - 2 * step_acc <= 0)
                stepperb_run(dirb, step, max_widthb);
        }
    }
    steppera->current_pos = steppera->target_pos;
    stepperb->current_pos = stepperb->target_pos;
}

void moveto(double r, double theta, double h, stepper *steppera, stepper *stepperb, stepper *stepperz)
{
    calculate_angles(r, theta, h, &steppera->target_pos, &stepperb->target_pos, &stepperz->target_pos);
    stepperz_move(stepperz);
    stepperab_move(steppera, stepperb);
}

void pump(double volume, double velocity, stepper *stepperx)
{
    if (volume >= MIN_WIDTHPUMP || volume <= MAX_WIDTHPUMP)
        stepperx->speed = velocity;
    else if (volume < MIN_WIDTHPUMP)
        stepperx->speed = MIN_WIDTHPUMP;
    else if (volume > MAX_WIDTHPUMP)
        stepperx->speed = MAX_WIDTHPUMP;
    stepperx->target_pos = volume;
    stepperx->current_pos = 0;
    if (stepperx->id == STEPPER4)
        stepper4_move(stepperx);
    else if (stepperx->id == STEPPER7)
        stepper7_move(stepperx);
    else if (stepperx->id == STEPPER8)
        stepper8_move(stepperx);
}

void reset(stepper *steppera, stepper *stepperb, stepper *stepperz)
{
    EN1_LOW;
    EN2_LOW;
    EN3_LOW;
    DIR1_HIGH;
    DIR2_LOW;
    DIR3_HIGH;

    while (SWITCH3_LOW)
    {
        STEP1_HIGH;
        delay_us(SPEED_Z_RESET);
        STEP1_LOW;
        delay_us(SPEED_Z_RESET);
    }

    if (steppera->current_pos <= 0)
    {
        while (SWITCH2_LOW)
        {
            STEP3_HIGH;
            delay_us(SPEED_B_RESET);
            STEP3_LOW;
            delay_us(SPEED_B_RESET);
        }
        while (SWITCH1_LOW)
        {
            STEP2_HIGH;
            delay_us(SPEED_A_RESET);
            STEP2_LOW;
            delay_us(SPEED_A_RESET);
        }
    }

    else if (steppera->current_pos > 0)
    {
        while (SWITCH1_LOW)
        {
            STEP2_HIGH;
            delay_us(SPEED_A_RESET);
            STEP2_LOW;
            delay_us(SPEED_A_RESET);
        }
        while (SWITCH2_LOW)
        {
            STEP3_HIGH;
            delay_us(SPEED_B_RESET);
            STEP3_LOW;
            delay_us(SPEED_B_RESET);
        }
    }

    EN1_HIGH;
    EN2_HIGH;
    EN3_HIGH;
    steppera->current_pos = steppera->target_pos = THETA_A0;
    stepperb->current_pos = stepperb->target_pos = THETA_B0;
    stepperz->current_pos = stepperz->target_pos = HEIGHT0;
}
