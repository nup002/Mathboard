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

#ifndef MODE_H
#define MODE_H


// Each output mode is defined here. 
#define UC_MODE 0  // Unicode
#define MOF_MODE 1 // Microsoft Office Equation Editor
#define LTX_MODE 2 // LaTeX

void update_led_to_match_mode(void);

void output_mode_set(uint8_t mode);

void output_mode_update(void);
# endif