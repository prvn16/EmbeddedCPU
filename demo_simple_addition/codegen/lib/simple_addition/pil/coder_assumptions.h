/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "simple_addition_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_simple_addition_ExpHW
#define CA_Actual_HWImpl               CA_simple_addition_ActHW
#define CA_HWImpl_Results              CA_simple_addition_HWRes
#define CA_PortableWordSizes_Results   CA_simple_addition_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   simple_addition_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
