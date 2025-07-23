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

#ifndef MICROSOFT_OFFICE_MODE_H
#define MICROSOFT_OFFICE_MODE_H

#include QMK_KEYBOARD_H

#include "../../symbols/symbols.h"


// Function to send a symbol's Microsoft Office representation
void send_symbol_mof(const symbol_definition_t* symbol);
// Helper functions for sending spaces
void send_space(void);
void send_2x_space(void);

// Functions for sending Microsoft Office symbols with different methods
void send_as_is_1space(const char *string);
void send_as_is_2space(const char *string);
void send_with_left_move_1space(const char *string);
void send_with_left_move_2space(const char *string);
void send_with_delete_lims_1space(const char *string);

#endif /* MICROSOFT_OFFICE_MODE_H */
