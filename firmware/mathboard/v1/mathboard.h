/* Copyright 2023 Magne Lauritzen
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

// Any changes to the layout names and/or definitions must also be made to info.json

#define LAYOUT( \
    K00, K01, K02, K03, K04, \
         K10, K11, K12, K13, \
    K20, K21, K22, K23, K24, \
              K30,      K32  \
) { \
    { K00,   K01,   K02,   K03,   K04}, \
    { KC_NO, K10,   K11,   K12,   K13}, \
    { K20,   K21,   K22,   K23,   K24}, \
    { KC_NO, KC_NO, K30,   KC_NO, K32}  \
}
