# Windows Defender

Microsoft has confirmed that the D2SteamFix detection was a false positive and has removed it. If Windows Defender still reports the old detection, clear the cached definitions and download the latest malware definitions:

1. Open **Command Prompt** as an administrator.
2. Change to the Windows Defender directory:

   ```batch
   cd /d "C:\Program Files\Windows Defender"
   ```

3. Remove the cached dynamic signatures:

   ```batch
   MpCmdRun.exe -removedefinitions -dynamicsignatures
   ```

4. Download the latest malware definitions:

   ```batch
   MpCmdRun.exe -SignatureUpdate
   ```

Alternatively, the latest definition package is available from:

[https://docs.microsoft.com/microsoft-365/security/defender-endpoint/manage-updates-baselines-microsoft-defender-antivirus](https://docs.microsoft.com/microsoft-365/security/defender-endpoint/manage-updates-baselines-microsoft-defender-antivirus)
