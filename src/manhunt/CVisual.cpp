#include "CVisual.h"

namespace CVisual
{


    typedef void(__cdecl* tGameText)(const char*);
    void GameText(const char* text)
    {
        ((tGameText)0x005E5410)(text);
    }

    void GameTextEx(const char* fmt, int estado, int time, int effect, int slot)
    {
        va_list va;
        va_start(va, fmt);

        DWORD* p318 = (DWORD*)0x7CF318;
        DWORD* p380 = (DWORD*)0x7CF380;
        DWORD* p3E8 = (DWORD*)0x7CF3E8;
        DWORD* p450 = (DWORD*)0x7CF450;

        p318[slot] = estado;
        p380[slot] = time;
        p3E8[slot] = effect;

        if (!p450[slot])
        {
            DWORD ret;

            __asm
            {
                mov ecx, 0x67D000
                push 0x200

                mov eax, 0x401350
                call eax

                mov ret, eax
            }

            p450[slot] = ret;
        }

        typedef int(__cdecl* Format_t)(void*, int, int);
        ((Format_t)0x614C80)(
            (void*)p450[slot],
            (int)fmt,
            (int)va);

        va_end(va);
    }

    // ------------------------------------------------------------------------------------------

    /*


                CVisual::ShowDialogBox(
                    CVisual::KeyEx("maph0rip is cool?"),
                    CVisual::KeyEx("yes"),
                    CVisual::KeyEx("no"));


    */

    void ShowDialogBox(void* pMessageText , void* pBtn1, void* pBtn2, int pBtn1_Column = 1, int pBtn2_Column = 2)
    {
        Call<0x5D7EC0>(pMessageText, pBtn1, pBtn2, pBtn1_Column, pBtn2_Column);
    }

    // ------------------------------------------------------------------------------------------

    int LoadTexture(int txd, const char* texture)
    {
        return CallAndReturn<int, 0x5EA520, int, const char*>(txd, texture);
    }

    // ------------------------------------------------------------------------------------------

    void DrawImage(float posX, float posY, float scaleX, float scaleY, int red, int green, int blue, int alpha, int pTexture)
    {
		Call<0x5F96F0>(posX, posY, scaleX, scaleY, red, green, blue, alpha, pTexture);
	}

    void DrawMenuItem(wchar_t* text, float x, float y, int a4, float a5, int selected)
    {
        Call<0x5D55C0>(text, x, y, a4, a5, selected);
    }
    
    void DrawString(wchar_t* text, float x, float y, int a4, float a5)
    {
		Call<0x5D5B30>(text, x, y, a4, a5);
	}

    // ------------------------------------------------------------------------------------------


}