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

#define R0 90.0000
#define THETA_A0 0.0000
#define THETA_B0 0.0000
#define REDUCTION_RATIOAB 30
#define REDUCTION_RATIOH 30
#define STEP_ANGLE 1.8
#define SUBDIVISION 8
#define PITCH 0.83
#define M_PI 3.14159265358979323846

    void calculate_angles(double r, double theta, double *theta_a1, double *theta_b1, double *theta_a2, double *theta_b2);
    long calculate_posab(double theta);
    long calculate_posh(double height);

#ifdef __cplusplus
}
#endif
#endif /*__ SOLUTION_H__ */
