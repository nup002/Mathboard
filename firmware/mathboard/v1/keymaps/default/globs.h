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
#ifndef GLOBS_H
#define GLOBS_H

enum modes {
    UC,
    MOF,
    LTX
};

// MODE is a global variable that sets which type of output the Matboard should emit. 
// It can be Unicode, Microsoft Office equations editor, LaTeX, etc. Clicking the mode-change button on the Mathboard
// cycles the MODE variable to its next value.
enum modes MODE = LTX;


#endif