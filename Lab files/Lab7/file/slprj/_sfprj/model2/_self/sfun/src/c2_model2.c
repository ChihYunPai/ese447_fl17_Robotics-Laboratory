/* Include files */

#include "blascompat32.h"
#include "model2_sfun.h"
#include "c2_model2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "model2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[13] = { "point_a", "point_b",
  "point_c", "point_d", "currentState", "nargin", "nargout", "q2", "q2dot",
  "interval_1", "interval_2", "oldControl", "control" };

/* Function Declarations */
static void initialize_c2_model2(SFc2_model2InstanceStruct *chartInstance);
static void initialize_params_c2_model2(SFc2_model2InstanceStruct *chartInstance);
static void enable_c2_model2(SFc2_model2InstanceStruct *chartInstance);
static void disable_c2_model2(SFc2_model2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_model2(SFc2_model2InstanceStruct
  *chartInstance);
static void ext_mode_exec_c2_model2(SFc2_model2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_model2(SFc2_model2InstanceStruct
  *chartInstance);
static void set_sim_state_c2_model2(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_model2(SFc2_model2InstanceStruct *chartInstance);
static void sf_c2_model2(SFc2_model2InstanceStruct *chartInstance);
static void c2_chartstep_c2_model2(SFc2_model2InstanceStruct *chartInstance);
static void initSimStructsc2_model2(SFc2_model2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_control, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[14]);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_is_active_c2_model2, const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_model2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_model2(SFc2_model2InstanceStruct *chartInstance)
{
  int32_T *c2_sfEvent;
  uint8_T *c2_is_active_c2_model2;
  c2_is_active_c2_model2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_is_active_c2_model2 = 0U;
}

static void initialize_params_c2_model2(SFc2_model2InstanceStruct *chartInstance)
{
}

static void enable_c2_model2(SFc2_model2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_model2(SFc2_model2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_model2(SFc2_model2InstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c2_model2(SFc2_model2InstanceStruct *chartInstance)
{
  c2_update_debugger_state_c2_model2(chartInstance);
}

static const mxArray *get_sim_state_c2_model2(SFc2_model2InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_control;
  uint8_T *c2_is_active_c2_model2;
  c2_control = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_model2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  c2_hoistedGlobal = *c2_control;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_is_active_c2_model2;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_model2(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  boolean_T *c2_doneDoubleBufferReInit;
  real_T *c2_control;
  uint8_T *c2_is_active_c2_model2;
  c2_control = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_model2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_control = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "control");
  *c2_is_active_c2_model2 = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "is_active_c2_model2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_model2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_model2(SFc2_model2InstanceStruct *chartInstance)
{
}

static void sf_c2_model2(SFc2_model2InstanceStruct *chartInstance)
{
  int32_T *c2_sfEvent;
  real_T *c2_q2;
  real_T *c2_control;
  real_T *c2_q2dot;
  real_T *c2_interval_1;
  real_T *c2_interval_2;
  real_T *c2_oldControl;
  c2_oldControl = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_interval_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_interval_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_q2dot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_control = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, *c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_q2, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_control, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_q2dot, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_interval_1, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_interval_2, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_oldControl, 5U);
  *c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_model2(chartInstance);
  sf_debug_check_for_state_inconsistency(_model2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_model2(SFc2_model2InstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_q2;
  real_T c2_q2dot;
  real_T c2_interval_1;
  real_T c2_interval_2;
  real_T c2_oldControl;
  uint32_T c2_debug_family_var_map[13];
  real_T c2_point_a;
  real_T c2_point_b;
  real_T c2_point_c;
  real_T c2_point_d;
  real_T c2_currentState;
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 1.0;
  real_T c2_control;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_y;
  real_T c2_e_x;
  real_T c2_b_y;
  real_T c2_f_x;
  real_T c2_a;
  real_T c2_c_y;
  real_T c2_A;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_b_a;
  real_T c2_d_y;
  real_T c2_b_A;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_c_a;
  real_T c2_e_y;
  real_T c2_c_A;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_d_a;
  real_T c2_f_y;
  real_T c2_d_A;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_g_y;
  real_T *c2_b_oldControl;
  real_T *c2_b_interval_2;
  real_T *c2_b_interval_1;
  real_T *c2_b_q2dot;
  real_T *c2_b_q2;
  real_T *c2_b_control;
  int32_T *c2_sfEvent;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T guard7 = FALSE;
  boolean_T guard8 = FALSE;
  c2_b_oldControl = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_interval_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_interval_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_q2dot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_control = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, *c2_sfEvent);
  c2_hoistedGlobal = *c2_b_q2;
  c2_b_hoistedGlobal = *c2_b_q2dot;
  c2_c_hoistedGlobal = *c2_b_interval_1;
  c2_d_hoistedGlobal = *c2_b_interval_2;
  c2_e_hoistedGlobal = *c2_b_oldControl;
  c2_q2 = c2_hoistedGlobal;
  c2_q2dot = c2_b_hoistedGlobal;
  c2_interval_1 = c2_c_hoistedGlobal;
  c2_interval_2 = c2_d_hoistedGlobal;
  c2_oldControl = c2_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_point_a, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_point_b, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_point_c, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_point_d, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_currentState, 4U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_q2, 7U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q2dot, 8U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_interval_1, 9U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_interval_2, 10U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_oldControl, 11U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_control, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c2_sfEvent, 4);
  c2_q2 -= 3.1415926535897931;
  _SFD_EML_CALL(0U, *c2_sfEvent, 5);
  c2_x = c2_q2;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarSin(c2_b_x);
  c2_c_x = c2_q2;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarCos(c2_d_x);
  c2_y = c2_b_x;
  c2_e_x = c2_d_x;
  c2_b_y = c2_y;
  c2_f_x = c2_e_x;
  c2_q2 = muDoubleScalarAtan2(c2_b_y, c2_f_x);
  _SFD_EML_CALL(0U, *c2_sfEvent, 7);
  c2_a = 180.0 - c2_interval_1;
  c2_c_y = c2_a * 3.1415926535897931;
  c2_A = c2_c_y;
  c2_g_x = c2_A;
  c2_h_x = c2_g_x;
  c2_point_a = c2_h_x / 180.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 8);
  c2_b_a = -180.0 + c2_interval_1;
  c2_d_y = c2_b_a * 3.1415926535897931;
  c2_b_A = c2_d_y;
  c2_i_x = c2_b_A;
  c2_j_x = c2_i_x;
  c2_point_b = c2_j_x / 180.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 9);
  c2_c_a = -c2_interval_2;
  c2_e_y = c2_c_a * 3.1415926535897931;
  c2_c_A = c2_e_y;
  c2_k_x = c2_c_A;
  c2_l_x = c2_k_x;
  c2_point_c = c2_l_x / 180.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 10);
  c2_d_a = c2_interval_2;
  c2_f_y = c2_d_a * 3.1415926535897931;
  c2_d_A = c2_f_y;
  c2_m_x = c2_d_A;
  c2_n_x = c2_m_x;
  c2_point_d = c2_n_x / 180.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 13);
  guard5 = FALSE;
  if (CV_EML_COND(0, 1, 0, c2_q2 > c2_point_c)) {
    if (CV_EML_COND(0, 1, 1, c2_q2 < c2_point_d)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 0, TRUE);
      _SFD_EML_CALL(0U, *c2_sfEvent, 14);
      c2_currentState = 1.0;
    } else {
      guard5 = TRUE;
    }
  } else {
    guard5 = TRUE;
  }

  if (guard5 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, *c2_sfEvent, 15);
    guard6 = FALSE;
    guard7 = FALSE;
    guard8 = FALSE;
    if (CV_EML_COND(0, 1, 2, c2_q2 > c2_point_d)) {
      if (CV_EML_COND(0, 1, 3, c2_q2 < c2_point_a)) {
        guard7 = TRUE;
      } else {
        guard8 = TRUE;
      }
    } else {
      guard8 = TRUE;
    }

    if (guard8 == TRUE) {
      if (CV_EML_COND(0, 1, 4, c2_q2 > c2_point_b)) {
        if (CV_EML_COND(0, 1, 5, c2_q2 < c2_point_c)) {
          guard7 = TRUE;
        } else {
          guard6 = TRUE;
        }
      } else {
        guard6 = TRUE;
      }
    }

    if (guard7 == TRUE) {
      CV_EML_MCDC(0, 1, 1, TRUE);
      CV_EML_IF(0, 1, 1, TRUE);
      _SFD_EML_CALL(0U, *c2_sfEvent, 16);
      c2_currentState = 2.0;
    }

    if (guard6 == TRUE) {
      CV_EML_MCDC(0, 1, 1, FALSE);
      CV_EML_IF(0, 1, 1, FALSE);
      _SFD_EML_CALL(0U, *c2_sfEvent, 18);
      c2_currentState = 3.0;
    }
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 21);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 6, c2_oldControl == 1.0)) {
    if (CV_EML_COND(0, 1, 7, c2_currentState == 3.0)) {
      CV_EML_MCDC(0, 1, 2, TRUE);
      CV_EML_IF(0, 1, 2, TRUE);
      _SFD_EML_CALL(0U, *c2_sfEvent, 22);
      c2_control = 3.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 2, FALSE);
    CV_EML_IF(0, 1, 2, FALSE);
    _SFD_EML_CALL(0U, *c2_sfEvent, 23);
    guard2 = FALSE;
    guard3 = FALSE;
    if (CV_EML_COND(0, 1, 8, c2_oldControl == 2.0)) {
      if (CV_EML_COND(0, 1, 9, c2_currentState == 1.0)) {
        c2_o_x = c2_q2dot;
        c2_p_x = c2_o_x;
        c2_g_y = muDoubleScalarAbs(c2_p_x);
        if (CV_EML_COND(0, 1, 10, c2_g_y < 0.5)) {
          CV_EML_MCDC(0, 1, 3, TRUE);
          CV_EML_IF(0, 1, 3, TRUE);
          _SFD_EML_CALL(0U, *c2_sfEvent, 24);
          c2_control = 1.0;
        } else {
          guard2 = TRUE;
        }
      } else {
        guard3 = TRUE;
      }
    } else {
      guard3 = TRUE;
    }

    if (guard3 == TRUE) {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(0, 1, 3, FALSE);
      CV_EML_IF(0, 1, 3, FALSE);
      _SFD_EML_CALL(0U, *c2_sfEvent, 25);
      guard4 = FALSE;
      if (CV_EML_COND(0, 1, 11, c2_oldControl == 3.0)) {
        if (CV_EML_COND(0, 1, 12, c2_currentState == 2.0)) {
          CV_EML_MCDC(0, 1, 4, TRUE);
          CV_EML_IF(0, 1, 4, TRUE);
          _SFD_EML_CALL(0U, *c2_sfEvent, 26);
          c2_control = 2.0;
        } else {
          guard4 = TRUE;
        }
      } else {
        guard4 = TRUE;
      }

      if (guard4 == TRUE) {
        CV_EML_MCDC(0, 1, 4, FALSE);
        CV_EML_IF(0, 1, 4, FALSE);
        _SFD_EML_CALL(0U, *c2_sfEvent, 28);
        c2_control = c2_oldControl;
      }
    }
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, -28);
  sf_debug_symbol_scope_pop();
  *c2_b_control = c2_control;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c2_sfEvent);
}

static void initSimStructsc2_model2(SFc2_model2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_model2InstanceStruct *chartInstance;
  chartInstance = (SFc2_model2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_control, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_control), &c2_thisId);
  sf_mex_destroy(&c2_control);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_control;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_model2InstanceStruct *chartInstance;
  chartInstance = (SFc2_model2InstanceStruct *)chartInstanceVoid;
  c2_control = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_control), &c2_thisId);
  sf_mex_destroy(&c2_control);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_model2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[14];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c2_i0 = 0; c2_i0 < 14; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[14])
{
  c2_info[0].context = "";
  c2_info[0].name = "sin";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[0].fileTimeLo = 1286843950U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[1].name = "eml_scalar_sin";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[1].fileTimeLo = 1286843936U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "cos";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[2].fileTimeLo = 1286843906U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[3].name = "eml_scalar_cos";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[3].fileTimeLo = 1286843922U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "atan2";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[4].fileTimeLo = 1286843904U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[5].name = "eml_scalar_eg";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[5].fileTimeLo = 1286843996U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[6].name = "eml_scalexp_alloc";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[6].fileTimeLo = 1330633634U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[7].name = "eml_scalar_atan2";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c2_info[7].fileTimeLo = 1286843920U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "";
  c2_info[8].name = "mtimes";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[8].fileTimeLo = 1289544892U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "mrdivide";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[9].fileTimeLo = 1342836144U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 1319755166U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[10].name = "rdivide";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[10].fileTimeLo = 1286844044U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[11].name = "eml_div";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[11].fileTimeLo = 1313373010U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "";
  c2_info[12].name = "abs";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[12].fileTimeLo = 1286843894U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[13].name = "eml_scalar_abs";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[13].fileTimeLo = 1286843912U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_model2InstanceStruct *chartInstance;
  chartInstance = (SFc2_model2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_model2InstanceStruct *chartInstance;
  chartInstance = (SFc2_model2InstanceStruct *)chartInstanceVoid;
  c2_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_is_active_c2_model2, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_is_active_c2_model2),
    &c2_thisId);
  sf_mex_destroy(&c2_is_active_c2_model2);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_model2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_model2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c2_model2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3604766577U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1016058380U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3674598082U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2320838779U);
}

mxArray *sf_c2_model2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MjLKtV4V4Y3szbIOl6lr9G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_model2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"control\",},{M[8],M[0],T\"is_active_c2_model2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_model2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_model2InstanceStruct *chartInstance;
    chartInstance = (SFc2_model2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_model2MachineNumber_,
          2,
          1,
          1,
          6,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_model2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_model2MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_model2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"q2");
          _SFD_SET_DATA_PROPS(1,2,0,1,"control");
          _SFD_SET_DATA_PROPS(2,1,1,0,"q2dot");
          _SFD_SET_DATA_PROPS(3,1,1,0,"interval_1");
          _SFD_SET_DATA_PROPS(4,1,1,0,"interval_2");
          _SFD_SET_DATA_PROPS(5,1,1,0,"oldControl");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,0,0,13,5);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,718);
        _SFD_CV_INIT_EML_IF(0,1,0,299,331,354,477);
        _SFD_CV_INIT_EML_IF(0,1,1,354,424,447,477);
        _SFD_CV_INIT_EML_IF(0,1,2,479,518,538,714);
        _SFD_CV_INIT_EML_IF(0,1,3,538,601,619,714);
        _SFD_CV_INIT_EML_IF(0,1,4,619,662,680,714);

        {
          static int condStart[] = { 302, 318 };

          static int condEnd[] = { 314, 330 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,302,330,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 362, 378, 394, 410 };

          static int condEnd[] = { 374, 390, 406, 422 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,361,423,4,2,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 482, 501 };

          static int condEnd[] = { 497, 518 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,482,518,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 545, 564, 585 };

          static int condEnd[] = { 560, 581, 601 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,545,601,3,8,&(condStart[0]),&(condEnd[0]),
                                5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 626, 645 };

          static int condEnd[] = { 641, 662 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4,626,662,2,11,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_q2;
          real_T *c2_control;
          real_T *c2_q2dot;
          real_T *c2_interval_1;
          real_T *c2_interval_2;
          real_T *c2_oldControl;
          c2_oldControl = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_interval_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_interval_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_q2dot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_control = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_q2);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_control);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_q2dot);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_interval_1);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_interval_2);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_oldControl);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_model2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "EUlQik9y4NEtcKf9g50ZaG";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_model2_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 2, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c2_model2(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc2_model2InstanceStruct*) chartInstanceVar)->S);
  chart_debug_initialization(((SFc2_model2InstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c2_model2((SFc2_model2InstanceStruct*) chartInstanceVar);
  initialize_c2_model2((SFc2_model2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_model2(void *chartInstanceVar)
{
  enable_c2_model2((SFc2_model2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_model2(void *chartInstanceVar)
{
  disable_c2_model2((SFc2_model2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_model2(void *chartInstanceVar)
{
  sf_c2_model2((SFc2_model2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c2_model2(void *chartInstanceVar)
{
  ext_mode_exec_c2_model2((SFc2_model2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_model2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_model2((SFc2_model2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_model2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_model2(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_model2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_model2((SFc2_model2InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_model2(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_model2(S);
}

static void sf_opaque_set_sim_state_c2_model2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_model2(S, st);
}

static void sf_opaque_terminate_c2_model2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_model2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_model2((SFc2_model2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_model2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_model2((SFc2_model2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_model2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_model2((SFc2_model2InstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c2_model2_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c2_model2\",T\"is_active_c2_model2\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3851270630U, 3363230343U, 1651207761U,
    946165807U };

  return checksum;
}

static void mdlSetWorkWidths_c2_model2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_model2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(977224098U));
  ssSetChecksum1(S,(2080960695U));
  ssSetChecksum2(S,(3052772645U));
  ssSetChecksum3(S,(1180484465U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_model2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_model2(SimStruct *S)
{
  SFc2_model2InstanceStruct *chartInstance;
  chartInstance = (SFc2_model2InstanceStruct *)malloc(sizeof
    (SFc2_model2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_model2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_model2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_model2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_model2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_model2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_model2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_model2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_model2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_model2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_model2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_model2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_model2;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c2_model2;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_model2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_model2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_model2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_model2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_model2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
