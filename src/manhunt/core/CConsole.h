// Console.h
#pragma once

#include "../../../framework.h"
#include "../../game.sdk.h"

class Console
{
private:
    static bool m_open;
    static char m_input[256];
    static char m_history[50][256];
    static int m_historyCount;
    static int m_historyIndex;
    static int m_scrollOffset;
    static int m_cursorBlink;
    static char m_logs[500][256];
    static int m_logCount;
    static DWORD m_lastKeyTime;
    static int m_displayOffset;

    static void ProcessCommand(const char* cmd);
    static void AddToHistory(const char* cmd);

public:
    static void Init();
    static void Draw();
    static void Print(const char* text);
    static void Printf(const char* format, ...);
    static bool IsOpen();
    static void Close();
};