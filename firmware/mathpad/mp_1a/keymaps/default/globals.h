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

// Global variables are defined in this file.

#ifndef GLOBALS_H
#define GLOBALS_H

#include QMK_KEYBOARD_H

// Define the 6 different symbol locations on the keycaps
#define _LEFT_TOP 0  
#define _LEFT_MID 1
#define _LEFT_FRONT 2
#define _RIGHT_TOP 3 
#define _RIGHT_MID 4
#define _RIGHT_FRONT 5

// Persistent settings
typedef union {
  uint8_t raw;
  struct {
    // MODE is a global variable that tracks the latest Mathpad mode.
    uint8_t     MODE :8;
  };
} user_config_t;

user_config_t user_config;
#endif