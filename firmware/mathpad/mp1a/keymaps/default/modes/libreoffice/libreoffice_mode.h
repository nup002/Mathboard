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

#ifndef LIBREOFFICE_MODE_H
#define LIBREOFFICE_MODE_H

#include QMK_KEYBOARD_H

#include "../../symbols/symbols.h"


// Function to send a symbol's LibreOffice representation
void send_symbol_lof(const symbol_definition_t* symbol);

// Functions for sending LibreOffice symbols with different methods
void send_lof_normal(const char *string);
void send_lof_1space(const char *string);
void send_lof_2space(const char *string);
void send_lof_1backtrack(const char *string);
void send_lof_2backtrack(const char *string);
void send_lof_3backtrack(const char *string);
void send_lof_6backtrack(const char *string);
void send_lof_1space_1backtrack(const char *string);
void send_lof_2space_1backtrack(const char *string);

#endif /* LIBREOFFICE_MODE_H */
