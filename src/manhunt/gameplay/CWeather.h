#pragma once

#include "../core/CConfigs.h"

class CWeather
{
public:

	// Lightning flash (white)
	static void BlinkLightning();

	// Lightning flash (with Color)
	static void SetWeatherLightningStatic(bool state);
	static void SetWeatherLightningFlashColor(BYTE red, BYTE green, BYTE blue);

	static void InstallHook();
};