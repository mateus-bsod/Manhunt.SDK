#include "../framework.h"
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

void InstallWeaponHook()
{
    g_WeaponParseHook = safetyhook::create_inline(
        (void*)0x442310,
        (void*)&hkWeaponParse);

    oWeaponParse =
        g_WeaponParseHook.original<tWeaponParse>();
}