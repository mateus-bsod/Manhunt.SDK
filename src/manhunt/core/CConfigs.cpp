#include "CConfigs.h"
#include <fstream>
#include <sstream>
#include <filesystem>

CConfigs::tParseGameConfig CConfigs::oParseGameConfig = nullptr;
SafetyHookInline CConfigs::g_ParseGameConfigHook;
CConfigs::GameConfig CConfigs::m_config;
bool CConfigs::m_initialized = false;
const std::string CConfigs::m_configPath = "Manhunt.SDK/config.cfg";

void CConfigs::InitGameConfig()
{
    m_config.dword_7D4FF4 = (int*)0x7D4FF4;
    m_config.unk_7D4FFC = (char*)0x7D4FFC;
    m_config.dword_7D507C = (int*)0x7D507C;
    m_config.dword_7D3594 = (int*)0x7D3594;
    m_config.dword_7D3598 = (int*)0x7D3598;
    m_config.dword_7D359C = (int*)0x7D359C;
    m_config.dword_7D35A0 = (int*)0x7D35A0;
    m_config.dword_7D4E88 = (int*)0x7D4E88;
    m_config.dword_7C9E34 = (int*)0x7C9E34;
    m_config.dword_7C9E38 = (int*)0x7C9E38;
    m_config.unk_7CA2AC = (int*)0x7CA2AC;
    m_config.unk_7CA2B0 = (int*)0x7CA2B0;
    m_config.unk_7CA2B4 = (int*)0x7CA2B4;
    m_config.unk_7CA2B8 = (int*)0x7CA2B8;
    m_config.g_MaxFadeValue = (int*)0x7CEFC8;
    m_config.dword_7D4E8C = (int*)0x7D4E8C;
    m_config.dword_7D4E9C = (int*)0x7D4E9C;
    m_config.dword_7D4E90 = (int*)0x7D4E90;
    m_config.dword_7D4E94 = (int*)0x7D4E94;
    m_config.dword_7D9248 = (int*)0x7D9248;
    m_config.dword_7D4E98 = (int*)0x7D4E98;
    m_config.dword_736BC4 = (int*)0x736BC4;

    m_initialized = true;
}

void CConfigs::LoadConfigFromFile()
{
    std::ifstream file(m_configPath);
    if (!file.is_open()) {
		MessageBoxA(nullptr, ("Failed to open config file: " + m_configPath).c_str(), "Error", MB_ICONERROR);
        exit(EXIT_FAILURE);
        return;
    }

    Console::Printf("[CConfigs] Loading config from: %s", m_configPath.c_str());

    std::string line;
    while (std::getline(file, line)) {
        size_t start = line.find_first_not_of(" \t\r\n");
        if (start == std::string::npos) continue;
        size_t end = line.find_last_not_of(" \t\r\n");
        line = line.substr(start, end - start + 1);

        if (line.empty() || line[0] == '#' || line[0] == '<') continue;

        size_t sep = line.find_first_of(" \t=");
        if (sep == std::string::npos) continue;

        std::string key = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 1);

        start = valueStr.find_first_not_of(" \t");
        if (start == std::string::npos) continue;
        valueStr = valueStr.substr(start);

        int value = std::stoi(valueStr);

        Console::Printf("[CConfigs] Found config: %s = %d", key.c_str(), value);
        ProcessKeyValue(key.c_str(), value);
    }

    file.close();
    Console::Printf("[CConfigs] Config loaded successfully!");
}

void CConfigs::ProcessKeyValue(const char* key, int value)
{
    if (_stricmp(key, "SKIP_MENU") == 0) {
        *m_config.dword_7D4E8C = (value > 0) ? 1 : 0;
        if (*m_config.dword_736BC4 >= 0 && *m_config.dword_736BC4 != -2) {
            *m_config.dword_7D4E8C = 1;
        }
        Console::Printf("[CConfigs] SKIP_MENU set to %d", *m_config.dword_7D4E8C);
    }
    else if (_stricmp(key, "START_LEVEL") == 0) {
        if (value < 0) value = 0;
        if (value > 999) value = 999;
        *m_config.dword_7D4E94 = value;
        if (*m_config.dword_736BC4 >= 0 && *m_config.dword_736BC4 != -2) {
            *m_config.dword_7D4E94 = *m_config.dword_736BC4;
        }
        Console::Printf("[CConfigs] START_LEVEL set to %d", *m_config.dword_7D4E94);
    }
    else if (_stricmp(key, "GAME_CONTROL_TYPE") == 0) {
        if (value < 0) value = 0;
        if (value > 2) value = 2;
        *m_config.dword_7D359C = value;
        Console::Printf("[CConfigs] GAME_CONTROL_TYPE set to %d", *m_config.dword_7D359C);
    }
    else if (_stricmp(key, "GAME_CONTROL_INVERT_Y") == 0) {
        *m_config.dword_7D35A0 = (value > 0) ? 1 : 0;
        Console::Printf("[CConfigs] GAME_CONTROL_INVERT_Y set to %d", *m_config.dword_7D35A0);
    }
    else if (_stricmp(key, "FX_MODE") == 0) {
        *m_config.dword_7D4E88 = (value > 0) ? 1 : 0;
        Console::Printf("[CConfigs] FX_MODE set to %d", *m_config.dword_7D4E88);
    }
    else if (_stricmp(key, "GAME_MAP_MINI") == 0) {
        *m_config.dword_7C9E34 = (value > 0) ? 1 : 0;
        Console::Printf("[CConfigs] GAME_MAP_MINI set to %d", *m_config.dword_7C9E34);
    }
    else if (_stricmp(key, "GAME_MAP_FULLSCREEN") == 0) {
        *m_config.dword_7C9E38 = (value > 0) ? 1 : 0;
        Console::Printf("[CConfigs] GAME_MAP_FULLSCREEN set to %d", *m_config.dword_7C9E38);
    }
    else if (_stricmp(key, "GAME_MAP_PLAYER_NOISE_RGB") == 0) {
        Console::Printf("[CConfigs] GAME_MAP_PLAYER_NOISE_RGB set");
    }
    else if (_stricmp(key, "GAME_MAP_MINI_VISIBLE_AREA") == 0) {
        if (value < 0) value = 0;
        if (value > 999) value = 999;
        *m_config.g_MaxFadeValue = value;
        Console::Printf("[CConfigs] GAME_MAP_MINI_VISIBLE_AREA set to %d", *m_config.g_MaxFadeValue);
    }
    else if (_stricmp(key, "PS2_PC_BUTTON_FIX") == 0) {
        *m_config.dword_7D4E9C = (value > 0) ? 1 : 0;
        Console::Printf("[CConfigs] PS2_PC_BUTTON_FIX set to %d", *m_config.dword_7D4E9C);
    }
    else if (_stricmp(key, "START_LANGUAGE") == 0) {
        if (value < 0) value = 0;
        if (value > 5) value = 5;
        *m_config.dword_7D4E98 = value;
        Console::Printf("[CConfigs] START_LANGUAGE set to %d", *m_config.dword_7D4E98);
    }
    else if (_stricmp(key, "DISABLE") == 0) {
        *m_config.dword_7D4E90 = (value > 0) ? 1 : 0;
        Console::Printf("[CConfigs] DISABLE set to %d", *m_config.dword_7D4E90);
    }
    else if (_stricmp(key, "USE_MEMORY_CARD") == 0) {
        *m_config.dword_7D9248 = (value > 0) ? 1 : 0;
        Console::Printf("[CConfigs] USE_MEMORY_CARD set to %d", *m_config.dword_7D9248);
    }
}

signed int CConfigs::ParseGameConfig()
{
    if (!m_initialized) {
        InitGameConfig();
    }

    LoadConfigFromFile();

    *m_config.dword_7D3594 = 0;
    *m_config.dword_7D3598 = 1;
    *m_config.dword_7D359C = 0;
    *m_config.unk_7CA2B8 = 128;
    *m_config.dword_7D4E98 = 0;

    Console::Printf("[CConfigs] Config parsing complete!");
    return 0;
}

int __thiscall CConfigs::hkParseGameConfig(void* pThis)
{
    ParseGameConfig();
    return 0;
}

void CConfigs::InstallHook()
{
    g_ParseGameConfigHook = safetyhook::create_inline(
        (void*)0x5FCC50,
        (void*)&CConfigs::hkParseGameConfig);

    oParseGameConfig = g_ParseGameConfigHook.original<tParseGameConfig>();

    Console::Printf("[CConfigs] Hook installed successfully!");
}

void CConfigs::UninstallHook()
{
    if (g_ParseGameConfigHook) {
        g_ParseGameConfigHook.reset();
        oParseGameConfig = nullptr;
        Console::Printf("[CConfigs] Hook uninstalled");
    }
}
