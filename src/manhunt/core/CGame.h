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
#include "../sdk/FakeRW.h"
#include "CConfigs.h"

extern RpLight* ms_pMenuLight;


class CGame
{
private:
    static DWORD gRenderer;

    typedef int(__cdecl* tOriginalEventHandler)(int a1, int a2);
    static tOriginalEventHandler oEventHandler;
    static SafetyHookInline g_EventHandlerHook;

    typedef void(__thiscall* tHUD_Draw)(int a1);
    static tHUD_Draw oHUD_Draw;
    static SafetyHookInline g_HUD_Draw;
    static void HUD_Draw(int a1);

    typedef int(__thiscall* tLoadingScreen)();
    static tLoadingScreen oLoadingScreen;
    static SafetyHookInline g_LoadingScreen;
    static void CGame::LoadingScreen();


public:
    static void InstallHook();

    static void InitialiseWorld(int missionId);
    static int Draw(int a1);
    static int Game_IsInGame();
    static int Game_IsPaused();
    static int WorldToScreen(DWORD outScreen, float worldX, float worldZ);

    static int Set2DRenderMode(int mode);

    static int __cdecl hkEventHandler(int a1, int a2);

    class GameState
    {
    public:
        static DWORD& GetTextResetFlag();
        static DWORD& GetDebugTextFlag();
        static DWORD& GetCanRenderShadow();
        static DWORD& GetGameStateFlag();
        static DWORD& GetGameFlags();
        static DWORD& GetTimerValue();
    };

    class Player
    {
    public:
        static DWORD& GetPlayerBase();
        static float GetPlayerHealth();
        static DWORD GetCurrentSlot();
    };
    

    class WeaponSlots
    {
    public:
        static DWORD& GetCurrentSlot1();
        static DWORD& GetCurrentSlot2();
        static DWORD& GetCurrentSlot3();
        static DWORD& GetCurrentSlot4();
    };

    class LastWeaponSlots
    {
    public:
        static DWORD& GetLastSlot1();
        static DWORD& GetLastSlot2();
        static DWORD& GetLastSlot3();
        static DWORD& GetLastSlot4();
    };

    class Radar
    {
    public:
        static DWORD& GetState();
        static DWORD& GetSlot();
        static bool IsActive();
    };

    class SwapSystem
    {
    public:
        static DWORD& GetActive();
        static DWORD& GetSlot();
        static DWORD& GetFlag();
        static bool IsSwapActive();
    };

    class WeaponChange
    {
    public:
        static DWORD& GetRequest();
        static DWORD* GetSlots();
        static DWORD& GetResult();
        static DWORD GetSlot(int index);
    };
};