/*
 * File: SingleCylinderTest.h
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

#ifndef RTW_HEADER_SingleCylinderTest_h_
#define RTW_HEADER_SingleCylinderTest_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef SingleCylinderTest_COMMON_INCLUDES_
# define SingleCylinderTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* SingleCylinderTest_COMMON_INCLUDES_ */

#include "SingleCylinderTest_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Sum2;                         /* '<S1>/Sum2' */
  real_T index_out;                    /* '<S7>/MATLAB Function' */
  real_T index_out_n;                  /* '<S7>/Chart' */
  real_T x;                            /* '<S9>/MATLAB Function' */
} B_SingleCylinderTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S7>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay1_DSTATE_o;          /* '<S6>/Unit Delay1' */
  uint8_T is_active_c3_SingleCylinderTest;/* '<S7>/Chart' */
  uint8_T is_c3_SingleCylinderTest;    /* '<S7>/Chart' */
} DW_SingleCylinderTest_T;

/* Parameters (auto storage) */
struct P_SingleCylinderTest_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S3>/PWM'
                                        */
  uint32_T PWM_pinNumber_g;            /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S4>/PWM'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay1'
                                        */
  real_T Step_Time;                    /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_f;/* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay1'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T P_Gain;                       /* Expression: 1/5
                                        * Referenced by: '<Root>/P'
                                        */
  real_T P_Gain_h;                     /* Expression: 3000
                                        * Referenced by: '<S1>/P'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant3'
                                        */
  uint32_T FeedbackVoltage_p1;         /* Computed Parameter: FeedbackVoltage_p1
                                        * Referenced by: '<S1>/Feedback Voltage'
                                        */
  uint16_T NormalizeFeedback_Gain;     /* Computed Parameter: NormalizeFeedback_Gain
                                        * Referenced by: '<S1>/Normalize Feedback'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SingleCylinderTest_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_SingleCylinderTest_T SingleCylinderTest_P;

/* Block signals (auto storage) */
extern B_SingleCylinderTest_T SingleCylinderTest_B;

/* Block states (auto storage) */
extern DW_SingleCylinderTest_T SingleCylinderTest_DW;

/* Model entry point functions */
extern void SingleCylinderTest_initialize(void);
extern void SingleCylinderTest_output(void);
extern void SingleCylinderTest_update(void);
extern void SingleCylinderTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SingleCylinderTest_T *const SingleCylinderTest_M;

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
 * '<Root>' : 'SingleCylinderTest'
 * '<S1>'   : 'SingleCylinderTest/Cylinder PID'
 * '<S2>'   : 'SingleCylinderTest/High Level System Controller'
 * '<S3>'   : 'SingleCylinderTest/Cylinder PID/Extend Command'
 * '<S4>'   : 'SingleCylinderTest/Cylinder PID/Retract Command'
 * '<S5>'   : 'SingleCylinderTest/Cylinder PID/Split Signal'
 * '<S6>'   : 'SingleCylinderTest/High Level System Controller/System Model'
 * '<S7>'   : 'SingleCylinderTest/High Level System Controller/System Model/State Machine'
 * '<S8>'   : 'SingleCylinderTest/High Level System Controller/System Model/Threshold'
 * '<S9>'   : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/Calculate Foot Position'
 * '<S10>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/Chart'
 * '<S11>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/MATLAB Function'
 * '<S12>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/Calculate Foot Position/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_SingleCylinderTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */