// Sector 88 Crafting - Recipe Manager (Singleton)
// Path: scripts/4_world/S88RecipeManager.c

class S88RecipeManager
{
    // Singleton
    private static ref S88RecipeManager s_Instance;
    
    // Recipe storage
    protected ref map<string, ref array<ref S88CraftingRecipe>> m_RecipesByCategory;
    protected ref array<ref S88CraftingRecipe> m_AllRecipes;
    
    void S88RecipeManager()
    {
        m_RecipesByCategory = new map<string, ref array<ref S88CraftingRecipe>>;
        m_AllRecipes = new array<ref S88CraftingRecipe>;
        
        LoadAllRecipes();
    }
    
    static S88RecipeManager GetInstance()
    {
        if (!s_Instance)
            s_Instance = new S88RecipeManager();
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
        ref S88CraftingRecipe glock = new S88CraftingRecipe();
        glock.SetName("craft_glock19");
        glock.SetDisplayName("Glock 19");
        glock.SetCategory("Pistols");
        glock.SetSubCategory("9mm");
        glock.SetCraftingTime(4);
        glock.SetIconPath("set:dayz_inventory image:glock19");
        glock.SetRequiredAttachments("BPGrinder,BPDrill");
        glock.AddIngredient("Barrel_9mm", 1);
        glock.AddIngredient("UpperReceiver_9mm", 1);
        glock.AddIngredient("LowerReceiver_9mm", 1);
        glock.AddResult("Glock19");
        AddRecipe(glock);
        
        ref S88CraftingRecipe cz75 = new S88CraftingRecipe();
        cz75.SetName("craft_cz75");
        cz75.SetDisplayName("CZ 75");
        cz75.SetCategory("Pistols");
        cz75.SetSubCategory("9mm");
        cz75.SetCraftingTime(4);
        cz75.SetIconPath("set:dayz_inventory image:cz75");
        cz75.SetRequiredAttachments("BPGrinder,BPDrill");
        cz75.AddIngredient("Barrel_9mm", 1);
        cz75.AddIngredient("UpperReceiver_9mm", 1);
        cz75.AddIngredient("LowerReceiver_9mm", 1);
        cz75.AddResult("CZ75");
        AddRecipe(cz75);
        
        // .45 ACP Pistols
        ref S88CraftingRecipe fnx45 = new S88CraftingRecipe();
        fnx45.SetName("craft_fnx45");
        fnx45.SetDisplayName("FNX-45");
        fnx45.SetCategory("Pistols");
        fnx45.SetSubCategory(".45 ACP");
        fnx45.SetCraftingTime(4);
        fnx45.SetIconPath("set:dayz_inventory image:fnx45");
        fnx45.SetRequiredAttachments("BPGrinder,BPDrill");
        fnx45.AddIngredient("Barrel_45ACP", 1);
        fnx45.AddIngredient("UpperReceiver_45ACP", 1);
        fnx45.AddIngredient("LowerReceiver_45ACP", 1);
        fnx45.AddResult("FNX45");
        AddRecipe(fnx45);
        
        ref S88CraftingRecipe m1911 = new S88CraftingRecipe();
        m1911.SetName("craft_1911");
        m1911.SetDisplayName("M1911");
        m1911.SetCategory("Pistols");
        m1911.SetSubCategory(".45 ACP");
        m1911.SetCraftingTime(4);
        m1911.SetIconPath("set:dayz_inventory image:colt1911");
        m1911.SetRequiredAttachments("BPGrinder,BPDrill");
        m1911.AddIngredient("Barrel_45ACP", 1);
        m1911.AddIngredient("UpperReceiver_45ACP", 1);
        m1911.AddIngredient("LowerReceiver_45ACP", 1);
        m1911.AddResult("Colt1911");
        AddRecipe(m1911);
        
        // .22 LR Pistols
        ref S88CraftingRecipe mkii = new S88CraftingRecipe();
        mkii.SetName("craft_mkii");
        mkii.SetDisplayName("MK II");
        mkii.SetCategory("Pistols");
        mkii.SetSubCategory(".22 LR");
        mkii.SetCraftingTime(3);
        mkii.SetIconPath("set:dayz_inventory image:mkii");
        mkii.SetRequiredAttachments("BPGrinder");
        mkii.AddIngredient("Barrel_22", 1);
        mkii.AddIngredient("LowerReceiver_22", 1);
        mkii.AddResult("MKII");
        AddRecipe(mkii);
    }
    
    protected void LoadSMGRecipes()
    {
        // MP5
        ref S88CraftingRecipe mp5 = new S88CraftingRecipe();
        mp5.SetName("craft_mp5k");
        mp5.SetDisplayName("MP5-K");
        mp5.SetCategory("SMGs");
        mp5.SetSubCategory("9mm SMG");
        mp5.SetCraftingTime(6);
        mp5.SetIconPath("set:dayz_inventory image:mp5k");
        mp5.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
        mp5.AddIngredient("Barrel_9mm", 1);
        mp5.AddIngredient("UpperReceiver_9mm", 1);
        mp5.AddIngredient("LowerReceiver_9mm", 1);
        mp5.AddResult("MP5K");
        AddRecipe(mp5);
        
        // UMP45
        ref S88CraftingRecipe ump = new S88CraftingRecipe();
        ump.SetName("craft_ump45");
        ump.SetDisplayName("UMP-45");
        ump.SetCategory("SMGs");
        ump.SetSubCategory(".45 ACP SMG");
        ump.SetCraftingTime(6);
        ump.SetIconPath("set:dayz_inventory image:ump45");
        ump.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
        ump.AddIngredient("Barrel_45ACP", 1);
        ump.AddIngredient("UpperReceiver_45ACP", 1);
        ump.AddIngredient("LowerReceiver_45ACP", 1);
        ump.AddResult("UMP45");
        AddRecipe(ump);
    }
    
    protected void LoadRifleRecipes()
    {
        // M4A1
        ref S88CraftingRecipe m4 = new S88CraftingRecipe();
        m4.SetName("craft_m4a1");
        m4.SetDisplayName("M4-A1");
        m4.SetCategory("Rifles");
        m4.SetSubCategory("5.56x45");
        m4.SetCraftingTime(8);
        m4.SetIconPath("set:dayz_inventory image:m4a1");
        m4.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
        m4.AddIngredient("Barrel_556", 1);
        m4.AddIngredient("UpperReceiver_556", 1);
        m4.AddIngredient("LowerReceiver_556", 1);
        m4.AddResult("M4A1");
        AddRecipe(m4);
        
        // AK-74
        ref S88CraftingRecipe ak74 = new S88CraftingRecipe();
        ak74.SetName("craft_ak74");
        ak74.SetDisplayName("AK-74");
        ak74.SetCategory("Rifles");
        ak74.SetSubCategory("5.45x39");
        ak74.SetCraftingTime(8);
        ak74.SetIconPath("set:dayz_inventory image:ak74");
        ak74.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
        ak74.AddIngredient("Barrel_545", 1);
        ak74.AddIngredient("UpperReceiver_545", 1);
        ak74.AddIngredient("LowerReceiver_545", 1);
        ak74.AddResult("AK74");
        AddRecipe(ak74);
        
        // AKM
        ref S88CraftingRecipe akm = new S88CraftingRecipe();
        akm.SetName("craft_akm");
        akm.SetDisplayName("AKM");
        akm.SetCategory("Rifles");
        akm.SetSubCategory("7.62x39");
        akm.SetCraftingTime(8);
        akm.SetIconPath("set:dayz_inventory image:akm");
        akm.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
        akm.AddIngredient("Barrel_762x39", 1);
        akm.AddIngredient("UpperReceiver_762x39", 1);
        akm.AddIngredient("LowerReceiver_762x39", 1);
        akm.AddResult("AKM");
        AddRecipe(akm);
        
        // SKS
        ref S88CraftingRecipe sks = new S88CraftingRecipe();
        sks.SetName("craft_sks");
        sks.SetDisplayName("SKS");
        sks.SetCategory("Rifles");
        sks.SetSubCategory("7.62x39");
        sks.SetCraftingTime(7);
        sks.SetIconPath("set:dayz_inventory image:sks");
        sks.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
        sks.AddIngredient("Barrel_762x39", 1);
        sks.AddIngredient("UpperReceiver_762x39", 1);
        sks.AddIngredient("LowerReceiver_762x39", 1);
        sks.AddResult("SKS");
        AddRecipe(sks);
    }
    
    protected void LoadSniperRecipes()
    {
        // Mosin
        ref S88CraftingRecipe mosin = new S88CraftingRecipe();
        mosin.SetName("craft_mosin");
        mosin.SetDisplayName("Mosin 9130");
        mosin.SetCategory("Snipers");
        mosin.SetSubCategory("7.62x54R");
        mosin.SetCraftingTime(10);
        mosin.SetIconPath("set:dayz_inventory image:mosin9130");
        mosin.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
        mosin.AddIngredient("Barrel_762x54", 1);
        mosin.AddIngredient("Bolt_762x54", 1);
        mosin.AddIngredient("LowerReceiver_762x54", 1);
        mosin.AddResult("Mosin9130");
        AddRecipe(mosin);
        
        // SVD
        ref S88CraftingRecipe svd = new S88CraftingRecipe();
        svd.SetName("craft_svd");
        svd.SetDisplayName("SVD");
        svd.SetCategory("Snipers");
        svd.SetSubCategory("7.62x54R");
        svd.SetCraftingTime(12);
        svd.SetIconPath("set:dayz_inventory image:svd");
        svd.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
        svd.AddIngredient("Barrel_762x54", 1);
        svd.AddIngredient("Bolt_762x54", 1);
        svd.AddIngredient("LowerReceiver_762x54", 1);
        svd.AddResult("SVD");
        AddRecipe(svd);
        
        // Tundra (.308)
        ref S88CraftingRecipe tundra = new S88CraftingRecipe();
        tundra.SetName("craft_tundra");
        tundra.SetDisplayName("M70 Tundra");
        tundra.SetCategory("Snipers");
        tundra.SetSubCategory(".308 Win");
        tundra.SetCraftingTime(10);
        tundra.SetIconPath("set:dayz_inventory image:m70_tundra");
        tundra.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
        tundra.AddIngredient("Barrel_308", 1);
        tundra.AddIngredient("Bolt_308", 1);
        tundra.AddIngredient("LowerReceiver_308", 1);
        tundra.AddResult("M70_Tundra");
        AddRecipe(tundra);
    }
    
    protected void LoadShotgunRecipes()
    {
        // MP-133
        ref S88CraftingRecipe mp133 = new S88CraftingRecipe();
        mp133.SetName("craft_mp133");
        mp133.SetDisplayName("MP-133");
        mp133.SetCategory("Shotguns");
        mp133.SetSubCategory("12 Gauge");
        mp133.SetCraftingTime(6);
        mp133.SetIconPath("set:dayz_inventory image:mp133shotgun");
        mp133.SetRequiredAttachments("BPGrinder,BPCutting_saw");
        mp133.AddIngredient("Barrel_12Gauge", 1);
        mp133.AddIngredient("UpperReceiver_12Gauge", 1);
        mp133.AddIngredient("LowerReceiver_12Gauge", 1);
        mp133.AddResult("MP133Shotgun");
        AddRecipe(mp133);
    }
    
    protected void LoadMagazineRecipes()
    {
        // Standard Pistol Mags
        ref S88CraftingRecipe pistolMag = new S88CraftingRecipe();
        pistolMag.SetName("craft_pistol_mag_std");
        pistolMag.SetDisplayName("Pistol Magazine (Standard)");
        pistolMag.SetCategory("Magazines");
        pistolMag.SetSubCategory("Pistol Mags");
        pistolMag.SetCraftingTime(3);
        pistolMag.SetIconPath("set:dayz_inventory image:mag_glock");
        pistolMag.SetRequiredAttachments("BPGrinder");
        pistolMag.AddIngredient("S88_SheetMetal_Small", 1);
        pistolMag.AddIngredient("S88_Spring_Small", 1);
        pistolMag.AddResult("Mag_Glock_15Rnd");
        AddRecipe(pistolMag);
        
        // Standard AR Mags
        ref S88CraftingRecipe arMag = new S88CraftingRecipe();
        arMag.SetName("craft_ar_mag_30");
        arMag.SetDisplayName("AR Magazine (30-Round)");
        arMag.SetCategory("Magazines");
        arMag.SetSubCategory("AR Mags");
        arMag.SetCraftingTime(5);
        arMag.SetIconPath("set:dayz_inventory image:mag_stanag_30rnd");
        arMag.SetRequiredAttachments("BPGrinder,BPCutting_saw");
        arMag.AddIngredient("S88_SheetMetal_Small", 1);
        arMag.AddIngredient("S88_Spring_Small", 1);
        arMag.AddResult("Mag_STANAG_30Rnd");
        AddRecipe(arMag);
        
        // Extended AR Mags
        ref S88CraftingRecipe arMagExt = new S88CraftingRecipe();
        arMagExt.SetName("craft_ar_mag_60");
        arMagExt.SetDisplayName("AR Magazine (60-Round)");
        arMagExt.SetCategory("Magazines");
        arMagExt.SetSubCategory("AR Mags");
        arMagExt.SetCraftingTime(8);
        arMagExt.SetIconPath("set:dayz_inventory image:mag_cmag_60rnd");
        arMagExt.SetRequiredAttachments("BPGrinder,BPCutting_saw");
        arMagExt.AddIngredient("S88_SheetMetal_Small", 2);
        arMagExt.AddIngredient("S88_Spring_Large", 1);
        arMagExt.AddResult("Mag_CMAG_60Rnd");
        AddRecipe(arMagExt);
        
        // Drum Mags
        ref S88CraftingRecipe drumMag = new S88CraftingRecipe();
        drumMag.SetName("craft_drum_mag");
        drumMag.SetDisplayName("Drum Magazine (75-Round)");
        drumMag.SetCategory("Magazines");
        drumMag.SetSubCategory("Drums");
        drumMag.SetCraftingTime(12);
        drumMag.SetIconPath("set:dayz_inventory image:mag_ak74_drum75rnd");
        drumMag.SetRequiredAttachments("BPGrinder,BPCutting_saw,BPDrill");
        drumMag.AddIngredient("S88_SheetMetal_Large", 2);
        drumMag.AddIngredient("S88_Spring_Large", 2);
        drumMag.AddResult("Mag_AK74_Drum75Rnd");
        AddRecipe(drumMag);
    }
    
    void AddRecipe(S88CraftingRecipe recipe)
    {
        m_AllRecipes.Insert(recipe);
        
        string category = recipe.GetCategory();
        
        if (!m_RecipesByCategory.Contains(category))
        {
            m_RecipesByCategory.Insert(category, new array<ref S88CraftingRecipe>);
        }
        
        m_RecipesByCategory.Get(category).Insert(recipe);
    }
    
    array<ref S88CraftingRecipe> GetRecipesForCategory(string category)
    {
        if (m_RecipesByCategory.Contains(category))
            return m_RecipesByCategory.Get(category);
            
        return null;
    }
    
    array<ref S88CraftingRecipe> GetRecipesForSubCategory(string category, string subCategory)
    {
        array<ref S88CraftingRecipe> result = new array<ref S88CraftingRecipe>;
        array<ref S88CraftingRecipe> categoryRecipes = GetRecipesForCategory(category);
        
        if (!categoryRecipes)
            return result;
            
        foreach (S88CraftingRecipe recipe : categoryRecipes)
        {
            if (recipe.GetSubCategory() == subCategory)
                result.Insert(recipe);
        }
        
        return result;
    }
    
    S88CraftingRecipe GetRecipeByName(string name)
    {
        foreach (S88CraftingRecipe recipe : m_AllRecipes)
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
