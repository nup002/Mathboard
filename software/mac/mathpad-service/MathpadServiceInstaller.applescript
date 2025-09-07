-- Mathpad Unicode Service Installer (User Installation - No Admin Required)
-- Save this as an Application in Script Editor

on run
	set installerVersion to "1.3.0"

	try
		-- Welcome dialog
		set userChoice to display dialog "Welcome to Mathpad Service " & installerVersion & " Installer!

This will install a background service in your user directory (no admin password required).

The service will:
• Run only for your user account
• Start automatically when you log in
• Enable Unicode typing in any application

Required permissions:
• Input Monitoring
• Accessibility

Click Install to continue." buttons {"Cancel", "Install"} default button 2 with title "Mathpad Service" with icon note

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
			display dialog "Error: Mathpad service binary not found in application bundle.

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
				set dialogMessage to "Mathpad Unicode Service is already installed and running.

What would you like to do?"
				set buttonOptions to {"Cancel", "Stop & Uninstall", "Reinstall"}
			else
				set dialogMessage to "Mathpad Unicode Service is already installed but not running.

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

				display dialog "✅ Mathpad Unicode Service has been uninstalled successfully." buttons {"OK"} default button 1 with title "Uninstall Complete" with icon note
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

		-- Load and start the service
		try
			do shell script "launchctl load " & quoted form of plistFile
			delay 2
		on error errMsg
			display dialog "Service installed but failed to start: " & errMsg buttons {"OK"} with icon caution
		end try

		-- Check if running
		try
			do shell script "pgrep -f mathpad-service"
			set isRunning to true
		on error
			set isRunning to false
		end try

		-- Final message
		if isRunning then
			set finalMessage to "✅ Installation completed successfully!

Your Mathpad Unicode Service is now running and will start automatically when you log in.

IMPORTANT: Please grant the following permissions:
• Input Monitoring
• Accessibility

Location: System Preferences > Security & Privacy > Privacy

Files installed in your home directory:
• Service: ~/.local/bin/mathpad-service
• Logs: ~/.local/var/log/mathpad-service.log
• Auto-start: ~/Library/LaunchAgents/com.mathpad.service.plist

Commands:
• Manual start: " & startupScript & "
• Stop: launchctl unload " & plistFile & "
• Restart: launchctl unload && launchctl load " & plistFile
		else
			set finalMessage to "⚠️ Installation completed but service may not be running.

This is normal and usually due to missing permissions. Please:

1. Open System Preferences > Security & Privacy > Privacy
2. Grant permissions for Input Monitoring and Accessibility
3. The service should start automatically

Manual commands:
• Start: launchctl load " & plistFile & "
• Stop: launchctl unload " & plistFile
		end if

		display dialog finalMessage buttons {"Open System Preferences", "Done"} default button 2 with title "Installation Complete" with icon note

		set userChoice to button returned of result
		if userChoice is "Open System Preferences" then
			do shell script "open 'x-apple.systempreferences:com.apple.preference.security?Privacy'"
		end if

		tell me to quit

	on error errMsg
		display dialog "Installation failed: " & errMsg buttons {"OK"} with icon stop
		tell me to quit
	end try
end run