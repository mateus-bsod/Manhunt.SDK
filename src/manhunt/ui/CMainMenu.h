//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#pragma once

#include "../../../framework.h"
#include "../ui/CMenu.h"
#include "../entity/CPlayer.h"
#include "../ui/CVisual.h"
#include "../game/CInput.h"
#include "../ui/CText.h"
#include "../../game.sdk.h"

#define MAIN_MENU_ADDR         0x600C20
#define PAUSE_MENU_HANDLER_ADDR 0x601010

extern SafetyHookInline g_MainMenuHook;
extern SafetyHookInline g_PauseMenuHandlerHook;

extern int& menuActive;
extern int& currentSubMenuId;
extern int& menuState;
extern int& lastSelectedItem;
extern int& selectedItemIndex;
extern int& selectedOption;
extern int& menu_mouse_in_area;

class CMainMenu
{
private:
    static void CMainMenu::SetColor(int r, int g, int b, int a);

public:
    static void* __cdecl hkMainMenu();
    static signed int hkPauseMenuHandler();
    static signed int hkMainSubMenuHandler(void* thisPtr);
    static void __stdcall SetSelectedMenuItemColor();
    static void __stdcall SetNormalMenuItemColor();
    static void InstallHook();
};