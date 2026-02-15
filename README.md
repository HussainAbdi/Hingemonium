# Your MacBook is Now a Harmonium

> This is a fork of [Rocktopus101/Hingemonium](https://github.com/Rocktopus101/Hingemonium) with improved bellows physics and a CI build workflow. See [What's Changed in This Fork](#whats-changed-in-this-fork) below.

This app transforms your MacBook into a surprisingly fun and expressive harmonium. You play the notes on the keyboard, and you **use the laptop's lid as the bellows to pump air**.

This project is a fork and a complete musical reimagining of the original **LidAngleSensor** utility by Sam Gold.

-----

## How to Play Your Laptop

The concept is simple, just like a real harmonium: you need air and you need to press a key.

  * **The Keys:** The bottom two rows of your keyboard are the keys (i.e., `Z`, `X`, `C`... for the white keys; and `S`, `D`, `G`...for the black keys). A handy legend in the app shows you exactly which note each key plays in the selected scale.
  * **The Bellows:** **Open and close your laptop lid to pump air**. The faster you move it, the more air pressure you build. Playing more notes drains air faster, just like a real harmonium. If you stop pumping, the sound will naturally fade as the air depletes.
  * **The Scales:** Use the dropdown to switch between Major, Minor, Chromatic, and other scales.
  * **Max Air Toggle:** Flip this on to bypass bellows physics and play at full volume (useful for testing or if your lid sensor isn't working).

-----

## What's Changed in This Fork

### Realistic Bellows Physics
The original air pressure model was essentially an on/off switch — any lid movement instantly maxed out pressure, then it drained at a fixed rate. This fork replaces it with a proper bellows simulation:

| Behavior | Description |
|---|---|
| **Gradual fill** | Takes several pump strokes to build full pressure, not instant |
| **Velocity smoothing** | Exponential moving average filters out sensor noise and jitter |
| **Dead zone** | Tiny movements (sensor drift) are ignored |
| **Back-pressure** | Harder to pump when the reservoir is already full |
| **Key-dependent drain** | Each held key acts as an open reed consuming air — more notes = faster drain |
| **Seal leak** | Very slow drain when no keys are held (bellows aren't perfectly airtight) |

### Bug Fix: Note Release Fade
Released notes were not fading out due to a timing bug where `processFadesWithDeltaTime:` was always receiving a delta of 0. This is now fixed.

### CI Build Workflow
A GitHub Actions workflow builds the app on every push to `main`, so you don't need Xcode installed locally. See [Building Without Xcode](#building-without-xcode-ci) below.

-----

## Installation

### Option 1: Homebrew (original upstream release)
```
brew tap Rocktopus101/homebrew-personal
brew install hingemonium
```
Note: this installs the original upstream version, not this fork's changes.

### Option 2: Building Without Xcode (CI)
This fork uses GitHub Actions to build on push. To get the latest build:

```bash
# Clone the repo
git clone https://github.com/HussainAbdi/Hingemonium.git
cd Hingemonium

# Download the latest build into the project folder
gh run download --name Hingemonium --dir .

# Unzip and run
unzip -o Hingemonium.zip
open Hingemonium.app
```

macOS Gatekeeper will likely block the app on first launch since it's ad-hoc signed. To allow it:
1. Right-click the app and select **Open**, or
2. Go to **System Settings > Privacy & Security** and click **Open Anyway**

### Option 3: Build with Xcode
Clone the repo, open `Hingemonium.xcodeproj` in Xcode, and hit the play button.

-----

## Dev Workflow (No Xcode Required)

If you want to make changes and rebuild without Xcode installed:

```bash
# 1. Make your code changes, then commit and push
git add -A && git commit -m "Your change description"
git push origin main

# 2. Wait for the build (takes ~45 seconds), then download it
gh run watch                                   # watch the build progress
gh run download --name Hingemonium --dir .      # download to project folder

# 3. Unzip and run
unzip -o Hingemonium.zip
open Hingemonium.app
```

You can also trigger a build manually without pushing:
```bash
gh workflow run build.yml
```

-----

## FAQ

**Will it work on my M1 Mac?**
Made and tested on M1 Pro. Some users have had trouble on the base M1 Air and 2020 touchbar Pro.

**What about my iMac?**
No lid, no bellows. Sorry.

**Why is the download so big?**
It's the 40 high quality harmonium WAV samples (~68 MB).

-----

## Origins & Thanks

This project would not exist without the original **LidAngleSensor** utility created by **Sam Gold** and the **Hingemonium** harmonium app by **Vedaant Rajeshirke** ([rocktopus101](https://github.com/Rocktopus101)).
