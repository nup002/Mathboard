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

#include "modifiers.h"
#include QMK_KEYBOARD_H
#include "globals.h"

// Initiate the modifier key states to false on Mathpad boot
bool rightkey_pressed = false;
bool midkey_pressed = false;
bool frontkey_pressed = false;


/**
 * @brief Function to update active layer based on modifier states
 *
 * This function should be called each time a modifier key is pressed or released.
 * It will update the active layer based on the modifier key states.
 */
void update_active_layer(void) {
    layer_clear(); // Clear all layers first

    // Set the appropriate layer based on modifier key combinations
    if (rightkey_pressed && frontkey_pressed && !midkey_pressed) {
        layer_on(_RIGHT_FRONT); // RIGHT and FRONT modifier keys are pressed
    } else if (rightkey_pressed && midkey_pressed && !frontkey_pressed) {
        layer_on(_RIGHT_MID); // RIGHT and MIDDLE keys are pressed
    } else if (rightkey_pressed && !midkey_pressed && !frontkey_pressed) {
        layer_on(_RIGHT_TOP); // Only RIGHT key is pressed
    } else if (!rightkey_pressed && midkey_pressed && !frontkey_pressed) {
        layer_on(_LEFT_MID); // Only MIDDLE key is pressed
    } else if (!rightkey_pressed && !midkey_pressed && frontkey_pressed) {
        layer_on(_LEFT_FRONT); // Only FRONT key is pressed
    } else {
        layer_on(_LEFT_TOP); // Default or invalid combinations go to the default _LEFT_TOP
    }
}
