#include "../../framework.h"
#include "CInventory.h"

tCycleInventoryItem oCycleInventoryItem = nullptr;
SafetyHookInline g_CycleInventoryHook;

void __fastcall hkCycleInventoryItem(void* pThis, void* edx, int a1, int a2, int itemType, int direction)
{
    oCycleInventoryItem(pThis, a1, a2, itemType, direction);
}

void InstallInventoryHook()
{
    g_CycleInventoryHook = safetyhook::create_inline(
        (void*)0x45BFC0,
        (void*)hkCycleInventoryItem
    );
    oCycleInventoryItem = 
        g_CycleInventoryHook.original<tCycleInventoryItem>();
}
