//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CCheats.h"
#include <cctype>

SafetyHookInline g_CheatsManager;
std::vector<CCheat::Cheat> m_Cheats;
char m_InputBuffer[64] = { 0 };
int m_InputIndex = 0;

// cheatFlag originalmente é mal feita, só aguenta um tipo de cheat ativo por vez
// então, para contornar isso, vamos usar variáveis
int& cheatFlag = *(int*)0x7C84A8; 

int& m_godMode = *(int*)0x7C84CC;
int& m_runner = *(int*)0x7C84B0;
int& m_silence = *(int*)0x7C84B4;
int& m_regenerate = *(int*)0x7C84B8;
int& m_heliumHunters = *(int*)0x7C84BC; // tiro bomba
int& m_fullyarmed = *(int*)0x7C84C0;
int& m_superPunch = *(int*)0x7C84C4;
int& m_invisibility = *(int*)0x7C84C8;
int& m_RabbitSkin = *(int*)0x6A94C0;
int& m_cheatsActive = *(int*)0x7C84AC;

CCheat* CCheat::m_Instance = nullptr;

CCheat* CCheat::Get() {
    if (!m_Instance) m_Instance = new CCheat();
    return m_Instance;
}

void CCheat::Register(const char* name, const char* code, void (*onToggle)()) {
    Cheat c;
    c.name = name;
    c.code = code;
    c.enabled = false;
    c.onToggle = onToggle;
    m_Cheats.push_back(c);
}

void CCheat::UpdateInput() {
    for (int key = 'A'; key <= 'Z'; key++) {
        if (GetAsyncKeyState(key) & 1) {
            m_InputBuffer[m_InputIndex++] = toupper(key);
            m_InputBuffer[m_InputIndex] = '\0';

            if (m_InputIndex >= 63) {
                m_InputIndex = 0;
                m_InputBuffer[0] = '\0';
            }

            for (auto& c : m_Cheats) {
                if (CheckCode(c.code)) {
                    c.enabled = !c.enabled;
                    if (c.onToggle) c.onToggle();
                    m_InputIndex = 0;
                    m_InputBuffer[0] = '\0';
                    break;
                }
            }
            break;
        }
    }
}

bool CCheat::CheckCode(const char* code) {
    int codeLen = strlen(code);
    int bufferLen = strlen(m_InputBuffer);

    if (bufferLen < codeLen) return false;

    for (int i = 0; i < codeLen; i++) {
        if (toupper(m_InputBuffer[bufferLen - codeLen + i]) != toupper(code[i])) {
            return false;
        }
    }
    return true;
}

void CCheat::Process() {
    if (CurrentPlayerMenu != 7) return;
    UpdateInput();
}

void CCheat::DrawActiveCheats() {
    if (CurrentPlayerMenu != 7) return;

    struct CheatItem { int active; const char* name; };
    /*
    *
    case 1: cheatText = CText::GetKey("C_RUN"); break;
    case 2: cheatText = CText::GetKey("C_SILEN"); break;
    case 4: cheatText = CText::GetKey("C_REGEN"); break;
    case 8: cheatText = CText::GetKey("C_HELI"); break;
    case 16: cheatText = CText::GetKey("C_FULEQ"); break;
    case 32: cheatText = CText::GetKey("C_SUPUN"); break;
    case 64: cheatText = CText::GetKey("C_RABBI"); break;
    case 128: cheatText = CText::GetKey("C_MONKE"); break;
    case 256: cheatText = CText::GetKey("C_INVIS"); break;
    case 512: cheatText = CText::GetKey("C_PIGGS"); break;
    case 1024: cheatText = CText::GetKey("C_GOD"); break;

    */
    CheatItem items[] = {
        {m_godMode, "God Mode"},
        {m_runner, "Runner"},
        {m_silence, "Silence"},
        {m_regenerate, "Regenerate"},
        {m_heliumHunters, "Helium Hunters"},
        {m_fullyarmed, "Fully Armed"},
        {m_superPunch, "Super Punch"},
        {m_invisibility, "Invisibility"},
        {m_RabbitSkin == 1, "White Rabbit"}, // checa valor 1
        {m_RabbitSkin == 2, "Monkey Skin"},  // checa valor 2
        {m_RabbitSkin == 3, "Piggsy Skin"}   // checa valor 3
    };

    float y = 0.70f;
    float x = 0.10f;
    float lineHeight = 0.025f;

    int activeCount = 0;
    for (auto& item : items) {
        if (item.active) activeCount++;
    }

    if (activeCount == 0)
    {
        m_cheatsActive = 0;
        return;
    }
    else m_cheatsActive = 1;


    for (auto& item : items) {
        if (item.active) {
            CVisual::DrawTextString("~green~[ON]~white~", x, y, 0.9f, 0.9f, 0, 0, 0);
            CVisual::DrawTextString(item.name, x + 0.08f, y, 0.9f, 0.9f, 0, 0, 0);
            y -= lineHeight;
        }
    }
}

void CheatManagerHook() {
    CCheat::Get()->Process();
}

void ToggleGodMode() {
    m_godMode = ~m_godMode;
}

void ToggleRunner() {
    m_runner = ~m_runner;
}

void ToggleSilence() {
    m_silence = ~m_silence;
}

void ToggleRegenerate() {
    m_regenerate = ~m_regenerate;
}

void ToggleHeliumHunters() {
    m_heliumHunters = ~m_heliumHunters;
}

void ToggleFullyArmed() {
    m_fullyarmed = ~m_fullyarmed;
}

void ToggleSuperPunch() {
    m_superPunch = ~m_superPunch;
}

void ToggleInvisibility() {
    m_invisibility = ~m_invisibility;
}

void ToggleWhiteRabbit() {
    m_RabbitSkin = (m_RabbitSkin == 1) ? 0 : 1;
}

void ToggleMonkeySkin() {
    m_RabbitSkin = (m_RabbitSkin == 2) ? 0 : 2;
}

void TogglePiggsySkin() {
    m_RabbitSkin = (m_RabbitSkin == 3) ? 0 : 3;
}

void DisableAllCheats() {
    m_godMode = false;
    m_runner = false;
    m_silence = false;
    m_regenerate = false;
    m_heliumHunters = false;
    m_fullyarmed = false;
    m_superPunch = false;
    m_invisibility = false;
    m_RabbitSkin = 0;
    m_cheatsActive = false;
}


void CCheat::InitCheats() {
    auto* cheats = CCheat::Get();

    cheats->Register("God Mode", "IMINVINCIBLE", ToggleGodMode);
    cheats->Register("Runner", "URUNFAST", ToggleRunner);
    cheats->Register("Silence", "ALLRDEAF", ToggleSilence);
    cheats->Register("Regenerate", "HEALBACK", ToggleRegenerate);
    cheats->Register("Helium Hunters", "THEYBOOM", ToggleHeliumHunters); // cria uma explosao aonde o tiro vai
    cheats->Register("Fully Armed", "UGOTARMS", ToggleFullyArmed);
    cheats->Register("Super Punch", "UHITHARD", ToggleSuperPunch);
    cheats->Register("Invisibility", "EVILEYES", ToggleInvisibility);
    cheats->Register("White Rabbit", "BUNYSUIT", ToggleWhiteRabbit);
    cheats->Register("Monkey Skin", "HELLSUIT", ToggleMonkeySkin); 
    cheats->Register("Piggsy Skin", "PIGGSUIT", TogglePiggsySkin);
    cheats->Register("Disable All", "CHEATOFF", DisableAllCheats);
}

void CCheat::InstallHook() {
    CCheat::InitCheats();
    g_CheatsManager = safetyhook::create_inline((void*)0x5D4330, (void*)&CheatManagerHook);
}