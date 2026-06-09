#include "CWeapons.h"


tWeaponParse oWeaponParse = nullptr;
SafetyHookInline g_WeaponParseHook;

char __fastcall hkWeaponParse(
    void* pThis,
    void*,
    void* property)
{
    char ret = oWeaponParse(pThis, property);

    CWeaponInfo* pWeapon = (CWeaponInfo*)pThis;

    if (pWeapon->vtable == (void*)WEAPON_VTABLE)
    {
        /*
		// one-hit
        pWeapon->fMaxFireRange = 1000.0f;
        pWeapon->nClipAmmo = 999;
        pWeapon->nMaxShots = 999;

        printf("ONE HIT KILL ACTIVATED - MaxRange: %.0f, Ammo: %d\n",
            pWeapon->fMaxFireRange, pWeapon->nClipAmmo);
        */
    }

    return ret;
}

namespace CWeapon
{
    // void SetOneHitKill(bool enabled)
    // {
    //     CWeaponInfo* pWeapon = (CWeaponInfo*)0x6AB5CC;
    //     if (enabled)
    //     {
    //         pWeapon->fMaxFireRange = 1000.0f;
    //         pWeapon->nClipAmmo = 999;
    //         pWeapon->nMaxShots = 999;
    //     }
    //     else
    //     {
    //         pWeapon->fMaxFireRange = 100.0f; // Valor original aproximado
    //         pWeapon->nClipAmmo = 30;          // Valor original aproximado
    //         pWeapon->nMaxShots = 120;        // Valor original aproximado
    //     }
    // }

    int GetCurrentWeapon()
    {
        int weaponid = *reinterpret_cast<int*>(0x4C5A90);
        return weaponid;
    }

    void InstallHook()
    {
        g_WeaponParseHook = safetyhook::create_inline(
            (void*)0x442310,
            (void*)&hkWeaponParse);

        oWeaponParse =
            g_WeaponParseHook.original<tWeaponParse>();
    }
}