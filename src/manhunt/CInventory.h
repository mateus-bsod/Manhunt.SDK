#pragma once

#define CYCLE_INVENTORY_ADDR 0x45BFC0

typedef void(__thiscall* tCycleInventoryItem)(void* pPlayer, int a1, int a2, int itemType, int direction);

extern tCycleInventoryItem oCycleInventoryItem;
extern SafetyHookInline g_CycleInventoryHook;

void __fastcall hkCycleInventoryItem(void* pThis, void* edx, int a1, int a2, int itemType, int direction);
void InstallInventoryHook();