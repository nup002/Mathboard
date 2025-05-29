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
// The equivalent file for multitap symbols is 'multitap_symbols_defs.h'

#include "normal_symbols_defs.h"
#include QMK_KEYBOARD_H
#include "globals.h"
#include "mode.h"
#include "unicode_symbols.h"
#include "microsoft_office.h"
#include "latex.h"

// 
// Greek non-multitap symbols
//

void alpha_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_alpha, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(alpha_LTX, record);}
};

void beta_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_beta, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(beta_LTX, record);}
};

void epsilon_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_epsilon, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(epsilon_LTX, record);}
};

void iota_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_iota, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(iota_LTX, record);}
};

void zeta_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_zeta, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(zeta_LTX, record);}
};

void eta_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_eta, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(eta_LTX, record);}
};

void kappa_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_kappa, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(kappa_LTX, record);}
};

void mu_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_mu, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(mu_LTX, record);}
};

void nu_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_nu, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(nu_LTX, record);}
};

void omicron_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_omicron, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(omicron_LTX, record);}
};


void rho_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_rho, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(rho_LTX, record);}
};

void tau_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_tau, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(tau_LTX, record);}
};

void upsilon_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_upsilon, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(upsilon_LTX, record);}
};

void chi_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_chi, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(chi_LTX, record);}
};

//
// Comparison and equivalence non-multitap symbols
//
void notequal_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_not_equal, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(not_equal_LTX, record);}
};

void almostequal_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_almost_equal, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(almost_equal_LTX, record);}
};

void proportional_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_proportional, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(proportional_LTX, record);}
};

void identicalto_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_identical_to, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(identical_to_LTX, record);}
};

void lessorequal_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_less_or_equal, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(less_or_equal_LTX, record);}
};

void greaterorequal_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_greater_or_equal, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(greater_or_equal_LTX, record);}
};


// 
// Combining diacritics (overbars, subscripts, superscripts) non-multitap symbols
//
void combiningtilde_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE){send_unicode_on_keypress(_combining_tilde, record);}
    else if (user_config.MODE == MOF_MODE){send_mof_on_keypress(ACCENT_TILDE_MOF, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(combining_tilde_LTX, record);}
};

void combiningbar_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE){send_unicode_on_keypress(_combining_bar, record);}
    else if (user_config.MODE == MOF_MODE){send_mof_on_keypress(ACCENT_BAR_MOF, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(combining_bar_LTX, record);}
};

void accent_arrow_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE){send_unicode_on_keypress(_combining_arrow, record);}
    else if (user_config.MODE == MOF_MODE){send_mof_on_keypress(ACCENT_ARROW_MOF, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(combining_arrow_LTX, record);}
};

void circumflex_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE){send_unicode_on_keypress(_circumflex, record);}
    else if (user_config.MODE == MOF_MODE){send_mof_on_keypress(ACCENT_HAT_MOF, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(circumflex_LTX, record);}
};

void check_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE){send_unicode_on_keypress(_check, record);}
    else if (user_config.MODE == MOF_MODE){send_mof_on_keypress(ACCENT_CHECK_MOF, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(check_LTX, record);}
};

//
// Algebra and Calculus non-multitap symbols
//
void sum_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE){send_unicode_on_keypress(_sum, record);}
    else if (user_config.MODE == MOF_MODE){send_mof_on_keypress(SUM_MOF, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(sum_LTX, record);}
};

void naryproduct_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE){send_unicode_on_keypress(_n_ary_product, record);}
    else if (user_config.MODE == MOF_MODE){send_mof_on_keypress(N_ARY_PRODUCT_MOF, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(n_ary_product_LTX, record);}
};

void partialderivative_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_partial_differential, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(partial_differential_LTX, record);}
};

void nabla_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_nabla, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(nabla_LTX, record);}
};

//
// Set Theory non-multitap symbols
//
void not_element_of_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_not_element_of, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(not_element_of_LTX, record);}
};

void disjointunion_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_disjoint_union, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(disjoint_union_LTX, record);}
};

// 
// Logic non-multitap symbols
//

void not_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_not, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(not_LTX, record);}
};

void forall_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_for_all, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(for_all_LTX, record);}
};

//
// Other non-multitap symbols
//
void degree_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_degree, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(degree_LTX, record);}
};

void fraction_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE){}
    else if (user_config.MODE == MOF_MODE){send_mof_on_keypress(FRAC_MOF, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(frac_LTX, record);}
};

void dotproduct_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_dotproduct, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(dotproduct_LTX, record);}
};

void infinity_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_infinity, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(infinity_LTX, record);}
};

//
// Number system non-multitap symbols
//
void naturals_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_naturals, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(naturals_LTX, record);}
};

void integers_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_integers, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(integers_LTX, record);}
};

void rationals_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_rationals, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(rationals_LTX, record);}
};

void reals_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_reals, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(reals_LTX, record);}
};

void complexes_key(keyrecord_t *record){
    if (user_config.MODE == UC_MODE || user_config.MODE == MOF_MODE){send_unicode_on_keypress(_complexes, record);}
    else if (user_config.MODE == LTX_MODE){send_latex_on_keypress(complexes_LTX, record);}
};