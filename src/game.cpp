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