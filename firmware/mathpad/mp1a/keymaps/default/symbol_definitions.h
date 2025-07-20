/* Copyright 2025 Summacogni OU
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SYMBOL_DEFINITIONS_H
#define SYMBOL_DEFINITIONS_H

#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stdint.h>

// Define the different sending methods for LaTeX
typedef enum {
    LATEX_NORMAL,         // Just send the string as is
    LATEX_BACKTRACK_1,    // Send string and move cursor back 1 position
    LATEX_BACKTRACK_3,    // Send string and move cursor back 3 positions
    LATEX_BACKTRACK_4     // Send string and move cursor back 4 positions
} latex_send_method_t;

// Define the different sending methods for Microsoft Office
typedef enum {
    MOF_AS_IS_1SPACE,
    MOF_AS_IS_2SPACE,
    MOF_MOVE_LEFT_1SPACE,
    MOF_MOVE_LEFT_2SPACE,
    MOF_SPACE_DELETE_PLACEHOLDER_LIMITS
} mof_send_method_t;

// Define the unified symbol structure
typedef struct {
    // Symbol metadata
    const char* name;           // Human-readable name of the symbol
    
    // Unicode representation
    uint32_t unicode_value;     // Unicode code point
    
    // LaTeX representation
    const char* latex_string;   // LaTeX string representation
    latex_send_method_t latex_method; // How to send the LaTeX string
    
    // Microsoft Office representation
    const char* mof_string;     // Microsoft Office string representation
    mof_send_method_t mof_method; // How to send the MOF string
} symbol_definition_t;


// Macro to define a symbol with all representations
#define DEFINE_SYMBOL(symbol_name, \
                     unicode_val, \
                     latex_str, latex_meth, \
                     mof_str, mof_meth) \
    { \
        .name = #symbol_name, \
        .unicode_value = unicode_val, \
        .latex_string = latex_str, \
        .latex_method = latex_meth, \
        .mof_string = mof_str, \
        .mof_method = mof_meth \
    }

#endif /* SYMBOL_DEFINITIONS_H */
