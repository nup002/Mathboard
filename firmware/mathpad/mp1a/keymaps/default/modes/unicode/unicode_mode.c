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
void send_unicode(uint32_t code_point) {
    uint8_t current_unicode_mode = get_unicode_input_mode();
    if (code_point != 0) {
        if (current_unicode_mode == UNICODE_MODE_MACOS) {
            send_unicode_via_rawhid(code_point);
        } else {
            register_unicode(code_point);
        }
    }
}

// Send Unicode character via Raw HID (for MAC OS)
void send_unicode_via_rawhid(uint32_t code_point) {
    // Prepare Raw HID report (32 bytes for QMK)
    uint8_t raw_hid_data[32] = {0};

    // Command byte: 0x01 = Unicode input
    raw_hid_data[0] = 0x01;

    // Convert uint32_t to 4-character hex string (as ASCII bytes)
    // Format: 0x00B0 becomes ['0', '0', 'b', '0']
    static const char hex_chars[] = "0123456789abcdef";

    raw_hid_data[1] = hex_chars[(code_point >> 12) & 0xF];  // Most significant nibble
    raw_hid_data[2] = hex_chars[(code_point >> 8) & 0xF];
    raw_hid_data[3] = hex_chars[(code_point >> 4) & 0xF];
    raw_hid_data[4] = hex_chars[code_point & 0xF];         // Least significant nibble

    // Send via QMK's Raw HID
    raw_hid_send(raw_hid_data, 32);
}