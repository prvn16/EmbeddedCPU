/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: simple_addition.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 21-Jan-2018 10:19:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simple_addition.h"

/* Function Definitions */

/*
 * Copyright 2015 The MathWorks, Inc.
 * Arguments    : const float u1[1024]
 *                const float u2[1024]
 *                float y[1024]
 * Return Type  : void
 */
void simple_addition(const float u1[1024], const float u2[1024], float y[1024])
{
  int i;
  for (i = 0; i < 1024; i++) {
    y[i] = u1[i] + u2[i];
  }
}

/*
 * File trailer for simple_addition.c
 *
 * [EOF]
 */
