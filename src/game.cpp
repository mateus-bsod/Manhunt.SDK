#include "game.h"
#include "sdk.h"

void Manhunt::Debug::ToggleScreenCalibLines(bool state)
{
    *reinterpret_cast<int*>(0x7CF09C) =
        state ? 1 : 0;
}

int Manhunt::Debug::GetScreenCalibLines()
{
    const int state = *reinterpret_cast<int*>(0x7CF09C);
    return state;
}

void Manhunt::Debug::ToggleTexCacheFix(bool state)
{
    *reinterpret_cast<int*>(0x7CF28C) =
        state ? 1 : 0;
}

int Manhunt::Debug::GetTexCacheFix()
{
    return *reinterpret_cast<int*>(0x7CF28C);
}

//

void Manhunt::Debug::ToggleZClearOnly(bool state)
{
    *reinterpret_cast<int*>(0x7CF290) =
        state ? 1 : 0;
}

int Manhunt::Debug::GetZClearOnly()
{
    return *reinterpret_cast<int*>(0x7CF290);
}

//

void Manhunt::Debug::ToggleFxMode(bool state)
{
    *reinterpret_cast<int*>(0x7CF0F0) =
        state ? 1 : 0;
}

int Manhunt::Debug::GetFxMode()
{
    return *reinterpret_cast<int*>(0x7CF0F0);
}

//

void Manhunt::Debug::ToggleFxModeAA(bool state)
{
    *reinterpret_cast<int*>(0x7CF0F4) =
        state ? 1 : 0;
}

int Manhunt::Debug::GetFxModeAA()
{
    return *reinterpret_cast<int*>(0x7CF0F4);
}

//

void Manhunt::Debug::ToggleFxArtFilter(bool state)
{
    *reinterpret_cast<int*>(0x7CF110) =
        state ? 1 : 0;
}

int Manhunt::Debug::GetFxArtFilter()
{
    return *reinterpret_cast<int*>(0x7CF110);
}

//

void Manhunt::Debug::ToggleFxDrug(bool state)
{
    *reinterpret_cast<int*>(0x7CF1E8) =
        state ? 1 : 0;
}

int Manhunt::Debug::GetFxDrug()
{
    return *reinterpret_cast<int*>(0x7CF1E8);
}

//

void Manhunt::Debug::ToggleSlowMotion(bool state)
{
    *reinterpret_cast<int*>(0x7D3518) =
        state ? 1 : 0;
}

int Manhunt::Debug::GetSlowMotion()
{
    return *reinterpret_cast<int*>(0x7D3518);
}

//

void Manhunt::Debug::ToggleDisableHunters(bool state)
{
    *reinterpret_cast<int*>(0x6A94C8) =
        state ? 1 : 0;
}

int Manhunt::Debug::GetDisableHunters()
{
    return *reinterpret_cast<int*>(0x6A94C8);
}

//

void Manhunt::Debug::ToggleInventoryInfo(bool state)
{
    *reinterpret_cast<int*>(0x7C9B20) =
        state ? 1 : 0;
}

int Manhunt::Debug::GetInventoryInfo()
{
    return *reinterpret_cast<int*>(0x7C9B20);
}

int Manhunt::PlayerState() {

	const int in_game = *reinterpret_cast<float*>(0x7D34F8); // dword_7D34F8
	switch (in_game) {
		case 0: return PLAYER_MENU;
		case 1: return PLAYER_CUTSCENE;
		case 2: return PLAYER_INGAME;
	}
	return PLAYER_INVALID;
}

void Manhunt::KillPlayer() // or [ sub_4BCCB0 ]
{
	Call<0x5EE9A0>();
}

void Manhunt::TogglePlayerGodMode()
{
	Call<0x5EE4F0>();
}

//

void Manhunt::ToggleMemInfo(bool state)
{
    *reinterpret_cast<int*>(0x7CF288) = 
        state ? 1 : 0;
}

void Manhunt::ToggleFPS(bool state)
{
    *reinterpret_cast<int*>(0x7CF284) = 
        state ? 1 : 0;
}

void ToggleHUD(bool state)
{
    *reinterpret_cast<int*>(0x7CF0A0) = 
        state ? 1 : 0;
}

void ToggleSlowMotion(bool state)
{
    *reinterpret_cast<int*>(0x7D3518) =
        state ? 1 : 0;
}

void DisableHunters(bool state)
{
    *reinterpret_cast<int*>(0x6A94C8) =
        state ? 1 : 0;
}


//

void Manhunt::SetPlayerCameraMode(CAMERA_MODE mode)
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

CAMERA_MODE Manhunt::GetPlayerCameraMode()
{
    int& gCameraMode = *reinterpret_cast<int*>(0x715BB0);
    int& gCameraMode2 = *reinterpret_cast<int*>(0x715BB4);

    if (!gCameraMode && !gCameraMode2) return CAMERA_MODE_FIRST_PERSON;
    else if (gCameraMode && !gCameraMode2) return CAMERA_MODE_FLYMODE;
    else if (gCameraMode && gCameraMode2) return CAMERA_MODE_THIRD_PERSON;
    return CAMERA_MODE_INVALID;
}

// visual

typedef void(__cdecl* tGameText)(const char*);
void Manhunt::Visual::GameText(const char* text)
{
    ((tGameText)0x005E5410)(text);
}



// weapons

int GetCurrentWeapon()
{
	int weaponid = *reinterpret_cast<int*>(0x4C5A90);
	return weaponid;
}