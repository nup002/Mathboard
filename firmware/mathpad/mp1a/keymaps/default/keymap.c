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
#include "modes/mode.h"
#include "symbols/symbols.h"
#include "symbols/symbol_categories.h"
#include "multitap.h"

//--------------
// KEYCODES
//--------------
enum custom_keycodes {
    KC_SWITCH_MODE = SAFE_RANGE, // KC_SWITCH_MODE is a special button that cycles the mathpad MODE
    KC_RIGHTKEY,                 // RIGHT modifier key
    KC_CENTERKEY,                // CENTER modifier key
    KC_BOTTOMKEY,                // BOTTOM modifier key
    
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

    // Accents
    KC_ACCENT_TILDE,
    KC_ACCENT_BAR,
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
            
        // Accents
        case KC_ACCENT_TILDE:
            return &SYMBOL_ACCENT_TILDE;
        case KC_ACCENT_BAR:
            return &SYMBOL_ACCENT_BAR;
        case KC_ACCENT_ARROW:
            return &SYMBOL_ACCENT_ARROW;
        case KC_ACCENT_CIRCUMFLEX:
            return &SYMBOL_ACCENT_CIRCUMFLEX;
        case KC_ACCENT_CHECK:
            return &SYMBOL_ACCENT_CHECK;
            
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
            return &SYMBOL_ACCENT_DOTPRODUCT;
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

//--------------
// MULTITAP CODES
//--------------
enum tap_dance_keys {
    // Greek symbols
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

    // Comparison symbols
    ASYMPT_EQ_TD,              // Asymptotically equal to ≃ / Approximately equal to ≈
    IDENTICALLY_EQUAL_TD,      // Identical to ≡ / Not identical to ≢
    EQUAL_BY_DEF_TD,           // Colon equals ≔ / Equal by definition ≝ 
    GTEQ_TD,                   // Greater or equal to ≥ / Less or equal to ≤
    MGT_TD,                    // Much greater than ≫ / Much less than ≪

    // Accents and subscript/superscript symbols
    ACCENT_DOT_TD,             // Dot · / Double dot ¨ / Triple dot ⃛  
    SUB_TD,                    // Subscripts: ₀ / ₁ / ₂ / ᵢ / ⱼ / ₙ
    SUP_TD,                    // Superscripts: ⁰ / ¹ / ² / ⁱ / ʲ / ⁿ

    // Calculus symbols
    INTEGRAL_TD,               // Integral ∫ / Double integral ∬ / Triple integral ∭
    LINE_INTEGRAL_TD,          // Line integral ∮ / Surface integral ∯ / Volume integral ∰

    // Algebra symbols
    ROOT_TD,                   // Square root √ / Cube root ∛ / Fourth root ∜

    // Arrows
    ARROW_TD,                  // Right arrow → / Left arrow ← / Left-right arrow ↔
    DOUBLE_ARROW_TD,           // Double right arrow ⇒ / Double left arrow ⇐ / Double left-right arrow ⇔

    // Set theory symbols
    UNION_TD,                  // Union ∪ / Intersection ∩
    EMPTY_SET_TD,              // Empty set ∅ / Power set ℘
    ELEMENT_OF_TD,             // Element of ∈ / Contains as member ∋
    PROPER_SUBSET_TD,          // Proper subset ⊂ / Not proper subset ⊄
    SUBSET_TD,                 // Subset ⊆ / Not subset ⊈

    // Logic symbols
    THERE_EXIST_TD,            // There exists ∃ / There does not exist ∄
    AND_TD,                    // Logical and ∧ / Logical or ∨ / Logical xor ⊕
    DOWN_TACK_TD,              // Down tack ⊤ / Up tack ⊥

    // Misc symbols
    CIRCLED_PLUS_TD,           // Circled plus ⊕ / Circled times ⊗
    TIMES_TD,                  // Multiplication × / Division ÷
    PLUSMINUS_TD               // Plus-minus ± / Minus-plus ∓
};

/**
 * This array maps multitap symbols to their corresponding functions.
 * See https://docs.qmk.fm/features/tap_dance
 */
 tap_dance_action_t tap_dance_actions[] = {
    // Greek symbols
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

    // Comparison symbols
    [ASYMPT_EQ_TD] = ACTION_TAP_DANCE_FN (asymptotically_equal_dance),
    [IDENTICALLY_EQUAL_TD] = ACTION_TAP_DANCE_FN (identically_equal_dance),
    [EQUAL_BY_DEF_TD] = ACTION_TAP_DANCE_FN (equal_by_definition_dance),
    [GTEQ_TD] = ACTION_TAP_DANCE_FN (greater_or_equal_dance),
    [MGT_TD] = ACTION_TAP_DANCE_FN (much_greater_than_dance),

    // Accents and subscript/superscript symbols
    [ACCENT_DOT_TD] = ACTION_TAP_DANCE_FN (accent_dot_dance),
    [SUB_TD] = ACTION_TAP_DANCE_FN (sub_dance),
    [SUP_TD] = ACTION_TAP_DANCE_FN (sup_dance),

    // Calculus symbols
    [INTEGRAL_TD] = ACTION_TAP_DANCE_FN (integral_dance),
    [LINE_INTEGRAL_TD] = ACTION_TAP_DANCE_FN (line_integral_dance),

    // Algebra symbols
    [ROOT_TD] = ACTION_TAP_DANCE_FN (root_dance),

    // Arrows
    [ARROW_TD] = ACTION_TAP_DANCE_FN (arrow_dance),
    [DOUBLE_ARROW_TD] = ACTION_TAP_DANCE_FN (double_arrow_dance),

    // Set theory symbols
    [UNION_TD] = ACTION_TAP_DANCE_FN (union_dance),
    [EMPTY_SET_TD] = ACTION_TAP_DANCE_FN (empty_set_dance),
    [ELEMENT_OF_TD] = ACTION_TAP_DANCE_FN (element_of_dance),
    [PROPER_SUBSET_TD] = ACTION_TAP_DANCE_FN (proper_subset_dance),
    [SUBSET_TD] = ACTION_TAP_DANCE_FN (subset_dance),

    // Logic symbols
    [THERE_EXIST_TD] = ACTION_TAP_DANCE_FN (there_exists_dance),
    [AND_TD] = ACTION_TAP_DANCE_FN (and_dance),
    [DOWN_TACK_TD] = ACTION_TAP_DANCE_FN (down_tack_dance),

    // Misc symbols
    [CIRCLED_PLUS_TD] = ACTION_TAP_DANCE_FN (circled_plus_dance),
    [TIMES_TD] = ACTION_TAP_DANCE_FN (times_dance),
    [PLUSMINUS_TD] = ACTION_TAP_DANCE_FN (plusminus_dance)
};

/**
 * Key Layout Structure Definition
 * 
 * Here, symbols (both normal and multitap) are mapped to the physical keys.
 *
 *  Physical Layout (4x3 grid):
 *  ┌─────┬─────┬─────┬─────┐
 *  │key00│key01│key02│key03│
 *  ├─────┼─────┼─────┼─────┤
 *  │key10│key11│key12│key13│
 *  ├─────┼─────┼─────┼─────┤
 *  │key20│key21│key22│key23│
 *  └─────┴─────┴─────┴─────┘

 *  Each key has 6 positions:
 *  ┌─────────────┐─────────────┐
 *  │ top_left    │ top_right   │
 *  │             │             │
 *  │ center_left │ center_right│ 
 *  │             │             │
 *  │ bottom_left │ bottom_right│
 *  └─────────────┘─────────────┘
 *
 */

typedef struct {
    uint16_t top_left;      // _LEFT_TOP layer (0)
    uint16_t center_left;   // _LEFT_CENTER layer (1) 
    uint16_t bottom_left;   // _LEFT_BOTTOM layer (2)
    uint16_t top_right;     // _RIGHT_TOP layer (3)
    uint16_t center_right;  // _RIGHT_CENTER layer (4)
    uint16_t bottom_right;  // _RIGHT_BOTTOM layer (5)
} key_layout_t;


// Top row keys
static const key_layout_t key00 = {
    .top_left = KC_ALPHA,
    .center_left = KC_NOTEQUAL,
    .bottom_left = KC_ACCENT_CIRCUMFLEX,
    .top_right = KC_BETA,
    .center_right = KC_ALMOSTEQUAL,
    .bottom_right = KC_ACCENT_CHECK
};

static const key_layout_t key01 = {
    .top_left = TD(GAMMA_TD),
    .center_left = KC_PROPORTIONAL,
    .bottom_left = KC_ACCENT_TILDE,
    .top_right = TD(DELTA_TD),
    .center_right = TD(ASYMPT_EQ_TD),
    .bottom_right = KC_ACCENT_BAR
};

static const key_layout_t key02 = {
    .top_left = KC_EPSILON,
    .center_left = TD(IDENTICALLY_EQUAL_TD),
    .bottom_left = KC_ACCENT_ARROW,
    .top_right = KC_ZETA,
    .center_right = TD(EQUAL_BY_DEF_TD),
    .bottom_right = TD(ACCENT_DOT_TD)
};

static const key_layout_t key03 = {
    .top_left = KC_ETA,
    .center_left = TD(GTEQ_TD),
    .bottom_left = TD(SUB_TD),
    .top_right = TD(THETA_TD),
    .center_right = TD(MGT_TD),
    .bottom_right = TD(SUP_TD)
};

// Middle row keys
static const key_layout_t key10 = {
    .top_left = KC_IOTA,
    .center_left = KC_SUM,
    .bottom_left = TD(ELEMENT_OF_TD),
    .top_right = KC_KAPPA,
    .center_right = KC_NARYPRODUCT,
    .bottom_right = KC_NOT_ELEMENT_OF
};

static const key_layout_t key11 = {
    .top_left = TD(LAMBDA_TD),
    .center_left = TD(INTEGRAL_TD),
    .bottom_left = TD(PROPER_SUBSET_TD),
    .top_right = KC_MU,
    .center_right = TD(LINE_INTEGRAL_TD),
    .bottom_right = TD(SUBSET_TD)
};

static const key_layout_t key12 = {
    .top_left = KC_NU,
    .center_left = TD(ROOT_TD),
    .bottom_left = TD(UNION_TD),
    .top_right = TD(XI_TD),
    .center_right = TD(ARROW_TD),
    .bottom_right = TD(CIRCLED_PLUS_TD)
};

static const key_layout_t key13 = {
    .top_left = TD(PI_TD),
    .center_left = KC_PARTIALDERIVATIVE,
    .bottom_left = KC_DISJOINTUNION,
    .top_right = KC_RHO,
    .center_right = KC_NABLA,
    .bottom_right = TD(EMPTY_SET_TD)
};

// Bottom row keys
static const key_layout_t key20 = {
    .top_left = TD(SIGMA_TD),
    .center_left = TD(AND_TD),
    .bottom_left = TD(TIMES_TD),
    .top_right = KC_TAU,
    .center_right = KC_NOT,
    .bottom_right = KC_DOTPRODUCT
};

static const key_layout_t key21 = {
    .top_left = KC_UPSILON,
    .center_left = TD(THERE_EXIST_TD),
    .bottom_left = TD(PLUSMINUS_TD),
    .top_right = TD(PHI_TD),
    .center_right = KC_FORALL,
    .bottom_right = KC_DEGREE
};

static const key_layout_t key22 = {
    .top_left = KC_CHI,
    .center_left = TD(DOWN_TACK_TD),
    .bottom_left = KC_INFINITY,
    .top_right = TD(PSI_TD),
    .center_right = TD(DOUBLE_ARROW_TD),
    .bottom_right = KC_FRACTION
};

static const key_layout_t key23 = {
    .top_left = TD(OMEGA_TD),
    .center_left = KC_INTEGERS,
    .bottom_left = KC_REALS,
    .top_right = KC_NATURALS,
    .center_right = KC_RATIONALS,
    .bottom_right = KC_COMPLEXES
};

//--------
// No user-configurable code below this line
//--------

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
            
        case KC_CENTERKEY:
            midkey_pressed = record->event.pressed;
            update_active_layer();
            return false; // Don't continue processing this key
            
        case KC_BOTTOMKEY:
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
        key00.top_left, key01.top_left,   key02.top_left,   key03.top_left,   KC_SWITCH_MODE,
                        key10.top_left,   key11.top_left,   key12.top_left,   key13.top_left,
        KC_RIGHTKEY,    key20.top_left,   key21.top_left,   key22.top_left,   key23.top_left,
                                          KC_CENTERKEY,                          KC_BOTTOMKEY
    ),
	[_RIGHT_TOP] = LAYOUT_5x3_macropad(
        key00.top_right, key01.top_right,   key02.top_right,   key03.top_right,   QK_UNDERGLOW_TOGGLE,
                         key10.top_right,   key11.top_right,   key12.top_right,   key13.top_right,
        KC_RIGHTKEY,     key20.top_right,   key21.top_right,   key22.top_right,   key23.top_right,
                                            KC_CENTERKEY,                            KC_BOTTOMKEY
    ),
    [_LEFT_CENTER] = LAYOUT_5x3_macropad(
        key00.center_left, key01.center_left,   key02.center_left,   key03.center_left,   QK_UNDERGLOW_VALUE_DOWN,
                        key10.center_left,   key11.center_left,   key12.center_left,   key13.center_left,
        KC_RIGHTKEY,    key20.center_left,   key21.center_left,   key22.center_left,   key23.center_left,
                                          KC_CENTERKEY,                          KC_BOTTOMKEY
    ),
	[_RIGHT_CENTER] = LAYOUT_5x3_macropad(
        key00.center_right, key01.center_right,   key02.center_right,   key03.center_right,   KC_SWITCH_MODE,
                         key10.center_right,   key11.center_right,   key12.center_right,   key13.center_right,
        KC_RIGHTKEY,     key20.center_right,   key21.center_right,   key22.center_right,   key23.center_right,
                                            KC_CENTERKEY,                            KC_BOTTOMKEY
    ),
	[_LEFT_BOTTOM] = LAYOUT_5x3_macropad(
        key00.bottom_left, key01.bottom_left,   key02.bottom_left,   key03.bottom_left,   QK_UNDERGLOW_VALUE_UP,
                           key10.bottom_left,   key11.bottom_left,   key12.bottom_left,   key13.bottom_left,
        KC_RIGHTKEY,       key20.bottom_left,   key21.bottom_left,   key22.bottom_left,   key23.bottom_left,
                                                KC_CENTERKEY,                                KC_BOTTOMKEY
    ),
	[_RIGHT_BOTTOM] = LAYOUT_5x3_macropad(
        key00.bottom_right, key01.bottom_right,   key02.bottom_right,   key03.bottom_right,   KC_SWITCH_MODE,
                            key10.bottom_right,   key11.bottom_right,   key12.bottom_right,   key13.bottom_right,
        KC_RIGHTKEY,        key20.bottom_right,   key21.bottom_right,   key22.bottom_right,   key23.bottom_right,
                                                  KC_CENTERKEY,                                  KC_BOTTOMKEY
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