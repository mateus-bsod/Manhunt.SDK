//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CWeather.h"
#include "../gameplay/CWeapons.h"
#include "../entity/CPlayer.h"

typedef int(__thiscall* tUpdateWeatherAndSky)();
tUpdateWeatherAndSky oUpdateWeatherAndSky = nullptr;
SafetyHookInline g_UpdateWeatherAndSky;

BYTE& g_LightningFlashWhite_Active = *reinterpret_cast<BYTE*>(0x7B3260);

bool g_LightningFlashStatic = false;
float& g_LightningFlashDuration = *reinterpret_cast<float*>(0x7B3278);
BYTE& g_LightningFlashRed = *reinterpret_cast<BYTE*>(0x715BB8);
BYTE& g_LightningFlashGreen = *reinterpret_cast<BYTE*>(0x715BB9);
BYTE& g_LightningFlashBlue = *reinterpret_cast<BYTE*>(0x715BBA);

BYTE g_LightningFlashRedChange = 0xFF;
BYTE g_LightningFlashGreenChange = 0xFF;
BYTE g_LightningFlashBlueChange = 0xFF;

void CWeather::BlinkLightning()
{
    g_LightningFlashWhite_Active = 1;
}

void CWeather::SetWeatherLightningStatic(bool state)
{
    g_LightningFlashStatic = state;
}

void CWeather::SetWeatherLightningFlashColor(BYTE red, BYTE green, BYTE blue)
{
    g_LightningFlashRed = g_LightningFlashRedChange = red;
    g_LightningFlashGreen = g_LightningFlashGreenChange = green;
    g_LightningFlashBlue = g_LightningFlashBlueChange = blue;
}

int UpdateWeatherAndSky()
{
    if (g_LightningFlashStatic)
    {
        g_LightningFlashDuration = 1.0;
        CWeather::SetWeatherLightningFlashColor(
            g_LightningFlashRedChange,
            g_LightningFlashGreenChange,
            g_LightningFlashBlueChange
        );
    }

    if (!CConfigs::m_config.DisableWeather)
        return oUpdateWeatherAndSky();
    else
        return 1;
}

void CWeather::InstallHook()
{
    if (CConfigs::m_config.DisableNewspapers)
    {
        PATCH(0x0474C80, 0x90, 5);
    }

    g_UpdateWeatherAndSky = safetyhook::create_inline(
        (void*)0x5AFA10,
        (void*)&UpdateWeatherAndSky);

    oUpdateWeatherAndSky = g_UpdateWeatherAndSky.original<tUpdateWeatherAndSky>();
}