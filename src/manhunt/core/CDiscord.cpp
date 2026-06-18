// CDiscord.cpp
#include "CDiscord.h"

void CDiscord::initDiscord()
{
    Discord_Initialize(APPLICATION_ID, 0, 0, 0);

    DiscordRichPresence drp;

    drp = { 0 };
    drp.largeImageKey = "small_eyes";
    drp.startTimestamp = time(0);

    PLAYER_STATE playerState;
    while (1)
    {


		playerState = CPlayer::GetPlayerState();
        if (playerState == PLAYER_MENU)
        {
            drp.state = "In Menu";
            drp.smallImageKey = "smyle";
            drp.smallImageText = "Mr. Nasty waiting for you.";
            drp.details = "Choosing which film to shoot...";
        }
        else if (playerState == PLAYER_INGAME)
        {
            drp.state = "In Game";
            drp.smallImageKey = "man";
            drp.smallImageText = "Watching a movie.";

            int missionId = CPlayer::GetPlayerMission();

            int* missionNamePtr = nullptr;
            int* subtitlePtr = nullptr;

            CPlayer::GetMissionName(missionId, missionNamePtr, subtitlePtr);

            wchar_t* missionNameW = (wchar_t*)missionNamePtr;
            wchar_t* subtitleW = (wchar_t*)subtitlePtr;

            char missionName[64] = { 0 };
            char subtitle[64] = { 0 };

            if (missionNameW) {
                WideCharToMultiByte(CP_UTF8, 0, missionNameW, -1, missionName, 64, NULL, NULL);
            }
            if (subtitleW) {
                WideCharToMultiByte(CP_UTF8, 0, subtitleW, -1, subtitle, 64, NULL, NULL);
            }

            std::string buffer = "Scene: " + std::string(missionName) + " (File: " + std::to_string(missionId) + ")";
            drp.details = buffer.c_str();

        }
		else
		{
			drp.state = "In Cutscene";
            drp.smallImageKey = "smyle";
            drp.smallImageText = "About to begin...";
		}


        Discord_UpdatePresence(&drp);

        Sleep(15000);
    }
}

void CDiscord::Shutdown()
{
    Discord_Shutdown();
}