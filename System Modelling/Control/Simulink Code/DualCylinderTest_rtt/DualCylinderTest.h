/*
 * File: DualCylinderTest.h
 *
 * Code generated for Simulink model 'DualCylinderTest'.
 *
 * Model version                  : 1.129
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 22 11:32:24 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DualCylinderTest_h_
#define RTW_HEADER_DualCylinderTest_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef DualCylinderTest_COMMON_INCLUDES_
# define DualCylinderTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* DualCylinderTest_COMMON_INCLUDES_ */

#include "DualCylinderTest_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Sum2;                         /* '<S2>/Sum2' */
  real_T index_out;                    /* '<S5>/MATLAB Function' */
  real_T index_out_n;                  /* '<S5>/Chart' */
  real_T x;                            /* '<S7>/MATLAB Function' */
} B_DualCylinderTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S4>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_k;          /* '<S5>/Unit Delay1' */
  uint8_T is_active_c3_DualCylinderTest;/* '<S5>/Chart' */
  uint8_T is_c3_DualCylinderTest;      /* '<S5>/Chart' */
} DW_DualCylinderTest_T;

/* Parameters (auto storage) */
struct P_DualCylinderTest_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S11>/PWM'
                                        */
  uint32_T PWM_pinNumber_n;            /* Mask Parameter: PWM_pinNumber_n
                                        * Referenced by: '<S12>/PWM'
                                        */
  uint32_T PWM_pinNumber_p;            /* Mask Parameter: PWM_pinNumber_p
                                        * Referenced by: '<S14>/PWM'
                                        */
  uint32_T PWM_pinNumber_g;            /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S15>/PWM'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S16>/Constant2'
                                        */
  real_T Constant1_Value_j;            /* Expression: 1
                                        * Referenced by: '<S16>/Constant1'
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
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S4>/Unit Delay1'
                                        */
  real_T Constant_Value;               /* Expression: 500
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition_l;/* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay1'
                                        */
  real_T Normalize_Gain;               /* Expression: 1/5
                                        * Referenced by: '<Root>/Normalize'
                                        */
  real_T ShankOffset_Value;            /* Expression: 1
                                        * Referenced by: '<Root>/Shank Offset'
                                        */
  real_T P_Gain;                       /* Expression: 3000
                                        * Referenced by: '<S2>/P'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S13>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T P_Gain_h;                     /* Expression: 3000
                                        * Referenced by: '<S3>/P'
                                        */
  real_T Switch_Threshold_m;           /* Expression: 0
                                        * Referenced by: '<S16>/Switch'
                                        */
  real_T Constant3_Value_p;            /* Expression: 1
                                        * Referenced by: '<S16>/Constant3'
                                        */
  uint32_T FeedbackVoltage_p1;         /* Computed Parameter: FeedbackVoltage_p1
                                        * Referenced by: '<S2>/Feedback Voltage'
                                        */
  uint32_T FeedbackVoltage_p1_n;       /* Computed Parameter: FeedbackVoltage_p1_n
                                        * Referenced by: '<S3>/Feedback Voltage'
                                        */
  uint32_T NormalizeFeedback_Gain;     /* Computed Parameter: NormalizeFeedback_Gain
                                        * Referenced by: '<S3>/Normalize Feedback'
                                        */
  uint16_T NormalizeFeedback_Gain_g;   /* Computed Parameter: NormalizeFeedback_Gain_g
                                        * Referenced by: '<S2>/Normalize Feedback'
                                        */
  uint16_T LengthCompensation_Gain;    /* Computed Parameter: LengthCompensation_Gain
                                        * Referenced by: '<S3>/Length Compensation'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_DualCylinderTest_T {
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
extern P_DualCylinderTest_T DualCylinderTest_P;

/* Block signals (auto storage) */
extern B_DualCylinderTest_T DualCylinderTest_B;

/* Block states (auto storage) */
extern DW_DualCylinderTest_T DualCylinderTest_DW;

/* Model entry point functions */
extern void DualCylinderTest_initialize(void);
extern void DualCylinderTest_output(void);
extern void DualCylinderTest_update(void);
extern void DualCylinderTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DualCylinderTest_T *const DualCylinderTest_M;

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
 * '<Root>' : 'DualCylinderTest'
 * '<S1>'   : 'DualCylinderTest/High Level System Controller'
 * '<S2>'   : 'DualCylinderTest/Shank PID'
 * '<S3>'   : 'DualCylinderTest/Thigh PID'
 * '<S4>'   : 'DualCylinderTest/High Level System Controller/System Model'
 * '<S5>'   : 'DualCylinderTest/High Level System Controller/System Model/State Machine'
 * '<S6>'   : 'DualCylinderTest/High Level System Controller/System Model/Threshold'
 * '<S7>'   : 'DualCylinderTest/High Level System Controller/System Model/State Machine/Calculate Foot Position'
 * '<S8>'   : 'DualCylinderTest/High Level System Controller/System Model/State Machine/Chart'
 * '<S9>'   : 'DualCylinderTest/High Level System Controller/System Model/State Machine/MATLAB Function'
 * '<S10>'  : 'DualCylinderTest/High Level System Controller/System Model/State Machine/Calculate Foot Position/MATLAB Function'
 * '<S11>'  : 'DualCylinderTest/Shank PID/Extend Command'
 * '<S12>'  : 'DualCylinderTest/Shank PID/Retract Command'
 * '<S13>'  : 'DualCylinderTest/Shank PID/Split Signal'
 * '<S14>'  : 'DualCylinderTest/Thigh PID/Extend Command'
 * '<S15>'  : 'DualCylinderTest/Thigh PID/Retract Command'
 * '<S16>'  : 'DualCylinderTest/Thigh PID/Split Signal'
 */
#endif                                 /* RTW_HEADER_DualCylinderTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
