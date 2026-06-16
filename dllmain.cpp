//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//----------------------------------------------------------

#define DEBUG_CONSOLE true


#include "framework.h"
#include "./src/game.sdk.h"

#include "src/manhunt/entity/CPlayer.h"
#include "src/manhunt/ui/CText.h"
#include "src/manhunt/ui/CMainMenu.h"
#include "src/manhunt/gameplay/CWeapons.h"
#include "src/manhunt/ui/CVisual.h"    
#include "src/manhunt/core/CGame.h"    
#include "src/manhunt/game/CInput.h"    
#include "src/manhunt/entity/CEntity.h"    

#include "./src/hooks.h"

#include <stdio.h>


DWORD WINAPI MainThread(LPVOID)
{
    Console::Init();
    InitHooks();

    // Disable Lock On
	PATCH(0x475EA0 + 0x273, 0x90, 5); // LOCK-ON
    
	// Disable Crow and Rats
    PATCH(0x5CF3D0 + 0x7, 0x90, 5); // UpdateCrowEffects
    PATCH(0x474BD0 + 0xB5, 0x90, 5); // ManageCrowSwarm
    PATCH(0x5CFAA0 + 0xCD7, 0x90, 5); // CrowLand (ou UpdateCrowSwarm)
    return 0;
}



BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD reason,
    LPVOID
)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);

        CreateThread(
            nullptr,
            0,
            MainThread,
            nullptr,
            0,

            nullptr
        );
    }
	if (reason == DLL_PROCESS_DETACH)
    {
        CInput::Shutdown();
    }

    return TRUE;
}