/*
 * File: SingleCylinderTest_data.c
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

/* Block parameters (auto storage) */
P_SingleCylinderTest_T SingleCylinderTest_P = {
  0.0,                                 /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S3>/Derivative Gain'
                                        */
  25.0,                                /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S3>/Integral Gain'
                                        */
  0.0,                                 /* Mask Parameter: DiscretePIDController_LowerSatu
                                        * Referenced by:
                                        *   '<S3>/Saturation'
                                        *   '<S6>/DeadZone'
                                        */
  100.0,                               /* Mask Parameter: DiscretePIDController_N
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  3000.0,                              /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S3>/Proportional Gain'
                                        */
  0.0,                                 /* Mask Parameter: DiscretePIDController_UpperSatu
                                        * Referenced by:
                                        *   '<S3>/Saturation'
                                        *   '<S6>/DeadZone'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S4>/PWM'
                                        */
  7U,                                  /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S5>/PWM'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S9>/Constant'
                                        */
  0.2,                                 /* Expression: 1/5
                                        * Referenced by: '<S1>/Normalize'
                                        */
  0.01,                                /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S3>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S3>/Integrator'
                                        */
  0.01,                                /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S3>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S3>/Filter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  2U,                                  /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  32800U                               /* Computed Parameter: SetTo01_Gain
                                        * Referenced by: '<S1>/Set To (0, 1)'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
