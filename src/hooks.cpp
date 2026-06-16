//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "../framework.h"

#include "manhunt/core/CConfigs.h"
#include "manhunt/game/CPhysics.h"
#include "manhunt/gameplay/CCollectable.h"
#include "manhunt/gameplay/CInventory.h"
#include "manhunt/gameplay/CWeapons.h"
#include "manhunt/entity/CPlayer.h"
#include "manhunt/ui/CMenu.h"
#include "manhunt/ui/CText.h"
#include "manhunt/game/CInput.h"
#include "manhunt/ui/CMainMenu.h"
#include "manhunt/core/CGame.h"
#include "manhunt/core/CResourceManager.h"




// --------------------------------------------------------------------------------

typedef void(__cdecl* tPrint)(void* logger, const char* text);

tPrint oPrint = nullptr;
SafetyHookInline g_PrintHook;

void __cdecl hkPrint(void* logger, const char* text)
{
    if (text)
    {
        /*
        if (strcmp(text, "OK") == 0)
        {
            ClearConsole();
            return;
        }
        */

		Console::Printf("[CGame::Log] %s\n", text);
    }

    oPrint(logger, text);
}

// ------------------------------------------------------------------------------------




void InitHooks()
{
    g_PrintHook = safetyhook::create_inline(
        reinterpret_cast<void*>(0x0060F110),
        reinterpret_cast<void*>(&hkPrint)
    );

    oPrint = g_PrintHook.original<tPrint>();

    //

	CConfigs::InstallHook();
    CResourceManager::InstallHook();
    CGame::InstallHook();

    CCollectable::InstallHook();
    CWeapon::InstallHook();
    CPlayer::InstallHook();
    CPhysics::InstallHook();
    CInventory::InstallHook();
    CMenu::InstallHook();
    CMainMenu::InstallHook();
    CVisual::InstallHook();
    CInput::InstallHook();
    CText::InstallHook();
}
