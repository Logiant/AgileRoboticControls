/*
 * File: XbeeSerial.h
 *
 * Code generated for Simulink model 'XbeeSerial'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed May 06 22:44:51 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_XbeeSerial_h_
#define RTW_HEADER_XbeeSerial_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef XbeeSerial_COMMON_INCLUDES_
# define XbeeSerial_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_serialwrite_lct.h"
#endif                                 /* XbeeSerial_COMMON_INCLUDES_ */

#include "XbeeSerial_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Output;                       /* '<S1>/Output' */
  uint8_T DataTypeConversion;          /* '<Root>/Data Type Conversion' */
} B_XbeeSerial_T;

/* Parameters (auto storage) */
struct P_XbeeSerial_T_ {
  real_T Ramp_X0;                      /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Ramp_slope;                   /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Ramp_start;                   /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S1>/Step'
                                        */
  uint32_T SerialTransmit_portNumber;  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_XbeeSerial_T {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_XbeeSerial_T XbeeSerial_P;

/* Block signals (auto storage) */
extern B_XbeeSerial_T XbeeSerial_B;

/* Model entry point functions */
extern void XbeeSerial_initialize(void);
extern void XbeeSerial_output(void);
extern void XbeeSerial_update(void);
extern void XbeeSerial_terminate(void);

/* Real-time Model object */
extern RT_MODEL_XbeeSerial_T *const XbeeSerial_M;

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
 * '<Root>' : 'XbeeSerial'
 * '<S1>'   : 'XbeeSerial/Ramp'
 */
#endif                                 /* RTW_HEADER_XbeeSerial_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
