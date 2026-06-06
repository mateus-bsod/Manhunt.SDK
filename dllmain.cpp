 
#include "framework.h"
#include "./src/game.h"
#include "./src/hooks.h"


void InitConsole()
{
    AllocConsole();

    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);

    SetConsoleTitleA("Manhunt Debug Console");

    typedef void(__stdcall* pdiasodas)(int naosei);
    static pdiasodas mateus_zin =
        (pdiasodas)0x5D7A40;

    typedef void(__stdcall* pdia323sodas)(int naosei);
    static pdia323sodas towowo =
        (pdia323sodas)0x5D7A40;


    /*
    
int KillPlayer()
{
  int result; // eax

  sub_5D7A40(-1);
  sub_431480(flt_7CC558); // flt-> sompra
  result = sub_476BF0(0);
  dword_7C86E8 = 0;
  gDebug_Menu = 0;
  return result;
}
    
    */

    if (Manhunt::PlayerState() == PLAYER_INGAME)
    {
        Manhunt::Visual::GameText("Manhunt Mod Loader: initialized!");
        Manhunt::Visual::GameTextLeft(1, "Manhunt Mod Loader: initialized!");
        Manhunt::ToggleFPS(true);
        Manhunt::ToggleMemInfo(true);
    }
}



DWORD WINAPI MainThread(LPVOID)
{
	InitConsole();
	InitHooks();
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