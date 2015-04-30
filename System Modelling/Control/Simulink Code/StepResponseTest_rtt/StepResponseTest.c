/*
 * File: StepResponseTest.c
 *
 * Code generated for Simulink model 'StepResponseTest'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed Apr 29 19:20:04 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "StepResponseTest.h"
#include "StepResponseTest_private.h"

/* Block signals (auto storage) */
B_StepResponseTest_T StepResponseTest_B;

/* Block states (auto storage) */
DW_StepResponseTest_T StepResponseTest_DW;

/* Real-time model */
RT_MODEL_StepResponseTest_T StepResponseTest_M_;
RT_MODEL_StepResponseTest_T *const StepResponseTest_M = &StepResponseTest_M_;

/* Model output function */
void StepResponseTest_output(void)
{
  uint16_T rtb_FeedbackInput_0;
  real_T rtb_IntegralGain;
  real_T rtb_DeadZone;
  real_T rtb_IfPositive;
  real_T rtb_Switch;
  uint8_T rtb_IfPositive_0;
  real_T rtb_IntegralGain_0;

  /* S-Function (arduinoanaloginput_sfcn): '<Root>/Feedback Input' */
  rtb_FeedbackInput_0 = MW_analogRead(StepResponseTest_P.FeedbackInput_p1);

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Reference Voltage (Percent)'
   *  Gain: '<Root>/Scale To (0, 1)'
   *  S-Function (arduinoanaloginput_sfcn): '<Root>/Feedback Input'
   */
  rtb_IntegralGain = StepResponseTest_P.ReferenceVoltagePercent_Value - (real_T)
    ((uint32_T)StepResponseTest_P.ScaleTo01_Gain * rtb_FeedbackInput_0) *
    2.9802322387695313E-8;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S1>/Filter'
   *  Gain: '<S1>/Derivative Gain'
   *  Sum: '<S1>/SumD'
   */
  StepResponseTest_B.FilterCoefficient =
    (StepResponseTest_P.DiscretePIDController_D * rtb_IntegralGain -
     StepResponseTest_DW.Filter_DSTATE) *
    StepResponseTest_P.DiscretePIDController_N;

  /* Sum: '<S1>/Sum' incorporates:
   *  DiscreteIntegrator: '<S1>/Integrator'
   *  Gain: '<S1>/Proportional Gain'
   */
  rtb_DeadZone = (StepResponseTest_P.DiscretePIDController_P * rtb_IntegralGain
                  + StepResponseTest_DW.Integrator_DSTATE) +
    StepResponseTest_B.FilterCoefficient;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_DeadZone > StepResponseTest_P.DiscretePIDController_UpperSatu) {
    rtb_IfPositive = StepResponseTest_P.DiscretePIDController_UpperSatu;
  } else if (rtb_DeadZone < StepResponseTest_P.DiscretePIDController_LowerSatu)
  {
    rtb_IfPositive = StepResponseTest_P.DiscretePIDController_LowerSatu;
  } else {
    rtb_IfPositive = rtb_DeadZone;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   */
  if (rtb_IfPositive >= StepResponseTest_P.Switch_Threshold) {
    rtb_Switch = StepResponseTest_P.Constant1_Value;
  } else {
    rtb_Switch = StepResponseTest_P.Constant2_Value;
  }

  /* End of Switch: '<S5>/Switch' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Product: '<S5>/0 if Negative'
   */
  rtb_IntegralGain_0 = rtb_IfPositive * rtb_Switch;
  if (rtb_IntegralGain_0 < 256.0) {
    if (rtb_IntegralGain_0 >= 0.0) {
      rtb_IfPositive_0 = (uint8_T)rtb_IntegralGain_0;
    } else {
      rtb_IfPositive_0 = 0U;
    }
  } else {
    rtb_IfPositive_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_analogWrite(StepResponseTest_P.PWM_pinNumber, rtb_IfPositive_0);

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Reference Voltage (Percent)'
   *  Gain: '<Root>/Reference Gain'
   */
  rtb_IntegralGain_0 = StepResponseTest_P.ReferenceGain_Gain *
    StepResponseTest_P.ReferenceVoltagePercent_Value;
  if (rtb_IntegralGain_0 < 256.0) {
    if (rtb_IntegralGain_0 >= 0.0) {
      rtb_IfPositive_0 = (uint8_T)rtb_IntegralGain_0;
    } else {
      rtb_IfPositive_0 = 0U;
    }
  } else {
    rtb_IfPositive_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S3>/PWM' */
  MW_analogWrite(StepResponseTest_P.PWM_pinNumber_b, rtb_IfPositive_0);

  /* Product: '<S5>/0 If Positive' incorporates:
   *  Constant: '<S5>/Constant3'
   *  Sum: '<S5>/Sum'
   */
  rtb_IfPositive *= rtb_Switch - StepResponseTest_P.Constant3_Value;

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  MinMax: '<Root>/Retract Saturation'
   */
  if (rtb_IfPositive < 256.0) {
    if (rtb_IfPositive >= 0.0) {
      rtb_IfPositive_0 = (uint8_T)rtb_IfPositive;
    } else {
      rtb_IfPositive_0 = 0U;
    }
  } else {
    rtb_IfPositive_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_analogWrite(StepResponseTest_P.PWM_pinNumber_j, rtb_IfPositive_0);

  /* Gain: '<S6>/Gain' */
  rtb_IfPositive = StepResponseTest_P.Gain_Gain * rtb_DeadZone;

  /* DeadZone: '<S6>/DeadZone' */
  if (rtb_DeadZone > StepResponseTest_P.DiscretePIDController_UpperSatu) {
    rtb_DeadZone -= StepResponseTest_P.DiscretePIDController_UpperSatu;
  } else if (rtb_DeadZone >= StepResponseTest_P.DiscretePIDController_LowerSatu)
  {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= StepResponseTest_P.DiscretePIDController_LowerSatu;
  }

  /* End of DeadZone: '<S6>/DeadZone' */

  /* Gain: '<S1>/Integral Gain' */
  rtb_IntegralGain *= StepResponseTest_P.DiscretePIDController_I;

  /* Signum: '<S6>/SignPreSat' */
  if (rtb_DeadZone < 0.0) {
    rtb_Switch = -1.0;
  } else if (rtb_DeadZone > 0.0) {
    rtb_Switch = 1.0;
  } else if (rtb_DeadZone == 0.0) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = rtb_DeadZone;
  }

  /* Signum: '<S6>/SignPreIntegrator' */
  if (rtb_IntegralGain < 0.0) {
    rtb_IntegralGain_0 = -1.0;
  } else if (rtb_IntegralGain > 0.0) {
    rtb_IntegralGain_0 = 1.0;
  } else if (rtb_IntegralGain == 0.0) {
    rtb_IntegralGain_0 = 0.0;
  } else {
    rtb_IntegralGain_0 = rtb_IntegralGain;
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Logic: '<S6>/AND'
   *  RelationalOperator: '<S6>/Equal'
   *  RelationalOperator: '<S6>/NotEqual'
   *  Signum: '<S6>/SignPreIntegrator'
   *  Signum: '<S6>/SignPreSat'
   */
  if ((rtb_IfPositive != rtb_DeadZone) && (rtb_Switch == rtb_IntegralGain_0)) {
    StepResponseTest_B.Switch = StepResponseTest_P.Constant_Value;
  } else {
    StepResponseTest_B.Switch = rtb_IntegralGain;
  }

  /* End of Switch: '<S1>/Switch' */
}

/* Model update function */
void StepResponseTest_update(void)
{
  /* Update for DiscreteIntegrator: '<S1>/Integrator' */
  StepResponseTest_DW.Integrator_DSTATE += StepResponseTest_P.Integrator_gainval
    * StepResponseTest_B.Switch;

  /* Update for DiscreteIntegrator: '<S1>/Filter' */
  StepResponseTest_DW.Filter_DSTATE += StepResponseTest_P.Filter_gainval *
    StepResponseTest_B.FilterCoefficient;
}

/* Model initialize function */
void StepResponseTest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  StepResponseTest_P.DiscretePIDController_LowerSatu = rtMinusInf;
  StepResponseTest_P.DiscretePIDController_UpperSatu = rtInf;

  /* initialize error status */
  rtmSetErrorStatus(StepResponseTest_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &StepResponseTest_B), 0,
                sizeof(B_StepResponseTest_T));

  /* states (dwork) */
  (void) memset((void *)&StepResponseTest_DW, 0,
                sizeof(DW_StepResponseTest_T));

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Feedback Input' */
  MW_pinModeAnalogInput(StepResponseTest_P.FeedbackInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(StepResponseTest_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S3>/PWM' */
  MW_pinModeOutput(StepResponseTest_P.PWM_pinNumber_b);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_pinModeOutput(StepResponseTest_P.PWM_pinNumber_j);

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Integrator' */
  StepResponseTest_DW.Integrator_DSTATE = StepResponseTest_P.Integrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Filter' */
  StepResponseTest_DW.Filter_DSTATE = StepResponseTest_P.Filter_IC;
}

/* Model terminate function */
void StepResponseTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
