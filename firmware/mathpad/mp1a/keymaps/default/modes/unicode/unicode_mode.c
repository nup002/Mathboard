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

#include "unicode_mode.h"


// Function to send a symbol's unicode representation
void send_symbol_unicode(const symbol_definition_t* symbol) {
    if (symbol->unicode_value != 0) {
        send_unicode(symbol->unicode_value);
    }
}

/**
 * @brief Sends a Unicode character
 *
 * @param unicode_value The Unicode code point to send
 */
void send_unicode(uint32_t unicode_value) {
    if (unicode_value != 0) {
        register_unicode(unicode_value);
    }
}