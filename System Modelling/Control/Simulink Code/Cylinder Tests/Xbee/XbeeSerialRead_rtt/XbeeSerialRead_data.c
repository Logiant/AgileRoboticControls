/*
 * File: XbeeSerialRead_data.c
 *
 * Code generated for Simulink model 'XbeeSerialRead'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 15 02:40:34 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "XbeeSerialRead.h"
#include "XbeeSerialRead_private.h"

/* Block parameters (auto storage) */
P_XbeeSerialRead_T XbeeSerialRead_P = {
  5U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S1>/PWM'
                                        */
  1U,                                  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S2>/Serial Transmit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  173.0,                               /* Expression: 173
                                        * Referenced by: '<S2>/Header'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Footer 1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Footer 2'
                                        */
  1U,                                  /* Computed Parameter: SerialReceive_p1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  0,                                   /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<Root>/Switch'
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
