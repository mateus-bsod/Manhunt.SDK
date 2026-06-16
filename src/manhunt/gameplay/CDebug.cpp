//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CDebug.h"

void CDebug::ToggleScreenCalibLines(bool state)
{
    *reinterpret_cast<int*>(0x7CF09C) = state ? 1 : 0;
}

int CDebug::GetScreenCalibLines()
{
    return *reinterpret_cast<int*>(0x7CF09C);
}

void CDebug::ToggleTexCacheFix(bool state)
{
    *reinterpret_cast<int*>(0x7CF28C) = state ? 1 : 0;
}

int CDebug::GetTexCacheFix()
{
    return *reinterpret_cast<int*>(0x7CF28C);
}

void CDebug::ToggleZClearOnly(bool state)
{
    *reinterpret_cast<int*>(0x7CF290) = state ? 1 : 0;
}

int CDebug::GetZClearOnly()
{
    return *reinterpret_cast<int*>(0x7CF290);
}

void CDebug::ToggleFxMode(bool state)
{
    *reinterpret_cast<int*>(0x7CF0F0) = state ? 1 : 0;
}

int CDebug::GetFxMode()
{
    return *reinterpret_cast<int*>(0x7CF0F0);
}

void CDebug::ToggleFxModeAA(bool state)
{
    *reinterpret_cast<int*>(0x7CF0F4) = state ? 1 : 0;
}

int CDebug::GetFxModeAA()
{
    return *reinterpret_cast<int*>(0x7CF0F4);
}

void CDebug::ToggleFxArtFilter(bool state)
{
    *reinterpret_cast<int*>(0x7CF110) = state ? 1 : 0;
}

int CDebug::GetFxArtFilter()
{
    return *reinterpret_cast<int*>(0x7CF110);
}

void CDebug::ToggleFxDrug(bool state)
{
    *reinterpret_cast<int*>(0x7CF1E8) = state ? 1 : 0;
}

int CDebug::GetFxDrug()
{
    return *reinterpret_cast<int*>(0x7CF1E8);
}

int CDebug::GetSlowMotion()
{
    return *reinterpret_cast<int*>(0x7D3518);
}

void CDebug::ToggleDisableHunters(bool state)
{
    *reinterpret_cast<int*>(0x6A94C8) = state ? 1 : 0;
}

int CDebug::GetDisableHunters()
{
    return *reinterpret_cast<int*>(0x6A94C8);
}

void CDebug::ToggleInventoryInfo(bool state)
{
    *reinterpret_cast<int*>(0x7C9B20) = state ? 1 : 0;
}

int CDebug::GetInventoryInfo()
{
    return *reinterpret_cast<int*>(0x7C9B20);
}

void CDebug::KillPlayer()
{
    Call<0x5EE9A0>();
}

void CDebug::TogglePlayerGodMode()
{
    Call<0x5EE4F0>();
}

void CDebug::ToggleMemInfo(bool state)
{
    *reinterpret_cast<int*>(0x7CF288) = state ? 1 : 0;
}

void CDebug::ToggleFPS(bool state)
{
    *reinterpret_cast<int*>(0x7CF284) = state ? 1 : 0;
}

void CDebug::ToggleSlowMotion(bool state)
{
    *reinterpret_cast<int*>(0x7D3518) = state ? 1 : 0;
}

void CDebug::DisableHunters(bool state)
{
    *reinterpret_cast<int*>(0x6A94C8) = state ? 1 : 0;
}