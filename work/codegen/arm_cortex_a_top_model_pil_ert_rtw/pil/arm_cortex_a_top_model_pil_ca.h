/*
 * File: arm_cortex_a_top_model_pil_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef ARM_CORTEX_A_TOP_MODEL_PIL_CA_H
#define ARM_CORTEX_A_TOP_MODEL_PIL_CA_H

/* preprocessor validation checks */
#include "arm_cortex_a_top_model_pil_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_arm_cortex_a_top_model_pil_HWRes;
extern CA_PWS_TestResults CA_arm_cortex_a_top_model_pil_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_arm_cortex_a_top_model_pil_ExpHW;
extern CA_HWImpl CA_arm_cortex_a_top_model_pil_ActHW;

/* entry point function to run tests */
void arm_cortex_a_top_model_pil_caRunTests(void);

#endif                                 /* ARM_CORTEX_A_TOP_MODEL_PIL_CA_H */
