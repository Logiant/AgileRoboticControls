/*
 * SingleCylinderTest_data.c
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

/* Block parameters (auto storage) */
P_SingleCylinderTest_T SingleCylinderTest_P = {
  0.0,                                 /* Mask Parameter: DiscretePIDController1_D
                                        * Referenced by: '<S3>/Derivative Gain'
                                        */
  0.5,                                 /* Mask Parameter: DiscretePIDController1_I
                                        * Referenced by: '<S3>/Integral Gain'
                                        */
  100.0,                               /* Mask Parameter: DiscretePIDController1_N
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  25.0,                                /* Mask Parameter: DiscretePIDController1_P
                                        * Referenced by: '<S3>/Proportional Gain'
                                        */
  13U,                                 /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S4>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/User Request'
                                        */
  500.0,                               /* Computed Parameter: UserRequest_Period
                                        * Referenced by: '<Root>/User Request'
                                        */
  375.0,                               /* Computed Parameter: UserRequest_Duty
                                        * Referenced by: '<Root>/User Request'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/User Request'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S2>/Feedback Voltage Max'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S2>/Stroke Length'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay1'
                                        */
  0.05,                                /* Expression: .05
                                        * Referenced by: '<S8>/Constant'
                                        */
  1.0,                                 /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S3>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S3>/Integrator'
                                        */
  1.0,                                 /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S3>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S3>/Filter'
                                        */
  6U,                                  /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  32768U                               /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
};
