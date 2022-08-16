#ifndef TAPDANCE_H
#define TAPDANCE_H

#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)
#include "unicode_symbols.h"

enum tap_dance_keys {
    GAMMA_TD_UC = 0,
    DELTA_TD_UC = 1,
    THETA_TD_UC = 2,
    XI_TD_UC = 3,
    PI_TD_UC = 4,
    SIGMA_TD_UC = 5,
    PHI_TD_UC = 6,
    PSI_TD_UC = 7,
    OMEGA_TD_UC = 8,
    MGT_TD_UC = 9, // Much greater / much much greater
    MLT_TD_UC = 10, // Much less / much much less
    DOT_UC = 11,
    SUB_UC = 12,
    SUP_UC = 13,
    INTEGRAL_UC = 14,
    LINE_INTEGRAL_UC = 15,
    ROOT_UC = 16,
    ELEMENT_OF_UC = 17,
    SUBSET_OF_UC = 18,
    SUBSET_OR_EQ_UC = 19,
    THERE_EXIST_UC = 20,
    AND_UC = 21,
    UNCONDITIONALLY_TRUE_UC = 22,
    PROVES_UC = 23,
    PLUSMINUS_UC = 24,
    LAMBDA_TD_UC = 25
};

void unicode_dance(int symbols[], int nelements, qk_tap_dance_state_t *state, void *user_data) {
    int index = state->count - 1;
    if (index >= nelements) {
        index = 0;
    }
    int symbol = symbols[index];
    unicode_input_start();
    register_hex(symbol);
    unicode_input_finish();
    reset_tap_dance(state);
}

void gamma_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_gamma, _Gamma};
    unicode_dance(symbols, 2, s, d);
}

void delta_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_delta, _Delta};
    unicode_dance(symbols, 2, s, d);
}

void theta_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_theta, _Theta};
    unicode_dance(symbols, 2, s, d);
}

void lambda_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_lambda, _Lambda};
    unicode_dance(symbols, 2, s, d);
}

void xi_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_xi, _Xi};
    unicode_dance(symbols, 2, s, d);
}

void pi_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_pi, _Pi};
    unicode_dance(symbols, 2, s, d);
}

void sigma_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_sigma, _Sigma};
    unicode_dance(symbols, 2, s, d);
}

void phi_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_phi, _Phi};
    unicode_dance(symbols, 2, s, d);
}

void psi_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_psi, _Psi};
    unicode_dance(symbols, 2, s, d);
}

void omega_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_omega, _Omega};
    unicode_dance(symbols, 2, s, d);
}

void much_greater_than_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_much_greater_than, _much_much_greater_than};
    unicode_dance(symbols, 2, s, d);
}

void much_less_than_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_much_less_than, _much_much_less_than};
    unicode_dance(symbols, 2, s, d);
}

void dot_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_combining_dot, _combining_2dot};
    unicode_dance(symbols, 2, s, d);
}

void sub_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_sub_0, _sub_1, _sub_2, _sub_i, _sub_j, _sub_n};
    unicode_dance(symbols, 6, s, d);
}

void sup_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_sup_0, _sup_1, _sup_2, _sup_i, _sup_j, _sup_n};
    unicode_dance(symbols, 6, s, d);
}

void integral_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_integral, _double_integral, _triple_integral};
    unicode_dance(symbols, 3, s, d);
}

void line_integral_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_line_integral, _surface_integral, _volume_integral};
    unicode_dance(symbols, 3, s, d);
}

void root_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_square_root, _cube_root, _fourth_root};
    unicode_dance(symbols, 3, s, d);
}

void element_of_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_element_of, _not_element_of};
    unicode_dance(symbols, 2, s, d);
}

void subset_of_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_subset_of, _not_subset_of};
    unicode_dance(symbols, 2, s, d);
}

void subset_or_equal_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_subset_or_equal, _not_subset_or_equal};
    unicode_dance(symbols, 2, s, d);
}

void there_exists_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_there_exists, _there_does_not_exists};
    unicode_dance(symbols, 2, s, d);
}

void and_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_and, _or, _xor};
    unicode_dance(symbols, 3, s, d);
}

void unconditionally_true_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_uncoditionally_true, _uncoditionally_false};
    unicode_dance(symbols, 2, s, d);
}

void proves_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_proves, _models};
    unicode_dance(symbols, 2, s, d);
}

void plusminus_unicode_dance (qk_tap_dance_state_t *s, void *d){
    int symbols[] = {_plusminus, _minusplus};
    unicode_dance(symbols, 2, s, d);
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [GAMMA_TD_UC] = ACTION_TAP_DANCE_FN (gamma_unicode_dance),
  [DELTA_TD_UC] = ACTION_TAP_DANCE_FN (delta_unicode_dance),
  [THETA_TD_UC] = ACTION_TAP_DANCE_FN (theta_unicode_dance),
  [LAMBDA_TD_UC] = ACTION_TAP_DANCE_FN (lambda_unicode_dance),
  [XI_TD_UC] = ACTION_TAP_DANCE_FN (xi_unicode_dance),
  [PI_TD_UC] = ACTION_TAP_DANCE_FN (pi_unicode_dance),
  [SIGMA_TD_UC] = ACTION_TAP_DANCE_FN (sigma_unicode_dance),
  [PHI_TD_UC] = ACTION_TAP_DANCE_FN (phi_unicode_dance),
  [PSI_TD_UC] = ACTION_TAP_DANCE_FN (psi_unicode_dance),
  [OMEGA_TD_UC] = ACTION_TAP_DANCE_FN (omega_unicode_dance),
  [MGT_TD_UC] = ACTION_TAP_DANCE_FN (much_greater_than_unicode_dance),
  [MLT_TD_UC] = ACTION_TAP_DANCE_FN (much_less_than_unicode_dance),
  [DOT_UC] = ACTION_TAP_DANCE_FN (dot_unicode_dance),
  [SUB_UC] = ACTION_TAP_DANCE_FN (sub_unicode_dance),
  [SUP_UC] = ACTION_TAP_DANCE_FN (sup_unicode_dance),
  [INTEGRAL_UC] = ACTION_TAP_DANCE_FN (integral_unicode_dance),
  [LINE_INTEGRAL_UC] = ACTION_TAP_DANCE_FN (line_integral_unicode_dance),
  [ROOT_UC] = ACTION_TAP_DANCE_FN (root_unicode_dance),
  [ELEMENT_OF_UC] = ACTION_TAP_DANCE_FN (element_of_unicode_dance),
  [SUBSET_OF_UC] = ACTION_TAP_DANCE_FN (subset_of_unicode_dance),
  [SUBSET_OR_EQ_UC] = ACTION_TAP_DANCE_FN (subset_or_equal_unicode_dance),
  [THERE_EXIST_UC] = ACTION_TAP_DANCE_FN (there_exists_unicode_dance),
  [AND_UC] = ACTION_TAP_DANCE_FN (and_unicode_dance),
  [UNCONDITIONALLY_TRUE_UC] = ACTION_TAP_DANCE_FN (unconditionally_true_unicode_dance),
  [PROVES_UC] = ACTION_TAP_DANCE_FN (proves_unicode_dance),
  [PLUSMINUS_UC] = ACTION_TAP_DANCE_FN (plusminus_unicode_dance)
};


#endif