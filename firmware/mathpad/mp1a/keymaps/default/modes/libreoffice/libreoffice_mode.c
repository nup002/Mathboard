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
        case LOF_1SPACE:
            send_lof_1space(symbol->lof_string);
            break;
        case LOF_1BACKTRACK:
            send_lof_1backtrack(symbol->lof_string);
            break;
        case LOF_6BACKTRACK:
            send_lof_6backtrack(symbol->lof_string);
            break;
    }
}

/**
 * @brief Sends 'string' and one space.
 *
 * Used for most LibreOffice symbols. 
 *
 * @param string a pointer to the string to be sent
 */
void send_lof_1space(const char *string) {
    send_string(string);
    tap_code(KC_SPACE);
}

/**
 * @brief Sends string and moves the cursor 1 step backwards.
 *
 * This is commonly used when sending a LibreOffice code that ends with '{}', in order
 * to place the cursor inside the curly braces.
 *
 * @param string The string to send.
 */
void send_lof_1backtrack(const char *string) {
    send_string(string);
    tap_code(KC_LEFT);
}

/**
 * @brief Sends string and moves the cursor 6 steps backwards.
 *
 * This is commonly used when sending a LibreOffice code that ends with 'from{} to{}', in order
 * to place the cursor inside the first limit (the {} after 'from').
 *
 * @param string The string to send.
 */
void send_lof_6backtrack(const char *string) {
    send_string(string);
    for (int i = 0; i < 6; ++i) {
        tap_code(KC_LEFT);
    }
}
