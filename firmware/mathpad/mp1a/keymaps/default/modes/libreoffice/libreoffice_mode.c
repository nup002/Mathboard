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

#include "libreoffice_mode.h"
#include "../unicode/unicode_mode.h"


// Function to send a symbol's LibreOffice representation
void send_symbol_lof(const symbol_definition_t* symbol) {
    if (!symbol->lof_string && symbol->unicode_value != 0) {
        // If no specific LOF string is defined but we have a Unicode value,
        // fall back to sending the Unicode character
        send_symbol_unicode(symbol);
        return;
    }
    
    if (!symbol->lof_string) {
        return;  // No LOF representation available
    }
    
    // Call the appropriate LOF sending function based on the lof_method
    switch (symbol->lof_method) {
        case LOF_NORMAL:
            send_lof_normal(symbol->lof_string);
            break;
        case LOF_1SPACE:
            send_lof_1space(symbol->lof_string);
            break;
        case LOF_2SPACE:
            send_lof_2space(symbol->lof_string);
            break;
        case LOF_1BACKTRACK:
            send_lof_1backtrack(symbol->lof_string);
            break;
        case LOF_2BACKTRACK:
            send_lof_2backtrack(symbol->lof_string);
            break;
        case LOF_3BACKTRACK:
            send_lof_3backtrack(symbol->lof_string);
            break;
        case LOF_6BACKTRACK:
            send_lof_7backtrack(symbol->lof_string);
            break;
        case LOF_1SPACE_1BACKTRACK:
            send_lof_1space_1backtrack(symbol->lof_string);
            break;
        case LOF_2SPACE_1BACKTRACK:
            send_lof_2space_1backtrack(symbol->lof_string);
            break;
        default:
            // Default to sending as is
            send_lof_normal(symbol->lof_string);
            break;
    }
}

/**
 * @brief Sends one space character
 */
void send_space(void) {
    tap_code(KC_SPACE);
}

/**
 * @brief Sends two space characters
 */
void send_2x_space(void) {
    tap_code(KC_SPACE);
    tap_code(KC_SPACE);
}

/**
 * @brief Sends string as is without any modifications.
 *
 * Used for LibreOffice symbols that don't require special handling.
 *
 * @param string a pointer to the string to be sent
 */
void send_lof_normal(const char *string) {
    send_string(string);
}

/**
 * @brief Sends 'string' and one space.
 *
 * Typically used for typing symbols that require an extra space to appear correctly
 * in LibreOffice Equation Editor, such as subscripts and superscripts.
 *
 * @param string a pointer to the string to be sent
 */
void send_lof_1space(const char *string) {
    send_string(string);
    send_space();
}

/**
 * @brief Sends 'string' and two spaces.
 *
 * Typically used for typing symbols that require two extra spaces to appear
 * correctly in LibreOffice Equation Editor, such as combining symbols like hat, overbar, tilde, etc.
 *
 * @param string a pointer to the string to be sent
 */
void send_lof_2space(const char *string) {
    send_string(string);
    send_2x_space();
}

/**
 * @brief Sends string and moves the caret 1 step backwards.
 *
 * This is commonly used when sending a LibreOffice code that ends with '{}', in order
 * to place the caret inside the curly braces.
 *
 * @param string The string to send.
 */
void send_lof_1backtrack(const char *string) {
    send_string(string);
    tap_code(KC_LEFT);
}

/**
 * @brief Sends string and moves the caret 2 steps backwards.
 *
 * This is commonly used when sending a LibreOffice code that ends with '()' or similar
 * two-character constructs, in order to place the caret inside them.
 *
 * @param string The string to send.
 */
void send_lof_2backtrack(const char *string) {
    send_string(string);
    for (int i = 0; i < 2; ++i) {
        tap_code(KC_LEFT);
    }
}

/**
 * @brief Sends string and moves the caret 3 steps backwards.
 *
 * This is commonly used when sending a LibreOffice code that ends with '{}{}', in order
 * to place the caret inside the first curly braces.
 *
 * @param string The string to send.
 */
void send_lof_3backtrack(const char *string) {
    send_string(string);
    for (int i = 0; i < 3; ++i) {
        tap_code(KC_LEFT);
    }
}

/**
 * @brief Sends string and moves the caret 6 steps backwards.
 *
 * This is commonly used when sending a LibreOffice code that ends with 'from{} to{}', in order
 * to place the caret inside the first limit (the {} after 'from').
 *
 * @param string The string to send.
 */
void send_lof_6backtrack(const char *string) {
    send_string(string);
    for (int i = 0; i < 6; ++i) {
        tap_code(KC_LEFT);
    }
}

/**
 * @brief Sends 'string' and one space and moves the caret left once.
 *
 * Typically used for typing symbols that require one extra space to appear correctly
 * and where the caret should be within the symbol's boundaries after typing.
 *
 * @param string a pointer to the string to be sent
 */
void send_lof_1space_1backtrack(const char *string) {
    send_string(string);
    send_space();
    tap_code(KC_LEFT);
}

/**
 * @brief Sends 'string' and two spaces and moves the caret left once.
 *
 * Typically used for typing symbols that require two extra spaces to appear correctly
 * and where the caret should be within the symbol's boundaries after typing. Examples
 * include square root, cube root, and quadratic root.
 *
 * @param string a pointer to the string to be sent
 */
void send_lof_2space_1backtrack(const char *string) {
    send_string(string);
    send_2x_space();
    tap_code(KC_LEFT);
}
