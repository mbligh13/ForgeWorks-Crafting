// Sector 88 Crafting Workbench - Custom Object with Interaction
// Path: scripts/4_world/entities/FWCraftingWorkbench.c

class FWCraftingWorkbench extends ItemBase
{
    // Sound effects
    protected EffectSound m_AmbientSound;
    
    void FWCraftingWorkbench()
    {
        SetEventMask(EntityEvent.INIT);
        RegisterNetSyncVariableInt("m_IsBeingUsed");
    }
    
    void ~FWCraftingWorkbench()
    {
        StopAmbientSound();
    }
    
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionFWOpenCraftingMenu);
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
    
    // No tool checking needed - workbench is just a focus object for the GUI
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
class FWCraftingWorkbench_Military : FWCraftingWorkbench
{
    // Military-grade workbench with more slots
}

class FWCraftingWorkbench_Civilian : FWCraftingWorkbench
{
    // Basic civilian workbench
}
