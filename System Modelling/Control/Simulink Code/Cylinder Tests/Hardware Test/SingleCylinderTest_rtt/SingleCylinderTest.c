/*
 * File: SingleCylinderTest.c
 *
 * Code generated for Simulink model 'SingleCylinderTest'.
 *
 * Model version                  : 1.111
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Sun Apr 26 14:26:03 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SingleCylinderTest.h"
#include "SingleCylinderTest_private.h"

/* Named constants for Chart: '<S8>/Chart' */
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
  uint16_T rtb_AnalogInput_0;
  static const int8_T b[6] = { 1, 2, 3, 4, 3, 2 };

  real_T rtb_IntegralGain;
  real_T rtb_DeadZone;
  real_T rtb_Product;
  real_T rtb_Abs;
  real_T rtb_ifNegative;
  uint8_T rtb_ifNegative_0;
  real_T rtb_DeadZone_0;
  real_T rtb_IntegralGain_0;

  /* S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  rtb_AnalogInput_0 = MW_analogRead(SingleCylinderTest_P.AnalogInput_p1);

  /* Step: '<Root>/Step' */
  if (((SingleCylinderTest_M->Timing.clockTick0) * 0.01) <
      SingleCylinderTest_P.Step_Time) {
    rtb_Product = SingleCylinderTest_P.Step_Y0;
  } else {
    rtb_Product = SingleCylinderTest_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Product: '<S7>/Product' incorporates:
   *  Abs: '<S9>/Abs'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Relational Operator'
   *  Sum: '<S9>/Sum'
   *  UnitDelay: '<Root>/Unit Delay'
   *  UnitDelay: '<S7>/Unit Delay1'
   */
  rtb_Product *= (real_T)(fabs(SingleCylinderTest_DW.UnitDelay_DSTATE -
    SingleCylinderTest_DW.UnitDelay1_DSTATE_o) <
    SingleCylinderTest_P.Constant_Value);

  /* Chart: '<S8>/Chart' incorporates:
   *  UnitDelay: '<S8>/Unit Delay1'
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
    SingleCylinderTest_B.index_out_n = SingleCylinderTest_DW.UnitDelay1_DSTATE;
  } else {
    switch (SingleCylinderTest_DW.is_c3_SingleCylinderTest) {
     case SingleCylinderTest_IN_Forward:
      /* During 'Forward': '<S11>:2' */
      if (rtb_Product != 1.0) {
        /* Transition: '<S11>:7' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Idle;

        /* Entry 'Idle': '<S11>:1' */
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE;
      } else {
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE + 1.0;
      }
      break;

     case SingleCylinderTest_IN_Idle:
      /* During 'Idle': '<S11>:1' */
      if (rtb_Product == 1.0) {
        /* Transition: '<S11>:4' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Forward;

        /* Entry 'Forward': '<S11>:2' */
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE + 1.0;
      } else {
        if (rtb_Product == -1.0) {
          /* Transition: '<S11>:5' */
          SingleCylinderTest_DW.is_c3_SingleCylinderTest =
            SingleCylinderTest_IN_Reverse;

          /* Entry 'Reverse': '<S11>:3' */
          SingleCylinderTest_B.index_out_n =
            SingleCylinderTest_DW.UnitDelay1_DSTATE - 1.0;
        }
      }
      break;

     default:
      /* During 'Reverse': '<S11>:3' */
      if (rtb_Product != -1.0) {
        /* Transition: '<S11>:6' */
        SingleCylinderTest_DW.is_c3_SingleCylinderTest =
          SingleCylinderTest_IN_Idle;

        /* Entry 'Idle': '<S11>:1' */
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE;
      } else {
        SingleCylinderTest_B.index_out_n =
          SingleCylinderTest_DW.UnitDelay1_DSTATE - 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/Chart' */

  /* MATLAB Function: '<S8>/MATLAB Function' */
  /* MATLAB Function 'High Level System Controller/System Model/State Machine/MATLAB Function': '<S12>:1' */
  /* '<S12>:1:3' */
  SingleCylinderTest_B.index_out = SingleCylinderTest_B.index_out_n;
  if (SingleCylinderTest_B.index_out_n > 6.0) {
    /* '<S12>:1:4' */
    /* '<S12>:1:5' */
    SingleCylinderTest_B.index_out = 1.0;
  }

  if (SingleCylinderTest_B.index_out_n < 1.0) {
    /* '<S12>:1:7' */
    /* '<S12>:1:8' */
    SingleCylinderTest_B.index_out = 6.0;
  }

  /* End of MATLAB Function: '<S8>/MATLAB Function' */

  /* MATLAB Function: '<S10>/MATLAB Function' */
  /* MATLAB Function 'High Level System Controller/System Model/State Machine/Calculate Foot Position/MATLAB Function': '<S13>:1' */
  /* '<S13>:1:3' */
  rtb_Product = SingleCylinderTest_B.index_out;
  if (SingleCylinderTest_B.index_out < 1.0) {
    /* '<S13>:1:4' */
    /* '<S13>:1:5' */
    rtb_Product = 1.0;
  } else {
    if (SingleCylinderTest_B.index_out > 6.0) {
      /* '<S13>:1:6' */
      /* '<S13>:1:7' */
      rtb_Product = 6.0;
    }
  }

  /* '<S13>:1:9' */
  /* '<S13>:1:11' */
  SingleCylinderTest_B.x = b[(int16_T)rtb_Product - 1];

  /* End of MATLAB Function: '<S10>/MATLAB Function' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/Normalize'
   *  Gain: '<S1>/Set To (0, 1)'
   *  S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input'
   */
  rtb_IntegralGain = SingleCylinderTest_P.Normalize_Gain *
    SingleCylinderTest_B.x - (real_T)((uint32_T)
    SingleCylinderTest_P.SetTo01_Gain * rtb_AnalogInput_0) *
    2.9802322387695313E-8;

  /* Gain: '<S3>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S3>/Filter'
   *  Gain: '<S3>/Derivative Gain'
   *  Sum: '<S3>/SumD'
   */
  SingleCylinderTest_B.FilterCoefficient =
    (SingleCylinderTest_P.DiscretePIDController_D * rtb_IntegralGain -
     SingleCylinderTest_DW.Filter_DSTATE) *
    SingleCylinderTest_P.DiscretePIDController_N;

  /* Sum: '<S3>/Sum' incorporates:
   *  DiscreteIntegrator: '<S3>/Integrator'
   *  Gain: '<S3>/Proportional Gain'
   */
  rtb_DeadZone = (SingleCylinderTest_P.DiscretePIDController_P *
                  rtb_IntegralGain + SingleCylinderTest_DW.Integrator_DSTATE) +
    SingleCylinderTest_B.FilterCoefficient;

  /* Saturate: '<S3>/Saturation' */
  if (rtb_DeadZone > SingleCylinderTest_P.DiscretePIDController_UpperSatu) {
    rtb_Abs = SingleCylinderTest_P.DiscretePIDController_UpperSatu;
  } else if (rtb_DeadZone < SingleCylinderTest_P.DiscretePIDController_LowerSatu)
  {
    rtb_Abs = SingleCylinderTest_P.DiscretePIDController_LowerSatu;
  } else {
    rtb_Abs = rtb_DeadZone;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  if (rtb_Abs >= SingleCylinderTest_P.Switch_Threshold) {
    rtb_Product = SingleCylinderTest_P.Constant1_Value;
  } else {
    rtb_Product = SingleCylinderTest_P.Constant2_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Product: '<S1>/0 if Negative' */
  rtb_ifNegative = rtb_Abs * rtb_Product;

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  MinMax: '<S1>/MinMax'
   */
  if (rtb_ifNegative < 256.0) {
    if (rtb_ifNegative >= 0.0) {
      rtb_ifNegative_0 = (uint8_T)rtb_ifNegative;
    } else {
      rtb_ifNegative_0 = 0U;
    }
  } else {
    rtb_ifNegative_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_analogWrite(SingleCylinderTest_P.PWM_pinNumber, rtb_ifNegative_0);

  /* Product: '<S1>/0 If Positive' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Sum: '<S1>/Sum'
   */
  rtb_Abs *= rtb_Product - SingleCylinderTest_P.Constant3_Value;

  /* Abs: '<S1>/Abs' */
  rtb_Abs = fabs(rtb_Abs);

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  MinMax: '<S1>/MinMax1'
   */
  if (rtb_Abs < 256.0) {
    rtb_ifNegative_0 = (uint8_T)rtb_Abs;
  } else {
    rtb_ifNegative_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' */
  MW_analogWrite(SingleCylinderTest_P.PWM_pinNumber_g, rtb_ifNegative_0);

  /* Gain: '<S6>/Gain' */
  rtb_Product = SingleCylinderTest_P.Gain_Gain * rtb_DeadZone;

  /* DeadZone: '<S6>/DeadZone' */
  if (rtb_DeadZone > SingleCylinderTest_P.DiscretePIDController_UpperSatu) {
    rtb_DeadZone -= SingleCylinderTest_P.DiscretePIDController_UpperSatu;
  } else if (rtb_DeadZone >=
             SingleCylinderTest_P.DiscretePIDController_LowerSatu) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= SingleCylinderTest_P.DiscretePIDController_LowerSatu;
  }

  /* End of DeadZone: '<S6>/DeadZone' */

  /* Gain: '<S3>/Integral Gain' */
  rtb_IntegralGain *= SingleCylinderTest_P.DiscretePIDController_I;

  /* Signum: '<S6>/SignPreSat' */
  if (rtb_DeadZone < 0.0) {
    rtb_DeadZone_0 = -1.0;
  } else if (rtb_DeadZone > 0.0) {
    rtb_DeadZone_0 = 1.0;
  } else if (rtb_DeadZone == 0.0) {
    rtb_DeadZone_0 = 0.0;
  } else {
    rtb_DeadZone_0 = rtb_DeadZone;
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

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Logic: '<S6>/AND'
   *  RelationalOperator: '<S6>/Equal'
   *  RelationalOperator: '<S6>/NotEqual'
   *  Signum: '<S6>/SignPreIntegrator'
   *  Signum: '<S6>/SignPreSat'
   */
  if ((rtb_Product != rtb_DeadZone) && (rtb_DeadZone_0 == rtb_IntegralGain_0)) {
    SingleCylinderTest_B.Switch = SingleCylinderTest_P.Constant_Value_b;
  } else {
    SingleCylinderTest_B.Switch = rtb_IntegralGain;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S1>/Sum2' */
  SingleCylinderTest_B.Sum2 = rtb_ifNegative + rtb_Abs;
}

/* Model update function */
void SingleCylinderTest_update(void)
{
  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE = SingleCylinderTest_B.index_out;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  SingleCylinderTest_DW.UnitDelay_DSTATE = SingleCylinderTest_B.Sum2;

  /* Update for UnitDelay: '<S7>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE_o = SingleCylinderTest_B.x;

  /* Update for DiscreteIntegrator: '<S3>/Integrator' */
  SingleCylinderTest_DW.Integrator_DSTATE +=
    SingleCylinderTest_P.Integrator_gainval * SingleCylinderTest_B.Switch;

  /* Update for DiscreteIntegrator: '<S3>/Filter' */
  SingleCylinderTest_DW.Filter_DSTATE += SingleCylinderTest_P.Filter_gainval *
    SingleCylinderTest_B.FilterCoefficient;

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

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  SingleCylinderTest_P.DiscretePIDController_LowerSatu = rtMinusInf;
  SingleCylinderTest_P.DiscretePIDController_UpperSatu = rtInf;

  /* initialize real-time model */
  (void) memset((void *)SingleCylinderTest_M, 0,
                sizeof(RT_MODEL_SingleCylinderTest_T));

  /* block I/O */
  (void) memset(((void *) &SingleCylinderTest_B), 0,
                sizeof(B_SingleCylinderTest_T));

  /* states (dwork) */
  (void) memset((void *)&SingleCylinderTest_DW, 0,
                sizeof(DW_SingleCylinderTest_T));

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  MW_pinModeAnalogInput(SingleCylinderTest_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_pinModeOutput(SingleCylinderTest_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' */
  MW_pinModeOutput(SingleCylinderTest_P.PWM_pinNumber_g);

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE =
    SingleCylinderTest_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  SingleCylinderTest_DW.UnitDelay_DSTATE =
    SingleCylinderTest_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
  SingleCylinderTest_DW.UnitDelay1_DSTATE_o =
    SingleCylinderTest_P.UnitDelay1_InitialCondition_f;

  /* InitializeConditions for Chart: '<S8>/Chart' */
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

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
