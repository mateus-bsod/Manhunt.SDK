#pragma once

#include "../../../framework.h"
#include "../../game.sdk.h"

namespace CDebug
{
    typedef void(__stdcall* ShowCredits_t)();
    static ShowCredits_t ShowCredits =
        (ShowCredits_t)0x5EE5F0;

    typedef void(__stdcall* ToggleGodMode_t)();
    static ToggleGodMode_t ToggleGodMode =
        (ToggleGodMode_t)0x5EE4F0;

    typedef void(__stdcall* KillHunters_t)();
    static KillHunters_t KillHunters =
        (KillHunters_t)0x5EE7C0;

    typedef void(__stdcall* ToggleHunterEn_t)();
    static ToggleHunterEn_t ToggleHunterEn =
        (ToggleHunterEn_t)0x5EE580;

    typedef void(__stdcall* ResetGameState_t)();
    static ResetGameState_t ResetGameState =
        (ResetGameState_t)0x5D2010;

    typedef void(__stdcall* CompleteLevel_t)();
    static CompleteLevel_t CompleteLevel =
        (CompleteLevel_t)0x5D1F00;

    typedef void(__stdcall* GiveAllStars_t)();
    static GiveAllStars_t GiveAllStars =
        (GiveAllStars_t)0x5D6CC0;

    typedef void(__stdcall* OpenNormalLevels_t)();
    static OpenNormalLevels_t OpenNormalLevels =
        (OpenNormalLevels_t)0x5D6CB0;

    //

    void ToggleScreenCalibLines(bool state);
    int GetScreenCalibLines();

    void ToggleScreenCalibLines(bool state);
    int GetScreenCalibLines();

    void ToggleTexCacheFix(bool state);
    int GetTexCacheFix();

    void ToggleZClearOnly(bool state);
    int GetZClearOnly();

    void ToggleFxMode(bool state);
    int GetFxMode();

    void ToggleFxModeAA(bool state);
    int GetFxModeAA();

    void ToggleFxArtFilter(bool state);
    int GetFxArtFilter();

    void ToggleFxDrug(bool state);
    int GetFxDrug();

    void ToggleSlowMotion(bool state);
    int GetSlowMotion();

    void ToggleDisableHunters(bool state);
    int GetDisableHunters();

    void ToggleInventoryInfo(bool state);
    int GetInventoryInfo();

    //


    void KillPlayer(); // or [ sub_4BCCB0 ]

    void TogglePlayerGodMode();

    //

    void ToggleMemInfo(bool state);
    void ToggleFPS(bool state);
    void ToggleSlowMotion(bool state);
    void DisableHunters(bool state);
}