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
        model = "\DZ\gear\camping\WorkBench.p3d";
        
        // Physics
        physLayer = "item_large";
        weight = 50000;
        heavyItem = 1;
        
        // Inventory
        itemsCargoSize[] = {10, 5};
        
        // Attachment slots for tools
        attachments[] = {
            "BPGrinder",
            "BPCutting_saw", 
            "BPDrill",
            "BPHammer",
            "BPWrench"
        };
        
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
        
        class GUIInventoryAttachmentsProps
        {
            class Tools
            {
                name = "Tools";
                description = "";
                attachmentSlots[] = {
                    "BPGrinder",
                    "BPCutting_saw",
                    "BPDrill",
                    "BPHammer",
                    "BPWrench"
                };
                icon = "set:dayz_inventory image:cat_common_cargo";
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
    class S88CraftingWorkbench_Military : S88CraftingWorkbench
    {
        scope = 2;
        displayName = "Military Workbench";
        descriptionShort = "A military-grade workbench with precision tools.";
        
        // More cargo space
        itemsCargoSize[] = {12, 6};
        
        // Additional attachment slots
        attachments[] = {
            "BPGrinder",
            "BPCutting_saw",
            "BPDrill",
            "BPHammer",
            "BPWrench",
            "BPVise",
            "BPPress"
        };
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
        itemsCargoSize[] = {8, 4};
        
        // Fewer attachment slots
        attachments[] = {
            "BPGrinder",
            "BPHammer",
            "BPWrench"
        };
    };
};

class CfgSlots
{
    class Slot_BPGrinder
    {
        name = "BPGrinder";
        displayName = "Grinder";
        ghostIcon = "set:dayz_inventory image:grinder";
    };
    class Slot_BPCutting_saw
    {
        name = "BPCutting_saw";
        displayName = "Cutting Saw";
        ghostIcon = "set:dayz_inventory image:hacksaw";
    };
    class Slot_BPDrill
    {
        name = "BPDrill";
        displayName = "Drill";
        ghostIcon = "set:dayz_inventory image:drill";
    };
    class Slot_BPHammer
    {
        name = "BPHammer";
        displayName = "Hammer";
        ghostIcon = "set:dayz_inventory image:hammer";
    };
    class Slot_BPWrench
    {
        name = "BPWrench";
        displayName = "Wrench";
        ghostIcon = "set:dayz_inventory image:wrench";
    };
    class Slot_BPVise
    {
        name = "BPVise";
        displayName = "Vise";
        ghostIcon = "set:dayz_inventory image:vise";
    };
    class Slot_BPPress
    {
        name = "BPPress";
        displayName = "Press";
        ghostIcon = "set:dayz_inventory image:press";
    };
};
