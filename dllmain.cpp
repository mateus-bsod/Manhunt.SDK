
#define DEBUG_CONSOLE true

#include "framework.h"


#include "src/manhunt/CPlayer.h"
#include "src/manhunt/CWeapons.h"
#include "src/manhunt/CVisual.h"    

#include "./src/hooks.h"

#include <stdio.h>




void InitConsole()
{
#if DEBUG_CONSOLE 
    AllocConsole();

    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);

    SetConsoleTitleA("Manhunt Debug Console");

    HWND hConsole = GetConsoleWindow();
    ShowWindow(hConsole, SW_MINIMIZE);
#endif
}

typedef void(__cdecl* tDrawString)(wchar_t* text, float x, float y, float scaleX, float scaleY);
tDrawString oDrawString = (tDrawString)0x5D5B30;

DWORD WINAPI MainThread(LPVOID)
{
	InitConsole();
	InitHooks();

 
    typedef void(__thiscall* tOpenSub)(int menu);
    tOpenSub Open_SubMenu = (tOpenSub)0x5D7A40;
    

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

    return TRUE;
}