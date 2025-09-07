-- Mathpad Service Installer
-- Save this as an Application in Script Editor

on run
	set installerVersion to "1.3.0"

	try
		-- Welcome dialog
		set userChoice to display dialog "You will now install Mathpad Service.

This is a small program that is required for your Mathpad to communicate with your Mac.

Click Install to continue." buttons {"Cancel", "Install"} default button 2 with title "Mathpad Service " & installerVersion & "" with icon note

		if button returned of userChoice is "Cancel" then
			tell me to quit
			return
		end if

		-- Set up user-specific paths (no admin required)
		set userHome to POSIX path of (path to home folder)
		set serviceBinPath to userHome & ".local/bin/"
		set serviceLogPath to userHome & ".local/var/log/"
		set launchAgentPath to userHome & "Library/LaunchAgents/"

		set serviceBinary to serviceBinPath & "mathpad-service"
		set startupScript to serviceBinPath & "start-mathpad-service"
		set plistFile to launchAgentPath & "com.mathpad.service.plist"

		-- Get source binary path
		set appPath to path to me as string
		set appPOSIXPath to POSIX path of appPath
		set sourceBinaryPath to appPOSIXPath & "Contents/Resources/mathpad-service"

		-- Check if source binary exists
		try
			do shell script "test -f " & quoted form of sourceBinaryPath
		on error
			display dialog "Error: Mathpad Service binary not found in application bundle.

Expected location: " & sourceBinaryPath buttons {"OK"} default button 1 with title "Installation Error" with icon stop
			return
		end try

		-- Check for existing installation
		set isInstalled to false
		set isRunning to false

		try
			do shell script "test -f " & quoted form of serviceBinary
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
				tell me to quit
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
					do shell script "rm -f " & quoted form of serviceBinary
					do shell script "rm -f " & quoted form of startupScript
					do shell script "rm -f " & quoted form of plistFile
					do shell script "rm -f /tmp/mathpad_service.pid"
					do shell script "rm -rf " & quoted form of serviceLogPath
				on error errMsg
					display dialog "Uninstall encountered some issues: " & errMsg buttons {"OK"} with icon caution
				end try

				display dialog "Mathpad Service has been uninstalled successfully." buttons {"OK"} default button 1 with title "✅ Uninstall Complete" with icon note
				tell me to quit
				return
			else
				-- Continue with reinstall
				try
					do shell script "launchctl unload " & quoted form of plistFile
					do shell script "pkill -f mathpad-service"
				end try
			end if
		end if

		-- Create directories (no admin required)
		try
			do shell script "mkdir -p " & quoted form of serviceBinPath & " " & quoted form of serviceLogPath & " " & quoted form of launchAgentPath
		on error errMsg
			display dialog "Failed to create directories: " & errMsg buttons {"OK"} with icon stop
			return
		end try

		-- Install binary
		try
			do shell script "cp " & quoted form of sourceBinaryPath & " " & quoted form of serviceBinary
			do shell script "chmod +x " & quoted form of serviceBinary
		on error errMsg
			display dialog "Failed to install service binary: " & errMsg buttons {"OK"} with icon stop
			return
		end try

		-- Create startup script
		set startupScriptContent to "#!/bin/bash
LOG_PATH=\"" & serviceLogPath & "mathpad-service.log\"
ERROR_LOG_PATH=\"" & serviceLogPath & "mathpad-service.error.log\"
PID_FILE=\"/tmp/mathpad-service.pid\"

if pgrep -f \"mathpad-service\" > /dev/null; then
    echo \"Mathpad service is already running\"
    exit 0
fi

echo \"Starting Mathpad service...\"
nohup \"" & serviceBinary & "\" > \"$LOG_PATH\" 2> \"$ERROR_LOG_PATH\" &
SERVICE_PID=$!
echo $SERVICE_PID > \"$PID_FILE\"
echo \"Mathpad service started with PID: $SERVICE_PID\"
"

		try
			do shell script "echo " & quoted form of startupScriptContent & " > " & quoted form of startupScript
			do shell script "chmod +x " & quoted form of startupScript
		on error errMsg
			display dialog "Failed to create startup script: " & errMsg buttons {"OK"} with icon stop
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
		set permissionChoice to display dialog "Next, Mathpad Service needs to start and request permissions from macOS.

When you click \"Start Service\", you will see two system dialogs asking for:
	• Keystroke Receiving permission
	• Accessibility Access permission

These permissions are required for the service to work properly.

Are you ready to grant these permissions?" buttons {"Cancel Installation", "Start Service"} default button 2 with title "✅ Files installed successfully" with icon note

		if button returned of permissionChoice is "Cancel Installation" then
			-- Clean up installed files since user cancelled
			try
				do shell script "rm -f " & quoted form of serviceBinary
				do shell script "rm -f " & quoted form of startupScript
				do shell script "rm -f " & quoted form of plistFile
			end try

			display dialog "Installation cancelled. Files have been cleaned up." buttons {"OK"} default button 1 with title "Installation Cancelled" with icon note
			tell me to quit
			return
		end if

		-- User confirmed they're ready, now start the service
		try
			-- Load and start the service (this will trigger permission requests if not already granted)
			do shell script "launchctl load " & quoted form of plistFile

			-- Give service a moment to start
			delay 2

			-- Now ask user to confirm they've granted permissions
			set permissionConfirm to display dialog "Mathpad Service has started and should have requested permissions.

Please grant BOTH permissions:
	• Keystroke Receiving
	• Accessibility Access

If you haven't seen the permission dialogs yet, they may appear while this dialog is open." buttons {"I could not grant permissions", "I have granted the permissions"} default button 2 with title "Grant Permissions" with icon note

			if button returned of permissionConfirm is "I could not grant permissions" then
				display dialog "Your Mathpad will not work until these two permissions are granted.

You can manually grant the permissions by going to System Preferences → Security and Privacy → Privacy." buttons {"Take me there", "OK"} default button 1 with title "Permissions Needed" with icon caution
				tell me to quit
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

Remember to set your Mathpad's OS switch to the 'MAC' position."
		else
			set finalMessage to "⚠️ Installation complete, but service verification failed.

This might mean:
	• Permissions were not fully granted
	• The service needs a restart

Please check:
1. System Preferences > Security & Privacy > Privacy
2. Ensure both Input Monitoring and Accessibility show Mathpad Service as enabled
3. Restart your computer if needed

Mathpad Service should work once permissions are properly set."
		end if

		display dialog finalMessage buttons {"Done"} default button 1 with title "✅ Installation Complete" with icon note

		tell me to quit

	on error errMsg
		display dialog "Installation failed: " & errMsg buttons {"OK"} with icon stop
		tell me to quit
	end try
end run