/* Copyright 2023 Magne Lauritzen
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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,
    KC_NO,    KC_F,    KC_G,    KC_H,   KC_I,
    KC_J,    KC_K,    KC_L,    KC_M,    KC_N,
    KC_NO,    KC_NO,    KC_O,  KC_NO,   KC_P
  )
};
