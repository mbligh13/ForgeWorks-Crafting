// Sector 88 Crafting - Data Classes
// Path: scripts/4_world/S88CraftingData.c

// ============================================
// CRAFTING INGREDIENT
// ============================================
class S88CraftingIngredient
{
    protected string m_ClassName;
    protected int m_Amount;
    protected string m_DisplayName;
    
    void S88CraftingIngredient(string className, int amount)
    {
        m_ClassName = className;
        m_Amount = amount;
        m_DisplayName = GetDisplayNameFromClass(className);
    }
    
    string GetClassName() { return m_ClassName; }
    int GetAmount() { return m_Amount; }
    string GetDisplayName() { return m_DisplayName; }
    
    protected string GetDisplayNameFromClass(string className)
    {
        // Get display name from config
        string cfgPath = "CfgVehicles " + className + " displayName";
        string displayName;
        GetGame().ConfigGetText(cfgPath, displayName);
        
        if (displayName == "")
            return className;
            
        return displayName;
    }
}

// ============================================
// CRAFTING RECIPE
// ============================================
class S88CraftingRecipe
{
    protected string m_Name;
    protected string m_DisplayName;
    protected string m_Category;
    protected string m_SubCategory;
    protected int m_CraftingTime;
    protected string m_IconPath;
    protected string m_PreviewPath;
    protected string m_RequiredAttachments;
    
    protected ref array<ref S88CraftingIngredient> m_Ingredients;
    protected ref array<string> m_Results;
    
    void S88CraftingRecipe()
    {
        m_Ingredients = new array<ref S88CraftingIngredient>;
        m_Results = new array<string>;
        m_CraftingTime = 5;
        m_RequiredAttachments = "";
    }
    
    void SetName(string name) { m_Name = name; }
    void SetDisplayName(string name) { m_DisplayName = name; }
    void SetCategory(string cat) { m_Category = cat; }
    void SetSubCategory(string subCat) { m_SubCategory = subCat; }
    void SetCraftingTime(int time) { m_CraftingTime = time; }
    void SetIconPath(string path) { m_IconPath = path; }
    void SetPreviewPath(string path) { m_PreviewPath = path; }
    void SetRequiredAttachments(string attachments) { m_RequiredAttachments = attachments; }
    
    string GetName() { return m_Name; }
    string GetDisplayName() { return m_DisplayName; }
    string GetCategory() { return m_Category; }
    string GetSubCategory() { return m_SubCategory; }
    int GetCraftingTime() { return m_CraftingTime; }
    string GetIconPath() { return m_IconPath; }
    string GetPreviewPath() { return m_PreviewPath; }
    string GetRequiredAttachments() { return m_RequiredAttachments; }
    
    void AddIngredient(string className, int amount)
    {
        m_Ingredients.Insert(new S88CraftingIngredient(className, amount));
    }
    
    void AddResult(string className)
    {
        m_Results.Insert(className);
    }
    
    array<ref S88CraftingIngredient> GetIngredients()
    {
        return m_Ingredients;
    }
    
    array<string> GetResults()
    {
        return m_Results;
    }
}

// ============================================
// CRAFTING CATEGORY
// ============================================
class S88CraftingCategory
{
    protected string m_Name;
    protected string m_IconPath;
    protected ref array<string> m_SubCategories;
    
    void S88CraftingCategory(string name, string iconPath = "")
    {
        m_Name = name;
        m_IconPath = iconPath;
        m_SubCategories = new array<string>;
    }
    
    string GetName() { return m_Name; }
    string GetIconPath() { return m_IconPath; }
    
    void AddSubCategory(string subCat)
    {
        m_SubCategories.Insert(subCat);
    }
    
    array<string> GetSubCategories()
    {
        return m_SubCategories;
    }
}

// ============================================
// WORKBENCH POSITION CONFIG
// ============================================
class S88WorkbenchPosition
{
    vector m_Position;
    vector m_Orientation;
    string m_MapName;
    
    void S88WorkbenchPosition(vector pos, vector ori, string mapName = "")
    {
        m_Position = pos;
        m_Orientation = ori;
        m_MapName = mapName;
    }
    
    vector GetPosition() { return m_Position; }
    vector GetOrientation() { return m_Orientation; }
    string GetMapName() { return m_MapName; }
}
