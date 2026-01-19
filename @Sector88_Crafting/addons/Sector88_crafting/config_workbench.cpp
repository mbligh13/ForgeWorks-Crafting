// Sector 88 Crafting - Workbench Config
// This file defines the craftable workbench objects
// Add this to your main config.cpp or create a separate PBO

class CfgPatches
{
    class Sector88_CraftingWorkbench
    {
        units[] = {
            "S88CraftingWorkbench",
            "S88CraftingWorkbench_Military",
            "S88CraftingWorkbench_Civilian"
        };
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Gear_Tools"};
    };
};

class CfgVehicles
{
    // Base game workbench for inheritance
    class Inventory_Base;
    class Workbench;
    
    // ============================================
    // S88 CRAFTING WORKBENCH - BASE
    // ============================================
    class S88CraftingWorkbench : Inventory_Base
    {
        scope = 2;
        displayName = "Sector 88 Workbench";
        descriptionShort = "A well-equipped workbench for crafting weapons and equipment.";
        // Use the custom Sector88 workbench model from the mod's models folder
        model = "\sector88_weaponparts\data\models\work_bench.p3d";
        
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
        
        // No attachment slots needed
        
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
    class S88CraftingWorkbench_Military : S88CraftingWorkbench
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
    class S88CraftingWorkbench_Civilian : S88CraftingWorkbench
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

// No attachment slots needed for crafting
