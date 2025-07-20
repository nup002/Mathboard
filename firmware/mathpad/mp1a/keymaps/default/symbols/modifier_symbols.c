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
#include "modifier_symbols.h"

// Modifiers
const symbol_definition_t SYMBOL_CIRCUMFLEX = DEFINE_SYMBOL(
    circumflex,
    0x0302,                  // Unicode: ̂ (combining circumflex)
    "\\hat{}", LATEX_BACKTRACK_1,
    "\\hat", MOF_AS_IS_2SPACE
);

const symbol_definition_t SYMBOL_CHECK = DEFINE_SYMBOL(
    check,
    0x030C,                  // Unicode: ̌ (combining caron)
    "\\check{}", LATEX_BACKTRACK_1,
    "\\check", MOF_AS_IS_2SPACE
);

const symbol_definition_t SYMBOL_COMBINING_TILDE = DEFINE_SYMBOL(
    combining_tilde,
    0x0303,                  // Unicode: ̃ (combining tilde)
    "\\tilde{}", LATEX_BACKTRACK_1,
    "\\tilde", MOF_AS_IS_2SPACE
);

const symbol_definition_t SYMBOL_BAR = DEFINE_SYMBOL(
    bar,
    0x0304,                  // Unicode: ̄ (combining macron)
    "\\bar{}", LATEX_BACKTRACK_1,
    "\\bar", MOF_AS_IS_2SPACE
);

const symbol_definition_t SYMBOL_ARROW = DEFINE_SYMBOL(
    arrow,
    0x20D7,                  // Unicode: ⃗ (combining right arrow above)
    "\\vec{}", LATEX_BACKTRACK_1,
    "\\vec", MOF_AS_IS_2SPACE
);

const symbol_definition_t SYMBOL_DOT = DEFINE_SYMBOL(
    dot,
    0x0307,                  // Unicode: ̇ (combining dot above)
    "\\dot{}", LATEX_BACKTRACK_1,
    "\\dot", MOF_AS_IS_2SPACE
);

const symbol_definition_t SYMBOL_DOUBLE_DOT = DEFINE_SYMBOL(
    double_dot,
    0x0308,                  // Unicode: ̈ (combining diaeresis)
    "\\ddot{}", LATEX_BACKTRACK_1,
    "\\ddot", MOF_AS_IS_2SPACE
);

const symbol_definition_t SYMBOL_TRIPLE_DOT = DEFINE_SYMBOL(
    triple_dot,
    0x20DB,                  // Unicode: ⃛ (combining three dots above)
    "\\dddot{}", LATEX_BACKTRACK_1,
    "\\dddot", MOF_AS_IS_2SPACE
);

const symbol_definition_t SYMBOL_PRIME = DEFINE_SYMBOL(
    prime,
    0x2032,                  // Unicode: ′
    "'", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_DOUBLE_PRIME = DEFINE_SYMBOL(
    double_prime,
    0x2033,                  // Unicode: ″
    "''", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_TRIPLE_PRIME = DEFINE_SYMBOL(
    triple_prime,
    0x2034,                  // Unicode: ‴
    "'''", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_TRANSPOSE = DEFINE_SYMBOL(
    transpose,
    0x1D40,                  // Unicode: ᵀ (modifier letter capital T)
    "^{\\mathsf{T}}", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);
