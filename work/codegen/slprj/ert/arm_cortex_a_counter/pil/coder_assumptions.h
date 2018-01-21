/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "arm_cortex_a_counter_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_arm_cortex_a_counter_ExpHW
#define CA_Actual_HWImpl               CA_arm_cortex_a_counter_ActHW
#define CA_HWImpl_Results              CA_arm_cortex_a_counter_HWRes
#define CA_PortableWordSizes_Results   CA_arm_cortex_a_counter_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   arm_cortex_a_counter_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
