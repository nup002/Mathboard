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

#ifndef TAPDANCE_H
#define TAPDANCE_H

#include QMK_KEYBOARD_H
#include "symbols/symbols.h"

// Helper function to handle tap dance actions
void symbol_dance(tap_dance_state_t *s, void *d, const symbol_definition_t *first_symbol, const symbol_definition_t *second_symbol);

// Greek symbols
void gamma_dance(tap_dance_state_t *s, void *d);
void delta_dance(tap_dance_state_t *s, void *d);
void theta_dance(tap_dance_state_t *s, void *d);
void lambda_dance(tap_dance_state_t *s, void *d);
void xi_dance(tap_dance_state_t *s, void *d);
void pi_dance(tap_dance_state_t *s, void *d);
void sigma_dance(tap_dance_state_t *s, void *d);
void varphi_dance(tap_dance_state_t *s, void *d);
void psi_dance(tap_dance_state_t *s, void *d);
void omega_dance(tap_dance_state_t *s, void *d);

// Comparison symbols
void asymptotically_equal_dance(tap_dance_state_t *s, void *d);
void identically_equal_dance(tap_dance_state_t *s, void *d);
void equal_by_definition_dance(tap_dance_state_t *s, void *d);
void greater_or_equal_dance(tap_dance_state_t *s, void *d);
void much_greater_than_dance(tap_dance_state_t *s, void *d);

// Modifier symbols
void dot_dance(tap_dance_state_t *s, void *d);
void sub_dance(tap_dance_state_t *s, void *d);
void sup_dance(tap_dance_state_t *s, void *d);

// Calculus symbols
void integral_dance(tap_dance_state_t *s, void *d);
void line_integral_dance(tap_dance_state_t *s, void *d);

// Algebra symbols
void root_dance(tap_dance_state_t *s, void *d);

// Arrows
void arrow_dance(tap_dance_state_t *s, void *d);
void double_arrow_dance(tap_dance_state_t *s, void *d);


// Set theory symbols
void circled_plus_dance(tap_dance_state_t *s, void *d);
void union_dance(tap_dance_state_t *s, void *d);
void empty_set_dance(tap_dance_state_t *s, void *d);
void element_of_dance(tap_dance_state_t *s, void *d);
void proper_subset_dance(tap_dance_state_t *s, void *d);
void subset_dance(tap_dance_state_t *s, void *d);
void there_exists_dance(tap_dance_state_t *s, void *d);
void and_dance(tap_dance_state_t *s, void *d);
void down_tack_dance(tap_dance_state_t *s, void *d);

// Misc symbols
void times_dance(tap_dance_state_t *s, void *d);
void plusminus_dance(tap_dance_state_t *s, void *d);

#endif // TAPDANCE_H
