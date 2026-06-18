//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CPlayer.h"

int& CPlayer::Player_State = *reinterpret_cast<int*>(0x7D34F8);

void CPlayer::SetPlayerCameraMode(CAMERA_MODE mode)
{
    int& gCameraMode = *reinterpret_cast<int*>(0x715BB0);
    int& gCameraMode2 = *reinterpret_cast<int*>(0x715BB4);

    switch (mode)
    {
    case CAMERA_MODE_FIRST_PERSON:
        gCameraMode = 0;
        gCameraMode2 = 0;
        break;

    case CAMERA_MODE_FLYMODE:
        gCameraMode = 1;
        gCameraMode2 = 0;
        break;

    case CAMERA_MODE_THIRD_PERSON:
        gCameraMode = 1;
        gCameraMode2 = 1;
        break;
    }
}

CAMERA_MODE CPlayer::GetPlayerCameraMode()
{
    int& gCameraMode = *reinterpret_cast<int*>(0x715BB0);
    int& gCameraMode2 = *reinterpret_cast<int*>(0x715BB4);

    if (!gCameraMode && !gCameraMode2) return CAMERA_MODE_FIRST_PERSON;
    else if (gCameraMode && !gCameraMode2) return CAMERA_MODE_FLYMODE;
    else if (gCameraMode && gCameraMode2) return CAMERA_MODE_THIRD_PERSON;
    return CAMERA_MODE_INVALID;
}

PLAYER_STATE CPlayer::GetPlayerState()
{
    switch (Player_State)
    {
    case 0: return PLAYER_MENU;
    case 1: return PLAYER_CUTSCENE;
    case 2: return PLAYER_INGAME;
    }
    return PLAYER_INVALID;
}

int CPlayer::GetPlayerMission()
{
	return *reinterpret_cast<int*>(0x75622C);
}

void CPlayer::GetMissionName(int missionid, int*& missionName, int*& subtitle)
{
    DWORD func = 0x5D6770;
    __asm {
        push subtitle
        push missionName
        push missionid
        call dword ptr[func]
        add esp, 0x0C
    }
}
void CPlayer::SetPlayerFogColor(DWORD color)
{
    DWORD& gFogColor = *reinterpret_cast<DWORD*>(0x715BB8);
    gFogColor = color;
}

DWORD CPlayer::GetPlayerFogColor()
{
    DWORD& gFogColor = *reinterpret_cast<DWORD*>(0x715BB8);
    return gFogColor;
}

DWORD* CPlayer::GetPlayerBase()
{
    __try {
        return (DWORD*)*(DWORD*)0x715B9C;
    }
    __except (1) {
        //printf("[CRASH] GetPlayerBase");
        return nullptr;
    }
}

CPlayer* CPlayer::GetPlayer()
{
    DWORD addr = *(DWORD*)0x715B9C;
    if (!addr) return nullptr;
    return (CPlayer*)addr;
}

void CPlayer::TogglePlayerHud(bool toggle)
{
    DWORD& gPlayerHud = *reinterpret_cast<DWORD*>(0x7CF0A0);
    gPlayerHud = toggle ? 1 : 0;
}

bool CPlayer::IsPlayerHudEnabled()
{
    DWORD& gPlayerHud = *reinterpret_cast<DWORD*>(0x7CF0A0);
    return gPlayerHud != 0;
}

void CPlayer::SetMenu(int menu)
{
    Call<0x5D7A40, int>(menu);
}

void CPlayer::AccumulateTime()
{
    __try {
        void* pPlayer = *(void**)0x715B9C;
        if (!pPlayer) return;

        DWORD funcAddr = 0x45BB10;

        __asm {
            mov ecx, pPlayer
            call funcAddr
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {}
}

void CPlayer::InstallHook()
{
}