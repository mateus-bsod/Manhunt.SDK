//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//----------------------------------------------------------

/*

v21 = g_MissionData & 0x7FFF;
v1 = (double)v21 / flt_7B3198;  // Progresso da transição (0.0 a 1.0)

if ( v1 >= 1.0 )  // Se a transição acabou
{
    word_7B3238 = word_7B323A;  // Clima atual = próximo clima
    // Escolhe o próximo clima aleatório
    word_7B323A = word_7B3432[random];
}
*(float *)&dword_7B3244 = v1;  // Salva progresso

----

if ( !(dword_75628C & 7) )  // Se certas condições
    v0 = 1;  // Modo especial (player?)

if ( (dword_75628C & 7) == 3 )
    v17 = 1;  // Modo neblina

------

if ( !(dword_75628C & 7) )  // Se certas condições
    v0 = 1;  // Modo especial (player?)

if ( (dword_75628C & 7) == 3 )
    v17 = 1;  // Modo neblina

-----

  if ( dword_715BAC )
  {
    if ( dword_715CA8 == 4 ) // reinicia a fase
    if ( dword_715CA8 == 3 ) // menu principal
    if ( dword_715CA8 == 2 ) // ???
    if ( dword_715CA8 == 1 ) // crash
  }


-----

if ( dword_715BB0 && !dword_715BB4 ) // cam hacker

----

writeBytes(0x4D7B93, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90)  -- NOP
abertura loading?


sub_5EA2C0	IsPlayerInCover

----

7C9E58 - g_PlayerHUD_Radar

4BBCF0 - ToggleFullBright (funcao)

*/


#pragma comment(lib, "rwcore.lib")
#pragma comment(lib, "rpworld.lib")
#pragma comment(lib, "rtfsyst.lib")
#pragma comment(lib, "rphanim.lib")
#pragma comment(lib, "rpskin.lib")
#pragma comment(lib, "rpmatfx.lib")
#pragma comment(lib, "rt2d.lib")
#pragma comment(lib, "rttga.lib")
#pragma comment(lib, "rwplcore.lib")
#pragma comment(lib, "rpcollis.lib")
#pragma comment(lib, "rppvs.lib")
#pragma comment(lib, "rprandom.lib")

#pragma comment(lib, "msvcrt.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

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




int DeleteAllHunters()
{
    DWORD node = *CEntity::m_EntityList;
    int killed = 0;

    while (node)
    {
        CEntity* entity = (CEntity*)node;
        if (entity && entity->IsHunter())
        {
            entity->DestroyEntity();
            killed++;
        }
        node = *(DWORD*)(node + 8);
    }

    return killed;
}

/*
void LoadPlayerSkin(const char* skinDFF, const char* skinTXD)
{
    
      RegistryResource(&unk_739614, sub_4F2520, &unk_821088);
      InitializeResource(aGlobalCharpakC);
      RegistryResource(&dword_73961C, sub_4F2520, &unk_821094);
      InitializeResource(aGlobalCharpakC_0);
      RegistryResource(&dword_739624, sub_4F2520, &unk_8210A0);
    
    
	// CResourceManager::InitializeResource((void*)0x821088, skinDFF);
	// CResourceManager::RegistryResource((FileRegistryNode*)0x739614, (void*)0x4F2520, (void*)0x821088);
	// CResourceManager::InitializeResource((void*)0x821094, skinTXD);
	// CResourceManager::RegistryResource((FileRegistryNode*)0x73961C, (void*)0x4F2520, (void*)0x821094);
	char v7[260], v6[260];
    strcpy(v7, *(char**)skinTXD);                // // "/global/charpak/CASH_PC.TXD"
    strcpy(v6, *(char**)skinDFF);                // // "/global/charpak/CASH_PC.DFF"
    *(DWORD*)0x6A94A0 = *(DWORD*)0x69B6DE;
    *(DWORD*)0x6A94A4 = *(DWORD*)0x69B6E2;
    (*(DWORD*)0x6A94A8) = *(DWORD*)0x69B6E6;
    (*(DWORD*)0x6A94A8) = *(BYTE*)0x69B6E8;
    *(DWORD*)0x7AE94C = 1;
}
*/

void MyFunction()
{
	MessageBoxA(nullptr, "Manhunt.SDK carregado com sucesso!", "Manhunt.SDK", MB_OK | MB_ICONINFORMATION);
    //LoadPlayerSkin("Manhunt.SDK/skins/hel_pc.dff", "Manhunt.SDK/skins/hel_pc.txd");
}


void SetPlayerCameraREC(bool state)
{
    if (state)
    {
        Call< 0x542330 >();
    }
}

DWORD WINAPI MainThread(LPVOID)
{
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
     
    HMODULE hD3D8 = LoadLibraryA("d3d8.dll");
    if (!hD3D8)
        MessageBoxA(nullptr, "[SDK] d3d8.dll não encontrada!", "Manhunt.SDK", MB_OK | MB_ICONINFORMATION);

    CreateDirectoryA("Manhunt.SDK", NULL);
    CreateDirectoryA("Manhunt.SDK/skins", NULL);

    InitHooks();

    Console::Init();
	CDiscord::initDiscord();

    //Sleep(25000);
    //DeleteAllHunters();
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