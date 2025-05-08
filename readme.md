# Mathpad
<div align="center">
  <table border="0" cellspacing="0" cellpadding="0" style="border-collapse: collapse;">
    <tr>
      <td align="center" width="33%" style="border: none;">
        <a href="https://summa-cogni.github.io/Mathpad/#/">
          <img src=".github/images/documentation_banner.svg" alt="Documentation">
        </a><br>
        <p>Learn more about Mathpad with the 
        <a href="https://summa-cogni.github.io/Mathpad/#/">Official Documentation</a>.</p>
      </td>
      <td align="center" width="33%" style="border: none;">
        <a href="https://discord.gg/dgD6cMCUhD">
          <img src=".github/images/discord_banner.svg" alt="Discord">
        </a><br>
        <p>Chat with other users and ask your questions in the
        <a href="https://discord.gg/dgD6cMCUhD">Mathpad Discord</a>.</p>
      </td>
      <td align="center" width="33%" style="border: none;">
        <a href="https://x.com/SummaCogni">
          <img src=".github/images/x_banner.svg" alt="Twitter/X">
        </a><br>
        <p>Get the latest updates about Mathpad on
        <a href="https://x.com/SummaCogni">Twitter/X</a>.</p>
      </td>
    </tr>
  </table>
</div>
<p align="center">
<img src=".github/images/mathpad_prototype.jpg" width="300">
</p>

## What is it?
Mathpad helps you write equations on a computer. It is intended for engineers, 
scientists, students, and professionals in STEM fields who regularly need to write equations or who use 
mathematical symbols in their day to day work. 

With the Mathpad you can type 83 symbols from algebra, calculus, set theory, and 
logic, as well as all Greek letters including uppercase. The following equations are a few examples of what you can 
type directly with the Mathpad:

<p style="text-align: center;"><font size="4"> 
E = mc²<br>
∛β ≫ ∯Ω(t)dt<br>
(A⊂B) ∧ (A⊂C) ⇔ A ⊂ (B ∪ C)
</font> </p>



## Supported input methods
| Input mode                       | Supported |
|----------------------------------|-----------|
| Unicode plaintext                | ✅        |
| LaTeX                            | ✅        |
| Microsoft Office equation editor | ✅        |
| LibreOffice equation editor      | ❌        |

LibreOffice support is in development.

## Compatibility
Mathpad works on Windows, virtually all Unix systems, and Apple macOS. When using a Mathpad on Windows, the 
lightweight and open source application [WinCompose](https://github.com/samhocevar/wincompose) must be installed and running.
When using it on Apple macOS, you must enable Unicode Hex Input as a keyboard input source.

## Building and flashing the firmware
Official releases will be located in [releases](https://github.com/Summa-Cogni/Mathpad/releases). The firmware is under development 
and therefore no official release exists yet.

If you wish to build the firmwre binaries yourself, you need to set up the build environment for QMK. This is not very difficult 
if you follow the [guide](https://docs.qmk.fm/#/newbs_getting_started). Once you've got the build environment set up, use the QMK 
CLI to navigate to `/firmware` and type `make`. 

## Licenses
<p align="center">
<img src=".github/images/oshw_facts.svg" width="250">
</p>

Everyone is permitted to replicate the Mathpad based on the design files found in this repository. Everyone is
 permitted to modify, share, and distribute the files, as long as the terms set out in the licenses are respected.

The Summa Cogni logo and the Mathpad logo are the properties of Summacogni OÜ, and may not be replicated.

The OSHWA certification ID `UK000074` is issued to Summacogni OÜ, and may not be replicated.

## Certifications
Mathpad is certified by the Open Source Hardware Association.

<img src=".github/images/certification-mark-UK000074-wide.png" width="350">
