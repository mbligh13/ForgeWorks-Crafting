# Workshop Mod Mismatch Error - Troubleshooting

## Error: "You have a mod/PBO the server doesn't"

### Root Cause
This error occurs when the client and server have different versions or configurations of the same mod, even if both downloaded from Steam Workshop.

## Common Causes & Solutions

### 1. **UNPACKED vs PACKED (Most Common)**

**Problem:** Your Workshop upload has unpacked addon folders instead of PBO files.

**Check:**
```
ForgeWorksCrafting/addons/
├── ForgeWorks_crafting/        ← WRONG for Workshop (unpacked folder)
└── forgeworks_weaponparts/     ← WRONG for Workshop (unpacked folder)
```

**Should be:**
```
ForgeWorksCrafting/addons/
├── ForgeWorks_crafting.pbo     ← CORRECT (packed PBO)
└── forgeworks_weaponparts.pbo  ← CORRECT (packed PBO)
```

**Solution:**
- Pack your addons into PBOs using DayZ Tools Addon Builder
- Delete the unpacked folders from addons/ after packing
- Re-upload to Workshop with PBOs

---

### 2. **Version Mismatch**

**Problem:** Server has old version, client has new version (or vice versa).

**Check:**
- Server owner: Check which version is installed
- Compare mod.cpp version numbers

**Solution:**
- Server owner must update mod from Workshop
- Both must restart completely
- Verify Workshop item updated (check timestamp)

---

### 3. **Signature Mismatch**

**Problem:** Client and server have different signatures or one is missing signatures.

**Check:**
```
ForgeWorksCrafting/addons/
├── ForgeWorks_crafting.pbo
├── ForgeWorks_crafting.pbo.YourKey.bisign     ← Signature file
├── forgeworks_weaponparts.pbo
└── forgeworks_weaponparts.pbo.YourKey.bisign  ← Signature file
```

**Solution Option A - No Signatures (easier for testing):**
- Don't sign PBOs
- Server removes `-BEpath=` parameter or disables signature verification
- Remove any .bisign files

**Solution Option B - Proper Signatures:**
- Sign ALL PBOs with same private key
- Include .bisign files in Workshop upload
- Include .bikey file in keys/ folder
- Server must have matching .bikey in keys/

---

### 4. **Server Configuration Issue**

**Problem:** Server isn't loading the mod correctly.

**Check Server Launch Parameters:**
```bash
# CORRECT - using Workshop ID
-mod=@ForgeWorksCrafting

# OR using direct path
-mod=ForgeWorksCrafting
```

**Check Server Mods Folder:**
- Verify mod is actually in the mods folder
- Check folder name matches launch parameter
- Verify PBO files are present in addons/

---

### 5. **Development Build vs Release**

**Problem:** You uploaded a development version with unpacked files.

**Development Mode (local testing only):**
```
- Use unpacked folders
- Server uses -filePatching parameter
- NOT suitable for Workshop
```

**Release Mode (Workshop/public servers):**
```
- Use packed PBOs
- No -filePatching needed
- Required for Workshop
```

---

## Step-by-Step Fix Process

### For Mod Author (You):

1. **Pack Your Addons:**
   ```
   - Open DayZ Tools > Addon Builder
   - Pack: forgeworks_weaponparts folder → .pbo
   - Pack: ForgeWorks_crafting folder → .pbo
   - Result: Two .pbo files in addons/
   ```

2. **Clean the Addons Folder:**
   ```
   ForgeWorksCrafting/addons/
   ├── ForgeWorks_crafting.pbo          ← Keep
   ├── forgeworks_weaponparts.pbo       ← Keep
   ├── ForgeWorks_crafting/             ← DELETE (unpacked folder)
   └── forgeworks_weaponparts/          ← DELETE (unpacked folder)
   ```

3. **Update Version:**
   - Edit mod.cpp: Increment version (e.g., 1.0.1 → 1.0.2)
   - This helps track which version people have

4. **Re-upload to Workshop:**
   - Use Publisher Tool or Workshop Uploader
   - Upload the entire ForgeWorksCrafting folder
   - Include changelog mentioning "Fixed PBO packaging"

5. **Test Locally:**
   ```
   - Install from Workshop yourself
   - Check addons/ folder has .pbo files
   - Join test server to verify
   ```

### For Server Owner:

1. **Update Mod from Workshop:**
   - Use SteamCMD or Workshop Downloader
   - Completely delete old version first
   - Download fresh copy

2. **Verify PBO Files:**
   ```
   Check: mods/ForgeWorksCrafting/addons/
   Should have: .pbo files only
   Should NOT have: unpacked folders
   ```

3. **Check Launch Parameters:**
   ```bash
   -mod=@ForgeWorksCrafting
   # or
   -mod=ForgeWorksCrafting
   ```

4. **Restart Server Completely:**
   - Full stop, not just restart
   - Wait 30 seconds
   - Start again

5. **Check Server Logs:**
   ```
   Look for:
   ✓ "Loading mod: ForgeWorksCrafting"
   ✓ "Loading addon: ForgeWorks_crafting"
   ✓ "Loading addon: forgeworks_weaponparts"
   
   Errors to watch for:
   ✗ "Cannot load file..."
   ✗ "Missing addon..."
   ✗ "Signature verification failed"
   ```

### For Players (Client):

1. **Verify Mod is Subscribed:**
   - Check Steam Workshop subscriptions
   - Look for ForgeWorksCrafting

2. **Verify Download Completed:**
   - Steam > Downloads
   - Make sure Workshop item finished downloading

3. **Check Local Installation:**
   ```
   Location: 
   C:\Program Files (x86)\Steam\steamapps\workshop\content\221100\[workshop_id]\
   
   Should contain:
   - addons/ folder with .pbo files
   - mod.cpp
   - meta.cpp
   ```

4. **Restart DayZ Client:**
   - Complete restart
   - Not just disconnect/reconnect

5. **Verify Mod Shows in Launcher:**
   - DayZ Launcher > Mods tab
   - ForgeWorksCrafting should be listed
   - Should be enabled/checked

---

## Quick Verification Checklist

**Mod Author (Before Upload):**
- [ ] Addons are packed into .pbo files
- [ ] Unpacked folders removed from addons/
- [ ] Version number incremented in mod.cpp
- [ ] Tested locally with packed PBOs
- [ ] Workshop upload includes entire mod folder

**Server Owner:**
- [ ] Downloaded latest version from Workshop
- [ ] addons/ folder contains .pbo files (not folders)
- [ ] -mod parameter includes ForgeWorksCrafting
- [ ] Server fully restarted after update
- [ ] Server logs show mod loading correctly

**Players:**
- [ ] Subscribed to mod on Workshop
- [ ] Download completed (check Steam downloads)
- [ ] DayZ client restarted
- [ ] Mod shows as enabled in launcher

---

## Still Having Issues?

### Check These:

1. **Workshop Upload Date:**
   - Does Workshop page show recent update?
   - Server/clients might have cached old version

2. **File Sizes:**
   - Compare client and server PBO file sizes
   - Should be identical

3. **Workshop ID:**
   - Verify server is using correct Workshop ID
   - Check published ID matches

4. **Conflicting Mods:**
   - Temporarily disable other mods
   - Test with only ForgeWorksCrafting

5. **Cache Issues:**
   - Steam: Clear download cache
   - Server: Delete and re-download mod
   - Client: Unsubscribe, restart Steam, resubscribe

---

## For Your Specific Case

Since both client and server downloaded from Workshop, most likely:

1. **Your Workshop upload has unpacked folders instead of PBOs**
   - Fix: Pack into PBOs and re-upload

2. **Server cached old version before you updated**
   - Fix: Server owner must delete mod folder and re-download

3. **Version mismatch between what's on Workshop and what server has**
   - Fix: Ensure server is actually downloading from Workshop, not using a local copy
