/*
 * File: RetractExpandCommand.c
 *
 * Code generated for Simulink model 'RetractExpandCommand'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed Apr 29 19:53:38 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RetractExpandCommand.h"
#include "RetractExpandCommand_private.h"

/* Real-time model */
RT_MODEL_RetractExpandCommand_T RetractExpandCommand_M_;
RT_MODEL_RetractExpandCommand_T *const RetractExpandCommand_M =
  &RetractExpandCommand_M_;

/* Model output function */
void RetractExpandCommand_output(void)
{
  uint8_T tmp;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (RetractExpandCommand_P.Constant1_Value < 256.0) {
    if (RetractExpandCommand_P.Constant1_Value >= 0.0) {
      tmp = (uint8_T)RetractExpandCommand_P.Constant1_Value;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_analogWrite(RetractExpandCommand_P.PWM_pinNumber, tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if (RetractExpandCommand_P.Constant2_Value < 256.0) {
    if (RetractExpandCommand_P.Constant2_Value >= 0.0) {
      tmp = (uint8_T)RetractExpandCommand_P.Constant2_Value;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_analogWrite(RetractExpandCommand_P.PWM_pinNumber_m, tmp);
}

/* Model update function */
void RetractExpandCommand_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void RetractExpandCommand_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(RetractExpandCommand_M, (NULL));

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_pinModeOutput(RetractExpandCommand_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(RetractExpandCommand_P.PWM_pinNumber_m);
}

/* Model terminate function */
void RetractExpandCommand_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
