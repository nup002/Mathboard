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
// The equivalent file for 'normal' (non-multitap) symbols is 'normal_symbols_defs.h'

#include "modifiers.h"
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

#include "multitap_symbols_defs.h"
#include "quantum.h"
#include "globals.h"
#include "mode.h"
#include "unicode_symbols.h"
#include "microsoft_office.h"
#include "latex.h"
#include "symbol_definitions.h"
#include "symbols/greek_symbols.h"
#include "symbols/algebra_symbols.h"
#include "symbols/comparison_symbols.h"
#include "symbols/logic_symbols.h"
#include "symbols/misc_symbols.h"
#include "symbols/set_theory_symbols.h"
#include "qmk_firmware/quantum/process_keycode/process_tap_dance.h"
#include "process_tap_dance.h"
#include <stdlib.h>


/**
 * @brief Handles tap dance for symbols using the unified symbol_definition_t structure
 *
 * This function selects the appropriate symbol from the array based on the tap count
 * and sends it using the appropriate method for the current mode.
 *
 * @param symbols Array of symbol_definition_t pointers
 * @param nelements Number of elements in the array
 * @param state Tap dance state
 * @param user_data User data
 */
void symbol_dance(const symbol_definition_t *symbols[], int nelements, tap_dance_state_t *state, void *user_data) {
    int index = state->count - 1;
    if (index >= nelements) {
        index = 0;
    }
    
    const symbol_definition_t *symbol = symbols[index];
    send_symbol(symbol);
    reset_tap_dance(state);
}

// The logic of every tapdance symbol is defined beneath this line.
// To define a new multitap symbol, add a new function.


void gamma_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_GAMMA, &SYMBOL_GAMMA_UPPERCASE};
    symbol_dance(symbols, 2, s, d);
}

void delta_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_DELTA, &SYMBOL_DELTA_UPPERCASE};
    symbol_dance(symbols, 2, s, d);
}

void theta_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_THETA, &SYMBOL_THETA_UPPERCASE};
    symbol_dance(symbols, 2, s, d);
}

void lambda_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_LAMBDA, &SYMBOL_LAMBDA_UPPERCASE};
    symbol_dance(symbols, 2, s, d);
}

void xi_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_XI, &SYMBOL_XI_UPPERCASE};
    symbol_dance(symbols, 2, s, d);
}

void pi_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_PI, &SYMBOL_PI_UPPERCASE};
    symbol_dance(symbols, 2, s, d);
}

void sigma_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_SIGMA, &SYMBOL_SIGMA_UPPERCASE};
    symbol_dance(symbols, 2, s, d);
}

void varphi_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_PHI, &SYMBOL_PHI_UPPERCASE};
    symbol_dance(symbols, 2, s, d);
}

void psi_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_PSI, &SYMBOL_PSI_UPPERCASE};
    symbol_dance(symbols, 2, s, d);
}

void omega_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_OMEGA, &SYMBOL_OMEGA_UPPERCASE};
    symbol_dance(symbols, 2, s, d);
}


void asymptotically_equal_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_ASYMPTOTICALLY_EQUAL, &SYMBOL_APPROXIMATELY_EQUAL};
    symbol_dance(symbols, 2, s, d);
}

void identically_equal_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_IDENTICAL, &SYMBOL_NOT_IDENTICAL};
    symbol_dance(symbols, 2, s, d);
}

void equal_by_definition_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_COLON_EQUALS, &SYMBOL_EQUAL_BY_DEFINITION};
    symbol_dance(symbols, 2, s, d);
}

void greater_or_equal_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_GREATER_THAN_OR_EQUAL, &SYMBOL_LESS_THAN_OR_EQUAL};
    symbol_dance(symbols, 2, s, d);
}

void much_greater_less_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_MUCH_GREATER_THAN, &SYMBOL_MUCH_LESS_THAN};
    symbol_dance(symbols, 2, s, d);
}

void dot_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_DOT, &SYMBOL_COMBINING_DOUBLE_DOT, &SYMBOL_COMBINING_TRIPLE_DOT};
    symbol_dance(symbols, 3, s, d);
}

void sub_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_SUB_0, &SYMBOL_SUB_1, &SYMBOL_SUB_2, &SYMBOL_SUB_I, &SYMBOL_SUB_J, &SYMBOL_SUB_N};
    symbol_dance(symbols, 6, s, d);
}

void sup_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_SUP_0, &SYMBOL_SUP_1, &SYMBOL_SUP_2, &SYMBOL_SUP_I, &SYMBOL_SUP_J, &SYMBOL_SUP_N};
    symbol_dance(symbols, 6, s, d);
}

void integral_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_INTEGRAL, &SYMBOL_DOUBLE_INTEGRAL, &SYMBOL_TRIPLE_INTEGRAL};
    symbol_dance(symbols, 3, s, d);
}

void line_integral_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_LINE_INTEGRAL, &SYMBOL_SURFACE_INTEGRAL, &SYMBOL_VOLUME_INTEGRAL};
    symbol_dance(symbols, 3, s, d);
}

void root_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_SQUARE_ROOT, &SYMBOL_CUBE_ROOT, &SYMBOL_FOURTH_ROOT};
    symbol_dance(symbols, 3, s, d);
}

void union_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_UNION, &SYMBOL_INTERSECTION};
    symbol_dance(symbols, 2, s, d);
}

void arrow_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_RIGHTARROW, &SYMBOL_LEFTRIGHTARROW, &SYMBOL_LEFTARROW};
    symbol_dance(symbols, 3, s, d);
}

void double_arrow_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_LONGRIGHTARROW, &SYMBOL_LONGLEFTRIGHTARROW, &SYMBOL_LONGLEFTARROW};
    symbol_dance(symbols, 3, s, d);
}

void circled_plus_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_DIRECT_SUM, &SYMBOL_CIRCLED_TIMES};
    symbol_dance(symbols, 2, s, d);
}

void empty_set_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_EMPTY_SET, &SYMBOL_POWER_SET};
    symbol_dance(symbols, 2, s, d);
}

void element_of_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_ELEMENT_OF, &SYMBOL_CONTAINS_AS_MEMBER};
    symbol_dance(symbols, 2, s, d);
}

void proper_subset_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_PROPER_SUBSET, &SYMBOL_NOT_PROPER_SUBSET};
    symbol_dance(symbols, 2, s, d);
}

void subset_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_SUBSET, &SYMBOL_NOT_SUBSET};
    symbol_dance(symbols, 2, s, d);
}

void there_exists_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_THERE_EXISTS, &SYMBOL_THERE_DOES_NOT_EXIST};
    symbol_dance(symbols, 2, s, d);
}

void and_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_AND, &SYMBOL_OR, &SYMBOL_XOR};
    symbol_dance(symbols, 3, s, d);
}

void times_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_TIMES, &SYMBOL_DIVISION};
    symbol_dance(symbols, 2, s, d);
}

void plusminus_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_PLUSMINUS, &SYMBOL_MINUSPLUS};
    symbol_dance(symbols, 2, s, d);
}

void down_tack_dance (tap_dance_state_t *s, void *d){
    static const symbol_definition_t *symbols[] = {&SYMBOL_DOWN_TACK, &SYMBOL_UP_TACK};
    symbol_dance(symbols, 2, s, d);
}