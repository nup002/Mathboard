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
#include <stddef.h> // For NULL definition
#include "globals.h"
#include "modifiers.h"
#include "mode.h"

// Include other project headers after keycodes.h
#include "symbols/symbols.h"
#include "symbols/symbol_categories.h"
#include "tap_dance.h"

enum custom_keycodes {
    KC_SWITCH_MODE = SAFE_RANGE, // KC_SWITCH_MODE is a special button that cycles the mathpad MODE variable.
    KC_RIGHTKEY, // RIGHT keycap side modifier key
    KC_MIDKEY, // MID keycap row modifier key
    KC_FRONTKEY, // FRONT keycap row modifier key
    
    // Greek symbols
    KC_ALPHA,
    KC_BETA,
    KC_EPSILON,
    KC_ZETA,
    KC_ETA,
    KC_IOTA,
    KC_KAPPA,
    KC_MU,
    KC_NU,
    KC_OMICRON,
    KC_RHO,
    KC_TAU,
    KC_UPSILON,
    KC_CHI,

    // Comparison symbols
    KC_NOTEQUAL,
    KC_ALMOSTEQUAL,
    KC_PROPORTIONAL,
    KC_IDENTICALTO,
    KC_LESSOREQUAL,
    KC_GREATEROREQUAL,

    // Combining diacritics
    KC_COMBININGTILDE,
    KC_COMBININGBAR,
    KC_ACCENT_ARROW,
    KC_ACCENT_CIRCUMFLEX,
    KC_ACCENT_CHECK,

    // Algebra and Calculus symbols
    KC_SUM,
    KC_NARYPRODUCT,
    KC_PARTIALDERIVATIVE,
    KC_NABLA,

    // Set Theory symbols
    KC_NOT_ELEMENT_OF,
    KC_DISJOINTUNION,

    // Logic symbols
    KC_NOT,
    KC_FORALL,

    // Other symbols
    KC_DEGREE,
    KC_FRACTION,
    KC_DOTPRODUCT,
    KC_INFINITY,

    // Number system symbols
    KC_NATURALS,
    KC_INTEGERS,
    KC_RATIONALS,
    KC_REALS,
    KC_COMPLEXES
};

/**
 * Maps a custom keycode to its corresponding symbol definition
 * 
 * @param keycode The custom keycode to map
 * @return Pointer to the corresponding symbol definition, or NULL if not found
 */
 static const symbol_definition_t* get_symbol_for_keycode(uint16_t keycode) {
    switch (keycode) {
        // Greek symbols
        case KC_ALPHA:
            return &SYMBOL_ALPHA;
        case KC_BETA:
            return &SYMBOL_BETA;
        case KC_EPSILON:
            return &SYMBOL_EPSILON;
        case KC_ZETA:
            return &SYMBOL_ZETA;
        case KC_ETA:
            return &SYMBOL_ETA;
        case KC_IOTA:
            return &SYMBOL_IOTA;
        case KC_KAPPA:
            return &SYMBOL_KAPPA;
        case KC_MU:
            return &SYMBOL_MU;
        case KC_NU:
            return &SYMBOL_NU;
        case KC_OMICRON:
            return &SYMBOL_OMICRON;
        case KC_RHO:
            return &SYMBOL_RHO;
        case KC_TAU:
            return &SYMBOL_TAU;
        case KC_UPSILON:
            return &SYMBOL_UPSILON;
        case KC_CHI:
            return &SYMBOL_CHI;
            
        // Comparison symbols
        case KC_NOTEQUAL:
            return &SYMBOL_NOT_EQUAL;
        case KC_ALMOSTEQUAL:
            return &SYMBOL_APPROXIMATELY_EQUAL;
        case KC_PROPORTIONAL:
            return &SYMBOL_PROPORTIONAL_TO;
        case KC_IDENTICALTO:
            return &SYMBOL_IDENTICAL;
        case KC_LESSOREQUAL:
            return &SYMBOL_LESS_THAN_OR_EQUAL;
        case KC_GREATEROREQUAL:
            return &SYMBOL_GREATER_THAN_OR_EQUAL;
            
        // Combining diacritics
        case KC_COMBININGTILDE:
            return &SYMBOL_COMBINING_TILDE;
        case KC_COMBININGBAR:
            return &SYMBOL_BAR;
        case KC_ACCENT_ARROW:
            return &SYMBOL_ARROW;
        case KC_ACCENT_CIRCUMFLEX:
            return &SYMBOL_CIRCUMFLEX;
        case KC_ACCENT_CHECK:
            return &SYMBOL_CHECK;
            
        // Algebra and Calculus symbols
        case KC_SUM:
            return &SYMBOL_SUM;
        case KC_NARYPRODUCT:
            return &SYMBOL_N_ARY_PRODUCT;
        case KC_PARTIALDERIVATIVE:
            return &SYMBOL_PARTIAL_DIFFERENTIAL;
        case KC_NABLA:
            return &SYMBOL_NABLA;
            
        // Set Theory symbols
        case KC_NOT_ELEMENT_OF:
            return &SYMBOL_NOT_ELEMENT_OF;
        case KC_DISJOINTUNION:
            return &SYMBOL_DISJOINT_UNION;
            
        // Logic symbols
        case KC_NOT:
            return &SYMBOL_NOT;
        case KC_FORALL:
            return &SYMBOL_FOR_ALL;
            
        // Other symbols
        case KC_DEGREE:
            return &SYMBOL_DEGREE;
        case KC_FRACTION:
            return &SYMBOL_FRAC;
        case KC_DOTPRODUCT:
            return &SYMBOL_DOTPRODUCT;
        case KC_INFINITY:
            return &SYMBOL_INFINITY;
            
        // Number system symbols
        case KC_NATURALS:
            return &SYMBOL_NATURALS;
        case KC_INTEGERS:
            return &SYMBOL_INTEGERS;
        case KC_RATIONALS:
            return &SYMBOL_RATIONALS;
        case KC_REALS:
            return &SYMBOL_REALS;
        case KC_COMPLEXES:
            return &SYMBOL_COMPLEXES;
            
        default:
            return NULL;
    }
}

// Enum defining every tapdance symbol
enum tap_dance_keys {
    GAMMA_TD,                  // Gamma γ / Digamma ϝ
    DELTA_TD,                  // Delta δ / Capital delta Δ
    THETA_TD,                  // Theta θ / Capital theta Θ
    LAMBDA_TD,                 // Lambda λ / Capital lambda Λ
    XI_TD,                     // Xi ξ / Capital xi Ξ
    PI_TD,                     // Pi π / Capital pi Π
    SIGMA_TD,                  // Sigma σ / Capital sigma Σ
    PHI_TD,                    // Phi φ / Capital phi Φ
    PSI_TD,                    // Psi ψ / Capital psi Ψ
    OMEGA_TD,                  // Omega ω / Capital omega Ω
    ASYMPT_EQ_TD,              // Asymptotically equal to ≃ / Approximately equal to ≈
    IDENTICALLY_EQUAL_TD,      // Identical to ≡ / Not identical to ≢
    EQUAL_BY_DEF_TD,           // Equal by definition ≝ / Questioned equal to ≟
    MGT_TD,                    // Much greater than ≫ / Much less than ≪
    GTEQ_TD,                   // Greater or equal to ≥ / Less or equal to ≤
    DOT_TD,                    // Diacritic dot ȯ / Double diacritic dot ö  
    SUB_TD,                    // Subscripts
    SUP_TD,                    // Superscripts
    LINE_INTEGRAL_TD,
    ROOT_TD,
    ARROW_TD,
    UNION_TD,
    INTEGRAL_TD,
    CIRCLED_PLUS_TD,
    EMPTY_SET_TD,
    AND_TD,
    ELEMENT_OF_TD,
    PROPER_SUBSET_TD,
    SUBSET_TD,
    THERE_EXIST_TD,
    DOWN_TACK_TD,
    DOUBLE_ARROW_TD,
    TIMES_TD,
    PLUSMINUS_TD
};

/**
 * This array defines all the multitap symbols (known as 'tapdance' in QMK parlance).
 * See https://docs.qmk.fm/features/tap_dance
 */
 tap_dance_action_t tap_dance_actions[] = {
    [GAMMA_TD] = ACTION_TAP_DANCE_FN (gamma_dance),
    [DELTA_TD] = ACTION_TAP_DANCE_FN (delta_dance),
    [THETA_TD] = ACTION_TAP_DANCE_FN (theta_dance),
    [LAMBDA_TD] = ACTION_TAP_DANCE_FN (lambda_dance),
    [XI_TD] = ACTION_TAP_DANCE_FN (xi_dance),
    [PI_TD] = ACTION_TAP_DANCE_FN (pi_dance),
    [SIGMA_TD] = ACTION_TAP_DANCE_FN (sigma_dance),
    [PHI_TD] = ACTION_TAP_DANCE_FN (varphi_dance),
    [PSI_TD] = ACTION_TAP_DANCE_FN (psi_dance),
    [OMEGA_TD] = ACTION_TAP_DANCE_FN (omega_dance),
    [ASYMPT_EQ_TD] = ACTION_TAP_DANCE_FN (asymptotically_equal_dance),
    [IDENTICALLY_EQUAL_TD] = ACTION_TAP_DANCE_FN (identically_equal_dance),
    [EQUAL_BY_DEF_TD] = ACTION_TAP_DANCE_FN (equal_by_definition_dance),
    [GTEQ_TD] = ACTION_TAP_DANCE_FN (greater_or_equal_dance),
    [MGT_TD] = ACTION_TAP_DANCE_FN (much_greater_than_dance),
    [DOT_TD] = ACTION_TAP_DANCE_FN (dot_dance),
    [SUB_TD] = ACTION_TAP_DANCE_FN (sub_dance),
    [SUP_TD] = ACTION_TAP_DANCE_FN (sup_dance),
    [INTEGRAL_TD] = ACTION_TAP_DANCE_FN (integral_dance),
    [LINE_INTEGRAL_TD] = ACTION_TAP_DANCE_FN (line_integral_dance),
    [ROOT_TD] = ACTION_TAP_DANCE_FN (root_dance),
    [UNION_TD] = ACTION_TAP_DANCE_FN (union_dance),
    [ARROW_TD] = ACTION_TAP_DANCE_FN (arrow_dance),
    [DOUBLE_ARROW_TD] = ACTION_TAP_DANCE_FN (double_arrow_dance),
    [CIRCLED_PLUS_TD] = ACTION_TAP_DANCE_FN (circled_plus_dance),
    [EMPTY_SET_TD] = ACTION_TAP_DANCE_FN (empty_set_dance),
    [ELEMENT_OF_TD] = ACTION_TAP_DANCE_FN (element_of_dance),
    [PROPER_SUBSET_TD] = ACTION_TAP_DANCE_FN (proper_subset_dance),
    [SUBSET_TD] = ACTION_TAP_DANCE_FN (subset_dance),
    [THERE_EXIST_TD] = ACTION_TAP_DANCE_FN (there_exists_dance),
    [AND_TD] = ACTION_TAP_DANCE_FN (and_dance),
    [DOWN_TACK_TD] = ACTION_TAP_DANCE_FN (down_tack_dance),
    [TIMES_TD] = ACTION_TAP_DANCE_FN (times_dance),
    [PLUSMINUS_TD] = ACTION_TAP_DANCE_FN (plusminus_dance)
};

#ifdef SENDSTRING_LAYOUT
  // This converts the layout name to a string
  #define STRINGIFY(x) #x
  #define TOSTRING(x) STRINGIFY(x)

  // This creates the actual include path string
  #define LAYOUTPATH(layout) "sendstring_" TOSTRING(layout) ".h"

  // Include the appropriate header
  #include LAYOUTPATH(SENDSTRING_LAYOUT)
#endif

/**
 * Each physical symbol key on the mathpad is defined here as an array. 
 * The upper rightmost key is 'key00'. The bottom leftmost key is 'key23':
 * 00 01 02 03 <- Top row
 * 10 11 12 13 <- Middle row
 * 20 21 22 23 <- Bottom row
 * The index of a symbol in the following key arrays defines its location on the physical key.
 * It goes: [top left, mid left, bottom left, top right, mid right, bottom right] 
 */

 // Top row
static const int key00[6] = {KC_ALPHA, KC_NOTEQUAL, KC_ACCENT_CIRCUMFLEX, KC_BETA, KC_ALMOSTEQUAL, KC_ACCENT_CHECK};
static const int key01[6] = {TD(GAMMA_TD), KC_PROPORTIONAL, KC_COMBININGTILDE, TD(DELTA_TD), TD(ASYMPT_EQ_TD), KC_COMBININGBAR};
static const int key02[6] = {KC_EPSILON, TD(IDENTICALLY_EQUAL_TD), KC_ACCENT_ARROW, KC_ZETA, TD(EQUAL_BY_DEF_TD), TD(DOT_TD)};
static const int key03[6] = {KC_ETA, TD(GTEQ_TD), TD(SUB_TD), TD(THETA_TD), TD(MGT_TD), TD(SUP_TD)};

// Middle row
static const int key10[6] = {KC_IOTA, KC_SUM, TD(ELEMENT_OF_TD), KC_KAPPA, KC_NARYPRODUCT, KC_NOT_ELEMENT_OF};
static const int key11[6] = {TD(LAMBDA_TD), TD(INTEGRAL_TD), TD(PROPER_SUBSET_TD), KC_MU, TD(LINE_INTEGRAL_TD), TD(SUBSET_TD)};
static const int key12[6] = {KC_NU, TD(ROOT_TD), TD(UNION_TD), TD(XI_TD), TD(ARROW_TD), TD(CIRCLED_PLUS_TD)};
static const int key13[6] = {TD(PI_TD), KC_PARTIALDERIVATIVE, KC_DISJOINTUNION, KC_RHO, KC_NABLA, TD(EMPTY_SET_TD)};

// Bottom row
static const int key20[6] = {TD(SIGMA_TD), TD(AND_TD), TD(TIMES_TD), KC_TAU, KC_NOT, KC_DOTPRODUCT};
static const int key21[6] = {KC_UPSILON, TD(THERE_EXIST_TD), TD(PLUSMINUS_TD), TD(PHI_TD), KC_FORALL, KC_DEGREE};
static const int key22[6] = {KC_CHI, TD(DOWN_TACK_TD), KC_INFINITY, TD(PSI_TD), TD(DOUBLE_ARROW_TD), KC_FRACTION};
static const int key23[6] = {TD(OMEGA_TD), KC_INTEGERS, KC_REALS, KC_NATURALS, KC_RATIONALS, KC_COMPLEXES};


/**
 * 'process_record_user' handles keyclicks on symbols using the unified symbol definition structure.
 * For normal (non-multitap) symbols, it uses the get_symbol_for_keycode function to map the keycode
 * to its corresponding symbol definition, then processes it with handle_symbol_key.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t mode_key_timer;
    
    // Handle special modifier keys first
    switch (keycode) {
        case KC_SWITCH_MODE:
            // Mode key clicked. Rotates from mode to mode.
            if (record->event.pressed) {
                mode_key_timer = timer_read();
            } else if (timer_elapsed(mode_key_timer) > 1000) {
                output_mode_set(UC_MODE); // Go to Unicode mode if MODE key is held for more than one second
            } else {
                output_mode_update(); // Cycle to next mode if the MODE key is released within one second
            }
            return false; // Don't continue processing this key
            
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
    }
    
    // Handle normal (non-multitap) symbols
    const symbol_definition_t *symbol = get_symbol_for_keycode(keycode);
    if (symbol != NULL) {
        send_symbol_on_keypress(symbol, record);
        return false;
    }
    
    // If we get here, it's not a symbol we know how to handle
    return true;
};


/**
 * Keymap definition: This section defines each of the six symbol layers available on the Mathpad.
 * The symbol layers can be accessed by combining specific modifier keys.
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_LEFT_TOP] = LAYOUT_5x3_macropad(
        key00[_LEFT_TOP], key01[_LEFT_TOP],   key02[_LEFT_TOP],   key03[_LEFT_TOP],   KC_SWITCH_MODE,
                          key10[_LEFT_TOP],   key11[_LEFT_TOP],   key12[_LEFT_TOP],   key13[_LEFT_TOP],
        KC_RIGHTKEY,      key20[_LEFT_TOP],   key21[_LEFT_TOP],   key22[_LEFT_TOP],   key23[_LEFT_TOP],
                                              KC_MIDKEY,                              KC_FRONTKEY
    ),
	[_RIGHT_TOP] = LAYOUT_5x3_macropad(
        key00[_RIGHT_TOP], key01[_RIGHT_TOP],   key02[_RIGHT_TOP],   key03[_RIGHT_TOP],   KC_SWITCH_MODE,
                           key10[_RIGHT_TOP],   key11[_RIGHT_TOP],   key12[_RIGHT_TOP],   key13[_RIGHT_TOP],
        KC_RIGHTKEY,       key20[_RIGHT_TOP],   key21[_RIGHT_TOP],   key22[_RIGHT_TOP],   key23[_RIGHT_TOP],
                                                KC_MIDKEY,                                KC_FRONTKEY
    ),
    [_LEFT_MID] = LAYOUT_5x3_macropad(
        key00[_LEFT_MID], key01[_LEFT_MID],   key02[_LEFT_MID],   key03[_LEFT_MID],   KC_SWITCH_MODE,
                          key10[_LEFT_MID],   key11[_LEFT_MID],   key12[_LEFT_MID],   key13[_LEFT_MID],
        KC_RIGHTKEY,      key20[_LEFT_MID],   key21[_LEFT_MID],   key22[_LEFT_MID],   key23[_LEFT_MID],
                                              KC_MIDKEY,                              KC_FRONTKEY
    ),
	[_RIGHT_MID] = LAYOUT_5x3_macropad(
        key00[_RIGHT_MID], key01[_RIGHT_MID],   key02[_RIGHT_MID],   key03[_RIGHT_MID],   KC_SWITCH_MODE,
                           key10[_RIGHT_MID],   key11[_RIGHT_MID],   key12[_RIGHT_MID],   key13[_RIGHT_MID],
        KC_RIGHTKEY,       key20[_RIGHT_MID],   key21[_RIGHT_MID],   key22[_RIGHT_MID],   key23[_RIGHT_MID],
                                                KC_MIDKEY,                                KC_FRONTKEY
    ),
	[_LEFT_FRONT] = LAYOUT_5x3_macropad(
        key00[_LEFT_FRONT], key01[_LEFT_FRONT],   key02[_LEFT_FRONT],   key03[_LEFT_FRONT],   KC_SWITCH_MODE,
                            key10[_LEFT_FRONT],   key11[_LEFT_FRONT],   key12[_LEFT_FRONT],   key13[_LEFT_FRONT],
        KC_RIGHTKEY,        key20[_LEFT_FRONT],   key21[_LEFT_FRONT],   key22[_LEFT_FRONT],   key23[_LEFT_FRONT],
                                                  KC_MIDKEY,                                  KC_FRONTKEY
    ),
	[_RIGHT_FRONT] = LAYOUT_5x3_macropad(
        key00[_RIGHT_FRONT], key01[_RIGHT_FRONT],   key02[_RIGHT_FRONT],   key03[_RIGHT_FRONT],   KC_SWITCH_MODE,
                             key10[_RIGHT_FRONT],   key11[_RIGHT_FRONT],   key12[_RIGHT_FRONT],   key13[_RIGHT_FRONT],
        KC_RIGHTKEY,         key20[_RIGHT_FRONT],   key21[_RIGHT_FRONT],   key22[_RIGHT_FRONT],   key23[_RIGHT_FRONT],
                                                    KC_MIDKEY,                                    KC_FRONTKEY
    )
};

/**
 * Performs post-initialization tasks for the keyboard.
 * 
 * This function reads the user configuration from EEPROM and updates the LED to match the current mode stored in the 
 * configuration. It is typically called after the keyboard hardware has been initialized.
 */
void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user(); // Read the user config from EEPROM
  update_led_to_match_mode();
}