# D2SteamFix

D2SteamFix is a launch wrapper for Destiny 2 intended to help alleviate frame pacing and stuttering issues for Steam users. Before starting Destiny 2, it temporarily denies execute access to Steam's overlay renderer DLLs, then restores the original permissions after exiting the game.

Please note that blocking the Steam Overlay DLLs can also affect overlay-dependent features such as Steam Input, notifications, Game Recording, and Remote Play. This program temporarily changes only the ACL metadata of the overlay DLLs; it does not alter their contents. It does not inject code, inspect process memory, modify game files, change Steam configuration, or bypass BattlEye.

## Installation

Download [steamfix.exe](https://pkg.d2checkpoint.com/D2SteamFix/steamfix.exe) and place it directly in your game's directory.

Then, open Destiny 2's launch options in Steam:

1. In Steam right-click **Destiny 2** in your library and select **Properties**.
2. Find the **Launch Options** field under the **General** tab and paste the command below.

```text
"C:\path\to\Destiny 2\steamfix.exe" %command%
```

Replace `C:\path\to\Destiny 2` with the actual location of your Destiny 2 installation. The example path below is for a default Steam installation; if your game is on another drive, use that drive letter and the complete path instead:

```text
"C:\Program Files (x86)\Steam\steamapps\common\Destiny 2\steamfix.exe" %command%
```

![Steam Launch Options](https://static.d2checkpoint.com/steamfix_launch_options.png)
