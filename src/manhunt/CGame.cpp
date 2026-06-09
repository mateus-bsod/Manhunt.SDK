#include "CGame.h"

namespace CGame
{
	void InitialiseWorld(int missionId)
	{
		Call<0x474330, int>(missionId);
	}

	void InstallHook()
	{

	}
}