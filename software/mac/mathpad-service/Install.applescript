on run
	-- Get version from mathpad-service binary
	set installerVersion to getVersionFromBinary()
	
	try
		-- Welcome dialog
		set userChoice to display dialog "You are about to install Mathpad Service.

This is a small program allows your Mathpad to communicate with your Mac.

Click Install to continue." buttons {"Cancel", "Install"} default button 2 with title "Mathpad Service " & installerVersion & "" with icon note
		
		if button returned of userChoice is "Cancel" then
			my dismountAndQuit()
			return
		end if
		
		-- Set up paths for app installation
		set userHome to POSIX path of (path to home folder)
		set applicationsPath to userHome & "Applications/"
		set serviceLogPath to userHome & ".local/var/log/"
		set launchAgentPath to userHome & "Library/LaunchAgents/"
		
		set serviceAppPath to applicationsPath & "mathpad-service.app"
		set serviceBinary to serviceAppPath & "/Contents/MacOS/mathpad-service"
		set plistFile to launchAgentPath & "com.mathpad.service.plist"
		
		-- Get source app bundle path
		set appPath to path to me as string
		set appPOSIXPath to POSIX path of appPath
		set sourceAppPath to appPOSIXPath & "Contents/Resources/mathpad-service.app"
		
		-- Check if source app bundle exists
		try
			do shell script "test -d " & quoted form of sourceAppPath
		on error
			display dialog "Error: Mathpad Service app bundle not found in installer.

Expected location: " & sourceAppPath buttons {"OK"} default button 1 with title "Installation Error" with icon stop
			return
		end try
		
		-- Check for existing installation
		set isInstalled to false
		set isRunning to false
		
		try
			do shell script "test -d " & quoted form of serviceAppPath
			set isInstalled to true
		end try
		
		try
			do shell script "pgrep -f mathpad-service"
			set isRunning to true
		end try
		
		-- Handle existing installation
		if isInstalled then
			set dialogMessage to ""
			set buttonOptions to {}
			
			if isRunning then
				set dialogMessage to "Mathpad Service is already installed and running.

What would you like to do?"
				set buttonOptions to {"Cancel", "Stop & Uninstall", "Reinstall"}
			else
				set dialogMessage to "Mathpad Service is already installed but not running.

What would you like to do?"
				set buttonOptions to {"Cancel", "Uninstall", "Reinstall"}
			end if
			
			set userChoice to display dialog dialogMessage buttons buttonOptions default button (count of buttonOptions) with title "Existing Installation Found" with icon caution
			
			set chosenAction to button returned of userChoice
			
			if chosenAction is "Cancel" then
				my dismountAndQuit()
				return
			else if chosenAction is "Stop & Uninstall" or chosenAction is "Uninstall" then
				-- Unload LaunchAgent
				try
					do shell script "launchctl unload " & quoted form of plistFile
				end try
				
				-- Stop running service
				try
					do shell script "pkill -f mathpad-service"
				end try
				
				-- Remove files
				try
					do shell script "rm -rf " & quoted form of serviceAppPath
					do shell script "rm -f " & quoted form of plistFile
					do shell script "rm -f /tmp/mathpad_service.pid"
					do shell script "rm -rf " & quoted form of serviceLogPath
				on error errMsg
					display dialog "Uninstall encountered some issues: " & errMsg buttons {"OK"} with icon caution
				end try
				
				display dialog "Mathpad Service has been uninstalled successfully." buttons {"OK"} default button 1 with title "✅ Uninstall Complete" with icon note
				my dismountAndQuit()
				return
			else
				-- Continue with reinstall - properly stop service first
				try
					do shell script "launchctl unload " & quoted form of plistFile
				on error
					-- LaunchAgent might not be loaded, continue
				end try
				
				try
					do shell script "pkill -f mathpad-service"
					-- Wait for process to fully terminate
					delay 2
					-- Verify it's stopped
					try
						do shell script "pgrep -f mathpad-service"
						-- If we get here, process is still running
						display dialog "Warning: Could not stop the running service. The old version may remain active until you restart your Mac." buttons {"Continue Anyway", "Cancel"} default button 2 with title "Service Still Running" with icon caution
						if button returned of result is "Cancel" then
							my dismountAndQuit()
							return
						end if
					on error
						-- Process is stopped, good to continue
					end try
				on error
					-- No running process to kill, continue
				end try
				
				-- Remove old app to ensure clean install
				try
					do shell script "rm -rf " & quoted form of serviceAppPath
				on error
					-- File might not exist or be locked, continue
				end try
				
				-- Attempt to reset accessibility permissions for clean reinstall
				set permissionReset to false
				try
					do shell script "tccutil reset Accessibility com.mathpad.mathpad-service"
					set permissionReset to true
				on error errMsg
					-- tccutil failed - likely needs admin privileges or unsupported macOS version
				end try
			end if
		end if
		
		-- Create directories (no admin required)
		try
			do shell script "mkdir -p " & quoted form of applicationsPath & " " & quoted form of serviceLogPath & " " & quoted form of launchAgentPath
		on error errMsg
			display dialog "Failed to create directories: " & errMsg buttons {"OK"} with icon stop
			return
		end try
		
	-- Install app bundle
	try
		do shell script "cp -R " & quoted form of sourceAppPath & " " & quoted form of serviceAppPath
		do shell script "chmod +x " & quoted form of serviceBinary
	
	on error errMsg
		display dialog "Failed to install service app: " & errMsg buttons {"OK"} with icon stop
		return
	end try
		
		-- Create LaunchAgent plist for auto-start
		set plistContent to "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">
<plist version=\"1.0\">
<dict>
    <key>Label</key>
    <string>com.mathpad.service</string>
    <key>ProgramArguments</key>
    <array>
        <string>" & serviceBinary & "</string>
    </array>
    <key>RunAtLoad</key>
    <true/>
    <key>KeepAlive</key>
    <dict>
        <key>SuccessfulExit</key>
        <false/>
    </dict>
    <key>StandardOutPath</key>
    <string>" & serviceLogPath & "mathpad-service.log</string>
    <key>StandardErrorPath</key>
    <string>" & serviceLogPath & "mathpad-service.error.log</string>
</dict>
</plist>"
		
		try
			do shell script "echo " & quoted form of plistContent & " > " & quoted form of plistFile
		on error errMsg
			display dialog "Failed to create LaunchAgent: " & errMsg buttons {"OK"} with icon stop
			return
		end try
		
		-- PERMISSION CONFIRMATION DIALOG (NEW SECTION)
		set permissionMessage to "Next, Mathpad Service needs to start and obtain a permission from macOS.

When you click \"Start Service\", you will see a system dialog asking for 'Accessibility Access' permission.

This permission is required for your Mathpad to inject Unicode characters into applications."

		-- Add reinstall-specific message if this was a reinstall
		if isInstalled then
			if permissionReset then
				set permissionMessage to permissionMessage & "

✅ Old accessibility permissions have been automatically cleared. You will need to grant permission for the new version."
			else
				set permissionMessage to permissionMessage & "

⚠️ Since this is a reinstall, you MUST grant permission again even if you previously had it enabled. You may need to manually remove the old entry from System Preferences > Security & Privacy > Privacy > Accessibility first."
			end if
		end if

		set permissionMessage to permissionMessage & "

Are you ready to grant this permission?"

		set permissionChoice to display dialog permissionMessage buttons {"Cancel Installation", "Start Service"} default button 2 with title "✅ Files installed successfully" with icon note
		
		if button returned of permissionChoice is "Cancel Installation" then
			-- Clean up installed files since user cancelled
			try
				do shell script "rm -rf " & quoted form of serviceAppPath
				do shell script "rm -f " & quoted form of plistFile
			end try
			
			display dialog "Installation cancelled. Files have been cleaned up." buttons {"OK"} default button 1 with title "Installation Cancelled" with icon note
			my dismountAndQuit()
			return
		end if
		
		-- User confirmed they're ready, now start the service
		try
			-- Load and start the service (this will trigger permission request if not already granted)
			do shell script "launchctl load " & quoted form of plistFile
			
			-- Give service a moment to start
			delay 2
			
			-- Now ask user to confirm they've granted permissions
			set permissionConfirm to display dialog "Mathpad Service has started and should have requested permission.

Please grant the permission 'Accessibility Access'.

If you haven't seen the permission dialog yet, it may be behind this dialog." buttons {"I could not grant permission", "I have granted the permission"} default button 2 with title "Grant Permission" with icon note
			
			if button returned of permissionConfirm is "I could not grant permission" then
				set takeThereDialog to display dialog "You must go to System Preferences → Security and Privacy → Privacy and manually grant permission.
Add 'mathpad-service' to Accessibility." buttons {"Take me there", "OK"} default button 1 with title "Permission Needed" with icon caution
				
				-- Handle the "Take me there" button click
				if button returned of takeThereDialog is "Take me there" then
					-- Use shell command to open System Preferences without AppleScript automation
					try
						do shell script "open 'x-apple.systempreferences:com.apple.preference.security'"
					on error
						-- Fallback: just open System Preferences
						do shell script "open '/System/Applications/System Preferences.app'"
					end try
				end if
				
				my dismountAndQuit()
				return
			end if
			
		on error errMsg
			display dialog "Service installed but failed to start: " & errMsg buttons {"OK"} with icon caution
		end try
		
		-- Check if service is running after permissions should be granted
		try
			do shell script "pgrep -f mathpad-service"
			set isRunning to true
		on error
			set isRunning to false
		end try
		
		-- Final status message
		if isRunning then
			set finalMessage to "Your Mathpad is now ready to be used.

Remember to set the OS Switch on the back of your Mathpad to the 'MAC' position."
		else
			set finalMessage to "⚠️ Installation complete, but service verification failed.

This might mean:
	• Permission was not fully granted
	• The service needs a restart

Please check:
1. System Preferences > Security & Privacy > Privacy
2. Ensure Accessibility shows Mathpad Service as enabled
3. Restart your computer if needed

Mathpad Service should work once permission is properly set."
		end if
		
		display dialog finalMessage buttons {"Done"} default button 1 with title "✅ Installation Complete" with icon note
		
		my dismountAndQuit()
		
	on error errMsg
		display dialog "Installation failed: " & errMsg buttons {"OK"} with icon stop
		my dismountAndQuit()
	end try
end run


-- Handler to get version from mathpad-service binary
on getVersionFromBinary()
	try
		-- Get the path to the mathpad-service binary inside the app bundle
		set appPath to path to me as string
		set appPOSIXPath to POSIX path of appPath
		set sourceBinaryPath to appPOSIXPath & "Contents/Resources/mathpad-service.app/Contents/MacOS/mathpad-service"
		
		-- Run the binary with --version flag and capture output
		set versionOutput to do shell script quoted form of sourceBinaryPath & " --version 2>/dev/null | head -1"
		
		-- Extract version number from "Mathpad Service vX.X.X" format
		set versionString to ""
		if versionOutput contains "Mathpad Service v" then
			set AppleScript's text item delimiters to "Mathpad Service v"
			set versionParts to text items of versionOutput
			if (count of versionParts) > 1 then
				set versionString to item 2 of versionParts
				-- Clean up any extra text after the version number
				set AppleScript's text item delimiters to " "
				set versionParts to text items of versionString
				set versionString to item 1 of versionParts
			end if
			set AppleScript's text item delimiters to ""
		end if
		
		-- Fallback to default version if extraction failed
		if versionString is "" then
			set versionString to "1.0.0"
		end if
		
		return versionString
		
	on error errMsg
		-- Fallback to default version if binary execution failed
		return "1.0.0"
	end try
end getVersionFromBinary

-- Handler to dismount DMG and quit
on dismountAndQuit()
	-- Removed broken autodismount code
	tell me to quit
end dismountAndQuit