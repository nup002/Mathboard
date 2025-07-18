/*
 * Copyright 2023 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stddef.h>  // For NULL
#include "../unicode_symbols.h"
#include "../symbol_definitions.h"
#include "../latex.h"
#include "../microsoft_office.h"
#include "greek_symbols.h"

// Greek letters - lowercase
const symbol_definition_t SYMBOL_ALPHA = DEFINE_SYMBOL(
    alpha,
    0x03B1,                  // Unicode: α
    "\\alpha", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_BETA = DEFINE_SYMBOL(
    beta,
    0x03B2,                  // Unicode: β
    "\\beta", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_GAMMA = DEFINE_SYMBOL(
    gamma,
    0x03B3,                  // Unicode: γ
    "\\gamma", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_DELTA = DEFINE_SYMBOL(
    delta,
    0x03B4,                  // Unicode: δ
    "\\delta", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_EPSILON = DEFINE_SYMBOL(
    epsilon,
    0x03B5,                  // Unicode: ε
    "\\epsilon", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_ZETA = DEFINE_SYMBOL(
    zeta,
    0x03B6,                  // Unicode: ζ
    "\\zeta", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_ETA = DEFINE_SYMBOL(
    eta,
    0x03B7,                  // Unicode: η
    "\\eta", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_THETA = DEFINE_SYMBOL(
    theta,
    0x03B8,                  // Unicode: θ
    "\\theta", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_IOTA = DEFINE_SYMBOL(
    iota,
    0x03B9,                  // Unicode: ι
    "\\iota", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_KAPPA = DEFINE_SYMBOL(
    kappa,
    0x03BA,                  // Unicode: κ
    "\\kappa", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_LAMBDA = DEFINE_SYMBOL(
    lambda,
    0x03BB,                  // Unicode: λ
    "\\lambda", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_MU = DEFINE_SYMBOL(
    mu,
    0x03BC,                  // Unicode: μ
    "\\mu", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_NU = DEFINE_SYMBOL(
    nu,
    0x03BD,                  // Unicode: ν
    "\\nu", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_XI = DEFINE_SYMBOL(
    xi,
    0x03BE,                  // Unicode: ξ
    "\\xi", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_OMICRON = DEFINE_SYMBOL(
    omicron,
    0x03BF,                  // Unicode: ο
    "\\omicron", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_PI = DEFINE_SYMBOL(
    pi,
    0x03C0,                  // Unicode: π
    "\\pi", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_RHO = DEFINE_SYMBOL(
    rho,
    0x03C1,                  // Unicode: ρ
    "\\rho", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_SIGMA = DEFINE_SYMBOL(
    sigma,
    0x03C3,                  // Unicode: σ
    "\\sigma", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_TAU = DEFINE_SYMBOL(
    tau,
    0x03C4,                  // Unicode: τ
    "\\tau", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_UPSILON = DEFINE_SYMBOL(
    upsilon,
    0x03C5,                  // Unicode: υ
    "\\upsilon", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_PHI = DEFINE_SYMBOL(
    phi,
    0x03C6,                  // Unicode: φ
    "\\phi", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_CHI = DEFINE_SYMBOL(
    chi,
    0x03C7,                  // Unicode: χ
    "\\chi", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_PSI = DEFINE_SYMBOL(
    psi,
    0x03C8,                  // Unicode: ψ
    "\\psi", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_OMEGA = DEFINE_SYMBOL(
    omega,
    0x03C9,                  // Unicode: ω
    "\\omega", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

// Greek letters - uppercase
const symbol_definition_t SYMBOL_ALPHA_UPPERCASE = DEFINE_SYMBOL(
    alpha_uppercase,
    0x0391,                  // Unicode: Α
    "\\Alpha", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_BETA_UPPERCASE = DEFINE_SYMBOL(
    beta_uppercase,
    0x0392,                  // Unicode: Β
    "\\Beta", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_GAMMA_UPPERCASE = DEFINE_SYMBOL(
    gamma_uppercase,
    0x0393,                  // Unicode: Γ
    "\\Gamma", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_DELTA_UPPERCASE = DEFINE_SYMBOL(
    delta_uppercase,
    0x0394,                  // Unicode: Δ
    "\\Delta", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_EPSILON_UPPERCASE = DEFINE_SYMBOL(
    epsilon_uppercase,
    0x0395,                  // Unicode: Ε
    "\\Epsilon", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_ZETA_UPPERCASE = DEFINE_SYMBOL(
    zeta_uppercase,
    0x0396,                  // Unicode: Ζ
    "\\Zeta", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_ETA_UPPERCASE = DEFINE_SYMBOL(
    eta_uppercase,
    0x0397,                  // Unicode: Η
    "\\Eta", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_THETA_UPPERCASE = DEFINE_SYMBOL(
    theta_uppercase,
    0x0398,                  // Unicode: Θ
    "\\Theta", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_IOTA_UPPERCASE = DEFINE_SYMBOL(
    iota_uppercase,
    0x0399,                  // Unicode: Ι
    "\\Iota", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_KAPPA_UPPERCASE = DEFINE_SYMBOL(
    kappa_uppercase,
    0x039A,                  // Unicode: Κ
    "\\Kappa", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_LAMBDA_UPPERCASE = DEFINE_SYMBOL(
    lambda_uppercase,
    0x039B,                  // Unicode: Λ
    "\\Lambda", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_MU_UPPERCASE = DEFINE_SYMBOL(
    mu_uppercase,
    0x039C,                  // Unicode: Μ
    "\\Mu", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_NU_UPPERCASE = DEFINE_SYMBOL(
    nu_uppercase,
    0x039D,                  // Unicode: Ν
    "\\Nu", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_XI_UPPERCASE = DEFINE_SYMBOL(
    xi_uppercase,
    0x039E,                  // Unicode: Ξ
    "\\Xi", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_OMICRON_UPPERCASE = DEFINE_SYMBOL(
    omicron_uppercase,
    0x039F,                  // Unicode: Ο
    "\\Omicron", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_PI_UPPERCASE = DEFINE_SYMBOL(
    pi_uppercase,
    0x03A0,                  // Unicode: Π
    "\\Pi", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_RHO_UPPERCASE = DEFINE_SYMBOL(
    rho_uppercase,
    0x03A1,                  // Unicode: Ρ
    "\\Rho", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_SIGMA_UPPERCASE = DEFINE_SYMBOL(
    sigma_uppercase,
    0x03A3,                  // Unicode: Σ
    "\\Sigma", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_TAU_UPPERCASE = DEFINE_SYMBOL(
    tau_uppercase,
    0x03A4,                  // Unicode: Τ
    "\\Tau", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_UPSILON_UPPERCASE = DEFINE_SYMBOL(
    upsilon_uppercase,
    0x03A5,                  // Unicode: Υ
    "\\Upsilon", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_PHI_UPPERCASE = DEFINE_SYMBOL(
    phi_uppercase,
    0x03A6,                  // Unicode: Φ
    "\\Phi", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_CHI_UPPERCASE = DEFINE_SYMBOL(
    chi_uppercase,
    0x03A7,                  // Unicode: Χ
    "\\Chi", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_PSI_UPPERCASE = DEFINE_SYMBOL(
    psi_uppercase,
    0x03A8,                  // Unicode: Ψ
    "\\Psi", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_OMEGA_UPPERCASE = DEFINE_SYMBOL(
    omega_uppercase,
    0x03A9,                  // Unicode: Ω
    "\\Omega", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);
