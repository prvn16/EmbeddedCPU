/*
 * File: simple_addition_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef SIMPLE_ADDITION_CA_H
#define SIMPLE_ADDITION_CA_H

/* preprocessor validation checks */
#include "simple_addition_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_simple_addition_HWRes;
extern CA_PWS_TestResults CA_simple_addition_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_simple_addition_ExpHW;
extern CA_HWImpl CA_simple_addition_ActHW;

/* entry point function to run tests */
void simple_addition_caRunTests(void);

#endif                                 /* SIMPLE_ADDITION_CA_H */
