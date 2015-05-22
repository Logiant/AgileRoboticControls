/* Include files */

#include "SingleCylinderTest_sfun.h"
#include "SingleCylinderTest_sfun_debug_macros.h"
#include "c1_SingleCylinderTest.h"
#include "c3_SingleCylinderTest.h"
#include "c4_SingleCylinderTest.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _SingleCylinderTestMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void SingleCylinderTest_initializer(void)
{
}

void SingleCylinderTest_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_SingleCylinderTest_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_SingleCylinderTest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_SingleCylinderTest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_SingleCylinderTest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_SingleCylinderTest_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2945987373U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(88383576U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1879860135U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(171161406U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3124961596U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(128470221U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2803917443U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1781913324U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_SingleCylinderTest_get_check_sum(mxArray *plhs[]);
          sf_c1_SingleCylinderTest_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_SingleCylinderTest_get_check_sum(mxArray *plhs[]);
          sf_c3_SingleCylinderTest_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_SingleCylinderTest_get_check_sum(mxArray *plhs[]);
          sf_c4_SingleCylinderTest_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(581429910U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2374367879U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(219780377U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1216069927U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3423971248U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1526693630U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2677811569U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1269209555U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SingleCylinderTest_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "QeBjb5Aq2GdPf6Pu15V7VG") == 0) {
          extern mxArray *sf_c1_SingleCylinderTest_get_autoinheritance_info(void);
          plhs[0] = sf_c1_SingleCylinderTest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "54ef0P4npsKzK4b9xLAZaD") == 0) {
          extern mxArray *sf_c3_SingleCylinderTest_get_autoinheritance_info(void);
          plhs[0] = sf_c3_SingleCylinderTest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "W3HVDWo7L4PdgZbFJnPAf") == 0) {
          extern mxArray *sf_c4_SingleCylinderTest_get_autoinheritance_info(void);
          plhs[0] = sf_c4_SingleCylinderTest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SingleCylinderTest_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_SingleCylinderTest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_SingleCylinderTest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_SingleCylinderTest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_SingleCylinderTest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_SingleCylinderTest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_SingleCylinderTest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SingleCylinderTest_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "JLDHc8DCUd6XsgTZdf2dtF") == 0) {
          extern mxArray *sf_c1_SingleCylinderTest_third_party_uses_info(void);
          plhs[0] = sf_c1_SingleCylinderTest_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ra4QoEo9c3foXxwjniAvIC") == 0) {
          extern mxArray *sf_c3_SingleCylinderTest_third_party_uses_info(void);
          plhs[0] = sf_c3_SingleCylinderTest_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "U89GILYXf8x1sV6ZOgDetD") == 0) {
          extern mxArray *sf_c4_SingleCylinderTest_third_party_uses_info(void);
          plhs[0] = sf_c4_SingleCylinderTest_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_SingleCylinderTest_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "JLDHc8DCUd6XsgTZdf2dtF") == 0) {
          extern mxArray *sf_c1_SingleCylinderTest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c1_SingleCylinderTest_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ra4QoEo9c3foXxwjniAvIC") == 0) {
          extern mxArray *sf_c3_SingleCylinderTest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c3_SingleCylinderTest_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "U89GILYXf8x1sV6ZOgDetD") == 0) {
          extern mxArray *sf_c4_SingleCylinderTest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c4_SingleCylinderTest_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void SingleCylinderTest_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _SingleCylinderTestMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "SingleCylinderTest","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _SingleCylinderTestMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _SingleCylinderTestMachineNumber_,0);
}

void SingleCylinderTest_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_SingleCylinderTest_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "SingleCylinderTest", "SingleCylinderTest");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_SingleCylinderTest_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
