#ifndef KEY_DEFINITIONS_H
#define KEY_DEFINITIONS_H
#include QMK_KEYBOARD_H
#include "globs.h"
#include "unicode_symbols.h"
#include "tapdance.h"
#include "microsoft_office.h"
#include "latex.h"


void alpha_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_alpha, record);}
    else if (MODE == LTX){send_latex_on_keypress(alpha_LTX, record);}
};

void notequal_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_notequal, record);}
    else if (MODE == LTX){send_latex_on_keypress(notequal_LTX, record);}
};

void beta_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_beta, record);}
    else if (MODE == LTX){send_latex_on_keypress(beta_LTX, record);}
};

void almostequal_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_almostequal, record);}
    else if (MODE == LTX){send_latex_on_keypress(almostequal_LTX, record);}
};

void circumflex_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_circumflex, record);}
    else if (MODE == MOF){send_mof_on_keypress(ACCENT_HAT_MOF, record);}
    else if (MODE == LTX){send_latex_on_keypress(circumflex_LTX, record);}
};

void check_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_check, record);}
    else if (MODE == MOF){send_mof_on_keypress(ACCENT_CHECK_MOF, record);}
    else if (MODE == LTX){send_latex_on_keypress(check_LTX, record);}
};

void proportional_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_proportional, record);}
    else if (MODE == LTX){send_latex_on_keypress(proportional_LTX, record);}
};

void identicalto_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_identicalto, record);}
    else if (MODE == LTX){send_latex_on_keypress(identicalto_LTX, record);}
};

void combiningtilde_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_combining_tilde, record);}
    else if (MODE == MOF){send_mof_on_keypress(ACCENT_TILDE_MOF, record);}
    else if (MODE == LTX){send_latex_on_keypress(combining_tilde_LTX, record);}
};

void combiningbar_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_combining_bar, record);}
    else if (MODE == MOF){send_mof_on_keypress(ACCENT_BAR_MOF, record);}
    else if (MODE == LTX){send_latex_on_keypress(combining_bar_LTX, record);}
};

void epsilon_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_epsilon, record);}
    else if (MODE == LTX){send_latex_on_keypress(epsilon_LTX, record);}
};

void lessorequal_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_lessorequal, record);}
    else if (MODE == LTX){send_latex_on_keypress(lessorequal_LTX, record);}
};

void zeta_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_zeta, record);}
    else if (MODE == LTX){send_latex_on_keypress(zeta_LTX, record);}
};

void greaterorequal_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_greaterorequal, record);}
    else if (MODE == LTX){send_latex_on_keypress(greaterorequal_LTX, record);}
};

void accent_arrow_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_combining_arrow, record);}
    else if (MODE == MOF){send_mof_on_keypress(ACCENT_ARROW_MOF, record);}
    else if (MODE == LTX){send_latex_on_keypress(combining_arrow_LTX, record);}
};

void eta_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_eta, record);}
    else if (MODE == LTX){send_latex_on_keypress(eta_LTX, record);}
};

void iota_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_iota, record);}
    else if (MODE == LTX){send_latex_on_keypress(iota_LTX, record);}
};

void sum_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_sum, record);}
    else if (MODE == MOF){send_mof_on_keypress(SUM_MOF, record);}
    else if (MODE == LTX){send_latex_on_keypress(sum_LTX, record);}
};

void kappa_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_kappa, record);}
    else if (MODE == LTX){send_latex_on_keypress(kappa_LTX, record);}
};

void naryproduct_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_n_ary_product, record);}
    else if (MODE == MOF){send_mof_on_keypress(N_ARY_PRODUCT_MOF, record);}
    else if (MODE == LTX){send_latex_on_keypress(n_ary_product_LTX, record);}
};

void union_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_union, record);}
    else if (MODE == MOF){send_mof_on_keypress(UNION_MOF, record);}
    else if (MODE == LTX){send_latex_on_keypress(union_LTX, record);}
};

void intersection_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_intersection, record);}
    else if (MODE == MOF){send_mof_on_keypress(INTERSECTION_MOF, record);}
    else if (MODE == LTX){send_latex_on_keypress(intersection_LTX, record);}
};

void mu_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_mu, record);}
    else if (MODE == LTX){send_latex_on_keypress(mu_LTX, record);}
};

void emptyset_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_empty_set, record);}
    else if (MODE == LTX){send_latex_on_keypress(empty_set_LTX, record);}
};

void nu_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_nu, record);}
    else if (MODE == LTX){send_latex_on_keypress(nu_LTX, record);}
};

void arrow_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_arrow, record);}
    else if (MODE == LTX){send_latex_on_keypress(arrow_LTX, record);}
};

void setdifference_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_set_difference, record);}
    else if (MODE == LTX){send_latex_on_keypress(set_difference_LTX, record);}
};

void omicron_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_omicron, record);}
    else if (MODE == LTX){send_latex_on_keypress(omicron_LTX, record);}
};

void partialderivative_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_partial_derivative, record);}
    else if (MODE == LTX){send_latex_on_keypress(partial_derivative_LTX, record);}
};

void nabla_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_nabla, record);}
    else if (MODE == LTX){send_latex_on_keypress(nabla_LTX, record);}
};

void disjointunion_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_disjoint_union, record);}
    else if (MODE == LTX){send_latex_on_keypress(disjoint_union_LTX, record);}
};

void rho_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_rho, record);}
    else if (MODE == LTX){send_latex_on_keypress(rho_LTX, record);}
};

void arrowimplies_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_arrow_implies, record);}
    else if (MODE == LTX){send_latex_on_keypress(arrow_implies_LTX, record);}
};

void arrowifandonlyif_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_arrow_if_and_only_if, record);}
    else if (MODE == LTX){send_latex_on_keypress(arrow_if_and_only_if_LTX, record);}
};

void dotproduct_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_dotproduct, record);}
    else if (MODE == LTX){send_latex_on_keypress(dotproduct_LTX, record);}
};

void crossproduct_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_crossproduct, record);}
    else if (MODE == LTX){send_latex_on_keypress(crossproduct_LTX, record);}
};

void tau_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_tau, record);}
    else if (MODE == LTX){send_latex_on_keypress(tau_LTX, record);}
};

void upsilon_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_upsilon, record);}
    else if (MODE == LTX){send_latex_on_keypress(upsilon_LTX, record);}
};

void parallel_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_parallel, record);}
    else if (MODE == LTX){send_latex_on_keypress(parallel_LTX, record);}
};

void forall_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_for_all, record);}
    else if (MODE == LTX){send_latex_on_keypress(for_all_LTX, record);}
};

void chi_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_chi, record);}
    else if (MODE == LTX){send_latex_on_keypress(chi_LTX, record);}
};

void degree_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_degree, record);}
    else if (MODE == LTX){send_latex_on_keypress(degree_LTX, record);}
};

void infinity_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_infinity, record);}
    else if (MODE == LTX){send_latex_on_keypress(infinity_LTX, record);}
};

void not_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_not, record);}
    else if (MODE == LTX){send_latex_on_keypress(not_LTX, record);}
};

void matrix_key(keyrecord_t *record){
    if (MODE == UC){}
    else if (MODE == MOF){send_mof_on_keypress(MATRIX_MOF, record);}
};

void fraction_key(keyrecord_t *record){
    if (MODE == UC){}
    else if (MODE == MOF){send_mof_on_keypress(FRAC_MOF, record);}
    else if (MODE == LTX){send_latex_on_keypress(frac_LTX, record);}
};

#endif