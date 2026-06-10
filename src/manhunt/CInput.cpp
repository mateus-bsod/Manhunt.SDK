#include "CInput.h"


namespace CInput
{
	bool g_DialogThreadRunning = true;

	int IsUpKeyPressed()
	{
		return CallAndReturn<int, 0x5D8A10>();
	}

	int IsDownKeyPressed()
	{
		return CallAndReturn<int, 0x5D8AA0>();
	}

	int IsConfirmKeyPressed()
	{
		return CallAndReturn<int, 0x5DACC0>();
	}

	int IsActionKeyPressed()
	{
		return CallAndReturn<int, 0x5D8B30>();
	}

	int IsExitKeyPressed()
	{
		return CallAndReturn<int, 0x5D8C60>();
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


	int GetSelectedOptionFromMouse()
	{
		return CallAndReturn<int, 0x5DAD00>();
	}

	void ResetMenuState()
	{
		Call<0x5EF820>();
	}

	// ----------------------------------------------------------------------------------------------

	void DialogThreadFunc()
	{
		while (g_DialogThreadRunning)
		{
			if (InDialogBox && VisibleDialog)
			{
				if ((GetAsyncKeyState(VK_RETURN) & 1) || (GetAsyncKeyState(VK_SPACE) & 1) || (GetAsyncKeyState(VK_LBUTTON) & 1))
				{
					CVisual::UpdateDialogBox();
				}
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}

	// ----------------------------------------------------------------------------------------------

	void InstallHook()
	{
		std::thread dialogThread(DialogThreadFunc);
		dialogThread.detach();
	}

	void Shutdown()
	{
		g_DialogThreadRunning = false;
	}
}