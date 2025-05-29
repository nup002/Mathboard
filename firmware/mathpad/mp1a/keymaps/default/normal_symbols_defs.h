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

// Every 'normal', i.e. non-multitap symbol is defined in this file. It defines what should happen
// when the symbol is clicked. The action to take typically depend on which mode is active.
// The equivalent file for multitap symbols is 'tapdance_symbols_defs.h'

#ifndef NORMAL_SYMBOLS_DEFINITIONS_H
#define NORMAL_SYMBOLS_DEFINITIONS_H

#include QMK_KEYBOARD_H

// Greek letters
void alpha_key(keyrecord_t *record);

void beta_key(keyrecord_t *record);

void epsilon_key(keyrecord_t *record);

void zeta_key(keyrecord_t *record);

void eta_key(keyrecord_t *record);

void iota_key(keyrecord_t *record);

void kappa_key(keyrecord_t *record);

void mu_key(keyrecord_t *record);

void nu_key(keyrecord_t *record);

void omicron_key(keyrecord_t *record);

void rho_key(keyrecord_t *record);

void tau_key(keyrecord_t *record);

void upsilon_key(keyrecord_t *record);

void chi_key(keyrecord_t *record);

void tau_key(keyrecord_t *record);

void upsilon_key(keyrecord_t *record);

void notequal_key(keyrecord_t *record);

void almostequal_key(keyrecord_t *record);

void circumflex_key(keyrecord_t *record);

void check_key(keyrecord_t *record);

void proportional_key(keyrecord_t *record);

void identicalto_key(keyrecord_t *record);

void combiningtilde_key(keyrecord_t *record);

void combiningbar_key(keyrecord_t *record);

void lessorequal_key(keyrecord_t *record);

void greaterorequal_key(keyrecord_t *record);

void accent_arrow_key(keyrecord_t *record);

void sum_key(keyrecord_t *record);

void naryproduct_key(keyrecord_t *record);

void union_key(keyrecord_t *record);

void intersection_key(keyrecord_t *record);

void emptyset_key(keyrecord_t *record);

void not_element_of_key(keyrecord_t *record);

void arrow_key(keyrecord_t *record);

void setdifference_key(keyrecord_t *record);

void partialderivative_key(keyrecord_t *record);

void nabla_key(keyrecord_t *record);

void disjointunion_key(keyrecord_t *record);

void arrowimplies_key(keyrecord_t *record);

void arrowifandonlyif_key(keyrecord_t *record);

void dotproduct_key(keyrecord_t *record);

void crossproduct_key(keyrecord_t *record);

void parallel_key(keyrecord_t *record);

void forall_key(keyrecord_t *record);

void infinity_key(keyrecord_t *record);

void not_key(keyrecord_t *record);

// Other symbols
void degree_key(keyrecord_t *record);

void fraction_key(keyrecord_t *record);

void matrix_key(keyrecord_t *record);

// Number systems
void naturals_key(keyrecord_t *record);

void integers_key(keyrecord_t *record);

void rationals_key(keyrecord_t *record);

void reals_key(keyrecord_t *record);

void complexes_key(keyrecord_t *record);

#endif