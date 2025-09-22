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
#include "misc_symbols.h"

// Other mathematical and scientific symbols
const symbol_definition_t SYMBOL_ACCENT_DOTPRODUCT = DEFINE_SYMBOL(
    dotproduct,
    0x22C5,                  // Unicode: ⋅
    "\\cdot", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "cdot", LOF_1SPACE
);

const symbol_definition_t SYMBOL_TIMES = DEFINE_SYMBOL(
    times,
    0x00D7,                  // Unicode: ×
    "\\times", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "times", LOF_1SPACE
);

const symbol_definition_t SYMBOL_DIVISION = DEFINE_SYMBOL(
    division,
    0x00F7,                  // Unicode: ÷
    "\\div", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "div", LOF_1SPACE
);

const symbol_definition_t SYMBOL_PLUSMINUS = DEFINE_SYMBOL(
    plusminus,
    0x00B1,                  // Unicode: ±
    "\\pm", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "plusminus", LOF_1SPACE
);

const symbol_definition_t SYMBOL_MINUSPLUS = DEFINE_SYMBOL(
    minusplus,
    0x2213,                  // Unicode: ∓
    "\\mp", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "minusplus", LOF_1SPACE
);

const symbol_definition_t SYMBOL_DEGREE = DEFINE_SYMBOL(
    degree,
    0x00B0,                  // Unicode: °
    "\\degree", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    NULL, LOF_1SPACE
);

const symbol_definition_t SYMBOL_INFINITY = DEFINE_SYMBOL(
    infinity,
    0x221E,                  // Unicode: ∞
    "\\infty", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    NULL, LOF_1SPACE
);

const symbol_definition_t SYMBOL_CIRCLED_TIMES = DEFINE_SYMBOL(
    circled_times,
    0x2297,                  // Unicode: ⊗
    "\\otimes", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "otimes", LOF_1SPACE
);

// Arrows
const symbol_definition_t SYMBOL_RIGHTARROW = DEFINE_SYMBOL(
    rightarrow,
    0x2192,                  // Unicode: →
    "\\rightarrow", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    NULL, LOF_1SPACE
);

const symbol_definition_t SYMBOL_LEFTARROW = DEFINE_SYMBOL(
    leftarrow,
    0x2190,                  // Unicode: ←
    "\\leftarrow", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    NULL, LOF_1SPACE
);

const symbol_definition_t SYMBOL_LEFTRIGHTARROW = DEFINE_SYMBOL(
    leftrightarrow,
    0x2194,                  // Unicode: ↔
    "\\leftrightarrow", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    NULL, LOF_1SPACE
);

const symbol_definition_t SYMBOL_DOUBLERIGHTARROW = DEFINE_SYMBOL(
    doublerightarrow,
    0x21D2,                  // Unicode: ⇒
    "\\Rightarrow", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "drarrow", LOF_1SPACE
);

const symbol_definition_t SYMBOL_DOUBLELEFTARROW = DEFINE_SYMBOL(
    doubleleftarrow,
    0x21D0,                  // Unicode: ⇐
    "\\Leftarrow", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "dlarrow", LOF_1SPACE
);

const symbol_definition_t SYMBOL_DOUBLERIGHTLEFTARROW = DEFINE_SYMBOL(
    doubleleftrightarrow,
    0x21D4,                  // Unicode: ⇔
    "\\Leftrightarrow", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "dlrarrow", LOF_1SPACE
);

// Subscript symbols
const symbol_definition_t SYMBOL_SUB_0 = DEFINE_SYMBOL(
    sub_0,
    0x2080,                  // Unicode: ₀
    "_0", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "_0", LOF_1SPACE
);

const symbol_definition_t SYMBOL_SUB_1 = DEFINE_SYMBOL(
    sub_1,
    0x2081,                  // Unicode: ₁
    "_1", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "_1", LOF_1SPACE
);

const symbol_definition_t SYMBOL_SUB_2 = DEFINE_SYMBOL(
    sub_2,
    0x2082,                  // Unicode: ₂
    "_2", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "_2", LOF_1SPACE
);

const symbol_definition_t SYMBOL_SUB_I = DEFINE_SYMBOL(
    sub_i,
    0x1D62,                  // Unicode: ᵢ
    "_i", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "_i", LOF_1SPACE
);

const symbol_definition_t SYMBOL_SUB_J = DEFINE_SYMBOL(
    sub_j,
    0x2C7C,                  // Unicode: ⱼ
    "_j", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "_j", LOF_1SPACE
);

const symbol_definition_t SYMBOL_SUB_N = DEFINE_SYMBOL(
    sub_n,
    0x2099,                  // Unicode: ₙ
    "_n", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "_n", LOF_1SPACE
);

// Superscript symbols
const symbol_definition_t SYMBOL_SUP_0 = DEFINE_SYMBOL(
    sup_0,
    0x2070,                  // Unicode: ⁰
    "^0", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "^0", LOF_1SPACE
);

const symbol_definition_t SYMBOL_SUP_1 = DEFINE_SYMBOL(
    sup_1,
    0x00B9,                  // Unicode: ¹
    "^1", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "^1", LOF_1SPACE
);

const symbol_definition_t SYMBOL_SUP_2 = DEFINE_SYMBOL(
    sup_2,
    0x00B2,                  // Unicode: ²
    "^2", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "^2", LOF_1SPACE
);

const symbol_definition_t SYMBOL_SUP_I = DEFINE_SYMBOL(
    sup_i,
    0x2071,                  // Unicode: ⁱ
    "^i", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "^i", LOF_1SPACE
);

const symbol_definition_t SYMBOL_SUP_J = DEFINE_SYMBOL(
    sup_j,
    0x02B2,                  // Unicode: ʲ
    "^j", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "^j", LOF_1SPACE
);

const symbol_definition_t SYMBOL_SUP_N = DEFINE_SYMBOL(
    sup_n,
    0x207F,                  // Unicode: ⁿ
    "^n", LATEX_1SPACE,
    NULL, MOF_1SPACE,
    "^n", LOF_1SPACE
);
