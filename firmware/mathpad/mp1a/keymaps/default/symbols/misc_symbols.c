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
#include "misc_symbols.h"

// Other mathematical and scientific symbols
const symbol_definition_t SYMBOL_DOTPRODUCT = DEFINE_SYMBOL(
    dotproduct,
    0x22C5,                  // Unicode: ⋅
    "\\cdot", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_TIMES = DEFINE_SYMBOL(
    times,
    0x00D7,                  // Unicode: ×
    "\\times", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_DIVISION = DEFINE_SYMBOL(
    division,
    0x00F7,                  // Unicode: ÷
    "\\div", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_PLUSMINUS = DEFINE_SYMBOL(
    plusminus,
    0x00B1,                  // Unicode: ±
    "\\pm", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_MINUSPLUS = DEFINE_SYMBOL(
    minusplus,
    0x2213,                  // Unicode: ∓
    "\\mp", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_PARALLEL = DEFINE_SYMBOL(
    parallel,
    0x2225,                  // Unicode: ∥
    "\\parallel", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_DEGREE = DEFINE_SYMBOL(
    degree,
    0x00B0,                  // Unicode: °
    "\\degree", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_INFINITY = DEFINE_SYMBOL(
    infinity,
    0x221E,                  // Unicode: ∞
    "\\infty", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_CIRCLED_TIMES = DEFINE_SYMBOL(
    circled_times,
    0x2297,                  // Unicode: ⊗
    "\\otimes", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

// Arrows
const symbol_definition_t SYMBOL_RIGHTARROW = DEFINE_SYMBOL(
    rightarrow,
    0x2192,                  // Unicode: →
    "\\rightarrow", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_LEFTARROW = DEFINE_SYMBOL(
    leftarrow,
    0x2190,                  // Unicode: ←
    "\\leftarrow", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_LEFTRIGHTARROW = DEFINE_SYMBOL(
    leftrightarrow,
    0x2194,                  // Unicode: ↔
    "\\leftrightarrow", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_MAPSTO = DEFINE_SYMBOL(
    mapsto,
    0x21A6,                  // Unicode: ↦
    "\\mapsto", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_LONGMAPSTO = DEFINE_SYMBOL(
    longmapsto,
    0x27FC,                  // Unicode: ⟼
    "\\longmapsto", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_LONGRIGHTARROW = DEFINE_SYMBOL(
    longrightarrow,
    0x27F6,                  // Unicode: ⟶
    "\\longrightarrow", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_LONGLEFTARROW = DEFINE_SYMBOL(
    longleftarrow,
    0x27F5,                  // Unicode: ⟵
    "\\longleftarrow", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

const symbol_definition_t SYMBOL_LONGLEFTRIGHTARROW = DEFINE_SYMBOL(
    longleftrightarrow,
    0x27F7,                  // Unicode: ⟷
    "\\longleftrightarrow", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);
