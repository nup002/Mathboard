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
#include "set_theory_symbols.h"

// Set theory symbols
const symbol_definition_t SYMBOL_UNION = DEFINE_SYMBOL(
    union_symbol,
    0x222A,                  // Unicode: ∪
    "\\cup", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_INTERSECTION = DEFINE_SYMBOL(
    intersection,
    0x2229,                  // Unicode: ∩
    "\\cap", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_ELEMENT_OF = DEFINE_SYMBOL(
    element_of,
    0x2208,                  // Unicode: ∈
    "\\in", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_NOT_ELEMENT_OF = DEFINE_SYMBOL(
    not_element_of,
    0x2209,                  // Unicode: ∉
    "\\notin", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_CONTAINS_AS_MEMBER = DEFINE_SYMBOL(
    contains_as_member,
    0x220B,                  // Unicode: ∋
    "\\ni", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_EMPTY_SET = DEFINE_SYMBOL(
    empty_set,
    0x2205,                  // Unicode: ∅
    "\\emptyset", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_POWER_SET = DEFINE_SYMBOL(
    power_set,
    0x2118,                  // Unicode: ℘
    "\\wp", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_PROPER_SUBSET = DEFINE_SYMBOL(
    proper_subset,
    0x2282,                  // Unicode: ⊂
    "\\subset", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_NOT_PROPER_SUBSET = DEFINE_SYMBOL(
    not_proper_subset,
    0x2284,                  // Unicode: ⊄
    "\\not\\subset", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_SET_DIFFERENCE = DEFINE_SYMBOL(
    set_difference,
    0x2216,                  // Unicode: ∖
    "\\setminus", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_SUBSET = DEFINE_SYMBOL(
    subset,
    0x2286,                  // Unicode: ⊆
    "\\subseteq", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_NOT_SUBSET = DEFINE_SYMBOL(
    not_subset,
    0x2288,                  // Unicode: ⊈
    "\\not\\subseteq", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_DISJOINT_UNION = DEFINE_SYMBOL(
    disjoint_union,
    0x2A06,                  // Unicode: ⨆
    "\\bigsqcup", LATEX_NORMAL,
    NULL, MOF_1SPACE
);

const symbol_definition_t SYMBOL_DIRECT_SUM = DEFINE_SYMBOL(
    direct_sum,
    0x2295,                  // Unicode: ⊕
    "\\oplus", LATEX_NORMAL,
    NULL, MOF_1SPACE
);
