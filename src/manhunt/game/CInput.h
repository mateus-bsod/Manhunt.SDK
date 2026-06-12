#pragma once

#include "../../framework.h"
#include "../ui/CVisual.h"
#include "../../game.sdk.h"

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
	int GetSelectedOptionFromMouse();
	void HealPlayer(void* pPlayer);
	void ResetMenuState();
	void InstallHook();
	void Shutdown();
	void CheckDialogInput();
}