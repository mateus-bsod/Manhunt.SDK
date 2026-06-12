
#define DEBUG_CONSOLE true

#include "framework.h"
#include "./src/game.sdk.h"

#include "src/manhunt/entity/CPlayer.h"
#include "src/manhunt/ui/CText.h"
#include "src/manhunt/ui/CMainMenu.h"
#include "src/manhunt/gameplay/CWeapons.h"
#include "src/manhunt/ui/CVisual.h"    
#include "src/manhunt/core/CGame.h"    
#include "src/manhunt/game/CInput.h"    
#include "src/manhunt/entity/CEntity.h"    

#include "./src/hooks.h"

#include <stdio.h>




void InitConsole()
{
    AllocConsole();

    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);

    SetConsoleTitleA("Manhunt Debug Console");

#if DEBUG_CONSOLE == false
    HWND hConsole = GetConsoleWindow();
    ShowWindow(hConsole, SW_HIDE);
#else
    HWND hConsole = GetConsoleWindow();

    RECT desktop;
    GetWindowRect(GetDesktopWindow(), &desktop);

    int consoleWidth = 600;
    int consoleHeight = 400;

    SetWindowPos(hConsole, NULL,
        desktop.right - consoleWidth, 
        desktop.bottom - consoleHeight,
        consoleWidth, consoleHeight, SWP_NOZORDER);

    ShowWindow(hConsole, SW_SHOW);
#endif
}


DWORD WINAPI KillAllHunters(LPVOID) {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);


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



            if (GetAsyncKeyState(VK_DELETE) & 1)
            {
                __try
                {
                    if (gRenderer || CPlayer::GetPlayerState() == PLAYER_INGAME)
                    {
                        sprintf(buffer, "Pos: %.2f %.2f %.2f", pos->x, pos->y, pos->z);
						CVisual::DrawTextString(buffer, 0.58f, startY + lineHeight * 0, 0.70f, 0.70f, 0, 0, 0);

                        sprintf(buffer, "Rot: %.2f %.2f %.2f", rot->x, rot->y, rot->z);
                        CVisual::DrawTextString(buffer, 0.58f, startY + lineHeight * 1, 0.70f, 0.70f, 0, 0, 0);

                        sprintf(buffer, "Bound Max: %.2f %.2f %.2f", boundmax->x, boundmax->y, boundmax->z);
                        CVisual::DrawTextString(buffer, 0.58f, startY + lineHeight * 2, 0.70f, 0.70f, 0, 0, 0);

                        sprintf(buffer, "Bound Min: %.2f %.2f %.2f", boundmin->x, boundmin->y, boundmin->z);
                        CVisual::DrawTextString(buffer, 0.58f, startY + lineHeight * 3, 0.70f, 0.70f, 0, 0, 0);
                    }
                }
                __except (MyExceptionFilter(GetExceptionInformation()))
                {
                    printf("Exception: %08X\n", GetExceptionCode());
                }
            }


            // Posição
            //CVisual::DrawString(CText::KeyEx(buffer), 0.58f, startY, 0.70f, 0.70f);

            /*
            // Rotação
            CVisual::DrawString(CText::KeyEx(buffer), 0.58f, startY + lineHeight, 0.70f, 0.70f);

            // Bounding Box Max
            CVisual::DrawString(CText::KeyEx(buffer), 0.58f, startY + lineHeight * 2, 0.70f, 0.70f);

            // Bounding Box Min
            CVisual::DrawString(CText::KeyEx(buffer), 0.58f, startY + lineHeight * 3, 0.70f, 0.70f);
            */


        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            continue;
        }
        Sleep(80);
    }
    return 1;
}


DWORD WINAPI MainThread(LPVOID)
{
    InitConsole();
    InitHooks();

    
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