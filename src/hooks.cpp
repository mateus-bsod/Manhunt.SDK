
#include "../framework.h"

#include "manhunt/CPhysics.h"
#include "manhunt/CCollectable.h"
#include "manhunt/CInventory.h"
#include "manhunt/CWeapons.h"
#include "manhunt/CPlayer.h"
#include "manhunt/CInventory.h"
#include "manhunt/CMenu.h"
#include "manhunt/CMainMenu.h"


typedef void(__cdecl* tPrint)(void* logger, const char* text);

tPrint oPrint = nullptr;
SafetyHookInline g_PrintHook;

void __cdecl hkPrint(void* logger, const char* text)
{
    if (text)
    {
        if (strcmp(text, "OK") == 0)
        {
			printf("[GAME] Manhunt Mod Loader: OK!\n");
            return;
        }
        printf("[GAME] %s\n", text);
    }

    oPrint(logger, text);
}




void InitHooks()
{
    g_PrintHook = safetyhook::create_inline(
        reinterpret_cast<void*>(0x0060F110),
        reinterpret_cast<void*>(&hkPrint)
    );

    oPrint = g_PrintHook.original<tPrint>();

    //

    CCollectable::InstallHook();
    CWeapon::InstallHook();
    CPlayer::InstallHook();
    CPhysics::InstallHook();
    CInventory::InstallHook();
    CMenu::InstallHook();
    CMainMenu::InstallHook();
}
