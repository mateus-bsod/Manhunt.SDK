//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//----------------------------------------------------------

#define DEBUG_CONSOLE true


#include "framework.h"
#include "./src/game.sdk.h"

#include "src/manhunt/core/CDiscord.h"
#include "src/manhunt/core/CConfigs.h"
#include "src/manhunt/core/CConfigs.h"
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
    HMODULE hD3D8 = LoadLibraryA("d3d8.dll");
    if (!hD3D8)
        MessageBoxA(nullptr, "[SDK] d3d8.dll não encontrada!", "Manhunt.SDK", MB_OK | MB_ICONINFORMATION);


    // Disable Lock On
	// PATCH(0x475EA0 + 0x273, 0x90, 5); // LOCK-ON
	// PATCH(0x5EF990 + 0x1EF0, 0x90, 5); // health

	// Disable Crow and Rats
    //PATCH(0x5CF3D0 + 0x7, 0x90, 5); // UpdateCrowEffects
    //PATCH(0x474BD0 + 0xB5, 0x90, 5); // ManageCrowSwarm
    //PATCH(0x5CFAA0 + 0xCD7, 0x90, 5); // CrowLand (ou UpdateCrowSwarm)

    // Disable neblina
    //PATCH(0x4E9110 + 0xDD, 0x90, 5); // particulas de neblina
    //PATCH(0x475EA0 + 0x25F, 0x90, 5); // particulas de neblina
    // // PATCH(0x4F2F10 + 0x5B2, 0x90, 5); // particulas de neblina
    InitHooks();
    Console::Init();
	CDiscord::initDiscord();
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

        HANDLE hThread = CreateThread(nullptr, 0, MainThread, nullptr, 0, nullptr);
        if (hThread)
            CloseHandle(hThread);
    }
	if (reason == DLL_PROCESS_DETACH)
    {
        CInput::Shutdown();
        CDiscord::Shutdown();
    }

    return TRUE;
}