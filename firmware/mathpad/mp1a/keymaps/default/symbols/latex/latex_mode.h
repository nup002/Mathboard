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

#ifndef LATEX_MODE_H
#define LATEX_MODE_H

#include QMK_KEYBOARD_H

// Define the different sending methods for LaTeX
typedef enum {
    LATEX_NORMAL,         // Just send the string as is
    LATEX_BACKTRACK_1,    // Send string and move cursor back 1 position
    LATEX_BACKTRACK_3,    // Send string and move cursor back 3 positions
    LATEX_BACKTRACK_4     // Send string and move cursor back 4 positions
} latex_send_method_t;

// LaTeX string constants are defined in latex_strings.h
#include "symbols/latex/latex_strings.h"

void send_symbol_latex(const symbol_definition_t* symbol);

// Function to send a string and move the caret 4 steps backwards
void send_and_backtrack_4(const char *string);

// Function to send a string and move the caret 3 steps backwards
void send_and_backtrack_3(const char *string);

// Function to send a string and move the caret 1 step backwards
void send_and_backtrack_1(const char *string);

#endif /* LATEX_MODE_H */
