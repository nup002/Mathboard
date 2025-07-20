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
#include "logic_symbols.h"

// Logic symbols
const symbol_definition_t SYMBOL_THERE_EXISTS = DEFINE_SYMBOL(
    there_exists,
    0x2203,                  // Unicode: ∃
    "\\exists", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_THERE_DOES_NOT_EXIST = DEFINE_SYMBOL(
    there_does_not_exists,
    0x2204,                  // Unicode: ∄
    "\\nexists", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_AND = DEFINE_SYMBOL(
    and,
    0x2227,                  // Unicode: ∧
    "\\wedge", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_OR = DEFINE_SYMBOL(
    or,
    0x2228,                  // Unicode: ∨
    "\\vee", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_XOR = DEFINE_SYMBOL(
    xor,
    0x22BB,                  // Unicode: ⊻
    "\\veebar", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_FOR_ALL = DEFINE_SYMBOL(
    for_all,
    0x2200,                  // Unicode: ∀
    "\\forall", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_NOT = DEFINE_SYMBOL(
    not,
    0x00AC,                  // Unicode: ¬
    "\\neg", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_PROVES = DEFINE_SYMBOL(
    proves,
    0x22A2,                  // Unicode: ⊢
    "\\vdash", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_MODELS = DEFINE_SYMBOL(
    models,
    0x22A8,                  // Unicode: ⊨
    "\\models", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_DOWN_TACK = DEFINE_SYMBOL(
    down_tack,
    0x22A4,                  // Unicode: ⊤
    "\\top", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_UP_TACK = DEFINE_SYMBOL(
    up_tack,
    0x22A5,                  // Unicode: ⊥
    "\\bot", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);
