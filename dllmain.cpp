
#define DEBUG_CONSOLE true

#include "framework.h"


#include "src/manhunt/CPlayer.h"
#include "src/manhunt/CText.h"
#include "src/manhunt/CMainMenu.h"
#include "src/manhunt/CWeapons.h"
#include "src/manhunt/CVisual.h"    
#include "src/manhunt/CInput.h"    

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

typedef void(__thiscall* ttttasmdinasd)(void* text, float x, float y, int alignX, int alignY, int color, int flag);
ttttasmdinasd sub_5E5980 = (ttttasmdinasd)0x5E5980;

void MeuCallback(int button)
{
    if (button == 1)
        CVisual::GameText("Nao");
    else
        CVisual::GameText("Obvio que nao!");
}


DWORD WINAPI MainThread(LPVOID)
{
	InitConsole();
	InitHooks();


    CVisual::ShowDialogBoxEx(
        CText::KeyEx("Você tem certeza?"),
        CText::KeyEx("Não"),
        CText::KeyEx("Obvio que nao"),
        MeuCallback
    );




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