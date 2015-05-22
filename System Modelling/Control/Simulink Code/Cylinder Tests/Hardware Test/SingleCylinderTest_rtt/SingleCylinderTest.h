/*
 * File: SingleCylinderTest.h
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
  real_T FilterCoefficient;            /* '<S3>/Filter Coefficient' */
  real_T Switch;                       /* '<S3>/Switch' */
  real_T Sum2;                         /* '<S1>/Sum2' */
  real_T index_out;                    /* '<S8>/MATLAB Function' */
  real_T index_out_n;                  /* '<S8>/Chart' */
  real_T x;                            /* '<S10>/MATLAB Function' */
} B_SingleCylinderTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S8>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay1_DSTATE_o;          /* '<S7>/Unit Delay1' */
  real_T Integrator_DSTATE;            /* '<S3>/Integrator' */
  real_T Filter_DSTATE;                /* '<S3>/Filter' */
  uint8_T is_active_c3_SingleCylinderTest;/* '<S8>/Chart' */
  uint8_T is_c3_SingleCylinderTest;    /* '<S8>/Chart' */
} DW_SingleCylinderTest_T;

/* Parameters (auto storage) */
struct P_SingleCylinderTest_T_ {
  real_T DiscretePIDController_D;      /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S3>/Derivative Gain'
                                        */
  real_T DiscretePIDController_I;      /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S3>/Integral Gain'
                                        */
  real_T DiscretePIDController_LowerSatu;/* Mask Parameter: DiscretePIDController_LowerSatu
                                          * Referenced by:
                                          *   '<S3>/Saturation'
                                          *   '<S6>/DeadZone'
                                          */
  real_T DiscretePIDController_N;      /* Mask Parameter: DiscretePIDController_N
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  real_T DiscretePIDController_P;      /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S3>/Proportional Gain'
                                        */
  real_T DiscretePIDController_UpperSatu;/* Mask Parameter: DiscretePIDController_UpperSatu
                                          * Referenced by:
                                          *   '<S3>/Saturation'
                                          *   '<S6>/DeadZone'
                                          */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S4>/PWM'
                                        */
  uint32_T PWM_pinNumber_g;            /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S5>/PWM'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay1'
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
                                        * Referenced by: '<S7>/Unit Delay1'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Normalize_Gain;               /* Expression: 1/5
                                        * Referenced by: '<S1>/Normalize'
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
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Gain_Gain;                    /* Expression: 0
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint32_T AnalogInput_p1;             /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  uint16_T SetTo01_Gain;               /* Computed Parameter: SetTo01_Gain
                                        * Referenced by: '<S1>/Set To (0, 1)'
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
 * '<S3>'   : 'SingleCylinderTest/Cylinder PID/Discrete PID Controller'
 * '<S4>'   : 'SingleCylinderTest/Cylinder PID/PWM'
 * '<S5>'   : 'SingleCylinderTest/Cylinder PID/PWM1'
 * '<S6>'   : 'SingleCylinderTest/Cylinder PID/Discrete PID Controller/Clamping circuit'
 * '<S7>'   : 'SingleCylinderTest/High Level System Controller/System Model'
 * '<S8>'   : 'SingleCylinderTest/High Level System Controller/System Model/State Machine'
 * '<S9>'   : 'SingleCylinderTest/High Level System Controller/System Model/Threshold'
 * '<S10>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/Calculate Foot Position'
 * '<S11>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/Chart'
 * '<S12>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/MATLAB Function'
 * '<S13>'  : 'SingleCylinderTest/High Level System Controller/System Model/State Machine/Calculate Foot Position/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_SingleCylinderTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
