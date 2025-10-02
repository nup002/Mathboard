# Compatibility

Mathpad is a [QMK](https://docs.qmk.fm)-based keypad that works on nearly all operating systems and with all 
Latin-based keyboard layouts. This page explicitly defines these compatibilities to help you determine if Mathpad 
will work with your setup.

# Operating Systems

Mathpad works on:
 - **Windows 10 and 11** with [WinCompose](#/software-download?id=wincompose) installed
 - **Mac** with [Mathpad Service](#/software-download?id=mathpad-service) installed (requires accessibility permissions)
 - **Linux distros with IBus** (includes Ubuntu, Debian, Fedora, CentOS, Raspbian, and many more)

>[!TIP]
>If you cannot install WinCompose, for example due to not having administrator rights, you can use the 
>[portable executable](https://github.com/samhocevar/wincompose/releases/download/v0.9.10/WinCompose-NoInstall-0.9.10.zip) instead.
>

# Fonts
Mathpad outputs Unicode mathematical symbols that may not display correctly if your system fonts don't include the 
necessary character definitions. This can result in:
 - Missing symbols showing as empty boxes (□)
 - Symbols appearing as question marks (?)
 - Fallback to basic ASCII characters
 - Inconsistent symbol rendering across applications

## Recommended Fonts
For best compatibility, ensure your system has fonts that include mathematical Unicode blocks:
 - Windows: Cambria Math, Segoe UI Symbol (usually pre-installed)
 - MacOS: SF Pro, Menlo, Monaco (usually pre-installed)
 - Linux: DejaVu Sans, Liberation fonts, or install `fonts-symbola` package

## Testing Font Coverage
To test if your fonts support mathematical symbols:
 - Try typing or pasting these characters: ∑ ∫ ∞ ≤ ≥ ≠ ± √ π
 - If you see boxes or question marks, you may need to install additional fonts
 - Different applications may use different fonts, so test in your intended software

# Supported Keyboard Layouts

Mathpad requires that the computer uses a **Latin-based keyboard layout**. This means layouts that use the 
Latin alphabet (A-Z) as their primary character set, as opposed to Cyrillic, Arabic, Chinese, or other 
non-Latin scripts. The layout can include additional accented characters and symbols, but the base alphabet must be 
Latin.

### North America
 - US ANSI (Standard layout in the USA)
 - English (US International)
 - Canadian Multilingual (CSA)
 - French (Canada)

### United Kingdom & Ireland
 - English (UK)

### Western Europe
 - Danish
 - Dutch (Belgium)
 - Finnish
 - French
 - French (AFNOR)
 - French (BÉPO)
 - French (Switzerland)
 - French (macOS, ISO)
 - German
 - German (Switzerland)
 - German (macOS)
 - Icelandic
 - Italian
 - Italian (macOS, ANSI)
 - Italian (macOS, ISO)
 - Norwegian
 - Portuguese
 - Portuguese (macOS, ISO)
 - Spanish
 - Swedish

### Eastern Europe
 - Croatian
 - Czech
 - Czech (macOS, ANSI)
 - Czech (macOS, ISO)
 - Estonian
 - Hungarian
 - Latvian
 - Lithuanian (ĄŽERTY)
 - Lithuanian (QWERTY)
 - Romanian
 - Serbian (Latin)
 - Slovak
 - Slovenian

### Other Regions
 - Portuguese (Brazil)
 - Spanish (Latin America)
 - Japanese
 - Turkish (F)
 - Turkish (Q)

### Alternative Layouts
Mathpad also supports these non-QWERTY layouts:
 - Colemak  
 - Dvorak   
 - Dvorak (French)  
 - Dvorak (Spanish)
 - Dvorak (Programmer)  
 - Norman   
 - Plover (Dvorak)
 - Workman  
 - Workman (ZXCVM)

## If your Latin keyboard layout is not on the list of supported layouts
It is possible that there exist certain Latin-based layouts that are not supported by Mathpad. In that case you have 
two options:
1) Install the Mathpad firmware version for whatever layout is the most similar to yours and hope it works
2) Add your layout as a [Sendstring LUT header file](https://docs.qmk.fm/reference_keymap_extras#header-files) to the
 QMK repository. Once your Pull Request has been accepted, request a new firmware build on the 
 [Mathpad forum](https://www.summacogni.com/forum/viewforum.php?f=3&sid=c0af401a0636b960e1b51769f60db79d).

## Unsupported Layouts

If you use an unsupported keyboard layout (non-Latin scripts like Arabic, Cyrillic, Chinese, etc.), Mathpad simply will 
not function. The reason is that Mathpad sends symbols in their Unicode representation, which **requires** that 
the letters A, B, C, D, E, and F can be typed.

## How to Check Your Layout

### Windows
1. Right-click the language indicator in the system tray (usually shows "ENG" or similar)
2. Select "More keyboard settings"
3. Your current keyboard layout is shown under "Preferred languages"

### MacOS
1. Go to System Preferences > Keyboard > Input Sources
2. Your active layout is shown in the left panel
3. You can also check the input menu in the menu bar (flag icon)

### Linux
1. Open System Settings > Region & Language (Ubuntu/GNOME)
2. Or run `setxkbmap -query` in terminal to see current layout
3. The layout name will be shown in the "layout" field

## Known Issues

### Windows
- WinCompose must be running 

### Mac
- Mathpad Service must be running
- Mathpad Service must have been granted Accessibility and Input Monitoring permissions
- On some macOS versions, certain mathematical symbols may require manual font installation


### Linux
- IBus must be properly configured and running
- Some minimal Linux distributions may require additional Unicode font packages
- Wayland vs X11 display servers may affect dead key behavior

### General
- Some virtualized environments (VMs, remote desktop) may have reduced symbol support
