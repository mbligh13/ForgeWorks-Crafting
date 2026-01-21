# ForgeWorks Crafting - Troubleshooting Guide

## Common Server Errors and Solutions

### Error: "Missing addon 'ForgeWorks_WeaponParts'"
**Cause:** The ForgeWorks_crafting.pbo requires the forgeworks_weaponparts.pbo to be loaded first.

**Solution:**
1. Ensure both PBOs exist in `ForgeWorksCrafting/addons/`:
   - `ForgeWorks_crafting.pbo`
   - `forgeworks_weaponparts.pbo`
2. The server should load them automatically, but verify both are present

### Error: "Cannot find file 'ForgeWorks_Crafting/addons/ForgeWorks_crafting/scripts/3_game'"
**Cause:** Script paths in mod.cpp don't match the actual directory structure.

**Solution:**
Verify your `mod.cpp` has the correct paths:
```cpp
files[] = { "ForgeWorksCrafting/addons/ForgeWorks_crafting/scripts/3_game" };
```
NOT:
```cpp
files[] = { "ForgeWorks_crafting/scripts/3_game" };  // Wrong - missing mod folder
```

### Error: "Duplicate class 'FWCraftingWorkbench'"
**Cause:** Workbench class defined in multiple config files.

**Solution:**
We've fixed this - workbenches should ONLY be in `ForgeWorks_crafting/config.cpp`, NOT in `forgeworks_weaponparts/config.cpp`.

### Error: "Cannot load model '\forgeworks_weaponparts\data\models\work_bench.p3d'"
**Cause:** Model file doesn't exist or path is wrong.

**Solution:**
1. Check that `.p3d` files exist in `forgeworks_weaponparts/data/models/`
2. Verify paths use backslashes: `\forgeworks_weaponparts\data\models\work_bench.p3d`
3. Ensure model paths are relative to the PBO root

### Error: "String 'STR_S88_CRAFT' not found"
**Cause:** Old Sector88 string references still in use.

**Solution:**
We've fixed this - all strings now use `STR_FW_` prefix in stringtable.xml and scripts.

### Error: "Cannot open file 'fw_tags.json'"
**Cause:** JSON files not found in the expected location.

**Solution:**
Verify these files exist in `ForgeWorks_crafting/_core/`:
- `fw_tags.json`
- `recipe_list.json`

## Pre-Launch Checklist

### Before Building PBOs:
- [ ] No S88/Sector88 references remaining (except in comments)
- [ ] All class names use FW prefix
- [ ] All model paths use backslashes
- [ ] stringtable.xml uses STR_FW_ prefix
- [ ] recipe_list.json Directory set to "ForgeWorks"

### After Building PBOs:
- [ ] Both PBOs exist in `addons/` folder
- [ ] PBOs are signed (`.bisign` files present)
- [ ] Signature key (`.bikey`) is in `keys/` folder
- [ ] mod.cpp still in root (not packed)
- [ ] meta.cpp still in root (not packed)
- [ ] types.xml still in root (not packed)

### Server Configuration:
- [ ] Mod folder copied to server mods directory
- [ ] Launch parameter includes: `-mod=ForgeWorksCrafting`
- [ ] types.xml entries merged into server types
- [ ] spawnabletypes.xml entries merged
- [ ] Server restarted after configuration

## Testing Procedures

### Basic Functionality Test:
1. **Start Server**
   - Check server console for errors during mod loading
   - Look for "ForgeWorks" references in startup logs
   
2. **Join Server**
   - Verify mod shows as loaded in main menu
   - Check that ForgeWorks icon appears

3. **Spawn Workbench**
   ```
   Admin command or spawn:
   FWCraftingWorkbench
   ```

4. **Test Crafting Menu**
   - Approach workbench
   - Look for interaction prompt: "Open Crafting Menu"
   - Open menu (default action key)
   - Verify categories load
   - Check recipes appear

5. **Test Crafting**
   - Spawn required materials
   - Place in workbench inventory
   - Select a simple recipe
   - Verify crafting completes
   - Check output item is correct

### Advanced Testing:
- Test all caliber categories
- Verify breakdown recipes
- Test magazine crafting
- Check upgrade recipes
- Verify tool requirements

## Config File Validation

### VS Code Errors Can Be Ignored
**Note:** VS Code will show errors in config.cpp files. This is normal!

Config.cpp files use DayZ's proprietary configuration syntax, not standard C++. Errors like:
- "identifier 'units' is undefined"
- "expected an identifier"
- "this declaration has no storage class"

These are **NOT REAL ERRORS** - they only appear because VS Code treats .cpp as C++ files.

### Actual Config Errors to Watch For:
1. **Missing semicolons** - End of statements
2. **Unmatched braces** - `{}` must be balanced
3. **Missing class inheritance** - `class X : ParentClass`
4. **Typos in class names**
5. **Wrong path separators** - Use `\` for model paths, `/` for script paths

## Log File Locations

### Server Logs:
- Windows: `C:\Users\YourName\AppData\Local\DayZ\`
- Linux: Usually in server root or `~/.local/share/DayZ/`

### What to Look For:
```
✓ Good: "Registering ForgeWorks_Crafting mod"
✓ Good: "Loading script module: 3_game"
✗ Bad: "Warning: Class 'FWCraftingWorkbench' not found"
✗ Bad: "Error: Cannot load model..."
✗ Bad: "Missing addon..."
```

## Quick Fixes

### Reset Everything:
1. Delete both PBOs from `addons/`
2. Verify source files are correct
3. Rebuild PBOs fresh
4. Restart server completely

### Clear Server Cache:
Sometimes servers cache old configs:
1. Stop server
2. Delete server cache/temp files
3. Restart server

### Verify File Integrity:
```bash
# Check PBO contents (if you have PBO tools)
extractPBO ForgeWorks_crafting.pbo temp/
ls -R temp/

# Should show:
# - config.cpp
# - model.cfg
# - scripts/
# - gui/
# - data/
# - etc.
```

## Getting Help

### Information to Provide:
1. Server RPT log (last 100 lines showing error)
2. Client RPT log if GUI doesn't work
3. Exact error message
4. Steps to reproduce
5. Server OS and DayZ version
6. Other mods installed

### Common False Positives:
- "Failed to load textureheaders" - Usually harmless
- "No entry 'bin\config.bin/CfgVehicles.X'" - May indicate missing dependency
- EnforceScript errors - These ARE important!

## Performance Notes

### Mod Size:
- Keep PBOs under 50MB each if possible
- Compress textures appropriately
- Remove unused files before packing

### Server Impact:
- Recipe JSON loading happens once at startup
- GUI only loads when player opens menu
- Minimal runtime performance impact
- No constant background processes

## Development Mode

### Testing Without PBOs (Unpacked):
For rapid development, you can test with unpacked addons:

1. **Remove or rename the PBOs:**
   - Move `ForgeWorks_crafting.pbo` out of addons
   - Leave the unpacked `ForgeWorks_crafting/` folder

2. **Add `-filePatching` to server launch:**
   ```
   -mod=ForgeWorksCrafting -filePatching
   ```

3. **Edit files directly, restart server to test**

**Remember:** Always build and test with PBOs before release!
