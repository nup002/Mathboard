#ifndef KEY_DEFINITIONS_H
#define KEY_DEFINITIONS_H
#include QMK_KEYBOARD_H
#include "globs.h"
#include "unicode_symbols.h"
#include "tapdance.h"
#include "microsoft_office.h"


void alpha_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_alpha, record);}
};

void notequal_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_notequal, record);}
};

void beta_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_beta, record);}
};

void almostequal_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_almostequal, record);}
};

void circumflex_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_circumflex, record);}
    else if (MODE == MOF){send_mof_on_keypress(ACCENT_HAT_MOF, record);}
};

void check_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_check, record);}
    else if (MODE == MOF){send_mof_on_keypress(ACCENT_CHECK_MOF, record);}
};

void proportional_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_proportional, record);}
};

void identicalto_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_identicalto, record);}
};

void combiningtilde_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_combining_tilde, record);}
    else if (MODE == MOF){send_mof_on_keypress(ACCENT_TILDE_MOF, record);}
};

void combiningbar_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_combining_bar, record);}
    else if (MODE == MOF){send_mof_on_keypress(ACCENT_BAR_MOF, record);}
};

void epsilon_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_epsilon, record);}
};

void lessorequal_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_lessorequal, record);}
};

void zeta_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_zeta, record);}
};

void greaterorequal_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_greaterorequal, record);}
};

void accent_arrow_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_combining_arrow, record);}
    else if (MODE == MOF){send_mof_on_keypress(ACCENT_ARROW_MOF, record);}
};

void eta_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_eta, record);}
};

void iota_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_iota, record);}
};

void sum_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_sum, record);}
    else if (MODE == MOF){send_mof_on_keypress(SUM_MOF, record);}
};

void kappa_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_kappa, record);}
};

void naryproduct_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_n_ary_product, record);}
    else if (MODE == MOF){send_mof_on_keypress(N_ARY_PRODUCT_MOF, record);}
};

void union_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_union, record);}
    else if (MODE == MOF){send_mof_on_keypress(UNION_MOF, record);}
};

void intersection_key(keyrecord_t *record){
    if (MODE == UC){send_hex_on_keypress(_intersection, record);}
    else if (MODE == MOF){send_mof_on_keypress(INTERSECTION_MOF, record);}
};

void mu_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_mu, record);}
};

void emptyset_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_empty_set, record);}
};

void nu_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_nu, record);}
};

void arrow_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_arrow, record);}
};

void setdifference_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_set_difference, record);}
};

void omicron_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_omicron, record);}
};

void partialderivative_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_partial_derivative, record);}
};

void nabla_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_nabla, record);}
};

void disjointunion_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_disjoint_union, record);}
};

void rho_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_rho, record);}
};

void arrowimplies_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_arrow_implies, record);}
};

void arrowifandonlyif_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_arrow_if_and_only_if, record);}
};

void dotproduct_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_dotproduct, record);}
};

void crossproduct_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_crossproduct, record);}
};

void tau_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_tau, record);}
};

void upsilon_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_upsilon, record);}
};

void parallel_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_parallel, record);}
};

void forall_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_for_all, record);}
};

void chi_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_chi, record);}
};

void degree_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_degree, record);}
};

void infinity_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_infinity, record);}
};

void not_key(keyrecord_t *record){
    if (MODE == UC || MODE == MOF){send_hex_on_keypress(_not, record);}
};

void matrix_key(keyrecord_t *record){
    if (MODE == UC){}
    else if (MODE == MOF){send_mof_on_keypress(MATRIX_MOF, record);}
};

void fraction_key(keyrecord_t *record){
    if (MODE == UC){}
    else if (MODE == MOF){}
};


// void _key(keyrecord_t *record){
//     if (MODE == UC || MODE == MOF){send_hex_on_keypress(, record);}
// };


#endif