/*
 * File: BatteryManagementSystem_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef BATTERYMANAGEMENTSYSTEM_CA_H
#define BATTERYMANAGEMENTSYSTEM_CA_H

/* preprocessor validation checks */
#include "BatteryManagementSystem_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_BatteryManagementSystem_HWRes;
extern CA_PWS_TestResults CA_BatteryManagementSystem_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_BatteryManagementSystem_ExpHW;
extern CA_HWImpl CA_BatteryManagementSystem_ActHW;

/* entry point function to run tests */
void BatteryManagementSystem_caRunTests(void);

#endif                                 /* BATTERYMANAGEMENTSYSTEM_CA_H */
