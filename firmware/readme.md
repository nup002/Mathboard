# Firmware resources

This folder contains everything related to the firmware of the Mathpad.

If you wish to get started with developing or modifying the Mathpad firmware, follow the 
[guide](https://docs.qmk.fm/#/newbs_getting_started) by QMK on how to get your development environment set up.

The Mathpad firmware is licensed under [GNU GENERAL PUBLIC LICENSE version 3](https://www.gnu.org/licenses/gpl-3.0.en.html).

## How to build the firmware
In `firmware` folder, run the following command:
```
make [LAYOUT=<layout>] [STICKY_MODIFIERS=<true|false>]
```

**Examples**

Compile the firmware for the default US ANSI keyboard layout:
```
make
```

Compile the firmware for Canadian French layout:
```
make LAYOUT=canadian_french
```

Compile the firmware for Dvorak layout with sticky modifier keys:
```
make LAYOUT=dvorak STICKY_MODIFIERS=true
```

For more detailed information, see [the official documentation](https://summa-cogni.github.io/Mathpad/#/firmware?id=compiling).

## What you CAN do:
- Use the firmware for any purpose
- Study how the firmware works
- Modify the firmware to suit your needs
- Share and distribute the original firmware
- Share and distribute your modified versions

## What you MUST do:
- Include a copy of the license with the firmware
- Keep all copyright notices intact
- Make the source code available when you distribute the firmware
- License any modifications you make under the same GPL-3.0 license
- Clearly mark any modifications you make to the original firmware
- If you distribute the firmware in executable form, you must make the complete source code available as well

## What you CANNOT do:
- Restrict others from exercising the rights granted by the license
- Incorporate the firmware into proprietary (closed-source) firmware
- Remove or alter the original license or copyright notices
- Use the firmware in a way that requires users to pay for the right to use it
- Prevent users from installing modified versions on their devices
- Use patents you hold to restrict users of the firmware
