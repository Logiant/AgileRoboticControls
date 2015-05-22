/*
 * File: XbeeSerialRead.h
 *
 * Code generated for Simulink model 'XbeeSerialRead'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 15 02:40:34 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_XbeeSerialRead_h_
#define RTW_HEADER_XbeeSerialRead_h_
#include <stddef.h>
#include <string.h>
#ifndef XbeeSerialRead_COMMON_INCLUDES_
# define XbeeSerialRead_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_serialread_lct.h"
#include "arduino_analogoutput_lct.h"
#include "arduino_serialwrite_lct.h"
#endif                                 /* XbeeSerialRead_COMMON_INCLUDES_ */

#include "XbeeSerialRead_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Switch;                       /* '<Root>/Switch' */
} B_XbeeSerialRead_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
} DW_XbeeSerialRead_T;

/* Parameters (auto storage) */
struct P_XbeeSerialRead_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S1>/PWM'
                                        */
  uint32_T SerialTransmit_portNumber;  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S2>/Serial Transmit'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Header_Value;                 /* Expression: 173
                                        * Referenced by: '<S2>/Header'
                                        */
  real_T Footer1_Value;                /* Expression: 1
                                        * Referenced by: '<S2>/Footer 1'
                                        */
  real_T Footer2_Value;                /* Expression: 1
                                        * Referenced by: '<S2>/Footer 2'
                                        */
  uint32_T SerialReceive_p1;           /* Computed Parameter: SerialReceive_p1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  int16_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<Root>/Switch'
                                        */
  boolean_T SerialReceive_p2;          /* Computed Parameter: SerialReceive_p2
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_XbeeSerialRead_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_XbeeSerialRead_T XbeeSerialRead_P;

/* Block signals (auto storage) */
extern B_XbeeSerialRead_T XbeeSerialRead_B;

/* Block states (auto storage) */
extern DW_XbeeSerialRead_T XbeeSerialRead_DW;

/* Model entry point functions */
extern void XbeeSerialRead_initialize(void);
extern void XbeeSerialRead_output(void);
extern void XbeeSerialRead_update(void);
extern void XbeeSerialRead_terminate(void);

/* Real-time Model object */
extern RT_MODEL_XbeeSerialRead_T *const XbeeSerialRead_M;

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
 * '<Root>' : 'XbeeSerialRead'
 * '<S1>'   : 'XbeeSerialRead/PWM'
 * '<S2>'   : 'XbeeSerialRead/Send Message'
 */
#endif                                 /* RTW_HEADER_XbeeSerialRead_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
