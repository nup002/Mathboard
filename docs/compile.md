# Compiling the Mathpad firmware

Compiling transforms your modified code into firmware that your Mathpad can understand and use.

### Choose Your Keyboard Layout

The compilation process needs to know what keyboard layout your computer uses, since this affects how symbols are typed.

#### For US ANSI Layout (Most Common)
If your computer uses the standard US keyboard layout, you're all set! Just use the basic compile command.

#### For Other Layouts
1. **Find your layout:** Check the [QMK supported layouts list](https://docs.qmk.fm/reference_keymap_extras#header-files)
2. **Look for your layout:** In the "Sendstring LUT Header" column, find your layout
3. **Note the layout code:** Take the part after `sendstring_`. For example:
   - English UK → `sendstring_uk.h` → layout code is `uk`
   - German → `sendstring_german.h` → layout code is `german`

### Run the Compilation

1. **Open your terminal:** Use your regular terminal or QMK MSYS (Windows)

2. **Navigate to the firmware folder:**
   ```
   cd path/to/your/Mathpad/firmware
   ```

3. **Run the appropriate compile command:**

   **For US ANSI:**
   ```shell
   make
   ```

   **For other layouts:**
   ```shell
   make LAYOUT=<your_layout_code>
   ```

   **Example for UK layout:**
   ```shell
   make LAYOUT=uk
   ```

### What to Expect

**During compilation:**
- You'll see lots of text scrolling by - this is normal!
- First-time compilation takes longer (10-30 minutes)
- Subsequent compilations are faster (2-10 minutes)
- Your computer's fan might run faster due to the processing

**If successful:**
- You'll see a message like "Linking: summacogni_mathpad_mp1a_default.elf"
- A new file will appear in `Mathpad/firmware/compiled/`
- The file will be named something like `summacogni_mathpad_mp1a_<layout>.uf2`

**If there are errors:**
- Compilation will stop and show error messages
- Look for the first error message - it often explains the problem
- Common issues include missing commas, mismatched brackets, or typos in names

### Installing Your New Firmware

Once compilation succeeds:

1. **Locate your firmware file:** Go to `Mathpad/firmware/compiled/`
2. **Follow the flashing guide:** Use the instructions in [Update Firmware](/update_firmware.md) starting from Step 2
3. **Test thoroughly:** Make sure all your changes work as expected before making additional modifications
