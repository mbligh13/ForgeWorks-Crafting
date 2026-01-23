// ForgeWorks Crafting System - Main Config
// This file defines the crafting system patches and workbench classes

class CfgPatches
{
    class ForgeWorks_Crafting
    {
        units[] = {
            "FWCraftingWorkbench",
            "FWCraftingWorkbench_Military",
            "FWCraftingWorkbench_Civilian"
        };
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {
            "DZ_Data",
            "DZ_Gear_Tools",
            "DZ_Scripts",
            "ForgeWorks_WeaponParts",  // Require the weapon parts addon
            "DZ_Expansion_Core",       // DayZ Expansion - Core
            "DZ_Expansion_Objects"     // DayZ Expansion - Objects (toolbox, etc.)
        };
    };
};

class CfgVehicles
{
    // Base game workbench for inheritance
    class Inventory_Base;
    class Workbench;
    
    // ============================================
    // FW CRAFTING WORKBENCH - BASE
    // ============================================
    class FWCraftingWorkbench : Inventory_Base
    {
        scope = 2;
        displayName = "ForgeWorks Workbench";
        descriptionShort = "A well-equipped workbench for crafting weapons and equipment.";
        // Use the custom forgeworks workbench model from the weapon parts addon
        model = "\forgeworks_weaponparts\data\models\work_bench.p3d";
        
        // Physics
        physLayer = "item_large";
        weight = 50000;
        heavyItem = 1;
        
        // Inventory
        itemsCargoSize[] = {10, 10};
        
        // No attachment slots needed - workbench is just a focus object
        attachments[] = {};
        
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 1000;
                    healthLevels[] = {
                        {1.0, {}},
                        {0.7, {}},
                        {0.5, {}},
                        {0.3, {}},
                        {0.0, {}}
                    };
                };
            };
        };
        
        // Actions
        class AnimEvents
        {
            class SoundWeapon
            {
                class craft
                {
                    soundSet = "craft_universal_SoundSet";
                    id = 201;
                };
            };
        };
    };
    
    // ============================================
    // MILITARY VARIANT
    // ============================================
    class FWCraftingWorkbench_Military : FWCraftingWorkbench
    {
        scope = 2;
        displayName = "Military Workbench";
        descriptionShort = "A military-grade workbench with precision tools.";
        
        // More cargo space
        itemsCargoSize[] = {12, 12};
        
        // No attachment slots needed
        attachments[] = {};
    };
    
    // ============================================
    // CIVILIAN VARIANT
    // ============================================
    class FWCraftingWorkbench_Civilian : FWCraftingWorkbench
    {
        scope = 2;
        displayName = "Civilian Workbench";
        descriptionShort = "A basic workbench for simple crafting.";
        
        // Less cargo space
        itemsCargoSize[] = {8, 8};
        
        // No attachment slots needed
        attachments[] = {};
    };
};
