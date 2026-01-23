// Sector 88 Crafting - Recipe Manager (Singleton)
// Path: scripts/4_world/FWRecipeManager.c

class FWRecipeManager
{
    // Singleton
    private static ref FWRecipeManager s_Instance;
    
    // Recipe storage
    protected ref map<string, ref array<ref FWCraftingRecipe>> m_RecipesByCategory;
    protected ref array<ref FWCraftingRecipe> m_AllRecipes;
    
    void FWRecipeManager()
    {
        m_RecipesByCategory = new map<string, ref array<ref FWCraftingRecipe>>;
        m_AllRecipes = new array<ref FWCraftingRecipe>;
        
        LoadAllRecipes();
    }
    
    static FWRecipeManager GetInstance()
    {
        if (!s_Instance)
            s_Instance = new FWRecipeManager();
        return s_Instance;
    }
    
    void LoadAllRecipes()
    {
        // Load pistol recipes
        LoadPistolRecipes();
        LoadSMGRecipes();
        LoadRifleRecipes();
        LoadSniperRecipes();
        LoadShotgunRecipes();
        LoadMagazineRecipes();
    }
    
    protected void LoadPistolRecipes()
    {
        // 9mm Pistols
        ref FWCraftingRecipe glock = new FWCraftingRecipe();
        glock.SetName("craft_glock19");
        glock.SetDisplayName("Glock 19");
        glock.SetCategory("Pistols");
        glock.SetSubCategory("9mm");
        glock.SetCraftingTime(4);
        glock.SetIconPath("set:dayz_inventory image:glock19");        glock.AddIngredient("Barrel_9mm", 1);
        glock.AddIngredient("UpperReceiver_9mm", 1);
        glock.AddIngredient("LowerReceiver_9mm", 1);
        glock.AddResult("Glock19");
        AddRecipe(glock);
        
        ref FWCraftingRecipe cz75 = new FWCraftingRecipe();
        cz75.SetName("craft_cz75");
        cz75.SetDisplayName("CZ 75");
        cz75.SetCategory("Pistols");
        cz75.SetSubCategory("9mm");
        cz75.SetCraftingTime(4);
        cz75.SetIconPath("set:dayz_inventory image:cz75");        cz75.AddIngredient("Barrel_9mm", 1);
        cz75.AddIngredient("UpperReceiver_9mm", 1);
        cz75.AddIngredient("LowerReceiver_9mm", 1);
        cz75.AddResult("CZ75");
        AddRecipe(cz75);
        
        // .45 ACP Pistols
        ref FWCraftingRecipe fnx45 = new FWCraftingRecipe();
        fnx45.SetName("craft_fnx45");
        fnx45.SetDisplayName("FNX-45");
        fnx45.SetCategory("Pistols");
        fnx45.SetSubCategory(".45 ACP");
        fnx45.SetCraftingTime(4);
        fnx45.SetIconPath("set:dayz_inventory image:fnx45");        fnx45.AddIngredient("Barrel_45ACP", 1);
        fnx45.AddIngredient("UpperReceiver_45ACP", 1);
        fnx45.AddIngredient("LowerReceiver_45ACP", 1);
        fnx45.AddResult("FNX45");
        AddRecipe(fnx45);
        
        ref FWCraftingRecipe m1911 = new FWCraftingRecipe();
        m1911.SetName("craft_1911");
        m1911.SetDisplayName("M1911");
        m1911.SetCategory("Pistols");
        m1911.SetSubCategory(".45 ACP");
        m1911.SetCraftingTime(4);
        m1911.SetIconPath("set:dayz_inventory image:colt1911");        m1911.AddIngredient("Barrel_45ACP", 1);
        m1911.AddIngredient("UpperReceiver_45ACP", 1);
        m1911.AddIngredient("LowerReceiver_45ACP", 1);
        m1911.AddResult("Colt1911");
        AddRecipe(m1911);
        
        // .22 LR Pistols
        ref FWCraftingRecipe mkii = new FWCraftingRecipe();
        mkii.SetName("craft_mkii");
        mkii.SetDisplayName("MK II");
        mkii.SetCategory("Pistols");
        mkii.SetSubCategory(".22 LR");
        mkii.SetCraftingTime(3);
        mkii.SetIconPath("set:dayz_inventory image:mkii");        mkii.AddIngredient("Barrel_22", 1);
        mkii.AddIngredient("LowerReceiver_22", 1);
        mkii.AddResult("MKII");
        AddRecipe(mkii);
    }
    
    protected void LoadSMGRecipes()
    {
        // MP5
        ref FWCraftingRecipe mp5 = new FWCraftingRecipe();
        mp5.SetName("craft_mp5k");
        mp5.SetDisplayName("MP5-K");
        mp5.SetCategory("SMGs");
        mp5.SetSubCategory("9mm SMG");
        mp5.SetCraftingTime(6);
        mp5.SetIconPath("set:dayz_inventory image:mp5k");        mp5.AddIngredient("Barrel_9mm", 1);
        mp5.AddIngredient("UpperReceiver_9mm", 1);
        mp5.AddIngredient("LowerReceiver_9mm", 1);
        mp5.AddResult("MP5K");
        AddRecipe(mp5);
        
        // UMP45
        ref FWCraftingRecipe ump = new FWCraftingRecipe();
        ump.SetName("craft_ump45");
        ump.SetDisplayName("UMP-45");
        ump.SetCategory("SMGs");
        ump.SetSubCategory(".45 ACP SMG");
        ump.SetCraftingTime(6);
        ump.SetIconPath("set:dayz_inventory image:ump45");        ump.AddIngredient("Barrel_45ACP", 1);
        ump.AddIngredient("UpperReceiver_45ACP", 1);
        ump.AddIngredient("LowerReceiver_45ACP", 1);
        ump.AddResult("UMP45");
        AddRecipe(ump);
    }
    
    protected void LoadRifleRecipes()
    {
        // M4A1
        ref FWCraftingRecipe m4 = new FWCraftingRecipe();
        m4.SetName("craft_m4a1");
        m4.SetDisplayName("M4-A1");
        m4.SetCategory("Rifles");
        m4.SetSubCategory("5.56x45");
        m4.SetCraftingTime(8);
        m4.SetIconPath("set:dayz_inventory image:m4a1");        m4.AddIngredient("Barrel_556", 1);
        m4.AddIngredient("UpperReceiver_556", 1);
        m4.AddIngredient("LowerReceiver_556", 1);
        m4.AddResult("M4A1");
        AddRecipe(m4);
        
        // AK-74
        ref FWCraftingRecipe ak74 = new FWCraftingRecipe();
        ak74.SetName("craft_ak74");
        ak74.SetDisplayName("AK-74");
        ak74.SetCategory("Rifles");
        ak74.SetSubCategory("5.45x39");
        ak74.SetCraftingTime(8);
        ak74.SetIconPath("set:dayz_inventory image:ak74");        ak74.AddIngredient("Barrel_545", 1);
        ak74.AddIngredient("UpperReceiver_545", 1);
        ak74.AddIngredient("LowerReceiver_545", 1);
        ak74.AddResult("AK74");
        AddRecipe(ak74);
        
        // AKM
        ref FWCraftingRecipe akm = new FWCraftingRecipe();
        akm.SetName("craft_akm");
        akm.SetDisplayName("AKM");
        akm.SetCategory("Rifles");
        akm.SetSubCategory("7.62x39");
        akm.SetCraftingTime(8);
        akm.SetIconPath("set:dayz_inventory image:akm");        akm.AddIngredient("Barrel_762x39", 1);
        akm.AddIngredient("UpperReceiver_762x39", 1);
        akm.AddIngredient("LowerReceiver_762x39", 1);
        akm.AddResult("AKM");
        AddRecipe(akm);
        
        // SKS
        ref FWCraftingRecipe sks = new FWCraftingRecipe();
        sks.SetName("craft_sks");
        sks.SetDisplayName("SKS");
        sks.SetCategory("Rifles");
        sks.SetSubCategory("7.62x39");
        sks.SetCraftingTime(7);
        sks.SetIconPath("set:dayz_inventory image:sks");        sks.AddIngredient("Barrel_762x39", 1);
        sks.AddIngredient("UpperReceiver_762x39", 1);
        sks.AddIngredient("LowerReceiver_762x39", 1);
        sks.AddResult("SKS");
        AddRecipe(sks);
    }
    
    protected void LoadSniperRecipes()
    {
        // Mosin
        ref FWCraftingRecipe mosin = new FWCraftingRecipe();
        mosin.SetName("craft_mosin");
        mosin.SetDisplayName("Mosin 9130");
        mosin.SetCategory("Snipers");
        mosin.SetSubCategory("7.62x54R");
        mosin.SetCraftingTime(10);
        mosin.SetIconPath("set:dayz_inventory image:mosin9130");        mosin.AddIngredient("Barrel_762x54", 1);
        mosin.AddIngredient("Bolt_762x54", 1);
        mosin.AddIngredient("LowerReceiver_762x54", 1);
        mosin.AddResult("Mosin9130");
        AddRecipe(mosin);
        
        // SVD
        ref FWCraftingRecipe svd = new FWCraftingRecipe();
        svd.SetName("craft_svd");
        svd.SetDisplayName("SVD");
        svd.SetCategory("Snipers");
        svd.SetSubCategory("7.62x54R");
        svd.SetCraftingTime(12);
        svd.SetIconPath("set:dayz_inventory image:svd");        svd.AddIngredient("Barrel_762x54", 1);
        svd.AddIngredient("Bolt_762x54", 1);
        svd.AddIngredient("LowerReceiver_762x54", 1);
        svd.AddResult("SVD");
        AddRecipe(svd);
        
        // Tundra (.308)
        ref FWCraftingRecipe tundra = new FWCraftingRecipe();
        tundra.SetName("craft_tundra");
        tundra.SetDisplayName("M70 Tundra");
        tundra.SetCategory("Snipers");
        tundra.SetSubCategory(".308 Win");
        tundra.SetCraftingTime(10);
        tundra.SetIconPath("set:dayz_inventory image:m70_tundra");        tundra.AddIngredient("Barrel_308", 1);
        tundra.AddIngredient("Bolt_308", 1);
        tundra.AddIngredient("LowerReceiver_308", 1);
        tundra.AddResult("M70_Tundra");
        AddRecipe(tundra);
    }
    
    protected void LoadShotgunRecipes()
    {
        // MP-133
        ref FWCraftingRecipe mp133 = new FWCraftingRecipe();
        mp133.SetName("craft_mp133");
        mp133.SetDisplayName("MP-133");
        mp133.SetCategory("Shotguns");
        mp133.SetSubCategory("12 Gauge");
        mp133.SetCraftingTime(6);
        mp133.SetIconPath("set:dayz_inventory image:mp133shotgun");        mp133.AddIngredient("Barrel_12Gauge", 1);
        mp133.AddIngredient("UpperReceiver_12Gauge", 1);
        mp133.AddIngredient("LowerReceiver_12Gauge", 1);
        mp133.AddResult("MP133Shotgun");
        AddRecipe(mp133);
    }
    
    protected void LoadMagazineRecipes()
    {
        // Standard Pistol Mags
        ref FWCraftingRecipe pistolMag = new FWCraftingRecipe();
        pistolMag.SetName("craft_pistol_mag_std");
        pistolMag.SetDisplayName("Pistol Magazine (Standard)");
        pistolMag.SetCategory("Magazines");
        pistolMag.SetSubCategory("Pistol Mags");
        pistolMag.SetCraftingTime(3);
        pistolMag.SetIconPath("set:dayz_inventory image:mag_glock");        pistolMag.AddIngredient("FW_SheetMetal_Small", 1);
        pistolMag.AddIngredient("FW_Spring_Small", 1);
        pistolMag.AddResult("Mag_Glock_15Rnd");
        AddRecipe(pistolMag);
        
        // Standard AR Mags
        ref FWCraftingRecipe arMag = new FWCraftingRecipe();
        arMag.SetName("craft_ar_mag_30");
        arMag.SetDisplayName("AR Magazine (30-Round)");
        arMag.SetCategory("Magazines");
        arMag.SetSubCategory("AR Mags");
        arMag.SetCraftingTime(5);
        arMag.SetIconPath("set:dayz_inventory image:mag_stanag_30rnd");        arMag.AddIngredient("FW_SheetMetal_Small", 1);
        arMag.AddIngredient("FW_Spring_Small", 1);
        arMag.AddResult("Mag_STANAG_30Rnd");
        AddRecipe(arMag);
        
        // Extended AR Mags
        ref FWCraftingRecipe arMagExt = new FWCraftingRecipe();
        arMagExt.SetName("craft_ar_mag_60");
        arMagExt.SetDisplayName("AR Magazine (60-Round)");
        arMagExt.SetCategory("Magazines");
        arMagExt.SetSubCategory("AR Mags");
        arMagExt.SetCraftingTime(8);
        arMagExt.SetIconPath("set:dayz_inventory image:mag_cmag_60rnd");        arMagExt.AddIngredient("FW_SheetMetal_Small", 2);
        arMagExt.AddIngredient("FW_Spring_Large", 1);
        arMagExt.AddResult("Mag_CMAG_60Rnd");
        AddRecipe(arMagExt);
        
        // Drum Mags
        ref FWCraftingRecipe drumMag = new FWCraftingRecipe();
        drumMag.SetName("craft_drum_mag");
        drumMag.SetDisplayName("Drum Magazine (75-Round)");
        drumMag.SetCategory("Magazines");
        drumMag.SetSubCategory("Drums");
        drumMag.SetCraftingTime(12);
        drumMag.SetIconPath("set:dayz_inventory image:mag_ak74_drum75rnd");        drumMag.AddIngredient("FW_SheetMetal_Large", 2);
        drumMag.AddIngredient("FW_Spring_Large", 2);
        drumMag.AddResult("Mag_AK74_Drum75Rnd");
        AddRecipe(drumMag);
    }
    
    void AddRecipe(FWCraftingRecipe recipe)
    {
        m_AllRecipes.Insert(recipe);
        
        string category = recipe.GetCategory();
        
        if (!m_RecipesByCategory.Contains(category))
        {
            m_RecipesByCategory.Insert(category, new array<ref FWCraftingRecipe>);
        }
        
        m_RecipesByCategory.Get(category).Insert(recipe);
    }
    
    array<ref FWCraftingRecipe> GetRecipesForCategory(string category)
    {
        if (m_RecipesByCategory.Contains(category))
            return m_RecipesByCategory.Get(category);
            
        return null;
    }
    
    array<ref FWCraftingRecipe> GetRecipesForSubCategory(string category, string subCategory)
    {
        array<ref FWCraftingRecipe> result = new array<ref FWCraftingRecipe>;
        array<ref FWCraftingRecipe> categoryRecipes = GetRecipesForCategory(category);
        
        if (!categoryRecipes)
            return result;
            
        foreach (FWCraftingRecipe recipe : categoryRecipes)
        {
            if (recipe.GetSubCategory() == subCategory)
                result.Insert(recipe);
        }
        
        return result;
    }
    
    FWCraftingRecipe GetRecipeByName(string name)
    {
        foreach (FWCraftingRecipe recipe : m_AllRecipes)
        {
            if (recipe.GetName() == name)
                return recipe;
        }
        return null;
    }
    
    static string GetItemIcon(string className)
    {
        // Return icon path for item
        string cfgPath = "CfgVehicles " + className + " hiddenSelectionsTextures";
        
        // Try to get from config
        TStringArray textures = new TStringArray;
        GetGame().ConfigGetTextArray(cfgPath, textures);
        
        if (textures.Count() > 0)
            return textures.Get(0);
            
        // Default fallback
        return "set:dayz_inventory image:" + className;
    }
}
