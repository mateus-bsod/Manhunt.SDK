//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#pragma once

#include "../../game.sdk.h"
#include "../../../framework.h"

class CDebug
{
public:
    static void ToggleScreenCalibLines(bool state);
    static int GetScreenCalibLines();
    static void ToggleTexCacheFix(bool state);
    static int GetTexCacheFix();
    static void ToggleZClearOnly(bool state);
    static int GetZClearOnly();
    static void ToggleFxMode(bool state);
    static int GetFxMode();
    static void ToggleFxModeAA(bool state);
    static int GetFxModeAA();
    static void ToggleFxArtFilter(bool state);
    static int GetFxArtFilter();
    static void ToggleFxDrug(bool state);
    static int GetFxDrug();
    static int GetSlowMotion();
    static void ToggleDisableHunters(bool state);
    static int GetDisableHunters();
    static void ToggleInventoryInfo(bool state);
    static int GetInventoryInfo();
    static void KillPlayer();
    static void TogglePlayerGodMode();
    static void ToggleMemInfo(bool state);
    static void ToggleFPS(bool state);
    static void ToggleSlowMotion(bool state);
    static void DisableHunters(bool state);
};