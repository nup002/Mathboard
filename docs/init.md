# Initial Setup

**Mathpad works straight out of the box in many cases.** But depending on your operating system and keyboard layout, 
there are a few initial tasks that may have to be performed. Follow this short guide to get your Mathpad up and running.

## What operating system do you use?

<!-- tabs:start -->
#### **Mac**

1) Install [Mathpad Service](https://github.com/Summa-Cogni/Mathpad/releases/download/mathpad-service-v1.0.0/mathpad-service-1.0.0.dmg) - this small application enables Mathpad to insert Unicode symbols on Mac.
2) Set the OS switch on the back of your Mathpad to the MAC position



#### **Windows**

1) Install [WinCompose](http://wincompose.info) - this enables special character input on Windows
2) Set the OS switch on the back of your Mathpad to the WINDOWS position

> [!TIP]
> If you cannot install WinCompose, for example if your computer is managed by an IT department and you 
> lack administrator rights, use the [portable executable](https://github.com/samhocevar/wincompose/releases/download/v0.9.10/WinCompose-NoInstall-0.9.10.zip).
> 
> 


#### **Linux**

1) Set the OS switch on the back of your Mathpad to the LINUX position

There's no software to install on Linux, as most distros have built-in support for Unicode input.
> 
<!-- tabs:end -->


> [!NOTE|label:Why Setting The OS Switch Is Required]
> Mathpad transmits symbols using Unicode. Since each operating system handles Unicode input differently, Mathpad needs 
> to adjust its data format based on the connected operating system. USB devices like Mathpad cannot detect your 
> computer's operating system automatically, so you must specify it with the OS switch.
> 
> 
## What is your keyboard layout?
<!-- tabs:start -->

#### **US ANSI (standard layout in USA)**

You're good to go! Mathpad supports US ANSI out of the box. You can move on to [Getting Started](/get_started.md).

> [!TIP]
> You may still want to update your Mathpad's firmware to the newest version to benefit from 
> new features and bugfixes. Do so by following the instructions in the [Firmware Update Guide](update_firmware.md).
> 

#### **Any other layout**

**You must update your Mathpad's firmware to match your computer's keyboard layout.** 
1) Follow the instructions in the [Firmware Update Guide](update_firmware.md)
2) Once you've updated your Mathpad's firmware, move on to [Getting Started](/get_started.md).

> [!TIP]
>Your keyboard layout is usually defined in the "Input devices" or "Language and Region" settings. Check out this 
> [guide](/compatibility.md#how-to-check-your-layout) if you need some extra help.
> 
<!-- tabs:end -->

> [!NOTE|label:Why Layout Matching Is Required]
>Your Mathpad's firmware must match your computer's keyboard layout. This is necessary because operating systems 
> interpret keyboard signals differently based on layout settings, and USB devices like Mathpad cannot detect your 
> computer's layout automatically. 
> 
> Keyboards do not send actual letters. Instead they send 'keycodes' which are interpreted into symbols by the 
> OS. When a Norwegian keyboard user clicks the key for 'å', the letter 'å' is never sent. Instead, the keyboard sends 
> the keycode for 'left bracket' (`[`) which is then interpreted as 'å' by the OS.
