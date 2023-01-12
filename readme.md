# Mathboard

The Mathboard is a 4x4 macropad to make typing math on a computer easier for engineers and scientists. 
Follow its development on Hackaday: https://hackaday.io/project/186205-math-keyboard
<p align="center">
<img src="https://cdn.hackaday.io/images/1746721664193689607.jpg" width="400">
</p>
With the Mathboard you can type 75 of the most common symbols used in algebra, calculus, set theory and logic, as well as all greek letters (including uppercase). The following equations are a few examples of what you can type directly with the Mathboard:

<p style="text-align: center;"><font size="4"> 
E = mc²<br>
∛β ≫ ∯Ω(t)dt<br>
(A⊂B) ∧ (A⊂C) ⇔ A ⊂ (B ∪ C)
</font> </p>

## Supported input methods
| Input mode                         | Supported |
|------------------------------------|-----------|
| Unicode plaintext                  | ✅        |
| LaTeX                              | ✅        |
| Microsoft Office equation editor   | ✅        |
| Apache Open Office equation editor | ❌        |

## Compatibility
The mathboard works on Unix systems (including Apple Mac OS) and Windows.
When using the Mathboard on Windows, the open source application [WinCompose](https://github.com/samhocevar/wincompose) 
must be installed and running.

## Hardware
The Mathboard is a 
[Sweet 16](https://1upkeyboards.com/shop/keyboard-kits/macro-pads/sweet16-macro-pad-white/) macro pad from 1UP 
Keyboards. You must choose the 'Pro Micro 5V/16MHz' microcontroller when ordering it.

You should use OEM R2 keycaps, since the decals in `/hardware/keycaps/decals` are made for these specific keycaps. Their
shape also makes it easier to see the symbols printed on their front faces.

You must find your own way of printing the keycaps. I have been using a UV printer, but you can also use 
[waterslide decals](https://www.reddit.com/r/MechanicalKeyboards/comments/nncx59/how_to_diy_custom_print_keycaps_using_waterslide/),
or draw the symbols with a pen and covering the keys with clear lacquer. 

## Building and flashing the firmware
The newest firmware version can always be found in the [releases](https://github.com/nup002/Mathboard/releases). The releases also contain 
instructions on how to flash your Mathboard with the firmware.

If you wish to build the binaries yourself, for example after modifying the source files, you need to set up the 
build environment for QMK. This is not very difficult if you follow the 
[guide](https://docs.qmk.fm/#/newbs_getting_started). Once you've got the build environment set up, use the QMK CLI to
navigate to the `/firmware` and type `make`. 
