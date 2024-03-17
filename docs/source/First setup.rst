.. _first_setup:
First setup of the Mathboard
============================
The Mathboard *almost* works straight out of the box, but there are some initial setup tasks that must be performed.
These tasks will depend on the computer that you intend to use the Mathboard with.

Software
########
If you intend to use the Mathboard on an Apple Mac or any Linux-based operating system, you can skip to the next
section.

Windows does not natively support Unicode input, which
the Mathboard relies extensively on. If you intend to use the Mathboard on a Windows computer, you must therefore first
install the lightweight application `WinCompose <http://wincompose.info>`_, which provides support for Unicode input.

Firmware
########
The firmware of the Mathboard must match the keyboard layout of the computer on which you intend to use it with.
This is a consequence of both how operating systems interpret keycodes from keyboards, and the inability of the
Mathboard to automatically deduce the keyboard layout of the computer it is plugged in to.

You must therefore upload, or "flash", a version of the firmware that matches your keyboard layout. Start by figuring
out your keyboard layout (google can help you here). Then go to the
`latest release <https://github.com/nup002/Mathboard/releases/tag/v0.0.1>`_ and download the firmware file for your
keyboard layout. Then, plug in the Mathboard and press the reset button (found on the bottom) for at least
half a second. When you release the reset button, a folder will open on your computer. Place the firmware file
in this folder to flash it to the Mathboard. The folder will automatically close when finished, and the Mathboard will
reboot. Done!

.. warning::
    This instruction is not currently valid since the Mathboard is not fully released yet. For now, you must build
    your own firmware.

Setting the OS switch
#####################
Each operating system [OS] interprets Unicode input differently. The Mathboard must therefore be adjusted to
output Unicode that the OS can understand. Using the illustration on the bottom of the Mathboard, place the OS switch on
the back of the Mathboard to the OS your computer is running.