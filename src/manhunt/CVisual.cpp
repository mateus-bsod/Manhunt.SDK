#include "../../framework.h"

namespace CVisual
{

    typedef void(__cdecl* tGameText)(const char*);
    void GameText(const char* text)
    {
        ((tGameText)0x005E5410)(text);
    }

    void GameTextEx(const char* fmt, int estado, int time, int effect, int slot = 0)
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
}