#include "CMainMenu.h"

enum MenuID {
    MENU_LOAD_GAME = 4,
    MENU_OPTIONS = 9,
    MENU_SAVE_GAME = 10,
    MENU_BONUS = 14,
    MENU_NEW_GAME = 17,
    MENU_QUIT = 23
};

int& menuActive = *reinterpret_cast<int*>(0x8221F8);
int& currentSubMenuId = *reinterpret_cast<int*>(0x7D7DCC);
int& menuState = *reinterpret_cast<int*>(0x7C8700);
int& lastSelectedItem = *reinterpret_cast<int*>(0x7C89CC);
int& selectedItemIndex = *reinterpret_cast<int*>(0x7C89CC);
int& selectedOption = *reinterpret_cast<int*>(0x7C8A68);
int& menu_mouse_in_area = *(int*)0x7C8F80;

int& dword_7C89EC = *reinterpret_cast<int*>(0x7C89EC);
int& dword_7C8A6C = *reinterpret_cast<int*>(0x7C8A6C);
int& dword_7C86E8 = *reinterpret_cast<int*>(0x7C86E8);
int& dword_7D6148 = *reinterpret_cast<int*>(0x7D6148);

void*& off_7D614E = *reinterpret_cast<void**>(0x7D614E);
void*& unk_7D6152 = *reinterpret_cast<void**>(0x7D6152);
void*& aUquit_1 = *reinterpret_cast<void**>(0x7D6156);

typedef void (*sub_605030_t)(void*);
sub_605030_t sub_605030 = (sub_605030_t)0x605030;



typedef void* (__cdecl* tPrintCheat)(void* a1, void* a2, void* a3, void* a4);
tPrintCheat oPrintCheat = (tPrintCheat)0x5D5BB0;

SafetyHookInline g_MainMenuHook;
safetyhook::InlineHook hook_selected, hook_normal;

typedef signed int (*tPauseMenuHandler)();
tPauseMenuHandler oPauseMenuHandler = (tPauseMenuHandler)0x601010;
SafetyHookInline g_PauseMenuHandlerHook;

SafetyHookInline g_MainSubMenuHook;

namespace CMainMenu
{
    int& dword_7C89D4 = *reinterpret_cast<int*>(0x7C89D4);
    int& dword_7C89E4 = *reinterpret_cast<int*>(0x7C89E4);

    int sub_606EB0(int* saveList, double a2, int a3)
    {
        return CallAndReturn<int, 0x606EB0>(saveList, a2, a3);
    }


    void* __cdecl hkMainMenu()
    {
        int v0 = *(int*)0x7C8720;
        float v1 = *(float*)0x7C8724;
        float v2 = *(float*)0x7C8728;
        int selected = *(int*)0x7C89D4;


        __try {
            wchar_t* cheatText = CText::GetKey("MAINM");
            CVisual::DrawMenuCameraCounter(cheatText);
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
        }

        int logoTexture = CVisual::LoadTextureTXD(*(int*)0x7C8704, "logo");
        float logoScale = *(float*)0x7D3458 * *(float*)0x7D63FC;
        CVisual::DrawImage(*(float*)0x7D6408, *(float*)0x7D6404, logoScale, *(float*)0x7D6400, 180, 180, 180, 255, logoTexture);

        float x = *(float*)0x7D6410;
        float baseY = *(float*)0x7D640C;
        float step = 0.06f;

        CVisual::DrawMenuItem(CText::GetKey("PLAY"), x, baseY + (step * 0), v0, v1, selected == 0);
        CVisual::DrawMenuItem(CText::GetKey("SELSCE"), x, baseY + (step * 1), v0, v1, selected == 1);
        CVisual::DrawMenuItem(CText::GetKey("LOADG"), x, baseY + (step * 2), v0, v1, selected == 2);
        CVisual::DrawMenuItem(CText::GetKey("SETT"), x, baseY + (step * 3), v0, v1, selected == 3);
        CVisual::DrawMenuItem(CText::GetKey("BONFEA"), x, baseY + (step * 4), v0, v1, selected == 4);
        CVisual::DrawMenuItem(CText::GetKey("BONFEA"), x, baseY + (step * 4), v0, v1, selected == 4);
        CVisual::DrawMenuItem(CText::GetKey("QUITPRG"), x, baseY + (step * 5), v0, v1, selected == 5);

        //CVisual::DrawString(CText::KeyEx("~white~MH::MODLOADER ~yellow~1.0.0b"), x + 0.1f, baseY + (step * 9), v0, v1);


        int cheatFlag = *(int*)0x7C84A8;
        wchar_t* cheatText = (wchar_t*)0x7D6360;

        if (cheatFlag) {
            switch (cheatFlag) {
            case 1: cheatText = CText::GetKey("C_RUN"); break;
            case 2: cheatText = CText::GetKey("C_SILEN"); break;
            case 4: cheatText = CText::GetKey("C_REGEN"); break;
            case 8: cheatText = CText::GetKey("C_HELI"); break;
            case 16: cheatText = CText::GetKey("C_FULEQ"); break;
            case 32: cheatText = CText::GetKey("C_SUPUN"); break;
            case 64: cheatText = CText::GetKey("C_RABBI"); break;
            case 128: cheatText = CText::GetKey("C_MONKE"); break;
            case 256: cheatText = CText::GetKey("C_INVIS"); break;
            case 512: cheatText = CText::GetKey("C_PIGGS"); break;
            case 1024: cheatText = CText::GetKey("C_GOD"); break;
            }
        }

        if (*(int*)0x7C84AC == 1) {
            oPrintCheat(cheatText, (void*)0x7D6360, (void*)0x7D6360, (void*)0x7D6360);
        }


        return (void*)0x7D6360;
    }

    void SetColor(int r, int g, int b, int a) {
        int* c = (int*)0x7D4EC8;
        for (int i = 0; i < 4; i++) {
            c[i * 4] = r; c[i * 4 + 1] = g; c[i * 4 + 2] = b; c[i * 4 + 3] = a;
        }
    }

    void __stdcall SetSelectedMenuItemColor()
    {
        SetColor(255, 0, 0, 255);
    }

    void __stdcall SetNormalMenuItemColor()
    {
        SetColor(255, 255, 255, 255);
    }

    signed int hkPauseMenuHandler()
    {
        CVisual::GameText("hkPauseMenuHandler called");
        return oPauseMenuHandler();
    }

    // Menu de pause
    signed int hkMainSubMenuHandler(void* thisPtr)
    {
        signed int v1 = 0;
        void** v2 = nullptr;
        void** v3 = nullptr;
        void** v4 = nullptr;
        int v5 = 0;

        if (!CMenu::IsMenuLocked())
        {
            if (CInput::IsUpKeyPressed())
            {
                if (!CInput::IsUsingMouse() && selectedOption == 2)
                    --selectedOption;
                if (--selectedOption < 0)
                    selectedOption = 3;
            }
            if (CInput::IsDownKeyPressed())
            {
                if (!CInput::IsUsingMouse() && !selectedOption)
                    ++selectedOption;
                if (++selectedOption > 3)
                    selectedOption = 0;
            }
            if (CInput::IsConfirmKeyPressed())
            {
                selectedOption = CInput::GetSelectedOptionFromMouse();
                if (!CInput::IsUsingMouse() && selectedOption > 0)
                    ++selectedOption;
            }
        }
        if (CInput::IsActionKeyPressed())
        {
            if (!selectedOption)
            {
                CPlayer::SetMenu(10);
                dword_7C89EC = 1;
            }
            if (selectedOption == 1 && dword_7D6148 == 46)
            {
            }
            if (selectedOption == 2)
            {
                CVisual::ShowDialogBox(
                    CText::GetKey("UQUIT?"),
                    CText::GetKey("NO"),
                    CText::GetKey("YES"), 1, 2);
            }
            if (selectedOption == 3)
            {
                v1 = 1;
                if (CPlayer::GetPlayer())
                    CPlayer::GetPlayer()->dwGodModeFlag |= 0x80000000;
            }
        }
        if (!CMenu::IsMenuLocked() && CInput::IsExitKeyPressed())
            v1 = 1;
        if (v1 == 1)
            dword_7C86E8 = 2;
        if (CInput::IsKeyReleased() == 1)
        {
            CInput::ResetMenuState();
            selectedOption = 3;
            dword_7C89EC = 0;
            dword_7C8A6C = 0;
        }

        v5 = (int)CPlayer::GetPlayer();
        if (!dword_7D6148)
        {
        }
        return 1;
    }

    // ----------------------------------------------------------------------------------------------------

    bool sub_5D87F0()
    {
		return CallAndReturn<bool, 0x5D87F0>();
    }
    
    void sub_5DAA20()
    {
        Call<0x5DAA20>();
	}
    
	int sub_5DAA50(int* a1)
    {
        return CallAndReturn<int, 0x5DAA50>(a1);
    }
    
    int sub_5DAD00()
    {
        return CallAndReturn<int, 0x5DAD00>();
	}
    
    void sub_5D6A60()
    {
        Call<0x5D6A60>();
    }
    
	BYTE* sub_5D6720(int saveIndex, int a2)
    {
        return CallAndReturn<BYTE*, 0x5D6720>(saveIndex, a2);
    }

    int sub_5D6900()
    {
        return CallAndReturn<int, 0x5D6900> ();
    }

    int& dword_7C86F0 = *reinterpret_cast<int*>(0x7C86F0);
    int& dword_7C86F4 = *reinterpret_cast<int*>(0x7C86F4);
    int& dword_7D8F58 = *reinterpret_cast<int*>(0x7D8F58);
    int* g_SaveFileList = *reinterpret_cast<int**>(0x7D7DC8);

    SafetyHookInline g_VideoMenuHook;
    SafetyHookInline g_AudioMenuHook;
    SafetyHookInline g_ControlsMenuHook;

    void* __cdecl hkVideoMenu() { return nullptr; }
    void* __cdecl hkAudioMenu() { return nullptr; }
    void* __cdecl hkControlsMenu() { return nullptr; }

    typedef signed int (*tMainMenu_HandleInput)(int*, double);
    tMainMenu_HandleInput original_MainMenu_HandleInput = (tMainMenu_HandleInput)0x600AF0;

    SafetyHookInline g_ModLoaderHook;

    int hkMainMenu_Handler(int* a1, double a2)
    {



        return original_MainMenu_HandleInput(a1, a2);
    }

    void InstallHook()
    {
        g_MainMenuHook = safetyhook::create_inline((void*)0x600C20, (void*)&hkMainMenu);
        hook_selected = safetyhook::create_inline((void*)0x5D7B10, (void*)&SetSelectedMenuItemColor);
        hook_normal = safetyhook::create_inline((void*)0x5D7BC0, (void*)&SetNormalMenuItemColor);

        // MENU HANDLER
        /*
        
            original..

            MainMenu_HandleInput+DA

            ... minha parte

            MainMenu_HandleInput+126

            original..

            -------------------

        0x600AF0 + 0xDA
        ...
        0x600AF0 + 0x126

        
        */
        //g_MainMenuHook = safetyhook::create_inline((void*)0x600AF0, (void*)&hkMainMenu_Handler);
		//original_MainMenu_HandleInput = g_MainMenuHook.original<tMainMenu_HandleInput>();
        
        g_MainSubMenuHook = safetyhook::create_inline((void*)0x5FFB50, (void*)&hkMainSubMenuHandler);
    }
}