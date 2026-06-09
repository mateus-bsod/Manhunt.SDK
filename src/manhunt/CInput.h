#pragma once

#include "../../framework.h"
#include "../game.sdk.h"

namespace CInput
{
	bool IsUpKeyPressed();
	bool IsDownKeyPressed();
	bool IsConfirmKeyPressed();
	bool IsActionKeyPressed();
	bool IsExitKeyPressed();
	int IsKeyReleased();
	bool IsUsingMouse();
	void* GetLocalizedString(void* pStringId);
	void PlayMenuSound(int soundId, int pPlayer);
	int GetSelectedOptionFromMouse();
	void HealPlayer(void* pPlayer);
	void ResetMenuState();
}