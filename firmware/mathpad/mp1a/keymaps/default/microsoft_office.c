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
#include "microsoft_office.h"
#include QMK_KEYBOARD_H

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
 
 * Typically used for typing symbols that require an extra space to appear correctly, 
 * such as subscripts and superscripts.
 *
 * To send a MOF symbol with this method, define .type = AS_IS_1SPACE in the mofDefinition struct.
 *
 * @param string a pointer to the string to be sent
 */
void send_as_is_1space(char *string){
    send_string(string);
    send_space();
};

/**
 * @brief Sends 'string' and two spaces. 
 * 
 * Typically used for typing symbols that require two extra spaces to appear 
 * correctly, such as combining symbols like hat, overbar, tilde, etc.
 *
 * To send a MOF symbol with this method, define .type = AS_IS_2SPACE in the mofDefinition struct.
 *
 * @param string a pointer to the string to be sent
 */
void send_as_is_2space(char *string){
    // Sends 'string' and two spaces
    send_string(string);
    send_2x_space();
};

/**
 * @brief Sends 'string' and one space and moves the caret left once.
 *
 * To send a MOF symbol with this method, define .type = MOVE_LEFT_1SPACE in the mofDefinition struct.
 *
 * @param string a pointer to the string to be sent
 */
void send_with_left_move_1space(char *string){
    send_string(string);
    send_space();
    tap_code(KC_LEFT);
};

/**
 * @brief Sends 'string' and two spaces and moves the caret left once.
 *
 * Typically used for typing symbols that require two extra spaces to appear correctly 
 * and where the caret should be within the symbol's boundaries after typing. Examples
 * include square root, cube root, and quadratic root.
 *
 * To send a MOF symbol with this method, define .type = MOVE_LEFT_2SPACE in the mofDefinition struct.
 *
 * @param string a pointer to the string to be sent
 */
void send_with_left_move_2space(char *string){
    send_string(string);
    send_2x_space();
    tap_code(KC_LEFT);
};

/**
 * @brief Sends 'string' and one space and deletes limits.
 *
 * Typically used for typing symbols that must be typed with placeholder limits, and you want 
 * to delete the placeholder limits after typing. Examples include summation, integrals, etc.
 * The symbol string must end with '_a^b'. For example, '\\sum_a^b'.
 *
 * To send a MOF symbol with this method, define .type = SPACE_DELETE_PLACEHOLDER_LIMITS in 
 * the mofDefinition struct.
 *
 * @param string a pointer to the string to be sent
 */
void send_with_delete_lims_1space(char *string){
    send_string(string);
    send_space();
    tap_code(KC_LEFT);
    tap_code(KC_BSPC);
    tap_code(KC_LEFT);
    tap_code(KC_BSPC);
};

/**
 * @brief Sends the string and spaces according to the type of the string.
 *
 * This function takes a struct mofDefinition and sends the string and spaces according to
 * the type of the string. The type can be one of the following:
 * - AS_IS_1SPACE: sends the string and one space
 * - AS_IS_2SPACE: sends the string and two spaces
 * - MOVE_LEFT_1SPACE: sends the string and one space and moves the caret left once
 * - MOVE_LEFT_2SPACE: sends the string and two spaces and moves the caret left once
 * - SPACE_DELETE_PLACEHOLDER_LIMITS: sends the string and one space and deletes limits
 *
 * @param mof_def a pointer to the struct mofDefinition to be sent
 */
void send_mof(struct mofDefinition mof_def){
    enum mofTypes mof_type = mof_def.type;
    char *string = mof_def.string;
    switch (mof_type) {
        case AS_IS_1SPACE:
            send_as_is_1space(string);
            break;
        case AS_IS_2SPACE:
            send_as_is_2space(string);
            break;
        case MOVE_LEFT_1SPACE:
            send_with_left_move_1space(string);
            break;
        case MOVE_LEFT_2SPACE:
            send_with_left_move_2space(string);
            break;
        case SPACE_DELETE_PLACEHOLDER_LIMITS:
            send_with_delete_lims_1space(string);
            break;
    };
};

void send_mof_on_keypress(struct mofDefinition mof_def, keyrecord_t *record){
    if (record->event.pressed) {
        send_mof(mof_def);
    };
};