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
#include "algebra_symbols.h"

// Algebra and calculus symbols
const symbol_definition_t SYMBOL_SUM = DEFINE_SYMBOL(
    sum,
    0x2211,                  // Unicode: ∑
    "\\sum_{}{}", LATEX_BACKTRACK_3,
    "\\sum_a^b", MOF_SPACE_DELETE_PLACEHOLDER_LIMITS
);

const symbol_definition_t SYMBOL_N_ARY_PRODUCT = DEFINE_SYMBOL(
    n_ary_product,
    0x220F,                  // Unicode: ∏
    "\\prod_{}{}", LATEX_BACKTRACK_3,
    "\\prod_a^b", MOF_SPACE_DELETE_PLACEHOLDER_LIMITS
);

const symbol_definition_t SYMBOL_INTEGRAL = DEFINE_SYMBOL(
    integral,
    0x222B,                  // Unicode: ∫
    "\\int_{}{}", LATEX_BACKTRACK_3,
    "\\int_a^b", MOF_SPACE_DELETE_PLACEHOLDER_LIMITS
);

const symbol_definition_t SYMBOL_DOUBLE_INTEGRAL = DEFINE_SYMBOL(
    double_integral,
    0x222C,                  // Unicode: ∬
    "\\iint_{}{}", LATEX_BACKTRACK_3,
    "\\iint_a^b", MOF_SPACE_DELETE_PLACEHOLDER_LIMITS
);

const symbol_definition_t SYMBOL_TRIPLE_INTEGRAL = DEFINE_SYMBOL(
    triple_integral,
    0x222D,                  // Unicode: ∭
    "\\iiint_{}{}", LATEX_BACKTRACK_3,
    "\\iiint_a^b", MOF_SPACE_DELETE_PLACEHOLDER_LIMITS
);

const symbol_definition_t SYMBOL_LINE_INTEGRAL = DEFINE_SYMBOL(
    line_integral,
    0x222E,                  // Unicode: ∮
    "\\oint_{}{}", LATEX_BACKTRACK_3,
    "\\oint_a^b", MOF_SPACE_DELETE_PLACEHOLDER_LIMITS
);

const symbol_definition_t SYMBOL_SURFACE_INTEGRAL = DEFINE_SYMBOL(
    surface_integral,
    0x222F,                  // Unicode: ∯
    "\\oiint_{}{}", LATEX_BACKTRACK_3,
    "\\oiint_a^b", MOF_SPACE_DELETE_PLACEHOLDER_LIMITS
);

const symbol_definition_t SYMBOL_VOLUME_INTEGRAL = DEFINE_SYMBOL(
    volume_integral,
    0x2230,                  // Unicode: ∰
    "\\oiiint_{}{}", LATEX_BACKTRACK_3,
    "\\oiiint_a^b", MOF_SPACE_DELETE_PLACEHOLDER_LIMITS
);

const symbol_definition_t SYMBOL_SQUARE_ROOT = DEFINE_SYMBOL(
    square_root,
    0x221A,                  // Unicode: √
    "\\sqrt{}", LATEX_BACKTRACK_1,
    "\\sqrt", MOF_MOVE_LEFT_2SPACE
);

const symbol_definition_t SYMBOL_CUBE_ROOT = DEFINE_SYMBOL(
    cube_root,
    0x221B,                  // Unicode: ∛
    "\\sqrt[3]{}", LATEX_BACKTRACK_1,
    "\\cbrt", MOF_MOVE_LEFT_2SPACE
);

const symbol_definition_t SYMBOL_FOURTH_ROOT = DEFINE_SYMBOL(
    fourth_root,
    0x221C,                  // Unicode: ∜
    "\\sqrt[4]{}", LATEX_BACKTRACK_1,
    "\\qdrt", MOF_MOVE_LEFT_2SPACE
);

const symbol_definition_t SYMBOL_PARTIAL_DIFFERENTIAL = DEFINE_SYMBOL(
    partial_differential,
    0x2202,                  // Unicode: ∂
    "\\partial", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_NABLA = DEFINE_SYMBOL(
    nabla,
    0x2207,                  // Unicode: ∇
    "\\nabla", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_FRAC = DEFINE_SYMBOL(
    frac,
    0x2044,                  // Unicode: ⁄ (fraction slash)
    "\\frac{}{}", LATEX_BACKTRACK_1,
    " a/b", MOF_SPACE_DELETE_PLACEHOLDER_LIMITS
);

const symbol_definition_t SYMBOL_MATRIX = DEFINE_SYMBOL(
    matrix,
    0x25A1,                  // Unicode: □ (using white square as approximation)
    "\\begin{bmatrix} a & b \\\\ c & d \\end{bmatrix}", LATEX_NORMAL,
    "[\\matrix(@&)]", MOF_MOVE_LEFT_1SPACE
);
