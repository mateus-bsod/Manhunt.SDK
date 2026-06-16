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
#include "../../game.sdk.h"

class CText
{
public:
    static int Text_ClearAll();
    static float GetTextWidth8(const wchar_t* text, int sizex, int fontType);
    static float Text_CalcWidth(const wchar_t* text, int fontType, int fontIndex);
    static float GetTextWidth(int fontType, float scale);
    static wchar_t* GetKey(const char* key);
    static int Text_AddCharacter(short ch, int a4);
    static void Text_DrawFormatted(wchar_t* text, wchar_t* buffer);
    static void InstallHook();
};