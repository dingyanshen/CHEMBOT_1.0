/**
 ******************************************************************************
 * @file    solution.c
 * @brief   This file provides code for the solution.
 ******************************************************************************
 */

#include "solution.h"

void calculate_angles(double r, double theta, double *theta_a1, double *theta_b1, double *theta_a2, double *theta_b2)
{
    double theta_b = 360.0000 * asin(r / (2.0000 * R0)) / M_PI;
    *theta_b1 = theta_b - THETA_B0;
    *theta_b2 = 360.0000 - theta_b - THETA_B0;
    *theta_a1 = theta + 90.0000 - theta_b / 2.0000 - THETA_A0;
    *theta_a2 = theta - 90.0000 + theta_b / 2.0000 - THETA_A0;
}

long calculate_posab(double theta)
{
    return (long)(theta * REDUCTION_RATIOAB * SUBDIVISION / STEP_ANGLE);
}

long calculate_posh(double height)
{
    return (long)((height / PITCH) * REDUCTION_RATIOH * SUBDIVISION / STEP_ANGLE);
}
