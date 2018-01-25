/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_simple_addition_target.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 21-Jan-2018 10:19:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simple_addition.h"
#include "_coder_simple_addition_target.h"

/* Function Declarations */
static void xilTargetDeserializer(float b[1024]);
static void xilTargetSerializer(const float b[1024]);

/* Function Definitions */

/*
 * Arguments    : float b[1024]
 * Return Type  : void
 */
static void xilTargetDeserializer(float b[1024])
{
  xilReadData((MemUnit_T *)b, sizeof(float) << 10);
}

/*
 * Arguments    : const float b[1024]
 * Return Type  : void
 */
static void xilTargetSerializer(const float b[1024])
{
  xilWriteData((MemUnit_T *)b, sizeof(float) << 10);
}

/*
 * Arguments    : unsigned int fcnId
 * Return Type  : XIL_PROCESSDATA_ERROR_CODE
 */
XIL_PROCESSDATA_ERROR_CODE xilTarget_simple_addition(unsigned int fcnId)
{
  XIL_PROCESSDATA_ERROR_CODE error_id;
  float u1[1024];
  float u2[1024];
  float y[1024];

  /* Deserialize function input u1 argument. */
  xilTargetDeserializer(u1);

  /* Deserialize function input u2 argument. */
  xilTargetDeserializer(u2);

  /* Calling XIL API before invoke entry point. */
  xilPreEntryPoint(fcnId);

  /* Invoke target entry point. */
  simple_addition(u1, u2, y);

  /* Calling XIL API after invoke entry point. */
  if (xilPostEntryPoint(fcnId) == XIL_INTERFACE_SUCCESS) {
    /* Serialize function output argument y. */
    xilTargetSerializer(y);
    error_id = XIL_PROCESSDATA_SUCCESS;
  } else {
    error_id = XIL_PROCESSDATA_DATA_STREAM_ERROR;
  }

  return error_id;
}

/*
 * File trailer for _coder_simple_addition_target.c
 *
 * [EOF]
 */
