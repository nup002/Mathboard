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

// Every tapdance symbol is defined in this file. It defines what should happen
// when the symbol is tapped, double-tapped, triple-tapped, etc. The action to 
// take typically depend on which mode is active.
// The equivalent file for 'normal' (non-tapdance) symbols is 'normal_symbols_defs.h'

#ifndef TAPDANCE_H
#define TAPDANCE_H

#include "latex.h"
#include QMK_KEYBOARD_H
#include "microsoft_office.h"

// Enum defining every tapdance symbol
enum tap_dance_keys {
    GAMMA_TD = 0,
    DELTA_TD = 1,
    THETA_TD = 2,
    LAMBDA_TD = 3,
    XI_TD = 4,
    PI_TD = 5,
    SIGMA_TD = 6,
    PHI_TD = 7,
    PSI_TD = 8,
    OMEGA_TD = 9,
    ASYMPT_EQ_TD = 10,               // Asymptotically equal to ≃ / approximately equal to ≅
    IDENTICALLY_EQUAL_TD = 11,      // Identical to ≡ / not identical to ≢
    EQUAL_BY_DEF_TD = 12,           // Colon equals ≔ / Equal by definition ≝
    MGT_TD = 13,                    // Much greater than ≫ / Much less than ≪
    GTEQ_TD = 14,                   // Greater or equal to ≥ / Less or equal to ≤
    DOT_TD = 15,                    // Diacritic dot ȯ / Double diacritic dot ö  
    SUB_TD = 16,                    // Subscripts
    SUP_TD = 17,                    // Superscripts
    LINE_INTEGRAL_TD = 18,
    ROOT_TD = 19,
    ARROW_TD = 20,
    UNION_TD = 21,
    INTEGRAL_TD = 22,
    CIRCLED_PLUS_TD = 23,
    EMPTY_SET_TD = 24,
    AND_TD = 25,
    ELEMENT_OF_TD = 26,
    PROPER_SUBSET_TD = 27,
    SUBSET_TD = 28,
    THERE_EXIST_TD = 29,
    DOWN_TACK_TD = 30,
    DOUBLE_ARROW_TD = 31,
    CROSS_PRODUCT_TD = 32,
    PLUSMINUS_TD = 33
};

void latex_dance(const char *symbols[], int nelements, tap_dance_state_t *state, void *user_data);

void mof_dance(mofDefinition mof_defs[], int nelements, tap_dance_state_t *state, void *user_data);

void unicode_dance(int symbols[], int nelements, tap_dance_state_t *state, void *user_data);

void gamma_dance (tap_dance_state_t *s, void *d);

void delta_dance (tap_dance_state_t *s, void *d);

void theta_dance (tap_dance_state_t *s, void *d);

void lambda_dance (tap_dance_state_t *s, void *d);

void xi_dance (tap_dance_state_t *s, void *d);

void pi_dance (tap_dance_state_t *s, void *d);

void sigma_dance (tap_dance_state_t *s, void *d);

void varphi_dance (tap_dance_state_t *s, void *d);

void psi_dance (tap_dance_state_t *s, void *d);

void omega_dance (tap_dance_state_t *s, void *d);

void asymptotically_equal_dance (tap_dance_state_t *s, void *d);

void identically_equal_dance (tap_dance_state_t *s, void *d);

void equal_by_definition_dance (tap_dance_state_t *s, void *d);

void greater_or_equal_dance (tap_dance_state_t *s, void *d);

void much_greater_than_dance (tap_dance_state_t *s, void *d);

void dot_dance (tap_dance_state_t *s, void *d);

void sub_dance (tap_dance_state_t *s, void *d);

void sup_dance (tap_dance_state_t *s, void *d);

void integral_dance (tap_dance_state_t *s, void *d);

void line_integral_dance (tap_dance_state_t *s, void *d);

void root_dance (tap_dance_state_t *s, void *d);

void union_dance (tap_dance_state_t *s, void *d);

void arrow_dance (tap_dance_state_t *s, void *d);

void double_arrow_dance (tap_dance_state_t *s, void *d);

void circled_plus_dance (tap_dance_state_t *s, void *d);

void empty_set_dance (tap_dance_state_t *s, void *d);

void element_of_dance (tap_dance_state_t *s, void *d);

void proper_subset_dance (tap_dance_state_t *s, void *d);

void subset_dance (tap_dance_state_t *s, void *d);

void there_exists_dance (tap_dance_state_t *s, void *d);

void and_dance (tap_dance_state_t *s, void *d);

void down_tack_dance (tap_dance_state_t *s, void *d);

void plusminus_dance (tap_dance_state_t *s, void *d);


#endif