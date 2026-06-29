// CCheats.h
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
#include "../ui/CVisual.h"
#include "../ui/CMainMenu.h"
#include "../../game.sdk.h"

extern int& cheatFlag;
extern int& m_cheatsActive;

class CCheat {
public:
    struct Cheat {
        const char* name;
        const char* code;
        int enabled;
        void (*onToggle)();
    };


    static CCheat* Get();
    static void Register(const char* name, const char* code, void (*onToggle)());
    static void Process();
    static void InitCheats();
    static void InstallHook();

    static void DrawActiveCheats();


private:
    CCheat() {}
    static CCheat* m_Instance;
    static void UpdateInput();
    static bool CheckCode(const char* code);
};