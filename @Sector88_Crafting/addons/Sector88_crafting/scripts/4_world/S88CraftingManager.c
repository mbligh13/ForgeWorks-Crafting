// Sector 88 Crafting - Crafting Manager (Handles Craft Logic)
// Path: scripts/4_world/S88CraftingManager.c

class S88CraftingManager
{
    // Singleton
    private static ref S88CraftingManager s_Instance;
    
    // Active crafting operations
    protected ref map<PlayerBase, ref S88CraftingOperation> m_ActiveOperations;
    
    void S88CraftingManager()
    {
        m_ActiveOperations = new map<PlayerBase, ref S88CraftingOperation>;
    }
    
    static S88CraftingManager GetInstance()
    {
        if (!s_Instance)
            s_Instance = new S88CraftingManager();
        return s_Instance;
    }
    
    void RequestCraft(S88CraftingRecipe recipe, PlayerBase player, Object workbench)
    {
        if (!recipe || !player || !workbench)
            return;
            
        // Validate workbench has materials (not player)
        if (!ValidateMaterials(recipe, workbench))
        {
            NotifyPlayer(player, "Insufficient materials in workbench!");
            return;
        }
        
        // Validate workbench has space for crafted item
        if (!ValidateInventorySpace(recipe, workbench))
        {
            NotifyPlayer(player, "Workbench inventory is full! Remove items before crafting.");
            return;
        }
        
        // Check if player already crafting
        if (m_ActiveOperations.Contains(player))
        {
            NotifyPlayer(player, "Already crafting!");
            return;
        }
        
        // Start crafting operation
        ref S88CraftingOperation operation = new S88CraftingOperation(recipe, player, workbench);
        m_ActiveOperations.Insert(player, operation);
        
        // Begin crafting timer
        operation.Start();
        
        NotifyPlayer(player, "Crafting " + recipe.GetDisplayName() + "...");
    }
    
    protected bool ValidateMaterials(S88CraftingRecipe recipe, Object workbench)
    {
        if (!workbench)
            return false;
            
        array<ref S88CraftingIngredient> ingredients = recipe.GetIngredients();
        
        foreach (S88CraftingIngredient ingredient : ingredients)
        {
            int available = CountObjectItems(workbench, ingredient.GetClassName());
                
            if (available < ingredient.GetAmount())
                return false;
        }
        
        return true;
    }
    
    protected bool ValidateInventorySpace(S88CraftingRecipe recipe, Object workbench)
    {
        if (!workbench)
            return false;
            
        ItemBase workbenchItem = ItemBase.Cast(workbench);
        if (!workbenchItem || !workbenchItem.GetInventory())
            return false;
            
        // Check if workbench has space for result items
        array<string> results = recipe.GetResults();
        
        foreach (string resultClass : results)
        {
            // Test if item can fit in inventory
            if (!workbenchItem.GetInventory().CanAddEntityInCargoEx(null, 0, 0, 0, false, false))
            {
                return false;
            }
        }
        
        return true;
    }
    
    // No tool validation needed - workbench is just a focus object
    
    // Only workbench inventory is checked
    
    protected int CountObjectItems(Object obj, string className)
    {
        if (!obj)
            return 0;
            
        ItemBase item = ItemBase.Cast(obj);
        if (!item || !item.GetInventory())
            return 0;
            
        int count = 0;
        array<EntityAI> items = new array<EntityAI>;
        item.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, items);
        
        foreach (EntityAI invItem : items)
        {
            if (invItem.GetType() == className)
                count++;
        }
        
        return count;
    }
    
    void OnCraftingComplete(S88CraftingOperation operation)
    {
        if (!operation)
            return;
            
        PlayerBase player = operation.GetPlayer();
        S88CraftingRecipe recipe = operation.GetRecipe();
        Object workbench = operation.GetWorkbench();
        
        if (!player || !recipe)
            return;
            
        // Remove ingredients from workbench
        RemoveIngredients(recipe, workbench);
        
        // Spawn crafted item(s)
        SpawnResults(recipe, player, workbench);
        
        // Notify player
        NotifyPlayer(player, "Crafting complete! " + recipe.GetDisplayName() + " is in the workbench.");
        
        // Play completion sound
        GetGame().GetSoundScene().Play("craft_complete_SoundSet", player.GetPosition());
        
        // Remove from active operations
        m_ActiveOperations.Remove(player);
    }
    
    void OnCraftingCancelled(S88CraftingOperation operation)
    {
        if (!operation)
            return;
            
        PlayerBase player = operation.GetPlayer();
        
        if (player)
        {
            NotifyPlayer(player, "Crafting cancelled.");
            m_ActiveOperations.Remove(player);
        }
    }
    
    protected void RemoveIngredients(S88CraftingRecipe recipe, Object workbench)
    {
        if (!workbench)
            return;
            
        ItemBase workbenchItem = ItemBase.Cast(workbench);
        if (!workbenchItem)
            return;
            
        array<ref S88CraftingIngredient> ingredients = recipe.GetIngredients();
        
        foreach (S88CraftingIngredient ingredient : ingredients)
        {
            RemoveItemsFromInventory(workbenchItem, ingredient.GetClassName(), ingredient.GetAmount());
        }
    }
    
    protected int RemoveItemsFromInventory(EntityAI container, string className, int count)
    {
        if (!container || !container.GetInventory() || count <= 0)
            return count;
            
        array<EntityAI> items = new array<EntityAI>;
        container.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, items);
        
        int remaining = count;
        
        foreach (EntityAI item : items)
        {
            if (item.GetType() == className && remaining > 0)
            {
                GetGame().ObjectDelete(item);
                remaining--;
                
                if (remaining <= 0)
                    break;
            }
        }
        
        return remaining;
    }
    
    protected void SpawnResults(S88CraftingRecipe recipe, PlayerBase player, Object workbench)
    {
        if (!workbench)
            return;
            
        ItemBase workbenchItem = ItemBase.Cast(workbench);
        if (!workbenchItem || !workbenchItem.GetInventory())
            return;
            
        array<string> results = recipe.GetResults();
        
        foreach (string resultClass : results)
        {
            // Spawn in workbench inventory only (space was pre-validated)
            EntityAI result = workbenchItem.GetInventory().CreateInInventory(resultClass);
            if (!result)
            {
                // This shouldn't happen due to pre-validation, but log if it does
                Print("[S88] ERROR: Failed to spawn " + resultClass + " in workbench after crafting!");
            }
        }
    }
    
    protected void NotifyPlayer(PlayerBase player, string message)
    {
        if (!player)
            return;
            
        // Send notification
        if (GetGame().IsServer())
        {
            // Server-side notification via RPC
            Param1<string> params = new Param1<string>(message);
            GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, params, true, player.GetIdentity());
        }
        else
        {
            // Client-side notification
            GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", message, ""));
        }
    }
    
    bool IsPlayerCrafting(PlayerBase player)
    {
        return m_ActiveOperations.Contains(player);
    }
    
    void CancelCrafting(PlayerBase player)
    {
        if (!m_ActiveOperations.Contains(player))
            return;
            
        S88CraftingOperation operation = m_ActiveOperations.Get(player);
        if (operation)
            operation.Cancel();
    }
}

// ============================================
// CRAFTING OPERATION (Individual Craft Instance)
// ============================================
class S88CraftingOperation
{
    protected ref S88CraftingRecipe m_Recipe;
    protected PlayerBase m_Player;
    protected Object m_Workbench;
    protected float m_TimeRemaining;
    protected bool m_IsCancelled;
    protected ref Timer m_Timer;
    
    void S88CraftingOperation(S88CraftingRecipe recipe, PlayerBase player, Object workbench)
    {
        m_Recipe = recipe;
        m_Player = player;
        m_Workbench = workbench;
        m_TimeRemaining = recipe.GetCraftingTime();
        m_IsCancelled = false;
    }
    
    void ~S88CraftingOperation()
    {
        if (m_Timer)
            m_Timer.Stop();
    }
    
    S88CraftingRecipe GetRecipe() { return m_Recipe; }
    PlayerBase GetPlayer() { return m_Player; }
    Object GetWorkbench() { return m_Workbench; }
    float GetTimeRemaining() { return m_TimeRemaining; }
    
    void Start()
    {
        m_Timer = new Timer();
        m_Timer.Run(1.0, this, "OnTick", null, true);
    }
    
    void Cancel()
    {
        m_IsCancelled = true;
        
        if (m_Timer)
            m_Timer.Stop();
            
        S88CraftingManager.GetInstance().OnCraftingCancelled(this);
    }
    
    protected void OnTick()
    {
        if (m_IsCancelled)
            return;
            
        m_TimeRemaining -= 1.0;
        
        // Check if player moved too far from workbench
        if (m_Player && m_Workbench)
        {
            float dist = vector.Distance(m_Player.GetPosition(), m_Workbench.GetPosition());
            if (dist > 3.0)
            {
                Cancel();
                return;
            }
        }
        
        // Check completion
        if (m_TimeRemaining <= 0)
        {
            if (m_Timer)
                m_Timer.Stop();
                
            S88CraftingManager.GetInstance().OnCraftingComplete(this);
        }
    }
}
