#include QMK_KEYBOARD_H
#include "unicode_symbols.h"
#include "tapdance.h"
#include "microsoft_office.h"

#define _BASE 0
#define _BASE_SHIFT 1
#define _OPT 2
#define _OPT_SHIFT 3
#define _BASE_FRONT 4
#define _OPT_FRONT 5
#define _BASE_MOF 6
#define _BASE_MOF_SHIFT 7
#define _OPT_MOF 8
#define _OPT_MOF_SHIFT 9
#define _BASE_MOF_FRONT 10
#define _OPT_MOF_FRONT 11

enum custom_keycodes {
    KC_ACCENT_CIRCUMFLEX_MOF = SAFE_RANGE,
    KC_ACCENT_CHECK_MOF,
    KC_ACCENT_TILDE_MOF,
    KC_ACCENT_BAR_MOF,
    KC_ACCENT_ARROW_MOF,
    KC_SUM_MOF,
    KC_N_ARY_PRODUCT_MOF,
    KC_UNION_MOF,
    KC_INTERSECTION_MOF,
    KC_MATRIX_MOF
};

const int key00[6] = {UC(_alpha), UC(_notequal), UC(_beta), UC(_almostequal), UC(_circumflex), UC(_check)};
const int key00_MOF[6] = {key00[0], key00[1], key00[2], key00[3], KC_ACCENT_CIRCUMFLEX_MOF, KC_ACCENT_CHECK_MOF};
const int key01[6] = {TD(GAMMA_TD_UC), UC(_proportional), TD(DELTA_TD_UC), UC(_identicalto), UC(_combining_tilde), UC(_combining_bar)};
const int key01_MOF[6] = {key01[0], key01[1], key01[2], key01[3], KC_ACCENT_TILDE_MOF, KC_ACCENT_BAR_MOF};
const int key02[6] = {UC(_epsilon), UC(_lessorequal), UC(_zeta), UC(_greaterorequal), UC(_combining_arrow), TD(DOT_UC)};
const int key02_MOF[6] = {key02[0], key02[1], key02[2], key02[3], KC_ACCENT_ARROW_MOF, TD(DOT_TD_MOF)};
const int key03[6] = {UC(_eta), TD(MLT_TD_UC), TD(THETA_TD_UC), TD(MGT_TD_UC), TD(SUB_UC), TD(SUP_UC)};
const int key03_MOF[6] = {key03[0], key03[1], key03[2], key03[3], TD(SUB_TD_MOF), TD(SUP_TD_MOF)};
const int key10[6] = {UC(_iota), UC(_sum), UC(_kappa), UC(_n_ary_product), UC(_union), UC(_intersection)};
const int key10_MOF[6] = {key10[0], KC_SUM_MOF, key10[2], KC_N_ARY_PRODUCT_MOF, KC_UNION_MOF, KC_INTERSECTION_MOF};
const int key11[6] = {TD(LAMBDA_TD_UC), TD(INTEGRAL_UC), UC(_mu), TD(LINE_INTEGRAL_UC), TD(ELEMENT_OF_UC), UC(_empty_set)};
const int key11_MOF[6] = {key11[0], TD(INTEGRAL_TD_MOF), key11[2], TD(LINE_INTEGRAL_TD_MOF), key11[4], key11[5]};
const int key12[6] = {UC(_nu), TD(ROOT_UC), TD(XI_TD_UC), UC(_arrow), TD(SUBSET_OF_UC), UC(_set_difference)};
const int key12_MOF[6] = {key12[0], TD(ROOT_TD_MOF), key12[2], key12[3], key12[4], key12[5]};
const int key13[6] = {UC(_omicron), UC(_partial_derivative), TD(PI_TD_UC), UC(_nabla), TD(SUBSET_OR_EQ_UC), UC(_disjoint_union)};
const int key13_MOF[6] = {key13[0], key13[1], key13[2], key13[3], key13[4], key13[5]};
const int key20[6] = {UC(_rho), UC(_arrow_implies), TD(SIGMA_TD_UC), UC(_arrow_if_and_only_if), UC(_dotproduct), UC(_crossproduct)};
const int key20_MOF[6] = {key20[0], key20[1], key20[2], key20[3], key20[4], key20[5]};
const int key21[6] = {UC(_tau), TD(THERE_EXIST_UC), UC(_upsilon), TD(AND_UC), TD(PLUSMINUS_UC), UC(_parallel)};
const int key21_MOF[6] = {key21[0], key21[1], key21[2], key21[3], key21[4], key21[5]};
const int key22[6] = {TD(PHI_TD_UC), UC(_for_all), UC(_chi), TD(UNCONDITIONALLY_TRUE_UC), UC(_degree), UC(_infinity)};
const int key22_MOF[6] = {key22[0], key22[1], key22[2], key22[3], key22[4], key22[5]};
const int key23[6] = {TD(PSI_TD_UC), UC(_not), TD(OMEGA_TD_UC), TD(PROVES_UC), KC_NO, KC_NO};
const int key23_MOF[6] = {key23[0], key23[1], key23[2], key23[3], KC_MATRIX_MOF, KC_NO};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ACCENT_CIRCUMFLEX_MOF:
            send_mof_on_keypress(ACCENT_HAT_MOF, record);
            break;
        case KC_ACCENT_CHECK_MOF:
            send_mof_on_keypress(ACCENT_CHECK_MOF, record);
            break;
        case KC_ACCENT_TILDE_MOF:
            send_mof_on_keypress(ACCENT_TILDE_MOF, record);
            break;
        case KC_ACCENT_BAR_MOF:
            send_mof_on_keypress(ACCENT_BAR_MOF, record);
            break;
        case KC_ACCENT_ARROW_MOF:
            send_mof_on_keypress(ACCENT_ARROW_MOF, record);
            break;
        case KC_SUM_MOF:
            send_mof_on_keypress(SUM_MOF, record);
            break;
        case KC_N_ARY_PRODUCT_MOF:
            send_mof_on_keypress(N_ARY_PRODUCT_MOF, record);
            break;
        case KC_INTERSECTION_MOF:
            send_mof_on_keypress(UNION_MOF, record);
            break;
        case KC_UNION_MOF:
            send_mof_on_keypress(INTERSECTION_MOF, record);
            break;
        case KC_MATRIX_MOF:
            send_mof_on_keypress(MATRIX_MOF, record);
            break;
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x4(
        key00[_BASE], key01[_BASE],   key02[_BASE],   key03[_BASE],
        key10[_BASE], key11[_BASE],   key12[_BASE],   key13[_BASE],
        key20[_BASE], key21[_BASE],   key22[_BASE],   key23[_BASE],
        DF(_BASE_MOF), MO(_BASE_FRONT),MO(_BASE_SHIFT),MO(_OPT)
    ),
	[_BASE_SHIFT] = LAYOUT_ortho_4x4(
        key00[_BASE_SHIFT], key01[_BASE_SHIFT],   key02[_BASE_SHIFT],   key03[_BASE_SHIFT],
        key10[_BASE_SHIFT], key11[_BASE_SHIFT],   key12[_BASE_SHIFT],   key13[_BASE_SHIFT],
        key20[_BASE_SHIFT], key21[_BASE_SHIFT],   key22[_BASE_SHIFT],   key23[_BASE_SHIFT],
        KC_NO,        KC_NO,          MO(_BASE_SHIFT),MO(_OPT_SHIFT)
    ),
	[_OPT] = LAYOUT_ortho_4x4(
        key00[_OPT], key01[_OPT],   key02[_OPT],   key03[_OPT],
        key10[_OPT], key11[_OPT],   key12[_OPT],   key13[_OPT],
        key20[_OPT], key21[_OPT],   key22[_OPT],   key23[_OPT],
        KC_NO,        MO(_OPT_FRONT), MO(_OPT_SHIFT), MO(_OPT)
    ),
	[_OPT_SHIFT] = LAYOUT_ortho_4x4(
        key00[_OPT_SHIFT], key01[_OPT_SHIFT],   key02[_OPT_SHIFT],   key03[_OPT_SHIFT],
        key10[_OPT_SHIFT], key11[_OPT_SHIFT],   key12[_OPT_SHIFT],   key13[_OPT_SHIFT],
        key20[_OPT_SHIFT], key21[_OPT_SHIFT],   key22[_OPT_SHIFT],   key23[_OPT_SHIFT],
        KC_NO,        KC_NO,          MO(_OPT_SHIFT), MO(_OPT_SHIFT)
    ),
	[_BASE_FRONT] = LAYOUT_ortho_4x4(
        key00[_BASE_FRONT], key01[_BASE_FRONT],   key02[_BASE_FRONT],   key03[_BASE_FRONT],
        key10[_BASE_FRONT], key11[_BASE_FRONT],   key12[_BASE_FRONT],   key13[_BASE_FRONT],
        key20[_BASE_FRONT], key21[_BASE_FRONT],   key22[_BASE_FRONT],   key23[_BASE_FRONT],
        KC_NO,        MO(_BASE_FRONT),          KC_NO, MO(_OPT_FRONT)
    ),
	[_OPT_FRONT] = LAYOUT_ortho_4x4(
        key00[_OPT_FRONT], key01[_OPT_FRONT],   key02[_OPT_FRONT],   key03[_OPT_FRONT],
        key10[_OPT_FRONT], key11[_OPT_FRONT],   key12[_OPT_FRONT],   key13[_OPT_FRONT],
        key20[_OPT_FRONT], key21[_OPT_FRONT],   key22[_OPT_FRONT],   key23[_OPT_FRONT],
        KC_NO,        MO(_OPT_FRONT),          KC_NO, MO(_OPT_FRONT)
    ),
    [_BASE_MOF] = LAYOUT_ortho_4x4(
        key00_MOF[_BASE], key01_MOF[_BASE],   key02_MOF[_BASE],   key03_MOF[_BASE],
        key10_MOF[_BASE], key11_MOF[_BASE],   key12_MOF[_BASE],   key13_MOF[_BASE],
        key20_MOF[_BASE], key21_MOF[_BASE],   key22_MOF[_BASE],   key23_MOF[_BASE],
        DF(_BASE),       MO(_BASE_MOF_FRONT),MO(_BASE_MOF_SHIFT),MO(_OPT_MOF)         
    ),
    [_BASE_MOF_SHIFT] = LAYOUT_ortho_4x4(
        key00_MOF[_BASE_SHIFT], key01_MOF[_BASE_SHIFT],   key02_MOF[_BASE_SHIFT],   key03_MOF[_BASE_SHIFT],
        key10_MOF[_BASE_SHIFT], key11_MOF[_BASE_SHIFT],   key12_MOF[_BASE_SHIFT],   key13_MOF[_BASE_SHIFT],
        key20_MOF[_BASE_SHIFT], key21_MOF[_BASE_SHIFT],   key22_MOF[_BASE_SHIFT],   key23_MOF[_BASE_SHIFT],
        KC_NO,        KC_NO,          MO(_BASE_MOF_SHIFT),MO(_OPT_MOF_SHIFT)          
    ),
    [_OPT_MOF] = LAYOUT_ortho_4x4(
        key00_MOF[_OPT], key01_MOF[_OPT],   key02_MOF[_OPT],   key03_MOF[_OPT],
        key10_MOF[_OPT], key11_MOF[_OPT],   key12_MOF[_OPT],   key13_MOF[_OPT],
        key20_MOF[_OPT], key21_MOF[_OPT],   key22_MOF[_OPT],   key23_MOF[_OPT],
        KC_NO,        MO(_OPT_MOF_FRONT), MO(_OPT_MOF_SHIFT), MO(_OPT_MOF)      
    ),
    [_OPT_MOF_SHIFT] = LAYOUT_ortho_4x4(
        key00_MOF[_OPT_SHIFT], key01_MOF[_OPT_SHIFT],   key02_MOF[_OPT_SHIFT],   key03_MOF[_OPT_SHIFT],
        key10_MOF[_OPT_SHIFT], key11_MOF[_OPT_SHIFT],   key12_MOF[_OPT_SHIFT],   key13_MOF[_OPT_SHIFT],
        key20_MOF[_OPT_SHIFT], key21_MOF[_OPT_SHIFT],   key22_MOF[_OPT_SHIFT],   key23_MOF[_OPT_SHIFT],
        KC_NO,        KC_NO,          MO(_OPT_MOF_SHIFT), MO(_OPT_MOF_SHIFT)         
    ),
    [_BASE_MOF_FRONT] = LAYOUT_ortho_4x4(
        key00_MOF[_BASE_FRONT], key01_MOF[_BASE_FRONT],   key02_MOF[_BASE_FRONT],   key03_MOF[_BASE_FRONT],
        key10_MOF[_BASE_FRONT], key11_MOF[_BASE_FRONT],   key12_MOF[_BASE_FRONT],   key13_MOF[_BASE_FRONT],
        key20_MOF[_BASE_FRONT], key21_MOF[_BASE_FRONT],   key22_MOF[_BASE_FRONT],   key23_MOF[_BASE_FRONT],
        KC_NO,        MO(_BASE_MOF_FRONT),          KC_NO, MO(_OPT_MOF_FRONT)         
    ),
    [_OPT_MOF_FRONT] = LAYOUT_ortho_4x4(
        key00_MOF[_OPT_FRONT], key01_MOF[_OPT_FRONT],   key02_MOF[_OPT_FRONT],   key03_MOF[_OPT_FRONT],
        key10_MOF[_OPT_FRONT], key11_MOF[_OPT_FRONT],   key12_MOF[_OPT_FRONT],   key13_MOF[_OPT_FRONT],
        key20_MOF[_OPT_FRONT], key21_MOF[_OPT_FRONT],   key22_MOF[_OPT_FRONT],   key23_MOF[_OPT_FRONT],
        KC_NO,        MO(_OPT_MOF_FRONT),          KC_NO, MO(_OPT_MOF_FRONT)         
    )
};

#ifdef ENCODER_ENABLE
#include "encoder.h"
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
  return true;
}
#endif


