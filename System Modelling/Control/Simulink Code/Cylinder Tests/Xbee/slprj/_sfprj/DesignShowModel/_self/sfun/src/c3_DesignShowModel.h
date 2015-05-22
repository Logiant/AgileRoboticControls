#ifndef __c3_DesignShowModel_h__
#define __c3_DesignShowModel_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_DesignShowModelInstanceStruct
#define typedef_SFc3_DesignShowModelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_Idle;
  uint8_T c3_tp_Reverse;
  uint8_T c3_tp_Forward;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_DesignShowModel;
  uint8_T c3_is_c3_DesignShowModel;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_DesignShowModelInstanceStruct;

#endif                                 /*typedef_SFc3_DesignShowModelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_DesignShowModel_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_DesignShowModel_get_check_sum(mxArray *plhs[]);
extern void c3_DesignShowModel_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
