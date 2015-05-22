/*
 * File: XbeeIO.c
 *
 * Code generated for Simulink model 'XbeeIO'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed May 06 22:02:41 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "XbeeIO.h"
#include "XbeeIO_private.h"

/* Real-time model */
RT_MODEL_XbeeIO_T XbeeIO_M_;
RT_MODEL_XbeeIO_T *const XbeeIO_M = &XbeeIO_M_;

/* Model output function */
void XbeeIO_output(void)
{
  /* S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_digitalWrite(XbeeIO_P.DigitalOutput_pinNumber, XbeeIO_P.Constant_Value);

  /* S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_digitalWrite(XbeeIO_P.DigitalOutput_pinNumber_j, XbeeIO_P.Constant_Value);
}

/* Model update function */
void XbeeIO_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void XbeeIO_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(XbeeIO_M, (NULL));

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_pinModeOutput(XbeeIO_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_pinModeOutput(XbeeIO_P.DigitalOutput_pinNumber_j);
}

/* Model terminate function */
void XbeeIO_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
