#include "../../framework.h"
#include ".././game.sdk.h"

namespace CDebug
{

    void ToggleScreenCalibLines(bool state)
    {
        *reinterpret_cast<int*>(0x7CF09C) =
            state ? 1 : 0;
    }

    int GetScreenCalibLines()
    {
        const int state = *reinterpret_cast<int*>(0x7CF09C);
        return state;
    }

    void ToggleTexCacheFix(bool state)
    {
        *reinterpret_cast<int*>(0x7CF28C) =
            state ? 1 : 0;
    }

    int GetTexCacheFix()
    {
        return *reinterpret_cast<int*>(0x7CF28C);
    }

    //

    void ToggleZClearOnly(bool state)
    {
        *reinterpret_cast<int*>(0x7CF290) =
            state ? 1 : 0;
    }

    int GetZClearOnly()
    {
        return *reinterpret_cast<int*>(0x7CF290);
    }

    //

    void ToggleFxMode(bool state)
    {
        *reinterpret_cast<int*>(0x7CF0F0) =
            state ? 1 : 0;
    }

    int GetFxMode()
    {
        return *reinterpret_cast<int*>(0x7CF0F0);
    }

    //

    void ToggleFxModeAA(bool state)
    {
        *reinterpret_cast<int*>(0x7CF0F4) =
            state ? 1 : 0;
    }

    int GetFxModeAA()
    {
        return *reinterpret_cast<int*>(0x7CF0F4);
    }

    //

    void ToggleFxArtFilter(bool state)
    {
        *reinterpret_cast<int*>(0x7CF110) =
            state ? 1 : 0;
    }

    int GetFxArtFilter()
    {
        return *reinterpret_cast<int*>(0x7CF110);
    }

    //

    void ToggleFxDrug(bool state)
    {
        *reinterpret_cast<int*>(0x7CF1E8) =
            state ? 1 : 0;
    }

    int GetFxDrug()
    {
        return *reinterpret_cast<int*>(0x7CF1E8);
    }

    //



    int GetSlowMotion()
    {
        return *reinterpret_cast<int*>(0x7D3518);
    }

    //

    void ToggleDisableHunters(bool state)
    {
        *reinterpret_cast<int*>(0x6A94C8) =
            state ? 1 : 0;
    }

    int GetDisableHunters()
    {
        return *reinterpret_cast<int*>(0x6A94C8);
    }

    //

    void ToggleInventoryInfo(bool state)
    {
        *reinterpret_cast<int*>(0x7C9B20) =
            state ? 1 : 0;
    }

    int GetInventoryInfo()
    {
        return *reinterpret_cast<int*>(0x7C9B20);
    }

    void KillPlayer() // or [ sub_4BCCB0 ]
    {
        Call<0x5EE9A0>();
    }

    void TogglePlayerGodMode()
    {
        Call<0x5EE4F0>();
    }

    //

    void ToggleMemInfo(bool state)
    {
        *reinterpret_cast<int*>(0x7CF288) =
            state ? 1 : 0;
    }

    void ToggleFPS(bool state)
    {
        *reinterpret_cast<int*>(0x7CF284) =
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
}