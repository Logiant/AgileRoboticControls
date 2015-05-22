/*
 * SingleCylinderTest.h
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
#ifndef RTW_HEADER_SingleCylinderTest_h_
#define RTW_HEADER_SingleCylinderTest_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef SingleCylinderTest_COMMON_INCLUDES_
# define SingleCylinderTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* SingleCylinderTest_COMMON_INCLUDES_ */

#include "SingleCylinderTest_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T index_out;                    /* '<S7>/Chart' */
} B_SingleCylinderTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S7>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay1_DSTATE_o;          /* '<S5>/Unit Delay1' */
  real_T Integrator_DSTATE;            /* '<S3>/Integrator' */
  real_T Filter_DSTATE;                /* '<S3>/Filter' */
  struct {
    void *LoggedData;
  } RequestScope_PWORK;                /* '<Root>/Request Scope' */

  struct {
    void *LoggedData;
  } ThighScope_PWORK;                  /* '<Root>/Thigh Scope' */

  struct {
    void *LoggedData;
  } ClosetoEqual_PWORK;                /* '<S5>/Close to Equal' */

  struct {
    void *LoggedData;
  } ThighScope_PWORK_g;                /* '<S5>/Thigh Scope' */

  struct {
    void *LoggedData;
  } ThighScope1_PWORK;                 /* '<S5>/Thigh Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S7>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/User Request' */
  uint8_T is_active_c3_SingleCylinderTest;/* '<S7>/Chart' */
  uint8_T is_c3_SingleCylinderTest;    /* '<S7>/Chart' */
} DW_SingleCylinderTest_T;

/* Parameters (auto storage) */
struct P_SingleCylinderTest_T_ {
  real_T DiscretePIDController1_D;     /* Mask Parameter: DiscretePIDController1_D
                                        * Referenced by: '<S3>/Derivative Gain'
                                        */
  real_T DiscretePIDController1_I;     /* Mask Parameter: DiscretePIDController1_I
                                        * Referenced by: '<S3>/Integral Gain'
                                        */
  real_T DiscretePIDController1_N;     /* Mask Parameter: DiscretePIDController1_N
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  real_T DiscretePIDController1_P;     /* Mask Parameter: DiscretePIDController1_P
                                        * Referenced by: '<S3>/Proportional Gain'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S4>/PWM'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay1'
                                        */
  real_T UserRequest_Amp;              /* Expression: 2
                                        * Referenced by: '<Root>/User Request'
                                        */
  real_T UserRequest_Period;           /* Computed Parameter: UserRequest_Period
                                        * Referenced by: '<Root>/User Request'
                                        */
  real_T UserRequest_Duty;             /* Computed Parameter: UserRequest_Duty
                                        * Referenced by: '<Root>/User Request'
                                        */
  real_T UserRequest_PhaseDelay;       /* Expression: 0
                                        * Referenced by: '<Root>/User Request'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T FeedbackVoltageMax_Value;     /* Expression: 4
                                        * Referenced by: '<S2>/Feedback Voltage Max'
                                        */
  real_T StrokeLength_Value;           /* Expression: 3
                                        * Referenced by: '<S2>/Stroke Length'
                                        */
  real_T UnitDelay1_InitialCondition_f;/* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay1'
                                        */
  real_T Constant_Value_m;             /* Expression: .05
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S3>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S3>/Filter'
                                        */
  uint32_T AnalogInput_p1;             /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SingleCylinderTest_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
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
extern void SingleCylinderTest_step(void);
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
 * '<S3>'   : 'SingleCylinderTest/Cylinder PID/Discrete PID Controller1'
 * '<S4>'   : 'SingleCylinderTest/Cylinder PID/PWM'
 * '<S5>'   : 'SingleCylinderTest/High Level System Controller/System Model'
 * '<S6>'   : 'SingleCylinderTest/High Level System Controller/System Model/Length to Voltage'
 * '<S7>'   : 'SingleCylinderTest/High Level System Controller/System Model/State Machine'
 * '<S8>'   : 'SingleCylinderTest/High Level System Controller/System Model/Threshold'
 * '<S9>'   : 'SingleCylinderTest/High Level System Controller/System Model/Voltage to Length'
 * '<S10>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/Calculate Foot Position'
 * '<S11>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/Chart'
 * '<S12>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/MATLAB Function'
 * '<S13>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/Calculate Foot Position/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_SingleCylinderTest_h_ */
