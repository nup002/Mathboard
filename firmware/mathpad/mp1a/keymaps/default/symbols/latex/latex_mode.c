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

#include "symbols/latex/latex_mode.h"
#include QMK_KEYBOARD_H

// Function to send a symbol's LaTeX representation
void send_symbol_latex(const symbol_definition_t* symbol) {
    if (!symbol->latex_string) {
        return;  // No LaTeX representation available
    }
    
    switch (symbol->latex_method) {
        case LATEX_NORMAL:
            send_string(symbol->latex_string);
            break;
        case LATEX_BACKTRACK_1:
            send_and_backtrack_1(symbol->latex_string);
            break;
        case LATEX_BACKTRACK_3:
            send_and_backtrack_3(symbol->latex_string);
            break;
        case LATEX_BACKTRACK_4:
            send_and_backtrack_4(symbol->latex_string);
            break;
    }
}

/**
 * @brief Sends a string and moves the caret 4 steps backwards.
 *
 * This is commonly used when sending a LaTeX code that ends with '{}_{}', in order
 * to place the caret inside the first curly braces.
 *
 * @param string The string to send.
 */
void send_and_backtrack_4(const char *string) {
    send_string(string);
    for (int i = 0; i < 4; ++i) {
        tap_code(KC_LEFT);
    }
}

/**
 * @brief Sends a string and moves the caret 3 steps backwards.
 *
 * This is commonly used when sending a LaTeX code that ends with '{}{}', in order
 * to place the caret inside the first curly braces.
 *
 * @param string The string to send.
 */
void send_and_backtrack_3(const char *string) {
    send_string(string);
    for (int i = 0; i < 3; ++i) {
        tap_code(KC_LEFT);
    }
}

/**
 * @brief Sends a string and moves the caret 1 step backwards.
 *
 * This is commonly used when sending a LaTeX code that ends with '{}', in order
 * to place the caret inside the curly braces.
 *
 * @param string The string to send.
 */
void send_and_backtrack_1(const char *string) {
    send_string(string);
    tap_code(KC_LEFT);
}
