/*
 * File: DualCylinderTest_data.c
 *
 * Code generated for Simulink model 'DualCylinderTest'.
 *
 * Model version                  : 1.126
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Thu Apr 30 18:42:35 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DualCylinderTest.h"
#include "DualCylinderTest_private.h"

/* Block parameters (auto storage) */
P_DualCylinderTest_T DualCylinderTest_P = {
  9U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S11>/PWM'
                                        */
  11U,                                 /* Mask Parameter: PWM_pinNumber_n
                                        * Referenced by: '<S12>/PWM'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber_p
                                        * Referenced by: '<S14>/PWM'
                                        */
  7U,                                  /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S15>/PWM'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
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
                                        * Referenced by: '<S4>/Unit Delay1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S6>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay1'
                                        */
  0.2,                                 /* Expression: 1/5
                                        * Referenced by: '<Root>/P'
                                        */
  3000.0,                              /* Expression: 3000
                                        * Referenced by: '<S2>/P'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Constant3'
                                        */
  3000.0,                              /* Expression: 3000
                                        * Referenced by: '<S3>/P'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Constant3'
                                        */
  4U,                                  /* Computed Parameter: FeedbackVoltage_p1
                                        * Referenced by: '<S2>/Feedback Voltage'
                                        */
  2U,                                  /* Computed Parameter: FeedbackVoltage_p1_n
                                        * Referenced by: '<S3>/Feedback Voltage'
                                        */
  2149582850U,                         /* Computed Parameter: NormalizeFeedback_Gain
                                        * Referenced by: '<S3>/Normalize Feedback'
                                        */
  32800U,                              /* Computed Parameter: NormalizeFeedback_Gain_g
                                        * Referenced by: '<S2>/Normalize Feedback'
                                        */
  49152U                               /* Computed Parameter: LengthCompensation_Gain
                                        * Referenced by: '<S3>/Length Compensation'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
