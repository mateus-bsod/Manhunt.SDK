#pragma once


#define WEAPON_VTABLE 0x6AB5CC

#pragma pack(push, 1)
struct CWeaponInfo
{
    void* vtable;                       // 0x00
    char pad_0004[0x54 - 0x04];         // 0x04 - 0x54
    float fMinFireRange;                // 0x54
    float fMaxFireRange;                // 0x58
    float fMaxFireRangeHitProb;         // 0x5C
    char pad_0060[0x68 - 0x60];         // 0x60 - 0x68
    int nMaxClips;                      // 0x68 (v2 + 26)
    int nClipAmmo;                      // 0x6C (v2 + 27)
    int nMaxShots;                      // 0x70 (v2 + 28)
};
#pragma pack(pop)

typedef char(__thiscall* tWeaponParse)(
    void* pThis,
    void* property);

#ifndef C_WEAPON_H
#define C_WEAPON_H
    extern tWeaponParse oWeaponParse;
    extern SafetyHookInline g_WeaponParseHook;
#endif

char __fastcall hkWeaponParse(
    void* pThis,
    void*,
    void* property);

void InstallWeaponHook();