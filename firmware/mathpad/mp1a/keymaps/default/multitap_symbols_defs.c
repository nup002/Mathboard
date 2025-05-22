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

#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

#include "multitap_symbols_defs.h"
#include QMK_KEYBOARD_H
#include "globals.h"
#include "mode.h"
#include "unicode_symbols.h"
#include "microsoft_office.h"
#include "latex.h"




void latex_dance(const char *symbols[], int nelements, tap_dance_state_t *state, void *user_data) {
    // Track tapdance state and send the elements in 'symbols' as a LaTeX string.
    int index = state->count - 1;
    if (index >= nelements) {
        index = 0;
    }
    send_latex(symbols[index]);
}

void mof_dance(mofDefinition mof_defs[], int nelements, tap_dance_state_t *state, void *user_data) {
    // Track tapdance state and send the elements in 'symbols' as a Microsoft Office Equation Editor string.
    int index = state->count - 1;
    if (index >= nelements) {
        index = 0;
    }
    send_mof(mof_defs[index]);
}

void unicode_dance(int symbols[], int nelements, tap_dance_state_t *state, void *user_data) {
    // Track tapdance state and send the elements in 'symbols' as Unicode.
    int index = state->count - 1;
    if (index >= nelements) {
        index = 0;
    }
    int symbol = symbols[index];
    send_unicode_as_hex(symbol);
    reset_tap_dance(state);
}

// The logic of every tapdance symbol is defined beneath this line.
// To define a new multitap symbol, add a new function.


void gamma_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_gamma, _Gamma};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {gamma_LTX, Gamma_LTX};
        latex_dance(symbols, 2, s, d);}
}

void delta_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_delta, _Delta};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {delta_LTX, Delta_LTX};
        latex_dance(symbols, 2, s, d);}
}

void theta_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_theta, _Theta};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {theta_LTX, Theta_LTX};
        latex_dance(symbols, 2, s, d);}
}

void lambda_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_lambda, _Lambda};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {lambda_LTX, Lambda_LTX};
        latex_dance(symbols, 2, s, d);}
}

void xi_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_xi, _Xi};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {xi_LTX, Xi_LTX};
        latex_dance(symbols, 2, s, d);}
}

void pi_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_pi, _Pi};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {pi_LTX, Pi_LTX};
        latex_dance(symbols, 2, s, d);}
}

void sigma_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_sigma, _Sigma};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {sigma_LTX, Sigma_LTX};
        latex_dance(symbols, 2, s, d);}
}

void varphi_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_varphi, _Phi};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {varphi_LTX, Phi_LTX};
        latex_dance(symbols, 2, s, d);}
}

void psi_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_psi, _Psi};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {psi_LTX, Psi_LTX};
        latex_dance(symbols, 2, s, d);}
}

void omega_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_omega, _Omega};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {omega_LTX, Omega_LTX};
        latex_dance(symbols, 2, s, d);}
}


void asymptotically_equal_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_asymptotically_equal, _approximately_equal};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {asymptotically_equal_LTX, approximately_equal_LTX};
        latex_dance(symbols, 2, s, d);}
}

void identically_equal_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_identical_to, _not_identical_to};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {identical_to_LTX, not_identical_to_LTX};
        latex_dance(symbols, 2, s, d);}
}

void equal_by_definition_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_colon_equals, _equal_by_definition};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {colon_equals_LTX, equal_by_definition_LTX};
        latex_dance(symbols, 2, s, d);}
}

void greater_or_equal_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_greater_or_equal, _less_or_equal};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {greater_or_equal_LTX, less_or_equal_LTX};
        latex_dance(symbols, 2, s, d);}
}

void much_greater_than_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_much_greater_than, _much_less_than};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {much_greater_than_LTX, much_less_than_LTX};
        latex_dance(symbols, 2, s, d);}
}

void dot_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE){   
        int symbols[] = {_combining_dot, _combining_2dot};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == MOF_MODE){
        mofDefinition mof_defs[] = {ACCENT_DOT_MOF, ACCENT_2DOT_MOF};
        mof_dance(mof_defs, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {combining_dot_LTX, combining_2dot_LTX};
        latex_dance(symbols, 2, s, d);}
}

void sub_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE){
        int symbols[] = {_sub_0, _sub_1, _sub_2, _sub_i, _sub_j, _sub_n};
        unicode_dance(symbols, 6, s, d);}
    else if (user_config.MODE == MOF_MODE){
        mofDefinition mof_defs[] = {SUB_0_MOF, SUB_1_MOF, SUB_2_MOF, SUB_i_MOF, SUB_j_MOF, SUB_n_MOF};
        mof_dance(mof_defs, 6, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {sub_0_LTX, sub_1_LTX, sub_2_LTX, sub_i_LTX, sub_j_LTX, sub_n_LTX};
        latex_dance(symbols, 6, s, d);}
}

void sup_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE){
        int symbols[] = {_sup_0, _sup_1, _sup_2, _sup_i, _sup_j, _sup_n};
        unicode_dance(symbols, 6, s, d);}
    else if (user_config.MODE == MOF_MODE){
        mofDefinition mof_defs[] = {SUP_0_MOF, SUP_1_MOF, SUP_2_MOF, SUP_i_MOF, SUP_j_MOF, SUP_n_MOF};
        mof_dance(mof_defs, 6, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {sup_0_LTX, sup_1_LTX, sup_2_LTX, sup_i_LTX, sup_j_LTX, sup_n_LTX};
        latex_dance(symbols, 6, s, d);}
}

void integral_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE){
        int symbols[] = {_integral, _double_integral, _triple_integral};
        unicode_dance(symbols, 3, s, d);}
    else if (user_config.MODE == MOF_MODE){
        mofDefinition mof_defs[] = {INTEGRAL_MOF, DOUBLE_INTEGRAL_MOF, TRIPLE_INTEGRAL_MOF};
        mof_dance(mof_defs, 3, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {integral_LTX, double_integral_LTX, triple_integral_LTX};
        latex_dance(symbols, 3, s, d);}
}

void line_integral_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE){
        int symbols[] = {_line_integral, _surface_integral, _volume_integral};
        unicode_dance(symbols, 3, s, d);}
    else if (user_config.MODE == MOF_MODE){
        mofDefinition mof_defs[] = {LINE_INTEGRAL_MOF, SURFACE_INTEGRAL_MOF, VOLUME_INTEGRAL_MOF};
        mof_dance(mof_defs, 3, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {line_integral_LTX, surface_integral_LTX, volume_integral_LTX};
        latex_dance(symbols, 3, s, d);}
}

void root_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE){
        int symbols[] = {_square_root, _cube_root, _fourth_root};
        unicode_dance(symbols, 3, s, d);}
    else if (user_config.MODE == MOF_MODE){
        mofDefinition mof_defs[] = {ROOT_MOF, CUBE_ROOT_MOF, FOURTH_ROOT_MOF};
        mof_dance(mof_defs, 3, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {square_root_LTX, cube_root_LTX, fourth_root_LTX};
        latex_dance(symbols, 3, s, d);}
}

void element_of_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_element_of, _not_element_of};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {element_of_LTX, not_element_of_LTX};
        latex_dance(symbols, 2, s, d);}
}

void subset_of_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_subset_of, _not_subset_of};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {subset_of_LTX, not_subset_of_LTX};
        latex_dance(symbols, 2, s, d);}
}

void subset_or_equal_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_subset_or_equal, _not_subset_or_equal};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {subset_or_equal_LTX, not_subset_or_equal_LTX};
        latex_dance(symbols, 2, s, d);}
}

void there_exists_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_there_exists, _there_does_not_exists};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {there_exists_LTX, there_does_not_exist_LTX};
        latex_dance(symbols, 2, s, d);}
}

void and_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_and, _or, _xor};
        unicode_dance(symbols, 3, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {and_LTX, or_LTX, xor_LTX};
        latex_dance(symbols, 3, s, d);}
}

void unconditionally_true_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_uncoditionally_true, _uncoditionally_false};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {unconditionally_true_LTX, unconditionally_false_LTX};
        latex_dance(symbols, 2, s, d);}
}

void proves_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_proves, _models};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {proves_LTX, models_LTX};
        latex_dance(symbols, 2, s, d);}
}

void plusminus_dance (tap_dance_state_t *s, void *d){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){
        int symbols[] = {_plusminus, _minusplus};
        unicode_dance(symbols, 2, s, d);}
    else if (user_config.MODE == LTX_MODE){
        const char *symbols[] = {plusminus_LTX, minusplus_LTX};
        latex_dance(symbols, 2, s, d);}
}