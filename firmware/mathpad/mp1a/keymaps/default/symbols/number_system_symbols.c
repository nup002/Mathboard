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
#include "number_system_symbols.h"

// Number system symbols
const symbol_definition_t SYMBOL_NATURALS = DEFINE_SYMBOL(
    naturals,
    0x2115,                  // Unicode: ℕ
    "\\mathbb{N}", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_INTEGERS = DEFINE_SYMBOL(
    integers,
    0x2124,                  // Unicode: ℤ
    "\\mathbb{Z}", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_RATIONALS = DEFINE_SYMBOL(
    rationals,
    0x211A,                  // Unicode: ℚ
    "\\mathbb{Q}", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_REALS = DEFINE_SYMBOL(
    reals,
    0x211D,                  // Unicode: ℝ
    "\\mathbb{R}", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_COMPLEXES = DEFINE_SYMBOL(
    complexes,
    0x2102,                  // Unicode: ℂ
    "\\mathbb{C}", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);
