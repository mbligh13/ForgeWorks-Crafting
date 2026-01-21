class CfgPatches
{
    class ForgeWorks_WeaponParts
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgMods
{
    class ForgeWorks_WeaponParts
    {
        dir = "forgeworks_weaponparts";
        name = "ForgeWorks Weapon Parts System";
        picture = "";
        action = "";
        hideName = 0;
        hidePicture = 0;
        credits = "Sector 88 Dev Team";
        author = "Rook";
        extra = 0;
        type = "mod";
    };
};

class CfgVehicles
{
    class Inventory_Base;

    // ===========================
    // BASE CLASS FOR ALL NEW PARTS
    // ===========================
    class FW_PartBase: Inventory_Base
    {
        scope = 0;
        weight = 250;
        itemSize[] = {2,2};
        inventorySlot[] = {};
        varQuantityInit = 0;
        varQuantityMin = 0;
        varQuantityMax = 0;
        destroyOnEmpty = 0;
        canBeSplit = 0;
        absorbency = 0;
        rotationFlags = 17;
        
        // Prevent items from being held in hands (fixes crash)
        canBeMovedOverride = 1;
        itemBehaviour = 0;

        // ICON PATH (will be set per item)
        hiddenSelections[] = {"zbytek"};
        hiddenSelectionsTextures[] = {""};
        hiddenSelectionsMaterials[] = {""};
        
        // Inventory icon (2D display)
        inventoryIcon[] = {};
    };
// =====================================================
// SECTION 2 — SHARED MATERIALS (SPRINGS, METAL SHEETS)
// =====================================================

    // ---------------------------
    // SPRINGS (shared crafting)
    // ---------------------------

    class FW_Spring_Small: FW_PartBase
    {
        scope = 2;
        displayName = "Small Spring";
        descriptionShort = "A small tension spring used in crafting lower-tier magazines and pistol-caliber firearm components.";
        model = "\forgeworks_weaponparts\data\models\small_spring.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 50;
        itemSize[] = {1,1};
    };

    class FW_Spring_Large: FW_PartBase
    {
        scope = 2;
        displayName = "Large Spring";
        descriptionShort = "A heavy-duty spring used in crafting high-capacity magazines and advanced rifle components.";
        model = "\forgeworks_weaponparts\data\models\large_spring.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 80;
        itemSize[] = {1,2};
    };

    // ---------------------------
    // METAL SHEETS (shared crafting)
    // ---------------------------

    class FW_SheetMetal_Small: FW_PartBase
    {
        scope = 2;
        displayName = "Small Sheet Metal";
        descriptionShort = "Light sheet metal used for crafting magazine bodies and firearm internals.";
        model = "\forgeworks_weaponparts\data\models\small_sheet_metal.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 100;
        itemSize[] = {2,1};
    };

    class FW_SheetMetal_Large: FW_PartBase
    {
        scope = 2;
        displayName = "Large Sheet Metal";
        descriptionShort = "Reinforced sheet metal used for heavy magazines, advanced receivers, and high-caliber firearm components.";
        model = "\forgeworks_weaponparts\data\models\small_sheet_metal.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 150;
        itemSize[] = {2,2};
    };

// =====================================================
// SECTION 2B — PISTOL PARTS (RECEIVER & HANDLE)
// =====================================================

    // ---------------------------
    // BASE PISTOL RECEIVER CLASS
    // ---------------------------

    class FW_PistolReceiver_Base: FW_PartBase
    {
        scope = 0;
        // Corrected model path to existing file name
        model = "\forgeworks_weaponparts\data\models\pistol_reciever.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 250;
        itemSize[] = {2,1};
    };

    // ---------------------------
    // PISTOL CALIBER RECEIVERS
    // ---------------------------

    class FW_PistolReceiver_22: FW_PistolReceiver_Base
    {
        scope = 2;
        displayName = "Pistol Receiver (.22 LR)";
        descriptionShort = "A compact .22 LR pistol receiver frame used for small-caliber handguns.";
    };

    class FW_PistolReceiver_9mm: FW_PistolReceiver_Base
    {
        scope = 2;
        displayName = "Pistol Receiver (9×19mm)";
        descriptionShort = "A 9×19mm pistol receiver compatible with most modern handgun platforms.";
    };

    class FW_PistolReceiver_45ACP: FW_PistolReceiver_Base
    {
        scope = 2;
        displayName = "Pistol Receiver (.45 ACP)";
        descriptionShort = "A heavy-frame .45 ACP pistol receiver designed for large-caliber handguns.";
    };

    class FW_PistolReceiver_762x25: FW_PistolReceiver_Base
    {
        scope = 2;
        displayName = "Pistol Receiver (7.62×25)";
        descriptionShort = "A 7.62×25 Tokarev pistol receiver used in historical military sidearms.";
    };

    class FW_PistolReceiver_380: FW_PistolReceiver_Base
    {
        scope = 2;
        displayName = "Pistol Receiver (.380 ACP)";
        descriptionShort = "A compact .380 ACP pistol receiver for pocket and concealment pistols.";
    };

    // ---------------------------
    // BASE PISTOL HANDLE CLASS
    // ---------------------------

    class FW_PistolHandle_Base: FW_PartBase
    {
        scope = 0;
        model = "\forgeworks_weaponparts\data\models\pistol_handle.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 200;
        itemSize[] = {1,2};
    };

    // ---------------------------
    // PISTOL CALIBER HANDLES
    // ---------------------------

    class FW_PistolHandle_22: FW_PistolHandle_Base
    {
        scope = 2;
        displayName = "Pistol Handle (.22 LR)";
        descriptionShort = "A lightweight grip and trigger assembly for .22 LR pistols.";
    };

    class FW_PistolHandle_9mm: FW_PistolHandle_Base
    {
        scope = 2;
        displayName = "Pistol Handle (9×19mm)";
        descriptionShort = "A polymer or metal pistol grip designed for 9×19mm handguns.";
    };

    class FW_PistolHandle_45ACP: FW_PistolHandle_Base
    {
        scope = 2;
        displayName = "Pistol Handle (.45 ACP)";
        descriptionShort = "A reinforced pistol grip for handling the recoil of .45 ACP rounds.";
    };

    class FW_PistolHandle_762x25: FW_PistolHandle_Base
    {
        scope = 2;
        displayName = "Pistol Handle (7.62×25)";
        descriptionShort = "A wooden or bakelite grip from classic Tokarev-pattern pistols.";
    };

    class FW_PistolHandle_380: FW_PistolHandle_Base
    {
        scope = 2;
        displayName = "Pistol Handle (.380 ACP)";
        descriptionShort = "A compact grip for small-frame .380 ACP pistols.";
    };

// =====================================================
// SECTION 3 — BARREL DEFINITIONS (ALL CALIBERS)
// =====================================================

    // ---------------------------
    // BASE BARREL CLASS
    // ---------------------------

    class FW_Barrel_Base: FW_PartBase
    {
        scope = 0;
        model = "\forgeworks_weaponparts\data\models\barrel.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 350;
        itemSize[] = {3,1};
    };

    // ---------------------------
    // TIER 3 — PISTOL CALIBERS
    // ---------------------------

    class FW_Barrel_22: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.22 LR)";
        descriptionShort = "A lightweight .22 LR barrel, suitable for small-caliber improvised or low-tier pistols.";
    };

    class FW_Barrel_9mm: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (9×19mm)";
        descriptionShort = "A 9×19mm pistol-caliber barrel. Balanced, compact, and widely compatible with modern platforms.";
    };

    class FW_Barrel_45ACP: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.45 ACP)";
        descriptionShort = "A .45 ACP barrel intended for mid-tier handguns and compact SMGs.";
    };

    class FW_Barrel_762x25: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (7.62×25 Tokarev)";
        descriptionShort = "A 7.62×25 barrel compatible with specialty SMGs and certain historical sidearms.";
    };

    class FW_Barrel_380: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.380 ACP)";
        descriptionShort = "A compact .380 ACP barrel used in small pocket pistols and backup firearms.";
    };

    // ---------------------------
    // TIER 4–5 — INTERMEDIATE CALIBERS
    // ---------------------------

    class FW_Barrel_556: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (5.56×45)";
        descriptionShort = "A 5.56×45 NATO barrel. Standard for modern AR-platform rifles.";
    };

    class FW_Barrel_545: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (5.45×39)";
        descriptionShort = "A 5.45×39 barrel used in AK-74 pattern rifles. Lightweight and accurate.";
    };

    class FW_Barrel_300BLK: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.300 Blackout)";
        descriptionShort = "A .300 Blackout barrel designed for suppressed AR builds and close-quarters rifles.";
    };

    class FW_Barrel_762x39: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (7.62×39)";
        descriptionShort = "A rugged 7.62×39 barrel used in AK-pattern weapons and mid-tier battle rifles.";
    };

    class FW_Barrel_939: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (9×39)";
        descriptionShort = "A heavy suppressed-oriented 9×39 barrel, typically used in VSS and AS VAL platforms.";
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class FW_Barrel_762x54: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (7.62×54R)";
        descriptionShort = "A high-pressure sniper-grade barrel chambered in 7.62×54R.";
    };

    class FW_Barrel_308: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.308 Winchester)";
        descriptionShort = "A precision .308 Win barrel suited for DMR and battle rifle builds.";
    };

    class FW_Barrel_300WM: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.300 Winchester Magnum)";
        descriptionShort = "A high-powered long-range sniper barrel chambered in .300 WinMag.";
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class FW_Barrel_338: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.338 Lapua Magnum)";
        descriptionShort = "A precision-engineered .338 Lapua Magnum barrel for extreme long-range accuracy.";
    };

    // ---------------------------
    // TIER 8 — ULTRA CALIBERS
    // ---------------------------

    class FW_Barrel_408: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.408 CheyTac)";
        descriptionShort = "An ultra-high-performance .408 CheyTac barrel. Extremely rare and valuable.";
    };

    class FW_Barrel_50: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.50 BMG)";
        descriptionShort = "A massive .50 BMG barrel used for anti-materiel rifles. Extremely rare.";
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL CALIBERS
    // ---------------------------

    class FW_Barrel_8mm: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (8mm)";
        descriptionShort = "An 8mm barrel typically used for historical bolt-action rifles.";
    };

    // ---------------------------
    // SHOTGUNS — 12 GAUGE
    // ---------------------------

    class FW_Barrel_12Gauge: FW_Barrel_Base
    {
        scope = 2;
        displayName = "Shotgun Barrel (12 Gauge)";
        descriptionShort = "A 12-gauge shotgun barrel suitable for pump-action and semi-automatic shotguns.";
    };
// =====================================================
// SECTION 4 — LOWER RECEIVERS (ALL CALIBERS)
// =====================================================

    // ---------------------------
    // BASE LOWER RECEIVER CLASS
    // ---------------------------

    class FW_LowerReceiver_Base: FW_PartBase
    {
        scope = 0;
        model = "\forgeworks_weaponparts\data\models\lower_receiver.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 350;
        itemSize[] = {2,2};
    };

    // ---------------------------
    // TIER 3 — PISTOL CALIBERS
    // ---------------------------

    class FW_LowerReceiver_22: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.22 LR)";
        descriptionShort = "A lower receiver configured for .22 LR platforms. Used in light pistols and training weapons.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_9mm: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (9×19mm)";
        descriptionShort = "A lower receiver built for 9×19mm pistols and SMG platforms.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_45ACP: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.45 ACP)";
        descriptionShort = "A lower receiver engineered for .45 ACP platforms. Compatible with mid-tier handguns and compact carbines.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_762x25: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (7.62×25)";
        descriptionShort = "A 7.62×25 lower receiver used for specialty SMG and pistol conversions.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_380: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.380 ACP)";
        descriptionShort = "A compact lower receiver for .380 ACP pocket pistols.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 4–5 — INTERMEDIATE CALIBERS
    // ---------------------------

    class FW_LowerReceiver_556: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (5.56×45)";
        descriptionShort = "A lower receiver for 5.56×45 AR-platform rifles. Widely compatible with modern parts.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_545: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (5.45×39)";
        descriptionShort = "A lower receiver for 5.45×39 AK-74 pattern rifles. Standard Soviet-era configuration.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_300BLK: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.300 Blackout)";
        descriptionShort = "A specialized lower receiver for .300 Blackout rifles, typically used in suppressed configurations.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_762x39: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (7.62×39)";
        descriptionShort = "A rugged lower receiver built for AK-pattern rifles and 7.62×39 conversions.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_939: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (9×39)";
        descriptionShort = "A heavy-duty lower receiver for 9×39 integrally suppressed rifles.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class FW_LowerReceiver_762x54: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (7.62×54R)";
        descriptionShort = "A precision lower receiver for classic 7.62×54R marksman rifles.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_308: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.308 Winchester)";
        descriptionShort = "A lower receiver built for .308 Win battle rifles and designated marksman platforms.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_300WM: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.300 WinMag)";
        descriptionShort = "A reinforced lower receiver engineered to handle the high pressure of .300 WinMag.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class FW_LowerReceiver_338: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.338 Lapua)";
        descriptionShort = "A precision-machined lower receiver for .338 Lapua Magnum sniper systems.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 8 — ULTRA CALIBERS
    // ---------------------------

    class FW_LowerReceiver_408: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.408 CheyTac)";
        descriptionShort = "An extremely rare lower receiver calibrated for .408 CheyTac anti-personnel rifles.";
        // Use model materials; no hiddenSelections override
    };

    class FW_LowerReceiver_50: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.50 BMG)";
        descriptionShort = "A reinforced .50 BMG lower receiver designed for anti-materiel platforms.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL CALIBERS
    // ---------------------------

    class FW_LowerReceiver_8mm: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (8mm)";
        descriptionShort = "A lower receiver for classic 8mm bolt-action rifles.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // SHOTGUNS — 12 GAUGE
    // ---------------------------

    class FW_LowerReceiver_12Gauge: FW_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Shotgun Lower Receiver (12 Gauge)";
        descriptionShort = "A 12-gauge lower receiver for pump-action and semi-automatic shotguns.";
        // Use model materials; no hiddenSelections override
    };
// =====================================================
// SECTION 5 — UPPER RECEIVERS (ALL CALIBERS)
// =====================================================

    // ---------------------------
    // BASE UPPER RECEIVER CLASS
    // ---------------------------

    class FW_UpperReceiver_Base: FW_PartBase
    {
        scope = 0;
        model = "\forgeworks_weaponparts\data\models\upper_receiver.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 380;
        itemSize[] = {2,2};
    };

    // ---------------------------
    // TIER 3 — PISTOL CALIBERS
    // ---------------------------

    class FW_UpperReceiver_22: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.22 LR)";
        descriptionShort = "A .22 LR upper receiver designed for lightweight small-caliber pistol builds.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_9mm: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (9×19mm)";
        descriptionShort = "A 9×19mm upper receiver used for various pistol-caliber builds and compact SMGs.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_45ACP: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.45 ACP)";
        descriptionShort = "A .45 ACP upper receiver compatible with heavy-frame pistols and SMGs.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_762x25: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (7.62×25)";
        descriptionShort = "An upper receiver built for the fast, high-velocity 7.62×25 cartridge.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_380: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.380 ACP)";
        descriptionShort = "A compact upper receiver for .380 ACP pocket pistols and derringers.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 4–5 — INTERMEDIATE RIFLE CALIBERS
    // ---------------------------

    class FW_UpperReceiver_556: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (5.56×45)";
        descriptionShort = "A 5.56×45 NATO upper receiver, standard in many AR-platform rifles.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_545: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (5.45×39)";
        descriptionShort = "A 5.45×39 upper receiver for AK-74 pattern rifles. Lightweight and reliable.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_300BLK: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.300 Blackout)";
        descriptionShort = "A .300 Blackout upper receiver optimized for suppressed builds.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_762x39: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (7.62×39)";
        descriptionShort = "A 7.62×39 upper receiver designed for AK-pattern and hybrid rifle systems.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_939: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (9×39)";
        descriptionShort = "A heavy-duty upper receiver compatible with suppressed 9×39 rifle systems.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class FW_UpperReceiver_762x54: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (7.62×54R)";
        descriptionShort = "A hardened upper receiver intended for long-range 7.62×54R marksman rifles.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_308: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.308 Winchester)";
        descriptionShort = "A .308 Win upper receiver engineered for precision DMR and battle rifle builds.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_300WM: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.300 WinMag)";
        descriptionShort = "A reinforced upper receiver capable of handling the high-pressure .300 WinMag cartridge.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class FW_UpperReceiver_338: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.338 Lapua)";
        descriptionShort = "A precision-crafted upper receiver made for elite .338 Lapua Magnum sniper systems.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 8 — ULTRA CALIBERS
    // ---------------------------

    class FW_UpperReceiver_408: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.408 CheyTac)";
        descriptionShort = "An extremely rare and powerful upper receiver for .408 CheyTac platforms.";
        // Use model materials; no hiddenSelections override
    };

    class FW_UpperReceiver_50: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.50 BMG)";
        descriptionShort = "A massive reinforced upper receiver intended for .50 BMG anti-materiel rifles.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL CALIBERS
    // ---------------------------

    class FW_UpperReceiver_8mm: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (8mm)";
        descriptionShort = "An upper receiver for powerful 8mm historical rifles.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // SHOTGUNS — 12 GAUGE (NO BOLT)
    // ---------------------------

    class FW_UpperReceiver_12Gauge: FW_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Shotgun Upper Receiver (12 Gauge)";
        descriptionShort = "A 12-gauge upper receiver compatible with pump-action and semi-automatic shotgun builds.";
        // Use model materials; no hiddenSelections override
    };
// =====================================================
// SECTION 6 — BOLT ASSEMBLIES (DMR & SNIPER CALIBERS)
// =====================================================

    // ---------------------------
    // BASE BOLT CLASS
    // ---------------------------

    class FW_Bolt_Base: FW_PartBase
    {
        scope = 0;
        model = "\forgeworks_weaponparts\data\models\bolt.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 200;
        itemSize[] = {1,2};
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class FW_Bolt_762x54: FW_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (7.62×54R)";
        descriptionShort = "A bolt assembly designed for powerful 7.62×54R marksman rifles.";
        // Use model materials; no hiddenSelections override
    };

    class FW_Bolt_308: FW_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.308 Winchester)";
        descriptionShort = "A precision-machined bolt assembly for .308 Win DMR platforms.";
        // Use model materials; no hiddenSelections override
    };

    class FW_Bolt_300WM: FW_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.300 WinMag)";
        descriptionShort = "A reinforced bolt assembly capable of handling high-pressure .300 WinMag loads.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class FW_Bolt_338: FW_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.338 Lapua Magnum)";
        descriptionShort = "A precision bolt assembly used in elite .338 Lapua Magnum sniper systems.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 8 — ULTRA SNIPER CALIBERS
    // ---------------------------

    class FW_Bolt_408: FW_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.408 CheyTac)";
        descriptionShort = "An extremely rare bolt assembly engineered for .408 CheyTac anti-personnel rifles.";
        // Use model materials; no hiddenSelections override
    };

    class FW_Bolt_50: FW_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.50 BMG)";
        descriptionShort = "A massive bolt assembly used in .50 BMG anti-materiel rifle platforms.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL
    // ---------------------------

    class FW_Bolt_8mm: FW_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (8mm)";
        descriptionShort = "A traditional bolt assembly for powerful 8mm historical rifles.";
        // Use model materials; no hiddenSelections override
    };
// =====================================================
// SECTION 7 — MAGAZINE CRAFTING (LOGIC ONLY, NO ITEMS)
// =====================================================
//
// Note:
// Magazine crafting for all calibers is handled purely
// by Expansion crafting recipes using:
//
//   FW_Spring_Small
//   FW_Spring_Large
//   FW_SheetMetal_Small
//   FW_SheetMetal_Large
//
// No dedicated MagazineBody_* item classes are used.
// The bench behaves like a vending machine: the amount
// and size of springs/metal determines which existing
// Vanilla/Expansion/AJ's magazines can be crafted.
//
// Item definitions are therefore not required here.
// All logic will live in JSON recipes under:
//   config/ExpansionMod/Crafting/forgeworks/
//
// =====================================================
// SECTION 8 — ULTRA-RARE UPGRADE PARTS (TIER 8 ONLY)
// =====================================================

    // ---------------------------
    // BASE CLASS FOR UPGRADES
    // ---------------------------

    class FW_Upgrade_Base: FW_PartBase
    {
        scope = 0;
        model = "\forgeworks_weaponparts\data\models\lower_receiver.p3d";
        weight = 150;
        itemSize[] = {2,1};
    };

    // ---------------------------
    // MATCH-GRADE BARREL LINER
    // ---------------------------

    class FW_BarrelLiner_MatchGrade: FW_Upgrade_Base
    {
        scope = 2;
        displayName = "Match-Grade Barrel Liner";
        descriptionShort = "A premium-grade barrel liner engineered with exceptional precision. Install inside a rifle barrel to increase accuracy and bullet velocity.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // PRECISION BOLT ASSEMBLY
    // ---------------------------

    class FW_BoltAssembly_Precision: FW_Upgrade_Base
    {
        scope = 2;
        displayName = "Precision Bolt Assembly";
        descriptionShort = "A finely machined bolt assembly designed for improved cycling and smoother bolt operation.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // REINFORCED RECEIVER BRACKET
    // ---------------------------

    class FW_ReceiverBracket_Reinforced: FW_Upgrade_Base
    {
        scope = 2;
        displayName = "Reinforced Receiver Bracket";
        descriptionShort = "A high-strength support bracket used to reinforce a rifle’s receiver, reducing wear and recoil.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // ELITE BUFFER SPRING
    // ---------------------------

    class FW_Spring_Elite: FW_Upgrade_Base
    {
        scope = 2;
        displayName = "Elite Buffer Spring";
        descriptionShort = "A top-tier buffer spring crafted from advanced alloys, allowing smoother recoil control and faster semi-auto shot recovery.";
        // Use model materials; no hiddenSelections override
        weight = 80;
        itemSize[] = {1,2};
    };
}; // END OF CfgVehicles
