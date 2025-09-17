# Firmware prerequisites
Mathpad has been designed to make modifications easy, so that you can change its behaviour to suit your specific needs. 
Before you begin making changes to the firmware, make sure you have:

### 1) Required Knowledge
- Basic familiarity with using a command line terminal (opening it, navigating folders, running commands)
- Understanding of file and folder structures on your computer

### 2) Required Software
- **Git**: A version control system needed to download the Mathpad code
  - What it does: Allows you to download and manage code repositories from GitHub
  - Install from: [Git Installation Guide](https://github.com/git-guides/install-git)
- **A text editor**: For viewing and editing code files
  - Recommended: Visual Studio Code (free), Notepad++, or any code editor you prefer
  

## Setting Up Your Development Environment

This section will help you download the Mathpad code and set up the tools needed to modify and compile it.

### Step 1: Download the Mathpad Code
We'll use Git to "clone" (download) the Mathpad repository (code collection) to your computer.

1. Open a command line terminal:
   - **Windows**: Press `Win + R`, type `cmd`, press Enter
   - **Mac**: Press `Cmd + Space`, type "Terminal", press Enter
   - **Linux**: Press `Ctrl + Alt + T`

2. Navigate to where you want to store the Mathpad files. For example:
   ```
   cd Desktop
   ```

3. Download the Mathpad repository:
   ```
   git clone https://github.com/Summa-Cogni/Mathpad.git
   ```

**What you should see:** Git will show progress as it downloads files. This may take 5-10 minutes since it also 
downloads QMK (a large codebase).

**If successful:** You'll see a new folder called "Mathpad" in your chosen location.

### Step 2: Install the QMK Build Environment
QMK is the underlying system that powers Mathpad. You need to install its build tools.

1. Follow the '[Prepare Your Build Environment](https://docs.qmk.fm/newbs_getting_started#set-up-your-environment)' guide from the QMK documentation
2. This will install the necessary compilers and tools for your operating system


### Step 3: Connect QMK to Your Mathpad Files

>[!TIP]
> **Windows users:** You must use the `QMK MSYS` terminal for all `qmk` commands from here on. Find it in your Start 
> menu after installing QMK. It may take a while to fully start. You should see something like 
> `[username@pc_name ~]$` when it's ready.
> 

1. Open your terminal (or QMK MSYS on Windows)

2. Run QMK setup and tell it where to find your Mathpad files:
   ```
   qmk setup -H <path to your Mathpad QMK folder>
   ```

3. **Find your path:** The path should point to the QMK folder inside your downloaded Mathpad files. For example:
   - Windows: `qmk setup -H "C:\Users\YourName\Desktop\Mathpad\firmware\qmk_firmware"`
   - Mac/Linux: `qmk setup -H "/Users/YourName/Desktop/Mathpad/firmware/qmk_firmware"`

**What you should see:** QMK will configure itself and show a success message.

**Verify it worked:** Try running `qmk doctor` - it should report that everything is set up correctly.


## Troubleshooting

### Common Issues and Solutions

#### Git/Download Problems
**Problem:** "git: command not found"
- Install Git from the [official website](https://git-scm.com/downloads)
- Add Git to your system Path (many guides available online)

#### Setup Issues
**Problem:** QMK setup fails on Windows
- **Solution:** Make sure you're using the QMK MSYS terminal, not regular Command Prompt

**Problem:** "qmk: command not found"
- **Solution:** Restart your terminal after installing QMK, or reinstall QMK following their guide