//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#pragma once

#include "../../../framework.h"
#include "../ui/CMainMenu.h"
#include "../../game.sdk.h"

typedef void (*tDialogCallback)(int button);

struct DialogState
{
    bool waiting;
    tDialogCallback callback;
};

extern DialogState g_Dialog;

class CVisual
{
public:
    static int& selectedDialog;
    static int& InDialogBox;
    static int& VisibleDialog;
    static int& dword_7C8760;
    static int& dword_7C8764;
    static int& TitleDialogBox;
    static int& Btn1DialogBox;
    static int& Btn2DialogBox;
    static int& Btn1Pos;
    static int& Btn2Pos;

    static void GameText(const char* text);
    static void GameTextLeft(int line, const char* text);
    static int GetAspectRatio();
    static int IsUIActive();
    static void DrawTextString(const char* text, float x, float y, float scaleX, float scaleY, int a6, int style, int a8);
    static void Text_Render(int slot, const char* text, float x, float y, int font, int color, int shadow, int naosei);
    static void ShowDialogBox(void* pMessageText, void* pBtn1, void* pBtn2, int pBtn1_Column = 1, int pBtn2_Column = 2);
    static void HideDialogBox();
    static void ShowDialogBoxEx(void* pMessageText, void* pBtn1, void* pBtn2, tDialogCallback callback, int pBtn1_Column = 1, int pBtn2_Column = 2);
    static void UpdateDialogBox();
    static int LoadTextureTXD(int txd, const char* texture);
    static int Load_Texture(int txd, const char* texture);
    static void UI_ResetAndInitialize();
    static double UI_DrawTooltip(float x, float y, float width, float height, int textureId, float opacity, int color, float scale);
    static int UI_UpdateCursor();
    static int UI_Begin();
    static int UI_Flush();
    static __int16 UI_ShowMessage(int messageIndex, __int16 flags);
    static void UI_PlaySound(int soundId, int channel, float volume);
    static int UI_IsVisible(int panelId);
    static int UI_End(int a1, int a2);
    static void DrawMenuString(wchar_t* text, float x, float y, int textScaleX, float textScaleY);
    static void DrawImage(float posX, float posY, float scaleX, float scaleY, int red, int green, int blue, int alpha, int pTexture);
    static void DrawMenuItem(wchar_t* text, float x, float y, int textScaleX, float textScaleY, int selected);
    static void DrawMenuCameraCounter(const wchar_t* text);
    static void DrawColoredQuad(float x, float y, float width, float height, int r, int g, int b, int a, int unknown);
    static void InstallHook();
};