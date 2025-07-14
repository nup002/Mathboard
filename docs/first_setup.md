**Mathpad works straight out of the box in many cases.** But depending on your operating system and keyboard layout, 
there are a few initial tasks that may have to be performed. Follow this short guide to get your Mathpad up and running.

## What is your operating system?

<!-- tabs:start -->

#### **Linux**

Set the OS switch on the back of your Mathpad to the LINUX position

#### **Mac OS**

1) Go to System Preferences → Keyboard → Input Sources
2) Add Unicode Hex Input to the list (under Other) and activate it from the input dropdown in the menu bar
3) Set the OS switch on the back of your Mathpad to the MAC OS position

> [!NOTE]
> This may disable some Option-based shortcuts such as Option+Left and Option+Right.
> 

#### **Windows**

1) Install [WinCompose](http://wincompose.info) - this enables special character input on Windows
2) Set the OS switch on the back of your Mathpad to the WINDOWS position
3) 
> [!TIP]
> If you cannot install WinCompose, for example if your computer is managed by at IT department and you 
> lack administrator rights, use the [portable executable](https://github.com/samhocevar/wincompose/releases/download/v0.9.11/WinCompose-Setup-0.9.11.exe).
> 
> 
<!-- tabs:end -->

> [!NOTE|label:Why Setting The OS Switch Is Required]
> Mathpad transmits symbols using Unicode. Since each operating system handles Unicode input differently, Mathpad needs 
> to adjust its data format based on the connected operating system. USB devices like Mathpad cannot detect your 
> computer's operating system automatically, so you must specify it with the OS switch.
> 


## What is your keyboard layout?
<!-- tabs:start -->

#### **US ANSI (standard layout in USA)**

You're good to go! Mathpad supports US ANSI out of the box. You can move on to [Getting Started](/get_started.md).

#### **Any other layout**

You must update the firmware of your Mathpad to match the keyboard layout of your computer.

If you do not know your keyboard layout, you can follow the short guide in 
[compatibility](/compatibility.md#how-to-check-your-layout). Your keyboard layout is usually defined in the 
"Input devices" or "Language and Region" settings.

Once you know your keyboard layout, follow these steps to update your Mathpad's firmware:

1. Go to the [releases page](firmware_releases.md) and download the firmware file that matches your keyboard layout
2. Follow the instructions in the [Firmware Update Guide](update_firmware.md)

Once you're done, head over to [Getting Started](/get_started.md).

<!-- tabs:end -->

> [!NOTE|label:Why Layout Matching Is Required]
>Your Mathpad's firmware must match your computer's keyboard layout. This is necessary because operating systems 
> interpret keyboard signals differently based on layout settings, and USB devices like Mathpad cannot detect your 
> computer's layout automatically. 
> 
> Keyboards do not send actual letters. Instead they send 'keycodes' which are interpreted into symbols by the 
> OS. When a Norwegian keyboard user clicks the key for 'å', the letter 'å' is never sent. Instead, the keyboard sends 
> the keycode for 'left bracket' (`[`) which is then interpreted as 'å' by the OS.
