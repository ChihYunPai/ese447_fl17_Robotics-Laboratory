/* Include files */

#include "blascompat32.h"
#include "Lab3_sfun.h"
#include "c2_Lab3.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Lab3_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[20] = { "theta1", "theta2", "L1", "L2",
  "P0_Org", "P1_Org", "P2_Org", "P3_Org", "P4_Org", "P5_Org", "T01", "P1", "P2",
  "P3", "P4", "T12", "P5", "nargin", "nargout", "array" };

static const char * c2_b_debug_family_names[12] = { "r1", "r2", "r", "phi",
  "phi_", "theta1", "theta2", "x", "y", "z", "nargin", "nargout" };

/* Function Declarations */
static void initialize_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance);
static void initialize_params_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance);
static void enable_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance);
static void disable_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_Lab3(SFc2_Lab3InstanceStruct
  *chartInstance);
static void ext_mode_exec_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Lab3(SFc2_Lab3InstanceStruct
  *chartInstance);
static void set_sim_state_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance, const
  mxArray *c2_st);
static void finalize_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance);
static void sf_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance);
static void c2_chartstep_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance);
static void initSimStructsc2_Lab3(SFc2_Lab3InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_b_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[10000]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[80]);
static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[80]);
static void c2_Sphere(SFc2_Lab3InstanceStruct *chartInstance);
static real_T c2_sqrt(SFc2_Lab3InstanceStruct *chartInstance, real_T c2_x);
static void c2_eml_error(SFc2_Lab3InstanceStruct *chartInstance);
static void c2_sin(SFc2_Lab3InstanceStruct *chartInstance, real_T c2_x[10000],
                   real_T c2_b_x[10000]);
static void c2_cos(SFc2_Lab3InstanceStruct *chartInstance, real_T c2_x[10000],
                   real_T c2_b_x[10000]);
static void c2_eml_scalar_eg(SFc2_Lab3InstanceStruct *chartInstance);
static void c2_b_eml_scalar_eg(SFc2_Lab3InstanceStruct *chartInstance);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance,
  const mxArray *c2_is_active_c2_Lab3, const char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sqrt(SFc2_Lab3InstanceStruct *chartInstance, real_T *c2_x);
static void c2_b_sin(SFc2_Lab3InstanceStruct *chartInstance, real_T c2_x[10000]);
static void c2_b_cos(SFc2_Lab3InstanceStruct *chartInstance, real_T c2_x[10000]);
static void init_dsm_address_info(SFc2_Lab3InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance)
{
  int32_T *c2_sfEvent;
  uint8_T *c2_is_active_c2_Lab3;
  c2_is_active_c2_Lab3 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_is_active_c2_Lab3 = 0U;
}

static void initialize_params_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance)
{
}

static void enable_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Lab3(SFc2_Lab3InstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance)
{
  c2_update_debugger_state_c2_Lab3(chartInstance);
}

static const mxArray *get_sim_state_c2_Lab3(SFc2_Lab3InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T *c2_is_active_c2_Lab3;
  c2_is_active_c2_Lab3 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(1), FALSE);
  c2_hoistedGlobal = *c2_is_active_c2_Lab3;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance, const
  mxArray *c2_st)
{
  const mxArray *c2_u;
  boolean_T *c2_doneDoubleBufferReInit;
  uint8_T *c2_is_active_c2_Lab3;
  c2_is_active_c2_Lab3 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_is_active_c2_Lab3 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "is_active_c2_Lab3");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Lab3(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance)
{
}

static void sf_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance)
{
  int32_T c2_i0;
  int32_T *c2_sfEvent;
  real_T (*c2_array)[2];
  c2_array = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c2_sfEvent);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*c2_array)[c2_i0], 0U);
  }

  *c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_Lab3(chartInstance);
  sf_debug_check_for_state_inconsistency(_Lab3MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_Lab3(SFc2_Lab3InstanceStruct *chartInstance)
{
  int32_T c2_i1;
  real_T c2_array[2];
  uint32_T c2_debug_family_var_map[20];
  real_T c2_theta1;
  real_T c2_theta2;
  real_T c2_L1;
  real_T c2_L2;
  real_T c2_P0_Org[4];
  real_T c2_P1_Org[4];
  real_T c2_P2_Org[4];
  real_T c2_P3_Org[4];
  real_T c2_P4_Org[4];
  real_T c2_P5_Org[4];
  real_T c2_T01[16];
  real_T c2_P1[4];
  real_T c2_P2[4];
  real_T c2_P3[4];
  real_T c2_P4[4];
  real_T c2_T12[16];
  real_T c2_P5[4];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 0.0;
  int32_T c2_i2;
  static real_T c2_dv0[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c2_i3;
  static real_T c2_b[4] = { 0.0, 0.0, -1.0, 1.0 };

  int32_T c2_i4;
  static real_T c2_b_b[4] = { 0.0, 6.0, -1.0, 1.0 };

  int32_T c2_i5;
  static real_T c2_c_b[4] = { 0.0, 6.0, 0.0, 1.0 };

  int32_T c2_i6;
  static real_T c2_d_b[4] = { 0.0, 8.0, 0.0, 1.0 };

  int32_T c2_i7;
  static real_T c2_e_b[4] = { 0.0, 12.0, 0.0, 1.0 };

  real_T c2_a;
  real_T c2_y;
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_b_a;
  real_T c2_b_y;
  real_T c2_b_A;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  int32_T c2_i8;
  int32_T c2_i9;
  static real_T c2_dv1[4] = { 0.0, 0.0, 1.0, 0.0 };

  int32_T c2_i10;
  int32_T c2_i11;
  static real_T c2_dv2[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c2_i12;
  real_T c2_c_a[16];
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  real_T c2_C[4];
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  real_T c2_f_b[16];
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i58;
  real_T c2_c_y[16];
  int32_T c2_i59;
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  real_T c2_u[6];
  const mxArray *c2_d_y = NULL;
  real_T c2_b_u[6];
  const mxArray *c2_e_y = NULL;
  real_T c2_c_u[6];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i70;
  static char_T c2_cv0[2] = { '-', 'o' };

  char_T c2_d_u[2];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i71;
  static char_T c2_cv1[20] = { 'R', 'o', 'b', 'o', 't', ' ', 'R', 'e', 'p', 'r',
    'e', 's', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n' };

  char_T c2_e_u[20];
  const mxArray *c2_h_y = NULL;
  int32_T c2_i72;
  static char_T c2_cv2[2] = { 'o', 'n' };

  char_T c2_f_u[2];
  const mxArray *c2_i_y = NULL;
  int32_T c2_i73;
  real_T c2_g_u[2];
  const mxArray *c2_j_y = NULL;
  int32_T c2_i74;
  real_T c2_h_u[2];
  const mxArray *c2_k_y = NULL;
  int32_T c2_i75;
  real_T c2_i_u[2];
  const mxArray *c2_l_y = NULL;
  char_T c2_j_u;
  const mxArray *c2_m_y = NULL;
  char_T c2_k_u;
  const mxArray *c2_n_y = NULL;
  char_T c2_l_u;
  const mxArray *c2_o_y = NULL;
  real_T (*c2_b_array)[2];
  int32_T *c2_sfEvent;
  c2_b_array = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    c2_array[c2_i1] = (*c2_b_array)[c2_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 20U, 20U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_theta1, 0U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_theta2, 1U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L1, 2U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L2, 3U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_P0_Org, 4U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_P1_Org, 5U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_P2_Org, 6U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_P3_Org, 7U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_P4_Org, 8U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_P5_Org, 9U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_T01, 10U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_P1, 11U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_P2, 12U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_P3, 13U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_P4, 14U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_T12, 15U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_P5, 16U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 17U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 18U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_array, 19U, c2_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c2_sfEvent, 2);
  c2_theta1 = c2_array[0];
  _SFD_EML_CALL(0U, *c2_sfEvent, 3);
  c2_theta2 = c2_array[1];
  _SFD_EML_CALL(0U, *c2_sfEvent, 4);
  c2_Sphere(chartInstance);
  _SFD_EML_CALL(0U, *c2_sfEvent, 5);
  c2_L1 = 6.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 6);
  c2_L2 = 2.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 7);
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    c2_P0_Org[c2_i2] = c2_dv0[c2_i2];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 8);
  for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
    c2_P1_Org[c2_i3] = c2_b[c2_i3];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 9);
  for (c2_i4 = 0; c2_i4 < 4; c2_i4++) {
    c2_P2_Org[c2_i4] = c2_b_b[c2_i4];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 10);
  for (c2_i5 = 0; c2_i5 < 4; c2_i5++) {
    c2_P3_Org[c2_i5] = c2_c_b[c2_i5];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 11);
  for (c2_i6 = 0; c2_i6 < 4; c2_i6++) {
    c2_P4_Org[c2_i6] = c2_d_b[c2_i6];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 12);
  for (c2_i7 = 0; c2_i7 < 4; c2_i7++) {
    c2_P5_Org[c2_i7] = c2_e_b[c2_i7];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 14);
  c2_a = c2_theta1;
  c2_y = c2_a * 3.1415926535897931;
  c2_A = c2_y;
  c2_x = c2_A;
  c2_b_x = c2_x;
  c2_theta1 = c2_b_x / 180.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 15);
  c2_b_a = c2_theta2;
  c2_b_y = c2_b_a * 3.1415926535897931;
  c2_b_A = c2_b_y;
  c2_c_x = c2_b_A;
  c2_d_x = c2_c_x;
  c2_theta2 = c2_d_x / 180.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 17);
  c2_e_x = c2_theta1;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarCos(c2_f_x);
  c2_g_x = c2_theta1;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarSin(c2_h_x);
  c2_i_x = c2_theta1;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarSin(c2_j_x);
  c2_k_x = c2_theta1;
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarCos(c2_l_x);
  c2_T01[0] = c2_f_x;
  c2_T01[4] = -c2_h_x;
  c2_T01[8] = 0.0;
  c2_T01[12] = 0.0;
  c2_T01[1] = c2_j_x;
  c2_T01[5] = c2_l_x;
  c2_T01[9] = 0.0;
  c2_T01[13] = 0.0;
  c2_i8 = 0;
  for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
    c2_T01[c2_i8 + 2] = c2_dv1[c2_i9];
    c2_i8 += 4;
  }

  c2_i10 = 0;
  for (c2_i11 = 0; c2_i11 < 4; c2_i11++) {
    c2_T01[c2_i10 + 3] = c2_dv2[c2_i11];
    c2_i10 += 4;
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 18);
  for (c2_i12 = 0; c2_i12 < 16; c2_i12++) {
    c2_c_a[c2_i12] = c2_T01[c2_i12];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_P1[c2_i13] = 0.0;
  }

  for (c2_i14 = 0; c2_i14 < 4; c2_i14++) {
    c2_P1[c2_i14] = 0.0;
  }

  for (c2_i15 = 0; c2_i15 < 4; c2_i15++) {
    c2_C[c2_i15] = c2_P1[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
    c2_P1[c2_i16] = c2_C[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 4; c2_i17++) {
    c2_C[c2_i17] = c2_P1[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 4; c2_i18++) {
    c2_P1[c2_i18] = c2_C[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 4; c2_i19++) {
    c2_P1[c2_i19] = 0.0;
    c2_i20 = 0;
    for (c2_i21 = 0; c2_i21 < 4; c2_i21++) {
      c2_P1[c2_i19] += c2_c_a[c2_i20 + c2_i19] * c2_b[c2_i21];
      c2_i20 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 19);
  for (c2_i22 = 0; c2_i22 < 16; c2_i22++) {
    c2_c_a[c2_i22] = c2_T01[c2_i22];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i23 = 0; c2_i23 < 4; c2_i23++) {
    c2_P2[c2_i23] = 0.0;
  }

  for (c2_i24 = 0; c2_i24 < 4; c2_i24++) {
    c2_P2[c2_i24] = 0.0;
  }

  for (c2_i25 = 0; c2_i25 < 4; c2_i25++) {
    c2_C[c2_i25] = c2_P2[c2_i25];
  }

  for (c2_i26 = 0; c2_i26 < 4; c2_i26++) {
    c2_P2[c2_i26] = c2_C[c2_i26];
  }

  for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
    c2_C[c2_i27] = c2_P2[c2_i27];
  }

  for (c2_i28 = 0; c2_i28 < 4; c2_i28++) {
    c2_P2[c2_i28] = c2_C[c2_i28];
  }

  for (c2_i29 = 0; c2_i29 < 4; c2_i29++) {
    c2_P2[c2_i29] = 0.0;
    c2_i30 = 0;
    for (c2_i31 = 0; c2_i31 < 4; c2_i31++) {
      c2_P2[c2_i29] += c2_c_a[c2_i30 + c2_i29] * c2_b_b[c2_i31];
      c2_i30 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 20);
  for (c2_i32 = 0; c2_i32 < 16; c2_i32++) {
    c2_c_a[c2_i32] = c2_T01[c2_i32];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i33 = 0; c2_i33 < 4; c2_i33++) {
    c2_P3[c2_i33] = 0.0;
  }

  for (c2_i34 = 0; c2_i34 < 4; c2_i34++) {
    c2_P3[c2_i34] = 0.0;
  }

  for (c2_i35 = 0; c2_i35 < 4; c2_i35++) {
    c2_C[c2_i35] = c2_P3[c2_i35];
  }

  for (c2_i36 = 0; c2_i36 < 4; c2_i36++) {
    c2_P3[c2_i36] = c2_C[c2_i36];
  }

  for (c2_i37 = 0; c2_i37 < 4; c2_i37++) {
    c2_C[c2_i37] = c2_P3[c2_i37];
  }

  for (c2_i38 = 0; c2_i38 < 4; c2_i38++) {
    c2_P3[c2_i38] = c2_C[c2_i38];
  }

  for (c2_i39 = 0; c2_i39 < 4; c2_i39++) {
    c2_P3[c2_i39] = 0.0;
    c2_i40 = 0;
    for (c2_i41 = 0; c2_i41 < 4; c2_i41++) {
      c2_P3[c2_i39] += c2_c_a[c2_i40 + c2_i39] * c2_c_b[c2_i41];
      c2_i40 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 21);
  for (c2_i42 = 0; c2_i42 < 16; c2_i42++) {
    c2_c_a[c2_i42] = c2_T01[c2_i42];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i43 = 0; c2_i43 < 4; c2_i43++) {
    c2_P4[c2_i43] = 0.0;
  }

  for (c2_i44 = 0; c2_i44 < 4; c2_i44++) {
    c2_P4[c2_i44] = 0.0;
  }

  for (c2_i45 = 0; c2_i45 < 4; c2_i45++) {
    c2_C[c2_i45] = c2_P4[c2_i45];
  }

  for (c2_i46 = 0; c2_i46 < 4; c2_i46++) {
    c2_P4[c2_i46] = c2_C[c2_i46];
  }

  for (c2_i47 = 0; c2_i47 < 4; c2_i47++) {
    c2_C[c2_i47] = c2_P4[c2_i47];
  }

  for (c2_i48 = 0; c2_i48 < 4; c2_i48++) {
    c2_P4[c2_i48] = c2_C[c2_i48];
  }

  for (c2_i49 = 0; c2_i49 < 4; c2_i49++) {
    c2_P4[c2_i49] = 0.0;
    c2_i50 = 0;
    for (c2_i51 = 0; c2_i51 < 4; c2_i51++) {
      c2_P4[c2_i49] += c2_c_a[c2_i50 + c2_i49] * c2_d_b[c2_i51];
      c2_i50 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 22);
  c2_m_x = c2_theta2;
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarCos(c2_n_x);
  c2_o_x = c2_theta2;
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarSin(c2_p_x);
  c2_q_x = c2_theta2;
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarSin(c2_r_x);
  c2_s_x = c2_theta2;
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarCos(c2_t_x);
  c2_T12[0] = c2_n_x;
  c2_T12[4] = -c2_p_x;
  c2_T12[8] = 0.0;
  c2_T12[12] = 0.0;
  c2_T12[1] = 0.0;
  c2_T12[5] = 0.0;
  c2_T12[9] = -1.0;
  c2_T12[13] = c2_L1 + c2_L2;
  c2_T12[2] = c2_r_x;
  c2_T12[6] = c2_t_x;
  c2_T12[10] = 0.0;
  c2_T12[14] = 0.0;
  c2_i52 = 0;
  for (c2_i53 = 0; c2_i53 < 4; c2_i53++) {
    c2_T12[c2_i52 + 3] = c2_dv2[c2_i53];
    c2_i52 += 4;
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 23);
  for (c2_i54 = 0; c2_i54 < 16; c2_i54++) {
    c2_c_a[c2_i54] = c2_T01[c2_i54];
  }

  for (c2_i55 = 0; c2_i55 < 16; c2_i55++) {
    c2_f_b[c2_i55] = c2_T12[c2_i55];
  }

  c2_b_eml_scalar_eg(chartInstance);
  c2_b_eml_scalar_eg(chartInstance);
  for (c2_i56 = 0; c2_i56 < 4; c2_i56++) {
    c2_i57 = 0;
    for (c2_i58 = 0; c2_i58 < 4; c2_i58++) {
      c2_c_y[c2_i57 + c2_i56] = 0.0;
      c2_i59 = 0;
      for (c2_i60 = 0; c2_i60 < 4; c2_i60++) {
        c2_c_y[c2_i57 + c2_i56] += c2_c_a[c2_i59 + c2_i56] * c2_f_b[c2_i60 +
          c2_i57];
        c2_i59 += 4;
      }

      c2_i57 += 4;
    }
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i61 = 0; c2_i61 < 4; c2_i61++) {
    c2_P5[c2_i61] = 0.0;
  }

  for (c2_i62 = 0; c2_i62 < 4; c2_i62++) {
    c2_P5[c2_i62] = 0.0;
  }

  for (c2_i63 = 0; c2_i63 < 4; c2_i63++) {
    c2_C[c2_i63] = c2_P5[c2_i63];
  }

  for (c2_i64 = 0; c2_i64 < 4; c2_i64++) {
    c2_P5[c2_i64] = c2_C[c2_i64];
  }

  for (c2_i65 = 0; c2_i65 < 4; c2_i65++) {
    c2_C[c2_i65] = c2_P5[c2_i65];
  }

  for (c2_i66 = 0; c2_i66 < 4; c2_i66++) {
    c2_P5[c2_i66] = c2_C[c2_i66];
  }

  for (c2_i67 = 0; c2_i67 < 4; c2_i67++) {
    c2_P5[c2_i67] = 0.0;
    c2_i68 = 0;
    for (c2_i69 = 0; c2_i69 < 4; c2_i69++) {
      c2_P5[c2_i67] += c2_c_y[c2_i68 + c2_i67] * c2_e_b[c2_i69];
      c2_i68 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 25);
  c2_u[0] = c2_P0_Org[0];
  c2_u[1] = c2_P1[0];
  c2_u[2] = c2_P2[0];
  c2_u[3] = c2_P3[0];
  c2_u[4] = c2_P4[0];
  c2_u[5] = c2_P5[0];
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  c2_b_u[0] = c2_P0_Org[1];
  c2_b_u[1] = c2_P1[1];
  c2_b_u[2] = c2_P2[1];
  c2_b_u[3] = c2_P3[1];
  c2_b_u[4] = c2_P4[1];
  c2_b_u[5] = c2_P5[1];
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  c2_c_u[0] = c2_P0_Org[2];
  c2_c_u[1] = c2_P1[2];
  c2_c_u[2] = c2_P2[2];
  c2_c_u[3] = c2_P3[2];
  c2_c_u[4] = c2_P4[2];
  c2_c_u[5] = c2_P5[2];
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  for (c2_i70 = 0; c2_i70 < 2; c2_i70++) {
    c2_d_u[c2_i70] = c2_cv0[c2_i70];
  }

  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("plot3", 0U, 4U, 14, c2_d_y, 14, c2_e_y, 14, c2_f_y, 14,
                    c2_g_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 26);
  for (c2_i71 = 0; c2_i71 < 20; c2_i71++) {
    c2_e_u[c2_i71] = c2_cv1[c2_i71];
  }

  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_e_u, 10, 0U, 1U, 0U, 2, 1, 20),
                FALSE);
  sf_mex_call_debug("title", 0U, 1U, 14, c2_h_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 26);
  for (c2_i72 = 0; c2_i72 < 2; c2_i72++) {
    c2_f_u[c2_i72] = c2_cv2[c2_i72];
  }

  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_f_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("grid", 0U, 1U, 14, c2_i_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 26);
  for (c2_i73 = 0; c2_i73 < 2; c2_i73++) {
    c2_g_u[c2_i73] = -10.0 + 20.0 * (real_T)c2_i73;
  }

  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_g_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("xlim", 0U, 1U, 14, c2_j_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 26);
  for (c2_i74 = 0; c2_i74 < 2; c2_i74++) {
    c2_h_u[c2_i74] = -10.0 + 20.0 * (real_T)c2_i74;
  }

  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_h_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("ylim", 0U, 1U, 14, c2_k_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 26);
  for (c2_i75 = 0; c2_i75 < 2; c2_i75++) {
    c2_i_u[c2_i75] = -10.0 + 20.0 * (real_T)c2_i75;
  }

  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_i_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("zlim", 0U, 1U, 14, c2_l_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 26);
  c2_j_u = 'x';
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_j_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("xlabel", 0U, 1U, 14, c2_m_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 26);
  c2_k_u = 'y';
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_k_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("ylabel", 0U, 1U, 14, c2_n_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 26);
  c2_l_u = 'z';
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_l_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("zlabel", 0U, 1U, 14, c2_o_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 27);
  sf_mex_call_debug("drawnow", 0U, 0U);
  _SFD_EML_CALL(0U, *c2_sfEvent, -27);
  sf_debug_symbol_scope_pop();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c2_sfEvent);
}

static void initSimStructsc2_Lab3(SFc2_Lab3InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 0U, sf_debug_get_script_id(
    "H:/winprofile/desktop/Lab 3/Sphere.m"));
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i76;
  real_T c2_b_inData[2];
  int32_T c2_i77;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i76 = 0; c2_i76 < 2; c2_i76++) {
    c2_b_inData[c2_i76] = (*(real_T (*)[2])c2_inData)[c2_i76];
  }

  for (c2_i77 = 0; c2_i77 < 2; c2_i77++) {
    c2_u[c2_i77] = c2_b_inData[c2_i77];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
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
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i78;
  real_T c2_b_inData[4];
  int32_T c2_i79;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i78 = 0; c2_i78 < 4; c2_i78++) {
    c2_b_inData[c2_i78] = (*(real_T (*)[4])c2_inData)[c2_i78];
  }

  for (c2_i79 = 0; c2_i79 < 4; c2_i79++) {
    c2_u[c2_i79] = c2_b_inData[c2_i79];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_b_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv3[4];
  int32_T c2_i80;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i80 = 0; c2_i80 < 4; c2_i80++) {
    c2_y[c2_i80] = c2_dv3[c2_i80];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_P5;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i81;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_P5 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_P5), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_P5);
  for (c2_i81 = 0; c2_i81 < 4; c2_i81++) {
    (*(real_T (*)[4])c2_outData)[c2_i81] = c2_y[c2_i81];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  real_T c2_b_inData[16];
  int32_T c2_i85;
  int32_T c2_i86;
  int32_T c2_i87;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i82 = 0;
  for (c2_i83 = 0; c2_i83 < 4; c2_i83++) {
    for (c2_i84 = 0; c2_i84 < 4; c2_i84++) {
      c2_b_inData[c2_i84 + c2_i82] = (*(real_T (*)[16])c2_inData)[c2_i84 +
        c2_i82];
    }

    c2_i82 += 4;
  }

  c2_i85 = 0;
  for (c2_i86 = 0; c2_i86 < 4; c2_i86++) {
    for (c2_i87 = 0; c2_i87 < 4; c2_i87++) {
      c2_u[c2_i87 + c2_i85] = c2_b_inData[c2_i87 + c2_i85];
    }

    c2_i85 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16])
{
  real_T c2_dv4[16];
  int32_T c2_i88;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i88 = 0; c2_i88 < 16; c2_i88++) {
    c2_y[c2_i88] = c2_dv4[c2_i88];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_T12;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i89;
  int32_T c2_i90;
  int32_T c2_i91;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_T12 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_T12), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_T12);
  c2_i89 = 0;
  for (c2_i90 = 0; c2_i90 < 4; c2_i90++) {
    for (c2_i91 = 0; c2_i91 < 4; c2_i91++) {
      (*(real_T (*)[16])c2_outData)[c2_i91 + c2_i89] = c2_y[c2_i91 + c2_i89];
    }

    c2_i89 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  real_T c2_b_inData[10000];
  int32_T c2_i95;
  int32_T c2_i96;
  int32_T c2_i97;
  real_T c2_u[10000];
  const mxArray *c2_y = NULL;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i92 = 0;
  for (c2_i93 = 0; c2_i93 < 100; c2_i93++) {
    for (c2_i94 = 0; c2_i94 < 100; c2_i94++) {
      c2_b_inData[c2_i94 + c2_i92] = (*(real_T (*)[10000])c2_inData)[c2_i94 +
        c2_i92];
    }

    c2_i92 += 100;
  }

  c2_i95 = 0;
  for (c2_i96 = 0; c2_i96 < 100; c2_i96++) {
    for (c2_i97 = 0; c2_i97 < 100; c2_i97++) {
      c2_u[c2_i97 + c2_i95] = c2_b_inData[c2_i97 + c2_i95];
    }

    c2_i95 += 100;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[10000])
{
  real_T c2_dv5[10000];
  int32_T c2_i98;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv5, 1, 0, 0U, 1, 0U, 2, 100,
                100);
  for (c2_i98 = 0; c2_i98 < 10000; c2_i98++) {
    c2_y[c2_i98] = c2_dv5[c2_i98];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_z;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[10000];
  int32_T c2_i99;
  int32_T c2_i100;
  int32_T c2_i101;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_z = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_z), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_z);
  c2_i99 = 0;
  for (c2_i100 = 0; c2_i100 < 100; c2_i100++) {
    for (c2_i101 = 0; c2_i101 < 100; c2_i101++) {
      (*(real_T (*)[10000])c2_outData)[c2_i101 + c2_i99] = c2_y[c2_i101 + c2_i99];
    }

    c2_i99 += 100;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i102;
  real_T c2_b_inData[100];
  int32_T c2_i103;
  real_T c2_u[100];
  const mxArray *c2_y = NULL;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i102 = 0; c2_i102 < 100; c2_i102++) {
    c2_b_inData[c2_i102] = (*(real_T (*)[100])c2_inData)[c2_i102];
  }

  for (c2_i103 = 0; c2_i103 < 100; c2_i103++) {
    c2_u[c2_i103] = c2_b_inData[c2_i103];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 100), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_Lab3_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[80];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i104;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  c2_b_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 80), FALSE);
  for (c2_i104 = 0; c2_i104 < 80; c2_i104++) {
    c2_r0 = &c2_info[c2_i104];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i104);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i104);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i104);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i104);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i104);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i104);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i104);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i104);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[80])
{
  c2_info[0].context = "";
  c2_info[0].name = "Sphere";
  c2_info[0].dominantType = "";
  c2_info[0].resolved = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[0].fileTimeLo = 1506443451U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[1].name = "mpower";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[1].fileTimeLo = 1286844042U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[2].name = "power";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[2].fileTimeLo = 1336547296U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[3].name = "eml_scalar_eg";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[3].fileTimeLo = 1286843996U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[4].name = "eml_scalexp_alloc";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[4].fileTimeLo = 1330633634U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[5].name = "floor";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[5].fileTimeLo = 1286843942U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[6].name = "eml_scalar_floor";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[6].fileTimeLo = 1286843926U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[7].name = "sqrt";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[7].fileTimeLo = 1286843952U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[8].name = "eml_error";
  c2_info[8].dominantType = "char";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[8].fileTimeLo = 1305343200U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[9].name = "eml_scalar_sqrt";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[9].fileTimeLo = 1286843938U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[10].name = "mrdivide";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[10].fileTimeLo = 1342836144U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 1319755166U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[11].name = "rdivide";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[11].fileTimeLo = 1286844044U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[12].name = "eml_div";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[12].fileTimeLo = 1313373010U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[13].name = "atan";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c2_info[13].fileTimeLo = 1305343198U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c2_info[14].name = "eml_scalar_atan";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c2_info[14].fileTimeLo = 1286843918U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[15].name = "mtimes";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[15].fileTimeLo = 1289544892U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[16].name = "linspace";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[16].fileTimeLo = 1286843962U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[17].name = "eml_scalar_eg";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[17].fileTimeLo = 1286843996U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[18].name = "eml_scalar_floor";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[18].fileTimeLo = 1286843926U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[19].name = "eml_index_class";
  c2_info[19].dominantType = "";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[19].fileTimeLo = 1323195778U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[20].name = "realmax";
  c2_info[20].dominantType = "char";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[20].fileTimeLo = 1307676442U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[21].name = "eml_realmax";
  c2_info[21].dominantType = "char";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[21].fileTimeLo = 1326753196U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[22].name = "eml_float_model";
  c2_info[22].dominantType = "char";
  c2_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[22].fileTimeLo = 1326753196U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[23].name = "mtimes";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[23].fileTimeLo = 1289544892U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[24].name = "mrdivide";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[24].fileTimeLo = 1342836144U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 1319755166U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[25].name = "mtimes";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[25].fileTimeLo = 1289544892U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[26].name = "meshgrid";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c2_info[26].fileTimeLo = 1294093142U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c2_info[27].name = "repmat";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[27].fileTimeLo = 1297372434U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[28].name = "eml_assert_valid_size_arg";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[28].fileTimeLo = 1286843894U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c2_info[29].name = "isinf";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[29].fileTimeLo = 1286843960U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c2_info[30].name = "mtimes";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[30].fileTimeLo = 1289544892U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[31].name = "eml_index_class";
  c2_info[31].dominantType = "";
  c2_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[31].fileTimeLo = 1323195778U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[32].name = "intmax";
  c2_info[32].dominantType = "char";
  c2_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[32].fileTimeLo = 1311280516U;
  c2_info[32].fileTimeHi = 0U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[33].name = "eml_index_class";
  c2_info[33].dominantType = "";
  c2_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[33].fileTimeLo = 1323195778U;
  c2_info[33].fileTimeHi = 0U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[34].name = "eml_index_minus";
  c2_info[34].dominantType = "coder.internal.indexInt";
  c2_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[34].fileTimeLo = 1286843978U;
  c2_info[34].fileTimeHi = 0U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[35].name = "eml_index_class";
  c2_info[35].dominantType = "";
  c2_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[35].fileTimeLo = 1323195778U;
  c2_info[35].fileTimeHi = 0U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[36].name = "eml_scalar_eg";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[36].fileTimeLo = 1286843996U;
  c2_info[36].fileTimeHi = 0U;
  c2_info[36].mFileTimeLo = 0U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[37].name = "eml_index_prod";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c2_info[37].fileTimeLo = 1286843980U;
  c2_info[37].fileTimeHi = 0U;
  c2_info[37].mFileTimeLo = 0U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c2_info[38].name = "eml_index_class";
  c2_info[38].dominantType = "";
  c2_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[38].fileTimeLo = 1323195778U;
  c2_info[38].fileTimeHi = 0U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c2_info[39].name = "eml_index_times";
  c2_info[39].dominantType = "coder.internal.indexInt";
  c2_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[39].fileTimeLo = 1286843980U;
  c2_info[39].fileTimeHi = 0U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
  c2_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[40].name = "eml_index_class";
  c2_info[40].dominantType = "";
  c2_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[40].fileTimeLo = 1323195778U;
  c2_info[40].fileTimeHi = 0U;
  c2_info[40].mFileTimeLo = 0U;
  c2_info[40].mFileTimeHi = 0U;
  c2_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[41].name = "eml_int_forloop_overflow_check";
  c2_info[41].dominantType = "";
  c2_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[41].fileTimeLo = 1332190272U;
  c2_info[41].fileTimeHi = 0U;
  c2_info[41].mFileTimeLo = 0U;
  c2_info[41].mFileTimeHi = 0U;
  c2_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[42].name = "intmax";
  c2_info[42].dominantType = "char";
  c2_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[42].fileTimeLo = 1311280516U;
  c2_info[42].fileTimeHi = 0U;
  c2_info[42].mFileTimeLo = 0U;
  c2_info[42].mFileTimeHi = 0U;
  c2_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[43].name = "eml_index_plus";
  c2_info[43].dominantType = "coder.internal.indexInt";
  c2_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[43].fileTimeLo = 1286843978U;
  c2_info[43].fileTimeHi = 0U;
  c2_info[43].mFileTimeLo = 0U;
  c2_info[43].mFileTimeHi = 0U;
  c2_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[44].name = "eml_index_class";
  c2_info[44].dominantType = "";
  c2_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[44].fileTimeLo = 1323195778U;
  c2_info[44].fileTimeHi = 0U;
  c2_info[44].mFileTimeLo = 0U;
  c2_info[44].mFileTimeHi = 0U;
  c2_info[45].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[45].name = "sin";
  c2_info[45].dominantType = "double";
  c2_info[45].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[45].fileTimeLo = 1286843950U;
  c2_info[45].fileTimeHi = 0U;
  c2_info[45].mFileTimeLo = 0U;
  c2_info[45].mFileTimeHi = 0U;
  c2_info[46].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[46].name = "eml_scalar_sin";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[46].fileTimeLo = 1286843936U;
  c2_info[46].fileTimeHi = 0U;
  c2_info[46].mFileTimeLo = 0U;
  c2_info[46].mFileTimeHi = 0U;
  c2_info[47].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[47].name = "cos";
  c2_info[47].dominantType = "double";
  c2_info[47].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[47].fileTimeLo = 1286843906U;
  c2_info[47].fileTimeHi = 0U;
  c2_info[47].mFileTimeLo = 0U;
  c2_info[47].mFileTimeHi = 0U;
  c2_info[48].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[48].name = "eml_scalar_cos";
  c2_info[48].dominantType = "double";
  c2_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[48].fileTimeLo = 1286843922U;
  c2_info[48].fileTimeHi = 0U;
  c2_info[48].mFileTimeLo = 0U;
  c2_info[48].mFileTimeHi = 0U;
  c2_info[49].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[49].name = "mesh";
  c2_info[49].dominantType = "double";
  c2_info[49].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/mesh.m";
  c2_info[49].fileTimeLo = 1301761842U;
  c2_info[49].fileTimeHi = 0U;
  c2_info[49].mFileTimeLo = 0U;
  c2_info[49].mFileTimeHi = 0U;
  c2_info[50].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[50].name = "hold";
  c2_info[50].dominantType = "char";
  c2_info[50].resolved = "[IXE]$matlabroot$/toolbox/matlab/graphics/hold.m";
  c2_info[50].fileTimeLo = 1305061498U;
  c2_info[50].fileTimeHi = 0U;
  c2_info[50].mFileTimeLo = 0U;
  c2_info[50].mFileTimeHi = 0U;
  c2_info[51].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[51].name = "grid";
  c2_info[51].dominantType = "char";
  c2_info[51].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/grid.m";
  c2_info[51].fileTimeLo = 1311280766U;
  c2_info[51].fileTimeHi = 0U;
  c2_info[51].mFileTimeLo = 0U;
  c2_info[51].mFileTimeHi = 0U;
  c2_info[52].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[52].name = "xlim";
  c2_info[52].dominantType = "double";
  c2_info[52].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/xlim.m";
  c2_info[52].fileTimeLo = 1299479202U;
  c2_info[52].fileTimeHi = 0U;
  c2_info[52].mFileTimeLo = 0U;
  c2_info[52].mFileTimeHi = 0U;
  c2_info[53].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[53].name = "ylim";
  c2_info[53].dominantType = "double";
  c2_info[53].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/ylim.m";
  c2_info[53].fileTimeLo = 1299479202U;
  c2_info[53].fileTimeHi = 0U;
  c2_info[53].mFileTimeLo = 0U;
  c2_info[53].mFileTimeHi = 0U;
  c2_info[54].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[54].name = "zlim";
  c2_info[54].dominantType = "double";
  c2_info[54].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/zlim.m";
  c2_info[54].fileTimeLo = 1299479202U;
  c2_info[54].fileTimeHi = 0U;
  c2_info[54].mFileTimeLo = 0U;
  c2_info[54].mFileTimeHi = 0U;
  c2_info[55].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[55].name = "xlabel";
  c2_info[55].dominantType = "char";
  c2_info[55].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/xlabel.m";
  c2_info[55].fileTimeLo = 1303582146U;
  c2_info[55].fileTimeHi = 0U;
  c2_info[55].mFileTimeLo = 0U;
  c2_info[55].mFileTimeHi = 0U;
  c2_info[56].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[56].name = "ylabel";
  c2_info[56].dominantType = "char";
  c2_info[56].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/ylabel.m";
  c2_info[56].fileTimeLo = 1303582146U;
  c2_info[56].fileTimeHi = 0U;
  c2_info[56].mFileTimeLo = 0U;
  c2_info[56].mFileTimeHi = 0U;
  c2_info[57].context = "[E]H:/winprofile/desktop/Lab 3/Sphere.m";
  c2_info[57].name = "zlabel";
  c2_info[57].dominantType = "char";
  c2_info[57].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/zlabel.m";
  c2_info[57].fileTimeLo = 1303582144U;
  c2_info[57].fileTimeHi = 0U;
  c2_info[57].mFileTimeLo = 0U;
  c2_info[57].mFileTimeHi = 0U;
  c2_info[58].context = "";
  c2_info[58].name = "mtimes";
  c2_info[58].dominantType = "double";
  c2_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[58].fileTimeLo = 1289544892U;
  c2_info[58].fileTimeHi = 0U;
  c2_info[58].mFileTimeLo = 0U;
  c2_info[58].mFileTimeHi = 0U;
  c2_info[59].context = "";
  c2_info[59].name = "mrdivide";
  c2_info[59].dominantType = "double";
  c2_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[59].fileTimeLo = 1342836144U;
  c2_info[59].fileTimeHi = 0U;
  c2_info[59].mFileTimeLo = 1319755166U;
  c2_info[59].mFileTimeHi = 0U;
  c2_info[60].context = "";
  c2_info[60].name = "cos";
  c2_info[60].dominantType = "double";
  c2_info[60].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[60].fileTimeLo = 1286843906U;
  c2_info[60].fileTimeHi = 0U;
  c2_info[60].mFileTimeLo = 0U;
  c2_info[60].mFileTimeHi = 0U;
  c2_info[61].context = "";
  c2_info[61].name = "sin";
  c2_info[61].dominantType = "double";
  c2_info[61].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[61].fileTimeLo = 1286843950U;
  c2_info[61].fileTimeHi = 0U;
  c2_info[61].mFileTimeLo = 0U;
  c2_info[61].mFileTimeHi = 0U;
  c2_info[62].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[62].name = "eml_index_class";
  c2_info[62].dominantType = "";
  c2_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[62].fileTimeLo = 1323195778U;
  c2_info[62].fileTimeHi = 0U;
  c2_info[62].mFileTimeLo = 0U;
  c2_info[62].mFileTimeHi = 0U;
  c2_info[63].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[63].name = "eml_scalar_eg";
  c2_info[63].dominantType = "double";
  c2_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[63].fileTimeLo = 1286843996U;
  c2_info[63].fileTimeHi = 0U;
  c2_info[63].mFileTimeLo = 0U;
  c2_info[63].mFileTimeHi = 0U;
}

static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[80])
{
  c2_info[64].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[64].name = "eml_xgemm";
  c2_info[64].dominantType = "char";
  c2_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[64].fileTimeLo = 1299101972U;
  c2_info[64].fileTimeHi = 0U;
  c2_info[64].mFileTimeLo = 0U;
  c2_info[64].mFileTimeHi = 0U;
  c2_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[65].name = "eml_blas_inline";
  c2_info[65].dominantType = "";
  c2_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[65].fileTimeLo = 1299101968U;
  c2_info[65].fileTimeHi = 0U;
  c2_info[65].mFileTimeLo = 0U;
  c2_info[65].mFileTimeHi = 0U;
  c2_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[66].name = "mtimes";
  c2_info[66].dominantType = "double";
  c2_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[66].fileTimeLo = 1289544892U;
  c2_info[66].fileTimeHi = 0U;
  c2_info[66].mFileTimeLo = 0U;
  c2_info[66].mFileTimeHi = 0U;
  c2_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[67].name = "eml_index_class";
  c2_info[67].dominantType = "";
  c2_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[67].fileTimeLo = 1323195778U;
  c2_info[67].fileTimeHi = 0U;
  c2_info[67].mFileTimeLo = 0U;
  c2_info[67].mFileTimeHi = 0U;
  c2_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[68].name = "eml_scalar_eg";
  c2_info[68].dominantType = "double";
  c2_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[68].fileTimeLo = 1286843996U;
  c2_info[68].fileTimeHi = 0U;
  c2_info[68].mFileTimeLo = 0U;
  c2_info[68].mFileTimeHi = 0U;
  c2_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[69].name = "eml_refblas_xgemm";
  c2_info[69].dominantType = "char";
  c2_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[69].fileTimeLo = 1299101974U;
  c2_info[69].fileTimeHi = 0U;
  c2_info[69].mFileTimeLo = 0U;
  c2_info[69].mFileTimeHi = 0U;
  c2_info[70].context = "";
  c2_info[70].name = "plot3";
  c2_info[70].dominantType = "double";
  c2_info[70].resolved = "[IXMB]$matlabroot$/toolbox/matlab/graph3d/plot3";
  c2_info[70].fileTimeLo = MAX_uint32_T;
  c2_info[70].fileTimeHi = MAX_uint32_T;
  c2_info[70].mFileTimeLo = MAX_uint32_T;
  c2_info[70].mFileTimeHi = MAX_uint32_T;
  c2_info[71].context = "";
  c2_info[71].name = "title";
  c2_info[71].dominantType = "char";
  c2_info[71].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/title.m";
  c2_info[71].fileTimeLo = 1303582146U;
  c2_info[71].fileTimeHi = 0U;
  c2_info[71].mFileTimeLo = 0U;
  c2_info[71].mFileTimeHi = 0U;
  c2_info[72].context = "";
  c2_info[72].name = "grid";
  c2_info[72].dominantType = "char";
  c2_info[72].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/grid.m";
  c2_info[72].fileTimeLo = 1311280766U;
  c2_info[72].fileTimeHi = 0U;
  c2_info[72].mFileTimeLo = 0U;
  c2_info[72].mFileTimeHi = 0U;
  c2_info[73].context = "";
  c2_info[73].name = "xlim";
  c2_info[73].dominantType = "double";
  c2_info[73].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/xlim.m";
  c2_info[73].fileTimeLo = 1299479202U;
  c2_info[73].fileTimeHi = 0U;
  c2_info[73].mFileTimeLo = 0U;
  c2_info[73].mFileTimeHi = 0U;
  c2_info[74].context = "";
  c2_info[74].name = "ylim";
  c2_info[74].dominantType = "double";
  c2_info[74].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/ylim.m";
  c2_info[74].fileTimeLo = 1299479202U;
  c2_info[74].fileTimeHi = 0U;
  c2_info[74].mFileTimeLo = 0U;
  c2_info[74].mFileTimeHi = 0U;
  c2_info[75].context = "";
  c2_info[75].name = "zlim";
  c2_info[75].dominantType = "double";
  c2_info[75].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/zlim.m";
  c2_info[75].fileTimeLo = 1299479202U;
  c2_info[75].fileTimeHi = 0U;
  c2_info[75].mFileTimeLo = 0U;
  c2_info[75].mFileTimeHi = 0U;
  c2_info[76].context = "";
  c2_info[76].name = "xlabel";
  c2_info[76].dominantType = "char";
  c2_info[76].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/xlabel.m";
  c2_info[76].fileTimeLo = 1303582146U;
  c2_info[76].fileTimeHi = 0U;
  c2_info[76].mFileTimeLo = 0U;
  c2_info[76].mFileTimeHi = 0U;
  c2_info[77].context = "";
  c2_info[77].name = "ylabel";
  c2_info[77].dominantType = "char";
  c2_info[77].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/ylabel.m";
  c2_info[77].fileTimeLo = 1303582146U;
  c2_info[77].fileTimeHi = 0U;
  c2_info[77].mFileTimeLo = 0U;
  c2_info[77].mFileTimeHi = 0U;
  c2_info[78].context = "";
  c2_info[78].name = "zlabel";
  c2_info[78].dominantType = "char";
  c2_info[78].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/zlabel.m";
  c2_info[78].fileTimeLo = 1303582144U;
  c2_info[78].fileTimeHi = 0U;
  c2_info[78].mFileTimeLo = 0U;
  c2_info[78].mFileTimeHi = 0U;
  c2_info[79].context = "";
  c2_info[79].name = "drawnow";
  c2_info[79].dominantType = "";
  c2_info[79].resolved = "[IXMB]$matlabroot$/toolbox/matlab/graphics/drawnow";
  c2_info[79].fileTimeLo = MAX_uint32_T;
  c2_info[79].fileTimeHi = MAX_uint32_T;
  c2_info[79].mFileTimeLo = MAX_uint32_T;
  c2_info[79].mFileTimeHi = MAX_uint32_T;
}

static void c2_Sphere(SFc2_Lab3InstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[12];
  real_T c2_r1;
  real_T c2_r2;
  real_T c2_r;
  real_T c2_phi;
  real_T c2_phi_;
  real_T c2_theta1[100];
  real_T c2_theta2[100];
  static real_T c2_x[10000];
  static real_T c2_y[10000];
  static real_T c2_z[10000];
  static real_T c2_b_theta1[10000];
  static real_T c2_b_theta2[10000];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  int32_T c2_i105;
  static real_T c2_dv6[100] = { 0.5880026035475675, 0.60785702219902871,
    0.62771144085048991, 0.64756585950195111, 0.66742027815341232,
    0.68727469680487352, 0.70712911545633472, 0.72698353410779593,
    0.746837952759257, 0.76669237141071833, 0.78654679006217942,
    0.80640120871364063, 0.82625562736510183, 0.846110046016563,
    0.86596446466802424, 0.88581888331948544, 0.90567330197094664,
    0.92552772062240785, 0.945382139273869, 0.96523655792533025,
    0.98509097657679145, 1.0049453952282525, 1.0247998138797139,
    1.044654232531175, 1.0645086511826363, 1.0843630698340974,
    1.1042174884855585, 1.1240719071370198, 1.1439263257884811,
    1.1637807444399422, 1.1836351630914033, 1.2034895817428646,
    1.2233440003943259, 1.243198419045787, 1.2630528376972481,
    1.2829072563487094, 1.3027616750001707, 1.3226160936516318,
    1.3424705123030929, 1.3623249309545542, 1.3821793496060155,
    1.4020337682574766, 1.4218881869089377, 1.4417426055603988, 1.46159702421186,
    1.4814514428633214, 1.5013058615147825, 1.5211602801662436,
    1.5410146988177049, 1.5608691174691662, 1.5807235361206273,
    1.6005779547720884, 1.6204323734235495, 1.640286792075011,
    1.6601412107264721, 1.6799956293779332, 1.6998500480293943,
    1.7197044666808559, 1.739558885332317, 1.759413303983778, 1.7792677226352391,
    1.7991221412867007, 1.8189765599381618, 1.8388309785896229,
    1.8586853972410839, 1.878539815892545, 1.8983942345440066,
    1.9182486531954677, 1.9381030718469288, 1.9579574904983899,
    1.9778119091498514, 1.9976663278013125, 2.0175207464527736,
    2.0373751651042347, 2.0572295837556962, 2.0770840024071573,
    2.0969384210586184, 2.1167928397100795, 2.136647258361541,
    2.1565016770130021, 2.1763560956644632, 2.1962105143159243,
    2.2160649329673854, 2.2359193516188469, 2.255773770270308,
    2.2756281889217691, 2.29548260757323, 2.3153370262246917, 2.3351914448761528,
    2.3550458635276139, 2.374900282179075, 2.3947547008305365,
    2.4146091194819976, 2.4344635381334587, 2.45431795678492, 2.4741723754363814,
    2.4940267940878424, 2.5138812127393035, 2.5337356313907646,
    2.5535900500422257 };

  int32_T c2_i106;
  int32_T c2_i107;
  static real_T c2_dv7[10000] = { 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.5880026035475675,
    0.5880026035475675, 0.5880026035475675, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.60785702219902871, 0.60785702219902871, 0.60785702219902871,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.62771144085048991, 0.62771144085048991,
    0.62771144085048991, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.64756585950195111,
    0.64756585950195111, 0.64756585950195111, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.66742027815341232, 0.66742027815341232, 0.66742027815341232,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.68727469680487352, 0.68727469680487352,
    0.68727469680487352, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.70712911545633472,
    0.70712911545633472, 0.70712911545633472, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.72698353410779593, 0.72698353410779593, 0.72698353410779593,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.746837952759257, 0.746837952759257, 0.746837952759257, 0.746837952759257,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.76669237141071833, 0.76669237141071833,
    0.76669237141071833, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.78654679006217942,
    0.78654679006217942, 0.78654679006217942, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.80640120871364063, 0.80640120871364063, 0.80640120871364063,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.82625562736510183, 0.82625562736510183,
    0.82625562736510183, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.846110046016563, 0.846110046016563, 0.846110046016563,
    0.846110046016563, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.86596446466802424,
    0.86596446466802424, 0.86596446466802424, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.88581888331948544, 0.88581888331948544, 0.88581888331948544,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.90567330197094664, 0.90567330197094664,
    0.90567330197094664, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.92552772062240785,
    0.92552772062240785, 0.92552772062240785, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.945382139273869,
    0.945382139273869, 0.945382139273869, 0.945382139273869, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.96523655792533025, 0.96523655792533025, 0.96523655792533025,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 0.98509097657679145, 0.98509097657679145,
    0.98509097657679145, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0049453952282525,
    1.0049453952282525, 1.0049453952282525, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.0247998138797139, 1.0247998138797139, 1.0247998138797139,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.044654232531175, 1.044654232531175, 1.044654232531175, 1.044654232531175,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0645086511826363, 1.0645086511826363,
    1.0645086511826363, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.0843630698340974,
    1.0843630698340974, 1.0843630698340974, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1042174884855585, 1.1042174884855585, 1.1042174884855585,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1240719071370198, 1.1240719071370198,
    1.1240719071370198, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1439263257884811,
    1.1439263257884811, 1.1439263257884811, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1637807444399422, 1.1637807444399422, 1.1637807444399422,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.1836351630914033, 1.1836351630914033,
    1.1836351630914033, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2034895817428646,
    1.2034895817428646, 1.2034895817428646, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.2233440003943259, 1.2233440003943259, 1.2233440003943259,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.243198419045787, 1.243198419045787, 1.243198419045787, 1.243198419045787,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2630528376972481, 1.2630528376972481,
    1.2630528376972481, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.2829072563487094,
    1.2829072563487094, 1.2829072563487094, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3027616750001707, 1.3027616750001707, 1.3027616750001707,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3226160936516318, 1.3226160936516318,
    1.3226160936516318, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3424705123030929,
    1.3424705123030929, 1.3424705123030929, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3623249309545542, 1.3623249309545542, 1.3623249309545542,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.3821793496060155, 1.3821793496060155,
    1.3821793496060155, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4020337682574766,
    1.4020337682574766, 1.4020337682574766, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4218881869089377, 1.4218881869089377, 1.4218881869089377,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.4417426055603988, 1.4417426055603988,
    1.4417426055603988, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.46159702421186, 1.46159702421186, 1.46159702421186,
    1.46159702421186, 1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.4814514428633214, 1.4814514428633214,
    1.4814514428633214, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5013058615147825,
    1.5013058615147825, 1.5013058615147825, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5211602801662436, 1.5211602801662436, 1.5211602801662436,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5410146988177049, 1.5410146988177049,
    1.5410146988177049, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5608691174691662,
    1.5608691174691662, 1.5608691174691662, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.5807235361206273, 1.5807235361206273, 1.5807235361206273,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6005779547720884, 1.6005779547720884,
    1.6005779547720884, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.6204323734235495,
    1.6204323734235495, 1.6204323734235495, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.640286792075011, 1.640286792075011,
    1.640286792075011, 1.640286792075011, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6601412107264721,
    1.6601412107264721, 1.6601412107264721, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6799956293779332, 1.6799956293779332, 1.6799956293779332,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.6998500480293943, 1.6998500480293943,
    1.6998500480293943, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.7197044666808559,
    1.7197044666808559, 1.7197044666808559, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.739558885332317, 1.739558885332317,
    1.739558885332317, 1.739558885332317, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.759413303983778, 1.759413303983778,
    1.759413303983778, 1.759413303983778, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7792677226352391,
    1.7792677226352391, 1.7792677226352391, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.7991221412867007, 1.7991221412867007, 1.7991221412867007,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8189765599381618, 1.8189765599381618,
    1.8189765599381618, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8388309785896229,
    1.8388309785896229, 1.8388309785896229, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.8586853972410839, 1.8586853972410839, 1.8586853972410839,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.878539815892545, 1.878539815892545, 1.878539815892545, 1.878539815892545,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.8983942345440066, 1.8983942345440066,
    1.8983942345440066, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9182486531954677,
    1.9182486531954677, 1.9182486531954677, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9381030718469288, 1.9381030718469288, 1.9381030718469288,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9579574904983899, 1.9579574904983899,
    1.9579574904983899, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9778119091498514,
    1.9778119091498514, 1.9778119091498514, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    1.9976663278013125, 1.9976663278013125, 1.9976663278013125,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0175207464527736, 2.0175207464527736,
    2.0175207464527736, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0373751651042347,
    2.0373751651042347, 2.0373751651042347, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0572295837556962, 2.0572295837556962, 2.0572295837556962,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0770840024071573, 2.0770840024071573,
    2.0770840024071573, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.0969384210586184,
    2.0969384210586184, 2.0969384210586184, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.1167928397100795, 2.1167928397100795, 2.1167928397100795,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.136647258361541, 2.136647258361541, 2.136647258361541, 2.136647258361541,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1565016770130021, 2.1565016770130021,
    2.1565016770130021, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1763560956644632,
    2.1763560956644632, 2.1763560956644632, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.1962105143159243, 2.1962105143159243, 2.1962105143159243,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2160649329673854, 2.2160649329673854,
    2.2160649329673854, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.2359193516188469,
    2.2359193516188469, 2.2359193516188469, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.255773770270308, 2.255773770270308,
    2.255773770270308, 2.255773770270308, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.2756281889217691,
    2.2756281889217691, 2.2756281889217691, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.29548260757323, 2.29548260757323,
    2.29548260757323, 2.29548260757323, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3153370262246917,
    2.3153370262246917, 2.3153370262246917, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3351914448761528, 2.3351914448761528, 2.3351914448761528,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.3550458635276139, 2.3550458635276139,
    2.3550458635276139, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.374900282179075, 2.374900282179075, 2.374900282179075,
    2.374900282179075, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.3947547008305365,
    2.3947547008305365, 2.3947547008305365, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4146091194819976, 2.4146091194819976, 2.4146091194819976,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.4344635381334587, 2.4344635381334587,
    2.4344635381334587, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.45431795678492, 2.45431795678492, 2.45431795678492,
    2.45431795678492, 2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4741723754363814, 2.4741723754363814,
    2.4741723754363814, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.4940267940878424,
    2.4940267940878424, 2.4940267940878424, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5138812127393035, 2.5138812127393035, 2.5138812127393035,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5337356313907646, 2.5337356313907646,
    2.5337356313907646, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257, 2.5535900500422257,
    2.5535900500422257, 2.5535900500422257 };

  int32_T c2_i108;
  static real_T c2_dv8[10000] = { 0.0, 0.063466518254339258, 0.12693303650867852,
    0.19039955476301779, 0.25386607301735703, 0.31733259127169627,
    0.38079910952603557, 0.44426562778037482, 0.50773214603471406,
    0.5711986642890533, 0.63466518254339255, 0.69813170079773179,
    0.76159821905207115, 0.82506473730641039, 0.88853125556074963,
    0.95199777381508888, 1.0154642920694281, 1.0789308103237674,
    1.1423973285781066, 1.2058638468324459, 1.2693303650867851,
    1.3327968833411243, 1.3962634015954636, 1.4597299198498028,
    1.5231964381041423, 1.5866629563584815, 1.6501294746128208, 1.71359599286716,
    1.7770625111214993, 1.8405290293758385, 1.9039955476301778,
    1.967462065884517, 2.0309285841388562, 2.0943951023931957,
    2.1578616206475347, 2.2213281389018742, 2.2847946571562132,
    2.3482611754105527, 2.4117276936648917, 2.4751942119192312, 2.53866073017357,
    2.6021272484279097, 2.6655937666822487, 2.7290602849365881,
    2.7925268031909272, 2.8559933214452666, 2.9194598396996057,
    2.9829263579539451, 3.0463928762082846, 3.1098593944626236,
    3.1733259127169631, 3.2367924309713021, 3.3002589492256416,
    3.3637254674799806, 3.42719198573432, 3.4906585039886591, 3.5541250222429985,
    3.6175915404973376, 3.681058058751677, 3.744524577006016, 3.8079910952603555,
    3.8714576135146945, 3.934924131769034, 3.998390650023373, 4.0618571682777125,
    4.1253236865320515, 4.1887902047863914, 4.25225672304073, 4.3157232412950695,
    4.3791897595494085, 4.4426562778037484, 4.5061227960580874,
    4.5695893143124264, 4.6330558325667655, 4.6965223508211054,
    4.7599888690754444, 4.8234553873297834, 4.8869219055841224,
    4.9503884238384623, 5.0138549420928014, 5.07732146034714, 5.14078797860148,
    5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862, 0.0, 0.063466518254339258,
    0.12693303650867852, 0.19039955476301779, 0.25386607301735703,
    0.31733259127169627, 0.38079910952603557, 0.44426562778037482,
    0.50773214603471406, 0.5711986642890533, 0.63466518254339255,
    0.69813170079773179, 0.76159821905207115, 0.82506473730641039,
    0.88853125556074963, 0.95199777381508888, 1.0154642920694281,
    1.0789308103237674, 1.1423973285781066, 1.2058638468324459,
    1.2693303650867851, 1.3327968833411243, 1.3962634015954636,
    1.4597299198498028, 1.5231964381041423, 1.5866629563584815,
    1.6501294746128208, 1.71359599286716, 1.7770625111214993, 1.8405290293758385,
    1.9039955476301778, 1.967462065884517, 2.0309285841388562,
    2.0943951023931957, 2.1578616206475347, 2.2213281389018742,
    2.2847946571562132, 2.3482611754105527, 2.4117276936648917,
    2.4751942119192312, 2.53866073017357, 2.6021272484279097, 2.6655937666822487,
    2.7290602849365881, 2.7925268031909272, 2.8559933214452666,
    2.9194598396996057, 2.9829263579539451, 3.0463928762082846,
    3.1098593944626236, 3.1733259127169631, 3.2367924309713021,
    3.3002589492256416, 3.3637254674799806, 3.42719198573432, 3.4906585039886591,
    3.5541250222429985, 3.6175915404973376, 3.681058058751677, 3.744524577006016,
    3.8079910952603555, 3.8714576135146945, 3.934924131769034, 3.998390650023373,
    4.0618571682777125, 4.1253236865320515, 4.1887902047863914, 4.25225672304073,
    4.3157232412950695, 4.3791897595494085, 4.4426562778037484,
    4.5061227960580874, 4.5695893143124264, 4.6330558325667655,
    4.6965223508211054, 4.7599888690754444, 4.8234553873297834,
    4.8869219055841224, 4.9503884238384623, 5.0138549420928014, 5.07732146034714,
    5.14078797860148, 5.2042544968558193, 5.2677210151101583, 5.3311875333644974,
    5.3946540516188373, 5.4581205698731763, 5.5215870881275153,
    5.5850536063818543, 5.6485201246361942, 5.7119866428905333,
    5.7754531611448723, 5.8389196793992113, 5.9023861976535512, 5.96585271590789,
    6.0293192341622293, 6.0927857524165692, 6.1562522706709082,
    6.2197187889252472, 6.2831853071795862 };

  int32_T c2_i109;
  static real_T c2_dv9[10000];
  int32_T c2_i110;
  static real_T c2_dv10[10000];
  int32_T c2_i111;
  int32_T c2_i112;
  int32_T c2_i113;
  int32_T c2_i114;
  int32_T c2_i115;
  int32_T c2_i116;
  int32_T c2_i117;
  static real_T c2_u[10000];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i118;
  real_T c2_b_u[10000];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i119;
  real_T c2_c_u[10000];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i120;
  static char_T c2_cv3[2] = { 'o', 'n' };

  char_T c2_d_u[2];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i121;
  char_T c2_e_u[2];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i122;
  real_T c2_f_u[2];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i123;
  real_T c2_g_u[2];
  const mxArray *c2_h_y = NULL;
  int32_T c2_i124;
  real_T c2_h_u[2];
  const mxArray *c2_i_y = NULL;
  char_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  char_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  char_T c2_k_u;
  const mxArray *c2_l_y = NULL;
  int32_T c2_i125;
  char_T c2_l_u[2];
  const mxArray *c2_m_y = NULL;
  int32_T c2_i126;
  real_T c2_m_u[2];
  const mxArray *c2_n_y = NULL;
  int32_T c2_i127;
  real_T c2_n_u[2];
  const mxArray *c2_o_y = NULL;
  int32_T c2_i128;
  real_T c2_o_u[2];
  const mxArray *c2_p_y = NULL;
  char_T c2_p_u;
  const mxArray *c2_q_y = NULL;
  char_T c2_q_u;
  const mxArray *c2_r_y = NULL;
  char_T c2_r_u;
  const mxArray *c2_s_y = NULL;
  int32_T *c2_sfEvent;
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 12U, 14U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_r1, 0U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_r2, 1U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_r, 2U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_phi, 3U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_phi_, 4U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_theta1, MAX_uint32_T, c2_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_theta2, MAX_uint32_T, c2_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_x, 7U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_y, 8U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_z, 9U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_b_theta1, MAX_uint32_T, c2_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_b_theta2, MAX_uint32_T, c2_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 10U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 11U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 11);
  c2_r1 = 8.0;
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 12);
  c2_r2 = 12.0;
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 13);
  c2_r = 208.0;
  c2_b_sqrt(chartInstance, &c2_r);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 14);
  c2_phi = 0.5880026035475675;
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 15);
  c2_phi_ = 0.982793723247329;
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 17);
  for (c2_i105 = 0; c2_i105 < 100; c2_i105++) {
    c2_theta1[c2_i105] = c2_dv6[c2_i105];
  }

  sf_debug_symbol_switch(5U, 5U);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 18);
  for (c2_i106 = 0; c2_i106 < 100; c2_i106++) {
    c2_theta2[c2_i106] = 0.063466518254339258 * (real_T)c2_i106;
  }

  sf_debug_symbol_switch(6U, 6U);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 19);
  for (c2_i107 = 0; c2_i107 < 10000; c2_i107++) {
    c2_b_theta1[c2_i107] = c2_dv7[c2_i107];
  }

  sf_debug_symbol_switch(5U, 10U);
  for (c2_i108 = 0; c2_i108 < 10000; c2_i108++) {
    c2_b_theta2[c2_i108] = c2_dv8[c2_i108];
  }

  sf_debug_symbol_switch(6U, 11U);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 22);
  for (c2_i109 = 0; c2_i109 < 10000; c2_i109++) {
    c2_dv9[c2_i109] = c2_dv7[c2_i109];
  }

  c2_b_sin(chartInstance, c2_dv9);
  for (c2_i110 = 0; c2_i110 < 10000; c2_i110++) {
    c2_dv10[c2_i110] = c2_dv8[c2_i110];
  }

  c2_b_cos(chartInstance, c2_dv10);
  for (c2_i111 = 0; c2_i111 < 10000; c2_i111++) {
    c2_x[c2_i111] = c2_r * c2_dv9[c2_i111] * c2_dv10[c2_i111];
  }

  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 23);
  for (c2_i112 = 0; c2_i112 < 10000; c2_i112++) {
    c2_dv9[c2_i112] = c2_dv7[c2_i112];
  }

  c2_b_sin(chartInstance, c2_dv9);
  for (c2_i113 = 0; c2_i113 < 10000; c2_i113++) {
    c2_dv10[c2_i113] = c2_dv8[c2_i113];
  }

  c2_b_sin(chartInstance, c2_dv10);
  for (c2_i114 = 0; c2_i114 < 10000; c2_i114++) {
    c2_y[c2_i114] = c2_r * c2_dv9[c2_i114] * c2_dv10[c2_i114];
  }

  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 24);
  for (c2_i115 = 0; c2_i115 < 10000; c2_i115++) {
    c2_dv9[c2_i115] = c2_dv7[c2_i115];
  }

  c2_b_cos(chartInstance, c2_dv9);
  for (c2_i116 = 0; c2_i116 < 10000; c2_i116++) {
    c2_z[c2_i116] = c2_r * c2_dv9[c2_i116];
  }

  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 25);
  for (c2_i117 = 0; c2_i117 < 10000; c2_i117++) {
    c2_u[c2_i117] = c2_x[c2_i117];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  for (c2_i118 = 0; c2_i118 < 10000; c2_i118++) {
    c2_b_u[c2_i118] = c2_y[c2_i118];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  for (c2_i119 = 0; c2_i119 < 10000; c2_i119++) {
    c2_c_u[c2_i119] = c2_z[c2_i119];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  sf_mex_call_debug("mesh", 0U, 3U, 14, c2_b_y, 14, c2_c_y, 14, c2_d_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 26);
  for (c2_i120 = 0; c2_i120 < 2; c2_i120++) {
    c2_d_u[c2_i120] = c2_cv3[c2_i120];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("hold", 0U, 1U, 14, c2_e_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 27);
  for (c2_i121 = 0; c2_i121 < 2; c2_i121++) {
    c2_e_u[c2_i121] = c2_cv3[c2_i121];
  }

  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_e_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("grid", 0U, 1U, 14, c2_f_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 27);
  for (c2_i122 = 0; c2_i122 < 2; c2_i122++) {
    c2_f_u[c2_i122] = -10.0 + 20.0 * (real_T)c2_i122;
  }

  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_f_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("xlim", 0U, 1U, 14, c2_g_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 27);
  for (c2_i123 = 0; c2_i123 < 2; c2_i123++) {
    c2_g_u[c2_i123] = -10.0 + 20.0 * (real_T)c2_i123;
  }

  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_g_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("ylim", 0U, 1U, 14, c2_h_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 27);
  for (c2_i124 = 0; c2_i124 < 2; c2_i124++) {
    c2_h_u[c2_i124] = -10.0 + 20.0 * (real_T)c2_i124;
  }

  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_h_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("zlim", 0U, 1U, 14, c2_i_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 27);
  c2_i_u = 'x';
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("xlabel", 0U, 1U, 14, c2_j_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 27);
  c2_j_u = 'y';
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("ylabel", 0U, 1U, 14, c2_k_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 27);
  c2_k_u = 'z';
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_k_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("zlabel", 0U, 1U, 14, c2_l_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 29);
  for (c2_i125 = 0; c2_i125 < 2; c2_i125++) {
    c2_l_u[c2_i125] = c2_cv3[c2_i125];
  }

  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_l_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("grid", 0U, 1U, 14, c2_m_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 29);
  for (c2_i126 = 0; c2_i126 < 2; c2_i126++) {
    c2_m_u[c2_i126] = -10.0 + 20.0 * (real_T)c2_i126;
  }

  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_m_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("xlim", 0U, 1U, 14, c2_n_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 29);
  for (c2_i127 = 0; c2_i127 < 2; c2_i127++) {
    c2_n_u[c2_i127] = -10.0 + 20.0 * (real_T)c2_i127;
  }

  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", c2_n_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("ylim", 0U, 1U, 14, c2_o_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 29);
  for (c2_i128 = 0; c2_i128 < 2; c2_i128++) {
    c2_o_u[c2_i128] = -10.0 + 20.0 * (real_T)c2_i128;
  }

  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", c2_o_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("zlim", 0U, 1U, 14, c2_p_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 29);
  c2_p_u = 'x';
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_p_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("xlabel", 0U, 1U, 14, c2_q_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 29);
  c2_q_u = 'y';
  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_q_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("ylabel", 0U, 1U, 14, c2_r_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 29);
  c2_r_u = 'z';
  c2_s_y = NULL;
  sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_r_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("zlabel", 0U, 1U, 14, c2_s_y);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, -29);
  sf_debug_symbol_scope_pop();
}

static real_T c2_sqrt(SFc2_Lab3InstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void c2_eml_error(SFc2_Lab3InstanceStruct *chartInstance)
{
  int32_T c2_i129;
  static char_T c2_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  for (c2_i129 = 0; c2_i129 < 30; c2_i129++) {
    c2_u[c2_i129] = c2_varargin_1[c2_i129];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static void c2_sin(SFc2_Lab3InstanceStruct *chartInstance, real_T c2_x[10000],
                   real_T c2_b_x[10000])
{
  int32_T c2_i130;
  for (c2_i130 = 0; c2_i130 < 10000; c2_i130++) {
    c2_b_x[c2_i130] = c2_x[c2_i130];
  }

  c2_b_sin(chartInstance, c2_b_x);
}

static void c2_cos(SFc2_Lab3InstanceStruct *chartInstance, real_T c2_x[10000],
                   real_T c2_b_x[10000])
{
  int32_T c2_i131;
  for (c2_i131 = 0; c2_i131 < 10000; c2_i131++) {
    c2_b_x[c2_i131] = c2_x[c2_i131];
  }

  c2_b_cos(chartInstance, c2_b_x);
}

static void c2_eml_scalar_eg(SFc2_Lab3InstanceStruct *chartInstance)
{
}

static void c2_b_eml_scalar_eg(SFc2_Lab3InstanceStruct *chartInstance)
{
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i132;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i132, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i132;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)chartInstanceVoid;
  c2_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance,
  const mxArray *c2_is_active_c2_Lab3, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_is_active_c2_Lab3),
    &c2_thisId);
  sf_mex_destroy(&c2_is_active_c2_Lab3);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_Lab3InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sqrt(SFc2_Lab3InstanceStruct *chartInstance, real_T *c2_x)
{
  if (*c2_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void c2_b_sin(SFc2_Lab3InstanceStruct *chartInstance, real_T c2_x[10000])
{
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_b_x;
  real_T c2_c_x;
  for (c2_k = 0; c2_k < 10000; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_b_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_k), 1, 10000, 1, 0) - 1];
    c2_c_x = c2_b_x;
    c2_c_x = muDoubleScalarSin(c2_c_x);
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_k),
      1, 10000, 1, 0) - 1] = c2_c_x;
  }
}

static void c2_b_cos(SFc2_Lab3InstanceStruct *chartInstance, real_T c2_x[10000])
{
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_b_x;
  real_T c2_c_x;
  for (c2_k = 0; c2_k < 10000; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_b_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_k), 1, 10000, 1, 0) - 1];
    c2_c_x = c2_b_x;
    c2_c_x = muDoubleScalarCos(c2_c_x);
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_k),
      1, 10000, 1, 0) - 1] = c2_c_x;
  }
}

static void init_dsm_address_info(SFc2_Lab3InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c2_Lab3_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1201651821U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(181394342U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2850593408U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3220816632U);
}

mxArray *sf_c2_Lab3_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("TrP3X6tHFDH9iXU8nArM1E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_Lab3(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c2_Lab3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Lab3_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Lab3InstanceStruct *chartInstance;
    chartInstance = (SFc2_Lab3InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_Lab3MachineNumber_,
          2,
          1,
          1,
          1,
          0,
          0,
          0,
          0,
          1,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_Lab3MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_Lab3MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Lab3MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"array");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,815);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"Sphere",0,-1,720);
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
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c2_array)[2];
          c2_array = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_array);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_Lab3MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "D8R39IA9Ty7SarDzMPreYG";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Lab3_optimization_info();
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

static void sf_opaque_initialize_c2_Lab3(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc2_Lab3InstanceStruct*) chartInstanceVar)->S);
  chart_debug_initialization(((SFc2_Lab3InstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_Lab3((SFc2_Lab3InstanceStruct*) chartInstanceVar);
  initialize_c2_Lab3((SFc2_Lab3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_Lab3(void *chartInstanceVar)
{
  enable_c2_Lab3((SFc2_Lab3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_Lab3(void *chartInstanceVar)
{
  disable_c2_Lab3((SFc2_Lab3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_Lab3(void *chartInstanceVar)
{
  sf_c2_Lab3((SFc2_Lab3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c2_Lab3(void *chartInstanceVar)
{
  ext_mode_exec_c2_Lab3((SFc2_Lab3InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Lab3(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Lab3((SFc2_Lab3InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Lab3();/* state var info */
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

extern void sf_internal_set_sim_state_c2_Lab3(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Lab3();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Lab3((SFc2_Lab3InstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Lab3(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_Lab3(S);
}

static void sf_opaque_set_sim_state_c2_Lab3(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_Lab3(S, st);
}

static void sf_opaque_terminate_c2_Lab3(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Lab3InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_Lab3((SFc2_Lab3InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Lab3_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Lab3((SFc2_Lab3InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Lab3(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Lab3((SFc2_Lab3InstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c2_Lab3_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c2_Lab3\",T\"is_active_c2_Lab3\"}}"
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

static void mdlSetWorkWidths_c2_Lab3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Lab3_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(796262182U));
  ssSetChecksum1(S,(452322184U));
  ssSetChecksum2(S,(1180000821U));
  ssSetChecksum3(S,(1569392044U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_Lab3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Lab3(SimStruct *S)
{
  SFc2_Lab3InstanceStruct *chartInstance;
  chartInstance = (SFc2_Lab3InstanceStruct *)malloc(sizeof
    (SFc2_Lab3InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_Lab3InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_Lab3;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_Lab3;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_Lab3;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_Lab3;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_Lab3;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_Lab3;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_Lab3;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_Lab3;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Lab3;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Lab3;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_Lab3;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c2_Lab3;
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

void c2_Lab3_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Lab3(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Lab3(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Lab3(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Lab3_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
