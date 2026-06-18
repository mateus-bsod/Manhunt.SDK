#pragma once

#include "../../../framework.h"
#include "../../game.sdk.h"
#include <fstream>
#include <string>

class CConfigs
{
private:
    struct GameConfig {
        int* dword_7D4FF4;
        char* unk_7D4FFC;
        int* dword_7D507C;
        int* dword_7D3594;
        int* dword_7D3598;
        int* dword_7D359C;
        int* dword_7D35A0;
        int* dword_7D4E88;
        int* dword_7C9E34;
        int* dword_7C9E38;
        int* unk_7CA2AC;
        int* unk_7CA2B0;
        int* unk_7CA2B4;
        int* unk_7CA2B8;
        int* g_MaxFadeValue;
        int* dword_7D4E8C;
        int* dword_7D4E9C;
        int* dword_7D4E90;
        int* dword_7D4E94;
        int* dword_7D9248;
        int* dword_7D4E98;
        int* dword_736BC4;
    };

    typedef int(__thiscall* tParseGameConfig)(void*);
    static tParseGameConfig oParseGameConfig;
    static SafetyHookInline g_ParseGameConfigHook;
    static GameConfig m_config;
    static bool m_initialized;
    static const std::string m_configPath;

    static void InitGameConfig();
    static void ProcessKeyValue(const char* key, int value);
    static signed int ParseGameConfig();
    static int __thiscall hkParseGameConfig(void* pThis);
    static void LoadConfigFromFile();

public:
    static void InstallHook();
    static void UninstallHook();
    static void SetConfigPath(const std::string& path);
};