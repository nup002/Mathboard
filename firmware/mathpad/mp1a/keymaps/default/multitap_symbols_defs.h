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

#include QMK_KEYBOARD_H
#include "microsoft_office.h"

// Enum defining every tapdance symbol
enum tap_dance_keys {
    GAMMA_TD = 0,
    DELTA_TD = 1,
    THETA_TD = 2,
    XI_TD = 3,
    PI_TD = 4,
    SIGMA_TD = 5,
    PHI_TD = 6,
    PSI_TD = 7,
    OMEGA_TD = 8,
    MGT_TD = 9, // Much greater than / much much greater than
    MLT_TD = 10, // Much less than / much much less than
    DOT_TD = 11,
    SUB_TD = 12,
    SUP_TD = 13,
    INTEGRAL_TD = 14,
    LINE_INTEGRAL_TD = 15,
    ROOT_TD = 16,
    ELEMENT_OF_TD = 17,
    SUBSET_OF_TD = 18,
    SUBSET_OR_EQ_TD = 19,
    THERE_EXIST_TD = 20,
    AND_TD = 21,
    UNCONDITIONALLY_TRUE_TD = 22,
    PROVES_TD = 23,
    PLUSMINUS_TD = 24,
    LAMBDA_TD = 25,
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

void much_greater_than_dance (tap_dance_state_t *s, void *d);

void much_less_than_dance (tap_dance_state_t *s, void *d);

void dot_dance (tap_dance_state_t *s, void *d);

void sub_dance (tap_dance_state_t *s, void *d);

void sup_dance (tap_dance_state_t *s, void *d);

void integral_dance (tap_dance_state_t *s, void *d);

void line_integral_dance (tap_dance_state_t *s, void *d);

void root_dance (tap_dance_state_t *s, void *d);

void element_of_dance (tap_dance_state_t *s, void *d);

void subset_of_dance (tap_dance_state_t *s, void *d);

void subset_or_equal_dance (tap_dance_state_t *s, void *d);

void there_exists_dance (tap_dance_state_t *s, void *d);

void and_dance (tap_dance_state_t *s, void *d);

void unconditionally_true_dance (tap_dance_state_t *s, void *d);

void proves_dance (tap_dance_state_t *s, void *d);

void plusminus_dance (tap_dance_state_t *s, void *d);


#endif