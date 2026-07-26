# Mathpad Service — Real-Mac QA Checklist

## Why this exists

The GitHub Actions workflow (`sign_and_package_mathpad_service.yml`) proves the
built artifact is well-formed: universal (arm64 + x86_64), correctly floored
(`arm64` min-OS 11.0, `x86_64` min-OS 10.14.4), signed, notarized, stapled, and
Gatekeeper-approved (`spctl --assess`). That is the limit of what a headless
GitHub-hosted runner can verify.

It **cannot** verify that the service actually works, because that requires:

- A physical **Mathpad** device (HID input via `IOKit.hid`).
- An interactive **login session** with a real window server, since granting
  **Accessibility** (TCC) permission requires a human clicking through a
  system dialog — there is no TCC database to grant into on a headless runner.
- Real keystroke injection via `CGEvent`/`ApplicationServices`, which needs
  that Accessibility grant to have any effect.

This checklist is the manual pass that closes that gap. Run it on a real Mac
(borrowed hardware, or a rented instance — MacinCloud, MacStadium, AWS EC2
`mac2.metal`) after every signed/notarized build before shipping it.

## What the installer actually does

Based on `Install.applescript` (the source of truth — read it if this drifts):

- **Install location:** `~/Applications/mathpad-service.app` (the user's
  personal Applications folder, *not* `/usr/local/bin` or the system-wide
  `/Applications`). No admin/root privileges are required.
- **Binary path after install:**
  `~/Applications/mathpad-service.app/Contents/MacOS/mathpad-service`
- **Logs:** `~/.local/var/log/mathpad-service.log` and
  `~/.local/var/log/mathpad-service.error.log`
- **Autostart:** a LaunchAgent is written to
  `~/Library/LaunchAgents/com.mathpad.service.plist` with `RunAtLoad = true`
  and `KeepAlive.SuccessfulExit = false` (relaunches on crash, but not after a
  clean `exit(0)`). Because this is a standard per-user LaunchAgent, `launchd`
  reloads it automatically **on every login and after every reboot** — no
  extra step is needed for persistence.
- **Existing-installation handling:** the installer detects a prior install
  (checks for the app bundle and a running `mathpad-service` process via
  `pgrep`) and offers Cancel / (Stop &) Uninstall / Reinstall. Uninstall and
  reinstall both `launchctl unload` the LaunchAgent, `pkill` the process, and
  remove the app bundle, plist, PID file (`/tmp/mathpad_service.pid`), and log
  directory. Reinstall also best-effort runs
  `tccutil reset Accessibility com.mathpad.mathpad-service` (this can silently
  fail without admin rights — the installer warns the user to remove the old
  Accessibility entry by hand if so).
- **Permission flow:** after files are copied, the installer shows a dialog,
  then does `launchctl load` on the plist (which starts the service and
  should trigger the Accessibility prompt), then asks the user to confirm
  whether they granted it. If not, it offers to open
  System Preferences → Security & Privacy → Privacy directly.

## Checklist

1. **Download & mount**
   - [ ] Download the notarized DMG from the workflow run's artifact (or the
     GitHub Release, if one was published).
   - [ ] Double-click to mount. macOS should **not** show a Gatekeeper
     "unidentified developer" block — a clean open is the proof that
     notarization/stapling worked outside of CI.

2. **Run the installer**
   - [ ] Launch `Install.app` from the mounted DMG.
   - [ ] Confirm the welcome dialog shows the correct version number.
   - [ ] Click **Install**.
   - [ ] If a prior install exists, confirm the Cancel/Uninstall/Reinstall
     dialog appears and behaves as described above.

3. **Confirm install location**
   - [ ] `~/Applications/mathpad-service.app` exists.
   - [ ] `~/Library/LaunchAgents/com.mathpad.service.plist` exists and its
     `ProgramArguments` points at the binary above.
   - [ ] `~/.local/var/log/mathpad-service.log` is being written to.

4. **Grant Accessibility permission**
   - [ ] When prompted by the installer, click **Start Service**.
   - [ ] The macOS Accessibility permission dialog should appear (possibly
     behind the installer window — check).
   - [ ] Grant it, add `mathpad-service` under
     System Preferences/Settings → Privacy & Security → Accessibility if it
     doesn't appear automatically.
   - [ ] Confirm the installer's "I have granted the permission" flow
     completes and the final dialog reports the service running.

5. **Attach the Mathpad and verify keypresses**
   - [ ] Plug in the physical Mathpad, set its OS switch to **MAC**.
   - [ ] Open a text field and confirm keypresses/Unicode characters from the
     Mathpad are injected correctly.
   - [ ] Check `~/.local/var/log/mathpad-service.log` for `[SUCCESS]`/`Mathpad
     connected` lines and `~/.local/var/log/mathpad-service.error.log` for
     unexpected errors.

6. **Persistence across logout/login**
   - [ ] Log out and back in.
   - [ ] Confirm `pgrep -f mathpad-service` shows the process running again
     without manual intervention (LaunchAgent `RunAtLoad`).
   - [ ] Re-test Mathpad keypresses.

7. **Persistence across reboot**
   - [ ] Reboot the Mac.
   - [ ] Repeat the checks in step 6.

8. **Uninstall path** (optional, if testing removal)
   - [ ] Re-run `Install.app`, choose **Stop & Uninstall** (or **Uninstall**).
   - [ ] Confirm the app bundle, plist, PID file, and log directory are gone
     and the process is no longer running.

## Recommended follow-up (not implemented — flag for maintainer decision)

Add a `--self-test` flag to `MathpadService.swift` that, without entering the
`CFRunLoopRun()` run loop:

- Enumerates connected HID devices matching the Mathpad vendor/product ID.
- Reports `AXIsProcessTrusted()` (Accessibility grant status).
- Initializes the HID manager and other subsystems to confirm they don't
  throw/fail.
- Prints a pass/fail summary and exits non-zero on any failure.

This would give a fast, scriptable, repeatable smoke test to run on real
hardware after each install/reinstall, without needing to manually trigger
and observe a live keypress.
