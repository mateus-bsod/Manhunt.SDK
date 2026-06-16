//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CText.h"
#include <cstring>
#include <cstdlib>

void CText::Text_DrawFormatted(wchar_t* text, wchar_t* buffer)
{
	Call<0x5E5BC0, wchar_t*, wchar_t*>(text, buffer);
}

int CText::Text_ClearAll()
{
    return CallAndReturn<int, 0x5DFC00>();
}

float CText::GetTextWidth8(const wchar_t* text, int sizex, int fontType)
{
    return CallMethodAndReturn<float, 0x5E5670, const wchar_t*, int, int>(text, sizex, fontType);
}

float CText::Text_CalcWidth(const wchar_t* text, int fontType, int fontIndex)
{
    return CallAndReturn<float, 0x5E56F0, const wchar_t*, int, int>(text, fontType, fontIndex);
}

float CText::GetTextWidth(int fontType, float scale)
{
    float result;
    __asm {
        mov     ecx, fontType
        mov     eax, [0x7D2BC4 + ecx * 4]
        fld     dword ptr[0x7D2BF4 + eax * 4]
        fmul    scale
        fstp    result
    }
    return result;
}

wchar_t* CText::GetKey(const char* key)
{
    return CallMethodAndReturn<wchar_t*, 0x4937E0, int, const char*>(0x725A38, key);
}

void CText::InstallHook()
{
}