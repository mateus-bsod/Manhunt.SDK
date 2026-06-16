//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CInventory.h"

tCycleInventoryItem CInventory::oCycleInventoryItem = nullptr;
SafetyHookInline CInventory::g_CycleInventoryHook;

DWORD& CInventory::SlotSelection::GetLastSelectedSlot()
{
    static DWORD& g_LastSelectedSlot = *(DWORD*)0x7C9B28;
    return g_LastSelectedSlot;
}

DWORD& CInventory::SlotSelection::GetWeaponChangedFlag()
{
    static DWORD& g_WeaponChangedFlag = *(DWORD*)0x7C9B30;
    return g_WeaponChangedFlag;
}

DWORD& CInventory::SlotSelection::GetWeaponEmptyFlag()
{
    static DWORD& g_WeaponEmptyFlag = *(DWORD*)0x7C9B74;
    return g_WeaponEmptyFlag;
}

DWORD& CInventory::SlotSelection::GetCurrentSelectedSlot()
{
    static DWORD& g_CurrentSelectedSlot = *(DWORD*)0x7C9CD0;
    return g_CurrentSelectedSlot;
}

int CInventory::Inventory_GetItemType()
{
    return CallAndReturn<int, 0x4F8150, CInventory*>(this);
}

void CInventory::InstallHook()
{

}