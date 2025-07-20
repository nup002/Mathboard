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
#include "comparison_symbols.h"

// Comparison and equivalence symbols
const symbol_definition_t SYMBOL_NOT_EQUAL = DEFINE_SYMBOL(
    not_equal,
    0x2260,                  // Unicode: ≠
    "\\neq", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE   // Use Unicode for MOF
);

const symbol_definition_t SYMBOL_LESS_THAN_OR_EQUAL = DEFINE_SYMBOL(
    less_than_or_equal,
    0x2264,                  // Unicode: ≤
    "\\leq", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_GREATER_THAN_OR_EQUAL = DEFINE_SYMBOL(
    greater_than_or_equal,
    0x2265,                  // Unicode: ≥
    "\\geq", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_IDENTICAL = DEFINE_SYMBOL(
    identical,
    0x2261,                  // Unicode: ≡
    "\\equiv", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_NOT_IDENTICAL = DEFINE_SYMBOL(
    not_identical,
    0x2262,                  // Unicode: ≢
    "\\not\\equiv", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_APPROXIMATELY_EQUAL = DEFINE_SYMBOL(
    approximately_equal,
    0x2248,                  // Unicode: ≈
    "\\approx", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_ASYMPTOTICALLY_EQUAL = DEFINE_SYMBOL(
    asymptotically_equal,
    0x2243,                  // Unicode: ≃
    "\\simeq", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_PROPORTIONAL_TO = DEFINE_SYMBOL(
    proportional_to,
    0x221D,                  // Unicode: ∝
    "\\propto", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_MUCH_GREATER_THAN = DEFINE_SYMBOL(
    much_greater_than,
    0x226B,                  // Unicode: ≫
    "\\gg", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_MUCH_LESS_THAN = DEFINE_SYMBOL(
    much_less_than,
    0x226A,                  // Unicode: ≪
    "\\ll", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_COLON_EQUALS = DEFINE_SYMBOL(
    colon_equals,
    0x2254,                  // Unicode: ≔
    "\\coloneq", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_EQUAL_BY_DEFINITION = DEFINE_SYMBOL(
    equal_by_definition,
    0x225D,                  // Unicode: ≝
    "\\overset{\\underset{\\mathrm{def}}{}}{=}", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);
