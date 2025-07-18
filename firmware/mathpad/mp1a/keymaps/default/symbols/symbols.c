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
#include "symbols.h"
#include "../globals.h"
#include "../mode.h"
#include "../keymap.c"  // Include keymap.c to get custom keycodes
#include "unicode/unicode_mode.h"
#include "latex/latex_mode.h"
#include "microsoft_office/microsoft_office_mode.h"

// Function to send a symbol if the key is pressed
void send_symbol_on_keypress(const symbol_definition_t* symbol, keyrecord_t* record) {
    if (!record->event.pressed) {
        return;  // Only process on key press, not release
    }
    send_symbol(symbol);
}

// Function to send a symbol based on the current mode
void send_symbol(const symbol_definition_t* symbol) {
    switch (user_config.MODE) {
        case UC_MODE:
            send_symbol_unicode(symbol);
            break;
        case LTX_MODE:
            send_symbol_latex(symbol);
            break;
        case MOF_MODE:
            send_symbol_mof(symbol);
            break;
    }
}

/**
 * Maps a custom keycode to its corresponding symbol definition
 * 
 * @param keycode The custom keycode to map
 * @return Pointer to the corresponding symbol definition, or NULL if not found
 */
const symbol_definition_t* get_symbol_for_keycode(uint16_t keycode) {
    // This function will be populated with a mapping from keycodes to symbol definitions
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
            return &SYMBOL_ALMOST_EQUAL;
        case KC_PROPORTIONAL:
            return &SYMBOL_PROPORTIONAL;
        case KC_IDENTICALTO:
            return &SYMBOL_IDENTICAL_TO;
        case KC_LESSOREQUAL:
            return &SYMBOL_LESS_THAN_OR_EQUAL;
        case KC_GREATEROREQUAL:
            return &SYMBOL_GREATER_THAN_OR_EQUAL;
            
        // Combining diacritics
        case KC_COMBININGTILDE:
            return &SYMBOL_COMBINING_TILDE;
        case KC_COMBININGBAR:
            return &SYMBOL_COMBINING_BAR;
        case KC_ACCENT_ARROW:
            return &SYMBOL_ACCENT_ARROW;
        case KC_ACCENT_CIRCUMFLEX:
            return &SYMBOL_CIRCUMFLEX;
        case KC_ACCENT_CHECK:
            return &SYMBOL_CHECK;
            
        // Algebra and Calculus symbols
        case KC_SUM:
            return &SYMBOL_SUM;
        case KC_NARYPRODUCT:
            return &SYMBOL_NARY_PRODUCT;
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
            return &SYMBOL_FRACTION;
        case KC_DOTPRODUCT:
            return &SYMBOL_DOT_PRODUCT;
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
