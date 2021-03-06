/* Include files */

#include "blascompat32.h"
#include "Lab4_sfun.h"
#include "c1_Lab4.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Lab4_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[20] = { "theta1", "theta2", "L1", "L2",
  "P0_Org", "P1_Org", "P2_Org", "P3_Org", "P4_Org", "P5_Org", "T01", "P1", "P2",
  "P3", "P4", "T12", "P5", "nargin", "nargout", "X" };

/* Function Declarations */
static void initialize_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance);
static void initialize_params_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance);
static void enable_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance);
static void disable_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_Lab4(SFc1_Lab4InstanceStruct
  *chartInstance);
static void ext_mode_exec_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Lab4(SFc1_Lab4InstanceStruct
  *chartInstance);
static void set_sim_state_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance, const
  mxArray *c1_st);
static void finalize_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance);
static void sf_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance);
static void c1_chartstep_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance);
static void initSimStructsc1_Lab4(SFc1_Lab4InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_b_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[16]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[22]);
static void c1_eml_scalar_eg(SFc1_Lab4InstanceStruct *chartInstance);
static void c1_b_eml_scalar_eg(SFc1_Lab4InstanceStruct *chartInstance);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance,
  const mxArray *c1_is_active_c1_Lab4, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_Lab4InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance)
{
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_Lab4;
  c1_is_active_c1_Lab4 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_is_active_c1_Lab4 = 0U;
}

static void initialize_params_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance)
{
}

static void enable_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_Lab4(SFc1_Lab4InstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance)
{
  c1_update_debugger_state_c1_Lab4(chartInstance);
}

static const mxArray *get_sim_state_c1_Lab4(SFc1_Lab4InstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T *c1_is_active_c1_Lab4;
  c1_is_active_c1_Lab4 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(1), FALSE);
  c1_hoistedGlobal = *c1_is_active_c1_Lab4;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance, const
  mxArray *c1_st)
{
  const mxArray *c1_u;
  boolean_T *c1_doneDoubleBufferReInit;
  uint8_T *c1_is_active_c1_Lab4;
  c1_is_active_c1_Lab4 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_is_active_c1_Lab4 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "is_active_c1_Lab4");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Lab4(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance)
{
}

static void sf_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T *c1_sfEvent;
  real_T (*c1_X)[4];
  c1_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c1_sfEvent);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_X)[c1_i0], 0U);
  }

  *c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_Lab4(chartInstance);
  sf_debug_check_for_state_inconsistency(_Lab4MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_Lab4(SFc1_Lab4InstanceStruct *chartInstance)
{
  int32_T c1_i1;
  real_T c1_X[4];
  uint32_T c1_debug_family_var_map[20];
  real_T c1_theta1;
  real_T c1_theta2;
  real_T c1_L1;
  real_T c1_L2;
  real_T c1_P0_Org[4];
  real_T c1_P1_Org[4];
  real_T c1_P2_Org[4];
  real_T c1_P3_Org[4];
  real_T c1_P4_Org[4];
  real_T c1_P5_Org[4];
  real_T c1_T01[16];
  real_T c1_P1[4];
  real_T c1_P2[4];
  real_T c1_P3[4];
  real_T c1_P4[4];
  real_T c1_T12[16];
  real_T c1_P5[4];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 0.0;
  int32_T c1_i2;
  static real_T c1_dv0[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c1_i3;
  static real_T c1_b[4] = { 0.0, 0.0, -1.0, 1.0 };

  int32_T c1_i4;
  static real_T c1_b_b[4] = { 0.0, 6.0, -1.0, 1.0 };

  int32_T c1_i5;
  static real_T c1_c_b[4] = { 0.0, 6.0, 0.0, 1.0 };

  int32_T c1_i6;
  static real_T c1_d_b[4] = { 0.0, 8.0, 0.0, 1.0 };

  int32_T c1_i7;
  static real_T c1_e_b[4] = { 0.0, 12.0, 0.0, 1.0 };

  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  int32_T c1_i8;
  int32_T c1_i9;
  static real_T c1_dv1[4] = { 0.0, 0.0, 1.0, 0.0 };

  int32_T c1_i10;
  int32_T c1_i11;
  static real_T c1_dv2[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c1_i12;
  real_T c1_a[16];
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  real_T c1_C[4];
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  real_T c1_f_b[16];
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  real_T c1_y[16];
  int32_T c1_i59;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  real_T c1_u[6];
  const mxArray *c1_b_y = NULL;
  real_T c1_b_u[6];
  const mxArray *c1_c_y = NULL;
  real_T c1_c_u[6];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i70;
  static char_T c1_cv0[2] = { '-', 'o' };

  char_T c1_d_u[2];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i71;
  static char_T c1_cv1[20] = { 'R', 'o', 'b', 'o', 't', ' ', 'R', 'e', 'p', 'r',
    'e', 's', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n' };

  char_T c1_e_u[20];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i72;
  static char_T c1_cv2[2] = { 'o', 'n' };

  char_T c1_f_u[2];
  const mxArray *c1_g_y = NULL;
  int32_T c1_i73;
  real_T c1_g_u[2];
  const mxArray *c1_h_y = NULL;
  int32_T c1_i74;
  real_T c1_h_u[2];
  const mxArray *c1_i_y = NULL;
  int32_T c1_i75;
  real_T c1_i_u[2];
  const mxArray *c1_j_y = NULL;
  char_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  char_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  char_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  real_T (*c1_b_X)[4];
  int32_T *c1_sfEvent;
  c1_b_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    c1_X[c1_i1] = (*c1_b_X)[c1_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 20U, 20U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta1, 0U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta2, 1U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L1, 2U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L2, 3U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_P0_Org, 4U, c1_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_P1_Org, 5U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_P2_Org, 6U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_P3_Org, 7U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_P4_Org, 8U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_P5_Org, 9U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_T01, 10U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_P1, 11U, c1_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_P2, 12U, c1_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_P3, 13U, c1_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_P4, 14U, c1_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_T12, 15U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_P5, 16U, c1_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 17U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 18U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_X, 19U, c1_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c1_sfEvent, 2);
  c1_theta1 = c1_X[0];
  _SFD_EML_CALL(0U, *c1_sfEvent, 3);
  c1_theta2 = c1_X[2];
  _SFD_EML_CALL(0U, *c1_sfEvent, 5);
  c1_L1 = 6.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 6);
  c1_L2 = 2.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 7);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    c1_P0_Org[c1_i2] = c1_dv0[c1_i2];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 8);
  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    c1_P1_Org[c1_i3] = c1_b[c1_i3];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 9);
  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    c1_P2_Org[c1_i4] = c1_b_b[c1_i4];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 10);
  for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
    c1_P3_Org[c1_i5] = c1_c_b[c1_i5];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 11);
  for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
    c1_P4_Org[c1_i6] = c1_d_b[c1_i6];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 12);
  for (c1_i7 = 0; c1_i7 < 4; c1_i7++) {
    c1_P5_Org[c1_i7] = c1_e_b[c1_i7];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 17);
  c1_x = c1_theta1;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_c_x = c1_theta1;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarSin(c1_d_x);
  c1_e_x = c1_theta1;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarSin(c1_f_x);
  c1_g_x = c1_theta1;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarCos(c1_h_x);
  c1_T01[0] = c1_b_x;
  c1_T01[4] = -c1_d_x;
  c1_T01[8] = 0.0;
  c1_T01[12] = 0.0;
  c1_T01[1] = c1_f_x;
  c1_T01[5] = c1_h_x;
  c1_T01[9] = 0.0;
  c1_T01[13] = 0.0;
  c1_i8 = 0;
  for (c1_i9 = 0; c1_i9 < 4; c1_i9++) {
    c1_T01[c1_i8 + 2] = c1_dv1[c1_i9];
    c1_i8 += 4;
  }

  c1_i10 = 0;
  for (c1_i11 = 0; c1_i11 < 4; c1_i11++) {
    c1_T01[c1_i10 + 3] = c1_dv2[c1_i11];
    c1_i10 += 4;
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 18);
  for (c1_i12 = 0; c1_i12 < 16; c1_i12++) {
    c1_a[c1_i12] = c1_T01[c1_i12];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i13 = 0; c1_i13 < 4; c1_i13++) {
    c1_P1[c1_i13] = 0.0;
  }

  for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
    c1_P1[c1_i14] = 0.0;
  }

  for (c1_i15 = 0; c1_i15 < 4; c1_i15++) {
    c1_C[c1_i15] = c1_P1[c1_i15];
  }

  for (c1_i16 = 0; c1_i16 < 4; c1_i16++) {
    c1_P1[c1_i16] = c1_C[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 4; c1_i17++) {
    c1_C[c1_i17] = c1_P1[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 4; c1_i18++) {
    c1_P1[c1_i18] = c1_C[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 4; c1_i19++) {
    c1_P1[c1_i19] = 0.0;
    c1_i20 = 0;
    for (c1_i21 = 0; c1_i21 < 4; c1_i21++) {
      c1_P1[c1_i19] += c1_a[c1_i20 + c1_i19] * c1_b[c1_i21];
      c1_i20 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 19);
  for (c1_i22 = 0; c1_i22 < 16; c1_i22++) {
    c1_a[c1_i22] = c1_T01[c1_i22];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
    c1_P2[c1_i23] = 0.0;
  }

  for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
    c1_P2[c1_i24] = 0.0;
  }

  for (c1_i25 = 0; c1_i25 < 4; c1_i25++) {
    c1_C[c1_i25] = c1_P2[c1_i25];
  }

  for (c1_i26 = 0; c1_i26 < 4; c1_i26++) {
    c1_P2[c1_i26] = c1_C[c1_i26];
  }

  for (c1_i27 = 0; c1_i27 < 4; c1_i27++) {
    c1_C[c1_i27] = c1_P2[c1_i27];
  }

  for (c1_i28 = 0; c1_i28 < 4; c1_i28++) {
    c1_P2[c1_i28] = c1_C[c1_i28];
  }

  for (c1_i29 = 0; c1_i29 < 4; c1_i29++) {
    c1_P2[c1_i29] = 0.0;
    c1_i30 = 0;
    for (c1_i31 = 0; c1_i31 < 4; c1_i31++) {
      c1_P2[c1_i29] += c1_a[c1_i30 + c1_i29] * c1_b_b[c1_i31];
      c1_i30 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 20);
  for (c1_i32 = 0; c1_i32 < 16; c1_i32++) {
    c1_a[c1_i32] = c1_T01[c1_i32];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i33 = 0; c1_i33 < 4; c1_i33++) {
    c1_P3[c1_i33] = 0.0;
  }

  for (c1_i34 = 0; c1_i34 < 4; c1_i34++) {
    c1_P3[c1_i34] = 0.0;
  }

  for (c1_i35 = 0; c1_i35 < 4; c1_i35++) {
    c1_C[c1_i35] = c1_P3[c1_i35];
  }

  for (c1_i36 = 0; c1_i36 < 4; c1_i36++) {
    c1_P3[c1_i36] = c1_C[c1_i36];
  }

  for (c1_i37 = 0; c1_i37 < 4; c1_i37++) {
    c1_C[c1_i37] = c1_P3[c1_i37];
  }

  for (c1_i38 = 0; c1_i38 < 4; c1_i38++) {
    c1_P3[c1_i38] = c1_C[c1_i38];
  }

  for (c1_i39 = 0; c1_i39 < 4; c1_i39++) {
    c1_P3[c1_i39] = 0.0;
    c1_i40 = 0;
    for (c1_i41 = 0; c1_i41 < 4; c1_i41++) {
      c1_P3[c1_i39] += c1_a[c1_i40 + c1_i39] * c1_c_b[c1_i41];
      c1_i40 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 21);
  for (c1_i42 = 0; c1_i42 < 16; c1_i42++) {
    c1_a[c1_i42] = c1_T01[c1_i42];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i43 = 0; c1_i43 < 4; c1_i43++) {
    c1_P4[c1_i43] = 0.0;
  }

  for (c1_i44 = 0; c1_i44 < 4; c1_i44++) {
    c1_P4[c1_i44] = 0.0;
  }

  for (c1_i45 = 0; c1_i45 < 4; c1_i45++) {
    c1_C[c1_i45] = c1_P4[c1_i45];
  }

  for (c1_i46 = 0; c1_i46 < 4; c1_i46++) {
    c1_P4[c1_i46] = c1_C[c1_i46];
  }

  for (c1_i47 = 0; c1_i47 < 4; c1_i47++) {
    c1_C[c1_i47] = c1_P4[c1_i47];
  }

  for (c1_i48 = 0; c1_i48 < 4; c1_i48++) {
    c1_P4[c1_i48] = c1_C[c1_i48];
  }

  for (c1_i49 = 0; c1_i49 < 4; c1_i49++) {
    c1_P4[c1_i49] = 0.0;
    c1_i50 = 0;
    for (c1_i51 = 0; c1_i51 < 4; c1_i51++) {
      c1_P4[c1_i49] += c1_a[c1_i50 + c1_i49] * c1_d_b[c1_i51];
      c1_i50 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 22);
  c1_i_x = c1_theta2;
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarCos(c1_j_x);
  c1_k_x = c1_theta2;
  c1_l_x = c1_k_x;
  c1_l_x = muDoubleScalarSin(c1_l_x);
  c1_m_x = c1_theta2;
  c1_n_x = c1_m_x;
  c1_n_x = muDoubleScalarSin(c1_n_x);
  c1_o_x = c1_theta2;
  c1_p_x = c1_o_x;
  c1_p_x = muDoubleScalarCos(c1_p_x);
  c1_T12[0] = c1_j_x;
  c1_T12[4] = -c1_l_x;
  c1_T12[8] = 0.0;
  c1_T12[12] = 0.0;
  c1_T12[1] = 0.0;
  c1_T12[5] = 0.0;
  c1_T12[9] = -1.0;
  c1_T12[13] = c1_L1 + c1_L2;
  c1_T12[2] = c1_n_x;
  c1_T12[6] = c1_p_x;
  c1_T12[10] = 0.0;
  c1_T12[14] = 0.0;
  c1_i52 = 0;
  for (c1_i53 = 0; c1_i53 < 4; c1_i53++) {
    c1_T12[c1_i52 + 3] = c1_dv2[c1_i53];
    c1_i52 += 4;
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 23);
  for (c1_i54 = 0; c1_i54 < 16; c1_i54++) {
    c1_a[c1_i54] = c1_T01[c1_i54];
  }

  for (c1_i55 = 0; c1_i55 < 16; c1_i55++) {
    c1_f_b[c1_i55] = c1_T12[c1_i55];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i56 = 0; c1_i56 < 4; c1_i56++) {
    c1_i57 = 0;
    for (c1_i58 = 0; c1_i58 < 4; c1_i58++) {
      c1_y[c1_i57 + c1_i56] = 0.0;
      c1_i59 = 0;
      for (c1_i60 = 0; c1_i60 < 4; c1_i60++) {
        c1_y[c1_i57 + c1_i56] += c1_a[c1_i59 + c1_i56] * c1_f_b[c1_i60 + c1_i57];
        c1_i59 += 4;
      }

      c1_i57 += 4;
    }
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i61 = 0; c1_i61 < 4; c1_i61++) {
    c1_P5[c1_i61] = 0.0;
  }

  for (c1_i62 = 0; c1_i62 < 4; c1_i62++) {
    c1_P5[c1_i62] = 0.0;
  }

  for (c1_i63 = 0; c1_i63 < 4; c1_i63++) {
    c1_C[c1_i63] = c1_P5[c1_i63];
  }

  for (c1_i64 = 0; c1_i64 < 4; c1_i64++) {
    c1_P5[c1_i64] = c1_C[c1_i64];
  }

  for (c1_i65 = 0; c1_i65 < 4; c1_i65++) {
    c1_C[c1_i65] = c1_P5[c1_i65];
  }

  for (c1_i66 = 0; c1_i66 < 4; c1_i66++) {
    c1_P5[c1_i66] = c1_C[c1_i66];
  }

  for (c1_i67 = 0; c1_i67 < 4; c1_i67++) {
    c1_P5[c1_i67] = 0.0;
    c1_i68 = 0;
    for (c1_i69 = 0; c1_i69 < 4; c1_i69++) {
      c1_P5[c1_i67] += c1_y[c1_i68 + c1_i67] * c1_e_b[c1_i69];
      c1_i68 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 25);
  c1_u[0] = c1_P0_Org[0];
  c1_u[1] = c1_P1[0];
  c1_u[2] = c1_P2[0];
  c1_u[3] = c1_P3[0];
  c1_u[4] = c1_P4[0];
  c1_u[5] = c1_P5[0];
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  c1_b_u[0] = c1_P0_Org[1];
  c1_b_u[1] = c1_P1[1];
  c1_b_u[2] = c1_P2[1];
  c1_b_u[3] = c1_P3[1];
  c1_b_u[4] = c1_P4[1];
  c1_b_u[5] = c1_P5[1];
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  c1_c_u[0] = c1_P0_Org[2];
  c1_c_u[1] = c1_P1[2];
  c1_c_u[2] = c1_P2[2];
  c1_c_u[3] = c1_P3[2];
  c1_c_u[4] = c1_P4[2];
  c1_c_u[5] = c1_P5[2];
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  for (c1_i70 = 0; c1_i70 < 2; c1_i70++) {
    c1_d_u[c1_i70] = c1_cv0[c1_i70];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_d_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("plot3", 0U, 4U, 14, c1_b_y, 14, c1_c_y, 14, c1_d_y, 14,
                    c1_e_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 26);
  for (c1_i71 = 0; c1_i71 < 20; c1_i71++) {
    c1_e_u[c1_i71] = c1_cv1[c1_i71];
  }

  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_e_u, 10, 0U, 1U, 0U, 2, 1, 20),
                FALSE);
  sf_mex_call_debug("title", 0U, 1U, 14, c1_f_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 26);
  for (c1_i72 = 0; c1_i72 < 2; c1_i72++) {
    c1_f_u[c1_i72] = c1_cv2[c1_i72];
  }

  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_f_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("grid", 0U, 1U, 14, c1_g_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 26);
  for (c1_i73 = 0; c1_i73 < 2; c1_i73++) {
    c1_g_u[c1_i73] = -10.0 + 20.0 * (real_T)c1_i73;
  }

  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_g_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("xlim", 0U, 1U, 14, c1_h_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 26);
  for (c1_i74 = 0; c1_i74 < 2; c1_i74++) {
    c1_h_u[c1_i74] = -10.0 + 20.0 * (real_T)c1_i74;
  }

  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_h_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("ylim", 0U, 1U, 14, c1_i_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 26);
  for (c1_i75 = 0; c1_i75 < 2; c1_i75++) {
    c1_i_u[c1_i75] = -10.0 + 20.0 * (real_T)c1_i75;
  }

  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_i_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("zlim", 0U, 1U, 14, c1_j_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 26);
  c1_j_u = 'x';
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("xlabel", 0U, 1U, 14, c1_k_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 26);
  c1_k_u = 'y';
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("ylabel", 0U, 1U, 14, c1_l_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 26);
  c1_l_u = 'z';
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("zlabel", 0U, 1U, 14, c1_m_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, -26);
  sf_debug_symbol_scope_pop();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
}

static void initSimStructsc1_Lab4(SFc1_Lab4InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i76;
  real_T c1_b_inData[4];
  int32_T c1_i77;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_Lab4InstanceStruct *chartInstance;
  chartInstance = (SFc1_Lab4InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i76 = 0; c1_i76 < 4; c1_i76++) {
    c1_b_inData[c1_i76] = (*(real_T (*)[4])c1_inData)[c1_i76];
  }

  for (c1_i77 = 0; c1_i77 < 4; c1_i77++) {
    c1_u[c1_i77] = c1_b_inData[c1_i77];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Lab4InstanceStruct *chartInstance;
  chartInstance = (SFc1_Lab4InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_Lab4InstanceStruct *chartInstance;
  chartInstance = (SFc1_Lab4InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_b_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv3[4];
  int32_T c1_i78;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i78 = 0; c1_i78 < 4; c1_i78++) {
    c1_y[c1_i78] = c1_dv3[c1_i78];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_P5;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i79;
  SFc1_Lab4InstanceStruct *chartInstance;
  chartInstance = (SFc1_Lab4InstanceStruct *)chartInstanceVoid;
  c1_P5 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_P5), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_P5);
  for (c1_i79 = 0; c1_i79 < 4; c1_i79++) {
    (*(real_T (*)[4])c1_outData)[c1_i79] = c1_y[c1_i79];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  real_T c1_b_inData[16];
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  real_T c1_u[16];
  const mxArray *c1_y = NULL;
  SFc1_Lab4InstanceStruct *chartInstance;
  chartInstance = (SFc1_Lab4InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i80 = 0;
  for (c1_i81 = 0; c1_i81 < 4; c1_i81++) {
    for (c1_i82 = 0; c1_i82 < 4; c1_i82++) {
      c1_b_inData[c1_i82 + c1_i80] = (*(real_T (*)[16])c1_inData)[c1_i82 +
        c1_i80];
    }

    c1_i80 += 4;
  }

  c1_i83 = 0;
  for (c1_i84 = 0; c1_i84 < 4; c1_i84++) {
    for (c1_i85 = 0; c1_i85 < 4; c1_i85++) {
      c1_u[c1_i85 + c1_i83] = c1_b_inData[c1_i85 + c1_i83];
    }

    c1_i83 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[16])
{
  real_T c1_dv4[16];
  int32_T c1_i86;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c1_i86 = 0; c1_i86 < 16; c1_i86++) {
    c1_y[c1_i86] = c1_dv4[c1_i86];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_T12;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[16];
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  SFc1_Lab4InstanceStruct *chartInstance;
  chartInstance = (SFc1_Lab4InstanceStruct *)chartInstanceVoid;
  c1_T12 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_T12), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_T12);
  c1_i87 = 0;
  for (c1_i88 = 0; c1_i88 < 4; c1_i88++) {
    for (c1_i89 = 0; c1_i89 < 4; c1_i89++) {
      (*(real_T (*)[16])c1_outData)[c1_i89 + c1_i87] = c1_y[c1_i89 + c1_i87];
    }

    c1_i87 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_Lab4_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[22];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i90;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 22), FALSE);
  for (c1_i90 = 0; c1_i90 < 22; c1_i90++) {
    c1_r0 = &c1_info[c1_i90];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i90);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i90);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i90);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i90);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i90);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i90);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i90);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i90);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[22])
{
  c1_info[0].context = "";
  c1_info[0].name = "cos";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[0].fileTimeLo = 1286843906U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[1].name = "eml_scalar_cos";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[1].fileTimeLo = 1286843922U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "";
  c1_info[2].name = "sin";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[2].fileTimeLo = 1286843950U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[3].name = "eml_scalar_sin";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[3].fileTimeLo = 1286843936U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "";
  c1_info[4].name = "mtimes";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[4].fileTimeLo = 1289544892U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[5].name = "eml_index_class";
  c1_info[5].dominantType = "";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[5].fileTimeLo = 1323195778U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[6].name = "eml_scalar_eg";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[6].fileTimeLo = 1286843996U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[7].name = "eml_xgemm";
  c1_info[7].dominantType = "char";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[7].fileTimeLo = 1299101972U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[8].name = "eml_blas_inline";
  c1_info[8].dominantType = "";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[8].fileTimeLo = 1299101968U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[9].name = "mtimes";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].fileTimeLo = 1289544892U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[10].name = "eml_index_class";
  c1_info[10].dominantType = "";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[10].fileTimeLo = 1323195778U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[11].name = "eml_scalar_eg";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[11].fileTimeLo = 1286843996U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[12].name = "eml_refblas_xgemm";
  c1_info[12].dominantType = "char";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[12].fileTimeLo = 1299101974U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context = "";
  c1_info[13].name = "plot3";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[IXMB]$matlabroot$/toolbox/matlab/graph3d/plot3";
  c1_info[13].fileTimeLo = MAX_uint32_T;
  c1_info[13].fileTimeHi = MAX_uint32_T;
  c1_info[13].mFileTimeLo = MAX_uint32_T;
  c1_info[13].mFileTimeHi = MAX_uint32_T;
  c1_info[14].context = "";
  c1_info[14].name = "title";
  c1_info[14].dominantType = "char";
  c1_info[14].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/title.m";
  c1_info[14].fileTimeLo = 1303582146U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context = "";
  c1_info[15].name = "grid";
  c1_info[15].dominantType = "char";
  c1_info[15].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/grid.m";
  c1_info[15].fileTimeLo = 1311280766U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context = "";
  c1_info[16].name = "xlim";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/xlim.m";
  c1_info[16].fileTimeLo = 1299479202U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context = "";
  c1_info[17].name = "ylim";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/ylim.m";
  c1_info[17].fileTimeLo = 1299479202U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context = "";
  c1_info[18].name = "zlim";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/zlim.m";
  c1_info[18].fileTimeLo = 1299479202U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context = "";
  c1_info[19].name = "xlabel";
  c1_info[19].dominantType = "char";
  c1_info[19].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/xlabel.m";
  c1_info[19].fileTimeLo = 1303582146U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context = "";
  c1_info[20].name = "ylabel";
  c1_info[20].dominantType = "char";
  c1_info[20].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/ylabel.m";
  c1_info[20].fileTimeLo = 1303582146U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context = "";
  c1_info[21].name = "zlabel";
  c1_info[21].dominantType = "char";
  c1_info[21].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/zlabel.m";
  c1_info[21].fileTimeLo = 1303582144U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
}

static void c1_eml_scalar_eg(SFc1_Lab4InstanceStruct *chartInstance)
{
}

static void c1_b_eml_scalar_eg(SFc1_Lab4InstanceStruct *chartInstance)
{
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Lab4InstanceStruct *chartInstance;
  chartInstance = (SFc1_Lab4InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i91;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i91, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i91;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_Lab4InstanceStruct *chartInstance;
  chartInstance = (SFc1_Lab4InstanceStruct *)chartInstanceVoid;
  c1_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance,
  const mxArray *c1_is_active_c1_Lab4, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_is_active_c1_Lab4),
    &c1_thisId);
  sf_mex_destroy(&c1_is_active_c1_Lab4);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_Lab4InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_Lab4InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c1_Lab4_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1519446044U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2440241493U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2975819565U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(118810732U);
}

mxArray *sf_c1_Lab4_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("3ouIbKtTRy0rM7UkjO3RsC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c1_Lab4(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c1_Lab4\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Lab4_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Lab4InstanceStruct *chartInstance;
    chartInstance = (SFc1_Lab4InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_Lab4MachineNumber_,
          1,
          1,
          1,
          1,
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
          init_script_number_translation(_Lab4MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_Lab4MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Lab4MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"X");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,801);
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
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c1_X)[4];
          c1_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_X);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_Lab4MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "Mj9pT3l9l8kLLG0UqXOGGE";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Lab4_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 1, "dworkChecksum");
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

static void sf_opaque_initialize_c1_Lab4(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_Lab4InstanceStruct*) chartInstanceVar)->S);
  chart_debug_initialization(((SFc1_Lab4InstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c1_Lab4((SFc1_Lab4InstanceStruct*) chartInstanceVar);
  initialize_c1_Lab4((SFc1_Lab4InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_Lab4(void *chartInstanceVar)
{
  enable_c1_Lab4((SFc1_Lab4InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Lab4(void *chartInstanceVar)
{
  disable_c1_Lab4((SFc1_Lab4InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_Lab4(void *chartInstanceVar)
{
  sf_c1_Lab4((SFc1_Lab4InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_Lab4(void *chartInstanceVar)
{
  ext_mode_exec_c1_Lab4((SFc1_Lab4InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_Lab4(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Lab4((SFc1_Lab4InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Lab4();/* state var info */
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

extern void sf_internal_set_sim_state_c1_Lab4(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Lab4();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Lab4((SFc1_Lab4InstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_Lab4(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_Lab4(S);
}

static void sf_opaque_set_sim_state_c1_Lab4(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_Lab4(S, st);
}

static void sf_opaque_terminate_c1_Lab4(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Lab4InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_Lab4((SFc1_Lab4InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Lab4_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Lab4((SFc1_Lab4InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Lab4(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Lab4((SFc1_Lab4InstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c1_Lab4_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c1_Lab4\",T\"is_active_c1_Lab4\"}}"
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

static void mdlSetWorkWidths_c1_Lab4(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Lab4_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1041575138U));
  ssSetChecksum1(S,(2377190966U));
  ssSetChecksum2(S,(3170362617U));
  ssSetChecksum3(S,(262525633U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_Lab4(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Lab4(SimStruct *S)
{
  SFc1_Lab4InstanceStruct *chartInstance;
  chartInstance = (SFc1_Lab4InstanceStruct *)malloc(sizeof
    (SFc1_Lab4InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_Lab4InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_Lab4;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_Lab4;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_Lab4;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Lab4;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Lab4;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_Lab4;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_Lab4;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_Lab4;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Lab4;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Lab4;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_Lab4;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c1_Lab4;
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

void c1_Lab4_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Lab4(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Lab4(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Lab4(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Lab4_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
