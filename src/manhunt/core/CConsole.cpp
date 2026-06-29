#include "CConsole.h"
#include "../entity/CPlayer.h"
#include "../gameplay/CWeapons.h"
#include <cstdarg>

bool Console::m_open = false;
char Console::m_input[256] = { 0 };
char Console::m_history[50][256] = { 0 };
int Console::m_historyCount = 0;
int Console::m_historyIndex = -1;
int Console::m_scrollOffset = 0;
int Console::m_cursorBlink = 0;
char Console::m_logs[500][256] = { 0 };
int Console::m_logCount = 0;
DWORD Console::m_lastKeyTime = 0;
int Console::m_displayOffset = 0;

void Console::Init()
{
    Print("[SYSTEM] Console initialized");
    Print("[SYSTEM] Press F2 to open console");
    Print("[SYSTEM] Use Page Up/Page Down to scroll");
    Print("[SYSTEM] Use Up/Down arrows for command history");
}

void Console::Print(const char* text)
{
    int len = strlen(text);
    int pos = 0;

    while (pos < len)
    {
        int remaining = len - pos;
        int copyLen = (remaining > 45) ? 45 : remaining;

        char line[256];
        strncpy(line, text + pos, copyLen);
        line[copyLen] = 0;

        strcpy(m_logs[m_logCount % 500], line);
        m_logCount++;

        pos += copyLen;
    }

    if (m_open)
    {
        m_scrollOffset = 0;
        m_displayOffset = 0;
    }
}

void Console::Printf(const char* format, ...)
{
    char buffer[300];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    Console::Print(buffer);
}

void Console::AddToHistory(const char* cmd)
{
    if (strlen(cmd) == 0) return;

    strcpy(m_history[m_historyCount % 50], cmd);
    m_historyCount++;
}


void Console::ProcessCommand(const char* cmd)
{
    char result[256] = "";
    char command[64] = "";
    char param[128] = "";

    const char* space = strchr(cmd, ' ');
    if (space) {
        size_t cmdLen = space - cmd;
        if (cmdLen < sizeof(command)) {
            strncpy(command, cmd, cmdLen);
            command[cmdLen] = '\0';
        }
        strcpy(param, space + 1); 
    }
    else {
        strcpy(command, cmd);
        param[0] = '\0';
    }
    
    // -----------------



    if (strcmp(command, "camera") == 0)
    {
		CCamera::ToggleCameraFlyMode(!g_CameraFlyMode);
        m_open = false;
    }

    else if (strcmp(command, "camera_speed") == 0)
    {
        if (param[0] == '\0') {
            sprintf(result, "[ERROR] Usage: camera_speed <value>");
        }
        else {
            float speed = (float)atof(param);
            if (speed > 0.0f) {
                CCamera::SetCameraFlySpeed(speed);
                sprintf(result, "[CAMERA] Speed set to: %.2f", speed);
            }
            else {
                sprintf(result, "[ERROR] Invalid speed: %s", param);
            }
        }
    }

    else if (strcmp(command, "camera_sensi") == 0)
    {
        if (param[0] == '\0') {
            sprintf(result, "[ERROR] Usage: camera_sensi <value>");
        }
        else {
            float speed = (float)atof(param);
            if (speed > 0) {
                CCamera::SetCameraFlySensitivity(speed);
                sprintf(result, "[CAMERA] sensitivity set to: %.2f", speed);
            }
            else {
                sprintf(result, "[ERROR] Invalid sensitivity: %s", param);
            }
        }
    }
    else if (strcmp(command, "clear") == 0)
    {
        m_logCount = 0;
        m_scrollOffset = 0;
        m_displayOffset = 0;
        sprintf(result, "[CONSOLE] Cleared");
    }
    else if (strcmp(command, "close") == 0)
    {
        m_open = false;
    }
    else if (strlen(command) > 0)
    {
        sprintf(result, "[ERROR] Unknown command: %s", command);
    }

    if (result[0] != 0)
    {
        Print(result);
    }
}

void Console::Draw()
{
    if (GetAsyncKeyState(VK_F2) & 1)
    {
        m_open = !m_open;
        if (m_open)
        {
            m_scrollOffset = 0;
            m_displayOffset = 0;
        }
        else
        {
            m_input[0] = 0;
            m_historyIndex = -1;
        }
    }

    if (!m_open) return;

    m_cursorBlink++;
    if (m_cursorBlink > 30) m_cursorBlink = 0;

    CVisual::DrawColoredQuad(0.01f, 0.01f, 0.98f, 0.45f, 0, 0, 0, 230, 0);

    int totalLogs = m_logCount;
    int visibleLines = 14;

    if (totalLogs > visibleLines)
    {
        char scrollInfo[64];
        sprintf(scrollInfo, "[Scroll: %d/%d]", m_scrollOffset, totalLogs - visibleLines);
        CVisual::DrawTextString(scrollInfo, 0.75f, 0.01f, 1.0f, 1.0f, 0, 0, 0);
        CVisual::DrawTextString("PageUp / PageDown", 0.75f, 0.05f, 1.0f, 1.0f, 0, 0, 0);
    }

    int startLog = totalLogs - visibleLines - m_scrollOffset;
    if (startLog < 0) startLog = 0;
    int endLog = startLog + visibleLines;
    if (endLog > totalLogs) endLog = totalLogs;

    float yPos = 0.01f;
    for (int i = startLog; i < endLog; i++)
    {
        if (m_logs[i][0] != 0)
        {
            CVisual::DrawTextString(m_logs[i], 0.02f, yPos, 1.0f, 1.0f, 0, 0, 0);
            yPos += 0.02f;
        }
    }

    char displayText[260];
    sprintf(displayText, "> %s%s", m_input, (m_cursorBlink < 15) ? "_" : " ");
    CVisual::DrawTextString(displayText, 0.02f, 0.41f, 1.2f, 1.2f, 0, 0, 0);

    if (GetAsyncKeyState(VK_NEXT) & 1)
    {
        m_scrollOffset++;
        if (m_scrollOffset > totalLogs - visibleLines) m_scrollOffset = totalLogs - visibleLines;
        if (m_scrollOffset < 0) m_scrollOffset = 0;
        Sleep(50);
    }

    if (GetAsyncKeyState(VK_PRIOR) & 1)
    {
        m_scrollOffset--;
        if (m_scrollOffset < 0) m_scrollOffset = 0;
        Sleep(50);
    }

    // Mouse wheel scroll
    if (GetAsyncKeyState(VK_MBUTTON) & 0x80)
    {
        // Suporte para wheel do mouse (opcional)
    }

    if (GetAsyncKeyState(VK_RETURN) & 1 && strlen(m_input) > 0)
    {
        AddToHistory(m_input);
        ProcessCommand(m_input);
        m_input[0] = 0;
        m_historyIndex = -1;
        m_scrollOffset = 0;
        Sleep(50);
    }

    if (GetAsyncKeyState(VK_BACK) & 1)
    {
        int len = strlen(m_input);
        if (len > 0) m_input[len - 1] = 0;
        Sleep(50);
    }

    if (GetAsyncKeyState(VK_UP) & 1 && m_historyCount > 0)
    {
        if (m_historyIndex < m_historyCount - 1)
        {
            m_historyIndex++;
            strcpy(m_input, m_history[(m_historyCount - 1 - m_historyIndex) % 50]);
        }
        Sleep(50);
    }

    if (GetAsyncKeyState(VK_DOWN) & 1)
    {
        if (m_historyIndex > 0)
        {
            m_historyIndex--;
            strcpy(m_input, m_history[(m_historyCount - 1 - m_historyIndex) % 50]);
        }
        else if (m_historyIndex == 0)
        {
            m_historyIndex = -1;
            m_input[0] = 0;
        }
        Sleep(50);
    }

    DWORD now = GetTickCount();
    if (now - m_lastKeyTime > 30)
    {
        for (int key = 'A'; key <= 'Z'; key++)
        {
            if (GetAsyncKeyState(key) & 1)
            {
                int len = strlen(m_input);
                if (len < 255)
                {
                    m_input[len] = tolower(key);
                    m_input[len + 1] = 0;
                    m_lastKeyTime = now;
                }
                break;
            }
        }
        
        for (int key = '0'; key <= '9'; key++)
        {
            if (GetAsyncKeyState(key) & 1)
            {
                int len = strlen(m_input);
                if (len < 255)
                {
                    m_input[len] = key;
                    m_input[len + 1] = 0;
                    m_lastKeyTime = now;
                }
                break;
            }
        }

        if (GetAsyncKeyState(VK_SPACE) & 1)
        {
            int len = strlen(m_input);
            if (len < 255)
            {
                m_input[len] = ' ';
                m_input[len + 1] = 0;
                m_lastKeyTime = now;
            }
        }
    }
}

bool Console::IsOpen()
{
    return m_open;
}

void Console::Close()
{
    m_open = false;
}