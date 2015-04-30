/*
 * File: FrequencyResponseTest.c
 *
 * Code generated for Simulink model 'FrequencyResponseTest'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed Apr 29 20:13:30 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FrequencyResponseTest.h"
#include "FrequencyResponseTest_private.h"

/* Block signals (auto storage) */
B_FrequencyResponseTest_T FrequencyResponseTest_B;

/* Real-time model */
RT_MODEL_FrequencyResponseTes_T FrequencyResponseTest_M_;
RT_MODEL_FrequencyResponseTes_T *const FrequencyResponseTest_M =
  &FrequencyResponseTest_M_;

/* Model output function */
void FrequencyResponseTest_output(void)
{
  real_T rtb_ReferenceGain;
  real_T rtb_IfPositive;
  real_T rtb_Switch;
  real_T tmp;

  /* Sin: '<Root>/Reference Voltage (Percentage)' */
  rtb_ReferenceGain = sin
    (FrequencyResponseTest_P.ReferenceVoltagePercentage_Freq *
     FrequencyResponseTest_M->Timing.t[0] +
     FrequencyResponseTest_P.ReferenceVoltagePercentage_Phas) *
    FrequencyResponseTest_P.ReferenceVoltagePercentage_Amp +
    FrequencyResponseTest_P.ReferenceVoltagePercentage_Bias;

  /* Gain: '<Root>/Scale Value' */
  rtb_IfPositive = FrequencyResponseTest_P.ScaleValue_Gain * rtb_ReferenceGain;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  if (rtb_IfPositive >= FrequencyResponseTest_P.Switch_Threshold) {
    rtb_Switch = FrequencyResponseTest_P.Constant1_Value;
  } else {
    rtb_Switch = FrequencyResponseTest_P.Constant2_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Product: '<S4>/0 if Negative'
   */
  tmp = rtb_IfPositive * rtb_Switch;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      FrequencyResponseTest_B.DataTypeConversion = (uint8_T)tmp;
    } else {
      FrequencyResponseTest_B.DataTypeConversion = 0U;
    }
  } else {
    FrequencyResponseTest_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_analogWrite(FrequencyResponseTest_P.PWM_pinNumber,
                 FrequencyResponseTest_B.DataTypeConversion);

  /* Gain: '<Root>/Reference Gain' */
  rtb_ReferenceGain *= FrequencyResponseTest_P.ReferenceGain_Gain;

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (rtb_ReferenceGain < 256.0) {
    if (rtb_ReferenceGain >= 0.0) {
      FrequencyResponseTest_B.DataTypeConversion_k = (uint8_T)rtb_ReferenceGain;
    } else {
      FrequencyResponseTest_B.DataTypeConversion_k = 0U;
    }
  } else {
    FrequencyResponseTest_B.DataTypeConversion_k = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_analogWrite(FrequencyResponseTest_P.PWM_pinNumber_b,
                 FrequencyResponseTest_B.DataTypeConversion_k);

  /* Product: '<S4>/0 If Positive' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Sum: '<S4>/Sum'
   */
  rtb_IfPositive *= rtb_Switch - FrequencyResponseTest_P.Constant3_Value;

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  MinMax: '<Root>/Retract Saturation'
   */
  if (rtb_IfPositive < 256.0) {
    if (rtb_IfPositive >= 0.0) {
      FrequencyResponseTest_B.DataTypeConversion_l = (uint8_T)rtb_IfPositive;
    } else {
      FrequencyResponseTest_B.DataTypeConversion_l = 0U;
    }
  } else {
    FrequencyResponseTest_B.DataTypeConversion_l = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S3>/PWM' */
  MW_analogWrite(FrequencyResponseTest_P.PWM_pinNumber_j,
                 FrequencyResponseTest_B.DataTypeConversion_l);
}

/* Model update function */
void FrequencyResponseTest_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  FrequencyResponseTest_M->Timing.t[0] =
    (++FrequencyResponseTest_M->Timing.clockTick0) *
    FrequencyResponseTest_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    FrequencyResponseTest_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void FrequencyResponseTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)FrequencyResponseTest_M, 0,
                sizeof(RT_MODEL_FrequencyResponseTes_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&FrequencyResponseTest_M->solverInfo,
                          &FrequencyResponseTest_M->Timing.simTimeStep);
    rtsiSetTPtr(&FrequencyResponseTest_M->solverInfo, &rtmGetTPtr
                (FrequencyResponseTest_M));
    rtsiSetStepSizePtr(&FrequencyResponseTest_M->solverInfo,
                       &FrequencyResponseTest_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&FrequencyResponseTest_M->solverInfo, ((const char_T **)
                           (&rtmGetErrorStatus(FrequencyResponseTest_M))));
    rtsiSetRTModelPtr(&FrequencyResponseTest_M->solverInfo,
                      FrequencyResponseTest_M);
  }

  rtsiSetSimTimeStep(&FrequencyResponseTest_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&FrequencyResponseTest_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(FrequencyResponseTest_M, &FrequencyResponseTest_M->Timing.tArray[0]);
  FrequencyResponseTest_M->Timing.stepSize0 = 0.2;

  /* block I/O */
  (void) memset(((void *) &FrequencyResponseTest_B), 0,
                sizeof(B_FrequencyResponseTest_T));

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_pinModeOutput(FrequencyResponseTest_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(FrequencyResponseTest_P.PWM_pinNumber_b);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S3>/PWM' */
  MW_pinModeOutput(FrequencyResponseTest_P.PWM_pinNumber_j);
}

/* Model terminate function */
void FrequencyResponseTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
