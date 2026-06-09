// CVisual.h
#pragma once

#include "../../framework.h"
#include "../game.sdk.h"

extern int& selectedDialog;
extern int& InDialogBox;
extern int& VisibleDialog;
extern int& dword_7C8760;
extern int& dword_7C8764;
extern int& TitleDialogBox;
extern int& Btn1DialogBox;
extern int& Btn2DialogBox;
extern int& Btn1Pos;
extern int& Btn2Pos;

typedef void (*tDialogCallback)(int button);

struct DialogState
{
    bool waiting;
    tDialogCallback callback;
};

extern DialogState g_Dialog;

namespace CVisual
{
    void GameText(const char* text);
    void GameTextEx(const char* fmt, int estado, int time, int effect, int slot = 0);

    typedef void(__stdcall* tGameTextLeft)(int line, const char* text);
    static tGameTextLeft GameTextLeft = (tGameTextLeft)0x5E5480;

    // ------------------------------------------------------------------------------------------

    void ShowDialogBox(void* pMessageText, void* pBtn1, void* pBtn2, int pBtn1_Column = 1, int pBtn2_Column = 2);
    void HideDialogBox();

    void ShowDialogBoxEx(void* pMessageText, void* pBtn1, void* pBtn2, tDialogCallback callback, int pBtn1_Column = 1, int pBtn2_Column = 2);
    void UpdateDialogBox();

    // ------------------------------------------------------------------------------------------

    int LoadTexture(int txd, const char* texture);

    // ------------------------------------------------------------------------------------------

    void DrawImage(float posX, float posY, float scaleX, float scaleY, int red, int green, int blue, int alpha, int pTexture);
    void DrawMenuItem(wchar_t* text, float x, float y, int a4, float a5, int selected);
    void DrawString(wchar_t* text, float x, float y, int a4, float a5);

    // ---

    void InstallHook();
}