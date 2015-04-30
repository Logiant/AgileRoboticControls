/*
 * File: RetractExpandCommand.h
 *
 * Code generated for Simulink model 'RetractExpandCommand'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed Apr 29 19:53:38 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RetractExpandCommand_h_
#define RTW_HEADER_RetractExpandCommand_h_
#include <stddef.h>
#ifndef RetractExpandCommand_COMMON_INCLUDES_
# define RetractExpandCommand_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* RetractExpandCommand_COMMON_INCLUDES_ */

#include "RetractExpandCommand_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_RetractExpandCommand_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S1>/PWM'
                                        */
  uint32_T PWM_pinNumber_m;            /* Mask Parameter: PWM_pinNumber_m
                                        * Referenced by: '<S2>/PWM'
                                        */
  real_T Constant1_Value;              /* Expression: 256
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_RetractExpandCommand_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_RetractExpandCommand_T RetractExpandCommand_P;

/* Model entry point functions */
extern void RetractExpandCommand_initialize(void);
extern void RetractExpandCommand_output(void);
extern void RetractExpandCommand_update(void);
extern void RetractExpandCommand_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RetractExpandCommand_T *const RetractExpandCommand_M;

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
 * '<Root>' : 'RetractExpandCommand'
 * '<S1>'   : 'RetractExpandCommand/Extend Command'
 * '<S2>'   : 'RetractExpandCommand/Retract Command'
 */
#endif                                 /* RTW_HEADER_RetractExpandCommand_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
