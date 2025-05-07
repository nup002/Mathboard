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

#include "unicode_symbols.h" 
#include QMK_KEYBOARD_H

 /**
  * @brief Send a Unicode symbol as a hexadecimal input
  * 
  * This function sends a Unicode symbol by using the QMK unicode input method.
  * It starts unicode input, registers the hex code, and finishes the input.
  * It is used to send Unicode symbols during multitap.
  *
  * @param symbol The Unicode code point to be sent (in hexadecimal)
  */
 void send_unicode_as_hex(int symbol){
     unicode_input_start();
     register_hex(symbol);
     unicode_input_finish();
 };
 
 /**
  * @brief Send a Unicode symbol when a key is pressed
  * 
  * This function registers a Unicode symbol only when the key is initially pressed down.
  * 
  * @param symbol The Unicode code point to be sent (in hexadecimal)
  * @param record Pointer to the key record containing event information
  */
 void send_unicode_on_keypress(int symbol, keyrecord_t *record){
     if (record->event.pressed) {
         register_unicode(symbol);
     };
 };
