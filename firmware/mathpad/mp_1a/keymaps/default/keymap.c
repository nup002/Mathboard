/* Copyright 2025 Summacogni OU
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "globs.h"
#include "print.h"
#include "unicode_symbols.h"
#include "tapdance.h"
#include "microsoft_office.h"
#include "symbol_functions.h"

//#include "sendstring_norwegian.h"

// Define the 6 different symbol locations on the keycaps
#define _LEFT_TOP 0  
#define _LEFT_MID 1
#define _LEFT_FRONT 2
#define _RIGHT_TOP 3 
#define _RIGHT_MID 4
#define _RIGHT_FRONT 5

// Track modifier key states
static bool rightkey_pressed = false;
static bool midkey_pressed = false;
static bool frontkey_pressed = false;

// Sets the LED indicator to match the output mode
void update_led_to_match_mode(void) {
    switch (user_config.MODE) {
        case UC:
            rgblight_sethsv_at(HSV_CYAN, 0);
            break;
        case MOF:
            rgblight_sethsv_at(HSV_MAGENTA, 0);
            break;
        case LTX:
            rgblight_sethsv_at(HSV_YELLOW, 0);
            break;
    }
}

// Sets the mathpad output mode
void output_mode_set(uint8_t mode) { 
    user_config.MODE = mode; 
    eeconfig_update_user(user_config.raw);
    update_led_to_match_mode();
}

// Cycles between mathpad output modes when called. UC -> MOF -> LTX -> UC
void output_mode_update(void) {
    if (user_config.MODE == UC){output_mode_set(MOF);} 
    else if (user_config.MODE == MOF){output_mode_set(LTX);}
    else if (user_config.MODE == LTX){output_mode_set(UC);}
}

// Function to update active layer based on modifier states
void update_active_layer(void) {
    // Reset all layers first
    layer_clear();

    // Set the appropriate layer based on key combinations
    if (rightkey_pressed && frontkey_pressed && !midkey_pressed) {
        layer_on(_RIGHT_FRONT);
    } else if (rightkey_pressed && midkey_pressed && !frontkey_pressed) {
        layer_on(_RIGHT_MID);
    } else if (rightkey_pressed && !midkey_pressed && !frontkey_pressed) {
        layer_on(_RIGHT_TOP);
    } else if (!rightkey_pressed && midkey_pressed && !frontkey_pressed) {
        layer_on(_LEFT_MID);
    } else if (!rightkey_pressed && !midkey_pressed && frontkey_pressed) {
        layer_on(_LEFT_FRONT);
    } else {
        // Default or invalid combinations go to _LEFT_TOP
        layer_on(_LEFT_TOP);
    }
}

// The custom_keycodes define all the "normal", or non-tapdance, symbols of the mathpad. These are the symbols that 
// (on the Matboard) do not have a red dot next to them. Examples include the nearly equal sign, nabla, and arrows. 
// Tapdance symbols are those symbols which have different behaviour depending on how many times you tap them. They have
// red dots next to them on the Matboard. These symbols are defined in the file tapdance.h.
enum custom_keycodes {
    KC_SWITCH_MODE = SAFE_RANGE, // KC_SWITCH_MODE is a special button that cycles the mathpad MODE variable.
    KC_RIGHTKEY, // RIGHT keycap side modifier key
    KC_MIDKEY, // MID keycap row modifier key
    KC_FRONTKEY, // FRONT keycap row modifier key
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

// Each physical symbolkey on the mathpad is defined here. The upper rightmost key is 00. The bottommost key is 23:
// 00 01 02 03 <- Top row
// 10 11 12 13 <- Middle row
// 20 21 22 23 <- Bottom row
// The index of a symbol in key arrays defines its location on the physical key. It goes:
// [top left, mid left, bottom left, top right, mid right, bottom right] 
const int key00[6] = {KC_ALPHA, KC_NOTEQUAL, KC_ACCENT_CIRCUMFLEX, KC_BETA, KC_ALMOSTEQUAL, KC_ACCENT_CHECK};
const int key01[6] = {TD(GAMMA_TD), KC_PROPORTIONAL, KC_COMBININGTILDE, TD(DELTA_TD), KC_IDENTICALTO, KC_COMBININGBAR};
const int key02[6] = {KC_EPSILON, KC_LESSOREQUAL, KC_ACCENT_ARROW, KC_ZETA, KC_GREATEROREQUAL, TD(DOT_TD)};
const int key03[6] = {KC_ETA, TD(MLT_TD), TD(SUB_TD), TD(THETA_TD), TD(MGT_TD), TD(SUP_TD)};
const int key10[6] = {KC_IOTA, KC_SUM, KC_UNION, KC_KAPPA, KC_NARYPRODUCT, KC_INTERSECTION};
const int key11[6] = {TD(LAMBDA_TD), TD(INTEGRAL_TD), TD(ELEMENT_OF_TD), KC_MU, TD(LINE_INTEGRAL_TD), KC_EMPTYSET};
const int key12[6] = {KC_NU, TD(ROOT_TD), TD(SUBSET_OF_TD), TD(XI_TD), KC_ARROW, KC_SETDIFFERENCE};
const int key13[6] = {KC_OMICRON, KC_PARTIALDERIVATIVE, TD(SUBSET_OR_EQ_TD), TD(PI_TD), KC_NABLA, KC_DISJOINTUNION};
const int key20[6] = {KC_RHO, KC_ARROWIMPLIES, KC_DOTPRODUCT, TD(SIGMA_TD), KC_ARROWIFANDONLYIF, KC_CROSSPRODUCT};
const int key21[6] = {KC_TAU, TD(THERE_EXIST_TD), TD(PLUSMINUS_TD), KC_UPSILON, TD(AND_TD), KC_PARALLEL};
const int key22[6] = {TD(PHI_TD), KC_FORALL, KC_DEGREE, KC_CHI, TD(UNCONDITIONALLY_TRUE_TD), KC_INFINITY};
const int key23[6] = {TD(PSI_TD), KC_NOT, KC_MATRIX, TD(OMEGA_TD), TD(PROVES_TD), KC_FRACTION};


// process_record_user handles keyclicks on "normal" (non-tapdance) symbols. Each normal symbol has a function defined in 
// symbol_functions.h. For example, when the user clicks KC_NOTEQUAL, process_record_user() will call notequal_key(). 
// The symbol functions defined in symbol_functions.h decides which action to take depending on the mathpad MODE.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SWITCH_MODE:
            if (record->event.pressed) {
                output_mode_update();
            }
            break;
        case KC_RIGHTKEY:
            rightkey_pressed = record->event.pressed;
            update_active_layer();
            return false; // Don't continue processing this key
        case KC_MIDKEY:
            midkey_pressed = record->event.pressed;
            update_active_layer();
            return false; // Don't continue processing this key
        case KC_FRONTKEY:
            frontkey_pressed = record->event.pressed;
            update_active_layer();
            return false; // Don't continue processing this key
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
	[_LEFT_TOP] = LAYOUT_5x3_macropad(
        key00[_LEFT_TOP], key01[_LEFT_TOP],   key02[_LEFT_TOP],   key03[_LEFT_TOP],   KC_SWITCH_MODE,
                          key10[_LEFT_TOP],   key11[_LEFT_TOP],   key12[_LEFT_TOP],   key13[_LEFT_TOP],
        KC_RIGHTKEY,      key20[_LEFT_TOP],   key21[_LEFT_TOP],   key22[_LEFT_TOP],   key23[_LEFT_TOP],
                                              KC_FRONTKEY,                            KC_MIDKEY
    ),
	[_RIGHT_TOP] = LAYOUT_5x3_macropad(
        key00[_RIGHT_TOP], key01[_RIGHT_TOP],   key02[_RIGHT_TOP],   key03[_RIGHT_TOP],   KC_SWITCH_MODE,
                           key10[_RIGHT_TOP],   key11[_RIGHT_TOP],   key12[_RIGHT_TOP],   key13[_RIGHT_TOP],
        KC_RIGHTKEY,       key20[_RIGHT_TOP],   key21[_RIGHT_TOP],   key22[_RIGHT_TOP],   key23[_RIGHT_TOP],
                                                KC_FRONTKEY,                              KC_MIDKEY
    ),
    [_LEFT_MID] = LAYOUT_5x3_macropad(
        key00[_LEFT_MID], key01[_LEFT_MID],   key02[_LEFT_MID],   key03[_LEFT_MID],   KC_SWITCH_MODE,
                          key10[_LEFT_MID],   key11[_LEFT_MID],   key12[_LEFT_MID],   key13[_LEFT_MID],
        KC_RIGHTKEY,      key20[_LEFT_MID],   key21[_LEFT_MID],   key22[_LEFT_MID],   key23[_LEFT_MID],
                                              KC_FRONTKEY,                            KC_MIDKEY
    ),
	[_RIGHT_MID] = LAYOUT_5x3_macropad(
        key00[_RIGHT_MID], key01[_RIGHT_MID],   key02[_RIGHT_MID],   key03[_RIGHT_MID],   KC_SWITCH_MODE,
                           key10[_RIGHT_MID],   key11[_RIGHT_MID],   key12[_RIGHT_MID],   key13[_RIGHT_MID],
        KC_RIGHTKEY,       key20[_RIGHT_MID],   key21[_RIGHT_MID],   key22[_RIGHT_MID],   key23[_RIGHT_MID],
                                                KC_FRONTKEY,                              KC_MIDKEY
    ),
	[_LEFT_FRONT] = LAYOUT_5x3_macropad(
        key00[_LEFT_FRONT], key01[_LEFT_FRONT],   key02[_LEFT_FRONT],   key03[_LEFT_FRONT],   KC_SWITCH_MODE,
                            key10[_LEFT_FRONT],   key11[_LEFT_FRONT],   key12[_LEFT_FRONT],   key13[_LEFT_FRONT],
        KC_RIGHTKEY,        key20[_LEFT_FRONT],   key21[_LEFT_FRONT],   key22[_LEFT_FRONT],   key23[_LEFT_FRONT],
                                                  KC_FRONTKEY,                                KC_MIDKEY
    ),
	[_RIGHT_FRONT] = LAYOUT_5x3_macropad(
        key00[_RIGHT_FRONT], key01[_RIGHT_FRONT],   key02[_RIGHT_FRONT],   key03[_RIGHT_FRONT],   KC_SWITCH_MODE,
                             key10[_RIGHT_FRONT],   key11[_RIGHT_FRONT],   key12[_RIGHT_FRONT],   key13[_RIGHT_FRONT],
        KC_RIGHTKEY,         key20[_RIGHT_FRONT],   key21[_RIGHT_FRONT],   key22[_RIGHT_FRONT],   key23[_RIGHT_FRONT],
                                                    KC_FRONTKEY,                                  KC_MIDKEY
    )
};


bool dip_switch_update_user(uint8_t index, bool active) { 
    uint8_t current_unicode_mode = get_unicode_input_mode();
    switch (index) {
        case 0:
            if(active & (current_unicode_mode!=UNICODE_MODE_LINUX)) {
                set_unicode_input_mode(UNICODE_MODE_LINUX); 
                }
            break;
        case 1:
            if(active & (current_unicode_mode!=UNICODE_MODE_MACOS)) {
                set_unicode_input_mode(UNICODE_MODE_MACOS); 
                }
            break;
        case 2:
            if(active & (current_unicode_mode!=UNICODE_MODE_WINCOMPOSE)) {
                set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE); 
                }
            break;
    }
    return true;
};

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user(); // Read the user config from EEPROM
  update_led_to_match_mode();
}

// DEBUG THINGS

void unicode_input_mode_set_user(uint8_t input_mode) {
    return;  // Comment this return statement to print a message when the unicode mode changes
    send_string(" Switched to unicode mode : ");
    switch (input_mode) {
        case UNICODE_MODE_LINUX:
            send_string("UNICODE_MODE_LINUX");
            break;
        case UNICODE_MODE_MACOS:
            send_string("UNICODE_MODE_MACOS");
            break;
        case UNICODE_MODE_WINCOMPOSE:
            send_string("UNICODE_MODE_WINCOMPOSE");
            break;
    }
};