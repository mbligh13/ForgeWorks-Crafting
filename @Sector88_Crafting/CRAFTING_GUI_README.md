# Sector 88 Crafting System - Setup Guide

## Overview
This mod adds a custom crafting GUI system that allows players to craft weapons, magazines, and other items at workbenches.

## Features
- **Tabbed Interface**: Categories for Pistols, SMGs, Rifles, Snipers, Shotguns, and Magazines
- **Material Tracking**: Real-time display of required materials with color-coded availability
- **Tool Requirements**: Workbench must have proper tools attached (Grinder, Drill, Saw, etc.)
- **Crafting Timer**: Time-based crafting with cancellation if player moves away
- **Vanilla Workbench Support**: Works with existing in-game workbenches

## Installation

### Server Setup
1. Copy `@Sector88_Crafting` folder to your DayZ server root
2. Add `@Sector88_Crafting` to your server startup parameters: `-mod=@Sector88_Crafting`
3. Pack the addons folder into PBO files using DayZ Tools Addon Builder

### Client Setup
1. Subscribe to the mod on Steam Workshop (once published)
2. Or copy `@Sector88_Crafting` to your DayZ client installation

## File Structure
```
@Sector88_Crafting/
├── addons/
│   ├── Sector88_crafting/
│   │   ├── config_workbench.cpp      # Workbench item definitions
│   │   ├── gui/layouts/              # UI layout files
│   │   │   ├── S88CraftingMenu.layout
│   │   │   ├── S88RecipeButton.layout
│   │   │   ├── S88MaterialSlot.layout
│   │   │   └── S88SubcategoryButton.layout
│   │   ├── scripts/
│   │   │   ├── 3_game/               # Game-level scripts
│   │   │   │   └── S88Constants.c
│   │   │   ├── 4_world/              # World-level scripts
│   │   │   │   ├── S88CraftingData.c
│   │   │   │   ├── S88CraftingManager.c
│   │   │   │   ├── S88RecipeManager.c
│   │   │   │   ├── actions/
│   │   │   │   └── entities/
│   │   │   └── 5_mission/            # Mission-level scripts
│   │   │       └── gui/
│   │   ├── config/workbenches/       # Workbench spawn positions
│   │   └── data/stringtable.xml      # Localization
│   └── sector88_weaponparts/         # Weapon parts definitions
├── keys/
└── mod.cpp
```

## Configuring Workbench Positions
Edit `config/workbenches/positions.json` to add custom workbench spawn locations:

```json
[
    {
        "m_Position": [4525.5, 0.0, 9867.2],
        "m_Orientation": [0.0, 0.0, 0.0],
        "m_MapName": "ChernarusPlus"
    }
]
```

## Adding New Recipes
Edit `S88RecipeManager.c` and add recipes in the appropriate Load function:

```csharp
ref S88CraftingRecipe myWeapon = new S88CraftingRecipe();
myWeapon.SetName("craft_my_weapon");
myWeapon.SetDisplayName("My Custom Weapon");
myWeapon.SetCategory("Rifles");
myWeapon.SetSubCategory("5.56x45");
myWeapon.SetCraftingTime(8);
myWeapon.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
myWeapon.AddIngredient("Barrel_556", 1);
myWeapon.AddIngredient("UpperReceiver_556", 1);
myWeapon.AddIngredient("LowerReceiver_556", 1);
myWeapon.AddResult("MyCustomWeapon_ClassName");
AddRecipe(myWeapon);
```

## Required Tools
The following tools can be attached to workbenches:
- **BPGrinder** - Required for most crafting
- **BPCutting_saw** - Required for rifles and larger items
- **BPDrill** - Required for precision work
- **BPHammer** - Basic tool
- **BPWrench** - Basic tool

## Admin Commands
Spawn a workbench at player position (requires admin scripts):
```csharp
S88AdminSpawnWorkbench.Execute(player);
```

Spawn at specific coordinates:
```csharp
S88WorkbenchSpawner.SpawnAtPosition(Vector(1000, 0, 1000), Vector(0, 0, 0));
```

## Troubleshooting

### Menu not appearing
- Ensure scripts are packed correctly in PBO
- Check server RPT for script errors
- Verify mod is loaded on both client and server

### Recipes not showing
- Check that S88RecipeManager is loading properly
- Verify category names match in both RecipeManager and Menu

### Crafting fails silently
- Check that all ingredient class names match exactly
- Verify workbench has required tool attachments
- Check player is within 3 meters of workbench

## Dependencies
- DayZ Standalone 1.24+
- Sector88 Weapon Parts mod

## Credits
Sector 88 Development Team
