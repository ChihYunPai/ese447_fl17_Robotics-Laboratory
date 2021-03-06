/* Include files */

#include "blascompat32.h"
#include "model2_sfun.h"
#include "c3_model2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "model2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[35] = { "q1", "q1dot", "q2", "q2dot",
  "theta1", "theta2", "theta3", "theta4", "theta5", "theta6", "m11", "m12",
  "m21", "m22", "c11", "c12", "c21", "c22", "f1", "f2", "g", "g1", "g2", "M",
  "C", "F", "G", "qdot", "qdotdot", "Q", "nargin", "nargout", "V", "X", "Xdot" };

/* Function Declarations */
static void initialize_c3_model2(SFc3_model2InstanceStruct *chartInstance);
static void initialize_params_c3_model2(SFc3_model2InstanceStruct *chartInstance);
static void enable_c3_model2(SFc3_model2InstanceStruct *chartInstance);
static void disable_c3_model2(SFc3_model2InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_model2(SFc3_model2InstanceStruct
  *chartInstance);
static void ext_mode_exec_c3_model2(SFc3_model2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_model2(SFc3_model2InstanceStruct
  *chartInstance);
static void set_sim_state_c3_model2(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_st);
static void finalize_c3_model2(SFc3_model2InstanceStruct *chartInstance);
static void sf_c3_model2(SFc3_model2InstanceStruct *chartInstance);
static void c3_chartstep_c3_model2(SFc3_model2InstanceStruct *chartInstance);
static void initSimStructsc3_model2(SFc3_model2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance, const
  mxArray *c3_Xdot, const char_T *c3_identifier, real_T c3_y[4]);
static void c3_b_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_d_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_e_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[30]);
static real_T c3_mpower(SFc3_model2InstanceStruct *chartInstance, real_T c3_a);
static void c3_eml_scalar_eg(SFc3_model2InstanceStruct *chartInstance);
static void c3_eml_warning(SFc3_model2InstanceStruct *chartInstance);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_f_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_is_active_c3_model2, const char_T *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_model2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_model2(SFc3_model2InstanceStruct *chartInstance)
{
  int32_T *c3_sfEvent;
  uint8_T *c3_is_active_c3_model2;
  c3_is_active_c3_model2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c3_is_active_c3_model2 = 0U;
}

static void initialize_params_c3_model2(SFc3_model2InstanceStruct *chartInstance)
{
}

static void enable_c3_model2(SFc3_model2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_model2(SFc3_model2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_model2(SFc3_model2InstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c3_model2(SFc3_model2InstanceStruct *chartInstance)
{
  c3_update_debugger_state_c3_model2(chartInstance);
}

static const mxArray *get_sim_state_c3_model2(SFc3_model2InstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[4];
  const mxArray *c3_b_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T *c3_is_active_c3_model2;
  real_T (*c3_Xdot)[4];
  c3_Xdot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_model2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  for (c3_i0 = 0; c3_i0 < 4; c3_i0++) {
    c3_u[c3_i0] = (*c3_Xdot)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = *c3_is_active_c3_model2;
  c3_b_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_model2(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[4];
  int32_T c3_i1;
  boolean_T *c3_doneDoubleBufferReInit;
  uint8_T *c3_is_active_c3_model2;
  real_T (*c3_Xdot)[4];
  c3_Xdot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_model2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)), "Xdot",
                      c3_dv0);
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    (*c3_Xdot)[c3_i1] = c3_dv0[c3_i1];
  }

  *c3_is_active_c3_model2 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "is_active_c3_model2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_model2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_model2(SFc3_model2InstanceStruct *chartInstance)
{
}

static void sf_c3_model2(SFc3_model2InstanceStruct *chartInstance)
{
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T *c3_sfEvent;
  real_T (*c3_X)[4];
  real_T (*c3_Xdot)[4];
  real_T (*c3_V)[2];
  c3_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c3_Xdot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_V = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, *c3_sfEvent);
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_V)[c3_i2], 0U);
  }

  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    _SFD_DATA_RANGE_CHECK((*c3_Xdot)[c3_i3], 1U);
  }

  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    _SFD_DATA_RANGE_CHECK((*c3_X)[c3_i4], 2U);
  }

  *c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_model2(chartInstance);
  sf_debug_check_for_state_inconsistency(_model2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_model2(SFc3_model2InstanceStruct *chartInstance)
{
  int32_T c3_i5;
  real_T c3_V[2];
  int32_T c3_i6;
  real_T c3_X[4];
  uint32_T c3_debug_family_var_map[35];
  real_T c3_q1;
  real_T c3_q1dot;
  real_T c3_q2;
  real_T c3_q2dot;
  real_T c3_theta1;
  real_T c3_theta2;
  real_T c3_theta3;
  real_T c3_theta4;
  real_T c3_theta5;
  real_T c3_theta6;
  real_T c3_m11;
  real_T c3_m12;
  real_T c3_m21;
  real_T c3_m22;
  real_T c3_c11;
  real_T c3_c12;
  real_T c3_c21;
  real_T c3_c22;
  real_T c3_f1;
  real_T c3_f2;
  real_T c3_g;
  real_T c3_g1;
  real_T c3_g2;
  real_T c3_M[4];
  real_T c3_C[4];
  real_T c3_F[2];
  real_T c3_G[2];
  real_T c3_qdot[2];
  real_T c3_qdotdot[2];
  real_T c3_Q[2];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  real_T c3_Xdot[4];
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_b;
  real_T c3_y;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_b_b;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_c_b;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_d_b;
  real_T c3_b_y;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_a;
  real_T c3_e_b;
  real_T c3_c_y;
  real_T c3_b_a;
  real_T c3_f_b;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_g_b;
  real_T c3_d_y;
  real_T c3_c_a;
  real_T c3_h_b;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_i_b;
  real_T c3_e_y;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_d_a;
  real_T c3_j_b;
  real_T c3_f_y;
  real_T c3_e_a;
  real_T c3_k_b;
  real_T c3_l_b;
  real_T c3_m_b;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_n_b;
  int32_T c3_i7;
  real_T c3_f_a[4];
  int32_T c3_i8;
  real_T c3_o_b[2];
  int32_T c3_i9;
  real_T c3_g_y[2];
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_h_y;
  real_T c3_v_x;
  real_T c3_w_x;
  real_T c3_i_y;
  real_T c3_d;
  real_T c3_x_x;
  real_T c3_y_x;
  real_T c3_ab_x;
  real_T c3_j_y;
  real_T c3_bb_x;
  real_T c3_cb_x;
  real_T c3_k_y;
  real_T c3_b_d;
  int32_T c3_r1;
  int32_T c3_r2;
  real_T c3_db_x;
  real_T c3_l_y;
  real_T c3_a21;
  real_T c3_g_a;
  real_T c3_p_b;
  real_T c3_m_y;
  real_T c3_a22;
  real_T c3_h_a;
  real_T c3_q_b;
  real_T c3_n_y;
  real_T c3_eb_x;
  real_T c3_o_y;
  real_T c3_z;
  real_T c3_i_a;
  real_T c3_r_b;
  real_T c3_p_y;
  real_T c3_fb_x;
  real_T c3_q_y;
  real_T c3_b_z;
  int32_T c3_i14;
  real_T (*c3_b_Xdot)[4];
  real_T (*c3_b_X)[4];
  real_T (*c3_b_V)[2];
  int32_T *c3_sfEvent;
  boolean_T guard1 = FALSE;
  c3_b_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_Xdot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_V = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, *c3_sfEvent);
  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    c3_V[c3_i5] = (*c3_b_V)[c3_i5];
  }

  for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
    c3_X[c3_i6] = (*c3_b_X)[c3_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 35U, 35U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_q1, 0U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_q1dot, 1U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_q2, 2U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_q2dot, 3U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_theta1, 4U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_theta2, 5U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_theta3, 6U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_theta4, 7U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_theta5, 8U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_theta6, 9U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_m11, 10U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_m12, 11U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_m21, 12U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_m22, 13U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_c11, 14U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_c12, 15U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_c21, 16U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_c22, 17U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_f1, 18U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_f2, 19U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_g, 20U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_g1, 21U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_g2, 22U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_M, 23U, c3_e_sf_marshallOut,
    c3_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_C, 24U, c3_e_sf_marshallOut,
    c3_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_F, 25U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_G, 26U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_qdot, 27U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_qdotdot, 28U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_Q, 29U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 30U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 31U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_V, 32U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_X, 33U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_Xdot, 34U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c3_sfEvent, 23);
  c3_q1 = c3_X[0];
  _SFD_EML_CALL(0U, *c3_sfEvent, 24);
  c3_q1dot = c3_X[1];
  _SFD_EML_CALL(0U, *c3_sfEvent, 25);
  c3_q2 = c3_X[2];
  _SFD_EML_CALL(0U, *c3_sfEvent, 26);
  c3_q2dot = c3_X[3];
  _SFD_EML_CALL(0U, *c3_sfEvent, 28);
  c3_theta1 = 0.030372023809524;
  _SFD_EML_CALL(0U, *c3_sfEvent, 29);
  c3_theta2 = 0.018426339285714;
  _SFD_EML_CALL(0U, *c3_sfEvent, 30);
  c3_theta3 = 0.018426339285714;
  _SFD_EML_CALL(0U, *c3_sfEvent, 31);
  c3_theta4 = 0.092131696428571;
  _SFD_EML_CALL(0U, *c3_sfEvent, 32);
  c3_theta5 = 0.610144642857143;
  _SFD_EML_CALL(0U, *c3_sfEvent, 33);
  c3_theta6 = 0.009672619047619;
  _SFD_EML_CALL(0U, *c3_sfEvent, 35);
  c3_x = c3_q2;
  c3_b_x = c3_x;
  c3_b_x = muDoubleScalarSin(c3_b_x);
  c3_b = c3_mpower(chartInstance, c3_b_x);
  c3_y = 0.018426339285714 * c3_b;
  c3_m11 = c3_theta1 + c3_y;
  _SFD_EML_CALL(0U, *c3_sfEvent, 36);
  c3_c_x = c3_q2;
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarCos(c3_d_x);
  c3_b_b = c3_d_x;
  c3_m12 = 0.018426339285714 * c3_b_b;
  _SFD_EML_CALL(0U, *c3_sfEvent, 37);
  c3_e_x = c3_q2;
  c3_f_x = c3_e_x;
  c3_f_x = muDoubleScalarCos(c3_f_x);
  c3_c_b = c3_f_x;
  c3_m21 = 0.018426339285714 * c3_c_b;
  _SFD_EML_CALL(0U, *c3_sfEvent, 38);
  c3_m22 = c3_theta2;
  _SFD_EML_CALL(0U, *c3_sfEvent, 39);
  c3_g_x = c3_q2;
  c3_h_x = c3_g_x;
  c3_h_x = muDoubleScalarSin(c3_h_x);
  c3_d_b = c3_h_x;
  c3_b_y = 0.036852678571428 * c3_d_b;
  c3_i_x = c3_q2;
  c3_j_x = c3_i_x;
  c3_j_x = muDoubleScalarCos(c3_j_x);
  c3_a = c3_b_y;
  c3_e_b = c3_j_x;
  c3_c_y = c3_a * c3_e_b;
  c3_b_a = c3_c_y;
  c3_f_b = c3_q2dot;
  c3_c11 = c3_b_a * c3_f_b;
  _SFD_EML_CALL(0U, *c3_sfEvent, 40);
  c3_k_x = c3_q2;
  c3_l_x = c3_k_x;
  c3_l_x = muDoubleScalarSin(c3_l_x);
  c3_g_b = c3_l_x;
  c3_d_y = -0.018426339285714 * c3_g_b;
  c3_c_a = c3_d_y;
  c3_h_b = c3_q2dot;
  c3_c12 = c3_c_a * c3_h_b;
  _SFD_EML_CALL(0U, *c3_sfEvent, 41);
  c3_m_x = c3_q2;
  c3_n_x = c3_m_x;
  c3_n_x = muDoubleScalarSin(c3_n_x);
  c3_i_b = c3_n_x;
  c3_e_y = -0.018426339285714 * c3_i_b;
  c3_o_x = c3_q2;
  c3_p_x = c3_o_x;
  c3_p_x = muDoubleScalarCos(c3_p_x);
  c3_d_a = c3_e_y;
  c3_j_b = c3_p_x;
  c3_f_y = c3_d_a * c3_j_b;
  c3_e_a = c3_f_y;
  c3_k_b = c3_q1dot;
  c3_c21 = c3_e_a * c3_k_b;
  _SFD_EML_CALL(0U, *c3_sfEvent, 42);
  c3_c22 = 0.0;
  _SFD_EML_CALL(0U, *c3_sfEvent, 43);
  c3_l_b = c3_q1dot;
  c3_f1 = 0.610144642857143 * c3_l_b;
  _SFD_EML_CALL(0U, *c3_sfEvent, 44);
  c3_m_b = c3_q2dot;
  c3_f2 = 0.009672619047619 * c3_m_b;
  _SFD_EML_CALL(0U, *c3_sfEvent, 45);
  c3_g = 9.8;
  _SFD_EML_CALL(0U, *c3_sfEvent, 46);
  c3_g1 = 0.0;
  _SFD_EML_CALL(0U, *c3_sfEvent, 47);
  c3_q_x = c3_q2;
  c3_r_x = c3_q_x;
  c3_r_x = muDoubleScalarSin(c3_r_x);
  c3_n_b = c3_r_x;
  c3_g2 = -0.90289062499999584 * c3_n_b;
  _SFD_EML_CALL(0U, *c3_sfEvent, 49);
  c3_M[0] = c3_m11;
  c3_M[2] = c3_m12;
  c3_M[1] = c3_m21;
  c3_M[3] = c3_m22;
  _SFD_EML_CALL(0U, *c3_sfEvent, 50);
  c3_C[0] = c3_c11;
  c3_C[2] = c3_c12;
  c3_C[1] = c3_c21;
  c3_C[3] = c3_c22;
  _SFD_EML_CALL(0U, *c3_sfEvent, 51);
  c3_F[0] = c3_f1;
  c3_F[1] = c3_f2;
  _SFD_EML_CALL(0U, *c3_sfEvent, 52);
  c3_G[0] = c3_g1;
  c3_G[1] = c3_g2;
  _SFD_EML_CALL(0U, *c3_sfEvent, 53);
  c3_qdot[0] = c3_q1dot;
  c3_qdot[1] = c3_q2dot;
  _SFD_EML_CALL(0U, *c3_sfEvent, 55);
  for (c3_i7 = 0; c3_i7 < 4; c3_i7++) {
    c3_f_a[c3_i7] = c3_C[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
    c3_o_b[c3_i8] = c3_qdot[c3_i8];
  }

  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i9 = 0; c3_i9 < 2; c3_i9++) {
    c3_g_y[c3_i9] = 0.0;
    c3_i10 = 0;
    for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
      c3_g_y[c3_i9] += c3_f_a[c3_i10 + c3_i9] * c3_o_b[c3_i11];
      c3_i10 += 2;
    }
  }

  for (c3_i12 = 0; c3_i12 < 4; c3_i12++) {
    c3_f_a[c3_i12] = c3_M[c3_i12];
  }

  for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
    c3_g_y[c3_i13] = ((c3_V[c3_i13] - c3_g_y[c3_i13]) - c3_F[c3_i13]) -
      c3_G[c3_i13];
  }

  c3_s_x = c3_f_a[1];
  c3_t_x = c3_s_x;
  c3_u_x = c3_t_x;
  c3_h_y = muDoubleScalarAbs(c3_u_x);
  c3_v_x = 0.0;
  c3_w_x = c3_v_x;
  c3_i_y = muDoubleScalarAbs(c3_w_x);
  c3_d = c3_h_y + c3_i_y;
  c3_x_x = c3_f_a[0];
  c3_y_x = c3_x_x;
  c3_ab_x = c3_y_x;
  c3_j_y = muDoubleScalarAbs(c3_ab_x);
  c3_bb_x = 0.0;
  c3_cb_x = c3_bb_x;
  c3_k_y = muDoubleScalarAbs(c3_cb_x);
  c3_b_d = c3_j_y + c3_k_y;
  if (c3_d > c3_b_d) {
    c3_r1 = 2;
    c3_r2 = 1;
  } else {
    c3_r1 = 1;
    c3_r2 = 2;
  }

  c3_db_x = c3_f_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c3_r2), 1, 2, 1, 0) - 1];
  c3_l_y = c3_f_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 2, 1, 0) - 1];
  c3_a21 = c3_db_x / c3_l_y;
  c3_g_a = c3_a21;
  c3_p_b = c3_f_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 2, 1, 0) + 1];
  c3_m_y = c3_g_a * c3_p_b;
  c3_a22 = c3_f_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 2, 1, 0) + 1] - c3_m_y;
  guard1 = FALSE;
  if (c3_a22 == 0.0) {
    guard1 = TRUE;
  } else {
    if (c3_f_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_r1), 1, 2, 1, 0) - 1] == 0.0) {
      guard1 = TRUE;
    }
  }

  if (guard1 == TRUE) {
    c3_eml_warning(chartInstance);
  }

  c3_eml_scalar_eg(chartInstance);
  c3_h_a = c3_g_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 2, 1, 0) - 1];
  c3_q_b = c3_a21;
  c3_n_y = c3_h_a * c3_q_b;
  c3_eb_x = c3_g_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c3_r2), 1, 2, 1, 0) - 1] - c3_n_y;
  c3_o_y = c3_a22;
  c3_z = c3_eb_x / c3_o_y;
  c3_qdotdot[1] = c3_z;
  c3_i_a = c3_qdotdot[1];
  c3_r_b = c3_f_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 2, 1, 0) + 1];
  c3_p_y = c3_i_a * c3_r_b;
  c3_fb_x = c3_g_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c3_r1), 1, 2, 1, 0) - 1] - c3_p_y;
  c3_q_y = c3_f_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 2, 1, 0) - 1];
  c3_b_z = c3_fb_x / c3_q_y;
  c3_qdotdot[0] = c3_b_z;
  _SFD_EML_CALL(0U, *c3_sfEvent, 56);
  c3_Xdot[0] = c3_q1dot;
  c3_Xdot[1] = c3_qdotdot[0];
  c3_Xdot[2] = c3_q2dot;
  c3_Xdot[3] = c3_qdotdot[1];
  _SFD_EML_CALL(0U, *c3_sfEvent, 57);
  c3_Q[0] = c3_q1;
  c3_Q[1] = c3_q2;
  _SFD_EML_CALL(0U, *c3_sfEvent, -57);
  sf_debug_symbol_scope_pop();
  for (c3_i14 = 0; c3_i14 < 4; c3_i14++) {
    (*c3_b_Xdot)[c3_i14] = c3_Xdot[c3_i14];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c3_sfEvent);
}

static void initSimStructsc3_model2(SFc3_model2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i15;
  real_T c3_b_inData[4];
  int32_T c3_i16;
  real_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i15 = 0; c3_i15 < 4; c3_i15++) {
    c3_b_inData[c3_i15] = (*(real_T (*)[4])c3_inData)[c3_i15];
  }

  for (c3_i16 = 0; c3_i16 < 4; c3_i16++) {
    c3_u[c3_i16] = c3_b_inData[c3_i16];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance, const
  mxArray *c3_Xdot, const char_T *c3_identifier, real_T c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Xdot), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_Xdot);
}

static void c3_b_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4])
{
  real_T c3_dv1[4];
  int32_T c3_i17;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c3_i17 = 0; c3_i17 < 4; c3_i17++) {
    c3_y[c3_i17] = c3_dv1[c3_i17];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Xdot;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[4];
  int32_T c3_i18;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_Xdot = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Xdot), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_Xdot);
  for (c3_i18 = 0; c3_i18 < 4; c3_i18++) {
    (*(real_T (*)[4])c3_outData)[c3_i18] = c3_y[c3_i18];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i19;
  real_T c3_b_inData[4];
  int32_T c3_i20;
  real_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i19 = 0; c3_i19 < 4; c3_i19++) {
    c3_b_inData[c3_i19] = (*(real_T (*)[4])c3_inData)[c3_i19];
  }

  for (c3_i20 = 0; c3_i20 < 4; c3_i20++) {
    c3_u[c3_i20] = c3_b_inData[c3_i20];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i21;
  real_T c3_b_inData[2];
  int32_T c3_i22;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i21 = 0; c3_i21 < 2; c3_i21++) {
    c3_b_inData[c3_i21] = (*(real_T (*)[2])c3_inData)[c3_i21];
  }

  for (c3_i22 = 0; c3_i22 < 2; c3_i22++) {
    c3_u[c3_i22] = c3_b_inData[c3_i22];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_d_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2])
{
  real_T c3_dv2[2];
  int32_T c3_i23;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i23 = 0; c3_i23 < 2; c3_i23++) {
    c3_y[c3_i23] = c3_dv2[c3_i23];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Q;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i24;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_Q = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Q), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_Q);
  for (c3_i24 = 0; c3_i24 < 2; c3_i24++) {
    (*(real_T (*)[2])c3_outData)[c3_i24] = c3_y[c3_i24];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  real_T c3_b_inData[4];
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  real_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i25 = 0;
  for (c3_i26 = 0; c3_i26 < 2; c3_i26++) {
    for (c3_i27 = 0; c3_i27 < 2; c3_i27++) {
      c3_b_inData[c3_i27 + c3_i25] = (*(real_T (*)[4])c3_inData)[c3_i27 + c3_i25];
    }

    c3_i25 += 2;
  }

  c3_i28 = 0;
  for (c3_i29 = 0; c3_i29 < 2; c3_i29++) {
    for (c3_i30 = 0; c3_i30 < 2; c3_i30++) {
      c3_u[c3_i30 + c3_i28] = c3_b_inData[c3_i30 + c3_i28];
    }

    c3_i28 += 2;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4])
{
  real_T c3_dv3[4];
  int32_T c3_i31;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv3, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c3_i31 = 0; c3_i31 < 4; c3_i31++) {
    c3_y[c3_i31] = c3_dv3[c3_i31];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_C;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[4];
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_C = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_C), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_C);
  c3_i32 = 0;
  for (c3_i33 = 0; c3_i33 < 2; c3_i33++) {
    for (c3_i34 = 0; c3_i34 < 2; c3_i34++) {
      (*(real_T (*)[4])c3_outData)[c3_i34 + c3_i32] = c3_y[c3_i34 + c3_i32];
    }

    c3_i32 += 2;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_model2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[30];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i35;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 30), FALSE);
  for (c3_i35 = 0; c3_i35 < 30; c3_i35++) {
    c3_r0 = &c3_info[c3_i35];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i35);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[30])
{
  c3_info[0].context = "";
  c3_info[0].name = "sin";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[0].fileTimeLo = 1286843950U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[1].name = "eml_scalar_sin";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[1].fileTimeLo = 1286843936U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "";
  c3_info[2].name = "mpower";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[2].fileTimeLo = 1286844042U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[3].name = "power";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[3].fileTimeLo = 1336547296U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[4].name = "eml_scalar_eg";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[4].fileTimeLo = 1286843996U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[5].name = "eml_scalexp_alloc";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[5].fileTimeLo = 1330633634U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[6].name = "floor";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[6].fileTimeLo = 1286843942U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[7].name = "eml_scalar_floor";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[7].fileTimeLo = 1286843926U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context = "";
  c3_info[8].name = "mtimes";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[8].fileTimeLo = 1289544892U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context = "";
  c3_info[9].name = "cos";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[9].fileTimeLo = 1286843906U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[10].name = "eml_scalar_cos";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[10].fileTimeLo = 1286843922U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[11].name = "eml_index_class";
  c3_info[11].dominantType = "";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[11].fileTimeLo = 1323195778U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[12].name = "eml_scalar_eg";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[12].fileTimeLo = 1286843996U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[13].name = "eml_xgemm";
  c3_info[13].dominantType = "char";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[13].fileTimeLo = 1299101972U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[14].name = "eml_blas_inline";
  c3_info[14].dominantType = "";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[14].fileTimeLo = 1299101968U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c3_info[15].name = "mtimes";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[15].fileTimeLo = 1289544892U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[16].name = "eml_index_class";
  c3_info[16].dominantType = "";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[16].fileTimeLo = 1323195778U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[17].name = "eml_scalar_eg";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[17].fileTimeLo = 1286843996U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[18].name = "eml_refblas_xgemm";
  c3_info[18].dominantType = "char";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[18].fileTimeLo = 1299101974U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context = "";
  c3_info[19].name = "mldivide";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c3_info[19].fileTimeLo = 1342836144U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 1319755166U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c3_info[20].name = "eml_lusolve";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c3_info[20].fileTimeLo = 1309476396U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c3_info[21].name = "eml_index_class";
  c3_info[21].dominantType = "";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[21].fileTimeLo = 1323195778U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c3_info[22].name = "eml_index_class";
  c3_info[22].dominantType = "";
  c3_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[22].fileTimeLo = 1323195778U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c3_info[23].name = "eml_xcabs1";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c3_info[23].fileTimeLo = 1286843906U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c3_info[24].name = "abs";
  c3_info[24].dominantType = "double";
  c3_info[24].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[24].fileTimeLo = 1286843894U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[25].name = "eml_scalar_abs";
  c3_info[25].dominantType = "double";
  c3_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[25].fileTimeLo = 1286843912U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c3_info[26].name = "eml_div";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[26].fileTimeLo = 1313373010U;
  c3_info[26].fileTimeHi = 0U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
  c3_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c3_info[27].name = "mtimes";
  c3_info[27].dominantType = "double";
  c3_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[27].fileTimeLo = 1289544892U;
  c3_info[27].fileTimeHi = 0U;
  c3_info[27].mFileTimeLo = 0U;
  c3_info[27].mFileTimeHi = 0U;
  c3_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c3_info[28].name = "eml_warning";
  c3_info[28].dominantType = "char";
  c3_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c3_info[28].fileTimeLo = 1286844002U;
  c3_info[28].fileTimeHi = 0U;
  c3_info[28].mFileTimeLo = 0U;
  c3_info[28].mFileTimeHi = 0U;
  c3_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c3_info[29].name = "eml_scalar_eg";
  c3_info[29].dominantType = "double";
  c3_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[29].fileTimeLo = 1286843996U;
  c3_info[29].fileTimeHi = 0U;
  c3_info[29].mFileTimeLo = 0U;
  c3_info[29].mFileTimeHi = 0U;
}

static real_T c3_mpower(SFc3_model2InstanceStruct *chartInstance, real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_ak = c3_c_a;
  return muDoubleScalarPower(c3_ak, 2.0);
}

static void c3_eml_scalar_eg(SFc3_model2InstanceStruct *chartInstance)
{
}

static void c3_eml_warning(SFc3_model2InstanceStruct *chartInstance)
{
  int32_T c3_i36;
  static char_T c3_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c3_u[27];
  const mxArray *c3_y = NULL;
  for (c3_i36 = 0; c3_i36 < 27; c3_i36++) {
    c3_u[c3_i36] = c3_varargin_1[c3_i36];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c3_y));
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i37;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i37, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i37;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)chartInstanceVoid;
  c3_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sfEvent), &c3_thisId);
  sf_mex_destroy(&c3_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_is_active_c3_model2, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_is_active_c3_model2),
    &c3_thisId);
  sf_mex_destroy(&c3_is_active_c3_model2);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_model2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_model2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c3_model2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2751706473U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2079156411U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2904518921U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1512371799U);
}

mxArray *sf_c3_model2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5GwTOhIjHMWLIm7y25nl1E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
      pr[0] = (double)(4);
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
      pr[1] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c3_model2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Xdot\",},{M[8],M[0],T\"is_active_c3_model2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_model2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_model2InstanceStruct *chartInstance;
    chartInstance = (SFc3_model2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_model2MachineNumber_,
          3,
          1,
          1,
          3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"V");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Xdot");
          _SFD_SET_DATA_PROPS(2,1,1,0,"X");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1027);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c3_V)[2];
          real_T (*c3_Xdot)[4];
          real_T (*c3_X)[4];
          c3_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c3_Xdot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_V = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_V);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_Xdot);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_X);
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
  return "oNk6dgyZJ9VXGe0vXPCPV";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_model2_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 3, "dworkChecksum");
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

static void sf_opaque_initialize_c3_model2(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc3_model2InstanceStruct*) chartInstanceVar)->S);
  chart_debug_initialization(((SFc3_model2InstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c3_model2((SFc3_model2InstanceStruct*) chartInstanceVar);
  initialize_c3_model2((SFc3_model2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_model2(void *chartInstanceVar)
{
  enable_c3_model2((SFc3_model2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_model2(void *chartInstanceVar)
{
  disable_c3_model2((SFc3_model2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_model2(void *chartInstanceVar)
{
  sf_c3_model2((SFc3_model2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_model2(void *chartInstanceVar)
{
  ext_mode_exec_c3_model2((SFc3_model2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_model2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_model2((SFc3_model2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_model2();/* state var info */
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

extern void sf_internal_set_sim_state_c3_model2(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_model2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_model2((SFc3_model2InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_model2(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_model2(S);
}

static void sf_opaque_set_sim_state_c3_model2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_model2(S, st);
}

static void sf_opaque_terminate_c3_model2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_model2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_model2((SFc3_model2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_model2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_model2((SFc3_model2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_model2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_model2((SFc3_model2InstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c3_model2_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c3_model2\",T\"is_active_c3_model2\"}}"
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

static void mdlSetWorkWidths_c3_model2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_model2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(184787438U));
  ssSetChecksum1(S,(1385166838U));
  ssSetChecksum2(S,(1429506154U));
  ssSetChecksum3(S,(340337639U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_model2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_model2(SimStruct *S)
{
  SFc3_model2InstanceStruct *chartInstance;
  chartInstance = (SFc3_model2InstanceStruct *)malloc(sizeof
    (SFc3_model2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_model2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_model2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_model2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_model2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_model2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_model2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_model2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_model2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_model2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_model2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_model2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_model2;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c3_model2;
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

void c3_model2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_model2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_model2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_model2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_model2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
