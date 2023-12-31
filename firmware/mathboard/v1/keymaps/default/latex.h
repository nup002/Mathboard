// Definitions specifically for LaTeX

#ifndef LATEX_H
#define LATEX_H

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
#define Phi_LTX     "\\Phi"
#define chi_LTX     "\\chi"
#define psi_LTX     "\\psi"
#define Psi_LTX     "\\Psi"
#define omega_LTX   "\\omega"
#define Omega_LTX   "\\Omega"

// Comparison and equivalence
#define notequal_LTX   "\\neq"
#define almostequal_LTX   "\\approx"
#define proportional_LTX   "\\propto"
#define identicalto_LTX   "\\equiv"
#define lessorequal_LTX   "\\leq"
#define greaterorequal_LTX   "\\geq"
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
#define arrow_LTX   "\\rightarrow"
#define partial_derivative_LTX   "\\partial"
#define nabla_LTX   "\\nabla"

// Set theory 
#define union_LTX   "\\bigcup_{}^{}"
#define intersection_LTX   "\\bigcap_{}^{}"
#define element_of_LTX   "\\in"
#define not_element_of_LTX   "\\notin"
#define empty_set_LTX   "\\varnothing" // Requires amssymb
#define subset_of_LTX   "\\subset"
#define not_subset_of_LTX   "\\not\\subset"
#define set_difference_LTX   "\\setminus"
#define subset_or_equal_LTX   "\\subseteq"
#define not_subset_or_equal_LTX   "\\nsubseteq"
#define disjoint_union_LTX   "\\sqcup"

// Logic
#define arrow_implies_LTX   "\\Rightarrow"
#define arrow_if_and_only_if_LTX   "\\Leftrightarrow"
#define there_exists_LTX   "\\exists"
#define there_does_not_exist_LTX   "\\nexists"
#define and_LTX   "\\wedge"
#define or_LTX   "\\vee"
#define xor_LTX   "\\veebar"
#define for_all_LTX   "\\forall"
#define unconditionally_true_LTX   "\\top"
#define unconditionally_false_LTX   "\\bot"
#define not_LTX   "\\neg"
#define proves_LTX   "\\vdash"
#define models_LTX   "\\models"

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

#define LTX_FLAG "LATEX: "

void send_and_backtrack_4(const char *string){
    //send_string(string);
    send_string(string);
    for (int i = 0; i < 4; ++i){tap_code(KC_LEFT);}
}

void send_and_backtrack_3(const char *string){
    //send_string(string);
    send_string(string);
    tap_code(KC_LEFT);
}

void send_and_backtrack_1(const char *string){
    //send_string(string);
    send_string(string);
    tap_code(KC_LEFT);
}

void send_latex(const char *string){
    // Else-if for special characters. Cannot use case switch structure because the defined latex strings are not constants.
    if (!strcmp(string, sum_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, n_ary_product_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, double_integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, triple_integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, line_integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, surface_integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, volume_integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, square_root_LTX)){send_and_backtrack_1(string);}
    else if (!strcmp(string, cube_root_LTX)){send_and_backtrack_1(string);}
    else if (!strcmp(string, fourth_root_LTX)){send_and_backtrack_1(string);}
    else if (!strcmp(string, union_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, intersection_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, frac_LTX)){send_and_backtrack_3(string);}
    else if(strlen(string) > 2 && !strcmp(string + strlen(string) - 2, "{}")) {
        // In this case the string is meant to wrap around the previous character
        tap_code(KC_LEFT);
        // Create a new string that contains the original string up to the last curly brace
        char substring[strlen(string)];
        memcpy(substring, &string[0], strlen(string)-1);
        substring[strlen(string)-1] = '\0';
        send_string(substring);
        tap_code(KC_RIGHT);
        // Send the final curly brace
        tap_code16(KC_RIGHT_CURLY_BRACE);
    } else {
        send_string(string);
    }
}

void send_latex_on_keypress(const char *string, keyrecord_t *record){
    if (record->event.pressed) {
        send_latex(string);
    };
};

#endif