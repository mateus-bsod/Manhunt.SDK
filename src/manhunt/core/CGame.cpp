//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CGame.h"
#include "../core/CMath.h"
#include "../entity/CEntity.h"
#include "../gameplay/CWeapons.h"
#include "../gameplay/CInventory.h"
#include "../core/CResourceManager.h"

DWORD CGame::gRenderer = 0;

CGame::tOriginalEventHandler CGame::oEventHandler = nullptr;
SafetyHookInline CGame::g_EventHandlerHook;

CGame::tHUD_Draw CGame::oHUD_Draw = nullptr;
SafetyHookInline CGame::g_HUD_Draw;

CGame::tLoadingScreen CGame::oLoadingScreen = nullptr;
SafetyHookInline CGame::g_LoadingScreen;

int CGame::Game_IsInGame()
{
    return CallAndReturn<int, 0x5EA4E0>();
}

int CGame::Game_IsPaused()
{
    return CallAndReturn<int, 0x5EA2C0>();
}

int CGame::WorldToScreen(DWORD outScreen, float worldX, float worldZ)
{
    return CallAndReturn<int, 0x5DFEA0, DWORD, float, float>(outScreen, worldX, worldZ);
}

void CGame::InitialiseWorld(int missionId)
{
    Call<0x474330, int>(missionId);
}

int __cdecl CGame::hkEventHandler(int a1, int a2)
{
    __try
    {
        int ret = oEventHandler(a1, a2);
        if (a2)
            CPlayer::Player_State = 2;
        else if (CPlayer::Player_State != 1)
            CPlayer::Player_State = 0;
        return ret;
    }
    __except (EXCEPTION_SDK)
    {
        Console::Printf("[CGame::hkEventHandler] Exception caught!");
        return 0;
    }
}


void CGame::HUD_Draw(int a1)
{
    Console::Draw();
    
	CPlayer* player = CPlayer::GetPlayer();

    return CGame::oHUD_Draw(a1);
}


void CGame::LoadingScreen()
{
    oLoadingScreen();
}

void CGame::InstallHook()
{
    while (true)
    {
        DWORD p = *(DWORD*)0x82279C;
        if (!p)
        {
            Console::Printf("[CGame::InstallHook] Waiting for renderer...");
            Sleep(1000);
            continue;
        }
        gRenderer = *(DWORD*)p;
        if (gRenderer) break;
    }

    Console::Printf("[CGame::InstallHook] Renderer = [ 0x%08X ]", gRenderer);

    g_HUD_Draw = safetyhook::create_inline((void*)0x5DE320, (void*)&CGame::HUD_Draw);
    oHUD_Draw = g_HUD_Draw.original<tHUD_Draw>();

    //
    //      CARREGAR CONFIGS
    //

    //
    //      LOADING SCREEN - Da missão
    //

    PATCH(0x5EEAD0 + 0x260, 0x90, 5);
    //PATCH(0x5EEAD0 + 0x33C, 0x90, 5); // Nome da missao
    PATCH(0x5EEAD0 + 0x426, 0x90, 5);
    PATCH(0x5EEAD0 + 0x501, 0x90, 5);


    //SendMessage(g_hVideoDialog, WM_COMMAND, MAKEWPARAM(1, 0), 0);


    g_LoadingScreen = safetyhook::create_inline((void*)0x5EEAD0, (void*)&CGame::LoadingScreen);
	oLoadingScreen = g_LoadingScreen.original<tLoadingScreen>();
}
