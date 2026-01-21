# ForgeWorks Crafting - Structure Validation Checklist

## ✅ Completed Steps

### 1. File Organization
- [x] Moved `model.cfg` from root to `addons/ForgeWorks_crafting/`
- [x] Created main `config.cpp` in `addons/ForgeWorks_crafting/`
- [x] Removed duplicate workbench definitions from `forgeworks_weaponparts/config.cpp`
- [x] Created build script (`build_mod.sh`)
- [x] Created build documentation (`BUILD_INSTRUCTIONS.md`)

### 2. Config Structure
- [x] `ForgeWorks_crafting/config.cpp` - Main crafting system & workbenches
- [x] `forgeworks_weaponparts/config.cpp` - Weapon parts definitions only
- [x] Proper CfgPatches dependencies set up

## 🔍 Next Steps - Systematic Review

### 3. Root Level Files (ForgeWorksCrafting/)
- [ ] Verify `mod.cpp` is correct
- [ ] Verify `meta.cpp` is correct  
- [ ] Check `ForgeWorks_Crafting.paa` exists
- [ ] Review `ForgeWorks_types.xml` format
- [ ] Review `ForgeWorks_spawnabletypes.xml` format
- [ ] Check `keys/ForgeWorks.bikey` exists

### 4. ForgeWorks_crafting Addon Structure
- [ ] Verify all script paths are correct in config.cpp
- [ ] Check scripts/3_game/ files
- [ ] Check scripts/4_world/ files
- [ ] Check scripts/5_mission/ files
- [ ] Verify GUI layout files
- [ ] Check stringtable.xml
- [ ] Verify recipe JSON files structure
- [ ] Check _core/ files (fw_tags.json, recipe_list.json)

### 5. forgeworks_weaponparts Addon Structure
- [ ] Verify model paths in config.cpp
- [ ] Check that .p3d models exist in data/models/
- [ ] Verify all part classes are defined

### 6. Configuration Consistency
- [ ] All class names use FW prefix (not S88)
- [ ] All paths use correct backslashes for P3D paths
- [ ] All model references point to correct locations
- [ ] Recipe JSONs reference correct class names

### 7. Testing Preparation
- [ ] Create test server configuration
- [ ] Document common errors and solutions
- [ ] Prepare troubleshooting guide

## 📝 Notes

### Development vs Distribution Files
**Keep in root (development only):**
- Development Tools/ folder
- Python scripts
- README files (non-user facing)

**Keep in ForgeWorksCrafting/ (distribution):**
- mod.cpp, meta.cpp
- .paa icon file
- types.xml and spawnabletypes.xml
- keys/
- addons/ (to be packed into PBOs)

### PBO Packing Order
1. Pack `forgeworks_weaponparts` first (no dependencies)
2. Pack `ForgeWorks_crafting` second (depends on weaponparts)

### Common Issues to Watch For
- Duplicate class definitions
- Wrong path separators (/ vs \)
- Missing model files
- Incorrect CfgPatches dependencies
- Script path mismatches
