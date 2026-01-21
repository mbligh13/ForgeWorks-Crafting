# ForgeWorks Crafting System - Setup Guide

## Overview
This mod adds a custom crafting GUI system that allows players to craft weapons, magazines, and other items at workbenches.

## Features (current)
- **Tabbed Interface**: Pistols, SMGs, Rifles, Snipers, Shotguns, Magazines
- **Workbench-only materials**: All required parts must be inside the workbench inventory (player inventory is ignored)
- **Material Tracking**: Real-time display of required materials with color-coded availability
- **Crafting Timer**: Time-based crafting; cancels if player moves away
- **Simple bench**: Workbench is only a GUI focus object (no attached tool requirements)

## Installation

### Server Setup
1. Copy `@ForgeWorks_Crafting` folder to your DayZ server root
2. Add `@ForgeWorks_Crafting` to your server startup parameters: `-mod=@ForgeWorks_Crafting`
3. Pack the addons folder into PBO files using DayZ Tools Addon Builder

### Client Setup
1. Subscribe to the mod on Steam Workshop (once published)
2. Or copy `@ForgeWorks_Crafting` to your DayZ client installation

## File Structure
```
@ForgeWorks_Crafting/
├── addons/
│   ├── ForgeWorks_crafting/
│   │   ├── config_workbench.cpp      # Workbench item definitions
│   │   ├── gui/layouts/              # UI layout files
│   │   │   ├── FWCraftingMenu.layout
│   │   │   ├── FWRecipeButton.layout
│   │   │   ├── FWMaterialSlot.layout
│   │   │   └── FWSubcategoryButton.layout
│   │   ├── scripts/
│   │   │   ├── 3_game/               # Game-level scripts
│   │   │   │   └── FWConstants.c
│   │   │   ├── 4_world/              # World-level scripts
│   │   │   │   ├── FWCraftingData.c
│   │   │   │   ├── FWCraftingManager.c
│   │   │   │   ├── FWRecipeManager.c
│   │   │   │   ├── actions/
│   │   │   │   └── entities/
│   │   │   └── 5_mission/            # Mission-level scripts
│   │   │       └── gui/
│   │   ├── config/workbenches/       # Workbench spawn positions
│   │   └── data/stringtable.xml      # Localization
│   └── forgeworks_weaponparts/       # Weapon parts definitions
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
- Recipes live in JSON under `addons/ForgeWorks_crafting/` (e.g., `Guns/556/craft_556_rifles.json`).
- No tool requirements are needed; only ingredients matter.
- Example JSON structure:

```json
{
    "Name": "Craft 5.56 Rifles",
    "ActionType": "Craft",
    "CraftingTime": 40,
    "Animation": "WorkOnBench",
    "Ingredients": {
        "X": [
            { "ClassName": "Barrel_556", "Amount": 1 },
            { "ClassName": "UpperReceiver_556", "Amount": 1 },
            { "ClassName": "LowerReceiver_556", "Amount": 1 }
        ]
    },
    "Result": {
        "Create": [ { "ClassName": "M4A1", "Amount": 1 } ],
        "Delete": [
            { "ClassName": "Barrel_556", "Amount": 1 },
            { "ClassName": "UpperReceiver_556", "Amount": 1 },
            { "ClassName": "LowerReceiver_556", "Amount": 1 }
        ]
    },
    "Tags": ["FW_MakeGun"]
}
```

## Admin Commands
Spawn a workbench at player position (requires admin scripts):
```csharp
FWAdminSpawnWorkbench.Execute(player);
```

Spawn at specific coordinates:
```csharp
FWWorkbenchSpawner.SpawnAtPosition(Vector(1000, 0, 1000), Vector(0, 0, 0));
```

## Troubleshooting

### Menu not appearing
- Ensure scripts are packed correctly in PBO
- Check server RPT for script errors
- Verify mod is loaded on both client and server

### Recipes not showing
- Check that FWRecipeManager is loading properly
- Verify category names match in both RecipeManager and Menu

### Crafting fails silently
- Check that all ingredient class names match exactly
- Verify required materials are inside the workbench inventory (not the player)
- Check player is within 3 meters of workbench

## Dependencies
- DayZ Standalone 1.24+
- ForgeWorks Weapon Parts mod

## Credits
Sector 88 Dev Team (original authors)
