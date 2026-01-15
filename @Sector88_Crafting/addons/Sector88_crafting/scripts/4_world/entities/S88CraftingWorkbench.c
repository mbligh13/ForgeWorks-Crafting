// Sector 88 Crafting Workbench - Custom Object with Interaction
// Path: scripts/4_world/entities/S88CraftingWorkbench.c

class S88CraftingWorkbench extends ItemBase
{
    // Sound effects
    protected EffectSound m_AmbientSound;
    
    void S88CraftingWorkbench()
    {
        SetEventMask(EntityEvent.INIT);
        RegisterNetSyncVariableInt("m_IsBeingUsed");
    }
    
    void ~S88CraftingWorkbench()
    {
        StopAmbientSound();
    }
    
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionS88OpenCraftingMenu);
    }
    
    override bool IsInventoryVisible()
    {
        return true;
    }
    
    override bool CanDisplayAttachmentCategory(string category_name)
    {
        return true;
    }
    
    override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        return super.CanReceiveAttachment(attachment, slotId);
    }
    
    override bool CanPutInCargo(EntityAI parent)
    {
        return false;
    }
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
    
    override bool CanRemoveFromHands(EntityAI parent)
    {
        return false;
    }
    
    override bool IsElectricAppliance()
    {
        return false;
    }
    
    override void OnStoreSave(ParamsWriteContext ctx)
    {
        super.OnStoreSave(ctx);
    }
    
    override bool OnStoreLoad(ParamsReadContext ctx, int version)
    {
        if (!super.OnStoreLoad(ctx, version))
            return false;
            
        return true;
    }
    
    // Check if player has required tools attached to workbench
    bool HasRequiredTools(string toolList)
    {
        if (toolList == "")
            return true;
            
        TStringArray tools = new TStringArray;
        toolList.Split(",", tools);
        
        foreach (string tool : tools)
        {
            tool = tool.Trim();
            if (!HasToolAttached(tool))
                return false;
        }
        
        return true;
    }
    
    protected bool HasToolAttached(string toolClass)
    {
        if (!GetInventory())
            return false;
            
        int slots = GetInventory().GetAttachmentSlotsCount();
        for (int i = 0; i < slots; i++)
        {
            EntityAI attachment = GetInventory().GetAttachmentFromIndex(i);
            if (attachment)
            {
                // Check exact class or base class
                if (attachment.GetType() == toolClass)
                    return true;
                    
                if (attachment.IsKindOf(toolClass))
                    return true;
            }
        }
        
        return false;
    }
    
    void PlayAmbientSound()
    {
        if (!m_AmbientSound)
        {
            m_AmbientSound = SEffectManager.PlaySound("workshop_ambience_SoundSet", GetPosition());
        }
    }
    
    void StopAmbientSound()
    {
        if (m_AmbientSound)
        {
            m_AmbientSound.Stop();
            m_AmbientSound = null;
        }
    }
}

// ============================================
// Workbench variants for different locations
// ============================================
class S88CraftingWorkbench_Military : S88CraftingWorkbench
{
    // Military-grade workbench with more slots
}

class S88CraftingWorkbench_Civilian : S88CraftingWorkbench
{
    // Basic civilian workbench
}
