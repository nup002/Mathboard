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
#include "os_switch.h"
#include "unicode.h"
#include "raw_hid.h"


// Function to send a symbol's unicode representation
void send_symbol_unicode(const symbol_definition_t* symbol) {
    if (symbol->unicode_value != 0) {
        if (get_unicode_input_mode() == UNICODE_MODE_MACOS) {
            send_raw_hid_unicode(symbol->unicode_value);
        } else {
            send_unicode(symbol->unicode_value);
        }
    }
}

void send_raw_hid_unicode(uint32_t unicode_value) {
    if (unicode_value != 0) {
        uint8_t data[32] = {0};
        
        // Prepare the data packet for raw HID
        // First byte: command type (1 for Unicode)
        data[0] = 1;
        
        // Next 4 bytes: Unicode value (32-bit)
        data[1] = (unicode_value >> 24) & 0xFF;
        data[2] = (unicode_value >> 16) & 0xFF;
        data[3] = (unicode_value >> 8) & 0xFF;
        data[4] = unicode_value & 0xFF;
        
        // Send the data packet
        raw_hid_send(data, 32);
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