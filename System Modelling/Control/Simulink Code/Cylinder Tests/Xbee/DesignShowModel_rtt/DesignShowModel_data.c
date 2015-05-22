/*
 * File: DesignShowModel_data.c
 *
 * Code generated for Simulink model 'DesignShowModel'.
 *
 * Model version                  : 1.128
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 22 12:35:13 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DesignShowModel.h"
#include "DesignShowModel_private.h"

/* Block parameters (auto storage) */
P_DesignShowModel_T DesignShowModel_P = {
  9U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S12>/PWM'
                                        */
  11U,                                 /* Mask Parameter: PWM_pinNumber_n
                                        * Referenced by: '<S13>/PWM'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber_p
                                        * Referenced by: '<S15>/PWM'
                                        */
  7U,                                  /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S16>/PWM'
                                        */
  1U,                                  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S2>/Serial Transmit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/No Request'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Constant1'
                                        */
  173.0,                               /* Expression: 173
                                        * Referenced by: '<S2>/Header'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S7>/Constant'
                                        */
  0.2,                                 /* Expression: 1/5
                                        * Referenced by: '<Root>/Normalize'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Shank Offset'
                                        */
  3000.0,                              /* Expression: 3000
                                        * Referenced by: '<S4>/P'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Constant3'
                                        */
  3000.0,                              /* Expression: 3000
                                        * Referenced by: '<S3>/P'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Footer 1'
                                        */
  16.0,                                /* Expression: 16
                                        * Referenced by: '<S2>/Footer 2'
                                        */
  2U,                                  /* Computed Parameter: FeedbackVoltage_p1
                                        * Referenced by: '<S4>/Feedback Voltage'
                                        */
  1U,                                  /* Computed Parameter: SerialReceive_p1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  4U,                                  /* Computed Parameter: FeedbackVoltage_p1_e
                                        * Referenced by: '<S3>/Feedback Voltage'
                                        */
  2149582850U,                         /* Computed Parameter: NormalizeFeedback_Gain
                                        * Referenced by: '<S4>/Normalize Feedback'
                                        */
  0,                                   /* Computed Parameter: Switch_Threshold_g3
                                        * Referenced by: '<Root>/Switch'
                                        */
  34133U,                              /* Computed Parameter: LengthCompensation_Gain
                                        * Referenced by: '<S4>/Length Compensation'
                                        */
  34133U,                              /* Computed Parameter: NormalizeFeedback_Gain_g
                                        * Referenced by: '<S3>/Normalize Feedback'
                                        */
  1                                    /* Computed Parameter: SerialReceive_p2
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
