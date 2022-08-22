# Mathboard

The Mathboard is a 4x4 macropad to make typing math on a computer easier for engineers and scientists. 
Follow its development on Hackaday: https://hackaday.io/project/186205-math-keyboard

With the Matboard you can type special characters, superscripts, subscripts, arrows, greek letters, and much more. The following equations are a few examples of what you can type directly with the Matboard:

<p style="text-align: center;"><font size="4"> 
E = mc²<br>
∛β ≫ ∯Ω(t)dt<br>
(A⊂B) ∧ (A⊂C) ⇔ A ⊂ (B ∪ C)
</font> </p>

The Mathboard lets you type the most common symbols used in algebra, calculus, set theory and logic. It also 
has common symbols of equivalence (≠, ≈, ∝, etc) and all greek letters, both lowercase and uppercase. 

## Compatibility
The mathboard works on Unix systems (including Apple Mac OS) and Windows.
When using the Mathboard on Windows, the open source application [WinCompose](https://github.com/samhocevar/wincompose) 
must be installed and running.

## Building and flashing the firmware
This repository contains the firmware for the Mathboard. You can download prebuilt binaries from the 
`/firmware/binaries` folder and flash them to the Mathboard using [QMK Toolbox](https://github.com/qmk/qmk_toolbox).

If you wish to build the binaries yourself, for example after modifying the source files, you need to set up the 
build environment for QMK. This is not very difficult if you follow the 
[guide](https://docs.qmk.fm/#/newbs_getting_started). Once you've got the build environment set up, use the QMK CLI to
navigate to the `/firmware` and type `make`. 
