/*
 * File: XbeeIO.h
 *
 * Code generated for Simulink model 'XbeeIO'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed May 06 22:02:41 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_XbeeIO_h_
#define RTW_HEADER_XbeeIO_h_
#include <stddef.h>
#ifndef XbeeIO_COMMON_INCLUDES_
# define XbeeIO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* XbeeIO_COMMON_INCLUDES_ */

#include "XbeeIO_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_XbeeIO_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S1>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_j;  /* Mask Parameter: DigitalOutput_pinNumber_j
                                        * Referenced by: '<S2>/Digital Output'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_XbeeIO_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_XbeeIO_T XbeeIO_P;

/* Model entry point functions */
extern void XbeeIO_initialize(void);
extern void XbeeIO_output(void);
extern void XbeeIO_update(void);
extern void XbeeIO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_XbeeIO_T *const XbeeIO_M;

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
 * '<Root>' : 'XbeeIO'
 * '<S1>'   : 'XbeeIO/Digital Output'
 * '<S2>'   : 'XbeeIO/Digital Output1'
 */
#endif                                 /* RTW_HEADER_XbeeIO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
