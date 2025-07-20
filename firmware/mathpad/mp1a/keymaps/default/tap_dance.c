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

#include "symbols/algebra_symbols.h"
#include QMK_KEYBOARD_H
#include "tap_dance.h"
#include "symbols/symbol_categories.h"

// Helper function to handle tap dance actions
void symbol_dance(tap_dance_state_t *s, void *d, const symbol_definition_t *first_symbol, const symbol_definition_t *second_symbol) {
    if (s->count == 1) {
        // Single tap - send the first symbol
        send_symbol(first_symbol);
    } else if (s->count == 2) {
        // Double tap - send the second symbol
        send_symbol(second_symbol);
    }
    reset_tap_dance(s);
}

// Greek symbols
void gamma_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_GAMMA, &SYMBOL_GAMMA_UPPERCASE);
}

void delta_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_DELTA, &SYMBOL_DELTA_UPPERCASE);
}

void theta_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_THETA, &SYMBOL_THETA_UPPERCASE);
}

void lambda_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_LAMBDA, &SYMBOL_LAMBDA_UPPERCASE);
}

void xi_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_XI, &SYMBOL_XI_UPPERCASE);
}

void pi_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_PI, &SYMBOL_PI_UPPERCASE);
}

void sigma_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_SIGMA, &SYMBOL_SIGMA_UPPERCASE);
}

void varphi_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_PHI, &SYMBOL_PHI_UPPERCASE);
}

void psi_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_PSI, &SYMBOL_PSI_UPPERCASE);
}

void omega_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_OMEGA, &SYMBOL_OMEGA_UPPERCASE);
}

// Comparison symbols
void asymptotically_equal_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_ASYMPTOTICALLY_EQUAL, &SYMBOL_APPROXIMATELY_EQUAL);
}

void identically_equal_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_IDENTICAL, &SYMBOL_NOT_IDENTICAL);
}

void equal_by_definition_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_COLON_EQUALS,&SYMBOL_EQUAL_BY_DEFINITION);
}

void greater_or_equal_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_GREATER_THAN_OR_EQUAL, &SYMBOL_LESS_THAN_OR_EQUAL);
}

void much_greater_than_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_MUCH_GREATER_THAN, &SYMBOL_MUCH_LESS_THAN);
}

// Modifier symbols
void dot_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_DOT, &SYMBOL_DOUBLE_DOT);
}

void sub_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_SUB_0, &SYMBOL_SUB_1);
}

void sup_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_SUP_0, &SYMBOL_SUP_1);
}

// Calculus symbols
void integral_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_INTEGRAL, &SYMBOL_DOUBLE_INTEGRAL);
}

void line_integral_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_LINE_INTEGRAL, &SYMBOL_SURFACE_INTEGRAL);
}

// Algebra symbols
void root_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_SQUARE_ROOT, &SYMBOL_CUBE_ROOT);
}

// Logic symbols
void arrow_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_RIGHTARROW, &SYMBOL_LEFTARROW);
}

void double_arrow_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_DOUBLERIGHTARROW, &SYMBOL_DOUBLELEFTARROW);
}

void circled_plus_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_DIRECT_SUM, &SYMBOL_CIRCLED_TIMES);
}

// Set theory symbols
void union_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_UNION, &SYMBOL_INTERSECTION);
}

void empty_set_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_EMPTY_SET, &SYMBOL_POWER_SET);
}

void element_of_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_ELEMENT_OF, &SYMBOL_CONTAINS_AS_MEMBER);
}

void proper_subset_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_PROPER_SUBSET, &SYMBOL_NOT_PROPER_SUBSET);
}

void subset_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_SUBSET, &SYMBOL_NOT_SUBSET);
}

void there_exists_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_THERE_EXISTS, &SYMBOL_THERE_DOES_NOT_EXIST);
}

void and_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_AND, &SYMBOL_OR);
}

void down_tack_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_DOWN_TACK, &SYMBOL_UP_TACK);
}

// Misc symbols
void times_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_TIMES, &SYMBOL_DIVISION);
}

void plusminus_dance(tap_dance_state_t *s, void *d) {
    symbol_dance(s, d, &SYMBOL_PLUSMINUS, &SYMBOL_MINUSPLUS);
}
