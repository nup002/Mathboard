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

// Functions related to setting the 'mode' of the Mathpad, meaning which 
// representation is used when typing symbols. Modes include Plaintext Unicode (UC_MODE), 
// LaTeX (LTX_MODE), Microsoft Office Equation Editor (MOF_MODE), and soon LibreOffice (LOF_MODE).

#include "mode.h"
#include QMK_KEYBOARD_H
#include "color.h"
#include "rgblight.h"
#include "../globals.h"

/** 
* When 'update_led_to_match_mode' is called, it checks the current value of
* user_config.MODE and sets the mode key backlight to the
* corresponding color.
*/
void update_led_to_match_mode(void) {
    rgblight_set_layer_state(0, user_config.MODE == UC_MODE);
    rgblight_set_layer_state(1, user_config.MODE == MOF_MODE);
    rgblight_set_layer_state(2, user_config.MODE == LOF_MODE);
    rgblight_set_layer_state(3, user_config.MODE == LTX_MODE);
}

/**
 * Increases the brightness of the MODE switch.
 *
 * This function increases the brightness of the MODE switch by a factor of 2.
 * If the brightness is already at its maximum, it will not change.
 */
void increase_brightness(void) {
    uint8_t val = rgblight_get_val(); 

    uint16_t new_val;  
    if (val == 0){
        new_val = 16; // Lowest brightness
    }else{
        new_val = (uint16_t)(val * 2);
        if (new_val > 255) {
            new_val = 255;
        }
    }
    rgblight_sethsv(255, 255, (uint8_t)new_val);
}

/**
 * Decreases the brightness of the MODE switch.
 *
 * This function decreases the brightness of the MODE switch by a factor of 2.
 * If the brightness is already at its minimum, it will not change.
 */
void decrease_brightness(void) {
    uint8_t val = rgblight_get_val(); 
    if (val <= 16){
        val = 0;
    }else{
        val /= 2;
    }
    rgblight_sethsv(255, 255, val);
}

/**
 * Sets the mathpad output mode.
 *
 * This function updates the user configuration with the specified mode,
 * writes the configuration back persistent memory, and updates the LED to reflect
 * the current mode.
 *
 * @param mode The mode to set. This should be one of the predefined modes
 *             such as UC_MODE, MOF_MODE, or LTX_MODE defined in mode.h
 */
void output_mode_set(uint8_t mode) { 
    user_config.MODE = mode; 
    eeconfig_update_user(user_config.raw); 
    update_led_to_match_mode();
}


/**
 * Cycles between mathpad output modes when called. 
 * It goes UC_MODE -> MOF_MODE -> LOF_MODE -> LTX_MODE 
 * 
 * This function is meant to be called from the keymap to cycle the output
 * modes of the mathpad.
 */
void output_mode_update(void) {
    if (user_config.MODE == UC_MODE) {
        output_mode_set(MOF_MODE);
    } else if (user_config.MODE == MOF_MODE) {
        output_mode_set(LOF_MODE);
    } else if (user_config.MODE == LOF_MODE) {
        output_mode_set(LTX_MODE);
    } else if (user_config.MODE == LTX_MODE) {
        output_mode_set(UC_MODE);
    }
}
