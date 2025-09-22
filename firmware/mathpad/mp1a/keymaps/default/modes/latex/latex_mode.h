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

#include "../../symbols/symbols.h"


void send_symbol_latex(const symbol_definition_t* symbol);

// Function to send a string and move the caret 4 steps backwards
void send_and_backtrack_4(const char *string);

// Function to send a string and move the caret 3 steps backwards
void send_and_backtrack_3(const char *string);

// Function to send a string and move the caret 1 step backwards
void send_and_backtrack_1(const char *string);

// Function to send a string and 1 space
void send_ltx_1space(const char *string);

#endif /* LATEX_MODE_H */
