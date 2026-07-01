//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "../gameplay/CWeapons.h"
#include "../entity/CPlayer.h"

int& g_CurrentSlot = *reinterpret_cast<int*>(0x7C9CD0);

tWeaponParse CWeapon::oWeaponParse = nullptr;
SafetyHookInline CWeapon::g_WeaponParseHook;

char __fastcall CWeapon::hkWeaponParse(void* pThis, void* _, void* property)
{
    return oWeaponParse(pThis, property);
}

CWeaponSystem* CWeapon::GetWeaponSystemFromPlayer(CPlayer* pPlayer)
{
    if (!pPlayer) return nullptr;
    return (CWeaponSystem*)pPlayer->pWeaponSystem;
}

int CWeapon::Weapon_GetId(DWORD weapon)
{
    DWORD func = 0x4C6F10;
    int result;
    __asm
    {
        mov ecx, weapon
        call func
        mov result, eax
    }
    return result;
}

void CWeapon::Weapon_Select(CEntity* entity, int slot, int unk)
{
    DWORD func = 0x4ABE70;
    __asm
    {
        push unk
        push slot
        mov ecx, entity
        call func
    }
}

void CWeapon::Weapon_ClearSlot(CEntity* entity, int slot)
{
	DWORD func = 0x46E580;
    __asm
    {
        push slot
        mov ecx, entity
        call func
    }
}

DWORD CWeapon::GiveWeapon(CEntity* entity, const char* weapon)
{
    DWORD func = 0x45BE40;
    DWORD result;

    const char* ptr = weapon;
    DWORD pptr = (DWORD)&ptr;

    __asm
    {
        mov ecx, entity

        mov eax, func
        push pptr
        call eax

        mov result, eax
    }

    return result;
}

const char* CWeapon::GetWeaponName(int weaponId)
{       
    switch (weaponId)
    {
    case CT_FISTS: return "Fists";
    case CT_KNIFE: return "Hunt_Knife_(CT)";
    case CT_SHARD: return "Shard_(CT)";
    case CT_BROKENBOTTLE: return "Broken_Bottle_(CT)";
    case CT_BOTTLE: return "Bottle_(CT)";
    case CT_PIPE: return "Pipe_(CT)";
    case CT_CLEAVER: return "Cleaver_(CT)";
    case CT_CROWBAR: return "Crowbar_(CT)";
    case CT_SICKLE: return "Sickle_(CT)";
    case CT_NIGHTSTICK: return "NightStick_(CT)";
    case CT_CANE: return "Cane_(CT)";
    case CT_AXE: return "Axe_(CT)";
    case CT_ICEPICK: return "IcePick_(CT)";
    case CT_MACHETE: return "Machete_(CT)";
    case CT_SMALLBAT: return "Small_Bat_(CT)";
    case CT_BASEBALLBAT: return "M_B_Bat_(CT)";
    case CT_WBASEBALLBAT: return "W_B_Bat_(CT)";
    case CT_FIREAXE: return "Fire_Axe_(CT)";
    case CT_HOCKEYSTICK: return "Hockey_Stick_(CT)";
    case CT_BASEBALLBATB: return "W_B_Bat_Nails_(CT)";
    case CT_6SHOOTER: return "6Shooter_(CT)";
    case CT_GLOCK: return "Glock_(CT)";
    case CT_UZI: return "Uzi_(CT)";
    case CT_SHOTGUN: return "Shotgun_(CT)";
    case CT_SHOTGUNTORCH: return "Shotgun_Torch_(CT)";
    case CT_DESERTEAGLE: return "Desert_Eagle_(CT)";
    case CT_COLTCOMMANDO: return "C_Commando_(CT)";
    case CT_SNIPERRIFLE: return "Sniper_Rifle_(CT)";
    case CT_SAWNOFF: return "SawnOff_Shotgun_(CT)";
    case CT_GRENADE: return "Grenade_(CT)";
    case CT_MOLOTOV: return "Molotov_(CT)";
    case CT_BRICKHALF: return "Half_Brick_(CT)";
    case CT_BAG: return "Bag_(CT)";
    case CT_WIRE: return "Wire_(CT)";
    case CT_CAN: return "Can_(CT)";
    case CT_WOODENSPIKE: return "Wooden_Spike_(CT)";
    case CT_CHAINSAW: return "Chainsaw_Player_(CT)";
    case CT_NAILGUN: return "Nail_Gun_(CT)";
    case CT_HAMMER: return "Hammer_(CT)";
    case CT_HEAD: return "Severed_Head_(CT)";
    default: return nullptr;
    }
}

DWORD CWeapon::GiveWeaponWithAmmo(CEntity* entity, int weaponId, int ammo)
{
    if (weaponId < 1 || weaponId > 110) return 0;

    Console::Printf("Gave weapon %d with ammo %d", weaponId, ammo);
    Console::Printf("Gave weapon %s with ammo %d", CWeapon::GetWeaponName(weaponId), ammo);
    DWORD weapon = GiveWeapon((CEntity*)entity, CWeapon::GetWeaponName(weaponId));

    if (weapon)
    {
        CEntity* pWeapon = (CEntity*)weapon;
        if (pWeapon && pWeapon->IsValidEntity())
        {
            CInventory* pInventory = (CInventory*)weapon;
            if (pInventory->Inventory_GetItemType() == 3)
            {
                SetWeaponAmmo(weapon, ammo);
            }
        }
    }

    return weapon;
}

int CWeapon::GetCurrentWeapon()
{
    CPlayer* pPlayer = CPlayer::GetPlayer();
    if (!pPlayer) return 0;

    CWeaponSystem* pWeaponSys = CWeapon::GetWeaponSystemFromPlayer(pPlayer);
    if (!pWeaponSys || !pWeaponSys->pWeaponSlots) return 0;

    DWORD pWeapon = 0;
    switch (pPlayer->currentSlot)
    {
    case 1: pWeapon = pWeaponSys->pWeaponSlots[0]; break;
    case 2: pWeapon = pWeaponSys->pWeaponSlots[1]; break;
    case 3: pWeapon = pWeaponSys->pWeaponSlots[2]; break;
    case 4: pWeapon = pWeaponSys->pWeaponSlots[3]; break;
    default: return 0;
    }

    if (!pWeapon) return 0;

    return CWeapon::Weapon_GetId(pWeapon);
}

int CWeapon::GetWeaponAmmo(DWORD weapon)
{
    DWORD func = 0x4927E0;
    int result;
    __asm
    {
        mov ecx, weapon
        call func
        mov result, eax
    }
    return result;
}

void CWeapon::SetWeaponAmmo(DWORD weapon, int ammo)
{
    DWORD func = 0x4F8B40;
    __asm
    {
        push ammo
        mov ecx, weapon
        call func
    }
}

void CWeapon::InstallHook()
{
    g_WeaponParseHook = safetyhook::create_inline(
        (void*)0x442310,
        (void*)&CWeapon::hkWeaponParse);

    oWeaponParse = g_WeaponParseHook.original<tWeaponParse>();
}