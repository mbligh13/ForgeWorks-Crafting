// Sector 88 Crafting Workbench - Main Menu Controller
// Path: scripts/5_mission/gui/S88CraftingMenu.c

class S88CraftingMenu extends UIScriptedMenu
{
    // UI References
    protected Widget m_Root;
    protected TabberWidget m_Tabber;
    protected GridSpacerWidget m_RecipeGrid;
    protected ImageWidget m_ItemPreview;
    protected TextWidget m_ItemName;
    protected TextWidget m_CraftingTime;
    protected GridSpacerWidget m_MaterialsGrid;
    protected ButtonWidget m_CraftButton;
    protected TextWidget m_AttachmentsText;
    
    // Data
    protected ref array<ref S88CraftingCategory> m_Categories;
    protected ref S88CraftingRecipe m_SelectedRecipe;
    protected Object m_Workbench;
    protected PlayerBase m_Player;
    
    // Constants
    const int CATEGORY_PISTOLS = 0;
    const int CATEGORY_SMGS = 1;
    const int CATEGORY_RIFLES = 2;
    const int CATEGORY_SNIPERS = 3;
    const int CATEGORY_SHOTGUNS = 4;
    const int CATEGORY_MAGAZINES = 5;
    
    void S88CraftingMenu()
    {
        m_Categories = new array<ref S88CraftingCategory>;
        InitializeCategories();
    }
    
    void ~S88CraftingMenu()
    {
        m_Categories.Clear();
    }
    
    override Widget Init()
    {
        m_Root = GetGame().GetWorkspace().CreateWidgets("Sector88_Crafting/gui/layouts/S88CraftingMenu.layout");
        
        // Get UI element references
        m_Tabber = TabberWidget.Cast(m_Root.FindAnyWidget("CategoryTabber"));
        m_RecipeGrid = GridSpacerWidget.Cast(m_Root.FindAnyWidget("RecipeGrid"));
        m_ItemPreview = ImageWidget.Cast(m_Root.FindAnyWidget("ItemPreviewImage"));
        m_ItemName = TextWidget.Cast(m_Root.FindAnyWidget("ItemNameText"));
        m_CraftingTime = TextWidget.Cast(m_Root.FindAnyWidget("CraftingTimeText"));
        m_MaterialsGrid = GridSpacerWidget.Cast(m_Root.FindAnyWidget("MaterialsGrid"));
        m_CraftButton = ButtonWidget.Cast(m_Root.FindAnyWidget("CraftButton"));
        m_AttachmentsText = TextWidget.Cast(m_Root.FindAnyWidget("AttachmentsText"));
        
        m_Player = PlayerBase.Cast(GetGame().GetPlayer());
        
        // Initialize first category
        if (m_Tabber)
            OnCategoryChanged(0);
        
        return m_Root;
    }
    
    override void OnShow()
    {
        super.OnShow();
        GetGame().GetInput().ChangeGameFocus(1);
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowUICursor(true);
        
        RefreshMaterialsDisplay();
    }
    
    override void OnHide()
    {
        super.OnHide();
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetUIManager().ShowUICursor(false);
    }
    
    void SetWorkbench(Object workbench)
    {
        m_Workbench = workbench;
    }
    
    protected void InitializeCategories()
    {
        // Pistol Calibers
        ref S88CraftingCategory pistols = new S88CraftingCategory("Pistols", "set:dayz_gui image:pistol");
        pistols.AddSubCategory("9mm");
        pistols.AddSubCategory(".45 ACP");
        pistols.AddSubCategory(".22 LR");
        pistols.AddSubCategory("7.62x25");
        pistols.AddSubCategory(".380");
        m_Categories.Insert(pistols);
        
        // SMGs
        ref S88CraftingCategory smgs = new S88CraftingCategory("SMGs", "set:dayz_gui image:smg");
        smgs.AddSubCategory("9mm SMG");
        smgs.AddSubCategory(".45 ACP SMG");
        smgs.AddSubCategory("7.62x25 SMG");
        m_Categories.Insert(smgs);
        
        // Assault Rifles
        ref S88CraftingCategory rifles = new S88CraftingCategory("Rifles", "set:dayz_gui image:rifle");
        rifles.AddSubCategory("5.56x45");
        rifles.AddSubCategory("5.45x39");
        rifles.AddSubCategory("7.62x39");
        rifles.AddSubCategory(".300 BLK");
        rifles.AddSubCategory("9x39");
        m_Categories.Insert(rifles);
        
        // Sniper/DMR
        ref S88CraftingCategory snipers = new S88CraftingCategory("Snipers", "set:dayz_gui image:sniper");
        snipers.AddSubCategory(".308 Win");
        snipers.AddSubCategory("7.62x54R");
        snipers.AddSubCategory(".300 WinMag");
        snipers.AddSubCategory(".338 Lapua");
        snipers.AddSubCategory(".408 CheyTac");
        snipers.AddSubCategory(".50 BMG");
        m_Categories.Insert(snipers);
        
        // Shotguns
        ref S88CraftingCategory shotguns = new S88CraftingCategory("Shotguns", "set:dayz_gui image:shotgun");
        shotguns.AddSubCategory("12 Gauge");
        m_Categories.Insert(shotguns);
        
        // Magazines
        ref S88CraftingCategory magazines = new S88CraftingCategory("Magazines", "set:dayz_gui image:magazine");
        magazines.AddSubCategory("Pistol Mags");
        magazines.AddSubCategory("SMG Mags");
        magazines.AddSubCategory("AR Mags");
        magazines.AddSubCategory("Drums");
        magazines.AddSubCategory("LMG Belts");
        m_Categories.Insert(magazines);
    }
    
    void OnCategoryChanged(int categoryIndex)
    {
        if (categoryIndex < 0 || categoryIndex >= m_Categories.Count())
            return;
            
        S88CraftingCategory category = m_Categories.Get(categoryIndex);
        PopulateRecipeGrid(category);
    }
    
    protected void PopulateRecipeGrid(S88CraftingCategory category)
    {
        // Clear existing recipe buttons
        ClearRecipeGrid();
        
        // Load recipes for this category from S88RecipeManager
        array<ref S88CraftingRecipe> recipes = S88RecipeManager.GetInstance().GetRecipesForCategory(category.GetName());
        
        if (!recipes)
            return;
            
        foreach (S88CraftingRecipe recipe : recipes)
        {
            CreateRecipeButton(recipe);
        }
    }
    
    protected void ClearRecipeGrid()
    {
        if (!m_RecipeGrid)
            return;
            
        Widget child = m_RecipeGrid.GetChildren();
        while (child)
        {
            Widget next = child.GetSibling();
            child.Unlink();
            child = next;
        }
    }
    
    protected void CreateRecipeButton(S88CraftingRecipe recipe)
    {
        Widget recipeWidget = GetGame().GetWorkspace().CreateWidgets("Sector88_Crafting/gui/layouts/S88RecipeButton.layout", m_RecipeGrid);
        
        if (!recipeWidget)
            return;
            
        // Set icon
        ImageWidget icon = ImageWidget.Cast(recipeWidget.FindAnyWidget("RecipeIcon"));
        if (icon)
        {
            string iconPath = recipe.GetIconPath();
            if (iconPath != "")
                icon.LoadImageFile(0, iconPath);
        }
        
        // Set name
        TextWidget nameText = TextWidget.Cast(recipeWidget.FindAnyWidget("RecipeName"));
        if (nameText)
            nameText.SetText(recipe.GetDisplayName());
            
        // Store recipe reference
        recipeWidget.SetUserData(recipe);
    }
    
    void SelectRecipe(S88CraftingRecipe recipe)
    {
        m_SelectedRecipe = recipe;
        
        // Update preview
        if (m_ItemPreview && recipe.GetPreviewPath() != "")
            m_ItemPreview.LoadImageFile(0, recipe.GetPreviewPath());
            
        // Update name
        if (m_ItemName)
            m_ItemName.SetText(recipe.GetDisplayName());
            
        // Update crafting time
        if (m_CraftingTime)
            m_CraftingTime.SetText("Time: " + recipe.GetCraftingTime().ToString() + "s");
            
        // Update required attachments
        if (m_AttachmentsText)
            m_AttachmentsText.SetText("Attachments: " + recipe.GetRequiredAttachments());
        
        // Update materials display
        RefreshMaterialsDisplay();
    }
    
    protected void RefreshMaterialsDisplay()
    {
        if (!m_MaterialsGrid || !m_SelectedRecipe)
            return;
            
        // Clear existing materials
        Widget child = m_MaterialsGrid.GetChildren();
        while (child)
        {
            Widget next = child.GetSibling();
            child.Unlink();
            child = next;
        }
        
        // Add material widgets
        array<ref S88CraftingIngredient> ingredients = m_SelectedRecipe.GetIngredients();
        foreach (S88CraftingIngredient ingredient : ingredients)
        {
            CreateMaterialWidget(ingredient);
        }
        
        // Update craft button state
        UpdateCraftButtonState();
    }
    
    protected void CreateMaterialWidget(S88CraftingIngredient ingredient)
    {
        Widget matWidget = GetGame().GetWorkspace().CreateWidgets("Sector88_Crafting/gui/layouts/S88MaterialSlot.layout", m_MaterialsGrid);
        
        if (!matWidget)
            return;
            
        ImageWidget icon = ImageWidget.Cast(matWidget.FindAnyWidget("MaterialIcon"));
        TextWidget countText = TextWidget.Cast(matWidget.FindAnyWidget("MaterialCount"));
        
        if (icon)
        {
            string iconPath = S88RecipeManager.GetItemIcon(ingredient.GetClassName());
            if (iconPath != "")
                icon.LoadImageFile(0, iconPath);
        }
        
        if (countText)
        {
            int playerHas = GetPlayerItemCount(ingredient.GetClassName());
            int required = ingredient.GetAmount();
            
            string countStr = playerHas.ToString() + "/" + required.ToString();
            countText.SetText(countStr);
            
            // Color based on availability
            if (playerHas >= required)
                countText.SetColor(ARGB(255, 0, 255, 0)); // Green
            else
                countText.SetColor(ARGB(255, 255, 0, 0)); // Red
        }
    }
    
    protected int GetPlayerItemCount(string className)
    {
        if (!m_Player)
            return 0;
            
        int count = 0;
        
        // Check player inventory
        array<EntityAI> items = new array<EntityAI>;
        m_Player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, items);
        
        foreach (EntityAI item : items)
        {
            if (item.GetType() == className)
                count++;
        }
        
        // Also check workbench inventory if applicable
        if (m_Workbench)
        {
            ItemBase workbenchItem = ItemBase.Cast(m_Workbench);
            if (workbenchItem && workbenchItem.GetInventory())
            {
                array<EntityAI> workbenchItems = new array<EntityAI>;
                workbenchItem.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, workbenchItems);
                
                foreach (EntityAI wItem : workbenchItems)
                {
                    if (wItem.GetType() == className)
                        count++;
                }
            }
        }
        
        return count;
    }
    
    protected void UpdateCraftButtonState()
    {
        if (!m_CraftButton || !m_SelectedRecipe)
            return;
            
        bool canCraft = CanCraftSelectedRecipe();
        m_CraftButton.Enable(canCraft);
        
        // Visual feedback
        if (canCraft)
            m_CraftButton.SetColor(ARGB(255, 180, 0, 0)); // Red enabled
        else
            m_CraftButton.SetColor(ARGB(255, 80, 80, 80)); // Grey disabled
    }
    
    protected bool CanCraftSelectedRecipe()
    {
        if (!m_SelectedRecipe || !m_Player)
            return false;
            
        array<ref S88CraftingIngredient> ingredients = m_SelectedRecipe.GetIngredients();
        
        foreach (S88CraftingIngredient ingredient : ingredients)
        {
            int playerHas = GetPlayerItemCount(ingredient.GetClassName());
            if (playerHas < ingredient.GetAmount())
                return false;
        }
        
        return true;
    }
    
    void OnCraftButtonClick()
    {
        if (!CanCraftSelectedRecipe())
            return;
            
        // Send craft request to server
        S88CraftingManager.GetInstance().RequestCraft(m_SelectedRecipe, m_Player, m_Workbench);
        
        // Play sound
        GetGame().GetSoundScene().Play("craft_start_SoundSet", GetGame().GetPlayer().GetPosition());
        
        // Refresh display
        RefreshMaterialsDisplay();
    }
    
    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_CraftButton)
        {
            OnCraftButtonClick();
            return true;
        }
        
        // Check if clicked on a recipe button
        S88CraftingRecipe recipe = S88CraftingRecipe.Cast(w.GetUserData());
        if (recipe)
        {
            SelectRecipe(recipe);
            return true;
        }
        
        return super.OnClick(w, x, y, button);
    }
    
    override bool OnChange(Widget w, int x, int y, bool finished)
    {
        if (w == m_Tabber)
        {
            OnCategoryChanged(m_Tabber.GetCurrentTab());
            return true;
        }
        
        return super.OnChange(w, x, y, finished);
    }
    
    override void Update(float timeslice)
    {
        super.Update(timeslice);
        
        // Close on ESC
        if (GetGame().GetInput().LocalPress("UAUIBack", false))
        {
            Close();
        }
    }
}
