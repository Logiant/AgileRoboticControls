/*
 * File: ArduinoFeedbackTest_data.c
 *
 * Code generated for Simulink model 'ArduinoFeedbackTest'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Mon Mar 16 16:55:36 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ArduinoFeedbackTest.h"
#include "ArduinoFeedbackTest_private.h"

/* Block parameters (auto storage) */
P_ArduinoFeedbackTest_T ArduinoFeedbackTest_P = {
  0.0,                                 /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  3.0,                                 /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  100.0,                               /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  35.0,                                /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.6,                                 /* Expression: .6
                                        * Referenced by: '<Root>/Desired Percent Max Position'
                                        */
  1023.0,                              /* Expression: 1023
                                        * Referenced by: '<Root>/Scale to Max Input'
                                        */
  0.25,                                /* Expression: 1/4
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  4U,                                  /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  0U                                   /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
