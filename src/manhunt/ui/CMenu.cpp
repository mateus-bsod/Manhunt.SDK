//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CMenu.h"
#include "../game/CInput.h"
#include "../ui/CVisual.h"
#include "../ui/CText.h"
#include "../entity/CPlayer.h"

tPauseMenuControl oPauseMenuControl = nullptr;
tDrawText oDrawText = nullptr;
SafetyHookInline g_PauseMenuHook;
SafetyHookInline g_DrawTextHook;

int currentSelection = 0;
bool customMenuActive = false;

signed int __fastcall hkPauseMenuControl(void* pThis, void* _)
{
    return oPauseMenuControl(pThis);
}

void __fastcall hkDrawText(void* text1, void* text2, void* text3, int a, int b)
{
    oDrawText(text1, text2, text3, a, b);
}

int CMenu::IsMenuLocked()
{
    int& dword_7C8758 = *reinterpret_cast<int*>(0x7C8758);
    return dword_7C8758;
}

void CMenu::InstallHook()
{
    /*
    oPauseMenuControl = (tPauseMenuControl)PAUSE_MENU_ADDR;
    g_PauseMenuHook = safetyhook::create_inline(
        (void*)PAUSE_MENU_ADDR,
        (void*)CMenu::hkPauseMenuControl
    );
    oPauseMenuControl = g_PauseMenuHook.original<tPauseMenuControl>();
    */
}