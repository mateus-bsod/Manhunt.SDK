#pragma once

#include "../../framework.h"
#include "../game.sdk.h"

namespace CVisual
{
    void GameText(const char* text);

    void GameTextEx(const char* fmt, int estado, int time, int effect, int slot = 0);

    typedef void(__stdcall* tGameTextLeft)(int line, const char* text);
    static tGameTextLeft GameTextLeft =
        (tGameTextLeft)0x5E5480;

    // ------------------------------------------------------------------------------------------

    void ShowDialogBox(void* pMessageText, void* pBtn1, void* pBtn2, int unk1, int unk2);

	// ------------------------------------------------------------------------------------------

    int LoadTexture(int txd, const char* texture);

    // ------------------------------------------------------------------------------------------

    void DrawImage(float posX, float posY, float scaleX, float scaleY, int red, int green, int blue, int alpha, int pTexture);
    void DrawMenuItem(wchar_t* text, float x, float y, int a4, float a5, int selected);
    void DrawString(wchar_t* text, float x, float y, int a4, float a5);

}