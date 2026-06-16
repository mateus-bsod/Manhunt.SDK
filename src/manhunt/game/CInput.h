//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#pragma once

#include <thread>
#include <chrono>
#include "../ui/CVisual.h"
#include "../../game.sdk.h"
#include "../../../framework.h"

class CInput
{
private:
    static bool g_DialogThreadRunning;

public:
    static int IsUpKeyPressed();
    static int IsDownKeyPressed();
    static int IsConfirmKeyPressed();
    static int IsActionKeyPressed();
    static int IsExitKeyPressed();
    static int IsKeyReleased();
    static bool IsUsingMouse();
    static void* GetLocalizedString(void* pStringId);
    static int GetSelectedOptionFromMouse();
    static void ResetMenuState();
    static void DialogThreadFunc();
    static void InstallHook();
    static void Shutdown();
};