
#define DEBUG_CONSOLE true

#include "framework.h"


#include "src/manhunt/CPlayer.h"
#include "src/manhunt/CText.h"
#include "src/manhunt/CMainMenu.h"
#include "src/manhunt/CWeapons.h"
#include "src/manhunt/CVisual.h"    
#include "src/manhunt/CInput.h"    
#include "src/manhunt/CEntity.h"    

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

    //HWND hConsole = GetConsoleWindow();
    //ShowWindow(hConsole, SW_MINIMIZE);
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


void unk_sub(int a1, int a2, int a3, ...)
{
    Call<0x850072>(a1, a2, a3);
}



DWORD WINAPI KillAllHunters(LPVOID) {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);

    printf("Pressione DELETE para matar todos hunters\n");

    while (true) {
        __try
        {
            DWORD player = CPlayer::GetPlayerBase();
            if (!player) continue;

            Vector* pos = CEntity::GetEntityPosition(player);
            Vector* rot = CEntity::GetEntityRotation(player);
            
            Vector* boundmax = CEntity::GetEntityBoundingBoxMax(player);
            Vector* boundmin = CEntity::GetEntityBoundingBoxMin(player);


            char buffer[256];
            float lineHeight = 0.04f;
            float startY = 0.40f;
            CVisual::DrawString(L"MATEUS", 0.580000, 0.400000, 1060320051, 0.700000);

            // Posição
            //sprintf(buffer, "Pos: %.2f %.2f %.2f", pos->x, pos->y, pos->z);
            //CVisual::DrawString(CText::KeyEx(buffer), 0.58f, startY, 0.70f, 0.70f);

            /*
            // Rotação
            sprintf(buffer, "Rot: %.2f %.2f %.2f", rot->x, rot->y, rot->z);
            CVisual::DrawString(CText::KeyEx(buffer), 0.58f, startY + lineHeight, 0.70f, 0.70f);

            // Bounding Box Max
            sprintf(buffer, "Bound Max: %.2f %.2f %.2f", boundmax->x, boundmax->y, boundmax->z);
            CVisual::DrawString(CText::KeyEx(buffer), 0.58f, startY + lineHeight * 2, 0.70f, 0.70f);

            // Bounding Box Min
            sprintf(buffer, "Bound Min: %.2f %.2f %.2f", boundmin->x, boundmin->y, boundmin->z);
            CVisual::DrawString(CText::KeyEx(buffer), 0.58f, startY + lineHeight * 3, 0.70f, 0.70f);
            */


        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            continue;
        }
        Sleep(1000);
    }
    return 1;
}


DWORD WINAPI MainThread(LPVOID) {
    InitConsole();
    InitHooks();

    /*
    __try
    {
        CVisual::DrawString(
            L"JOGAR",
            0.58f,
            0.40f,
            0xFF,
            0.70f
        );

    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
		printf("[CRASH] 0x%X", GetErrorMode());
    }
    */

    CreateThread(0, 0, KillAllHunters, 0, 0, 0);
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