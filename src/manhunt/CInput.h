#pragma once

#include "../../framework.h"
#include "CVisual.h"
#include "../game.sdk.h"

namespace CInput
{
	int IsUpKeyPressed();
	int IsDownKeyPressed();
	int IsConfirmKeyPressed();
	int IsActionKeyPressed();
	int IsExitKeyPressed();
	int IsKeyReleased();
	bool IsUsingMouse();
	void* GetLocalizedString(void* pStringId);
	void PlayMenuSound(int soundId, int pPlayer);
	int GetSelectedOptionFromMouse();
	void HealPlayer(void* pPlayer);
	void ResetMenuState();
	void InstallHook();
	void Shutdown();
	void CheckDialogInput();
}