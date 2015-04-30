/*
 * File: StepResponseTest.h
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

#ifndef RTW_HEADER_StepResponseTest_h_
#define RTW_HEADER_StepResponseTest_h_
#include <stddef.h>
#include <string.h>
#ifndef StepResponseTest_COMMON_INCLUDES_
# define StepResponseTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* StepResponseTest_COMMON_INCLUDES_ */

#include "StepResponseTest_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T FilterCoefficient;            /* '<S1>/Filter Coefficient' */
  real_T Switch;                       /* '<S1>/Switch' */
} B_StepResponseTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S1>/Integrator' */
  real_T Filter_DSTATE;                /* '<S1>/Filter' */
} DW_StepResponseTest_T;

/* Parameters (auto storage) */
struct P_StepResponseTest_T_ {
  real_T DiscretePIDController_D;      /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  real_T DiscretePIDController_I;      /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  real_T DiscretePIDController_LowerSatu;/* Mask Parameter: DiscretePIDController_LowerSatu
                                          * Referenced by:
                                          *   '<S1>/Saturation'
                                          *   '<S6>/DeadZone'
                                          */
  real_T DiscretePIDController_N;      /* Mask Parameter: DiscretePIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  real_T DiscretePIDController_P;      /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  real_T DiscretePIDController_UpperSatu;/* Mask Parameter: DiscretePIDController_UpperSatu
                                          * Referenced by:
                                          *   '<S1>/Saturation'
                                          *   '<S6>/DeadZone'
                                          */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  uint32_T PWM_pinNumber_b;            /* Mask Parameter: PWM_pinNumber_b
                                        * Referenced by: '<S3>/PWM'
                                        */
  uint32_T PWM_pinNumber_j;            /* Mask Parameter: PWM_pinNumber_j
                                        * Referenced by: '<S4>/PWM'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T ReferenceVoltagePercent_Value;/* Expression: 0.5
                                        * Referenced by: '<Root>/Reference Voltage (Percent)'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S1>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T ReferenceGain_Gain;           /* Expression: 255
                                        * Referenced by: '<Root>/Reference Gain'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Gain_Gain;                    /* Expression: 0
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint32_T FeedbackInput_p1;           /* Computed Parameter: FeedbackInput_p1
                                        * Referenced by: '<Root>/Feedback Input'
                                        */
  uint16_T ScaleTo01_Gain;             /* Computed Parameter: ScaleTo01_Gain
                                        * Referenced by: '<Root>/Scale To (0, 1)'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_StepResponseTest_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_StepResponseTest_T StepResponseTest_P;

/* Block signals (auto storage) */
extern B_StepResponseTest_T StepResponseTest_B;

/* Block states (auto storage) */
extern DW_StepResponseTest_T StepResponseTest_DW;

/* Model entry point functions */
extern void StepResponseTest_initialize(void);
extern void StepResponseTest_output(void);
extern void StepResponseTest_update(void);
extern void StepResponseTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_StepResponseTest_T *const StepResponseTest_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'StepResponseTest'
 * '<S1>'   : 'StepResponseTest/Discrete PID Controller'
 * '<S2>'   : 'StepResponseTest/Extend Signal'
 * '<S3>'   : 'StepResponseTest/Reference Signal'
 * '<S4>'   : 'StepResponseTest/Retract Signal'
 * '<S5>'   : 'StepResponseTest/Subsystem'
 * '<S6>'   : 'StepResponseTest/Discrete PID Controller/Clamping circuit'
 */
#endif                                 /* RTW_HEADER_StepResponseTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
