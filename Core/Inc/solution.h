/**
 ******************************************************************************
 * @file    solution.h
 * @brief   This file provides all the functions prototypes for
 *          the solution.c file.
 ******************************************************************************
 */

#ifndef __SOLUTION_H__
#define __SOLUTION_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "math.h"
#include "stepper.h"

#define R0 90.0000

#define REDUCTION_RATIOAB 30
#define REDUCTION_RATIOH 30
#define STEP_ANGLE 1.8
#define SUBDIVISION 8
#define PITCH 0.83
#define M_PI 3.14159265358979323846

#define HEIGHT0 180.0000
#define THETA_A0 -101.0000
#define THETA_B0 133.0000

#define HEIGHT_MAX 180.0000
#define HEIGHT_MIN 80.0000
#define THETA_A_MAX 90.0000
#define THETA_A_MIN -90.0000
#define THETA_B_MAX 150.0000
#define THETA_B_MIN -150.0000
#define R_MAX 180.0000
#define R_MIN 50.0000
#define THETA_MAX 90.0000
#define THETA_MIN -90.0000
#define H_MAX 180.0000
#define H_MIN 80.0000

    void calculate_angles(double r, double theta, double h, double *theta_a, double *theta_b, double *height);
    long calculate_stepab(stepper *stepperx);
    long calculate_steph(stepper *stepperx);

#ifdef __cplusplus
}
#endif
#endif /*__ SOLUTION_H__ */
