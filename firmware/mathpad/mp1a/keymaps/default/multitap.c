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

// Every multitap symbol is defined in this file. It defines what should happen
// when the symbol is tapped, double-tapped, triple-tapped, etc. The action to 
// take typically depend on which mode is active.

#include "symbols/calculus_symbols.h"
#include QMK_KEYBOARD_H
#include "multitap.h"
#include "symbols/symbol_categories.h"

// Helper function to handle tap dance actions
void symbol_dance(tap_dance_state_t *s, void *d, const symbol_definition_t **symbols, uint8_t symbol_count) {
    if (s->count > 0 && s->count <= symbol_count) {
        // Send the symbol corresponding to the tap count (1-indexed)
        send_symbol(symbols[s->count - 1]);
    } else if (symbol_count > 0) {
        // If tap count exceeds available symbols, send the last symbol
        send_symbol(symbols[symbol_count - 1]);
    }
    reset_tap_dance(s);
}

// Greek symbols
void gamma_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_GAMMA, &SYMBOL_GAMMA_UPPERCASE};
    symbol_dance(s, d, symbols, 2);
}

void delta_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_DELTA, &SYMBOL_DELTA_UPPERCASE};
    symbol_dance(s, d, symbols, 2);
}

void theta_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_THETA, &SYMBOL_THETA_UPPERCASE};
    symbol_dance(s, d, symbols, 2);
}

void lambda_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_LAMBDA, &SYMBOL_LAMBDA_UPPERCASE};
    symbol_dance(s, d, symbols, 2);
}

void xi_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_XI, &SYMBOL_XI_UPPERCASE};
    symbol_dance(s, d, symbols, 2);
}

void pi_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_PI, &SYMBOL_PI_UPPERCASE};
    symbol_dance(s, d, symbols, 2);
}

void sigma_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_SIGMA, &SYMBOL_SIGMA_UPPERCASE};
    symbol_dance(s, d, symbols, 2);
}

void varphi_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_PHI, &SYMBOL_PHI_UPPERCASE};
    symbol_dance(s, d, symbols, 2);
}

void psi_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_PSI, &SYMBOL_PSI_UPPERCASE};
    symbol_dance(s, d, symbols, 2);
}

void omega_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_OMEGA, &SYMBOL_OMEGA_UPPERCASE};
    symbol_dance(s, d, symbols, 2);
}

// Comparison symbols
void asymptotically_equal_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_ASYMPTOTICALLY_EQUAL, &SYMBOL_CONGRUENT};
    symbol_dance(s, d, symbols, 2);
} //TODO: 

void identically_equal_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_IDENTICAL, &SYMBOL_NOT_IDENTICAL};
    symbol_dance(s, d, symbols, 2);
}

void equal_by_definition_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_COLON_EQUALS, &SYMBOL_EQUAL_BY_DEFINITION};
    symbol_dance(s, d, symbols, 2);
}

void greater_or_equal_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_GREATER_THAN_OR_EQUAL, &SYMBOL_LESS_THAN_OR_EQUAL};
    symbol_dance(s, d, symbols, 2);
}

void much_greater_than_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_MUCH_GREATER_THAN, &SYMBOL_MUCH_LESS_THAN};
    symbol_dance(s, d, symbols, 2);
}

// Accents and sub/sup symbols
void accent_dot_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_ACCENT_DOT, &SYMBOL_ACCENT_DOUBLE_DOT, &SYMBOL_ACCENT_TRIPLE_DOT};
    symbol_dance(s, d, symbols, 3);
}

void sub_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_SUB_0, &SYMBOL_SUB_1, &SYMBOL_SUB_2, &SYMBOL_SUB_I, &SYMBOL_SUB_J, &SYMBOL_SUB_N};
    symbol_dance(s, d, symbols, 6);
}

void sup_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_SUP_0, &SYMBOL_SUP_1, &SYMBOL_SUP_2, &SYMBOL_SUP_I, &SYMBOL_SUP_J, &SYMBOL_SUP_N};
    symbol_dance(s, d, symbols, 6);
}

// Calculus symbols
void integral_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_INTEGRAL, &SYMBOL_DOUBLE_INTEGRAL, &SYMBOL_TRIPLE_INTEGRAL};
    symbol_dance(s, d, symbols, 3);
}

void line_integral_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_LINE_INTEGRAL, &SYMBOL_SURFACE_INTEGRAL, &SYMBOL_VOLUME_INTEGRAL};
    symbol_dance(s, d, symbols, 3);
}

// Algebra symbols
void root_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_SQUARE_ROOT, &SYMBOL_CUBE_ROOT, &SYMBOL_FOURTH_ROOT};
    symbol_dance(s, d, symbols, 3);
}

// Arrows
void arrow_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_RIGHTARROW, &SYMBOL_LEFTARROW, &SYMBOL_LEFTRIGHTARROW};
    symbol_dance(s, d, symbols, 3);
}

void double_arrow_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_DOUBLERIGHTARROW, &SYMBOL_DOUBLELEFTARROW, &SYMBOL_DOUBLERIGHTLEFTARROW};
    symbol_dance(s, d, symbols, 3);
}

// Set theory symbols
void union_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_UNION, &SYMBOL_INTERSECTION};
    symbol_dance(s, d, symbols, 2);
}

void empty_set_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_EMPTY_SET, &SYMBOL_POWER_SET};
    symbol_dance(s, d, symbols, 2);
}

void element_of_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_ELEMENT_OF, &SYMBOL_CONTAINS_AS_MEMBER};
    symbol_dance(s, d, symbols, 2);
}

void proper_subset_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_PROPER_SUBSET, &SYMBOL_NOT_PROPER_SUBSET};
    symbol_dance(s, d, symbols, 2);
}

void subset_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_SUBSET, &SYMBOL_NOT_SUBSET};
    symbol_dance(s, d, symbols, 2);
}

//Logic symbols
void there_exists_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_THERE_EXISTS, &SYMBOL_THERE_DOES_NOT_EXIST};
    symbol_dance(s, d, symbols, 2);
}

void and_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_AND, &SYMBOL_OR, &SYMBOL_XOR};
    symbol_dance(s, d, symbols, 3);
}

void down_tack_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_DOWN_TACK, &SYMBOL_UP_TACK};
    symbol_dance(s, d, symbols, 2);
}

// Misc symbols

void circled_plus_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_DIRECT_SUM, &SYMBOL_CIRCLED_TIMES};
    symbol_dance(s, d, symbols, 2);
}

void times_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_TIMES, &SYMBOL_DIVISION};
    symbol_dance(s, d, symbols, 2);
}

void plusminus_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_PLUSMINUS, &SYMBOL_MINUSPLUS};
    symbol_dance(s, d, symbols, 2);
}
