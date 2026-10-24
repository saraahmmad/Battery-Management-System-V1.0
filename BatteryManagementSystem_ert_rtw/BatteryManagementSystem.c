/*
 * File: BatteryManagementSystem.c
 *
 * Code generated for Simulink model 'BatteryManagementSystem'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Oct 23 21:17:40 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "BatteryManagementSystem.h"
#include "rtwtypes.h"
#include <math.h>
#include "math.h"

/* Named constants for Chart: '<S1>/MainStateMachine1' */
#define IN_CC                          ((uint8_T)1U)
#define IN_CV                          ((uint8_T)2U)
#define IN_Charging                    ((uint8_T)1U)
#define IN_Discharging                 ((uint8_T)2U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_Standby                     ((uint8_T)3U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
static void rate_scheduler(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
real_T rtNaN = -(real_T)NAN;
real_T rtInf = (real_T)INFINITY;
real_T rtMinusInf = -(real_T)INFINITY;
real32_T rtNaNF = -(real32_T)NAN;
real32_T rtInfF = (real32_T)INFINITY;
real32_T rtMinusInfF = -(real32_T)INFINITY;

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

static real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex)
{
  real32_T frac;
  real32_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = (uint32_T)(maxIndex >> 1UL);
    iLeft = 0UL;
    iRght = maxIndex;
    while ((uint32_T)(iRght - iLeft) > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (uint32_T)((uint32_T)(iRght + iLeft) >> 1UL);
    }

    frac = (u0 - bp0[iLeft]) / (bp0[(uint32_T)(iLeft + 1UL)] - bp0[iLeft]);
  } else {
    iLeft = (uint32_T)(maxIndex - 1UL);
    frac = (u0 - bp0[(uint32_T)(maxIndex - 1UL)]) / (bp0[maxIndex] - bp0
      [(uint32_T)(maxIndex - 1UL)]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[(uint32_T)(iLeft + 1UL)] - yL_0d0) * frac + yL_0d0;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.1s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }

  (rtM->Timing.TaskCounters.TID[2])++;
  if ((rtM->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.2s, 0.0s] */
    rtM->Timing.TaskCounters.TID[2] = 0;
  }

  (rtM->Timing.TaskCounters.TID[3])++;
  if ((rtM->Timing.TaskCounters.TID[3]) > 4) {/* Sample time: [0.25s, 0.0s] */
    rtM->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Model step function */
void BatteryManagementSystem_step(void)
{
  real32_T rtb_ImpAsg_InsertedFor_VfbState[3];
  real32_T VfbCellVoltages;
  real32_T Vmin;
  int16_T idx;
  int16_T k;
  int16_T rtb_DataTypeConversion1_idx_0;
  int16_T rtb_DataTypeConversion1_idx_1;
  int16_T rtb_DataTypeConversion1_idx_2;
  boolean_T rtb_BalanceCommand[3];
  boolean_T exitg1;
  boolean_T rtb_BalancingActive;

  /* Outputs for Atomic SubSystem: '<Root>/BatteryManagementSystem' */
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Atomic SubSystem: '<S1>/ StateOfChargeEstimation' */
    /* Outputs for Iterator SubSystem: '<S2>/StateOfChargeEstimation (Coulomb Counting)' incorporates:
     *  ForEach: '<S6>/For Each'
     */
    /* Gain: '<S6>/Cn2' incorporates:
     *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
     */
    Vmin = 0.000104821804F * rtDW.CoreSubsys[0].DiscreteTimeIntegrator_DSTATE;

    /* Outputs for Enabled SubSystem: '<S6>/Subsystem' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    /* Step: '<S6>/Step' */
    if (((rtM->Timing.clockTick2) * 0.2) < 0.1) {
      /* Lookup_n-D: '<S7>/1-D Lookup Table3' incorporates:
       *  ForEachSliceSelector generated from: '<S6>/VfbCellVoltages'
       *  Inport: '<Root>/VfbCellVoltages'
       */
      rtDW.CoreSubsys[0].uDLookupTable3 = look1_iflf_binlx(rtU.VfbCellVoltages[0],
        rtConstP.uDLookupTable3_bp01Data, rtConstP.uDLookupTable3_tableData,
        100UL);
    }

    /* End of Outputs for SubSystem: '<S6>/Subsystem' */

    /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S6>/Cn1'
     *  Inport: '<Root>/VfbPackCurrent '
     */
    rtDW.CoreSubsys[0].DiscreteTimeIntegrator_DSTATE += 0.2F *
      -rtU.VfbPackCurrent;

    /* ForEachSliceAssignment generated from: '<S6>/VfbStateOfCharge' incorporates:
     *  Sum: '<S6>/Subtract'
     */
    rtb_ImpAsg_InsertedFor_VfbState[0] = rtDW.CoreSubsys[0].uDLookupTable3 -
      Vmin;

    /* Gain: '<S6>/Cn2' incorporates:
     *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
     */
    Vmin = 0.000104821804F * rtDW.CoreSubsys[1].DiscreteTimeIntegrator_DSTATE;

    /* Outputs for Enabled SubSystem: '<S6>/Subsystem' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    /* Step: '<S6>/Step' */
    if (((rtM->Timing.clockTick2) * 0.2) < 0.1) {
      /* Lookup_n-D: '<S7>/1-D Lookup Table3' incorporates:
       *  ForEachSliceSelector generated from: '<S6>/VfbCellVoltages'
       *  Inport: '<Root>/VfbCellVoltages'
       */
      rtDW.CoreSubsys[1].uDLookupTable3 = look1_iflf_binlx(rtU.VfbCellVoltages[1],
        rtConstP.uDLookupTable3_bp01Data, rtConstP.uDLookupTable3_tableData,
        100UL);
    }

    /* End of Outputs for SubSystem: '<S6>/Subsystem' */

    /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S6>/Cn1'
     *  Inport: '<Root>/VfbPackCurrent '
     */
    rtDW.CoreSubsys[1].DiscreteTimeIntegrator_DSTATE += 0.2F *
      -rtU.VfbPackCurrent;

    /* ForEachSliceAssignment generated from: '<S6>/VfbStateOfCharge' incorporates:
     *  Sum: '<S6>/Subtract'
     */
    rtb_ImpAsg_InsertedFor_VfbState[1] = rtDW.CoreSubsys[1].uDLookupTable3 -
      Vmin;

    /* Gain: '<S6>/Cn2' incorporates:
     *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
     */
    Vmin = 0.000104821804F * rtDW.CoreSubsys[2].DiscreteTimeIntegrator_DSTATE;

    /* Outputs for Enabled SubSystem: '<S6>/Subsystem' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    /* Step: '<S6>/Step' */
    if (((rtM->Timing.clockTick2) * 0.2) < 0.1) {
      /* Lookup_n-D: '<S7>/1-D Lookup Table3' incorporates:
       *  ForEachSliceSelector generated from: '<S6>/VfbCellVoltages'
       *  Inport: '<Root>/VfbCellVoltages'
       */
      rtDW.CoreSubsys[2].uDLookupTable3 = look1_iflf_binlx(rtU.VfbCellVoltages[2],
        rtConstP.uDLookupTable3_bp01Data, rtConstP.uDLookupTable3_tableData,
        100UL);
    }

    /* End of Outputs for SubSystem: '<S6>/Subsystem' */

    /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S6>/Cn1'
     *  Inport: '<Root>/VfbPackCurrent '
     */
    rtDW.CoreSubsys[2].DiscreteTimeIntegrator_DSTATE += 0.2F *
      -rtU.VfbPackCurrent;

    /* ForEachSliceAssignment generated from: '<S6>/VfbStateOfCharge' incorporates:
     *  Sum: '<S6>/Subtract'
     */
    rtb_ImpAsg_InsertedFor_VfbState[2] = rtDW.CoreSubsys[2].uDLookupTable3 -
      Vmin;

    /* End of Outputs for SubSystem: '<S2>/StateOfChargeEstimation (Coulomb Counting)' */
    /* End of Outputs for SubSystem: '<S1>/ StateOfChargeEstimation' */
  }

  if (rtM->Timing.TaskCounters.TID[3] == 0) {
    /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
     *  UnitDelay: '<S1>/Unit Delay6'
     */
    rtb_DataTypeConversion1_idx_0 = (int16_T)rtDW.UnitDelay6_DSTATE[0];
    rtb_DataTypeConversion1_idx_1 = (int16_T)rtDW.UnitDelay6_DSTATE[1];
    rtb_DataTypeConversion1_idx_2 = (int16_T)rtDW.UnitDelay6_DSTATE[2];

    /* MATLAB Function: '<S1>/BalancingLogic' incorporates:
     *  Inport: '<Root>/VfbCellVoltages'
     */
    if (!rtIsNaNF(rtU.VfbCellVoltages[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!rtIsNaNF(rtU.VfbCellVoltages[(int16_T)(k - 1)])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      Vmin = rtU.VfbCellVoltages[0];
    } else {
      Vmin = rtU.VfbCellVoltages[(int16_T)(idx - 1)];
      for (k = (int16_T)(idx + 1); k < 4; k++) {
        VfbCellVoltages = rtU.VfbCellVoltages[(int16_T)(k - 1)];
        if (Vmin > VfbCellVoltages) {
          Vmin = VfbCellVoltages;
        }
      }
    }

    rtb_BalanceCommand[0] = ((real_T)(rtU.VfbCellVoltages[0] - Vmin) > 0.05);
    rtb_BalanceCommand[1] = ((real_T)(rtU.VfbCellVoltages[1] - Vmin) > 0.05);
    rtb_BalanceCommand[2] = ((real_T)(rtU.VfbCellVoltages[2] - Vmin) > 0.05);
    rtb_BalancingActive = false;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx < 3)) {
      if (rtb_BalanceCommand[idx]) {
        rtb_BalancingActive = true;
        exitg1 = true;
      } else {
        idx++;
      }
    }

    /* End of MATLAB Function: '<S1>/BalancingLogic' */
  }

  /* UnitDelay: '<S1>/Unit Delay1' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* UnitDelay: '<S1>/Unit Delay1' */
    rtDW.UnitDelay1 = rtDW.UnitDelay1_DSTATE;

    /* UnitDelay: '<S1>/Unit Delay2' */
    rtDW.UnitDelay2 = rtDW.UnitDelay2_DSTATE;

    /* UnitDelay: '<S1>/Unit Delay5' */
    rtDW.UnitDelay5 = rtDW.UnitDelay5_DSTATE;

    /* UnitDelay: '<S1>/Unit Delay4' */
    rtDW.UnitDelay4 = rtDW.UnitDelay4_DSTATE;

    /* Outputs for Atomic SubSystem: '<S1>/CurrentLimitsCalculation ' */
    /* MinMax: '<S4>/MinMax' incorporates:
     *  Inport: '<Root>/VfbCellVoltages'
     */
    rtDW.MinMax = fminf(fminf(rtU.VfbCellVoltages[0], rtU.VfbCellVoltages[1]),
                        rtU.VfbCellVoltages[2]);

    /* MinMax: '<S4>/MinMax1' incorporates:
     *  Inport: '<Root>/VfbCellTemperatures'
     */
    Vmin = fminf(fminf(rtU.VfbCellTemperatures[0], rtU.VfbCellTemperatures[1]),
                 rtU.VfbCellTemperatures[2]);

    /* MinMax: '<S4>/MinMax4' incorporates:
     *  Inport: '<Root>/VfbCellTemperatures'
     */
    VfbCellVoltages = fmaxf(fmaxf(rtU.VfbCellTemperatures[0],
      rtU.VfbCellTemperatures[1]), rtU.VfbCellTemperatures[2]);

    /* Gain: '<S4>/Gain2' incorporates:
     *  Gain: '<S4>/Gain'
     *  Lookup_n-D: '<S4>/HighTemp_DischargeCurrent'
     *  Lookup_n-D: '<S4>/LowTemp_DischargeCurrent'
     *  Lookup_n-D: '<S4>/MinCellVoltage_DischrageCurrent'
     *  MinMax: '<S4>/Min'
     *  MinMax: '<S4>/MinMax'
     *  MinMax: '<S4>/MinMax1'
     *  MinMax: '<S4>/MinMax4'
     */
    rtDW.Gain2 = -(1.325F * fminf(fminf(look1_iflf_binlx(rtDW.MinMax,
      rtConstP.MinCellVoltage_DischrageCurre_p,
      rtConstP.MinCellVoltage_DischrageCurrent, 5UL), look1_iflf_binlx(Vmin,
      rtConstP.LowTemp_DischargeCurrent_bp01Da,
      rtConstP.LowTemp_DischargeCurrent_tableD, 5UL)), look1_iflf_binlx
      (VfbCellVoltages, rtConstP.pooled3,
       rtConstP.HighTemp_DischargeCurrent_table, 5UL)));

    /* MinMax: '<S4>/MinMax2' incorporates:
     *  Inport: '<Root>/VfbCellVoltages'
     */
    rtDW.MinMax2 = fmaxf(fmaxf(rtU.VfbCellVoltages[0], rtU.VfbCellVoltages[1]),
                         rtU.VfbCellVoltages[2]);

    /* Gain: '<S4>/Gain1' incorporates:
     *  Lookup_n-D: '<S4>/HighTemp_ChrageCurrent'
     *  Lookup_n-D: '<S4>/LowTemp_ChrageCurrent'
     *  Lookup_n-D: '<S4>/MaxCellVoltage_ChrageCurrent'
     *  MinMax: '<S4>/Min1'
     *  MinMax: '<S4>/MinMax1'
     *  MinMax: '<S4>/MinMax2'
     *  MinMax: '<S4>/MinMax4'
     */
    rtDW.Gain1 = 1.325F * fminf(fminf(look1_iflf_binlx(rtDW.MinMax2,
      rtConstP.MaxCellVoltage_ChrageCurrent_bp,
      rtConstP.MaxCellVoltage_ChrageCurrent_ta, 7UL), look1_iflf_binlx(Vmin,
      rtConstP.LowTemp_ChrageCurrent_bp01Data,
      rtConstP.LowTemp_ChrageCurrent_tableData, 6UL)), look1_iflf_binlx
      (VfbCellVoltages, rtConstP.pooled3,
       rtConstP.HighTemp_ChrageCurrent_tableDat, 5UL));

    /* End of Outputs for SubSystem: '<S1>/CurrentLimitsCalculation ' */
  }

  /* End of UnitDelay: '<S1>/Unit Delay1' */

  /* Chart: '<S1>/MainStateMachine1' incorporates:
   *  Inport: '<Root>/ChargerOutputVoltage'
   *  Inport: '<Root>/InverterOutputVoltage'
   *  Inport: '<Root>/VfbStateRequest'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  if ((uint16_T)rtDW.is_active_c1_BatteryManagementS == 0U) {
    rtDW.is_active_c1_BatteryManagementS = 1U;
    rtDW.is_c1_BatteryManagementSystem = IN_Standby;

    /* Outport: '<Root>/VfbChargeCurrentCmd' */
    rtY.VfbChargeCurrentCmd = 0.0F;

    /* Outport: '<Root>/VfbBmsOperationalState' */
    rtY.VfbBmsOperationalState = Standby;

    /* Outport: '<Root>/VfbInverterContactorCommand' */
    rtY.VfbInverterContactorCommand = false;

    /* Outport: '<Root>/VfbChargerContactorCommand' */
    rtY.VfbChargerContactorCommand = false;
  } else {
    switch (rtDW.is_c1_BatteryManagementSystem) {
     case IN_Charging:
      /* Outport: '<Root>/VfbBmsOperationalState' */
      rtY.VfbBmsOperationalState = Charging;
      if ((rtU.VfbStateRequest == SRE_Standby) || (rtDW.UnitDelay_DSTATE <
           0.088333331F)) {
        rtDW.is_Charging = IN_NO_ACTIVE_CHILD;
        rtDW.is_c1_BatteryManagementSystem = IN_Standby;

        /* Outport: '<Root>/VfbChargeCurrentCmd' */
        rtY.VfbChargeCurrentCmd = 0.0F;

        /* Outport: '<Root>/VfbBmsOperationalState' */
        rtY.VfbBmsOperationalState = Standby;

        /* Outport: '<Root>/VfbInverterContactorCommand' */
        rtY.VfbInverterContactorCommand = false;

        /* Outport: '<Root>/VfbChargerContactorCommand' */
        rtY.VfbChargerContactorCommand = false;
      } else if ((rtU.VfbStateRequest == SRE_Discharging) && (fabsf
                  (rtU.InverterOutputVoltage - rtDW.UnitDelay3_DSTATE) < 2.0F) &&
                 (fabsf(rtU.ChargerOutputVoltage - rtDW.UnitDelay3_DSTATE) <
                  2.0F)) {
        rtDW.is_Charging = IN_NO_ACTIVE_CHILD;

        /* Outport: '<Root>/VfbChargerContactorCommand' */
        rtY.VfbChargerContactorCommand = false;
        rtDW.is_c1_BatteryManagementSystem = IN_Discharging;

        /* Outport: '<Root>/VfbInverterContactorCommand' */
        rtY.VfbInverterContactorCommand = true;

        /* Outport: '<Root>/VfbBmsOperationalState' */
        rtY.VfbBmsOperationalState = Discharging;
      } else if (rtDW.is_Charging == IN_CC) {
        if (rtDW.UnitDelay1 > 4.3F) {
          rtDW.is_Charging = IN_CV;
        }
      } else {
        /* Outport: '<Root>/VfbChargeCurrentCmd' */
        /* case IN_CV: */
        rtY.VfbChargeCurrentCmd -= rtDW.UnitDelay1 - 4.3F;
        rtY.VfbChargeCurrentCmd = rtY.VfbChargeCurrentCmd <= rtDW.UnitDelay5 ?
          rtY.VfbChargeCurrentCmd : rtDW.UnitDelay5;
      }
      break;

     case IN_Discharging:
      /* Outport: '<Root>/VfbBmsOperationalState' */
      rtY.VfbBmsOperationalState = Discharging;
      if ((rtU.VfbStateRequest == SRE_Charging) && (fabsf
           (rtU.ChargerOutputVoltage - rtDW.UnitDelay3_DSTATE) < 2.0F)) {
        /* Outport: '<Root>/VfbInverterContactorCommand' */
        rtY.VfbInverterContactorCommand = false;
        rtDW.is_c1_BatteryManagementSystem = IN_Charging;

        /* Outport: '<Root>/VfbBmsOperationalState' */
        rtY.VfbBmsOperationalState = Charging;

        /* Outport: '<Root>/VfbChargerContactorCommand' */
        rtY.VfbChargerContactorCommand = true;
        rtDW.is_Charging = IN_CC;

        /* Outport: '<Root>/VfbChargeCurrentCmd' */
        rtY.VfbChargeCurrentCmd = rtDW.UnitDelay5;
      } else if ((rtU.VfbStateRequest == SRE_Standby) || (rtDW.UnitDelay2 < 3.2F))
      {
        rtDW.is_c1_BatteryManagementSystem = IN_Standby;

        /* Outport: '<Root>/VfbChargeCurrentCmd' */
        rtY.VfbChargeCurrentCmd = 0.0F;

        /* Outport: '<Root>/VfbBmsOperationalState' */
        rtY.VfbBmsOperationalState = Standby;

        /* Outport: '<Root>/VfbInverterContactorCommand' */
        rtY.VfbInverterContactorCommand = false;

        /* Outport: '<Root>/VfbChargerContactorCommand' */
        rtY.VfbChargerContactorCommand = false;
      } else {
        /* Outport: '<Root>/VfbChargeCurrentCmd' */
        rtY.VfbChargeCurrentCmd = rtDW.UnitDelay4;
      }
      break;

     default:
      /* Outport: '<Root>/VfbBmsOperationalState' */
      /* case IN_Standby: */
      rtY.VfbBmsOperationalState = Standby;
      if ((rtU.VfbStateRequest == SRE_Discharging) && ((real_T)rtDW.UnitDelay2 >
           3.5200000524520876) && (fabsf(rtU.InverterOutputVoltage -
            rtDW.UnitDelay3_DSTATE) < 2.0F)) {
        rtDW.is_c1_BatteryManagementSystem = IN_Discharging;

        /* Outport: '<Root>/VfbInverterContactorCommand' */
        rtY.VfbInverterContactorCommand = true;

        /* Outport: '<Root>/VfbBmsOperationalState' */
        rtY.VfbBmsOperationalState = Discharging;
      } else if ((rtU.VfbStateRequest == SRE_Charging) && ((real_T)
                  rtDW.UnitDelay2 < 4.08500018119812) && (fabsf
                  (rtU.ChargerOutputVoltage - rtDW.UnitDelay3_DSTATE) < 2.0F)) {
        rtDW.is_c1_BatteryManagementSystem = IN_Charging;

        /* Outport: '<Root>/VfbBmsOperationalState' */
        rtY.VfbBmsOperationalState = Charging;

        /* Outport: '<Root>/VfbChargerContactorCommand' */
        rtY.VfbChargerContactorCommand = true;
        rtDW.is_Charging = IN_CC;

        /* Outport: '<Root>/VfbChargeCurrentCmd' */
        rtY.VfbChargeCurrentCmd = rtDW.UnitDelay5;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/MainStateMachine1' */
  if (rtM->Timing.TaskCounters.TID[3] == 0) {
    /* Update for UnitDelay: '<S1>/Unit Delay6' */
    rtDW.UnitDelay6_DSTATE[0] = rtb_BalanceCommand[0];
    rtDW.UnitDelay6_DSTATE[1] = rtb_BalanceCommand[1];
    rtDW.UnitDelay6_DSTATE[2] = rtb_BalanceCommand[2];
  }

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  Inport: '<Root>/VfbPackCurrent '
   */
  rtDW.UnitDelay_DSTATE = rtU.VfbPackCurrent;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtDW.UnitDelay1_DSTATE = rtDW.MinMax2;

    /* Update for UnitDelay: '<S1>/Unit Delay2' */
    rtDW.UnitDelay2_DSTATE = rtDW.MinMax;

    /* Update for UnitDelay: '<S1>/Unit Delay5' */
    rtDW.UnitDelay5_DSTATE = rtDW.Gain1;

    /* Update for UnitDelay: '<S1>/Unit Delay4' */
    rtDW.UnitDelay4_DSTATE = rtDW.Gain2;
  }

  /* End of Update for UnitDelay: '<S1>/Unit Delay1' */

  /* Update for UnitDelay: '<S1>/Unit Delay3' incorporates:
   *  Inport: '<Root>/TotalPackVoltage'
   */
  rtDW.UnitDelay3_DSTATE = rtU.TotalPackVoltage;

  /* End of Outputs for SubSystem: '<Root>/BatteryManagementSystem' */
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Outport: '<Root>/VfbStateOfCharge' */
    rtY.VfbStateOfCharge[0] = rtb_ImpAsg_InsertedFor_VfbState[0];
    rtY.VfbStateOfCharge[1] = rtb_ImpAsg_InsertedFor_VfbState[1];
    rtY.VfbStateOfCharge[2] = rtb_ImpAsg_InsertedFor_VfbState[2];
  }

  if (rtM->Timing.TaskCounters.TID[3] == 0) {
    /* Outport: '<Root>/VfbBalanceCommand' */
    rtY.VfbBalanceCommand[0] = (real_T)rtb_DataTypeConversion1_idx_0;
    rtY.VfbBalanceCommand[1] = (real_T)rtb_DataTypeConversion1_idx_1;
    rtY.VfbBalanceCommand[2] = (real_T)rtb_DataTypeConversion1_idx_2;

    /* Outport: '<Root>/VfbBalancingActive' */
    rtY.VfbBalancingActive = rtb_BalancingActive;
  }

  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick2++;
  }

  rate_scheduler();
}

/* Model initialize function */
void BatteryManagementSystem_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
