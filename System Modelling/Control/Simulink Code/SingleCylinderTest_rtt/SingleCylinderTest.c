/*
 * File: SingleCylinderTest.c
 *
 * Code generated for Simulink model 'SingleCylinderTest'.
 *
 * Model version                  : 1.126
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Thu Apr 30 18:37:11 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SingleCylinderTest.h"
#include "SingleCylinderTest_private.h"

/* Named constants for Chart: '<S5>/Chart' */
#define SingleCylind_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define SingleCylinderTest_IN_Forward  ((uint8_T)1U)
#define SingleCylinderTest_IN_Idle     ((uint8_T)2U)
#define SingleCylinderTest_IN_Reverse  ((uint8_T)3U)

/* Block signals (auto storage) */
B_SingleCylinderTest_T SingleCylinderTest_B;

/* Block states (auto storage) */
DW_SingleCylinderTest_T SingleCylinderTest_DW;

/* Real-time model */
RT_MODEL_SingleCylinderTest_T SingleCylinderTest_M_;
RT_MODEL_SingleCylinderTest_T *const SingleCylinderTest_M =
  &SingleCylinderTest_M_;
real_T uMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  int16_T i;
  int16_T exp_0;
  y = 0.0;
  exp_0 = e1;
  for (i = 0; i < n1; i++) {
    y += ldexp(u1[i], exp_0);
    exp_0 += 32;
  }

  return y;
}

void uMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = yk < cb ? 1UL : 0UL;
      u1i *= a0;
      yk += u1i;
      cb += yk < u1i ? 1UL : 0UL;
      u1i = w10 << 16U;
      yk += u1i;
      cb += yk < u1i ? 1UL : 0UL;
      u1i = w01 << 16U;
      yk += u1i;
      cb += yk < u1i ? 1UL : 0UL;
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

/* Model output function */
void SingleCylinderTest_output(void)
{
  uint16_T rtb_FeedbackVoltage_0;
  static const int8_T b[6] = { 1, 2, 3, 4, 3, 2 };

  real_T rtb_Abs1;
  real_T rtb_Product;
  real_T rtb_Switch;
  real_T rtb_Abs1_p;
  uint64m_T tmp;
  uint32_T tmp_0;
  uint8_T rtb_Abs1_k;

  /* Step: '<Root>/Step' */
  if (((SingleCylinderTest_M->Timing.clockTick0) * 0.01) <
      SingleCylinderTest_P.Step_Time) {
    rtb_Product = SingleCylinderTest_P.Step_Y0;
  } else {
    rtb_Product = SingleCylinderTest_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Product: '<S4>/Product' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  Sum: '<S6>/Sum'
   *  UnitDelay: '<Root>/Unit Delay'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  rtb_Product *= (real_T)(fabs(SingleCylinderTest_DW.UnitDelay_DSTATE -
    SingleCylinderTest_DW.UnitDelay1_DSTATE) <
    SingleCylinderTest_P.Constant_Value_m);

  /* Chart: '<S5>/Chart' incorporates:
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  /* Gateway: High Level System Controller/System Model/State Machine/Chart */
  /* During: High Level System Controller/System Model/State Machine/Chart */
  if (SingleCylinderTest_DW.is_active_c3_SingleCylinderTest == 0U) {
    /* Entry: High Level System Controller/System Model/State Machine/Chart */
    SingleCylinderTest_DW.is_active_c3_SingleCylinderTest = 1U;

    /* Entry Internal: High Level System Controller/System Model/State Machine/Chart */
    /* Transition: '<S8>:23' */
    SingleCylinderTest_DW.is_c3_SingleCylinderTest = SingleCylinderTest_IN_Idle;

    /* Entry 'Idle': '<S8>:1' */
    SingleCylinderTest_B.index_out_n = SingleCylinderTest_DW.UnitDelay1_DSTATE_k;
  } else {
    switch (SingleCylinderTest_DW.is_c3_SingleCylinderTest) {
     case SingleCylinderTest_IN_Forward:
      /* During 'Forward': '<S8>:2' */
      if (rtb_Product != 1.0) {
        /* Transition: '<S8>:7' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Idle;

        /* Entry 'Idle': '<S8>:1' */
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE_k;
      } else {
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE_k + 1.0;
      }
      break;

     case SingleCylinderTest_IN_Idle:
      /* During 'Idle': '<S8>:1' */
      if (rtb_Product == 1.0) {
        /* Transition: '<S8>:4' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Forward;

        /* Entry 'Forward': '<S8>:2' */
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE_k + 1.0;
      } else {
        if (rtb_Product == -1.0) {
          /* Transition: '<S8>:5' */
          SingleCylinderTest_DW.is_c3_SingleCylinderTest =
            SingleCylinderTest_IN_Reverse;

          /* Entry 'Reverse': '<S8>:3' */
          SingleCylinderTest_B.index_out_n =
            SingleCylinderTest_DW.UnitDelay1_DSTATE_k - 1.0;
        }
      }
      break;

     default:
      /* During 'Reverse': '<S8>:3' */
      if (rtb_Product != -1.0) {
        /* Transition: '<S8>:6' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Idle;

        /* Entry 'Idle': '<S8>:1' */
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE_k;
      } else {
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE_k - 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* MATLAB Function: '<S5>/MATLAB Function' */
  /* MATLAB Function 'High Level System Controller/System Model/State Machine/MATLAB Function': '<S9>:1' */
  /* '<S9>:1:3' */
  SingleCylinderTest_B.index_out = SingleCylinderTest_B.index_out_n;
  if (SingleCylinderTest_B.index_out_n > 6.0) {
    /* '<S9>:1:4' */
    /* '<S9>:1:5' */
    SingleCylinderTest_B.index_out = 1.0;
  }

  if (SingleCylinderTest_B.index_out_n < 1.0) {
    /* '<S9>:1:7' */
    /* '<S9>:1:8' */
    SingleCylinderTest_B.index_out = 6.0;
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* MATLAB Function: '<S7>/MATLAB Function' */
  /* MATLAB Function 'High Level System Controller/System Model/State Machine/Calculate Foot Position/MATLAB Function': '<S10>:1' */
  /* '<S10>:1:3' */
  rtb_Product = SingleCylinderTest_B.index_out;
  if (SingleCylinderTest_B.index_out < 1.0) {
    /* '<S10>:1:4' */
    /* '<S10>:1:5' */
    rtb_Product = 1.0;
  } else {
    if (SingleCylinderTest_B.index_out > 6.0) {
      /* '<S10>:1:6' */
      /* '<S10>:1:7' */
      rtb_Product = 6.0;
    }
  }

  /* '<S10>:1:9' */
  /* divide by 5 to normalize */
  /* '<S10>:1:11' */
  SingleCylinderTest_B.x = b[(int16_T)rtb_Product - 1];

  /* End of MATLAB Function: '<S7>/MATLAB Function' */

  /* S-Function (arduinoanaloginput_sfcn): '<S2>/Feedback Voltage' */
  rtb_FeedbackVoltage_0 = MW_analogRead(SingleCylinderTest_P.FeedbackVoltage_p1);

  /* Gain: '<Root>/P' */
  rtb_Product = SingleCylinderTest_P.P_Gain * SingleCylinderTest_B.x;

  /* Gain: '<S2>/P' incorporates:
   *  Gain: '<S2>/Normalize Feedback'
   *  S-Function (arduinoanaloginput_sfcn): '<S2>/Feedback Voltage'
   *  Sum: '<S2>/Sum1'
   */
  rtb_Abs1 = (rtb_Product - (real_T)((uint32_T)
    SingleCylinderTest_P.NormalizeFeedback_Gain_g * rtb_FeedbackVoltage_0) *
              2.9802322387695313E-8) * SingleCylinderTest_P.P_Gain_b;

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S13>/Constant2'
   */
  if (rtb_Abs1 >= SingleCylinderTest_P.Switch_Threshold) {
    rtb_Switch = SingleCylinderTest_P.Constant1_Value;
  } else {
    rtb_Switch = SingleCylinderTest_P.Constant2_Value;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Abs: '<S13>/Abs' incorporates:
   *  Product: '<S13>/0 if Negative'
   */
  rtb_Abs1_p = fabs(rtb_Abs1 * rtb_Switch);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  MinMax: '<S2>/Extend Saturation'
   */
  if (rtb_Abs1_p < 256.0) {
    rtb_Abs1_k = (uint8_T)rtb_Abs1_p;
  } else {
    rtb_Abs1_k = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S11>/PWM' */
  MW_analogWrite(SingleCylinderTest_P.PWM_pinNumber, rtb_Abs1_k);

  /* Product: '<S13>/0 If Positive' incorporates:
   *  Constant: '<S13>/Constant3'
   *  Sum: '<S13>/Sum'
   */
  rtb_Abs1 *= rtb_Switch - SingleCylinderTest_P.Constant3_Value;

  /* Abs: '<S13>/Abs1' */
  rtb_Abs1 = fabs(rtb_Abs1);

  /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
   *  MinMax: '<S2>/Retract Saturation'
   */
  if (rtb_Abs1 < 256.0) {
    rtb_Abs1_k = (uint8_T)rtb_Abs1;
  } else {
    rtb_Abs1_k = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S12>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S12>/PWM' */
  MW_analogWrite(SingleCylinderTest_P.PWM_pinNumber_n, rtb_Abs1_k);

  /* Sum: '<S2>/Sum2' */
  SingleCylinderTest_B.Sum2 = rtb_Abs1_p + rtb_Abs1;

  /* S-Function (arduinoanaloginput_sfcn): '<S3>/Feedback Voltage' */
  rtb_FeedbackVoltage_0 = MW_analogRead
    (SingleCylinderTest_P.FeedbackVoltage_p1_n);

  /* Gain: '<S3>/Normalize Feedback' incorporates:
   *  Gain: '<S3>/Length Compensation'
   *  S-Function (arduinoanaloginput_sfcn): '<S3>/Feedback Voltage'
   */
  tmp_0 = (uint32_T)SingleCylinderTest_P.LengthCompensation_Gain *
    rtb_FeedbackVoltage_0;
  uMultiWordMul(&SingleCylinderTest_P.NormalizeFeedback_Gain, 1, &tmp_0, 1,
                &tmp.chunks[0U], 2);

  /* Gain: '<S3>/P' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Abs1_p = ((SingleCylinderTest_P.Constant_Value - rtb_Product) -
                uMultiWord2Double(&tmp.chunks[0U], 2, 0) *
                1.3877787807814457E-17) * SingleCylinderTest_P.P_Gain_h;

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Constant: '<S16>/Constant2'
   */
  if (rtb_Abs1_p >= SingleCylinderTest_P.Switch_Threshold_m) {
    rtb_Switch = SingleCylinderTest_P.Constant1_Value_j;
  } else {
    rtb_Switch = SingleCylinderTest_P.Constant2_Value_d;
  }

  /* End of Switch: '<S16>/Switch' */

  /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
   *  Abs: '<S16>/Abs'
   *  Product: '<S16>/0 if Negative'
   */
  rtb_Product = fabs(rtb_Abs1_p * rtb_Switch);
  if (rtb_Product < 256.0) {
    rtb_Abs1_k = (uint8_T)rtb_Product;
  } else {
    rtb_Abs1_k = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S14>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S14>/PWM' */
  MW_analogWrite(SingleCylinderTest_P.PWM_pinNumber_p, rtb_Abs1_k);

  /* Product: '<S16>/0 If Positive' incorporates:
   *  Constant: '<S16>/Constant3'
   *  Sum: '<S16>/Sum'
   */
  rtb_Abs1_p *= rtb_Switch - SingleCylinderTest_P.Constant3_Value_p;

  /* Abs: '<S16>/Abs1' */
  rtb_Abs1_p = fabs(rtb_Abs1_p);

  /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
   *  MinMax: '<S3>/Retract Saturation'
   */
  if (rtb_Abs1_p < 256.0) {
    rtb_Abs1_k = (uint8_T)rtb_Abs1_p;
  } else {
    rtb_Abs1_k = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_analogWrite(SingleCylinderTest_P.PWM_pinNumber_g, rtb_Abs1_k);
}

/* Model update function */
void SingleCylinderTest_update(void)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  SingleCylinderTest_DW.UnitDelay_DSTATE = SingleCylinderTest_B.Sum2;

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE = SingleCylinderTest_B.x;

  /* Update for UnitDelay: '<S5>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE_k = SingleCylinderTest_B.index_out;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  SingleCylinderTest_M->Timing.clockTick0++;
}

/* Model initialize function */
void SingleCylinderTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)SingleCylinderTest_M, 0,
                sizeof(RT_MODEL_SingleCylinderTest_T));

  /* block I/O */
  (void) memset(((void *) &SingleCylinderTest_B), 0,
                sizeof(B_SingleCylinderTest_T));

  /* states (dwork) */
  (void) memset((void *)&SingleCylinderTest_DW, 0,
                sizeof(DW_SingleCylinderTest_T));

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S2>/Feedback Voltage' */
  MW_pinModeAnalogInput(SingleCylinderTest_P.FeedbackVoltage_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S11>/PWM' */
  MW_pinModeOutput(SingleCylinderTest_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S12>/PWM' */
  MW_pinModeOutput(SingleCylinderTest_P.PWM_pinNumber_n);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S3>/Feedback Voltage' */
  MW_pinModeAnalogInput(SingleCylinderTest_P.FeedbackVoltage_p1_n);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S14>/PWM' */
  MW_pinModeOutput(SingleCylinderTest_P.PWM_pinNumber_p);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_pinModeOutput(SingleCylinderTest_P.PWM_pinNumber_g);

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  SingleCylinderTest_DW.UnitDelay_DSTATE =
    SingleCylinderTest_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE =
    SingleCylinderTest_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE_k =
    SingleCylinderTest_P.UnitDelay1_InitialCondition_l;

  /* InitializeConditions for Chart: '<S5>/Chart' */
  SingleCylinderTest_DW.is_active_c3_SingleCylinderTest = 0U;
  SingleCylinderTest_DW.is_c3_SingleCylinderTest =
    SingleCylind_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void SingleCylinderTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
