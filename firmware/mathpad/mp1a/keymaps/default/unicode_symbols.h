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

#ifndef UNICODE_SYMBOLS_H
#define UNICODE_SYMBOLS_H
 
#include QMK_KEYBOARD_H

void send_unicode_as_hex(int symbol);

void send_unicode_on_keypress(int symbol, keyrecord_t *record);
 
  // Greek Letters
 #define _alpha 0x03B1       // https://www.compart.com/en/unicode/U+03B1 (α)
 #define _beta 0x03B2        // https://www.compart.com/en/unicode/U+03B2 (β)
 #define _gamma 0x03B3       // https://www.compart.com/en/unicode/U+03B3 (γ)
 #define _Gamma 0x0393       // https://www.compart.com/en/unicode/U+0393 (Γ, uppercase Gamma)
 #define _delta 0x03B4       // https://www.compart.com/en/unicode/U+03B4 (δ)
 #define _Delta 0x0394       // https://www.compart.com/en/unicode/U+0394 (Δ, uppercase Delta)
 #define _epsilon 0x03B5     // https://www.compart.com/en/unicode/U+03B5 (ε)
 #define _zeta 0x03B6        // https://www.compart.com/en/unicode/U+03B6 (ζ)
 #define _eta 0x03B7         // https://www.compart.com/en/unicode/U+03B7 (η)
 #define _theta 0x03B8       // https://www.compart.com/en/unicode/U+03B8 (θ)
 #define _Theta 0x0398       // https://www.compart.com/en/unicode/U+0398 (Θ, uppercase Theta)
 #define _iota 0x03B9        // https://www.compart.com/en/unicode/U+03B9 (ι)
 #define _kappa 0x03BA       // https://www.compart.com/en/unicode/U+03BA (κ)
 #define _lambda 0x03BB      // https://www.compart.com/en/unicode/U+03BB (λ)
 #define _Lambda 0x039B      // https://www.compart.com/en/unicode/U+039B (Λ, uppercase Lambda)
 #define _mu 0x03BC          // https://www.compart.com/en/unicode/U+03BC (μ)
 #define _nu 0x03BD          // https://www.compart.com/en/unicode/U+03BD (ν)
 #define _xi 0x03BE          // https://www.compart.com/en/unicode/U+03BE (ξ)
 #define _Xi 0x039E          // https://www.compart.com/en/unicode/U+039E (Ξ, uppercase Xi)
 #define _omicron 0x03BF     // https://www.compart.com/en/unicode/U+03BF (ο)
 #define _pi 0x03C0          // https://www.compart.com/en/unicode/U+03C0 (π)
 #define _Pi 0x03A0          // https://www.compart.com/en/unicode/U+03A0 (Π, uppercase Pi)
 #define _rho 0x03C1         // https://www.compart.com/en/unicode/U+03C1 (ρ)
 #define _sigma 0x03C3       // https://www.compart.com/en/unicode/U+03C3 (σ)
 #define _Sigma 0x03A3       // https://www.compart.com/en/unicode/U+03A3 (Σ, uppercase Sigma)
 #define _tau 0x03C4         // https://www.compart.com/en/unicode/U+03C4 (τ)
 #define _upsilon 0x03C5     // https://www.compart.com/en/unicode/U+03C5 (υ)
 #define _phi 0x03D5         // https://www.compart.com/en/unicode/U+03D5 (φ)
 #define _varphi 0x03C6      // https://www.compart.com/en/unicode/U+03C6 (φ)
 #define _Phi 0x03A6         // https://www.compart.com/en/unicode/U+03A6 (Φ, uppercase Phi)
 #define _chi 0x03C7         // https://www.compart.com/en/unicode/U+03C7 (χ)
 #define _psi 0x03C8         // https://www.compart.com/en/unicode/U+03C8 (ψ)
 #define _Psi 0x03A8         // https://www.compart.com/en/unicode/U+03A8 (Ψ, uppercase Psi)
 #define _omega 0x03C9       // https://www.compart.com/en/unicode/U+03C9 (ω)
 #define _Omega 0x03A9       // https://www.compart.com/en/unicode/U+03A9 (Ω, uppercase Omega)

 // Comparison and Equivalence Symbols
 #define _not_equal 0x2260              // https://www.compart.com/en/unicode/U+2260 (not equal to ≠)
 #define _almost_equal 0x2248           // https://www.compart.com/en/unicode/U+2248 (almost equal to ≈)
 #define _proportional 0x221D           // https://www.compart.com/en/unicode/U+221D (proportional to ∝)
 #define _identical_to 0x2261           // https://www.compart.com/en/unicode/U+2261 (identical to ≡)
 #define _asymptotically_equal 0x2243   // https://www.compart.com/en/unicode/U+2243 (asymptotically equal to ≃)
 #define _approximately_equal 0x2245    // https://www.compart.com/en/unicode/U+2245 (approximately equal to ≅)
 #define _identical_to 0x2261           // https://www.compart.com/en/unicode/U+2261 (identical to ≡)
 #define _not_identical_to 0x2262       // https://www.compart.com/en/unicode/U+2262 (not identical to ≢)
 #define _colon_equals 0x2254           // https://www.compart.com/en/unicode/U+2254 (colon equals ≔)
 #define _equal_by_definition 0x225D    // https://www.compart.com/en/unicode/U+225D (equal by definition ≝)
 #define _less_or_equal 0x2264          // https://www.compart.com/en/unicode/U+2264 (less than or equal to ≤)
 #define _greater_or_equal 0x2265       // https://www.compart.com/en/unicode/U+2265 (greater than or equal to ≥)
 #define _much_greater_than 0x226B      // https://www.compart.com/en/unicode/U+226B (much greater than ≫)
 #define _very_much_greater_than 0x22D9 // https://www.compart.com/en/unicode/U+22D9 (very much greater than ⋙)
 #define _much_less_than 0x226A         // https://www.compart.com/en/unicode/U+226A (much less than ≪)
 #define _very_much_less_than 0x22D8    // https://www.compart.com/en/unicode/U+22D8 (very much less than ⋘)

 // Combining diacritics (overbars, subscripts, superscripts)
 #define _circumflex 0x0302            // https://www.compart.com/en/unicode/U+0302 (combining circumflex accent ̂)
 #define _check 0x030C                 // https://www.compart.com/en/unicode/U+030C (combining caron ̌)
 #define _combining_tilde 0x0303       // https://www.compart.com/en/unicode/U+0303 (combining tilde ̃)
 #define _combining_bar 0x0304         // https://www.compart.com/en/unicode/U+0304 (combining macron ̄)
 #define _combining_arrow 0x20D7       // https://www.compart.com/en/unicode/U+20D7 (combining right arrow above ⃗)
 #define _combining_dot 0x0307         // https://www.compart.com/en/unicode/U+0307 (combining dot above ̇)
 #define _combining_2dot 0x0308        // https://www.compart.com/en/unicode/U+0308 (combining diaeresis ̈)
 #define _prime 0x2032                 // https://www.compart.com/en/unicode/U+2032 (prime ′)
 #define _double_prime 0x2033          // https://www.compart.com/en/unicode/U+2033 (double prime ″)
 #define _triple_prime 0x2034          // https://www.compart.com/en/unicode/U+2034 (triple prime ‴)
 #define _quadruple_prime 0x2057       // https://www.compart.com/en/unicode/U+2057 (quadruple prime ⁗)
 #define _transposed 0x1D40            // https://www.compart.com/en/unicode/U+1D40 (modifier letter capital T ᵀ)
 #define _sup_0 0x2070                 // https://www.compart.com/en/unicode/U+2070 (superscript 0 ⁰)
 #define _sup_1 0x00B9                 // https://www.compart.com/en/unicode/U+00B9 (superscript 1 ¹)
 #define _sup_2 0x00B2                 // https://www.compart.com/en/unicode/U+00B2 (superscript 2 ²)
 #define _sup_n 0x207F                 // https://www.compart.com/en/unicode/U+207F (superscript n ⁿ)
 #define _sup_i 0x2071                 // https://www.compart.com/en/unicode/U+2071 (superscript small i ⁱ)
 #define _sup_j 0x02B2                 // https://www.compart.com/en/unicode/U+02B2 (modifier letter small j ʲ)
 #define _sub_0 0x2080                 // https://www.compart.com/en/unicode/U+2080 (subscript 0 ₀)
 #define _sub_1 0x2081                 // https://www.compart.com/en/unicode/U+2081 (subscript 1 ₁)
 #define _sub_2 0x2082                 // https://www.compart.com/en/unicode/U+2082 (subscript 2 ₂)
 #define _sub_n 0x2099                 // https://www.compart.com/en/unicode/U+2099 (subscript n ₙ)
 #define _sub_i 0x1D62                 // https://www.compart.com/en/unicode/U+1D62 (subscript small i ᵢ)
 #define _sub_j 0x2C7C                 // https://www.compart.com/en/unicode/U+2C7C (subscript small j ⱼ)

 // Algebra and Calculus Symbols
 #define _sum 0x2211                   // https://www.compart.com/en/unicode/U+2211 (N-ary summation ∑)
 #define _n_ary_product 0x220F         // https://www.compart.com/en/unicode/U+220F (N-ary product ∏)
 #define _integral 0x222B              // https://www.compart.com/en/unicode/U+222B (integral ∫)
 #define _double_integral 0x222C       // https://www.compart.com/en/unicode/U+222C (double integral ∬)
 #define _triple_integral 0x222D       // https://www.compart.com/en/unicode/U+222D (triple integral ∭)
 #define _line_integral 0x222E         // https://www.compart.com/en/unicode/U+222E (line integral ∮)
 #define _surface_integral 0x222F      // https://www.compart.com/en/unicode/U+222F (surface integral ∯)
 #define _volume_integral 0x2230       // https://www.compart.com/en/unicode/U+2230 (volume integral ∰)
 #define _square_root 0x221A           // https://www.compart.com/en/unicode/U+221A (square root √)
 #define _cube_root 0x221B             // https://www.compart.com/en/unicode/U+221B (cube root ∛)
 #define _fourth_root 0x221C           // https://www.compart.com/en/unicode/U+221C (fourth root ∜)
 #define _partial_differential 0x2202    // https://www.compart.com/en/unicode/U+2202 (partial differential ∂)
 #define _nabla 0x2207                 // https://www.compart.com/en/unicode/U+2207 (nabla ∇)

 // Arrows
 #define _right_double_arrow 0x21D2    // https://www.compart.com/en/unicode/U+21D2 (rightwards double arrow ⇒)
 #define _left_double_arrow 0x21D0     // https://www.compart.com/en/unicode/U+21D0 (leftwards double arrow ⇐)
 #define _rightleft_double_arrow 0x21D4// https://www.compart.com/en/unicode/U+21D4 (left right double arrow ⇔)
 #define _right_arrow 0x2192           // https://www.compart.com/en/unicode/U+2192 (rightwards arrow →)
 #define _left_arrow 0x2190            // https://www.compart.com/en/unicode/U+2190 (leftwards arrow ←)
 #define _rightleft_arrow 0x2194       // https://www.compart.com/en/unicode/U+2194 (rightleft arrow ↔)

 // Set Theory Symbols
 #define _union 0x222A                 // https://www.compart.com/en/unicode/U+222A (union ∪)
 #define _intersection 0x2229          // https://www.compart.com/en/unicode/U+2229 (intersection ∩)
 #define _element_of 0x2208            // https://www.compart.com/en/unicode/U+2208 (element of ∈)
 #define _contains_as_member 0x2209    // https://www.compart.com/en/unicode/U+2209 (contains as member ∋)
 #define _not_element_of 0x2209        // https://www.compart.com/en/unicode/U+2209 (not an element of ∉)
 #define _direct_sum 0x2295            // https://www.compart.com/en/unicode/U+2295 (direct sum ⊕)
 #define _empty_set 0x2205             // https://www.compart.com/en/unicode/U+2205 (empty set ∅)
 #define _power_set 0x1D4AB            // https://www.compart.com/en/unicode/U+1D4AB (power set 𝒫)
 #define _proper_subset 0x2282         // https://www.compart.com/en/unicode/U+2282 (proper subset ⊂)
 #define _not_proper_subset 0x2284     // https://www.compart.com/en/unicode/U+2284 (not a proper subset ⊄)
 #define _set_difference 0x2216        // https://www.compart.com/en/unicode/U+2216 (set minus ∖)
 #define _subset 0x2286                // https://www.compart.com/en/unicode/U+2286 (subset ⊆)
 #define _not_subset 0x2288            // https://www.compart.com/en/unicode/U+2288 (not a subset ⊈)
 #define _disjoint_union 0x2A06        // https://www.compart.com/en/unicode/U+2A06 (disjoint union ⨆)

 // Logic Symbols
 #define _there_exists 0x2203          // https://www.compart.com/en/unicode/U+2203 (∃, there exists)
 #define _there_does_not_exists 0x2204 // https://www.compart.com/en/unicode/U+2204 (∄, there does not exist)
 #define _and 0x2227                   // https://www.compart.com/en/unicode/U+2227 (∧, logical and)
 #define _or 0x2228                    // https://www.compart.com/en/unicode/U+2228 (∨, logical or)
 #define _xor 0x22BB                   // https://www.compart.com/en/unicode/U+22BB (xor ⊻)
 #define _for_all 0x2200               // https://www.compart.com/en/unicode/U+2200 (∀, for all)
 #define _not 0x00AC                   // https://www.compart.com/en/unicode/U+00AC (¬, not)
 #define _proves 0x22A2                // https://www.compart.com/en/unicode/U+22A2 (right tack ⊢)
 #define _models 0x22A8                // https://www.compart.com/en/unicode/U+22A8 (true ⊨)
 #define _down_tack 0x22A4             // https://www.compart.com/en/unicode/U+22A4 (⊤, down tack)
 #define _up_tack 0x22A5               // https://www.compart.com/en/unicode/U+22A5 (⊥, up tack)

 // Other Mathematical and Scientific Symbols
 #define _dotproduct 0x22C5            // https://www.compart.com/en/unicode/U+22C5 (dot operator ⋅)
 #define _times 0x00D7                 // https://www.compart.com/en/unicode/U+00D7 (times ×)
 #define _division 0x00F7              // https://www.compart.com/en/unicode/U+00F7 (÷, division)
 #define _plusminus 0x00B1             // https://www.compart.com/en/unicode/U+00B1 (plus-minus sign ±)
 #define _minusplus 0x2213             // https://www.compart.com/en/unicode/U+2213 (minus-plus sign ∓)
 #define _parallel 0x2225              // https://www.compart.com/en/unicode/U+2225 (parallel to ∥)
 #define _degree 0x00B0                // https://www.compart.com/en/unicode/U+00B0 (degree sign °)
 #define _infinity 0x221E              // https://www.compart.com/en/unicode/U+221E (infinity ∞)
 #define _circled_times 0x2297         // https://www.compart.com/en/unicode/U+2297 (circled times ⊗)
 
 // Number systems
 #define _naturals 0x2115               // https://www.compart.com/en/unicode/U+2115 (ℕ, double-struck capital N)
 #define _integers 0x2124               // https://www.compart.com/en/unicode/U+2124 (ℤ, double-struck capital Z)
 #define _rationals 0x211A              // https://www.compart.com/en/unicode/U+211A (ℚ, double-struck capital Q)
 #define _reals 0x211D                  // https://www.compart.com/en/unicode/U+211D (ℝ, double-struck capital R)
 #define _complexes 0x2102              // https://www.compart.com/en/unicode/U+2102 (ℂ, double-struck capital C)

 #endif /* UNICODE_SYMBOLS_H */