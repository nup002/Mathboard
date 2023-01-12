#ifndef TAPDANCE_H
#define TAPDANCE_H

#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)
#include "globs.h"
#include "unicode_symbols.h"
#include "microsoft_office.h"
#include "latex.h"

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

void latex_dance(const char *symbols[], int nelements, qk_tap_dance_state_t *state, void *user_data) {
    int index = state->count - 1;
    if (index >= nelements) {
        index = 0;
    }
    send_latex(symbols[index]);
}

void mof_dance(mofDefinition mof_defs[], int nelements, qk_tap_dance_state_t *state, void *user_data) {
    int index = state->count - 1;
    if (index >= nelements) {
        index = 0;
    }
    send_mof(mof_defs[index]);
}

void unicode_dance(int symbols[], int nelements, qk_tap_dance_state_t *state, void *user_data) {
    int index = state->count - 1;
    if (index >= nelements) {
        index = 0;
    }
    int symbol = symbols[index];
    send_hex(symbol);
    reset_tap_dance(state);
}

void gamma_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_gamma, _Gamma};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {gamma_LTX, Gamma_LTX};
        latex_dance(symbols, 2, s, d);}
}

void delta_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_delta, _Delta};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {delta_LTX, Delta_LTX};
        latex_dance(symbols, 2, s, d);}
}

void theta_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_theta, _Theta};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {theta_LTX, Theta_LTX};
        latex_dance(symbols, 2, s, d);}
}

void lambda_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_lambda, _Lambda};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {lambda_LTX, Lambda_LTX};
        latex_dance(symbols, 2, s, d);}
}

void xi_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_xi, _Xi};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {xi_LTX, Xi_LTX};
        latex_dance(symbols, 2, s, d);}
}

void pi_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_pi, _Pi};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {pi_LTX, Pi_LTX};
        latex_dance(symbols, 2, s, d);}
}

void sigma_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_sigma, _Sigma};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {sigma_LTX, Sigma_LTX};
        latex_dance(symbols, 2, s, d);}
}

void phi_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_phi, _Phi};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {phi_LTX, Phi_LTX};
        latex_dance(symbols, 2, s, d);}
}

void psi_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_psi, _Psi};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {psi_LTX, Psi_LTX};
        latex_dance(symbols, 2, s, d);}
}

void omega_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_omega, _Omega};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {omega_LTX, Omega_LTX};
        latex_dance(symbols, 2, s, d);}
}

void much_greater_than_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_much_greater_than, _much_much_greater_than};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {much_greater_than_LTX, much_much_greater_than_LTX};
        latex_dance(symbols, 2, s, d);}
}

void much_less_than_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_much_less_than, _much_much_less_than};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {much_less_than_LTX, much_much_less_than_LTX};
        latex_dance(symbols, 2, s, d);}
}

void dot_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC){   
        int symbols[] = {_combining_dot, _combining_2dot};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == MOF){
        mofDefinition mof_defs[] = {ACCENT_DOT_MOF, ACCENT_2DOT_MOF};
        mof_dance(mof_defs, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {combining_dot_LTX, combining_2dot_LTX};
        latex_dance(symbols, 2, s, d);}
}

void sub_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC){
        int symbols[] = {_sub_0, _sub_1, _sub_2, _sub_i, _sub_j, _sub_n};
        unicode_dance(symbols, 6, s, d);}
    else if (MODE == MOF){
        mofDefinition mof_defs[] = {SUB_0_MOF, SUB_1_MOF, SUB_2_MOF, SUB_i_MOF, SUB_j_MOF, SUB_n_MOF};
        mof_dance(mof_defs, 6, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {sub_0_LTX, sub_1_LTX, sub_2_LTX, sub_i_LTX, sub_j_LTX, sub_n_LTX};
        latex_dance(symbols, 6, s, d);}
}

void sup_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC){
        int symbols[] = {_sup_0, _sup_1, _sup_2, _sup_i, _sup_j, _sup_n};
        unicode_dance(symbols, 6, s, d);}
    else if (MODE == MOF){
        mofDefinition mof_defs[] = {SUP_0_MOF, SUP_1_MOF, SUP_2_MOF, SUP_i_MOF, SUP_j_MOF, SUP_n_MOF};
        mof_dance(mof_defs, 6, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {sup_0_LTX, sup_1_LTX, sup_2_LTX, sup_i_LTX, sup_j_LTX, sup_n_LTX};
        latex_dance(symbols, 6, s, d);}
}

void integral_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC){
        int symbols[] = {_integral, _double_integral, _triple_integral};
        unicode_dance(symbols, 3, s, d);}
    else if (MODE == MOF){
        mofDefinition mof_defs[] = {INTEGRAL_MOF, DOUBLE_INTEGRAL_MOF, TRIPLE_INTEGRAL_MOF};
        mof_dance(mof_defs, 3, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {integral_LTX, double_integral_LTX, triple_integral_LTX};
        latex_dance(symbols, 3, s, d);}
}

void line_integral_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC){
        int symbols[] = {_line_integral, _surface_integral, _volume_integral};
        unicode_dance(symbols, 3, s, d);}
    else if (MODE == MOF){
        mofDefinition mof_defs[] = {LINE_INTEGRAL_MOF, SURFACE_INTEGRAL_MOF, VOLUME_INTEGRAL_MOF};
        mof_dance(mof_defs, 3, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {line_integral_LTX, surface_integral_LTX, volume_integral_LTX};
        latex_dance(symbols, 3, s, d);}
}

void root_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC){
        int symbols[] = {_square_root, _cube_root, _fourth_root};
        unicode_dance(symbols, 3, s, d);}
    else if (MODE == MOF){
        mofDefinition mof_defs[] = {ROOT_MOF, CUBE_ROOT_MOF, FOURTH_ROOT_MOF};
        mof_dance(mof_defs, 3, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {square_root_LTX, cube_root_LTX, fourth_root_LTX};
        latex_dance(symbols, 3, s, d);}
}

void element_of_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_element_of, _not_element_of};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {element_of_LTX, not_element_of_LTX};
        latex_dance(symbols, 2, s, d);}
}

void subset_of_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_subset_of, _not_subset_of};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {subset_of_LTX, not_subset_of_LTX};
        latex_dance(symbols, 2, s, d);}
}

void subset_or_equal_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_subset_or_equal, _not_subset_or_equal};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {subset_or_equal_LTX, not_subset_or_equal_LTX};
        latex_dance(symbols, 2, s, d);}
}

void there_exists_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_there_exists, _there_does_not_exists};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {there_exists_LTX, there_does_not_exist_LTX};
        latex_dance(symbols, 2, s, d);}
}

void and_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_and, _or, _xor};
        unicode_dance(symbols, 3, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {and_LTX, or_LTX, xor_LTX};
        latex_dance(symbols, 3, s, d);}
}

void unconditionally_true_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_uncoditionally_true, _uncoditionally_false};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {unconditionally_true_LTX, unconditionally_false_LTX};
        latex_dance(symbols, 2, s, d);}
}

void proves_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_proves, _models};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {proves_LTX, models_LTX};
        latex_dance(symbols, 2, s, d);}
}

void plusminus_dance (qk_tap_dance_state_t *s, void *d){
    if (MODE == UC || MODE == MOF){
        int symbols[] = {_plusminus, _minusplus};
        unicode_dance(symbols, 2, s, d);}
    else if (MODE == LTX){
        const char *symbols[] = {plusminus_LTX, minusplus_LTX};
        latex_dance(symbols, 2, s, d);}
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [GAMMA_TD] = ACTION_TAP_DANCE_FN (gamma_dance),
  [DELTA_TD] = ACTION_TAP_DANCE_FN (delta_dance),
  [THETA_TD] = ACTION_TAP_DANCE_FN (theta_dance),
  [LAMBDA_TD] = ACTION_TAP_DANCE_FN (lambda_dance),
  [XI_TD] = ACTION_TAP_DANCE_FN (xi_dance),
  [PI_TD] = ACTION_TAP_DANCE_FN (pi_dance),
  [SIGMA_TD] = ACTION_TAP_DANCE_FN (sigma_dance),
  [PHI_TD] = ACTION_TAP_DANCE_FN (phi_dance),
  [PSI_TD] = ACTION_TAP_DANCE_FN (psi_dance),
  [OMEGA_TD] = ACTION_TAP_DANCE_FN (omega_dance),
  [MGT_TD] = ACTION_TAP_DANCE_FN (much_greater_than_dance),
  [MLT_TD] = ACTION_TAP_DANCE_FN (much_less_than_dance),
  [DOT_TD] = ACTION_TAP_DANCE_FN (dot_dance),
  [SUB_TD] = ACTION_TAP_DANCE_FN (sub_dance),
  [SUP_TD] = ACTION_TAP_DANCE_FN (sup_dance),
  [INTEGRAL_TD] = ACTION_TAP_DANCE_FN (integral_dance),
  [LINE_INTEGRAL_TD] = ACTION_TAP_DANCE_FN (line_integral_dance),
  [ROOT_TD] = ACTION_TAP_DANCE_FN (root_dance),
  [ELEMENT_OF_TD] = ACTION_TAP_DANCE_FN (element_of_dance),
  [SUBSET_OF_TD] = ACTION_TAP_DANCE_FN (subset_of_dance),
  [SUBSET_OR_EQ_TD] = ACTION_TAP_DANCE_FN (subset_or_equal_dance),
  [THERE_EXIST_TD] = ACTION_TAP_DANCE_FN (there_exists_dance),
  [AND_TD] = ACTION_TAP_DANCE_FN (and_dance),
  [UNCONDITIONALLY_TRUE_TD] = ACTION_TAP_DANCE_FN (unconditionally_true_dance),
  [PROVES_TD] = ACTION_TAP_DANCE_FN (proves_dance),
  [PLUSMINUS_TD] = ACTION_TAP_DANCE_FN (plusminus_dance)
};


#endif