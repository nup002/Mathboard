Mathboard V1 assembly manual
=========================
This documentation is intended for those who wish to build their own Mathboard V1. If you are instead looking for
documentation on how to use the Mathboard, see :ref:`user_manual`.

Required tools and equipment
############################
The Mathboard is a very simple device that should be possible to build by nearly anyone. The following two lists
tells you everything you need to assemble your own. The next sections will go into further detail on the items that
need it.

**Components** :

* 1x Mathboard PCB
* 16x `Gateron KS-33 Low Profile v2 switches <https://www.gateron.co/products/gateron-low-profile-mechanical-switch-set>`_
* 1x `0xCB Helios RP2040 microcontroller <https://github.com/0xCB-dev/0xCB-Helios>`_
* 1x `WS2812 or WS2812B addressable LED <https://www.sparkfun.com/products/24837>`_
* 1x 3D-printed Mathboard case (bottom, lid, and LED diffuser)
* 16x 3D-printed keycap risers
* 12x blank white 1u OEM R2 keycaps
* 2x 1u keycaps of your choice
* 2x 1.5u keycaps of your choice
* 3x self-tapping M2.2 x 6mm screws
* 4x rubber feet. Maximum footprint: 1cm x 1cm.
* 1x USB-C cable

**Tools and supplies** :

* A UV printer. This may be hard to find, inquire with makerspaces or fablabs near you.
* A 3D printer, for printing the case, LED diffuser, keycap spacers, and UV printing fixtures.
* White PLA filament for the LED diffuser.
* Any color PLA filament, for the case, spacers, and UV printing fixtures
* A screwdriver, to insert the screws that hold the case together
* A soldering iron (plus solder) to solder the keyboard switches, the microcontroller, and the LED
* A wire clipper, to cut the microcontroller pins short after soldering
* Cyanoacrylate glue (AKA super glue), for gluing the LED diffuser to the case lid.

Mathboard V1 PCB
----------------
The mathboard V1 PCB can be manufactured by any electronics prototyping company. I have previously used JLCPCB,
and a correctly formatted Bill of Materials [BOM] file for use with them is provided in the Mathboard repository.

You can order the PCB pre-assembled with most of the components already soldered on, but some must still be soldered
by hand. These include the 16 keyswitches, the microcontroller, and the status LED. These components are all
through-hole mounted and are simple to solder. However, the status LED is surface-mounted [SMD]. If you have not
previously soldered SMD components, you may have some difficulty with this component. Luckily, it is not mandatory.

TODO: Add images of the PCB

3D printed components
---------------------
The Mathboard is designed with 3D printing in mind, and it should be possible to produce its parts with any filament
extrusion 3D printer. It may also be possible to use a resin printer, but I have not tried that. I recommend printing
the Mathboard in PLA, but you can probably use other materials as well.

You don't need any special slicer or printer settings for the Mathboard case: All three parts, meaning the bottom,
lid, and diffuser, should print fine with default settings.

The keycap risers are very small components with tight tolerances, and may require some tuning to print correctly. I
have personally had success with the following settings:

* Layer height : 0.2mm
* Skirt : Yes
* Speed : 20% of normal

Keycaps and UV printing
--------------------------
Blank keycaps can be purches from many sources. For the symbol keys you *must* use 1u OEM R2 keycaps, such as
`these <https://ymdkey.com/products/customized-1x-r1-r2-r3-r4-blank-thick-pbt-oem-profile-alphanumeric-keycaps-for-keycap-diy?variant=39374782234685>`_.
For the other keys you are free to choose which keycaps you prefer. You will need :

* A 1u keycap for the mode switch key
* A 1u keycap for the left modifier key
* Two 1.5u keycaps for the bottom modifier keys

TODO: Add images pointing out key positions

The most challenging aspect of building your own Mathboard is getting the symbols onto the 12 symbol keys. This is done
by UV printing, which prints the symbols onto the keys with special UV-curing ink. A UV printer is expensive and
requires regular maintenance, so it is not a common device. You may be able to find one if you inquire with local
makerspaces, fab-labs, or printing services.

Self-tapping screws
-------------------
Any type of self-tapping screws may be used. Self-tapping screws are also know as thread-forming or self-drilling
screws. Three are used in the Mathboard to assemble the case. Their dimensions must conform to the following
requirements:

* Length (measured from bottom of head) : 3mm to 6.8mm
* Thread diameter : 2mm to 2.5mm
* Head diameter : 2mm to 4mm

It is recommended to use M2.2 x 6.5mm screws if you can find them, for example
`these <https://www.amazon.com/uxcell-M2-2x6-5mm-Phillips-Tapping-Screws/dp/B01EHP3HLC>`_.