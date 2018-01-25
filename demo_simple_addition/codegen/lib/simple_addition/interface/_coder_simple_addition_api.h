/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_simple_addition_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 21-Jan-2018 10:19:15
 */

#ifndef _CODER_SIMPLE_ADDITION_API_H
#define _CODER_SIMPLE_ADDITION_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "xil_host_interface.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_simple_addition_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void simple_additionXilWrapper(const real32_T u1[1024], const real32_T
  u2[1024], real32_T y[1024]);
extern void simple_addition_api(const mxArray * const prhs[2], const mxArray
  *plhs[1]);
extern void simple_addition_atexit(void);
extern void simple_addition_initialize(void);
extern void simple_addition_terminate(void);
extern void simple_addition_xil_terminate(void);
extern void xil_terminate(void);

#endif

/*
 * File trailer for _coder_simple_addition_api.h
 *
 * [EOF]
 */
