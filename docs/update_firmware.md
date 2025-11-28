# Updating the Firmware

Firmware is the code that runs on the processor inside the Mathpad. You must sometimes update this firmware, 
for example when:
- You set up your Mathpad for the first time
- You change the keyboard layout on your computer
- You want to use a feature in a new firmware release
- You make your own modifications to the firmware

> [!TIP|label: Get your current firmware version]
> In a text editor, keep all the modifier keys ([R], [C] and [B]) pressed for at least 5 seconds, then release them.
> Your Mathpad will type a lot of information about itself, including its firmware version.
> 

**Updating the Mathpad firmware is safe and very simple**. It requires no previous experience or special 
tools. Just follow these three steps:

### Step 1: Download your firmware
Head over to the [Firmware Download](firmware-download.md) page and download the firmware that matches your keyboard 
layout.

### Step 2: Put your Mathpad in firmware upload mode
With your Mathpad plugged in, flip it over and use something long and thin (e.g. a pen) to press the 
Restart button for at least half a second, then release it. The Restart button is located here:

<img src="_media/bottom_labelled.svg" style="width: 100%; max-width: 500px;">

### Step 3: Drag and drop the firmware file
When you release the Restart button, a folder named `RPI-RP2` with a two files inside should appear automatically on 
your computer. Grab the firmware file you just downloaded, and drag-and-drop (or copy-paste) it to the `RPI-RP2` 
folder. Once the file has been transferred, the folder will close automatically. You're done!

> [!TIP|label:No RPI-RP2 folder]
> If the `RPI-RP2` folder does not appear, try keeping the Restart button pressed longer before releasing it. You 
> should also look under "This PC" on Windows, or "Computer" on Mac.
>

> [!TIP]
> The Mathpad is **not** a storage device like a USB memory stick - do not expect to find the firmware file in the 
> `RPI-RP2` folder after you have uploaded it.
>
