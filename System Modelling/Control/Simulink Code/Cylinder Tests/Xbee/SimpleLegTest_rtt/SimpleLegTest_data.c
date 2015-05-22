/*
 * File: SimpleLegTest_data.c
 *
 * Code generated for Simulink model 'SimpleLegTest'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 22 13:26:11 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SimpleLegTest.h"
#include "SimpleLegTest_private.h"

/* Block parameters (auto storage) */
P_SimpleLegTest_T SimpleLegTest_P = {
  2U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S1>/PWM'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber_p
                                        * Referenced by: '<S2>/PWM'
                                        */
  4U,                                  /* Mask Parameter: PWM_pinNumber_l
                                        * Referenced by: '<S3>/PWM'
                                        */
  1U,                                  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S4>/Serial Transmit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Constant2'
                                        */
  128.0,                               /* Expression: 128
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant3'
                                        */
  173.0,                               /* Expression: 173
                                        * Referenced by: '<S4>/Header'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Footer 1'
                                        */
  16.0,                                /* Expression: 16
                                        * Referenced by: '<S4>/Footer 2'
                                        */
  1U,                                  /* Computed Parameter: SerialReceive_p1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  0,                                   /* Computed Parameter: Switch_Threshold_i
                                        * Referenced by: '<Root>/Switch'
                                        */
  0U,                                  /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<Root>/Unit Delay'
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
