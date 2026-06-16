//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CVisual.h"
#include "../game/CInput.h"
#include "../ui/CText.h"

int& CVisual::selectedDialog = *reinterpret_cast<int*>(0x7C8774);
int& CVisual::InDialogBox = *reinterpret_cast<int*>(0x7C8758);
int& CVisual::VisibleDialog = *reinterpret_cast<int*>(0x7C875C);
int& CVisual::dword_7C8760 = *reinterpret_cast<int*>(0x7C8760);
int& CVisual::dword_7C8764 = *reinterpret_cast<int*>(0x7C8764);
int& CVisual::TitleDialogBox = *reinterpret_cast<int*>(0x7C8768);
int& CVisual::Btn1DialogBox = *reinterpret_cast<int*>(0x7C876C);
int& CVisual::Btn2DialogBox = *reinterpret_cast<int*>(0x7C8770);
int& CVisual::Btn1Pos = *reinterpret_cast<int*>(0x7C8774);
int& CVisual::Btn2Pos = *reinterpret_cast<int*>(0x7C8778);

DialogState g_Dialog = { false, nullptr };

void CVisual::UI_ResetAndInitialize()
{
    Call<0x5DAD20>();
}

int CVisual::UI_UpdateCursor()
{
    return CallAndReturn<int, 0x5F7A50>();
}

int CVisual::UI_Begin()
{
    return CallAndReturn<int, 0x5F5CF0>();
}

int CVisual::UI_Flush()
{
    return CallAndReturn<int, 0x5F5D30>();
}

void CVisual::UI_PlaySound(int soundId, int channel, float volume)
{
    Call<0x5E9B00, int, int, float>(soundId, channel, volume);
}

int CVisual::UI_End(int a1, int a2)
{
    return CallAndReturn<int, 0x5F5C90, int, int>(a1, a2);
}

int CVisual::LoadTextureTXD(int txd, const char* texture)
{
    return CallAndReturn<int, 0x5EA520, int, const char*>(txd, texture);
}

int CVisual::Load_Texture(int txd, const char* texture)
{
    return (int)((int* (__cdecl*)(int, const char*))0x62F660)(txd, texture);
}

void CVisual::DrawImage(float posX, float posY, float scaleX, float scaleY, int red, int green, int blue, int alpha, int pTexture)
{
    Call<0x5F96F0, float, float, float, float, int, int, int, int, int>(posX, posY, scaleX, scaleY, red, green, blue, alpha, pTexture);
}

void CVisual::DrawTextString(const char* text, float x, float y, float scaleX, float scaleY, int a6, int style, int a8)
{
    if (style >= 3)
    {
        Console::Printf("[CVisual::DrawTextString] Crash, style (font) >= 3");
        return;
    }
    Call<0x5E55E0, const char*, float, float, float, float, int, int, int>(text, x, y, scaleX, scaleY, a6, style, a8);
}

void CVisual::DrawMenuString(wchar_t* text, float x, float y, int textScaleX, float textScaleY)
{
    Call<0x5D5B30>(text, x, y, textScaleX, textScaleY);
}

void CVisual::DrawMenuItem(wchar_t* text, float x, float y, int textScaleX, float textScaleY, int selected)
{
    Call<0x5D55C0, wchar_t*, float, float, int, float, int>(text, x, y, textScaleX, textScaleY, selected);
    CVisual::DrawMenuString(text, x, y, textScaleX, textScaleY);
}

void CVisual::DrawColoredQuad(float x, float y, float width, float height, int r, int g, int b, int a, int unknown)
{
    Call<0x5F96F0, float, float, float, float, int, int, int, int, int>(x, y, width, height, r, g, b, a, unknown);
}

int CVisual::GetAspectRatio()
{
    return CallAndReturn<int, 0x5EA2B0>();
}

int CVisual::IsUIActive()
{
    return CallAndReturn<int, 0x5DACB0>();
}

void CVisual::GameText(const char* text)
{
    ((void(__cdecl*)(const char*))0x005E5410)(text);
}

void CVisual::GameTextLeft(int line, const char* text)
{
    if (line < 0 || line > 25) return;
    Call<0x5E5480, int, const char*>(line, text);
}

void CVisual::ShowDialogBox(void* pMessageText, void* pBtn1, void* pBtn2, int pBtn1_Column, int pBtn2_Column)
{
    if (InDialogBox) return;

    InDialogBox = 1;
    VisibleDialog = 1;
    dword_7C8760 = 0;
    dword_7C8764 = 1;
    TitleDialogBox = (int)pMessageText;
    Btn1DialogBox = (int)pBtn1;
    Btn2DialogBox = (int)pBtn2;
    Btn1Pos = pBtn1_Column - 1;
    Btn2Pos = pBtn2_Column - 1;
}

void CVisual::HideDialogBox()
{
    if (!InDialogBox && !VisibleDialog) return;
    InDialogBox = 0;
    VisibleDialog = 0;
    g_Dialog.waiting = false;
}

void CVisual::ShowDialogBoxEx(void* pMessageText, void* pBtn1, void* pBtn2, tDialogCallback callback, int pBtn1_Column, int pBtn2_Column)
{
    if (InDialogBox) return;

    ShowDialogBox(pMessageText, pBtn1, pBtn2, pBtn1_Column, pBtn2_Column);
    g_Dialog.waiting = true;
    g_Dialog.callback = callback;
}

void CVisual::UpdateDialogBox()
{
    if (!g_Dialog.waiting) return;
    if (!CVisual::InDialogBox || !CVisual::VisibleDialog) return;

    int button = (CVisual::selectedDialog == 0) ? 1 : 2;

    if (g_Dialog.callback)
        g_Dialog.callback(button);

    HideDialogBox();
}

void CVisual::DrawMenuCameraCounter(const wchar_t* text)
{
    Call<0x5D5740, const wchar_t*>(text);
}

void CVisual::InstallHook()
{
}