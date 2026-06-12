#pragma once

#include "../../../framework.h"

#include "../entity/CPlayer.h"
#include "../ui/CVisual.h"
#include "../ui/CText.h"

#include "../../game.sdk.h"

extern DWORD gRenderer;

namespace CGame
{
	void InitialiseWorld(int missionId);
	void InstallHook();
}