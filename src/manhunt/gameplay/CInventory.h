//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#pragma once

#include "../../game.sdk.h"
#include "../../../framework.h"

typedef void(__fastcall* tCycleInventoryItem)(void* pThis, void* edx, int a1, int a2, int itemType, int direction);

class CInventory
{
private:
    static tCycleInventoryItem oCycleInventoryItem;
    static SafetyHookInline g_CycleInventoryHook;

    static void __fastcall hkCycleInventoryItem(void* pThis, void* edx, int a1, int a2, int itemType, int direction);

public:
    class SlotSelection
    {
    public:
        static DWORD& GetLastSelectedSlot();
        static DWORD& GetWeaponChangedFlag();
        static DWORD& GetWeaponEmptyFlag();
        static DWORD& GetCurrentSelectedSlot();
    };


    int Inventory_GetItemType();

    static void InstallHook();
};