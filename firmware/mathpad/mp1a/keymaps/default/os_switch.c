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

#include "os_switch.h"
#include QMK_KEYBOARD_H

/**
 * @brief Set the current Unicode compatibility mode based on the state of the OS switch.
 */
bool dip_switch_update_user(uint8_t index, bool active) { 
    uint8_t current_unicode_mode = get_unicode_input_mode();
    switch (index) {
        case 0:
            if(active & (current_unicode_mode!=UNICODE_MODE_LINUX)) {
                set_unicode_input_mode(UNICODE_MODE_LINUX); 
                }
            break;
        case 1:
            if(active & (current_unicode_mode!=UNICODE_MODE_MACOS)) {
                set_unicode_input_mode(UNICODE_MODE_MACOS); 
                }
            break;
        case 2:
            if(active & (current_unicode_mode!=UNICODE_MODE_WINCOMPOSE)) {
                set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE); 
                }
            break;
    }
    return true;
};
