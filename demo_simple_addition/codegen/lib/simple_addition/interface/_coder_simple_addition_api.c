/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_simple_addition_api.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 21-Jan-2018 10:19:15
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_simple_addition_api.h"
#include "_coder_simple_addition_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
static boolean_T xilAlreadyInited;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131451U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "simple_addition",                   /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real32_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[1024];
static real32_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1024];
static real32_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u1,
  const char_T *identifier))[1024];
static const mxArray *emlrt_marshallOut(const real32_T u[1024]);
static void simple_addition_once(void);
static void xilHostDeserializer(real32_T b[1024]);
static void xilHostSerializer(const real32_T b[1024]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T (*)[1024]
 */
static real32_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[1024]
{
  real32_T (*y)[1024];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T (*)[1024]
 */
  static real32_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1024]
{
  real32_T (*ret)[1024];
  static const int32_T dims[1] = { 1024 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single", false, 1U, dims);
  ret = (real32_T (*)[1024])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u1
 *                const char_T *identifier
 * Return Type  : real32_T (*)[1024]
 */
static real32_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u1,
  const char_T *identifier))[1024]
{
  real32_T (*y)[1024];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u1), &thisId);
  emlrtDestroyArray(&u1);
  return y;
}
/*
 * Arguments    : const real32_T u[1024]
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const real32_T u[1024])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 0 };

  static const int32_T iv1[1] = { 1024 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxSINGLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv1, 1);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void simple_addition_once(void)
{
  xilAlreadyInited = false;
}

/*
 * Arguments    : real32_T b[1024]
 * Return Type  : void
 */
static void xilHostDeserializer(real32_T b[1024])
{
  xilReadData((uint8_T *)b, (size_t)1024, MEM_UNIT_SINGLE_TYPE);
}

/*
 * Arguments    : const real32_T b[1024]
 * Return Type  : void
 */
static void xilHostSerializer(const real32_T b[1024])
{
  xilWriteData((uint8_T *)b, (size_t)1024, MEM_UNIT_SINGLE_TYPE);
}

/*
 * Arguments    : const real32_T u1[1024]
 *                const real32_T u2[1024]
 *                real32_T y[1024]
 * Return Type  : void
 */
void simple_additionXilWrapper(const real32_T u1[1024], const real32_T u2[1024],
  real32_T y[1024])
{
  /* Serialize function input argument u1. */
  xilHostSerializer(u1);

  /* Serialize function input argument u2. */
  xilHostSerializer(u2);

  /* Calling XIL to invoke target side. */
  xilEntryPointHost(1U);

  /* Deserialize function output argument y. */
  xilHostDeserializer(y);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void simple_addition_api(const mxArray * const prhs[2], const mxArray *plhs[1])
{
  real32_T (*y)[1024];
  real32_T (*u1)[1024];
  real32_T (*u2)[1024];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  y = (real32_T (*)[1024])mxMalloc(sizeof(real32_T [1024]));

  /* Marshall function inputs */
  u1 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "u1");
  u2 = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "u2");

  /* Calling XIL to setup. */
  xilPreEntryPointHost(1U);

  /* Invoke the wrapper function */
  simple_additionXilWrapper(*u1, *u2, *y);

  /* Calling Xil to clean-up. */
  xilPostEntryPointHost(1U);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*y);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void simple_addition_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  simple_addition_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void simple_addition_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    simple_addition_once();
  }

  if (!xilAlreadyInited) {
    xilInitializeHost(xil_terminate);
    xilAlreadyInited = true;
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void simple_addition_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void xil_terminate(void)
{
  xilAlreadyInited = false;
  simple_addition_terminate();
}

/*
 * File trailer for _coder_simple_addition_api.c
 *
 * [EOF]
 */
