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
#include "info.h"
#include "globals.h"
#include "../../config.h"
#include "build_info.h"


/*
 * Returns the PCB revision string. The PCB revision is encoded in the hardware of the PCB and can be read as 3 bits from GPIO 17 to 19.
 * The 3-bit value is mapped to a version string.
 */
const char* pcb_revision(void){
    // Configure GPIO pins 17, 18, 19 as inputs with pull-up resistors
    setPinInputHigh(GP17);
    setPinInputHigh(GP18);
    setPinInputHigh(GP19);
    
    // Read the 3-bit value from the GPIO pins
    // GPIO 17 = bit 0, GPIO 18 = bit 1, GPIO 19 = bit 2
    uint8_t revision_bits = 0;
    
    if (!readPin(GP17)) revision_bits |= (1 << 0);  // Bit 0
    if (!readPin(GP18)) revision_bits |= (1 << 1);  // Bit 1
    if (!readPin(GP19)) revision_bits |= (1 << 2);  // Bit 2
    
    // Map the 3-bit value to a version string
    switch(revision_bits) {
        case 1: return "1.7";
        default: return "Unknown";
    }
}

void print_info(void){
    send_string("## MATHPAD DEBUG INFORMATION ## \n\n");
    wait_ms(50);  // Small delay to prevent jumbling
    
    // Print firmware version
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "Firmware version: %s\n", FIRMWARE_VERSION);
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling
    
    // Get PCB revision string
    const char* revision = pcb_revision();
    snprintf(buffer, sizeof(buffer), "PCB revision: %s\n", revision);
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling
    
    // Print sendstring header info
#ifdef SENDSTRING_LAYOUT
    #define STRINGIFY(x) #x
    #define TOSTRING(x) STRINGIFY(x)
    snprintf(buffer, sizeof(buffer), "Keyboard layout: %s\n", TOSTRING(SENDSTRING_LAYOUT));
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling
#else
    send_string("Keyboard layout: US ANSI (default)\n");
    wait_ms(50);  // Small delay to prevent jumbling
#endif
    
    // Print build date and time
#ifdef BUILD_DATE
    snprintf(buffer, sizeof(buffer), "Build date: %s", BUILD_DATE);
    #ifdef BUILD_TIME
        snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), " %s", BUILD_TIME);
    #endif
    strcat(buffer, "\n");
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling
#else
    send_string("Build date: not available\n");
    wait_ms(50);  // Small delay to prevent jumbling
#endif
    
    // Print Git commit hash
#ifdef GIT_COMMIT_HASH
    snprintf(buffer, sizeof(buffer), "Git commit: %s\n", GIT_COMMIT_HASH);
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling
#elif defined(GIT_HASH)
    snprintf(buffer, sizeof(buffer), "Git commit: %s\n", GIT_HASH);
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling
#else
    send_string("Git commit: not available\n");
    wait_ms(50);  // Small delay to prevent jumbling
#endif
    
    // Print compiler version
#ifdef COMPILER_VERSION
    snprintf(buffer, sizeof(buffer), "Compiler: %s\n", COMPILER_VERSION);
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling
#else
    send_string("Compiler: not available\n");
    wait_ms(50);  // Small delay to prevent jumbling
#endif
    
    // Print build flags
#ifdef BUILD_FLAGS
    snprintf(buffer, sizeof(buffer), "Build flags: %s\n", BUILD_FLAGS);
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling
#else
    send_string("Build flags: standard QMK flags\n");
    wait_ms(50);  // Small delay to prevent jumbling
#endif
    
    // Print current mode
    const char* mode_names[] = {"Unicode", "Microsoft Office", "LaTeX", "LibreOffice"};
    if (user_config.MODE < 4) {
        snprintf(buffer, sizeof(buffer), "Current mode: %s\n", mode_names[user_config.MODE]);
    } else {
        snprintf(buffer, sizeof(buffer), "Current mode: Unknown (%d)\n", user_config.MODE);
    }
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling

    // Print current brightness
    uint8_t brightness = rgblight_get_val();
    uint8_t brightness_percent = (brightness * 100) / 255;
    snprintf(buffer, sizeof(buffer), "Current mode switch brightness: %d%%\n", brightness_percent);
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling

    // Print sticky modifiers
    snprintf(buffer, sizeof(buffer), "Sticky modifiers: %s\n", STICKY_MODIFIERS ? "Enabled" : "Disabled");
    send_string(buffer);
    wait_ms(50);  // Small delay to prevent jumbling
}