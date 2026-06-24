//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CMainMenu.h"

int& menuActive = *reinterpret_cast<int*>(0x8221F8);
int& currentSubMenuId = *reinterpret_cast<int*>(0x7D7DCC);
int& menuState = *reinterpret_cast<int*>(0x7C8700);
int& lastSelectedItem = *reinterpret_cast<int*>(0x7C89CC);
int& selectedItemIndex = *reinterpret_cast<int*>(0x7C89CC);
int& selectedOption = *reinterpret_cast<int*>(0x7C8A68);
int& menu_mouse_in_area = *(int*)0x7C8F80;

int& CurrentPlayerMenu = *reinterpret_cast<int*>(0x7C86F8);

int& dword_7C89EC = *reinterpret_cast<int*>(0x7C89EC);
int& dword_7C8A6C = *reinterpret_cast<int*>(0x7C8A6C);
int& dword_7C86E8 = *reinterpret_cast<int*>(0x7C86E8);
int& dword_7D6148 = *reinterpret_cast<int*>(0x7D6148);


int& dword_7C86F0 = *reinterpret_cast<int*>(0x7C86F0);
int& dword_7C86F4 = *reinterpret_cast<int*>(0x7C86F4);
int& dword_7D8F58 = *reinterpret_cast<int*>(0x7D8F58);
int* dword_7D7DC8 = *reinterpret_cast<int**>(0x7D7DC8);


void*& off_7D614E = *reinterpret_cast<void**>(0x7D614E);
void*& unk_7D6152 = *reinterpret_cast<void**>(0x7D6152);
void*& aUquit_1 = *reinterpret_cast<void**>(0x7D6156);

typedef void (*sub_605030_t)(void*);
sub_605030_t sub_605030 = (sub_605030_t)0x605030;


typedef signed int (*tMainMenuHandler)();
tMainMenuHandler original_MainMenuHandler = (tMainMenuHandler)0x600B34;
SafetyHookInline g_MainHandlerMenuHook;

SafetyHookInline g_MainMenuHook;
safetyhook::InlineHook hook_selected, hook_normal;

typedef signed int (*tPauseMenuHandler)();
tPauseMenuHandler oPauseMenuHandler = (tPauseMenuHandler)0x601010;
SafetyHookInline g_PauseMenuHandlerHook;

SafetyHookInline g_MainSubMenuHook;

SafetyHookMid g_MenuProcesHook;


DWORD& g_MenuOption = *reinterpret_cast<DWORD*>(0x7C89D4);
int& dword_7C89E4 = *reinterpret_cast<int*>(0x7C89E4);



int sub_606EB0(int* this_, int a2)
{
    return CallAndReturn<int, 0x606EB0, int*, int>(this_, a2);
}

bool sub_5D87F0()
{
    return CallAndReturn<bool, 0x5D87F0>();
}

void sub_5DAA20()
{
    Call<0x5DAA20>();
}

int sub_5DAA50()
{
    return CallAndReturn<int, 0x5DAA50>();
}

int CMainMenu::getSelectionOption()
{
    return CallAndReturn<int, 0x5DAD00>();
}

void sub_5D6A60()
{
    Call<0x5D6A60>();
}

BYTE* sub_5D6720(int saveIndex, int a2)
{
    return CallAndReturn<BYTE*, 0x5D6720, int, int>(saveIndex, a2);
}

int ExistsSaveGame()
{
    return CallAndReturn<int, 0x5D6900>();
}

#include "../core/script/CSkinSelector.h"

DWORD g_MaxMenuOptions = 0;

void* __cdecl CMainMenu::hkMainMenu()
{
    
    // ------------------------------------------------------------------

    int v0 = *(int*)0x7C8720;
    float v1 = *(float*)0x7C8724;
    float v2 = *(float*)0x7C8728;
    int selected = *(int*)0x7C89D4;

    CVisual::DrawMenuCameraCounter(L"~star~ MANHUNT.SDK ~star~");

    int logoTexture = CVisual::LoadTextureTXD(*(int*)0x7C8704, "logo");
    float logoScale = *(float*)0x7D3458 * *(float*)0x7D63FC;
    CVisual::DrawColoredQuad(*(float*)0x7D6408, *(float*)0x7D6404, logoScale, *(float*)0x7D6400, 180, 180, 180, 255, logoTexture);

    float x = *(float*)0x7D6410;
    float baseY = *(float*)0x7D640C;
    float step = 0.06f;


    CVisual::DrawMenuItem(CText::GetKey("PLAY"), x, baseY + (step * 0), v0, v1, selected == 0);
    CVisual::DrawMenuItem(CText::GetKey("SELSCE"), x, baseY + (step * 1), v0, v1, selected == 1);
    CVisual::DrawMenuItem(CText::GetKey("LOADG"), x, baseY + (step * 2), v0, v1, selected == 2);
    CVisual::DrawMenuItem(CText::GetKey("SETT"), x, baseY + (step * 3), v0, v1, selected == 3);
    CVisual::DrawMenuItem(CText::GetKey("BONFEA"), x, baseY + (step * 4), v0, v1, selected == 4);
    CVisual::DrawMenuItem(CText::GetKey("QUITPRG"), x, baseY + (step * 5), v0, v1, selected == 5);
    CVisual::DrawMenuItem(L"SKINS", x, baseY + (step * 7), v0, v1, selected == 6);

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
        CVisual::DrawMenuInfo(cheatText, (wchar_t*)0x7D6360, (wchar_t*)0x7D6360, (wchar_t*)0x7D6360);
    }

    return (void*)0x7D6360;
}

void PlayLevel(int level, int unk)
{
    Call<0x5D6720, int, int>(level, unk);
}

int __cdecl CMainMenu::hkMainMenuHandler()
{
    int ret = original_MainMenuHandler();
    int v1; // eax

    if (!sub_5D87F0())
        return 1;

    dword_7C89EC = 0;

    if (!dword_7D8F58)
        sub_606EB0(dword_7D7DC8, 1);

    sub_5DAA20();
    sub_5DAA50();

    if (CInput::IsUpKeyPressed())
    {
        if (--g_MenuOption < 0)
            g_MenuOption = (g_MaxMenuOptions-1);
    }
    if (CInput::IsDownKeyPressed())
    {
        if (++g_MenuOption >= g_MaxMenuOptions)
            g_MenuOption = 0;
    }
    if (CInput::GetSelectedOptionFromMouse())
        g_MenuOption = CMainMenu::getSelectionOption();
    if (CInput::IsExitKeyPressed())
        CPlayer::SetMenu(MENU_SAIR);
    if (!CInput::IsActionKeyPressed())
        return 1;

    if (!g_MenuOption) // play
    {
        v1 = ExistsSaveGame();
        if (v1 == -1)
        {
            sub_5D6A60();
            dword_7C86F0 = 1;
            dword_7C86F4 = 0;
            CPlayer::SetMenu(MENU_BRILHO);
        }
        else
        {
            PlayLevel(v1, 1);
        }
    }
    if (g_MenuOption == 1)  // SELECIONAR
    {
        dword_7C89E4 = 7;
        CPlayer::SetMenu(MENU_SELECIONAR);
    }
    if (g_MenuOption == 2) // CARREGAR
    {
        CPlayer::SetMenu(MENU_CARREGAR);
    }
    if (g_MenuOption == 3) // CONFIG
    {
        CPlayer::SetMenu(MENU_CONFIG);
    }
    if (g_MenuOption == 4) // BONUS
    {
        CPlayer::SetMenu(MENU_BONUS);
    }
    if (g_MenuOption == 5) // SAIR
    {
        CPlayer::SetMenu(MENU_SAIR);
    }
    if (g_MenuOption == 6)
    {
        CPlayer::SetMenu(MENU_SKINS);
    }
    return ret;
}


void CMainMenu::SetColor(int r, int g, int b, int a)
{
    int* c = (int*)0x7D4EC8;
    for (int i = 0; i < 4; i++) {
        c[i * 4] = r;
        c[i * 4 + 1] = g;
        c[i * 4 + 2] = b;
        c[i * 4 + 3] = a;
    }
}

void __stdcall CMainMenu::SetSelectedMenuItemColor()
{
    SetColor(255, 0, 0, 255);
}

void __stdcall CMainMenu::SetNormalMenuItemColor()
{
    SetColor(255, 255, 255, 255);
}

signed int CMainMenu::hkPauseMenuHandler()
{
    CVisual::GameText("hkPauseMenuHandler called");
    return oPauseMenuHandler();
}

signed int CMainMenu::hkMainSubMenuHandler(void* thisPtr)
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


SafetyHookInline g_VideoMenuHook;
SafetyHookInline g_AudioMenuHook;
SafetyHookInline g_ControlsMenuHook;

void* __cdecl hkVideoMenu() { return nullptr; }
void* __cdecl hkAudioMenu() { return nullptr; }
void* __cdecl hkControlsMenu() { return nullptr; }


SafetyHookInline g_ModLoaderHook;

void HookExecuteMenuProcess(SafetyHookContext& ctx)
{
	if (CurrentPlayerMenu == MENU_SKINS) // SKINS
	{
        CSkinSelector::SkinSelectorMenu();
        CSkinSelector::SkinSelectorMenuHandler();
    }
}

void CMainMenu::InstallHook()
{
    // configs
    g_MaxMenuOptions = 7;

    CSkinSelector::Initialise();

    // hooks
    g_MainMenuHook = safetyhook::create_inline((void*)0x600C20, (void*)&CMainMenu::hkMainMenu);
    
    // MENUS
    PATCH(0x600BCB, 0x90, 0x4B); // seleção de menu
    PATCH(0x600B25, 0x90, 0x65); // navegação de menu
    
    g_MenuProcesHook = safetyhook::create_mid(
        (void*)0x5D75D7,
        HookExecuteMenuProcess
    );

    g_MainHandlerMenuHook = safetyhook::create_inline((void*)0x600AF0, (void*)&CMainMenu::hkMainMenuHandler);
    original_MainMenuHandler = g_MainHandlerMenuHook.original<tMainMenuHandler>();

    // SELEÇÃO
    hook_selected = safetyhook::create_inline((void*)0x5D7B10, (void*)&CMainMenu::SetSelectedMenuItemColor);
    hook_normal = safetyhook::create_inline((void*)0x5D7BC0, (void*)&CMainMenu::SetNormalMenuItemColor);

    g_MainSubMenuHook = safetyhook::create_inline((void*)0x5FFB50, (void*)&CMainMenu::hkMainSubMenuHandler);
}