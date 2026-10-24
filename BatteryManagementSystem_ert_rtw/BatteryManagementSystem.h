/*
 * File: BatteryManagementSystem.h
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

#ifndef BatteryManagementSystem_h_
#define BatteryManagementSystem_h_
#ifndef BatteryManagementSystem_COMMON_INCLUDES_
#define BatteryManagementSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                            /* BatteryManagementSystem_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_SRE_
#define DEFINED_TYPEDEF_FOR_SRE_

typedef enum {
  SRE_Charging = 0,                    /* Default value */
  SRE_Discharging,
  SRE_Standby
} SRE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BMS_State_Enum_
#define DEFINED_TYPEDEF_FOR_BMS_State_Enum_

typedef enum {
  Standby = 0,                         /* Default value */
  Charging,
  Discharging
} BMS_State_Enum;

#endif

/* Block signals and states (default storage) for system '<S2>/StateOfChargeEstimation (Coulomb Counting)' */
typedef struct {
  real32_T uDLookupTable3;             /* '<S7>/1-D Lookup Table3' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S6>/Discrete-Time Integrator' */
} DW_CoreSubsys;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_CoreSubsys CoreSubsys[3];
                         /* '<S2>/StateOfChargeEstimation (Coulomb Counting)' */
  real32_T UnitDelay1;                 /* '<S1>/Unit Delay1' */
  real32_T UnitDelay2;                 /* '<S1>/Unit Delay2' */
  real32_T UnitDelay5;                 /* '<S1>/Unit Delay5' */
  real32_T UnitDelay4;                 /* '<S1>/Unit Delay4' */
  real32_T MinMax;                     /* '<S4>/MinMax' */
  real32_T Gain2;                      /* '<S4>/Gain2' */
  real32_T MinMax2;                    /* '<S4>/MinMax2' */
  real32_T Gain1;                      /* '<S4>/Gain1' */
  real32_T UnitDelay_DSTATE;           /* '<S1>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S1>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S1>/Unit Delay2' */
  real32_T UnitDelay5_DSTATE;          /* '<S1>/Unit Delay5' */
  real32_T UnitDelay4_DSTATE;          /* '<S1>/Unit Delay4' */
  real32_T UnitDelay3_DSTATE;          /* '<S1>/Unit Delay3' */
  uint8_T is_active_c1_BatteryManagementS;/* '<S1>/MainStateMachine1' */
  uint8_T is_c1_BatteryManagementSystem;/* '<S1>/MainStateMachine1' */
  uint8_T is_Charging;                 /* '<S1>/MainStateMachine1' */
  boolean_T UnitDelay6_DSTATE[3];      /* '<S1>/Unit Delay6' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: uDLookupTable3_tableData
   * Referenced by: '<S7>/1-D Lookup Table3'
   */
  real32_T uDLookupTable3_tableData[101];

  /* Computed Parameter: uDLookupTable3_bp01Data
   * Referenced by: '<S7>/1-D Lookup Table3'
   */
  real32_T uDLookupTable3_bp01Data[101];

  /* Expression: single([0 0.1 0.3 0.6 0.9 1])
   * Referenced by: '<S4>/MinCellVoltage_DischrageCurrent'
   */
  real32_T MinCellVoltage_DischrageCurrent[6];

  /* Expression: single([2.7 2.8 3.0 3.2 3.4 3.6])
   * Referenced by: '<S4>/MinCellVoltage_DischrageCurrent'
   */
  real32_T MinCellVoltage_DischrageCurre_p[6];

  /* Expression: single([0 0 0.2 0.6 0.9 1])
   * Referenced by: '<S4>/LowTemp_DischargeCurrent'
   */
  real32_T LowTemp_DischargeCurrent_tableD[6];

  /* Expression: single([243.15 258.15 273.15 283.15 293.15 298.15])
   * Referenced by: '<S4>/LowTemp_DischargeCurrent'
   */
  real32_T LowTemp_DischargeCurrent_bp01Da[6];

  /* Expression: single([1 1 0.9 0.7 0.4 0])
   * Referenced by: '<S4>/HighTemp_DischargeCurrent'
   */
  real32_T HighTemp_DischargeCurrent_table[6];

  /* Pooled Parameter (Expression: single([298.15 308.15 313.15 318.15 323.15 333.15]))
   * Referenced by:
   *   '<S4>/HighTemp_ChrageCurrent'
   *   '<S4>/HighTemp_DischargeCurrent'
   */
  real32_T pooled3[6];

  /* Expression: single([1 1 0.8 0.5 0.2 0])
   * Referenced by: '<S4>/HighTemp_ChrageCurrent'
   */
  real32_T HighTemp_ChrageCurrent_tableDat[6];

  /* Expression: single([1 1 1 0.9 0.7 0.4 0.2 0])
   * Referenced by: '<S4>/MaxCellVoltage_ChrageCurrent'
   */
  real32_T MaxCellVoltage_ChrageCurrent_ta[8];

  /* Expression: single([3.0 3.5 3.8 4.0 4.1 4.2 4.25 4.35])
   * Referenced by: '<S4>/MaxCellVoltage_ChrageCurrent'
   */
  real32_T MaxCellVoltage_ChrageCurrent_bp[8];

  /* Expression: single([0 0 0 0.1 0.3 0.6 1])
   * Referenced by: '<S4>/LowTemp_ChrageCurrent'
   */
  real32_T LowTemp_ChrageCurrent_tableData[7];

  /* Expression: single([243.15 263.15 273.15 278.15 283.15 288.15 298.15])
   * Referenced by: '<S4>/LowTemp_ChrageCurrent'
   */
  real32_T LowTemp_ChrageCurrent_bp01Data[7];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  SRE VfbStateRequest;                 /* '<Root>/VfbStateRequest' */
  real32_T ChargerOutputVoltage;       /* '<Root>/ChargerOutputVoltage' */
  real32_T InverterOutputVoltage;      /* '<Root>/InverterOutputVoltage' */
  real32_T TotalPackVoltage;           /* '<Root>/TotalPackVoltage' */
  real32_T VfbPackCurrent;             /* '<Root>/VfbPackCurrent ' */
  real32_T VfbCellVoltages[3];         /* '<Root>/VfbCellVoltages' */
  real32_T VfbCellTemperatures[3];     /* '<Root>/VfbCellTemperatures' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T VfbChargeCurrentCmd;        /* '<Root>/VfbChargeCurrentCmd' */
  boolean_T VfbChargerContactorCommand;/* '<Root>/VfbChargerContactorCommand' */
  boolean_T VfbInverterContactorCommand;
                                      /* '<Root>/VfbInverterContactorCommand' */
  real32_T VfbStateOfCharge[3];        /* '<Root>/VfbStateOfCharge' */
  BMS_State_Enum VfbBmsOperationalState;/* '<Root>/VfbBmsOperationalState' */
  real_T VfbBalanceCommand[3];         /* '<Root>/VfbBalanceCommand' */
  boolean_T VfbBalancingActive;        /* '<Root>/VfbBalancingActive' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick2;
    struct {
      uint8_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void BatteryManagementSystem_initialize(void);
extern void BatteryManagementSystem_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Display' : Unused code path elimination
 * Block '<S7>/Display' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('BatteryManagementSystem_V1/BatteryManagementSystem')    - opens subsystem BatteryManagementSystem_V1/BatteryManagementSystem
 * hilite_system('BatteryManagementSystem_V1/BatteryManagementSystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BatteryManagementSystem_V1'
 * '<S1>'   : 'BatteryManagementSystem_V1/BatteryManagementSystem'
 * '<S2>'   : 'BatteryManagementSystem_V1/BatteryManagementSystem/ StateOfChargeEstimation'
 * '<S3>'   : 'BatteryManagementSystem_V1/BatteryManagementSystem/BalancingLogic'
 * '<S4>'   : 'BatteryManagementSystem_V1/BatteryManagementSystem/CurrentLimitsCalculation '
 * '<S5>'   : 'BatteryManagementSystem_V1/BatteryManagementSystem/MainStateMachine1'
 * '<S6>'   : 'BatteryManagementSystem_V1/BatteryManagementSystem/ StateOfChargeEstimation/StateOfChargeEstimation (Coulomb Counting)'
 * '<S7>'   : 'BatteryManagementSystem_V1/BatteryManagementSystem/ StateOfChargeEstimation/StateOfChargeEstimation (Coulomb Counting)/Subsystem'
 */
#endif                                 /* BatteryManagementSystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
