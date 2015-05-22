/*
 * File: DesignShowModel.h
 *
 * Code generated for Simulink model 'DesignShowModel'.
 *
 * Model version                  : 1.128
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 22 12:35:13 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DesignShowModel_h_
#define RTW_HEADER_DesignShowModel_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef DesignShowModel_COMMON_INCLUDES_
# define DesignShowModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analoginput_lct.h"
#include "arduino_serialread_lct.h"
#include "arduino_serialwrite_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* DesignShowModel_COMMON_INCLUDES_ */

#include "DesignShowModel_types.h"

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
  real_T Sum2;                         /* '<S4>/Sum2' */
  real_T index_out;                    /* '<S6>/MATLAB Function' */
  real_T index_out_n;                  /* '<S6>/Chart' */
  real_T x;                            /* '<S8>/MATLAB Function' */
} B_DesignShowModel_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S6>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay1_DSTATE_o;          /* '<S5>/Unit Delay1' */
  uint8_T is_active_c3_DesignShowModel;/* '<S6>/Chart' */
  uint8_T is_c3_DesignShowModel;       /* '<S6>/Chart' */
} DW_DesignShowModel_T;

/* Parameters (auto storage) */
struct P_DesignShowModel_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S12>/PWM'
                                        */
  uint32_T PWM_pinNumber_n;            /* Mask Parameter: PWM_pinNumber_n
                                        * Referenced by: '<S13>/PWM'
                                        */
  uint32_T PWM_pinNumber_p;            /* Mask Parameter: PWM_pinNumber_p
                                        * Referenced by: '<S15>/PWM'
                                        */
  uint32_T PWM_pinNumber_g;            /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S16>/PWM'
                                        */
  uint32_T SerialTransmit_portNumber;  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S2>/Serial Transmit'
                                        */
  real_T NoRequest_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/No Request'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real_T Constant1_Value_j;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Header_Value;                 /* Expression: 173
                                        * Referenced by: '<S2>/Header'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_f;/* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay1'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Normalize_Gain;               /* Expression: 1/5
                                        * Referenced by: '<Root>/Normalize'
                                        */
  real_T ShankOffset_Value;            /* Expression: 1
                                        * Referenced by: '<Root>/Shank Offset'
                                        */
  real_T P_Gain;                       /* Expression: 3000
                                        * Referenced by: '<S4>/P'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S17>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S17>/Constant3'
                                        */
  real_T P_Gain_b;                     /* Expression: 3000
                                        * Referenced by: '<S3>/P'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0
                                        * Referenced by: '<S14>/Switch'
                                        */
  real_T Constant3_Value_i;            /* Expression: 1
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real_T Footer1_Value;                /* Expression: 1
                                        * Referenced by: '<S2>/Footer 1'
                                        */
  real_T Footer2_Value;                /* Expression: 16
                                        * Referenced by: '<S2>/Footer 2'
                                        */
  uint32_T FeedbackVoltage_p1;         /* Computed Parameter: FeedbackVoltage_p1
                                        * Referenced by: '<S4>/Feedback Voltage'
                                        */
  uint32_T SerialReceive_p1;           /* Computed Parameter: SerialReceive_p1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  uint32_T FeedbackVoltage_p1_e;       /* Computed Parameter: FeedbackVoltage_p1_e
                                        * Referenced by: '<S3>/Feedback Voltage'
                                        */
  uint32_T NormalizeFeedback_Gain;     /* Computed Parameter: NormalizeFeedback_Gain
                                        * Referenced by: '<S4>/Normalize Feedback'
                                        */
  int16_T Switch_Threshold_g3;         /* Computed Parameter: Switch_Threshold_g3
                                        * Referenced by: '<Root>/Switch'
                                        */
  uint16_T LengthCompensation_Gain;    /* Computed Parameter: LengthCompensation_Gain
                                        * Referenced by: '<S4>/Length Compensation'
                                        */
  uint16_T NormalizeFeedback_Gain_g;   /* Computed Parameter: NormalizeFeedback_Gain_g
                                        * Referenced by: '<S3>/Normalize Feedback'
                                        */
  boolean_T SerialReceive_p2;          /* Computed Parameter: SerialReceive_p2
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_DesignShowModel_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_DesignShowModel_T DesignShowModel_P;

/* Block signals (auto storage) */
extern B_DesignShowModel_T DesignShowModel_B;

/* Block states (auto storage) */
extern DW_DesignShowModel_T DesignShowModel_DW;

/* Model entry point functions */
extern void DesignShowModel_initialize(void);
extern void DesignShowModel_output(void);
extern void DesignShowModel_update(void);
extern void DesignShowModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DesignShowModel_T *const DesignShowModel_M;

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
 * '<Root>' : 'DesignShowModel'
 * '<S1>'   : 'DesignShowModel/High Level System Controller'
 * '<S2>'   : 'DesignShowModel/Send Message'
 * '<S3>'   : 'DesignShowModel/Shank PID'
 * '<S4>'   : 'DesignShowModel/Thigh PID'
 * '<S5>'   : 'DesignShowModel/High Level System Controller/System Model'
 * '<S6>'   : 'DesignShowModel/High Level System Controller/System Model/State Machine'
 * '<S7>'   : 'DesignShowModel/High Level System Controller/System Model/Threshold'
 * '<S8>'   : 'DesignShowModel/High Level System Controller/System Model/State Machine/Calculate Foot Position'
 * '<S9>'   : 'DesignShowModel/High Level System Controller/System Model/State Machine/Chart'
 * '<S10>'  : 'DesignShowModel/High Level System Controller/System Model/State Machine/MATLAB Function'
 * '<S11>'  : 'DesignShowModel/High Level System Controller/System Model/State Machine/Calculate Foot Position/MATLAB Function'
 * '<S12>'  : 'DesignShowModel/Shank PID/Extend Command'
 * '<S13>'  : 'DesignShowModel/Shank PID/Retract Command'
 * '<S14>'  : 'DesignShowModel/Shank PID/Split Signal'
 * '<S15>'  : 'DesignShowModel/Thigh PID/Extend Command'
 * '<S16>'  : 'DesignShowModel/Thigh PID/Retract Command'
 * '<S17>'  : 'DesignShowModel/Thigh PID/Split Signal'
 */
#endif                                 /* RTW_HEADER_DesignShowModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
