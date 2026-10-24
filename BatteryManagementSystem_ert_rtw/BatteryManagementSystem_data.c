/*
 * File: BatteryManagementSystem_data.c
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

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Computed Parameter: uDLookupTable3_tableData
   * Referenced by: '<S7>/1-D Lookup Table3'
   */
  { 0.0F, 0.01F, 0.02F, 0.03F, 0.04F, 0.05F, 0.06F, 0.07F, 0.08F, 0.09F, 0.1F,
    0.11F, 0.12F, 0.13F, 0.14F, 0.15F, 0.16F, 0.17F, 0.18F, 0.19F, 0.2F, 0.21F,
    0.22F, 0.23F, 0.24F, 0.25F, 0.26F, 0.27F, 0.28F, 0.29F, 0.3F, 0.31F, 0.32F,
    0.33F, 0.34F, 0.35F, 0.36F, 0.37F, 0.38F, 0.39F, 0.4F, 0.41F, 0.42F, 0.43F,
    0.44F, 0.45F, 0.46F, 0.47F, 0.48F, 0.49F, 0.5F, 0.51F, 0.52F, 0.53F, 0.54F,
    0.55F, 0.56F, 0.57F, 0.58F, 0.59F, 0.6F, 0.61F, 0.62F, 0.63F, 0.64F, 0.65F,
    0.66F, 0.67F, 0.68F, 0.69F, 0.7F, 0.71F, 0.72F, 0.73F, 0.74F, 0.75F, 0.76F,
    0.77F, 0.78F, 0.79F, 0.8F, 0.81F, 0.82F, 0.83F, 0.84F, 0.85F, 0.86F, 0.87F,
    0.88F, 0.89F, 0.9F, 0.91F, 0.92F, 0.93F, 0.94F, 0.95F, 0.96F, 0.97F, 0.98F,
    0.99F, 1.0F },

  /* Computed Parameter: uDLookupTable3_bp01Data
   * Referenced by: '<S7>/1-D Lookup Table3'
   */
  { 3.04339F, 3.19969F, 3.32733F, 3.41897F, 3.47789F, 3.5189F, 3.54757F,
    3.56926F, 3.58543F, 3.59715F, 3.60656F, 3.61458F, 3.62125F, 3.62859F,
    3.63585F, 3.64117F, 3.64677F, 3.65281F, 3.65754F, 3.6622F, 3.66686F,
    3.67118F, 3.67547F, 3.67953F, 3.68333F, 3.68679F, 3.68929F, 3.69163F,
    3.69398F, 3.69633F, 3.69868F, 3.70108F, 3.7035F, 3.70592F, 3.70834F,
    3.71076F, 3.71334F, 3.71599F, 3.71889F, 3.72198F, 3.72508F, 3.72817F,
    3.73126F, 3.73436F, 3.73745F, 3.74054F, 3.74364F, 3.74686F, 3.75011F,
    3.75346F, 3.75768F, 3.7621F, 3.76652F, 3.77094F, 3.77575F, 3.78058F,
    3.78546F, 3.79147F, 3.79777F, 3.80409F, 3.8104F, 3.81672F, 3.82303F,
    3.82935F, 3.83618F, 3.84344F, 3.8508F, 3.85816F, 3.86553F, 3.87289F,
    3.88052F, 3.88833F, 3.89603F, 3.90423F, 3.91256F, 3.92124F, 3.93029F,
    3.93933F, 3.94837F, 3.95788F, 3.96788F, 3.97854F, 3.98931F, 4.00008F,
    4.01149F, 4.02304F, 4.03459F, 4.04614F, 4.05768F, 4.06947F, 4.08184F,
    4.09422F, 4.1067F, 4.11982F, 4.1326F, 4.14615F, 4.15754F, 4.16699F, 4.17222F,
    4.18119F, 4.30838F },

  /* Expression: single([0 0.1 0.3 0.6 0.9 1])
   * Referenced by: '<S4>/MinCellVoltage_DischrageCurrent'
   */
  { 0.0F, 0.1F, 0.3F, 0.6F, 0.9F, 1.0F },

  /* Expression: single([2.7 2.8 3.0 3.2 3.4 3.6])
   * Referenced by: '<S4>/MinCellVoltage_DischrageCurrent'
   */
  { 2.7F, 2.8F, 3.0F, 3.2F, 3.4F, 3.6F },

  /* Expression: single([0 0 0.2 0.6 0.9 1])
   * Referenced by: '<S4>/LowTemp_DischargeCurrent'
   */
  { 0.0F, 0.0F, 0.2F, 0.6F, 0.9F, 1.0F },

  /* Expression: single([243.15 258.15 273.15 283.15 293.15 298.15])
   * Referenced by: '<S4>/LowTemp_DischargeCurrent'
   */
  { 243.15F, 258.15F, 273.15F, 283.15F, 293.15F, 298.15F },

  /* Expression: single([1 1 0.9 0.7 0.4 0])
   * Referenced by: '<S4>/HighTemp_DischargeCurrent'
   */
  { 1.0F, 1.0F, 0.9F, 0.7F, 0.4F, 0.0F },

  /* Pooled Parameter (Expression: single([298.15 308.15 313.15 318.15 323.15 333.15]))
   * Referenced by:
   *   '<S4>/HighTemp_ChrageCurrent'
   *   '<S4>/HighTemp_DischargeCurrent'
   */
  { 298.15F, 308.15F, 313.15F, 318.15F, 323.15F, 333.15F },

  /* Expression: single([1 1 0.8 0.5 0.2 0])
   * Referenced by: '<S4>/HighTemp_ChrageCurrent'
   */
  { 1.0F, 1.0F, 0.8F, 0.5F, 0.2F, 0.0F },

  /* Expression: single([1 1 1 0.9 0.7 0.4 0.2 0])
   * Referenced by: '<S4>/MaxCellVoltage_ChrageCurrent'
   */
  { 1.0F, 1.0F, 1.0F, 0.9F, 0.7F, 0.4F, 0.2F, 0.0F },

  /* Expression: single([3.0 3.5 3.8 4.0 4.1 4.2 4.25 4.35])
   * Referenced by: '<S4>/MaxCellVoltage_ChrageCurrent'
   */
  { 3.0F, 3.5F, 3.8F, 4.0F, 4.1F, 4.2F, 4.25F, 4.35F },

  /* Expression: single([0 0 0 0.1 0.3 0.6 1])
   * Referenced by: '<S4>/LowTemp_ChrageCurrent'
   */
  { 0.0F, 0.0F, 0.0F, 0.1F, 0.3F, 0.6F, 1.0F },

  /* Expression: single([243.15 263.15 273.15 278.15 283.15 288.15 298.15])
   * Referenced by: '<S4>/LowTemp_ChrageCurrent'
   */
  { 243.15F, 263.15F, 273.15F, 278.15F, 283.15F, 288.15F, 298.15F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
