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

#ifndef SYMBOLS_H
#define SYMBOLS_H

// Include QMK headers first to get keyrecord_t definition
#include QMK_KEYBOARD_H

// Include the original symbol definitions header for compatibility
// This provides the symbol_definition_t structure and enums
#include "../symbol_definitions.h"

// Include all symbol categories
#include "symbol_categories.h"

// Function declarations for the new symbol sending system

// Function to send a symbol based on the current mode
void send_symbol(const symbol_definition_t* symbol);

// Function to send a symbol only if the key is pressed
void send_symbol_on_keypress(const symbol_definition_t* symbol, keyrecord_t* record);

// Maps a custom keycode to its corresponding symbol definition
const symbol_definition_t* get_symbol_for_keycode(uint16_t keycode);

#endif /* SYMBOLS_H */
