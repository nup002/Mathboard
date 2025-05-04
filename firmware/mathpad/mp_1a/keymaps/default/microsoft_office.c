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

void send_space(void){
    // Sends one space character
    tap_code(KC_SPACE);
};

void send_2x_space(void){
    // Sends two space characters
    tap_code(KC_SPACE);
    tap_code(KC_SPACE);
};

void send_as_is_1space(char *string){
    // Sends 'string' and one space
    send_string(string);
    send_space();
};

void send_as_is_2space(char *string){
    // Sends 'string' and two spaces
    send_string(string);
    send_2x_space();
};

void send_with_left_move_1space(char *string){
    // Sends 'string' and one space and moves the caret left once
    send_string(string);
    send_space();
    tap_code(KC_LEFT);
};

void send_with_left_move_2space(char *string){
    // Sends 'string' and two spaces and moves the caret left once
    send_string(string);
    send_2x_space();
    tap_code(KC_LEFT);
};

void send_with_delete_lims_1space(char *string){
    // Sends 'string' and one spaces and deletes limits.
    send_string(string);
    send_space();
    tap_code(KC_LEFT);
    tap_code(KC_BSPC);
    tap_code(KC_LEFT);
    tap_code(KC_BSPC);
};

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