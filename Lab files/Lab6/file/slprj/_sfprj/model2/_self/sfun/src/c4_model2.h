#ifndef __c4_model2_h__
#define __c4_model2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc4_model2InstanceStruct
#define typedef_SFc4_model2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc4_model2InstanceStruct;

#endif                                 /*typedef_SFc4_model2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_model2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_model2_get_check_sum(mxArray *plhs[]);
extern void c4_model2_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
