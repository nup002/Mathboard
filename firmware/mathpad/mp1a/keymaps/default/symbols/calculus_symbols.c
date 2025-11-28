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
#include "symbols.h"
#include "calculus_symbols.h"

// Algebra and calculus symbols
const symbol_definition_t SYMBOL_SUM = DEFINE_SYMBOL(
    sum,
    0x2211,                  // Unicode: ∑
    "\\sum_{}^{}", LATEX_3BACKTRACK,
    "\\sum_a^b", MOF_1SPACE_DELETE_LIMS,
    "sum from{} to{}", LOF_6BACKTRACK
); //TODO: LOF brackets are autocompleted

const symbol_definition_t SYMBOL_N_ARY_PRODUCT = DEFINE_SYMBOL(
    n_ary_product,
    0x220F,                  // Unicode: ∏
    "\\prod_{}^{}", LATEX_3BACKTRACK,
    "\\prod_a^b", MOF_1SPACE_DELETE_LIMS,
    "prod from{} to{}", LOF_6BACKTRACK
);

const symbol_definition_t SYMBOL_INTEGRAL = DEFINE_SYMBOL(
    integral,
    0x222B,                  // Unicode: ∫
    "\\int_{}^{}", LATEX_3BACKTRACK,
    "\\int_a^b", MOF_1SPACE_DELETE_LIMS,
    "int from{} to{}", LOF_6BACKTRACK
);

const symbol_definition_t SYMBOL_DOUBLE_INTEGRAL = DEFINE_SYMBOL(
    double_integral,
    0x222C,                  // Unicode: ∬
    "\\iint_{}^{}", LATEX_3BACKTRACK,
    "\\iint_a^b", MOF_1SPACE_DELETE_LIMS,
    "iint from{} to{}", LOF_6BACKTRACK
);

const symbol_definition_t SYMBOL_TRIPLE_INTEGRAL = DEFINE_SYMBOL(
    triple_integral,
    0x222D,                  // Unicode: ∭
    "\\iiint_{}^{}", LATEX_3BACKTRACK,
    "\\iiint_a^b", MOF_1SPACE_DELETE_LIMS,
    "iiint from{} to{}", LOF_6BACKTRACK
);

const symbol_definition_t SYMBOL_LINE_INTEGRAL = DEFINE_SYMBOL(
    line_integral,
    0x222E,                  // Unicode: ∮
    "\\oint_{}^{}", LATEX_3BACKTRACK,
    "\\oint_a^b", MOF_1SPACE_DELETE_LIMS,
    "lint from{} to{}", LOF_6BACKTRACK
);

const symbol_definition_t SYMBOL_SURFACE_INTEGRAL = DEFINE_SYMBOL(
    surface_integral,
    0x222F,                  // Unicode: ∯
    "\\oiint_{}^{}", LATEX_3BACKTRACK,
    "\\oiint_a^b", MOF_1SPACE_DELETE_LIMS,
    "llint from{} to{}", LOF_6BACKTRACK
);

const symbol_definition_t SYMBOL_VOLUME_INTEGRAL = DEFINE_SYMBOL(
    volume_integral,
    0x2230,                  // Unicode: ∰
    "\\oiiint_{}^{}", LATEX_3BACKTRACK,
    "\\oiiint_a^b", MOF_1SPACE_DELETE_LIMS,
    "lllint from{} to{}", LOF_6BACKTRACK
);

const symbol_definition_t SYMBOL_SQUARE_ROOT = DEFINE_SYMBOL(
    square_root,
    0x221A,                  // Unicode: √
    "\\sqrt{}", LATEX_1BACKTRACK,
    "\\sqrt", MOF_2SPACE_1BACKTRACK,
    "sqrt{}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_CUBE_ROOT = DEFINE_SYMBOL(
    cube_root,
    0x221B,                  // Unicode: ∛
    "\\sqrt[3]{}", LATEX_1BACKTRACK,
    "\\cbrt", MOF_2SPACE_1BACKTRACK,
    "nroot{3}{}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_FOURTH_ROOT = DEFINE_SYMBOL(
    fourth_root,
    0x221C,                  // Unicode: ∜
    "\\sqrt[4]{}", LATEX_1BACKTRACK,
    "\\qdrt", MOF_2SPACE_1BACKTRACK,
    "nroot{4}{}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_PARTIAL_DIFFERENTIAL = DEFINE_SYMBOL(
    partial_differential,
    0x2202,                  // Unicode: ∂
    "\\partial", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    NULL, LOF_1SPACE
);

const symbol_definition_t SYMBOL_NABLA = DEFINE_SYMBOL(
    nabla,
    0x2207,                  // Unicode: ∇
    "\\nabla", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    " nabla", LOF_1SPACE
);

const symbol_definition_t SYMBOL_FRAC = DEFINE_SYMBOL(
    frac,
    0x2044,                  // Unicode: ⁄ (fraction slash)
    "\\frac{}{}", LATEX_1BACKTRACK,
    " a/b", MOF_1SPACE_DELETE_LIMS,
    "{} over {}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_MATRIX = DEFINE_SYMBOL(
    matrix,
    0x25A1,                  // Unicode: □ (using white square as approximation)
    "\\begin{bmatrix} a & b \\\\ c & d \\end{bmatrix}", LATEX_1SPACE,
    "[\\matrix(@&)]", MOF_1SPACE_1BACKTRACK,
    "matrix{a # b ## c # d}", LOF_1SPACE
);
