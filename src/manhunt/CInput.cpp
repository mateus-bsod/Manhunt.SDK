#include "CInput.h"

namespace CInput
{
	bool IsUpKeyPressed()
	{
		return CallAndReturn<bool, 0x5D8A10>();
	}

	bool IsDownKeyPressed()
	{
		return CallAndReturn<bool, 0x5D8AA0>();
	}

	bool IsConfirmKeyPressed()
	{
		return CallAndReturn<bool, 0x5DACC0>();
	}

	bool IsActionKeyPressed()
	{
		return CallAndReturn<bool, 0x5D8B30>();
	}

	bool IsExitKeyPressed()
	{
		return CallAndReturn<bool, 0x5D8C60>();
	}

	int IsKeyReleased()
	{
		return CallAndReturn<int, 0x5D87A0>();
	}

	bool IsUsingMouse()
	{
		return CallAndReturn<bool, 0x5D5580>();
	}

	void* GetLocalizedString(void* pStringId)
	{
		return CallAndReturn<void*, 0x4937E0>(pStringId);
	}

	void PlayMenuSound(int soundId, int pPlayer)
	{
		Call<0x850072>(soundId, pPlayer);
	}

	int GetSelectedOptionFromMouse()
	{
		return CallAndReturn<int, 0x5DAD00>();
	}

	void ResetMenuState()
	{
		Call<0x5EF820>();
	}
}