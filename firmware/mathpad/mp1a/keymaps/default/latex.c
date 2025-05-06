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
#include "latex.h"
#include QMK_KEYBOARD_H

/**
 * @brief Sends a string and moves the caret 4 steps backwards.
 *
 * This is commonly used when sending a LaTeX code that ends with '{}_{}', in order
 * to place the caret inside the first curly braces.
 *
 * @param string The string to send.
 */
void send_and_backtrack_4(const char *string){
    send_string(string);
    for (int i = 0; i < 4; ++i){tap_code(KC_LEFT);}
}

/**
 * @brief Sends a string and moves the caret 3 steps backwards.
 *
 * This is commonly used when sending a LaTeX code that ends with '{}{}', in order
 * to place the caret inside the first curly braces.
 *
 * @param string The string to send.
 */
void send_and_backtrack_3(const char *string){
    send_string(string);
    for (int i = 0; i < 3; ++i){tap_code(KC_LEFT);}
}

/**
 * @brief Sends a string and moves the caret 1 step backwards.
 *
 * This is commonly used when sending a LaTeX code that ends with '{}', in order
 * to place the caret inside the curly braces.
 *
 * @param string The string to send.
 */
void send_and_backtrack_1(const char *string){
    send_string(string);
    tap_code(KC_LEFT);
}

void send_latex(const char *string){
    // Else-if for special LaTeX codes that require extra tasks when being sent, 
    // for example moving the caret backwards. 
    // We cannot use case switch structure because the defined LaTeX strings are not constants.
    if (!strcmp(string, sum_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, n_ary_product_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, double_integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, triple_integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, line_integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, surface_integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, volume_integral_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, square_root_LTX)){send_and_backtrack_1(string);}
    else if (!strcmp(string, cube_root_LTX)){send_and_backtrack_1(string);}
    else if (!strcmp(string, fourth_root_LTX)){send_and_backtrack_1(string);}
    else if (!strcmp(string, union_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, intersection_LTX)){send_and_backtrack_4(string);}
    else if (!strcmp(string, frac_LTX)){send_and_backtrack_3(string);}
    else if(strlen(string) > 2 && !strcmp(string + strlen(string) - 2, "{}")) {
        // In this case the string is meant to wrap around the previous character
        tap_code(KC_LEFT);
        // Create a new string that contains the original string up to the last curly brace
        char substring[strlen(string)];
        memcpy(substring, &string[0], strlen(string)-1);
        substring[strlen(string)-1] = '\0';
        send_string(substring);
        tap_code(KC_RIGHT);
        // Send the final curly brace
        tap_code16(KC_RIGHT_CURLY_BRACE);
    } else {
        // In case none of the if statements above were triggered, the string is sent normally
        send_string(string);
    }
}

void send_latex_on_keypress(const char *string, keyrecord_t *record){
    if (record->event.pressed) {
        send_latex(string);
    };
};