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
#include "../game/CCheats.h"


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

extern int& CurrentPlayerMenu;

extern DWORD& g_MenuOption;


enum
{
    MENU_LANGUAGE = 1,
    MENU_UNK = 2,
    MENU_DIFICULTY = 3,
    MENU_CARREGAR = 4,
    MENU_LOADGAME = 5,
    MENU_SAVEGAME = 6,
    MENU_UNK2 = 7,
    MENU_PAUSE = 8,
    MENU_SELECIONAR = 9,
    MENU_CONFIG = 10,
    MENU_CONFIG_AUDIO = 11,
    MENU_UNK3 = 12,
    MENU_CONFIG_VIDEO = 12,
    MENU_BONUS = 14,
    MENU_BONUS_CLOWN = 15,
    MENU_SCORE_FINAL = 16,
    MENU_BRILHO = 17,
    MENU_CONFIG_CONTROLS = 18,
    MENU_CONFIG_CONTROLS_RESET = 19,
    MENU_BUG = 20, // BLACK SCREEN
    MENU_CREDITS = 21,
    MENU_MAP_KEYBOARD = 22,
    MENU_SAIR = 23,

    MENU_SKINS = 24
};

class CMainMenu
{
private:
    static void CMainMenu::SetColor(int r, int g, int b, int a);

public:
    static int getSelectionOption();

    static void* __cdecl hkMainMenu();
    static int __cdecl hkMainMenuHandler();
    static signed int hkPauseMenuHandler();
    static signed int hkMainSubMenuHandler(void* thisPtr);
    static void __stdcall SetSelectedMenuItemColor();
    static void __stdcall SetNormalMenuItemColor();
    static void InstallHook();
};