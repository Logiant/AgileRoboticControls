/*
 * File: SingleCylinderTest.c
 *
 * Code generated for Simulink model 'SingleCylinderTest'.
 *
 * Model version                  : 1.121
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed Apr 29 18:56:04 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SingleCylinderTest.h"
#include "SingleCylinderTest_private.h"

/* Named constants for Chart: '<S7>/Chart' */
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

/* Model output function */
void SingleCylinderTest_output(void)
{
  uint16_T rtb_FeedbackVoltage_0;
  static const int8_T b[6] = { 1, 2, 3, 4, 3, 2 };

  real_T rtb_Switch;
  real_T rtb_Product;
  real_T rtb_Abs;
  uint8_T rtb_Abs_0;

  /* S-Function (arduinoanaloginput_sfcn): '<S1>/Feedback Voltage' */
  rtb_FeedbackVoltage_0 = MW_analogRead(SingleCylinderTest_P.FeedbackVoltage_p1);

  /* Step: '<Root>/Step' */
  if (((SingleCylinderTest_M->Timing.clockTick0) * 0.01) <
      SingleCylinderTest_P.Step_Time) {
    rtb_Product = SingleCylinderTest_P.Step_Y0;
  } else {
    rtb_Product = SingleCylinderTest_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Product: '<S6>/Product' incorporates:
   *  Abs: '<S8>/Abs'
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  Sum: '<S8>/Sum'
   *  UnitDelay: '<Root>/Unit Delay'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  rtb_Product *= (real_T)(fabs(SingleCylinderTest_DW.UnitDelay_DSTATE -
    SingleCylinderTest_DW.UnitDelay1_DSTATE_o) <
    SingleCylinderTest_P.Constant_Value);

  /* Chart: '<S7>/Chart' incorporates:
   *  UnitDelay: '<S7>/Unit Delay1'
   */
  /* Gateway: High Level System Controller/System Model/State Machine/Chart */
  /* During: High Level System Controller/System Model/State Machine/Chart */
  if (SingleCylinderTest_DW.is_active_c3_SingleCylinderTest == 0U) {
    /* Entry: High Level System Controller/System Model/State Machine/Chart */
    SingleCylinderTest_DW.is_active_c3_SingleCylinderTest = 1U;

    /* Entry Internal: High Level System Controller/System Model/State Machine/Chart */
    /* Transition: '<S10>:23' */
    SingleCylinderTest_DW.is_c3_SingleCylinderTest = SingleCylinderTest_IN_Idle;

    /* Entry 'Idle': '<S10>:1' */
    SingleCylinderTest_B.index_out_n = SingleCylinderTest_DW.UnitDelay1_DSTATE;
  } else {
    switch (SingleCylinderTest_DW.is_c3_SingleCylinderTest) {
     case SingleCylinderTest_IN_Forward:
      /* During 'Forward': '<S10>:2' */
      if (rtb_Product != 1.0) {
        /* Transition: '<S10>:7' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Idle;

        /* Entry 'Idle': '<S10>:1' */
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE;
      } else {
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE + 1.0;
      }
      break;

     case SingleCylinderTest_IN_Idle:
      /* During 'Idle': '<S10>:1' */
      if (rtb_Product == 1.0) {
        /* Transition: '<S10>:4' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Forward;

        /* Entry 'Forward': '<S10>:2' */
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE + 1.0;
      } else {
        if (rtb_Product == -1.0) {
          /* Transition: '<S10>:5' */
          SingleCylinderTest_DW.is_c3_SingleCylinderTest =
            SingleCylinderTest_IN_Reverse;

          /* Entry 'Reverse': '<S10>:3' */
          SingleCylinderTest_B.index_out_n =
            SingleCylinderTest_DW.UnitDelay1_DSTATE - 1.0;
        }
      }
      break;

     default:
      /* During 'Reverse': '<S10>:3' */
      if (rtb_Product != -1.0) {
        /* Transition: '<S10>:6' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Idle;

        /* Entry 'Idle': '<S10>:1' */
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE;
      } else {
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE - 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S7>/Chart' */

  /* MATLAB Function: '<S7>/MATLAB Function' */
  /* MATLAB Function 'High Level System Controller/System Model/State Machine/MATLAB Function': '<S11>:1' */
  /* '<S11>:1:3' */
  SingleCylinderTest_B.index_out = SingleCylinderTest_B.index_out_n;
  if (SingleCylinderTest_B.index_out_n > 6.0) {
    /* '<S11>:1:4' */
    /* '<S11>:1:5' */
    SingleCylinderTest_B.index_out = 1.0;
  }

  if (SingleCylinderTest_B.index_out_n < 1.0) {
    /* '<S11>:1:7' */
    /* '<S11>:1:8' */
    SingleCylinderTest_B.index_out = 6.0;
  }

  /* End of MATLAB Function: '<S7>/MATLAB Function' */

  /* MATLAB Function: '<S9>/MATLAB Function' */
  /* MATLAB Function 'High Level System Controller/System Model/State Machine/Calculate Foot Position/MATLAB Function': '<S12>:1' */
  /* '<S12>:1:3' */
  rtb_Product = SingleCylinderTest_B.index_out;
  if (SingleCylinderTest_B.index_out < 1.0) {
    /* '<S12>:1:4' */
    /* '<S12>:1:5' */
    rtb_Product = 1.0;
  } else {
    if (SingleCylinderTest_B.index_out > 6.0) {
      /* '<S12>:1:6' */
      /* '<S12>:1:7' */
      rtb_Product = 6.0;
    }
  }

  /* '<S12>:1:9' */
  /* divide by 5 to normalize */
  /* '<S12>:1:11' */
  SingleCylinderTest_B.x = b[(int16_T)rtb_Product - 1];

  /* End of MATLAB Function: '<S9>/MATLAB Function' */

  /* Gain: '<S1>/P' incorporates:
   *  Gain: '<Root>/P'
   *  Gain: '<S1>/Normalize Feedback'
   *  S-Function (arduinoanaloginput_sfcn): '<S1>/Feedback Voltage'
   *  Sum: '<S1>/Sum1'
   */
  rtb_Product = (SingleCylinderTest_P.P_Gain * SingleCylinderTest_B.x - (real_T)
                 ((uint32_T)SingleCylinderTest_P.NormalizeFeedback_Gain *
                  rtb_FeedbackVoltage_0) * 2.9802322387695313E-8) *
    SingleCylinderTest_P.P_Gain_h;

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   */
  if (rtb_Product >= SingleCylinderTest_P.Switch_Threshold) {
    rtb_Switch = SingleCylinderTest_P.Constant1_Value;
  } else {
    rtb_Switch = SingleCylinderTest_P.Constant2_Value;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Abs: '<S5>/Abs' incorporates:
   *  Product: '<S5>/0 if Negative'
   */
  rtb_Abs = fabs(rtb_Product * rtb_Switch);

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  MinMax: '<S1>/Extend Saturation'
   */
  if (rtb_Abs < 256.0) {
    rtb_Abs_0 = (uint8_T)rtb_Abs;
  } else {
    rtb_Abs_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S3>/PWM' */
  MW_analogWrite(SingleCylinderTest_P.PWM_pinNumber, rtb_Abs_0);

  /* Product: '<S5>/0 If Positive' incorporates:
   *  Constant: '<S5>/Constant3'
   *  Sum: '<S5>/Sum'
   */
  rtb_Product *= rtb_Switch - SingleCylinderTest_P.Constant3_Value;

  /* Abs: '<S5>/Abs1' */
  rtb_Product = fabs(rtb_Product);

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  MinMax: '<S1>/Retract Saturation'
   */
  if (rtb_Product < 256.0) {
    rtb_Abs_0 = (uint8_T)rtb_Product;
  } else {
    rtb_Abs_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_analogWrite(SingleCylinderTest_P.PWM_pinNumber_g, rtb_Abs_0);

  /* Sum: '<S1>/Sum2' */
  SingleCylinderTest_B.Sum2 = rtb_Abs + rtb_Product;
}

/* Model update function */
void SingleCylinderTest_update(void)
{
  /* Update for UnitDelay: '<S7>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE = SingleCylinderTest_B.index_out;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  SingleCylinderTest_DW.UnitDelay_DSTATE = SingleCylinderTest_B.Sum2;

  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE_o = SingleCylinderTest_B.x;

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

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Feedback Voltage' */
  MW_pinModeAnalogInput(SingleCylinderTest_P.FeedbackVoltage_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S3>/PWM' */
  MW_pinModeOutput(SingleCylinderTest_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_pinModeOutput(SingleCylinderTest_P.PWM_pinNumber_g);

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE =
    SingleCylinderTest_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  SingleCylinderTest_DW.UnitDelay_DSTATE =
    SingleCylinderTest_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE_o =
    SingleCylinderTest_P.UnitDelay1_InitialCondition_f;

  /* InitializeConditions for Chart: '<S7>/Chart' */
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
