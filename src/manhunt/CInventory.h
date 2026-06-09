#pragma once

#include "../../framework.h"

namespace CInventory
{

	typedef void(__thiscall* tCycleInventoryItem)(void* pPlayer, int a1, int a2, int itemType, int direction);

	extern tCycleInventoryItem oCycleInventoryItem;
	extern SafetyHookInline g_CycleInventoryHook;

	void __fastcall hkCycleInventoryItem(void* pThis, void* edx, int a1, int a2, int itemType, int direction);
	void InstallHook();
};

