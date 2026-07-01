//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#pragma once

#include "../../../framework.h"
#include "../entity/CPlayer.h"
#include "../entity/CEntity.h"
#include "../gameplay/CInventory.h"
#include "../core/CResourceManager.h"

enum
{
    CT_TRIPWIRE = 1,
    CT_GASOLINE = 2,
    CT_WATER = 3,
    CT_LIGHTER = 4,
    CT_CASH = 5,
    CT_TORCH = 6,
    CT_NVISION = 7,
    CT_PAINKILLERS = 8,
    CT_GFIRSTAID = 9,
    CT_YFIRSTAID = 10,
    CT_SPEEDBOOST = 11,
    CT_STRENGTHBOOS = 12,
    CT_SHOOTINGBOOS = 13,
    CT_REFLEXESBOOS = 14,
    CT_HEALTHBOOST = 15,
    CT_FISTS = 16,
    CT_KDUST = 17,
    CT_KNIFE = 18,
    CT_SHARD = 19,
    CT_BROKENBOTTLE = 20,
    CT_JURYBLADES = 21,
    CT_BOTTLE = 22,
    CT_PIPE = 23,
    CT_CLEAVER = 24,
    CT_WOODENBAR = 25,
    CT_CROWBAR = 26,
    CT_SICKLE = 27,
    CT_NIGHTSTICK = 28,
    CT_CANE = 29,
    CT_AXE = 30,
    CT_ICEPICK = 31,
    CT_MACHETE = 32,
    CT_SMALLBAT = 33,
    CT_BASEBALLBAT = 34,
    CT_WBASEBALLBAT = 35,
    CT_FIREAXE = 36,
    CT_HOCKEYSTICK = 37,
    CT_BASEBALLBATB = 38,
    CT_6SHOOTER = 39,
    CT_GLOCK = 40,
    CT_GLOCKSILENCE = 41,
    CT_GLOCKTORCH = 42,
    CT_UZI = 43,
    CT_SHOTGUN = 44,
    CT_SHOTGUNTORCH = 45,
    CT_DESERTEAGLE = 46,
    CT_COLTCOMMANDO = 47,
    CT_SNIPERRIFLE = 48,
    CT_SNIPERRIFLES = 48,
    CT_TRANQRIFLE = 49,
    CT_SAWNOFF = 50,
    CT_GRENADE = 51,
    CT_MOLOTOV = 52,
    CT_EXPMOLOTOV = 53,
    CT_TEARGAS = 54,
    CT_FLASH = 55,
    CT_BRICKHALF = 56,
    CT_FIREWORK = 57,
    CT_BAG = 58,
    CT_RAG = 59,
    CT_CHLORINE = 60,
    CT_METHS = 61,
    CT_HCC = 62,
    CT_DBEERGUY = 63,
    CT_DMERCLEADER = 64,
    CT_DSMILEY = 65,
    CT_DHUNTLORD = 66,
    CT_ELSIGHT = 67,
    CT_SSILENCER = 68,
    CT_RADIO = 69,
    CT_BARKEY = 70,
    CT_SYARDCOMB = 71,
    CT_CAMERA = 72,
    CT_BODYP1 = 73,
    CT_BODYP2 = 74,
    CT_PRECKEY = 75,
    CT_PRECCARD = 76,
    CT_PRECDOCS = 77,
    CT_PHARMHAND = 78,
    CT_ESTGKEY = 79,
    CT_ESTAKEY = 80,
    CT_DOLL = 81,
    CT_ANTIDOTE = 82,
    CT_KEY = 83,
    CT_CHAINSAW = 88,
    CT_NAILGUN = 89,
    CT_WIRE = 90,
    CT_CAN = 91,
    CT_WOODENSPIKE = 92,
    CT_PIGSYSHARD = 94,
    CT_PIGSYWIRE = 95,
    CT_PIGSYSPIKE = 96,
    CT_HAMMER = 97,
    CT_DOLL1 = 98,
    CT_DOLL2 = 99,
    CT_DOLL3 = 100,
    CT_HEAD = 101,
    CT_AMMONAILS = 102,
    CT_AMMOSHOTGUN = 103,
    CT_AMMOPISTOL = 104,
    CT_AMMOMGUN = 105,
    CT_AMMOTRANQ = 106,
    CT_AMMOSNIPER = 107,
    CT_CHAINSAWPLAY = 108,
    CT_DVTAPE = 109,
    CT_HANDYCAM = 110,
    CT_UNRECOGNISEDCO = 111
};

#pragma pack(push, 1)
struct CWeaponInfo
{
    void* vtable;
    char pad_0004[0x54 - 0x04];
    float fMinFireRange;
    float fMaxFireRange;
    float fMaxFireRangeHitProb;
    char pad_0060[0x68 - 0x60];
    int nMaxClips;
    int nClipAmmo;
    int nMaxShots;
    char pad_0074[0x1AC - 0x74];
    int nCurrentAmmo;
};

struct CWeaponSystem
{
    void* vtable;
    DWORD unknown04;
    DWORD* pWeaponSlots;
};

struct CWeaponSlots
{
    DWORD dwSlot1;
    DWORD dwSlot2;
    DWORD dwSlot3;
    DWORD dwSlot4;
};

struct CWeaponRange { // tests
    float minRange;     // 0x69A5AC - Alcance mínimo
    float maxRange;     // 0x69A5B0 - Alcance máximo
};
#define g_WeaponRange (*(CWeaponRange*)0x69A5AC)


#pragma pack(pop)

extern int& g_CurrentSlot;

typedef char(__thiscall* tWeaponParse)(void* pThis, void* property);

class CWeapon
{
private:
    static tWeaponParse oWeaponParse;
    static SafetyHookInline g_WeaponParseHook;

    static char __fastcall hkWeaponParse(void* pThis, void* _, void* property);

public:
    static int GetCurrentWeapon();
    static const char* GetWeaponName(int weaponId);
    static DWORD CWeapon::GiveWeaponWithAmmo(CEntity* entity, int weaponId, int ammo);
    static DWORD GiveWeapon(CEntity* entity, const char* weaponName);
    static CWeaponSystem* GetWeaponSystemFromPlayer(CPlayer* pPlayer);
    static int Weapon_GetId(DWORD weapon);
    static void Weapon_Select(CEntity* entity, int slot, int unk);
    static void Weapon_ClearSlot(CEntity* entity, int slot);
    static int GetWeaponAmmo(DWORD weapon);
    static void SetWeaponAmmo(DWORD weapon, int ammo);
    static void InstallHook();
};