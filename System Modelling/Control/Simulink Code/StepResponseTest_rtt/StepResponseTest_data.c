/*
 * File: StepResponseTest_data.c
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

/* Block parameters (auto storage) */
P_StepResponseTest_T StepResponseTest_P = {
  0.0,                                 /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  0.0,                                 /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  0.0,                                 /* Mask Parameter: DiscretePIDController_LowerSatu
                                        * Referenced by:
                                        *   '<S1>/Saturation'
                                        *   '<S6>/DeadZone'
                                        */
  100.0,                               /* Mask Parameter: DiscretePIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  30000.0,                             /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  0.0,                                 /* Mask Parameter: DiscretePIDController_UpperSatu
                                        * Referenced by:
                                        *   '<S1>/Saturation'
                                        *   '<S6>/DeadZone'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  9U,                                  /* Mask Parameter: PWM_pinNumber_b
                                        * Referenced by: '<S3>/PWM'
                                        */
  7U,                                  /* Mask Parameter: PWM_pinNumber_j
                                        * Referenced by: '<S4>/PWM'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Reference Voltage (Percent)'
                                        */
  0.01,                                /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.01,                                /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S1>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<Root>/Reference Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  2U,                                  /* Computed Parameter: FeedbackInput_p1
                                        * Referenced by: '<Root>/Feedback Input'
                                        */
  32800U                               /* Computed Parameter: ScaleTo01_Gain
                                        * Referenced by: '<Root>/Scale To (0, 1)'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
