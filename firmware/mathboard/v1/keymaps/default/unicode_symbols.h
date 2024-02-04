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

#ifndef UNICODE_SYMBOLS_H
#define UNICODE_SYMBOLS_H

void send_hex(int symbol){
    unicode_input_start();
    register_hex(symbol);
    unicode_input_finish();
};

void send_hex_on_keypress(int symbol, keyrecord_t *record){
    if (record->event.pressed) {
        //send_hex(symbol);
        register_unicode(symbol);
    };
};

// Greek letters
#define _alpha 0x03B1
#define _beta 0x03B2
#define _gamma 0x03B3
#define _Gamma 0x0393
#define _delta 0x03B4
#define _Delta 0x0394
#define _epsilon 0x03B5
#define _zeta 0x03B6
#define _eta 0x03B7
#define _theta 0x03B8
#define _Theta 0x0398
#define _iota 0x03B9
#define _kappa 0x03BA
#define _lambda 0x03BB
#define _Lambda 0x039B
#define _mu 0x03BC
#define _nu 0x03BD
#define _xi 0x03BE
#define _Xi 0x039E
#define _omicron 0x03BF
#define _pi 0x03C0
#define _Pi 0x03A0
#define _rho 0x03C1
#define _sigma 0x03C3
#define _Sigma 0x03A3
#define _tau 0x03C4
#define _upsilon 0x03C5
#define _phi 0x03C6
#define _Phi 0x03A6
#define _chi 0x03C7
#define _psi 0x03C8
#define _Psi 0x03A8
#define _omega 0x03C9
#define _Omega 0x03A9

// Comparison and equivalence
#define _notequal 0x2260
#define _almostequal 0x2248
#define _proportional 0x221D
#define _identicalto 0x2261
#define _lessorequal 0x2264
#define _greaterorequal 0x2265
#define _much_greater_than 0x226B
#define _much_much_greater_than 0x22D9
#define _much_less_than 0x226A
#define _much_much_less_than 0x22D8

// Modifiers
#define _circumflex 0x0302
#define _check 0x030C
#define _combining_tilde 0x0303
#define _combining_bar 0x0304
#define _combining_arrow 0x20D7
#define _combining_dot 0x0307
#define _combining_2dot 0x0308
#define _prime 0x2032 // not in use currently
#define _double_prime 0x2033 // not in use currently
#define _triple_prime 0x2034 // not in use currently
#define _quadruple_prime 0x2057 // not in use currently
#define _transposed 0x1D40
#define _sup_0 0x2070
#define _sup_1 0x00B9
#define _sup_2 0x00B2
#define _sup_n 0x207F
#define _sup_i 0x2071
#define _sup_j 0x02B2
#define _sub_0 0x2080
#define _sub_1 0x2081
#define _sub_2 0x2082
#define _sub_n 0x2099
#define _sub_i 0x1D62
#define _sub_j 0x2C7C

// Algebra and calculus
#define _sum 0x2211
#define _n_ary_product 0x220F
#define _integral 0x222B
#define _double_integral 0x222C
#define _triple_integral 0x222D
#define _line_integral 0x222E
#define _surface_integral 0x222F
#define _volume_integral 0x2230
#define _square_root 0x221A
#define _cube_root 0x221B
#define _fourth_root 0x221C
#define _arrow 0x2192
#define _partial_derivative 0x2202
#define _nabla 0x2207

// Set theory 
#define _union 0x222A
#define _intersection 0x2229
#define _element_of 0x2208
#define _not_element_of 0x2209
#define _empty_set 0x2205
#define _subset_of 0x2282
#define _not_subset_of 0x2284
#define _set_difference 0x2216
#define _subset_or_equal 0x2286
#define _not_subset_or_equal 0x2288
#define _disjoint_union 0x2A06

// Logic
#define _arrow_implies 0x21D2
#define _arrow_if_and_only_if 0x21D4
#define _there_exists 0x2203
#define _there_does_not_exists 0x2204
#define _and 0x2227
#define _or 0x2228
#define _xor 0x22BB
#define _for_all 0x2200
#define _uncoditionally_true 0x22A4
#define _uncoditionally_false 0x22A5
#define _not 0x00AC
#define _proves 0x22A2
#define _models 0x22A8

// Others
#define _dotproduct 0x22C5
#define _crossproduct 0x2A2F
#define _plusminus 0x00B1
#define _minusplus 0x2213
#define _parallel 0x2225
#define _degree 0x00B0
#define _infinity 0x221E

#endif