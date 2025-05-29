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

#ifndef LATEX_H
#define LATEX_H

#include QMK_KEYBOARD_H

// Greek letters
#define alpha_LTX   "\\alpha"
#define beta_LTX    "\\beta"
#define gamma_LTX   "\\gamma"
#define Gamma_LTX   "\\Gamma"
#define delta_LTX   "\\delta"
#define Delta_LTX   "\\Delta"
#define epsilon_LTX "\\epsilon"
#define zeta_LTX    "\\zeta"
#define eta_LTX     "\\eta"
#define theta_LTX   "\\theta"
#define Theta_LTX   "\\Theta"
#define iota_LTX    "\\iota"
#define kappa_LTX   "\\kappa"
#define lambda_LTX  "\\lambda"
#define Lambda_LTX  "\\Lambda"
#define mu_LTX      "\\mu"
#define nu_LTX      "\\nu"
#define xi_LTX      "\\xi"
#define Xi_LTX      "\\Xi"
#define omicron_LTX "\\αmathrm{o}"
#define pi_LTX      "\\pi"
#define Pi_LTX      "\\Pi"
#define rho_LTX     "\\rho"
#define sigma_LTX   "\\sigma"
#define Sigma_LTX   "\\Sigma"
#define tau_LTX     "\\tau"
#define upsilon_LTX "\\upsilon"
#define phi_LTX     "\\phi"
#define varphi_LTX  "\\varphi"
#define Phi_LTX     "\\Phi"
#define chi_LTX     "\\chi"
#define psi_LTX     "\\psi"
#define Psi_LTX     "\\Psi"
#define omega_LTX   "\\omega"
#define Omega_LTX   "\\Omega"

// Comparison and equivalence
#define not_equal_LTX   "\\neq"
#define almost_equal_LTX   "\\approx"
#define proportional_LTX   "\\propto"
#define asymptotically_equal_LTX "\\simeq"
#define approximately_equal_LTX "\\cong" 
#define identical_to_LTX   "\\equiv"
#define not_identical_to_LTX   "\\not\\equiv"
#define colon_equals_LTX "\\coloneq" // Requires mathtools
#define equal_by_definition_LTX "\\overset{\\underset{\\mathrm{def}}{}}{=}"
#define less_or_equal_LTX   "\\leq"
#define greater_or_equal_LTX   "\\geq"
#define much_greater_than_LTX   "\\gg"
#define much_much_greater_than_LTX   "\\ggg"
#define much_less_than_LTX   "\\ll"
#define much_much_less_than_LTX   "\\lll"

// Modifiers
#define circumflex_LTX   "\\hat{}"
#define check_LTX   "\\check{}"
#define combining_tilde_LTX   "\\tilde{}"
#define combining_bar_LTX   "\\bar{}"
#define combining_arrow_LTX   "\\vec{}"
#define combining_dot_LTX   "\\dot{}"
#define combining_2dot_LTX   "\\ddot{}"
#define prime_LTX   "\\prime" // not in use currently
#define transposed_LTX   "^\\top"
#define sup_0_LTX   "^{0}"
#define sup_1_LTX   "^{1}"
#define sup_2_LTX   "^{2}"
#define sup_n_LTX   "^{n}"
#define sup_i_LTX   "^{i}"
#define sup_j_LTX   "^{j}"
#define sub_0_LTX   "_{0}"
#define sub_1_LTX   "_{1}"
#define sub_2_LTX   "_{2}"
#define sub_n_LTX   "_{n}"
#define sub_i_LTX   "_{i}"
#define sub_j_LTX   "_{j}"

// Algebra and calculus
#define sum_LTX   "\\sum_{}^{}"
#define n_ary_product_LTX   "\\prod_{}^{}"
#define integral_LTX   "\\int_{}^{}"
#define double_integral_LTX   "\\iint_{}^{}"
#define triple_integral_LTX   "\\iiint_{}^{}"
#define line_integral_LTX   "\\oint_{}^{}"
#define surface_integral_LTX   "\\oiint_{}^{}" // Requires one of wasysym, esint, pxfonts
#define volume_integral_LTX   "\\oiiint_{}^{}" // Requires pxfonts
#define square_root_LTX   "\\sqrt{}"
#define cube_root_LTX   "\\sqrt[3]{}"
#define fourth_root_LTX   "\\sqrt[4]{}"
#define partial_differential_LTX   "\\partial"
#define nabla_LTX   "\\nabla"

// Arrows
#define right_arrow_LTX   "\\rightarrow"
#define leftright_arrow_LTX   "\\leftrightarrow"
#define left_arrow_LTX   "\\leftarrow"
#define right_double_arrow_LTX   "\\Rightarrow"
#define leftright_double_arrow_LTX   "\\Leftrightarrow"
#define left_double_arrow_LTX   "\\Leftarrow"

// Set theory 
#define union_LTX   "\\bigcup_{}^{}"
#define intersection_LTX   "\\bigcap_{}^{}"
#define element_of_LTX   "\\in"
#define not_element_of_LTX   "\\notin"
#define contains_as_member_LTX   "\\ni"
#define empty_set_LTX   "\\varnothing" // Requires amssymb
#define power_set_LTX   "\\mathcal{P}"
#define proper_subset_LTX   "\\subset"
#define not_proper_subset_LTX   "\\not\\subset"
#define set_difference_LTX   "\\setminus"
#define subset_LTX   "\\subseteq"
#define not_subset_LTX   "\\nsubseteq"
#define disjoint_union_LTX   "\\sqcup"
#define direct_sum_LTX   "\\oplus"

// Logic
#define there_exists_LTX   "\\exists"
#define there_does_not_exist_LTX   "\\nexists"
#define and_LTX   "\\wedge"
#define or_LTX   "\\vee"
#define xor_LTX   "\\veebar"
#define for_all_LTX   "\\forall"
#define not_LTX   "\\neg"
#define proves_LTX   "\\vdash"
#define models_LTX   "\\models"
#define down_tack_LTX   "\\top"
#define up_tack_LTX     "\\bot"

// Others
#define dotproduct_LTX   "\\cdot"
#define crossproduct_LTX   "\\times"
#define plusminus_LTX   "\\pm"
#define minusplus_LTX   "\\mp"
#define parallel_LTX   "\\parallel"
#define degree_LTX   "\\degree"
#define infinity_LTX   "\\infty"
#define matrix_LTX  "\\begin{bmatrix} a & b \\\\ c & d \\end{bmatrix}" // Requires amsmath
#define frac_LTX  "\\frac{}{}"
#define circled_times_LTX  "\\otimes"

//Number systems
#define naturals_LTX   "\\mathbb{N}"
#define integers_LTX   "\\mathbb{Z}"    
#define rationals_LTX   "\\mathbb{Q}"
#define reals_LTX   "\\mathbb{R}"
#define complexes_LTX   "\\mathbb{C}"

#define LTX_FLAG "LATEX: "

void send_and_backtrack_4(const char *string);

void send_and_backtrack_3(const char *string);

void send_and_backtrack_1(const char *string);

void send_latex(const char *string);

void send_latex_on_keypress(const char *string, keyrecord_t *record);

#endif