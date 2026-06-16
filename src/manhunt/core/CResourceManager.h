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
#include "../../game.sdk.h"
#include "../ui/CVisual.h"

struct FileRegistryNode {
    FileRegistryNode* next;
    void* callback;
    void* pathStruct;
};

class CResourceManager
{
private:
    
    typedef void(__thiscall* tTexturesLoad)();
    static tTexturesLoad oTexturesLoad;
    static SafetyHookInline g_TexturesLoadHook;

    typedef int(__thiscall* tResourceLoad)();
    static tResourceLoad oResourceLoad;
    static SafetyHookInline g_ResourceLoadHook;

    typedef int(__cdecl* tGetWeaponIcon)(int weaponId, int initFlag);
    static tGetWeaponIcon oGetWeaponIcon;
    static SafetyHookInline g_GetWeaponIconHook;



    typedef WORD* (__cdecl* tStringCopyWide)(int dest, WORD* src);
    static tStringCopyWide StringCopyWide;

    static int g_PlaceholderTexture[4];

    struct TextureEntry {
        int* pDest;
        const char* name;
        const char* nameAlt;
        bool dualLog;
    };

    struct ResourceEntry {
        void* pDest;
        const char* path;
        void* registryNode;
    };

    static const TextureEntry g_Textures[];
    static const ResourceEntry g_Resources[];

    static const char* aFeTexDict;
    static const char* aQuote;
    static char g_ErrorBuffer[512];

    static void hkTexturesLoad();
    static int hkResourceLoad();

public:
    typedef int* (__cdecl* tLoadTexture)(int dict, const char* name);
    static tLoadTexture oLoadTexture;
    static SafetyHookInline g_LoadTextureHook;
    static int* __cdecl hkLoadTexture(int dict, const char* name);

    typedef wchar_t* (__cdecl* tGetWeaponKeyName)(int weaponId);
    static tGetWeaponKeyName GetWeaponKeyName;

    typedef int(__cdecl* tLoadPlayerModel)(int skinType);
    static tLoadPlayerModel oLoadPlayerModel;
    static SafetyHookInline g_LoadPlayerModelHook;

    int __cdecl CResourceManager::hkLoadPlayerModel(int skinType);

    static int* g_pTexture_PCMouse;
    static int* g_pTexture_Lightcon;
    static int* g_pTexture_Scope;
    static int* g_pTexture_Corona;
    static int* g_pTexture_Corona2;
    static int* g_pTexture_CamFx;
    static int* g_pTexture_Halo;
    static int* g_pTexture_Fuzz;
    static int* g_pTexture_Noise;
    static int* g_pTexture_Lockon;
    static int* g_pTexture_GenPoint;
    static int* g_pTexture_Swap;
    static int* g_pTexture_DamageDir;
    static int* g_pTexture_MapPlayer;
    static int* g_pTexture_MapGoal;
    static int* g_pTexture_MapPos;
    static int* g_pTexture_MapDir;
    static int* g_pTexture_MapTri;
    static int* g_pTexture_MapNoise;
    static int* g_pTexture_MapNoiseEnt;
    static int* g_pTexture_VideoLine;
    static int* g_pTexture_Clear;
    static int* g_pTexture_Filled;
    static int* g_pTexture_FogGTA;
    static int* g_pTexture_Newspaper01;
    static int* g_pTexture_Newspaper02;
    static int* g_pTexture_Newspaper03;
    static int* g_pTexture_Newspaper04;
    static int* g_pTexture_Cloud;
    static int* g_pTexture_Moon;
    static int* g_pTexture_Star;
    static int* g_pTexture_Rain;
    static int* g_pTexture_FogPitch;
    static int* g_pTexture_Damage01;
    static int* g_pTexture_Damage02;
    static int* g_pTexture_Damage03;
    static int* g_pTexture_Damage04;
    static int* g_pTexture_Damage05;
    static int* g_pTexture_Damage06;
    static int* g_pTexture_Damage07;
    static int* g_pTexture_Damage08;
    static int* g_pTexture_Damage09;
    static int* g_pTexture_Damage10;
    static int* g_pTexture_Damage11;
    static int* g_pTexture_Damage12;
    static int* g_pTexture_Damage13;
    static int* g_pTexture_Damage14;
    static int* g_pTexture_Damage15;
    static int* g_pTexture_Damage16;
    static int* g_pTexture_DamagePlayer;
    static int* g_pTexture_Player00;
    static int* g_pTexture_Player01;
    static int* g_pTexture_Player02;
    static int* g_pTexture_Player03;
    static int* g_pTexture_Player04;
    static int* g_pTexture_Player05;
    static int* g_pTexture_Player06;
    static int* g_pTexture_Player07;
    static int* g_pTexture_Player08;
    static int* g_pTexture_Hunter00;
    static int* g_pTexture_Hunter01;
    static int* g_pTexture_Hunter02;
    static int* g_pTexture_Hunter03;
    static int* g_pTexture_Hunter04;
    static int* g_pTexture_Hunter05;
    static int* g_pTexture_Hunter06;
    static int* g_pTexture_Hunter07;
    static int* g_pTexture_Hunter08;
    static int* g_pTexture_PasphereA;
    static int* g_pTexture_Manhunt;
    static int* g_pTexture_Console;
    static int* g_pTexture_Test;
    static int* g_pTexture_Blood;
    static int* g_pTexture_Blood2;
    static int* g_pTexture_Blood3;
    static int* g_pTexture_BloodDead;
    static int* g_pTexture_Melee;
    static int* g_pTexture_Explos;
    static int* g_pTexture_Fluid;
    static int* g_pTexture_BH_Wood;
    static int* g_pTexture_BH_Glass;
    static int* g_pTexture_BH_Metal;
    static int* g_pTexture_BH_Stone;
    static int* g_pTexture_BH_Fabric;
    static int* g_pTexture_InvStrap;
    static int* g_pTexture_HS_Bar;
    static int* g_pTexture_HS_BarFill;
    static int* g_pTexture_ManTri;
    static int* g_pTexture_ManSneak;
    static int* g_pTexture_ManRun;
    static int* g_pTexture_ManPickup;
    static int* g_pTexture_ManDrop;
    static int* g_pTexture_ManSquashSt;
    static int* g_pTexture_ManSquashEn;
    static int* g_pTexture_ManFollow;
    static int* g_pTexture_ManStop;
    static int* g_pTexture_ManUse;
    static int* g_pTexture_ManKick;
    static int* g_pTexture_Radar;
    static int* g_pTexture_Empty;
    static int* g_pTexture_NA;
    static int* g_pTexture_Fists;
    static int* g_pTexture_Knife;
    static int* g_pTexture_Shard;
    static int* g_pTexture_Bottle;
    static int* g_pTexture_Pipe;
    static int* g_pTexture_Cleaver;
    static int* g_pTexture_Crowbar;
    static int* g_pTexture_Sickle;
    static int* g_pTexture_Nightstick;
    static int* g_pTexture_Cane;
    static int* g_pTexture_Unknown1;
    static int* g_pTexture_IcePick;
    static int* g_pTexture_Machete;
    static int* g_pTexture_SmallBat;
    static int* g_pTexture_Hammer;
    static int* g_pTexture_Baseball;
    static int* g_pTexture_WBaseball;
    static int* g_pTexture_BatBlades;
    static int* g_pTexture_Revolver;
    static int* g_pTexture_Glock;
    static int* g_pTexture_Unknown2;
    static int* g_pTexture_Shotgun;
    static int* g_pTexture_ShotgunLamp;
    static int* g_pTexture_Desert;
    static int* g_pTexture_ColtCom;
    static int* g_pTexture_Sniper;
    static int* g_pTexture_TranqRifle;
    static int* g_pTexture_SawnOff;
    static int* g_pTexture_Brick;
    static int* g_pTexture_Unknown3;
    static int* g_pTexture_Head;
    static int* g_pTexture_Chainsaw;
    static int* g_pTexture_Nailgun;
    static int* g_pTexture_Wire;
    static int* g_pTexture_Unknown4;
    static int* g_pTexture_WoodSpike;
    static int* g_pTexture_SniperSil;
    static int* g_pTexture_ShardPig;
    static int* g_pTexture_WirePig;

    static WORD word_7C9B7C[128];
    static int& dword_7C9C80;
    static int& dword_7C9B78;

    static void InitializeResource(void* dest, const char* src);
    static int RegistryResource(FileRegistryNode* node, void* callback, void* pathStruct);
    static int GetWeaponIcon(int weaponId, int initFlag);
    static void InstallHook();
};