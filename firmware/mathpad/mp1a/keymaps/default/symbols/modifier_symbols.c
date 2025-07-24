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
const symbol_definition_t SYMBOL_ACCENT_CIRCUMFLEX = DEFINE_SYMBOL(
    circumflex,
    0x0302,                  // Unicode: ̂ (combining circumflex)
    "\\hat{}", LATEX_1BACKTRACK,
    "\\hat", MOF_2SPACE,
    "hat{}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_ACCENT_CHECK = DEFINE_SYMBOL(
    check,
    0x030C,                  // Unicode: ̌ (combining caron)
    "\\check{}", LATEX_1BACKTRACK,
    "\\check", MOF_2SPACE,
    "check{}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_ACCENT_TILDE = DEFINE_SYMBOL(
    combining_tilde,
    0x0303,                  // Unicode: ̃ (combining tilde)
    "\\tilde{}", LATEX_1BACKTRACK,
    "\\tilde", MOF_2SPACE,
    "tilde{}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_ACCENT_BAR = DEFINE_SYMBOL(
    bar,
    0x0304,                  // Unicode: ̄ (combining macron)
    "\\bar{}", LATEX_1BACKTRACK,
    "\\bar", MOF_2SPACE,
    "bar{}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_ACCENT_ARROW = DEFINE_SYMBOL(
    arrow,
    0x20D7,                  // Unicode: ⃗ (combining right arrow above)
    "\\vec{}", LATEX_1BACKTRACK,
    "\\vec", MOF_2SPACE,
    "vec{}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_ACCENT_DOT = DEFINE_SYMBOL(
    dot,
    0x0307,                  // Unicode: ̇ (combining dot above)
    "\\dot{}", LATEX_1BACKTRACK,
    "\\dot", MOF_2SPACE,
    "dot{}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_ACCENT_DOUBLE_DOT = DEFINE_SYMBOL(
    double_dot,
    0x0308,                  // Unicode: ̈ (combining diaeresis)
    "\\ddot{}", LATEX_1BACKTRACK,
    "\\ddot", MOF_2SPACE,
    "ddot{}", LOF_1BACKTRACK
);

const symbol_definition_t SYMBOL_ACCENT_TRIPLE_DOT = DEFINE_SYMBOL(
    triple_dot,
    0x20DB,                  // Unicode: ⃛ (combining three dots above)
    "\\dddot{}", LATEX_1BACKTRACK,
    "\\dddot", MOF_2SPACE,
    "dddot{}", LOF_1BACKTRACK
);