/*
 * File: XbeeSerial_data.c
 *
 * Code generated for Simulink model 'XbeeSerial'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed May 06 22:44:51 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "XbeeSerial.h"
#include "XbeeSerial_private.h"

/* Block parameters (auto storage) */
P_XbeeSerial_T XbeeSerial_P = {
  0.0,                                 /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  1.0,                                 /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S1>/Step'
                                        */
  0.0,                                 /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S1>/Step'
                                        */
  1U,                                  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  255U                                 /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
