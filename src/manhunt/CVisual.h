#pragma once

namespace CVisual
{
    void GameText(const char* text);

    void GameTextEx(const char* fmt, int estado, int time, int effect, int slot = 0);

    typedef void(__stdcall* tGameTextLeft)(int line, const char* text);
    static tGameTextLeft GameTextLeft =
        (tGameTextLeft)0x5E5480;
}