/*
 * SingleCylinderTest.c
 *
 * Code generation for model "SingleCylinderTest".
 *
 * Model version              : 1.68
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Thu Apr 16 22:12:23 2015
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
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

/* Model step function */
void SingleCylinderTest_step(void)
{
  /* local block i/o variables */
  real_T rtb_Product1;
  real_T rtb_Product_d;
  real_T rtb_Sum;
  real_T rtb_index_out;
  real_T rtb_Sum_k;
  real_T rtb_UnitDelay1_b;
  real_T rtb_Product1_e;
  boolean_T rtb_RelationalOperator;
  uint16_T rtb_AnalogInput_0;
  real_T indexTemp;
  static const real_T b[10] = { 1.0, 1.25, 1.5, 1.75, 2.0, 2.0, 1.75, 1.5, 1.25,
    1.0 };

  real_T rtb_Sum_o;
  real_T rtb_FilterCoefficient;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<Root>/User Request' */
  rtb_Sum_k = (SingleCylinderTest_DW.clockTickCounter <
               SingleCylinderTest_P.UserRequest_Duty) &&
    (SingleCylinderTest_DW.clockTickCounter >= 0) ?
    SingleCylinderTest_P.UserRequest_Amp : 0.0;
  if (SingleCylinderTest_DW.clockTickCounter >=
      SingleCylinderTest_P.UserRequest_Period - 1.0) {
    SingleCylinderTest_DW.clockTickCounter = 0;
  } else {
    SingleCylinderTest_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/User Request' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Sum_k -= SingleCylinderTest_P.Constant_Value;

  /* Product: '<S9>/Reciprocal' incorporates:
   *  Constant: '<S2>/Feedback Voltage Max'
   */
  rtb_UnitDelay1_b = 1.0 / SingleCylinderTest_P.FeedbackVoltageMax_Value;

  /* Product: '<S9>/Product1' incorporates:
   *  Constant: '<S2>/Stroke Length'
   *  Product: '<S9>/Product'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  rtb_Product1 = SingleCylinderTest_DW.UnitDelay_DSTATE * rtb_UnitDelay1_b *
    SingleCylinderTest_P.StrokeLength_Value;

  /* UnitDelay: '<S5>/Unit Delay1' */
  rtb_UnitDelay1_b = SingleCylinderTest_DW.UnitDelay1_DSTATE_o;

  /* Sum: '<S8>/Sum' */
  rtb_Product1_e = rtb_Product1 - rtb_UnitDelay1_b;

  /* Abs: '<S8>/Abs' */
  rtb_Product1_e = fabs(rtb_Product1_e);

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/Constant'
   */
  rtb_RelationalOperator = (rtb_Product1_e <
    SingleCylinderTest_P.Constant_Value_m);

  /* Product: '<S5>/Product' */
  rtb_Product_d = rtb_Sum_k * (real_T)rtb_RelationalOperator;

  /* Chart: '<S7>/Chart' incorporates:
   *  UnitDelay: '<S7>/Unit Delay1'
   */
  /* Gateway: High Level System Controller/System Model/State Machine/Chart */
  /* During: High Level System Controller/System Model/State Machine/Chart */
  if (SingleCylinderTest_DW.is_active_c3_SingleCylinderTest == 0U) {
    /* Entry: High Level System Controller/System Model/State Machine/Chart */
    SingleCylinderTest_DW.is_active_c3_SingleCylinderTest = 1U;

    /* Entry Internal: High Level System Controller/System Model/State Machine/Chart */
    /* Transition: '<S11>:23' */
    SingleCylinderTest_DW.is_c3_SingleCylinderTest = SingleCylinderTest_IN_Idle;

    /* Entry 'Idle': '<S11>:1' */
    SingleCylinderTest_B.index_out = SingleCylinderTest_DW.UnitDelay1_DSTATE;
  } else {
    switch (SingleCylinderTest_DW.is_c3_SingleCylinderTest) {
     case SingleCylinderTest_IN_Forward:
      /* During 'Forward': '<S11>:2' */
      if (rtb_Product_d != 1.0) {
        /* Transition: '<S11>:7' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Idle;

        /* Entry 'Idle': '<S11>:1' */
        SingleCylinderTest_B.index_out = SingleCylinderTest_DW.UnitDelay1_DSTATE;
      } else {
        SingleCylinderTest_B.index_out = SingleCylinderTest_DW.UnitDelay1_DSTATE
          + 1.0;
      }
      break;

     case SingleCylinderTest_IN_Idle:
      /* During 'Idle': '<S11>:1' */
      if (rtb_Product_d == 1.0) {
        /* Transition: '<S11>:4' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Forward;

        /* Entry 'Forward': '<S11>:2' */
        SingleCylinderTest_B.index_out = SingleCylinderTest_DW.UnitDelay1_DSTATE
          + 1.0;
      } else {
        if (rtb_Product_d == -1.0) {
          /* Transition: '<S11>:5' */
          SingleCylinderTest_DW.is_c3_SingleCylinderTest =
            SingleCylinderTest_IN_Reverse;

          /* Entry 'Reverse': '<S11>:3' */
          SingleCylinderTest_B.index_out =
            SingleCylinderTest_DW.UnitDelay1_DSTATE - 1.0;
        }
      }
      break;

     default:
      /* During 'Reverse': '<S11>:3' */
      if (rtb_Product_d != -1.0) {
        /* Transition: '<S11>:6' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Idle;

        /* Entry 'Idle': '<S11>:1' */
        SingleCylinderTest_B.index_out = SingleCylinderTest_DW.UnitDelay1_DSTATE;
      } else {
        SingleCylinderTest_B.index_out = SingleCylinderTest_DW.UnitDelay1_DSTATE
          - 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S7>/Chart' */

  /* MATLAB Function: '<S7>/MATLAB Function' */
  /* MATLAB Function 'High Level System Controller/System Model/State Machine/MATLAB Function': '<S12>:1' */
  /* '<S12>:1:3' */
  rtb_index_out = SingleCylinderTest_B.index_out;
  if (SingleCylinderTest_B.index_out > 10.0) {
    /* '<S12>:1:4' */
    /* '<S12>:1:5' */
    rtb_index_out = 1.0;
  }

  if (SingleCylinderTest_B.index_out < 1.0) {
    /* '<S12>:1:7' */
    /* '<S12>:1:8' */
    rtb_index_out = 10.0;
  }

  /* End of MATLAB Function: '<S7>/MATLAB Function' */

  /* MATLAB Function: '<S10>/MATLAB Function' */
  /* MATLAB Function 'High Level System Controller/System Model/State Machine/Calculate Foot Position/MATLAB Function': '<S13>:1' */
  /* '<S13>:1:3' */
  indexTemp = rtb_index_out;
  if (rtb_index_out < 1.0) {
    /* '<S13>:1:4' */
    /* '<S13>:1:5' */
    indexTemp = 1.0;
  } else {
    if (rtb_index_out > 10.0) {
      /* '<S13>:1:6' */
      /* '<S13>:1:7' */
      indexTemp = 10.0;
    }
  }

  /* Product: '<S6>/Reciprocal' incorporates:
   *  Constant: '<S2>/Stroke Length'
   */
  /* '<S13>:1:9' */
  /* '<S13>:1:11' */
  rtb_Product1_e = 1.0 / SingleCylinderTest_P.StrokeLength_Value;

  /* Product: '<S6>/Product1' incorporates:
   *  Constant: '<S2>/Feedback Voltage Max'
   *  MATLAB Function: '<S10>/MATLAB Function'
   *  Product: '<S6>/Product'
   */
  rtb_Product1_e = b[(int32_T)indexTemp - 1] * rtb_Product1_e *
    SingleCylinderTest_P.FeedbackVoltageMax_Value;

  /* S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  rtb_AnalogInput_0 = MW_analogRead(SingleCylinderTest_P.AnalogInput_p1);

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input'
   */
  rtb_Sum_o = rtb_Product1_e - (real_T)((uint32_T)SingleCylinderTest_P.Gain_Gain
    * rtb_AnalogInput_0) * 1.1920928955078125E-7;

  /* Gain: '<S3>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S3>/Filter'
   *  Gain: '<S3>/Derivative Gain'
   *  Sum: '<S3>/SumD'
   */
  rtb_FilterCoefficient = (SingleCylinderTest_P.DiscretePIDController1_D *
    rtb_Sum_o - SingleCylinderTest_DW.Filter_DSTATE) *
    SingleCylinderTest_P.DiscretePIDController1_N;

  /* Sum: '<S3>/Sum' incorporates:
   *  DiscreteIntegrator: '<S3>/Integrator'
   *  Gain: '<S3>/Proportional Gain'
   */
  rtb_Sum = (SingleCylinderTest_P.DiscretePIDController1_P * rtb_Sum_o +
             SingleCylinderTest_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Sum < 256.0) {
    if (rtb_Sum >= 0.0) {
      tmp = (uint8_T)rtb_Sum;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_analogWrite(SingleCylinderTest_P.PWM_pinNumber, tmp);

  /* Update for UnitDelay: '<S7>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE = rtb_index_out;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  SingleCylinderTest_DW.UnitDelay_DSTATE = rtb_Sum;

  /* Update for UnitDelay: '<S5>/Unit Delay1' incorporates:
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  SingleCylinderTest_DW.UnitDelay1_DSTATE_o = b[(int32_T)indexTemp - 1];

  /* Update for DiscreteIntegrator: '<S3>/Integrator' incorporates:
   *  Gain: '<S3>/Integral Gain'
   */
  SingleCylinderTest_DW.Integrator_DSTATE +=
    SingleCylinderTest_P.DiscretePIDController1_I * rtb_Sum_o *
    SingleCylinderTest_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S3>/Filter' */
  SingleCylinderTest_DW.Filter_DSTATE += SingleCylinderTest_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Matfile logging */
  rt_UpdateTXYLogVars(SingleCylinderTest_M->rtwLogInfo,
                      (&SingleCylinderTest_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(SingleCylinderTest_M)!=-1) &&
        !((rtmGetTFinal(SingleCylinderTest_M)-
           SingleCylinderTest_M->Timing.taskTime0) >
          SingleCylinderTest_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(SingleCylinderTest_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++SingleCylinderTest_M->Timing.clockTick0)) {
    ++SingleCylinderTest_M->Timing.clockTickH0;
  }

  SingleCylinderTest_M->Timing.taskTime0 =
    SingleCylinderTest_M->Timing.clockTick0 *
    SingleCylinderTest_M->Timing.stepSize0 +
    SingleCylinderTest_M->Timing.clockTickH0 *
    SingleCylinderTest_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void SingleCylinderTest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SingleCylinderTest_M, 0,
                sizeof(RT_MODEL_SingleCylinderTest_T));
  rtmSetTFinal(SingleCylinderTest_M, 500.0);
  SingleCylinderTest_M->Timing.stepSize0 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    SingleCylinderTest_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(SingleCylinderTest_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(SingleCylinderTest_M->rtwLogInfo, (NULL));
    rtliSetLogT(SingleCylinderTest_M->rtwLogInfo, "tout");
    rtliSetLogX(SingleCylinderTest_M->rtwLogInfo, "");
    rtliSetLogXFinal(SingleCylinderTest_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(SingleCylinderTest_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(SingleCylinderTest_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(SingleCylinderTest_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(SingleCylinderTest_M->rtwLogInfo, 1);
    rtliSetLogY(SingleCylinderTest_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(SingleCylinderTest_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(SingleCylinderTest_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &SingleCylinderTest_B), 0,
                sizeof(B_SingleCylinderTest_T));

  /* states (dwork) */
  (void) memset((void *)&SingleCylinderTest_DW, 0,
                sizeof(DW_SingleCylinderTest_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(SingleCylinderTest_M->rtwLogInfo, 0.0,
    rtmGetTFinal(SingleCylinderTest_M), SingleCylinderTest_M->Timing.stepSize0,
                                   (&rtmGetErrorStatus(SingleCylinderTest_M)));

  /* Start for DiscretePulseGenerator: '<Root>/User Request' */
  SingleCylinderTest_DW.clockTickCounter = 0;

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  MW_pinModeAnalogInput(SingleCylinderTest_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_pinModeOutput(SingleCylinderTest_P.PWM_pinNumber);

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE =
    SingleCylinderTest_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  SingleCylinderTest_DW.UnitDelay_DSTATE =
    SingleCylinderTest_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE_o =
    SingleCylinderTest_P.UnitDelay1_InitialCondition_f;

  /* InitializeConditions for Chart: '<S7>/Chart' */
  SingleCylinderTest_DW.is_active_c3_SingleCylinderTest = 0U;
  SingleCylinderTest_DW.is_c3_SingleCylinderTest =
    SingleCylind_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Integrator' */
  SingleCylinderTest_DW.Integrator_DSTATE = SingleCylinderTest_P.Integrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Filter' */
  SingleCylinderTest_DW.Filter_DSTATE = SingleCylinderTest_P.Filter_IC;
}

/* Model terminate function */
void SingleCylinderTest_terminate(void)
{
  /* (no terminate code required) */
}
