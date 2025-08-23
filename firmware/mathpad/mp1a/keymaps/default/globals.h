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

#include "quantum.h"
#include "build_info_generated.h"
#include "build_config_generated.h"

// Define the 6 symbol layers
#define _LEFT_TOP 0  
#define _LEFT_CENTER 1
#define _LEFT_BOTTOM 2
#define _RIGHT_TOP 3 
#define _RIGHT_CENTER 4
#define _RIGHT_BOTTOM 5

// Persistent settings
typedef union {
  uint8_t raw;
  struct {
    uint8_t     MODE :8;  // tracks the latest Mathpad mode.
  };
} user_config_t;

// Sticky modifiers are normally off. Enable by adding `STICKY_MODIFIERS=true` to the `make` command when compiling.
// This is now defined in build_config_generated.h if specified during build
#ifndef STICKY_MODIFIERS
#define STICKY_MODIFIERS false
#endif

user_config_t user_config;
#endif