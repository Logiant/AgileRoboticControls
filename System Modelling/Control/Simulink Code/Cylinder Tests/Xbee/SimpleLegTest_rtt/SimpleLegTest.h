/*
 * File: SimpleLegTest.h
 *
 * Code generated for Simulink model 'SimpleLegTest'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 22 13:26:11 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SimpleLegTest_h_
#define RTW_HEADER_SimpleLegTest_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef SimpleLegTest_COMMON_INCLUDES_
# define SimpleLegTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_serialread_lct.h"
#include "arduino_analogoutput_lct.h"
#include "arduino_serialwrite_lct.h"
#endif                                 /* SimpleLegTest_COMMON_INCLUDES_ */

#include "SimpleLegTest_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  uint8_T Switch;                      /* '<Root>/Switch' */
} B_SimpleLegTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T UnitDelay_DSTATE;            /* '<Root>/Unit Delay' */
} DW_SimpleLegTest_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T FinalVoltage01;               /* '<Root>/Final Voltage (0, 1)' */
} ExtY_SimpleLegTest_T;

/* Parameters (auto storage) */
struct P_SimpleLegTest_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S1>/PWM'
                                        */
  uint32_T PWM_pinNumber_p;            /* Mask Parameter: PWM_pinNumber_p
                                        * Referenced by: '<S2>/PWM'
                                        */
  uint32_T PWM_pinNumber_l;            /* Mask Parameter: PWM_pinNumber_l
                                        * Referenced by: '<S3>/PWM'
                                        */
  uint32_T SerialTransmit_portNumber;  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S4>/Serial Transmit'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 2
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant1_Value_n;            /* Expression: 128
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Header_Value;                 /* Expression: 173
                                        * Referenced by: '<S4>/Header'
                                        */
  real_T Footer1_Value;                /* Expression: 1
                                        * Referenced by: '<S4>/Footer 1'
                                        */
  real_T Footer2_Value;                /* Expression: 16
                                        * Referenced by: '<S4>/Footer 2'
                                        */
  uint32_T SerialReceive_p1;           /* Computed Parameter: SerialReceive_p1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  int16_T Switch_Threshold_i;          /* Computed Parameter: Switch_Threshold_i
                                        * Referenced by: '<Root>/Switch'
                                        */
  uint8_T UnitDelay_InitialCondition;  /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  boolean_T SerialReceive_p2;          /* Computed Parameter: SerialReceive_p2
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SimpleLegTest_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_SimpleLegTest_T SimpleLegTest_P;

/* Block signals (auto storage) */
extern B_SimpleLegTest_T SimpleLegTest_B;

/* Block states (auto storage) */
extern DW_SimpleLegTest_T SimpleLegTest_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_SimpleLegTest_T SimpleLegTest_Y;

/* Model entry point functions */
extern void SimpleLegTest_initialize(void);
extern void SimpleLegTest_output(void);
extern void SimpleLegTest_update(void);
extern void SimpleLegTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SimpleLegTest_T *const SimpleLegTest_M;

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
 * '<Root>' : 'SimpleLegTest'
 * '<S1>'   : 'SimpleLegTest/Extend Command'
 * '<S2>'   : 'SimpleLegTest/PWM'
 * '<S3>'   : 'SimpleLegTest/Retract Command'
 * '<S4>'   : 'SimpleLegTest/Send Message'
 * '<S5>'   : 'SimpleLegTest/Split Signal'
 */
#endif                                 /* RTW_HEADER_SimpleLegTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
