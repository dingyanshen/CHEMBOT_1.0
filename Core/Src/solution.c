/**
 ******************************************************************************
 * @file    solution.c
 * @brief   This file provides code for the solution.
 ******************************************************************************
 */

#include "solution.h"

void calculate_angles(double r, double theta, double h, double *theta_a, double *theta_b, double *height)
{
    if (r > R_MAX || r < R_MIN || theta > THETA_MAX || theta < THETA_MIN || h > H_MAX || h < H_MIN)
        return;
    double temp = 180.0000 * asin(r / (2.0000 * R0)) / M_PI;
    double _theta_b = 180.0000 - 2.0000 * temp;
    double _theta_a = temp - 90.0000 + theta;
    double _height = h;
    if (_theta_a > THETA_A_MAX || _theta_a < THETA_A_MIN || _theta_b > THETA_B_MAX || _theta_b < THETA_B_MIN || _height > HEIGHT_MAX || _height < HEIGHT_MIN)
    {
        _theta_b = 2.0000 * temp - 180.0000;
        _theta_a = 90.0000 - temp + theta;
        if (_theta_a > THETA_A_MAX || _theta_a < THETA_A_MIN || _theta_b > THETA_B_MAX || _theta_b < THETA_B_MIN || _height > HEIGHT_MAX || _height < HEIGHT_MIN)
            return;
    }
    *theta_a = _theta_a;
    *theta_b = _theta_b;
    *height = _height;
}

long calculate_stepab(stepper *stepperx)
{
    return (long)((stepperx->target_pos - stepperx->current_pos) * REDUCTION_RATIOAB * SUBDIVISION / STEP_ANGLE);
}

long calculate_steph(stepper *stepperx)
{
    return (long)(((stepperx->target_pos - stepperx->current_pos) / PITCH) * REDUCTION_RATIOH * SUBDIVISION / STEP_ANGLE);
}

long calculate_steppump(stepper *stepperx)
{
    return (long)((stepperx->target_pos - stepperx->current_pos) * KPUMP);
}
