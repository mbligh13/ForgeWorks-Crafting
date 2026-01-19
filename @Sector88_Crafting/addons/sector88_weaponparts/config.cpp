class CfgPatches
{
    class Sector88_WeaponParts
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgMods
{
    class Sector88_WeaponParts
    {
        dir = "sector88_weaponparts";
        name = "Sector 88 Weapon Parts System";
        picture = "";
        action = "";
        hideName = 0;
        hidePicture = 0;
        credits = "Sector 88";
        author = "Sector 88 Dev Team";
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
    class S88_PartBase: Inventory_Base
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

    class S88_Spring_Small: S88_PartBase
    {
        scope = 2;
        displayName = "Small Spring";
        descriptionShort = "A small tension spring used in crafting lower-tier magazines and pistol-caliber firearm components.";
        model = "\sector88_weaponparts\data\models\small_spring.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 50;
        itemSize[] = {1,1};
    };

    class S88_Spring_Large: S88_PartBase
    {
        scope = 2;
        displayName = "Large Spring";
        descriptionShort = "A heavy-duty spring used in crafting high-capacity magazines and advanced rifle components.";
        model = "\sector88_weaponparts\data\models\large_spring.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 80;
        itemSize[] = {1,2};
    };

    // ---------------------------
    // METAL SHEETS (shared crafting)
    // ---------------------------

    class S88_SheetMetal_Small: S88_PartBase
    {
        scope = 2;
        displayName = "Small Sheet Metal";
        descriptionShort = "Light sheet metal used for crafting magazine bodies and firearm internals.";
        model = "\sector88_weaponparts\data\models\small_sheet_metal.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 100;
        itemSize[] = {2,1};
    };

    class S88_SheetMetal_Large: S88_PartBase
    {
        scope = 2;
        displayName = "Large Sheet Metal";
        descriptionShort = "Reinforced sheet metal used for heavy magazines, advanced receivers, and high-caliber firearm components.";
        model = "\sector88_weaponparts\data\models\small_sheet_metal.p3d";
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

    class S88_PistolReceiver_Base: S88_PartBase
    {
        scope = 0;
        // Corrected model path to existing file name
        model = "\sector88_weaponparts\data\models\pistol_reciever.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 250;
        itemSize[] = {2,1};
    };

    // ---------------------------
    // PISTOL CALIBER RECEIVERS
    // ---------------------------

    class PistolReceiver_22: S88_PistolReceiver_Base
    {
        scope = 2;
        displayName = "Pistol Receiver (.22 LR)";
        descriptionShort = "A compact .22 LR pistol receiver frame used for small-caliber handguns.";
    };

    class PistolReceiver_9mm: S88_PistolReceiver_Base
    {
        scope = 2;
        displayName = "Pistol Receiver (9×19mm)";
        descriptionShort = "A 9×19mm pistol receiver compatible with most modern handgun platforms.";
    };

    class PistolReceiver_45ACP: S88_PistolReceiver_Base
    {
        scope = 2;
        displayName = "Pistol Receiver (.45 ACP)";
        descriptionShort = "A heavy-frame .45 ACP pistol receiver designed for large-caliber handguns.";
    };

    class PistolReceiver_762x25: S88_PistolReceiver_Base
    {
        scope = 2;
        displayName = "Pistol Receiver (7.62×25)";
        descriptionShort = "A 7.62×25 Tokarev pistol receiver used in historical military sidearms.";
    };

    class PistolReceiver_380: S88_PistolReceiver_Base
    {
        scope = 2;
        displayName = "Pistol Receiver (.380 ACP)";
        descriptionShort = "A compact .380 ACP pistol receiver for pocket and concealment pistols.";
    };

    // ---------------------------
    // BASE PISTOL HANDLE CLASS
    // ---------------------------

    class S88_PistolHandle_Base: S88_PartBase
    {
        scope = 0;
        model = "\sector88_weaponparts\data\models\pistol_handle.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 200;
        itemSize[] = {1,2};
    };

    // ---------------------------
    // PISTOL CALIBER HANDLES
    // ---------------------------

    class PistolHandle_22: S88_PistolHandle_Base
    {
        scope = 2;
        displayName = "Pistol Handle (.22 LR)";
        descriptionShort = "A lightweight grip and trigger assembly for .22 LR pistols.";
    };

    class PistolHandle_9mm: S88_PistolHandle_Base
    {
        scope = 2;
        displayName = "Pistol Handle (9×19mm)";
        descriptionShort = "A polymer or metal pistol grip designed for 9×19mm handguns.";
    };

    class PistolHandle_45ACP: S88_PistolHandle_Base
    {
        scope = 2;
        displayName = "Pistol Handle (.45 ACP)";
        descriptionShort = "A reinforced pistol grip for handling the recoil of .45 ACP rounds.";
    };

    class PistolHandle_762x25: S88_PistolHandle_Base
    {
        scope = 2;
        displayName = "Pistol Handle (7.62×25)";
        descriptionShort = "A wooden or bakelite grip from classic Tokarev-pattern pistols.";
    };

    class PistolHandle_380: S88_PistolHandle_Base
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

    class S88_Barrel_Base: S88_PartBase
    {
        scope = 0;
        model = "\sector88_weaponparts\data\models\barrel.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 350;
        itemSize[] = {3,1};
    };

    // ---------------------------
    // TIER 3 — PISTOL CALIBERS
    // ---------------------------

    class Barrel_22: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.22 LR)";
        descriptionShort = "A lightweight .22 LR barrel, suitable for small-caliber improvised or low-tier pistols.";
    };

    class Barrel_9mm: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (9×19mm)";
        descriptionShort = "A 9×19mm pistol-caliber barrel. Balanced, compact, and widely compatible with modern platforms.";
    };

    class Barrel_45ACP: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.45 ACP)";
        descriptionShort = "A .45 ACP barrel intended for mid-tier handguns and compact SMGs.";
    };

    class Barrel_762x25: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (7.62×25 Tokarev)";
        descriptionShort = "A 7.62×25 barrel compatible with specialty SMGs and certain historical sidearms.";
    };

    class Barrel_380: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.380 ACP)";
        descriptionShort = "A compact .380 ACP barrel used in small pocket pistols and backup firearms.";
    };

    // ---------------------------
    // TIER 4–5 — INTERMEDIATE CALIBERS
    // ---------------------------

    class Barrel_556: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (5.56×45)";
        descriptionShort = "A 5.56×45 NATO barrel. Standard for modern AR-platform rifles.";
    };

    class Barrel_545: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (5.45×39)";
        descriptionShort = "A 5.45×39 barrel used in AK-74 pattern rifles. Lightweight and accurate.";
    };

    class Barrel_300BLK: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.300 Blackout)";
        descriptionShort = "A .300 Blackout barrel designed for suppressed AR builds and close-quarters rifles.";
    };

    class Barrel_762x39: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (7.62×39)";
        descriptionShort = "A rugged 7.62×39 barrel used in AK-pattern weapons and mid-tier battle rifles.";
    };

    class Barrel_939: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (9×39)";
        descriptionShort = "A heavy suppressed-oriented 9×39 barrel, typically used in VSS and AS VAL platforms.";
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class Barrel_762x54: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (7.62×54R)";
        descriptionShort = "A high-pressure sniper-grade barrel chambered in 7.62×54R.";
    };

    class Barrel_308: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.308 Winchester)";
        descriptionShort = "A precision .308 Win barrel suited for DMR and battle rifle builds.";
    };

    class Barrel_300WM: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.300 Winchester Magnum)";
        descriptionShort = "A high-powered long-range sniper barrel chambered in .300 WinMag.";
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class Barrel_338: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.338 Lapua Magnum)";
        descriptionShort = "A precision-engineered .338 Lapua Magnum barrel for extreme long-range accuracy.";
    };

    // ---------------------------
    // TIER 8 — ULTRA CALIBERS
    // ---------------------------

    class Barrel_408: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.408 CheyTac)";
        descriptionShort = "An ultra-high-performance .408 CheyTac barrel. Extremely rare and valuable.";
    };

    class Barrel_50: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.50 BMG)";
        descriptionShort = "A massive .50 BMG barrel used for anti-materiel rifles. Extremely rare.";
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL CALIBERS
    // ---------------------------

    class Barrel_8mm: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (8mm)";
        descriptionShort = "An 8mm barrel typically used for historical bolt-action rifles.";
    };

    // ---------------------------
    // SHOTGUNS — 12 GAUGE
    // ---------------------------

    class Barrel_12Gauge: S88_Barrel_Base
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

    class S88_LowerReceiver_Base: S88_PartBase
    {
        scope = 0;
        model = "\sector88_weaponparts\data\models\lower_receiver.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 350;
        itemSize[] = {2,2};
    };

    // ---------------------------
    // TIER 3 — PISTOL CALIBERS
    // ---------------------------

    class LowerReceiver_22: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.22 LR)";
        descriptionShort = "A lower receiver configured for .22 LR platforms. Used in light pistols and training weapons.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_9mm: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (9×19mm)";
        descriptionShort = "A lower receiver built for 9×19mm pistols and SMG platforms.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_45ACP: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.45 ACP)";
        descriptionShort = "A lower receiver engineered for .45 ACP platforms. Compatible with mid-tier handguns and compact carbines.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_762x25: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (7.62×25)";
        descriptionShort = "A 7.62×25 lower receiver used for specialty SMG and pistol conversions.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_380: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.380 ACP)";
        descriptionShort = "A compact lower receiver for .380 ACP pocket pistols.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 4–5 — INTERMEDIATE CALIBERS
    // ---------------------------

    class LowerReceiver_556: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (5.56×45)";
        descriptionShort = "A lower receiver for 5.56×45 AR-platform rifles. Widely compatible with modern parts.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_545: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (5.45×39)";
        descriptionShort = "A lower receiver for 5.45×39 AK-74 pattern rifles. Standard Soviet-era configuration.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_300BLK: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.300 Blackout)";
        descriptionShort = "A specialized lower receiver for .300 Blackout rifles, typically used in suppressed configurations.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_762x39: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (7.62×39)";
        descriptionShort = "A rugged lower receiver built for AK-pattern rifles and 7.62×39 conversions.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_939: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (9×39)";
        descriptionShort = "A heavy-duty lower receiver for 9×39 integrally suppressed rifles.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class LowerReceiver_762x54: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (7.62×54R)";
        descriptionShort = "A precision lower receiver for classic 7.62×54R marksman rifles.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_308: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.308 Winchester)";
        descriptionShort = "A lower receiver built for .308 Win battle rifles and designated marksman platforms.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_300WM: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.300 WinMag)";
        descriptionShort = "A reinforced lower receiver engineered to handle the high pressure of .300 WinMag.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class LowerReceiver_338: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.338 Lapua)";
        descriptionShort = "A precision-machined lower receiver for .338 Lapua Magnum sniper systems.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 8 — ULTRA CALIBERS
    // ---------------------------

    class LowerReceiver_408: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.408 CheyTac)";
        descriptionShort = "An extremely rare lower receiver calibrated for .408 CheyTac anti-personnel rifles.";
        // Use model materials; no hiddenSelections override
    };

    class LowerReceiver_50: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.50 BMG)";
        descriptionShort = "A reinforced .50 BMG lower receiver designed for anti-materiel platforms.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL CALIBERS
    // ---------------------------

    class LowerReceiver_8mm: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (8mm)";
        descriptionShort = "A lower receiver for classic 8mm bolt-action rifles.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // SHOTGUNS — 12 GAUGE
    // ---------------------------

    class LowerReceiver_12Gauge: S88_LowerReceiver_Base
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

    class S88_UpperReceiver_Base: S88_PartBase
    {
        scope = 0;
        model = "\sector88_weaponparts\data\models\upper_receiver.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 380;
        itemSize[] = {2,2};
    };

    // ---------------------------
    // TIER 3 — PISTOL CALIBERS
    // ---------------------------

    class UpperReceiver_22: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.22 LR)";
        descriptionShort = "A .22 LR upper receiver designed for lightweight small-caliber pistol builds.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_9mm: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (9×19mm)";
        descriptionShort = "A 9×19mm upper receiver used for various pistol-caliber builds and compact SMGs.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_45ACP: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.45 ACP)";
        descriptionShort = "A .45 ACP upper receiver compatible with heavy-frame pistols and SMGs.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_762x25: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (7.62×25)";
        descriptionShort = "An upper receiver built for the fast, high-velocity 7.62×25 cartridge.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_380: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.380 ACP)";
        descriptionShort = "A compact upper receiver for .380 ACP pocket pistols and derringers.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 4–5 — INTERMEDIATE RIFLE CALIBERS
    // ---------------------------

    class UpperReceiver_556: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (5.56×45)";
        descriptionShort = "A 5.56×45 NATO upper receiver, standard in many AR-platform rifles.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_545: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (5.45×39)";
        descriptionShort = "A 5.45×39 upper receiver for AK-74 pattern rifles. Lightweight and reliable.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_300BLK: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.300 Blackout)";
        descriptionShort = "A .300 Blackout upper receiver optimized for suppressed builds.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_762x39: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (7.62×39)";
        descriptionShort = "A 7.62×39 upper receiver designed for AK-pattern and hybrid rifle systems.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_939: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (9×39)";
        descriptionShort = "A heavy-duty upper receiver compatible with suppressed 9×39 rifle systems.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class UpperReceiver_762x54: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (7.62×54R)";
        descriptionShort = "A hardened upper receiver intended for long-range 7.62×54R marksman rifles.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_308: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.308 Winchester)";
        descriptionShort = "A .308 Win upper receiver engineered for precision DMR and battle rifle builds.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_300WM: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.300 WinMag)";
        descriptionShort = "A reinforced upper receiver capable of handling the high-pressure .300 WinMag cartridge.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class UpperReceiver_338: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.338 Lapua)";
        descriptionShort = "A precision-crafted upper receiver made for elite .338 Lapua Magnum sniper systems.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 8 — ULTRA CALIBERS
    // ---------------------------

    class UpperReceiver_408: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.408 CheyTac)";
        descriptionShort = "An extremely rare and powerful upper receiver for .408 CheyTac platforms.";
        // Use model materials; no hiddenSelections override
    };

    class UpperReceiver_50: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.50 BMG)";
        descriptionShort = "A massive reinforced upper receiver intended for .50 BMG anti-materiel rifles.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL CALIBERS
    // ---------------------------

    class UpperReceiver_8mm: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (8mm)";
        descriptionShort = "An upper receiver for powerful 8mm historical rifles.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // SHOTGUNS — 12 GAUGE (NO BOLT)
    // ---------------------------

    class UpperReceiver_12Gauge: S88_UpperReceiver_Base
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

    class S88_Bolt_Base: S88_PartBase
    {
        scope = 0;
        model = "\sector88_weaponparts\data\models\bolt.p3d";
        // Empty to allow engine to use model InvView
        inventoryIcon[] = {};
        weight = 200;
        itemSize[] = {1,2};
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class Bolt_762x54: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (7.62×54R)";
        descriptionShort = "A bolt assembly designed for powerful 7.62×54R marksman rifles.";
        // Use model materials; no hiddenSelections override
    };

    class Bolt_308: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.308 Winchester)";
        descriptionShort = "A precision-machined bolt assembly for .308 Win DMR platforms.";
        // Use model materials; no hiddenSelections override
    };

    class Bolt_300WM: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.300 WinMag)";
        descriptionShort = "A reinforced bolt assembly capable of handling high-pressure .300 WinMag loads.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class Bolt_338: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.338 Lapua Magnum)";
        descriptionShort = "A precision bolt assembly used in elite .338 Lapua Magnum sniper systems.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // TIER 8 — ULTRA SNIPER CALIBERS
    // ---------------------------

    class Bolt_408: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.408 CheyTac)";
        descriptionShort = "An extremely rare bolt assembly engineered for .408 CheyTac anti-personnel rifles.";
        // Use model materials; no hiddenSelections override
    };

    class Bolt_50: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.50 BMG)";
        descriptionShort = "A massive bolt assembly used in .50 BMG anti-materiel rifle platforms.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL
    // ---------------------------

    class Bolt_8mm: S88_Bolt_Base
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
//   S88_Spring_Small
//   S88_Spring_Large
//   S88_SheetMetal_Small
//   S88_SheetMetal_Large
//
// No dedicated MagazineBody_* item classes are used.
// The bench behaves like a vending machine: the amount
// and size of springs/metal determines which existing
// Vanilla/Expansion/AJ's magazines can be crafted.
//
// Item definitions are therefore not required here.
// All logic will live in JSON recipes under:
//   config/ExpansionMod/Crafting/Sector88/
//
// =====================================================
// SECTION 8 — ULTRA-RARE UPGRADE PARTS (TIER 8 ONLY)
// =====================================================

    // ---------------------------
    // BASE CLASS FOR UPGRADES
    // ---------------------------

    class S88_Upgrade_Base: S88_PartBase
    {
        scope = 0;
        model = "\sector88_weaponparts\data\models\lower_receiver.p3d";
        weight = 150;
        itemSize[] = {2,1};
    };

    // ---------------------------
    // MATCH-GRADE BARREL LINER
    // ---------------------------

    class BarrelLiner_MatchGrade: S88_Upgrade_Base
    {
        scope = 2;
        displayName = "Match-Grade Barrel Liner";
        descriptionShort = "A premium-grade barrel liner engineered with exceptional precision. Install inside a rifle barrel to increase accuracy and bullet velocity.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // PRECISION BOLT ASSEMBLY
    // ---------------------------

    class BoltAssembly_Precision: S88_Upgrade_Base
    {
        scope = 2;
        displayName = "Precision Bolt Assembly";
        descriptionShort = "A finely machined bolt assembly designed for improved cycling and smoother bolt operation.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // REINFORCED RECEIVER BRACKET
    // ---------------------------

    class ReceiverBracket_Reinforced: S88_Upgrade_Base
    {
        scope = 2;
        displayName = "Reinforced Receiver Bracket";
        descriptionShort = "A high-strength support bracket used to reinforce a rifle’s receiver, reducing wear and recoil.";
        // Use model materials; no hiddenSelections override
    };

    // ---------------------------
    // ELITE BUFFER SPRING
    // ---------------------------

    class Spring_Elite: S88_Upgrade_Base
    {
        scope = 2;
        displayName = "Elite Buffer Spring";
        descriptionShort = "A top-tier buffer spring crafted from advanced alloys, allowing smoother recoil control and faster semi-auto shot recovery.";
        // Use model materials; no hiddenSelections override
        weight = 80;
        itemSize[] = {1,2};
    };
}; // END OF CfgVehicles
