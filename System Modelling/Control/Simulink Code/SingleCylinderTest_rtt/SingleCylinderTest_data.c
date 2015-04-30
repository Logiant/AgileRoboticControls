/*
 * File: SingleCylinderTest_data.c
 *
 * Code generated for Simulink model 'SingleCylinderTest'.
 *
 * Model version                  : 1.121
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed Apr 29 18:56:04 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SingleCylinderTest.h"
#include "SingleCylinderTest_private.h"

/* Block parameters (auto storage) */
P_SingleCylinderTest_T SingleCylinderTest_P = {
  5U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S3>/PWM'
                                        */
  7U,                                  /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S4>/PWM'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S8>/Constant'
                                        */
  0.2,                                 /* Expression: 1/5
                                        * Referenced by: '<Root>/P'
                                        */
  3000.0,                              /* Expression: 3000
                                        * Referenced by: '<S1>/P'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant3'
                                        */
  2U,                                  /* Computed Parameter: FeedbackVoltage_p1
                                        * Referenced by: '<S1>/Feedback Voltage'
                                        */
  32800U                               /* Computed Parameter: NormalizeFeedback_Gain
                                        * Referenced by: '<S1>/Normalize Feedback'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
