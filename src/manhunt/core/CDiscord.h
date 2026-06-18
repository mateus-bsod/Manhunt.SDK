#pragma once

#include "../../../lib/discord-rpc.h"
#include "../../game.sdk.h"
#include "../entity/CPlayer.h"
#include "../../../framework.h"

#pragma comment(lib, "../../../lib/discord-rpc.lib")


#define APPLICATION_ID "1516982274674004178"

class CDiscord
{
public:
	static void initDiscord();
	static void Shutdown();
};