#include QMK_KEYBOARD_H
#include "unicode_symbols.h"
#include "tapdance.h"

#define _BASE 0
#define _BASE_SHIFT 1
#define _OPT 2
#define _OPT_SHIFT 3
#define _BASE_FRONT 4
#define _OPT_FRONT 5
#define _BASE_ML 6
#define _BASE_ML_SHIFT 7

enum custom_keycodes {
    SUM = SAFE_RANGE,
    PRODUCT
};

const int key00[6] = {UC(_alpha), UC(_notequal), UC(_beta), UC(_almostequal), UC(_circumflex), UC(_check)};
const int key00_ML[6] = {key00[0], key00[1], key00[2], key00[3], KC_NO, KC_NO};
const int key01[6] = {TD(GAMMA_TD_UC), UC(_proportional), TD(DELTA_TD_UC), UC(_identicalto), UC(_combining_tilde), UC(_combining_bar)};
const int key01_ML[6] = {key01[0], key01[1], key01[2], key01[3], KC_NO, KC_NO};
const int key02[6] = {UC(_epsilon), UC(_lessorequal), UC(_zeta), UC(_greaterorequal), UC(_combining_arrow), TD(DOT_UC)};
const int key02_ML[6] = {key02[0], key02[1], key02[2], key02[3], KC_NO, KC_NO};
const int key03[6] = {UC(_eta), TD(MLT_TD_UC), TD(THETA_TD_UC), TD(MGT_TD_UC), TD(SUB_UC), TD(SUP_UC)};
const int key03_ML[6] = {key03[0], key03[1], key03[2], key03[3], KC_NO, KC_NO};
const int key10[6] = {UC(_iota), UC(_sum), UC(_kappa), UC(_n_ary_product), UC(_union), UC(_intersection)};
const int key10_ML[6] = {key10[0], key10[1], key10[2], key10[3], KC_NO, KC_NO};
const int key11[6] = {TD(LAMBDA_TD_UC), TD(INTEGRAL_UC), UC(_mu), TD(LINE_INTEGRAL_UC), TD(ELEMENT_OF_UC), UC(_empty_set)};
const int key11_ML[6] = {key11[0], key11[1], key11[2], key11[3], KC_NO, KC_NO};
const int key12[6] = {UC(_nu), TD(ROOT_UC), TD(XI_TD_UC), UC(_arrow), TD(SUBSET_OF_UC), UC(_set_difference)};
const int key12_ML[6] = {key12[0], key12[1], key12[2], key12[3], key12[4], key12[5]};
const int key13[6] = {UC(_omicron), UC(_partial_derivative), TD(PI_TD_UC), UC(_nabla), TD(SUBSET_OR_EQ_UC), UC(_disjoint_union)};
const int key13_ML[6] = {key13[0], key13[1], key13[2], key13[3], KC_NO, KC_NO};
const int key20[6] = {UC(_rho), UC(_arrow_implies), TD(SIGMA_TD_UC), UC(_arrow_if_and_only_if), UC(_dotproduct), UC(_crossproduct)};
const int key20_ML[6] = {key20[0], key20[1], key20[2], key20[3], key20[4], key20[5]};
const int key21[6] = {UC(_tau), TD(THERE_EXIST_UC), UC(_upsilon), TD(AND_UC), TD(PLUSMINUS_UC), UC(_parallel)};
const int key21_ML[6] = {key21[0], key21[1], key21[2], key21[3], KC_NO, key21[5]};
const int key22[6] = {TD(PHI_TD_UC), UC(_for_all), UC(_chi), TD(UNCONDITIONALLY_TRUE_UC), UC(_degree), UC(_infinity)};
const int key22_ML[6] = {key22[0], key22[1], key22[2], key22[3], key22[4], key22[5]};
const int key23[6] = {TD(PSI_TD_UC), UC(_not), TD(OMEGA_TD_UC), TD(PROVES_UC), KC_NO, KC_NO};
const int key23_ML[6] = {key23[0], key23[1], key23[2], key23[3], KC_NO, KC_NO};


void send_string_on_press(keyrecord_t *record, const char *string) {
    if (record->event.pressed) {
        // when keycode sum is pressed
        SEND_STRING("Sum");
    } else {
        // when keycode is released
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SUM:
        send_string_on_press(record, "Sum");
    break;
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x4(
        key00[_BASE], key01[_BASE],   key02[_BASE],   key03[_BASE],
        key10[_BASE], key11[_BASE],   key12[_BASE],   key13[_BASE],
        key20[_BASE], key21[_BASE],   key22[_BASE],   key23[_BASE],
        KC_NO,        MO(_BASE_FRONT),MO(_BASE_SHIFT),MO(_OPT)
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
    [_BASE_ML] = LAYOUT_ortho_4x4(
        key00_ML[_BASE], key01_ML[_BASE],   key02_ML[_BASE],   key03_ML[_BASE],
        key10_ML[_BASE], key11_ML[_BASE],   key12_ML[_BASE],   key13_ML[_BASE],
        key20_ML[_BASE], key21_ML[_BASE],   key22_ML[_BASE],   key23_ML[_BASE],
        KC_NO,           TO(_BASE),      MO(_BASE_ML_SHIFT),   MO(_OPT)
    ),
    [_BASE_ML_SHIFT] = LAYOUT_ortho_4x4(
        key00_ML[_BASE_SHIFT], key01_ML[_BASE_SHIFT],   key02_ML[_BASE_SHIFT],   key03_ML[_BASE_SHIFT],
        key10_ML[_BASE_SHIFT], key11_ML[_BASE_SHIFT],   key12_ML[_BASE_SHIFT],   key13_ML[_BASE_SHIFT],
        key20_ML[_BASE_SHIFT], key21_ML[_BASE_SHIFT],   key22_ML[_BASE_SHIFT],   key23_ML[_BASE_SHIFT],
        KC_NO,           TO(_BASE),      MO(_BASE_ML_SHIFT),   MO(_OPT)
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


