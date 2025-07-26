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

#ifndef SYMBOLS_H
#define SYMBOLS_H
#include <stdint.h>
#include QMK_KEYBOARD_H

// Define the different sending methods for LaTeX
typedef enum {
    LATEX_NORMAL,         // Just send the string as is
    LATEX_1BACKTRACK,    // Send string and move cursor back 1 position
    LATEX_3BACKTRACK,    // Send string and move cursor back 3 positions
    LATEX_4BACKTRACK     // Send string and move cursor back 4 positions
} latex_send_method_t;


// Define the different sending methods for Microsoft Office
typedef enum {
    MOF_1SPACE,             // Send string and send 1 space
    MOF_2SPACE,             // Send string and send 2 spaces
    MOF_1SPACE_1BACKTRACK,  // Send string, 1 space, and move cursor back 1 position
    MOF_2SPACE_1BACKTRACK,  // Send string, 2 spaces, and move cursor back 1 position
    MOF_1SPACE_DELETE_LIMS  // Send string with placeholder limits (_a^b) and delete the limits
} mof_send_method_t;

// Define the different sending methods for LibreOffice Equation Editor
typedef enum {
    LOF_NORMAL,             // Just send the string as is with one preceding space
    LOF_1SPACE,             // Send string and send 1 space
    LOF_2SPACE,             // Send string and send 2 spaces
    LOF_1BACKTRACK,         // Send string and move cursor back 1 position
    LOF_2BACKTRACK,         // Send string and move cursor back 2 positions
    LOF_3BACKTRACK,         // Send string and move cursor back 3 positions
    LOF_6BACKTRACK,         // Send string and move cursor back 7 positions
    LOF_1SPACE_1BACKTRACK,  // Send string, 1 space, and move cursor back 1 position
    LOF_2SPACE_1BACKTRACK   // Send string, 2 spaces, and move cursor back 1 position
} lof_send_method_t;

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
    
    // LibreOffice representation
    const char* lof_string;     // LibreOffice string representation
    lof_send_method_t lof_method; // How to send the LOF string
} symbol_definition_t;

// Macro to define a symbol with all representations
#define DEFINE_SYMBOL(symbol_name, \
                     unicode_val, \
                     latex_str, latex_meth, \
                     mof_str, mof_meth, \
                     lof_str, lof_meth) \
    { \
        .name = #symbol_name, \
        .unicode_value = unicode_val, \
        .latex_string = latex_str, \
        .latex_method = latex_meth, \
        .mof_string = mof_str, \
        .mof_method = mof_meth, \
        .lof_string = lof_str, \
        .lof_method = lof_meth \
    }

// Function to send a symbol based on the current mode
void send_symbol(const symbol_definition_t* symbol);

// Function to send a symbol only if the key is pressed
void send_symbol_on_keypress(const symbol_definition_t* symbol, keyrecord_t* record);

#endif /* SYMBOLS_H */
