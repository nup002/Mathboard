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

#include QMK_KEYBOARD_H
#include "symbols.h"
#include "symbol_categories.h"
#include "../globals.h"
#include "../modes/mode.h"
#include "../modes/unicode/unicode_mode.h"
#include "../modes/latex/latex_mode.h"
#include "../modes/microsoft_office/microsoft_office_mode.h"
#include "../modes/libreoffice/libreoffice_mode.h"

// Function to send a symbol if the key is pressed
void send_symbol_on_keypress(const symbol_definition_t* symbol, keyrecord_t* record) {
    if (!record->event.pressed) {
        return;  // Only process on key press, not release
    }
    send_symbol(symbol);
}

// Function to send a symbol based on the current mode
void send_symbol(const symbol_definition_t* symbol) {
    switch (user_config.MODE) {
        case UC_MODE:
            send_symbol_unicode(symbol);
            break;
        case LTX_MODE:
            send_symbol_latex(symbol);
            break;
        case MOF_MODE:
            send_symbol_mof(symbol);
            break;
        case LOF_MODE:
            send_symbol_lof(symbol);
            break;
    }
}