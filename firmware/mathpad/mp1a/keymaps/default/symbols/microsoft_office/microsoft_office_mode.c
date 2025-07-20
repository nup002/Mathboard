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

#include "microsoft_office_mode.h"
#include "../unicode/unicode_mode.h"


// Function to send a symbol's Microsoft Office representation
void send_symbol_mof(const symbol_definition_t* symbol) {
    if (!symbol->mof_string && symbol->unicode_value != 0) {
        // If no specific MOF string is defined but we have a Unicode value,
        // fall back to sending the Unicode character
        send_symbol_unicode(symbol);
        return;
    }
    
    if (!symbol->mof_string) {
        return;  // No MOF representation available
    }
    
    // Call the appropriate MOF sending function directly based on the mof_method
    switch (symbol->mof_method) {
        case MOF_AS_IS_1SPACE:
            send_as_is_1space(symbol->mof_string);
            break;
        case MOF_AS_IS_2SPACE:
            send_as_is_2space(symbol->mof_string);
            break;
        case MOF_MOVE_LEFT_1SPACE:
            send_with_left_move_1space(symbol->mof_string);
            break;
        case MOF_MOVE_LEFT_2SPACE:
            send_with_left_move_2space(symbol->mof_string);
            break;
        case MOF_SPACE_DELETE_PLACEHOLDER_LIMITS:
            send_with_delete_lims_1space(symbol->mof_string);
            break;
        default:
            // Default to sending as is with one space
            send_as_is_1space(symbol->mof_string);
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
 * @brief Sends 'string' and one space. 
 *
 * Typically used for typing symbols that require an extra space to appear correctly, 
 * such as subscripts and superscripts.
 *
 * @param string a pointer to the string to be sent
 */
void send_as_is_1space(const char *string) {
    send_string(string);
    send_space();
}

/**
 * @brief Sends 'string' and two spaces. 
 * 
 * Typically used for typing symbols that require two extra spaces to appear 
 * correctly, such as combining symbols like hat, overbar, tilde, etc.
 *
 * @param string a pointer to the string to be sent
 */
void send_as_is_2space(const char *string) {
    send_string(string);
    send_2x_space();
}

/**
 * @brief Sends 'string' and one space and moves the caret left once.
 *
 * @param string a pointer to the string to be sent
 */
void send_with_left_move_1space(const char *string) {
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
void send_with_left_move_2space(const char *string) {
    send_string(string);
    send_2x_space();
    tap_code(KC_LEFT);
}

/**
 * @brief Sends 'string' and one space and deletes limits.
 *
 * Typically used for typing symbols that must be typed with placeholder limits, and you want 
 * to delete the placeholder limits after typing. Examples include summation, integrals, etc.
 * The symbol string must end with '_a^b'. For example, '\\sum_a^b'.
 *
 * @param string a pointer to the string to be sent
 */
void send_with_delete_lims_1space(const char *string) {
    send_string(string);
    send_space();
    tap_code(KC_LEFT);
    tap_code(KC_BSPC);
    tap_code(KC_LEFT);
    tap_code(KC_BSPC);
}
