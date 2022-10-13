#ifndef TAPDANCE_H
#define TAPDANCE_H

#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)
#include "globs.h"
#include "unicode_symbols.h"
#include "microsoft_office.h"

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
    int symbols[] = {_gamma, _Gamma};
    unicode_dance(symbols, 2, s, d);
}

void delta_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_delta, _Delta};
    unicode_dance(symbols, 2, s, d);
}

void theta_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_theta, _Theta};
    unicode_dance(symbols, 2, s, d);
}

void lambda_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_lambda, _Lambda};
    unicode_dance(symbols, 2, s, d);
}

void xi_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_xi, _Xi};
    unicode_dance(symbols, 2, s, d);
}

void pi_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_pi, _Pi};
    unicode_dance(symbols, 2, s, d);
}

void sigma_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_sigma, _Sigma};
    unicode_dance(symbols, 2, s, d);
}

void phi_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_phi, _Phi};
    unicode_dance(symbols, 2, s, d);
}

void psi_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_psi, _Psi};
    unicode_dance(symbols, 2, s, d);
}

void omega_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_omega, _Omega};
    unicode_dance(symbols, 2, s, d);
}

void much_greater_than_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_much_greater_than, _much_much_greater_than};
    unicode_dance(symbols, 2, s, d);
}

void much_less_than_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_much_less_than, _much_much_less_than};
    unicode_dance(symbols, 2, s, d);
}

void dot_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_combining_dot, _combining_2dot};
    mofDefinition mof_defs[] = {ACCENT_DOT_MOF, ACCENT_2DOT_MOF};
    if (MODE == UC){unicode_dance(symbols, 2, s, d);}
    else if (MODE == MOF){mof_dance(mof_defs, 2, s, d);}
}

void sub_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_sub_0, _sub_1, _sub_2, _sub_i, _sub_j, _sub_n};
    mofDefinition mof_defs[] = {SUB_0_MOF, SUB_1_MOF, SUB_2_MOF, SUB_i_MOF, SUB_j_MOF, SUB_n_MOF};
    if (MODE == UC){unicode_dance(symbols, 6, s, d);}
    else if (MODE == MOF){mof_dance(mof_defs, 6, s, d);}
}

void sup_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_sup_0, _sup_1, _sup_2, _sup_i, _sup_j, _sup_n};
    mofDefinition mof_defs[] = {SUP_0_MOF, SUP_1_MOF, SUP_2_MOF, SUP_i_MOF, SUP_j_MOF, SUP_n_MOF};
    if (MODE == UC){unicode_dance(symbols, 6, s, d);}
    else if (MODE == MOF){mof_dance(mof_defs, 6, s, d);}
}

void integral_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_integral, _double_integral, _triple_integral};
    mofDefinition mof_defs[] = {INTEGRAL_MOF, DOUBLE_INTEGRAL_MOF, TRIPLE_INTEGRAL_MOF};
    if (MODE == UC){unicode_dance(symbols, 3, s, d);}
    else if (MODE == MOF){mof_dance(mof_defs, 3, s, d);}
}

void line_integral_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_line_integral, _surface_integral, _volume_integral};
    mofDefinition mof_defs[] = {LINE_INTEGRAL_MOF, SURFACE_INTEGRAL_MOF, VOLUME_INTEGRAL_MOF};
    if (MODE == UC){unicode_dance(symbols, 3, s, d);}
    else if (MODE == MOF){mof_dance(mof_defs, 3, s, d);}
}

void root_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_square_root, _cube_root, _fourth_root};
    mofDefinition mof_defs[] = {ROOT_MOF, CUBE_ROOT_MOF, FOURTH_ROOT_MOF};
    if (MODE == UC){unicode_dance(symbols, 3, s, d);}
    else if (MODE == MOF){mof_dance(mof_defs, 3, s, d);}
}

void element_of_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_element_of, _not_element_of};
    unicode_dance(symbols, 2, s, d);
}

void subset_of_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_subset_of, _not_subset_of};
    unicode_dance(symbols, 2, s, d);
}

void subset_or_equal_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_subset_or_equal, _not_subset_or_equal};
    unicode_dance(symbols, 2, s, d);
}

void there_exists_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_there_exists, _there_does_not_exists};
    unicode_dance(symbols, 2, s, d);
}

void and_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_and, _or, _xor};
    unicode_dance(symbols, 3, s, d);
}

void unconditionally_true_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_uncoditionally_true, _uncoditionally_false};
    unicode_dance(symbols, 2, s, d);
}

void proves_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_proves, _models};
    unicode_dance(symbols, 2, s, d);
}

void plusminus_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_plusminus, _minusplus};
    unicode_dance(symbols, 2, s, d);
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