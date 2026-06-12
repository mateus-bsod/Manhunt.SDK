#include "../core/CGame.h"

DWORD gRenderer;

namespace CGame
{
    typedef int (__cdecl* tOriginalEventHandler)(int a1, int a2);
    tOriginalEventHandler oEventHandler = nullptr;
    SafetyHookInline g_EventHandlerHook;

    // --------------------------------------------------------------------------

    void InitialiseWorld(int missionId)
    {
        Call<0x474330, int>(missionId);
    }

    // --------------------------------------------------------------------

    typedef int (*tDraw)(int a1);
    tDraw oDraw = nullptr;
    SafetyHookInline g_Draw;



    // 4. Chamar


    int Draw(int a1)
    {
        __try
        {

        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            printf("[CGame::Draw] Exception occurred during draw call.\n");
            return 0;
        }
        /*
        // Stack allocation (1BAC bytes)
        char stackBuffer[0x1BAC];

        // Begin render frame
        RenderFrame_Begin();

        // Skip if no debug mode
        if (!dword_7CF080) {
            return;
        }

        RenderFrame_End(0);

        // Draw FPS counter
        if (dword_7CF2D0 || dword_7D2E28) {
            if (dword_7D2E28) {
                nullsub_42(&dword_799B50);
                dword_7CF2CC ^= 1;
            }

            if (dword_7CF2D0 == 1) {
                if (dword_7CF2CC == 0) {
                    dword_7CF260 = 1;
                    dword_7CF264 = 0xFF;
                    dword_7CF268 = 0;
                }
                else {
                    dword_7CF260 = 1;
                    dword_7CF264 = 0;
                    dword_7CF268 = 0xFF;
                }
                dword_7CF26C = 0;
            }
            dword_7CF2D0 = 1;
        }

        // Draw FPS string
        if (fps_info) {
            float fpsValue = *(float*)0x7D34A0;
            char fpsText[256];
            sprintf(fpsText, "%.0f", fpsValue);

            // Draw FPS text
            Text_DrawFormatted(stackBuffer, 0x3EF9DB23, 0x3F666666, 0x3F333333, 0x3F333333, 1);
        }

        // Draw shadow cameras info
        if (dword_7CF2C0) {
            int shadowCount = dword_7CF2C4;
            char shadowText[256];
            sprintf(shadowText, "%d shadow cameras active", shadowCount);
            Text_DrawFormatted(stackBuffer, 0x3F1C28F6, 0x3F23D70A, 0x3F333333, 0x3F333333, 1);
            dword_7CF2C4 = 0;
        }

        // Draw timing bars
        if (dword_7CF4B8 && !fps_info) {
            for (int i = 0; i < 3; i++) {
                float timingValue = *(float*)(0x7CF4D4 + i * 4);
                char timingText[256];
                sprintf(timingText, "(%d : %.3f ms)", i, timingValue);

                float x = i * 0.05f;
                Text_DrawFormatted(stackBuffer, 0x3CA3D70A, 0x3D23D70A, 0x3F333333, 0x3F333333, 1);
            }
        }

        // Draw screen effects
        if (dword_7CF098) {
            float effect = *(float*)0x7D5234;
            // ... effect processing ...

            // Draw damage indicator
            if (CPlayer) {
                int health = *(int*)(CPlayer + 0x7C);
                int currentHealth = *(int*)(health + 0x88);
                // Draw health text
            }

            // Draw weapon info
            Text_DrawFormatted(stackBuffer, 0x3CA3D70A, 0x3D75C28F, 0x3F333333, 0x3F333333, 1);
        }

        // Draw crosshair
        if (dword_7CF0A0) {
            // Draw crosshair based on scope
            if (dword_7D37BC) {
                Draw_ColoredQuad(0.5f, 0.5f, 0.1f, 0.1f, 255, 255, 255, 255);
            }
        }

        // Draw player info (health/armor)
        DrawPlayerInfo();

        // Draw health bar
        DrawHealthBar();

        // Draw weapons
        DrawWeapons();

        // Update world and camera
        World_Update();
        Camera_Update();
        Physics_Update();

        // Draw tooltips
        if (dword_7CF0B8) {
            UI_DrawTooltip();
        }

        // Draw progress bars
        UI_DrawProgressBars();

        // Draw debug menu if enabled
        if (gDebug_Menu) {
            DrawDebugMenu();
        }

        // Night vision effect
        if (dword_7CF0E0 && Player_State != 2) {
            Draw_ColoredQuad(0, 0, 1, 1, 0, 0, 0, 255);
        }

        // End frame
        RenderFrame_End(1);

        // Update timer
        int delta = Timer_GetDelta();
        */
        return oDraw(a1);
    }




    // --------------------------------------------------------------------------

	// hkEventHandler é chamado apenas quando está no menu ou cutscenes.
    int& dword_7D3460 = *reinterpret_cast<int*>(0x7D3460);
    int& dword_7D4E90 = *reinterpret_cast<int*>(0x7D4E90);
    int& dword_82279C = *reinterpret_cast<int*>(0x82279C);

    __declspec(naked) void nullsub_71()
    {
        __asm retn
    }

    /*
    int __cdecl sub_6260E0(int a1)
    {
        int result;

        __asm
        {
            mov ecx, a1
            mov eax, [esp + ecx]
            call dword ptr[eax + 18h]
            mov result, eax
        }

        return result;
    }
    */

    void __declspec(noreturn) sub_6260E0(int a1)
    {
        __asm
        {
            mov eax, a1
            jmp dword ptr[eax + 0x18]
        }
    }

    int __cdecl sub_6260D0(int a1)
    {
        return (*(int (**)(void))(a1 + 28))();
    }

    int __cdecl hkEventHandler(int a1, int a2) // a2 - parece ser o state
    {   
		int ret = oEventHandler(a1, a2);
        
        // in game
        if (a2)
        {
            Player_State = 2;
        }

        // no menu
        else if (Player_State != 1)
        {
            Player_State = 0;
        }
        
        /*
        int result = 0; // eax

        printf("1..\n");
        

        printf("2..\n");
        dword_7D3460 = a1;
        if (dword_7D4E90)
            return result;
        
        printf("3..\n");
        if (!a2) sub_6260E0(a1);

        printf("4..\n");
        ((void(__cdecl*)(signed int, DWORD))(dword_82279C + 32))(1, 0);
        printf("5..\n");
        result = Draw(a1);

        printf("6..\n");
        if (!a2)
            result = sub_6260D0(a1);
        //if (!a2) result = nullsub_71(a1);
        */
        printf("[CGame::EventHandler] Event: %d, State: %d\n", a1, a2);
        return ret;
    }

    //

    void InstallHook()
    {
        // ------------------------------------------------------

        //g_Draw = safetyhook::create_inline((void*)0x5EF990, (void*)&CGame__Draw);
        //oDraw = g_Draw.original<tDraw>();

        // ------------------------------------------------------

        while (true)
        {
            DWORD p = *(DWORD*)0x82279C;
            if (!p)
            {
                printf("\r[CGame::InstallHook] Waiting for renderer...\n");
                Sleep(1000);
                continue;
            }

            gRenderer = *(DWORD*)p;
            if (gRenderer) break;
        }

        printf("[CGame::InstallHook] Renderer = [ 0x%08X ]\n", gRenderer);
   

        //g_EventHandlerHook = safetyhook::create_inline((void*)0x5EF900, (void*)&hkEventHandler);
        //oEventHandler = g_EventHandlerHook.original<tOriginalEventHandler>();
    }

    void UinstallHook()
    {
    }
}