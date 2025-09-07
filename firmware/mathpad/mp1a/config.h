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

#pragma once

#define FIRMWARE_VERSION "1.1.0"      // Firmware version

#define RGBLIGHT_LIMIT_VAL 255        // Maximum MODE switch brightness
#define RGBLIGHT_LED_COUNT 1          // MODE switch backlight
#define RGBLIGHT_SLEEP true           // Turn off MODE switch light when host goes to sleep
#define RGBLIGHT_LAYERS               // Enable MODE switch colours
#define RGBLIGHT_LAYERS_RETAIN_VAL    // Retain brightness value when switching mode
#define DIP_SWITCH_PINS { GP7, GP8, GP9 }  // OS switch input pins

#define UNICODE_CYCLE_PERSIST false

