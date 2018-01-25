/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 21-Jan-2018 10:19:15
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "simple_addition.h"
#include "main.h"
#include "simple_addition_terminate.h"
#include "simple_addition_initialize.h"

/* Function Declarations */
static void argInit_1024x1_real32_T(float result[1024]);
static float argInit_real32_T(void);
static void main_simple_addition(void);

/* Function Definitions */

/*
 * Arguments    : float result[1024]
 * Return Type  : void
 */
static void argInit_1024x1_real32_T(float result[1024])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 1024; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real32_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : float
 */
static float argInit_real32_T(void)
{
  return 0.0F;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_simple_addition(void)
{
  float fv0[1024];
  float fv1[1024];
  float y[1024];

  /* Initialize function 'simple_addition' input arguments. */
  /* Initialize function input argument 'u1'. */
  /* Initialize function input argument 'u2'. */
  /* Call the entry-point 'simple_addition'. */
  argInit_1024x1_real32_T(fv0);
  argInit_1024x1_real32_T(fv1);
  simple_addition(fv0, fv1, y);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  simple_addition_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_simple_addition();

  /* Terminate the application.
     You do not need to do this more than one time. */
  simple_addition_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
