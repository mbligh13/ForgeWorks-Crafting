class CfgPatches
{
    class Sector88_WeaponParts
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = { "DZ_Data" };
    };
};

class CfgMods
{
    class Sector88_WeaponParts
    {
        dir = "Sector88_WeaponParts";
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

        // ICON PATH (will be set per item)
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {""};
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
        model = "\dz\gear\tools\toolhead.p3d";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\spring_small_ca.paa"};
        weight = 50;
        itemSize[] = {1,1};
    };

    class S88_Spring_Large: S88_PartBase
    {
        scope = 2;
        displayName = "Large Spring";
        descriptionShort = "A heavy-duty spring used in crafting high-capacity magazines and advanced rifle components.";
        model = "\dz\gear\tools\toolhead.p3d";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\spring_large_ca.paa"};
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
        model = "\dz\weapons\ammunition\data\ammobox_556.p3d";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\sheetmetal_small_ca.paa"};
        weight = 100;
        itemSize[] = {2,1};
    };

    class S88_SheetMetal_Large: S88_PartBase
    {
        scope = 2;
        displayName = "Large Sheet Metal";
        descriptionShort = "Reinforced sheet metal used for heavy magazines, advanced receivers, and high-caliber firearm components.";
        model = "\dz\weapons\ammunition\data\ammobox_556.p3d";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\sheetmetal_large_ca.paa"};
        weight = 150;
        itemSize[] = {2,2};
    };

    // ---------------------------
    // BASE CLASS FOR MAG BODIES
    // ---------------------------

    class S88_MagBody_Base: S88_PartBase
    {
        scope = 0;
        model = "\dz\weapons\ammunition\data\ammobox_556.p3d";
        weight = 200;
        itemSize[] = {2,2};
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
        model = "\dz\structures\industrial\metal\metal_pipe.p3d";
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
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_22_ca.paa"};
    };

    class Barrel_9mm: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (9×19mm)";
        descriptionShort = "A 9×19mm pistol-caliber barrel. Balanced, compact, and widely compatible with modern platforms.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_9mm_ca.paa"};
    };

    class Barrel_45ACP: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.45 ACP)";
        descriptionShort = "A .45 ACP barrel intended for mid-tier handguns and compact SMGs.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_45acp_ca.paa"};
    };

    class Barrel_762x25: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (7.62×25 Tokarev)";
        descriptionShort = "A 7.62×25 barrel compatible with specialty SMGs and certain historical sidearms.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_76225_ca.paa"};
    };

    // ---------------------------
    // TIER 4–5 — INTERMEDIATE CALIBERS
    // ---------------------------

    class Barrel_556: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (5.56×45)";
        descriptionShort = "A 5.56×45 NATO barrel. Standard for modern AR-platform rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_556_ca.paa"};
    };

    class Barrel_300BLK: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.300 Blackout)";
        descriptionShort = "A .300 Blackout barrel designed for suppressed AR builds and close-quarters rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_300blk_ca.paa"};
    };

    class Barrel_762x39: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (7.62×39)";
        descriptionShort = "A rugged 7.62×39 barrel used in AK-pattern weapons and mid-tier battle rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_76239_ca.paa"};
    };

    class Barrel_939: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (9×39)";
        descriptionShort = "A heavy suppressed-oriented 9×39 barrel, typically used in VSS and AS VAL platforms.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_939_ca.paa"};
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class Barrel_762x54: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (7.62×54R)";
        descriptionShort = "A high-pressure sniper-grade barrel chambered in 7.62×54R.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_76254_ca.paa"};
    };

    class Barrel_308: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.308 Winchester)";
        descriptionShort = "A precision .308 Win barrel suited for DMR and battle rifle builds.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_308_ca.paa"};
    };

    class Barrel_300WM: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.300 Winchester Magnum)";
        descriptionShort = "A high-powered long-range sniper barrel chambered in .300 WinMag.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_300wm_ca.paa"};
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class Barrel_338: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.338 Lapua Magnum)";
        descriptionShort = "A precision-engineered .338 Lapua Magnum barrel for extreme long-range accuracy.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_338_ca.paa"};
    };

    // ---------------------------
    // TIER 8 — ULTRA CALIBERS
    // ---------------------------

    class Barrel_408: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.408 CheyTac)";
        descriptionShort = "An ultra-high-performance .408 CheyTac barrel. Extremely rare and valuable.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_408_ca.paa"};
    };

    class Barrel_50: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (.50 BMG)";
        descriptionShort = "A massive .50 BMG barrel used for anti-materiel rifles. Extremely rare.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_50_ca.paa"};
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL CALIBERS
    // ---------------------------

    class Barrel_8mm: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Barrel (8mm)";
        descriptionShort = "An 8mm barrel typically used for historical bolt-action rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_8mm_ca.paa"};
    };

    // ---------------------------
    // SHOTGUNS — 12 GAUGE
    // ---------------------------

    class Barrel_12Gauge: S88_Barrel_Base
    {
        scope = 2;
        displayName = "Shotgun Barrel (12 Gauge)";
        descriptionShort = "A 12-gauge shotgun barrel suitable for pump-action and semi-automatic shotguns.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\barrel_12g_ca.paa"};
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
        model = "\dz\gear\tools\toolhead.p3d";
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
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_22_ca.paa"};
    };

    class LowerReceiver_9mm: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (9×19mm)";
        descriptionShort = "A lower receiver built for 9×19mm pistols and SMG platforms.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_9mm_ca.paa"};
    };

    class LowerReceiver_45ACP: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.45 ACP)";
        descriptionShort = "A lower receiver engineered for .45 ACP platforms. Compatible with mid-tier handguns and compact carbines.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_45acp_ca.paa"};
    };

    class LowerReceiver_762x25: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (7.62×25)";
        descriptionShort = "A 7.62×25 lower receiver used for specialty SMG and pistol conversions.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_76225_ca.paa"};
    };

    // ---------------------------
    // TIER 4–5 — INTERMEDIATE CALIBERS
    // ---------------------------

    class LowerReceiver_556: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (5.56×45)";
        descriptionShort = "A lower receiver for 5.56×45 AR-platform rifles. Widely compatible with modern parts.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_556_ca.paa"};
    };

    class LowerReceiver_300BLK: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.300 Blackout)";
        descriptionShort = "A specialized lower receiver for .300 Blackout rifles, typically used in suppressed configurations.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_300blk_ca.paa"};
    };

    class LowerReceiver_762x39: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (7.62×39)";
        descriptionShort = "A rugged lower receiver built for AK-pattern rifles and 7.62×39 conversions.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_76239_ca.paa"};
    };

    class LowerReceiver_939: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (9×39)";
        descriptionShort = "A heavy-duty lower receiver for 9×39 integrally suppressed rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_939_ca.paa"};
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class LowerReceiver_762x54: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (7.62×54R)";
        descriptionShort = "A precision lower receiver for classic 7.62×54R marksman rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_76254_ca.paa"};
    };

    class LowerReceiver_308: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.308 Winchester)";
        descriptionShort = "A lower receiver built for .308 Win battle rifles and designated marksman platforms.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_308_ca.paa"};
    };

    class LowerReceiver_300WM: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.300 WinMag)";
        descriptionShort = "A reinforced lower receiver engineered to handle the high pressure of .300 WinMag.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_300wm_ca.paa"};
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class LowerReceiver_338: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.338 Lapua)";
        descriptionShort = "A precision-machined lower receiver for .338 Lapua Magnum sniper systems.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_338_ca.paa"};
    };

    // ---------------------------
    // TIER 8 — ULTRA CALIBERS
    // ---------------------------

    class LowerReceiver_408: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.408 CheyTac)";
        descriptionShort = "An extremely rare lower receiver calibrated for .408 CheyTac anti-personnel rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_408_ca.paa"};
    };

    class LowerReceiver_50: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (.50 BMG)";
        descriptionShort = "A reinforced .50 BMG lower receiver designed for anti-materiel platforms.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_50_ca.paa"};
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL CALIBERS
    // ---------------------------

    class LowerReceiver_8mm: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Lower Receiver (8mm)";
        descriptionShort = "A lower receiver for classic 8mm bolt-action rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_8mm_ca.paa"};
    };

    // ---------------------------
    // SHOTGUNS — 12 GAUGE
    // ---------------------------

    class LowerReceiver_12Gauge: S88_LowerReceiver_Base
    {
        scope = 2;
        displayName = "Shotgun Lower Receiver (12 Gauge)";
        descriptionShort = "A 12-gauge lower receiver for pump-action and semi-automatic shotguns.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\lower_12g_ca.paa"};
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
        model = "\dz\gear\tools\toolhead.p3d";
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
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_22_ca.paa"};
    };

    class UpperReceiver_9mm: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (9×19mm)";
        descriptionShort = "A 9×19mm upper receiver used for various pistol-caliber builds and compact SMGs.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_9mm_ca.paa"};
    };

    class UpperReceiver_45ACP: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.45 ACP)";
        descriptionShort = "A .45 ACP upper receiver compatible with heavy-frame pistols and SMGs.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_45acp_ca.paa"};
    };

    class UpperReceiver_762x25: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (7.62×25)";
        descriptionShort = "An upper receiver built for the fast, high-velocity 7.62×25 cartridge.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_76225_ca.paa"};
    };

    // ---------------------------
    // TIER 4–5 — INTERMEDIATE RIFLE CALIBERS
    // ---------------------------

    class UpperReceiver_556: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (5.56×45)";
        descriptionShort = "A 5.56×45 NATO upper receiver, standard in many AR-platform rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_556_ca.paa"};
    };

    class UpperReceiver_300BLK: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.300 Blackout)";
        descriptionShort = "A .300 Blackout upper receiver optimized for suppressed builds.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_300blk_ca.paa"};
    };

    class UpperReceiver_762x39: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (7.62×39)";
        descriptionShort = "A 7.62×39 upper receiver designed for AK-pattern and hybrid rifle systems.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_76239_ca.paa"};
    };

    class UpperReceiver_939: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (9×39)";
        descriptionShort = "A heavy-duty upper receiver compatible with suppressed 9×39 rifle systems.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_939_ca.paa"};
    };

    // ---------------------------
    // TIER 5–6 — DMR CALIBERS
    // ---------------------------

    class UpperReceiver_762x54: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (7.62×54R)";
        descriptionShort = "A hardened upper receiver intended for long-range 7.62×54R marksman rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_76254_ca.paa"};
    };

    class UpperReceiver_308: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.308 Winchester)";
        descriptionShort = "A .308 Win upper receiver engineered for precision DMR and battle rifle builds.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_308_ca.paa"};
    };

    class UpperReceiver_300WM: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.300 WinMag)";
        descriptionShort = "A reinforced upper receiver capable of handling the high-pressure .300 WinMag cartridge.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_300wm_ca.paa"};
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class UpperReceiver_338: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.338 Lapua)";
        descriptionShort = "A precision-crafted upper receiver made for elite .338 Lapua Magnum sniper systems.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_338_ca.paa"};
    };

    // ---------------------------
    // TIER 8 — ULTRA CALIBERS
    // ---------------------------

    class UpperReceiver_408: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.408 CheyTac)";
        descriptionShort = "An extremely rare and powerful upper receiver for .408 CheyTac platforms.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_408_ca.paa"};
    };

    class UpperReceiver_50: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (.50 BMG)";
        descriptionShort = "A massive reinforced upper receiver intended for .50 BMG anti-materiel rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_50_ca.paa"};
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL CALIBERS
    // ---------------------------

    class UpperReceiver_8mm: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Upper Receiver (8mm)";
        descriptionShort = "An upper receiver for powerful 8mm historical rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_8mm_ca.paa"};
    };

    // ---------------------------
    // SHOTGUNS — 12 GAUGE (NO BOLT)
    // ---------------------------

    class UpperReceiver_12Gauge: S88_UpperReceiver_Base
    {
        scope = 2;
        displayName = "Shotgun Upper Receiver (12 Gauge)";
        descriptionShort = "A 12-gauge upper receiver compatible with pump-action and semi-automatic shotgun builds.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upper_12g_ca.paa"};
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
        model = "\dz\weapons\attachments\data\bolt.p3d";
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
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\bolt_76254_ca.paa"};
    };

    class Bolt_308: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.308 Winchester)";
        descriptionShort = "A precision-machined bolt assembly for .308 Win DMR platforms.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\bolt_308_ca.paa"};
    };

    class Bolt_300WM: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.300 WinMag)";
        descriptionShort = "A reinforced bolt assembly capable of handling high-pressure .300 WinMag loads.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\bolt_300wm_ca.paa"};
    };

    // ---------------------------
    // TIER 7 — ELITE SNIPER CALIBERS
    // ---------------------------

    class Bolt_338: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.338 Lapua Magnum)";
        descriptionShort = "A precision bolt assembly used in elite .338 Lapua Magnum sniper systems.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\bolt_338_ca.paa"};
    };

    // ---------------------------
    // TIER 8 — ULTRA SNIPER CALIBERS
    // ---------------------------

    class Bolt_408: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.408 CheyTac)";
        descriptionShort = "An extremely rare bolt assembly engineered for .408 CheyTac anti-personnel rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\bolt_408_ca.paa"};
    };

    class Bolt_50: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (.50 BMG)";
        descriptionShort = "A massive bolt assembly used in .50 BMG anti-materiel rifle platforms.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\bolt_50_ca.paa"};
    };

    // ---------------------------
    // SPECIALTY / HISTORICAL
    // ---------------------------

    class Bolt_8mm: S88_Bolt_Base
    {
        scope = 2;
        displayName = "Bolt Assembly (8mm)";
        descriptionShort = "A traditional bolt assembly for powerful 8mm historical rifles.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\bolt_8mm_ca.paa"};
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
        model = "\dz\gear\tools\toolhead.p3d";
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
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upgrade_barrelliner_ca.paa"};
    };

    // ---------------------------
    // PRECISION BOLT ASSEMBLY
    // ---------------------------

    class BoltAssembly_Precision: S88_Upgrade_Base
    {
        scope = 2;
        displayName = "Precision Bolt Assembly";
        descriptionShort = "A finely machined bolt assembly designed for improved cycling and smoother bolt operation.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upgrade_boltassembly_ca.paa"};
    };

    // ---------------------------
    // REINFORCED RECEIVER BRACKET
    // ---------------------------

    class ReceiverBracket_Reinforced: S88_Upgrade_Base
    {
        scope = 2;
        displayName = "Reinforced Receiver Bracket";
        descriptionShort = "A high-strength support bracket used to reinforce a rifle’s receiver, reducing wear and recoil.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upgrade_receiverbracket_ca.paa"};
    };

    // ---------------------------
    // ELITE BUFFER SPRING
    // ---------------------------

    class Spring_Elite: S88_Upgrade_Base
    {
        scope = 2;
        displayName = "Elite Buffer Spring";
        descriptionShort = "A top-tier buffer spring crafted from advanced alloys, allowing smoother recoil control and faster semi-auto shot recovery.";
        hiddenSelectionsTextures[] = {"\Sector88_WeaponParts\data\icons\upgrade_elitespring_ca.paa"};
        weight = 80;
        itemSize[] = {1,2};
    };
}; // END OF CfgVehicles
