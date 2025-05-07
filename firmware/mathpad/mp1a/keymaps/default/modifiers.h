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

#ifndef MODIFIERS_H
#define MODIFIERS_H

/*
 * Modifier key state variables.
 * These are set to True or False depending on which modifier
 * keys are pressed.
 */
extern bool rightkey_pressed;
extern bool midkey_pressed;
extern bool frontkey_pressed;

void update_active_layer(void);

#endif