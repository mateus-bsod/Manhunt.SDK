#pragma once

#include "../../framework.h"

#include "CMenu.h"
#include "CPlayer.h"
#include "CVisual.h"
#include "CInput.h"
#include "CText.h"

#include "../game.sdk.h"

//#include <windows.h>
//#include <stdio.h>

#define MAIN_MENU_ADDR         0x600C20
#define PAUSE_MENU_HANDLER_ADDR 0x601010

extern SafetyHookInline g_MainMenuHook;
extern SafetyHookInline g_PauseMenuHandlerHook;

namespace CMainMenu
{
	void* __cdecl hkMainMenu();
	signed int hkPauseMenuHandler();
	signed int hkMainSubMenuHandler(void* thisPtr);
	void InstallHook();
};