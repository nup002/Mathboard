#include QMK_KEYBOARD_H
#include "globs.h"
#include "unicode_symbols.h"
#include "tapdance.h"
#include "microsoft_office.h"
#include "key_definitions.h"

#define _BASE 0
#define _BASE_SHIFT 1
#define _OPT 2
#define _OPT_SHIFT 3
#define _BASE_FRONT 4
#define _OPT_FRONT 5

// The custom_keycodes define all the "normal", or non-tapdance, symbols of the Mathboard. These are the symbols that 
// (on the Matboard) do not have a red dot next to them. Examples include the nearly equal sign, nabla, and arrows. 
// Tapdance symbols are those symbols which have different behaviour depending on how many times you tap them. They have
// red dots next to them on the Matboard. These symbols are defined in the file tapdance.h.
enum custom_keycodes {
    KC_SWITCH_MODE = SAFE_RANGE, // KC_SWITCH_MODE is a special button that cycles the Mathboard MODE variable.
    KC_ALPHA,
    KC_NOTEQUAL,
    KC_BETA,
    KC_ALMOSTEQUAL,
    KC_ACCENT_CIRCUMFLEX,
    KC_ACCENT_CHECK,
    KC_PROPORTIONAL,
    KC_IDENTICALTO,
    KC_COMBININGTILDE,
    KC_COMBININGBAR,
    KC_EPSILON,
    KC_LESSOREQUAL,
    KC_ZETA,
    KC_GREATEROREQUAL,
    KC_ACCENT_ARROW,
    KC_ETA,
    KC_IOTA,
    KC_SUM,
    KC_KAPPA,
    KC_NARYPRODUCT,
    KC_UNION,
    KC_INTERSECTION,
    KC_MU,
    KC_EMPTYSET,
    KC_NU,
    KC_ARROW,
    KC_SETDIFFERENCE,
    KC_OMICRON,
    KC_PARTIALDERIVATIVE,
    KC_NABLA,
    KC_DISJOINTUNION,
    KC_RHO,
    KC_ARROWIMPLIES,
    KC_ARROWIFANDONLYIF,
    KC_DOTPRODUCT,
    KC_CROSSPRODUCT,
    KC_TAU,
    KC_UPSILON,
    KC_PARALLEL,
    KC_FORALL,
    KC_CHI,
    KC_DEGREE,
    KC_INFINITY,
    KC_NOT,
    KC_MATRIX,
    KC_FRACTION
};

// Each physical symbolkey on the Mathboard is defined here. The upper rightmost key is 00. The bottommost key is 23:
// 00 01 02 03 <- Top row
// 10 11 12 13 <- Middle row
// 20 21 22 23 <- Bottom row
// The index of a symbol in key arrays defines its location on the physical key. It goes:
// [top face left, top face upper left, top face right, top face upper right, front left, front right] 
const int key00[6] = {KC_ALPHA, KC_NOTEQUAL, KC_BETA, KC_ALMOSTEQUAL, KC_ACCENT_CIRCUMFLEX, KC_ACCENT_CHECK};
const int key01[6] = {TD(GAMMA_TD), KC_PROPORTIONAL, TD(DELTA_TD), KC_IDENTICALTO, KC_COMBININGTILDE, KC_COMBININGBAR};
const int key02[6] = {KC_EPSILON, KC_LESSOREQUAL, KC_ZETA, KC_GREATEROREQUAL, KC_ACCENT_ARROW, TD(DOT_TD)};
const int key03[6] = {KC_ETA, TD(MLT_TD), TD(THETA_TD), TD(MGT_TD), TD(SUB_TD), TD(SUP_TD)};
const int key10[6] = {KC_IOTA, KC_SUM, KC_KAPPA, KC_NARYPRODUCT, KC_UNION, KC_INTERSECTION};
const int key11[6] = {TD(LAMBDA_TD), TD(INTEGRAL_TD), KC_MU, TD(LINE_INTEGRAL_TD), TD(ELEMENT_OF_TD), KC_EMPTYSET};
const int key12[6] = {KC_NU, TD(ROOT_TD), TD(XI_TD), KC_ARROW, TD(SUBSET_OF_TD), KC_SETDIFFERENCE};
const int key13[6] = {KC_OMICRON, KC_PARTIALDERIVATIVE, TD(PI_TD), KC_NABLA, TD(SUBSET_OR_EQ_TD), KC_DISJOINTUNION};
const int key20[6] = {KC_RHO, KC_ARROWIMPLIES, TD(SIGMA_TD), KC_ARROWIFANDONLYIF, KC_DOTPRODUCT, KC_CROSSPRODUCT};
const int key21[6] = {KC_TAU, TD(THERE_EXIST_TD), KC_UPSILON, TD(AND_TD), TD(PLUSMINUS_TD), KC_PARALLEL};
const int key22[6] = {TD(PHI_TD), KC_FORALL, KC_CHI, TD(UNCONDITIONALLY_TRUE_TD), KC_DEGREE, KC_INFINITY};
const int key23[6] = {TD(PSI_TD), KC_NOT, TD(OMEGA_TD), TD(PROVES_TD), KC_MATRIX, KC_FRACTION};


// process_record_user handles keyclicks on "normal" (non-tapdance) symbols. Each normal symbol has a function defined in 
// symbol_functions.h. For example, when the user clicks KC_NOTEQUAL, process_record_user() will call notequal_key(). 
// The symbol functions defined in symbol_functions.h decides which action to take depending on the Mathboard MODE.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SWITCH_MODE:
            if (record->event.pressed) {
                if (MODE == UC){MODE = MOF;} 
                else if (MODE == MOF){MODE = UC;}
            }
            break;
        case KC_ALPHA:
            alpha_key(record);
            break;
        case KC_NOTEQUAL:
            notequal_key(record);
            break;
        case KC_BETA:
            beta_key(record);
            break;
        case KC_ALMOSTEQUAL:
            almostequal_key(record);
            break;
        case KC_ACCENT_CIRCUMFLEX:
            circumflex_key(record);
            break;
        case KC_ACCENT_CHECK:
            check_key(record);
            break;
        case KC_PROPORTIONAL:
            proportional_key(record);
            break;
        case KC_IDENTICALTO:
            identicalto_key(record);
            break;
        case KC_COMBININGTILDE:
            combiningtilde_key(record);
            break;
        case KC_COMBININGBAR:
            combiningbar_key(record);
            break;
        case KC_EPSILON:
            epsilon_key(record);
            break;
        case KC_LESSOREQUAL:
            lessorequal_key(record);
            break;
        case KC_ZETA:
            zeta_key(record);
            break;
        case KC_GREATEROREQUAL:
            greaterorequal_key(record);
            break;
        case KC_ACCENT_ARROW:
            accent_arrow_key(record);
            break;
        case KC_ETA:
            eta_key(record);
            break;
        case KC_IOTA:
            iota_key(record);
            break;
        case KC_SUM:
            sum_key(record);
            break;
        case KC_KAPPA:
            kappa_key(record);
            break;
        case KC_NARYPRODUCT:
            naryproduct_key(record);
            break;
        case KC_UNION:
            union_key(record);
            break;
        case KC_INTERSECTION:
            intersection_key(record);
            break;
        case KC_MU:
            mu_key(record);
            break;
        case KC_EMPTYSET:
            emptyset_key(record);
            break;
        case KC_NU:
            nu_key(record);
            break;
        case KC_ARROW:
            arrow_key(record);
            break;
        case KC_SETDIFFERENCE:
            setdifference_key(record);
            break;
        case KC_OMICRON:
            omicron_key(record);
            break;
        case KC_PARTIALDERIVATIVE:
            partialderivative_key(record);
            break;
        case KC_NABLA:
            nabla_key(record);
            break;
        case KC_DISJOINTUNION:
            disjointunion_key(record);
            break;
        case KC_RHO:
            rho_key(record);
            break;
        case KC_ARROWIMPLIES:
            arrowimplies_key(record);
            break;
        case KC_ARROWIFANDONLYIF:
            arrowifandonlyif_key(record);
            break;
        case KC_DOTPRODUCT:
            dotproduct_key(record);
            break;
        case KC_CROSSPRODUCT:
            crossproduct_key(record);
            break;
        case KC_TAU:
            tau_key(record);
            break;
        case KC_UPSILON:
            upsilon_key(record);
            break;
        case KC_PARALLEL:
            parallel_key(record);
            break;
        case KC_FORALL:
            forall_key(record);
            break;
        case KC_CHI:
            chi_key(record);
            break;
        case KC_DEGREE:
            degree_key(record);
            break;
        case KC_INFINITY:
            infinity_key(record);
            break;
        case KC_NOT:
            not_key(record);
            break;
        case KC_FRACTION:
            fraction_key(record);
            break;
        case KC_MATRIX:
            matrix_key(record);
            break;
    }
    return true;
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x4(
        key00[_BASE], key01[_BASE],   key02[_BASE],   key03[_BASE],
        key10[_BASE], key11[_BASE],   key12[_BASE],   key13[_BASE],
        key20[_BASE], key21[_BASE],   key22[_BASE],   key23[_BASE],
        KC_SWITCH_MODE, MO(_BASE_FRONT),MO(_BASE_SHIFT),MO(_OPT)
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


