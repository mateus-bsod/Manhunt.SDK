//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CResourceManager.h"



int* CResourceManager::g_pTexture_PCMouse = (int*)0x7D37B4;
int* CResourceManager::g_pTexture_Lightcon = (int*)0x7D37B8;
int* CResourceManager::g_pTexture_Scope = (int*)0x7D37BC;
int* CResourceManager::g_pTexture_Corona = (int*)0x7D37C0;
int* CResourceManager::g_pTexture_Corona2 = (int*)0x7D37C4;
int* CResourceManager::g_pTexture_CamFx = (int*)0x7D37C8;
int* CResourceManager::g_pTexture_Halo = (int*)0x7D37CC;
int* CResourceManager::g_pTexture_Fuzz = (int*)0x7D37D0;
int* CResourceManager::g_pTexture_Noise = (int*)0x7D37D4;
int* CResourceManager::g_pTexture_Lockon = (int*)0x7D37D8;
int* CResourceManager::g_pTexture_GenPoint = (int*)0x7D37DC;
int* CResourceManager::g_pTexture_Swap = (int*)0x7D37E0;
int* CResourceManager::g_pTexture_DamageDir = (int*)0x7D37E4;
int* CResourceManager::g_pTexture_MapPlayer = (int*)0x7D37E8;
int* CResourceManager::g_pTexture_MapGoal = (int*)0x7D37EC;
int* CResourceManager::g_pTexture_MapPos = (int*)0x7D37F0;
int* CResourceManager::g_pTexture_MapDir = (int*)0x7D37F4;
int* CResourceManager::g_pTexture_MapTri = (int*)0x7D37F8;
int* CResourceManager::g_pTexture_MapNoise = (int*)0x7D37FC;
int* CResourceManager::g_pTexture_MapNoiseEnt = (int*)0x7D3800;
int* CResourceManager::g_pTexture_VideoLine = (int*)0x7D3804;
int* CResourceManager::g_pTexture_Clear = (int*)0x7D3808;
int* CResourceManager::g_pTexture_Filled = (int*)0x7D380C;
int* CResourceManager::g_pTexture_FogGTA = (int*)0x7D3810;
int* CResourceManager::g_pTexture_Newspaper01 = (int*)0x7D3814;
int* CResourceManager::g_pTexture_Newspaper02 = (int*)0x7D3818;
int* CResourceManager::g_pTexture_Newspaper03 = (int*)0x7D381C;
int* CResourceManager::g_pTexture_Newspaper04 = (int*)0x7D3820;
int* CResourceManager::g_pTexture_Cloud = (int*)0x7D3824;
int* CResourceManager::g_pTexture_Moon = (int*)0x7D3828;
int* CResourceManager::g_pTexture_Star = (int*)0x7D382C;
int* CResourceManager::g_pTexture_Rain = (int*)0x7D3830;
int* CResourceManager::g_pTexture_FogPitch = (int*)0x7D3834;
int* CResourceManager::g_pTexture_Damage01 = (int*)0x7D3838;
int* CResourceManager::g_pTexture_Damage02 = (int*)0x7D383C;
int* CResourceManager::g_pTexture_Damage03 = (int*)0x7D3840;
int* CResourceManager::g_pTexture_Damage04 = (int*)0x7D3844;
int* CResourceManager::g_pTexture_Damage05 = (int*)0x7D3848;
int* CResourceManager::g_pTexture_Damage06 = (int*)0x7D384C;
int* CResourceManager::g_pTexture_Damage07 = (int*)0x7D3850;
int* CResourceManager::g_pTexture_Damage08 = (int*)0x7D3854;
int* CResourceManager::g_pTexture_Damage09 = (int*)0x7D3858;
int* CResourceManager::g_pTexture_Damage10 = (int*)0x7D385C;
int* CResourceManager::g_pTexture_Damage11 = (int*)0x7D3860;
int* CResourceManager::g_pTexture_Damage12 = (int*)0x7D3864;
int* CResourceManager::g_pTexture_Damage13 = (int*)0x7D3868;
int* CResourceManager::g_pTexture_Damage14 = (int*)0x7D386C;
int* CResourceManager::g_pTexture_Damage15 = (int*)0x7D3870;
int* CResourceManager::g_pTexture_Damage16 = (int*)0x7D3874;
int* CResourceManager::g_pTexture_DamagePlayer = (int*)0x7D3888;
int* CResourceManager::g_pTexture_Player00 = (int*)0x7D388C;
int* CResourceManager::g_pTexture_Player01 = (int*)0x7D3890;
int* CResourceManager::g_pTexture_Player02 = (int*)0x7D3894;
int* CResourceManager::g_pTexture_Player03 = (int*)0x7D3898;
int* CResourceManager::g_pTexture_Player04 = (int*)0x7D389C;
int* CResourceManager::g_pTexture_Player05 = (int*)0x7D38A0;
int* CResourceManager::g_pTexture_Player06 = (int*)0x7D38A4;
int* CResourceManager::g_pTexture_Player07 = (int*)0x7D38A8;
int* CResourceManager::g_pTexture_Player08 = (int*)0x7D38AC;
int* CResourceManager::g_pTexture_Hunter00 = (int*)0x7D38B0;
int* CResourceManager::g_pTexture_Hunter01 = (int*)0x7D38B4;
int* CResourceManager::g_pTexture_Hunter02 = (int*)0x7D38B8;
int* CResourceManager::g_pTexture_Hunter03 = (int*)0x7D38BC;
int* CResourceManager::g_pTexture_Hunter04 = (int*)0x7D38C0;
int* CResourceManager::g_pTexture_Hunter05 = (int*)0x7D38C4;
int* CResourceManager::g_pTexture_Hunter06 = (int*)0x7D38C8;
int* CResourceManager::g_pTexture_Hunter07 = (int*)0x7D38CC;
int* CResourceManager::g_pTexture_Hunter08 = (int*)0x7D38D0;
int* CResourceManager::g_pTexture_PasphereA = (int*)0x7D38D4;
int* CResourceManager::g_pTexture_Manhunt = (int*)0x7D38D8;
int* CResourceManager::g_pTexture_Console = (int*)0x7D38DC;
int* CResourceManager::g_pTexture_Test = (int*)0x7D38E8;
int* CResourceManager::g_pTexture_Blood = (int*)0x7D38EC;
int* CResourceManager::g_pTexture_Blood2 = (int*)0x7D38F0;
int* CResourceManager::g_pTexture_Blood3 = (int*)0x7D38F4;
int* CResourceManager::g_pTexture_BloodDead = (int*)0x7D38F8;
int* CResourceManager::g_pTexture_Melee = (int*)0x7D38FC;
int* CResourceManager::g_pTexture_Explos = (int*)0x7D3900;
int* CResourceManager::g_pTexture_Fluid = (int*)0x7D3904;
int* CResourceManager::g_pTexture_BH_Wood = (int*)0x7D3908;
int* CResourceManager::g_pTexture_BH_Glass = (int*)0x7D390C;
int* CResourceManager::g_pTexture_BH_Metal = (int*)0x7D3910;
int* CResourceManager::g_pTexture_BH_Stone = (int*)0x7D3914;
int* CResourceManager::g_pTexture_BH_Fabric = (int*)0x7D3918;
int* CResourceManager::g_pTexture_InvStrap = (int*)0x7D391C;
int* CResourceManager::g_pTexture_HS_Bar = (int*)0x7D3920;
int* CResourceManager::g_pTexture_HS_BarFill = (int*)0x7D3924;
int* CResourceManager::g_pTexture_ManTri = (int*)0x7D3928;
int* CResourceManager::g_pTexture_ManSneak = (int*)0x7D392C;
int* CResourceManager::g_pTexture_ManRun = (int*)0x7D3930;
int* CResourceManager::g_pTexture_ManPickup = (int*)0x7D3934;
int* CResourceManager::g_pTexture_ManDrop = (int*)0x7D3938;
int* CResourceManager::g_pTexture_ManSquashSt = (int*)0x7D393C;
int* CResourceManager::g_pTexture_ManSquashEn = (int*)0x7D3940;
int* CResourceManager::g_pTexture_ManFollow = (int*)0x7D3944;
int* CResourceManager::g_pTexture_ManStop = (int*)0x7D3948;
int* CResourceManager::g_pTexture_ManUse = (int*)0x7D394C;
int* CResourceManager::g_pTexture_ManKick = (int*)0x7D3950;
int* CResourceManager::g_pTexture_Radar = (int*)0x7D3954;
int* CResourceManager::g_pTexture_Empty = (int*)0x7D3958;
int* CResourceManager::g_pTexture_NA = (int*)0x7D395C;
int* CResourceManager::g_pTexture_Fists = (int*)0x7D3960;
int* CResourceManager::g_pTexture_Knife = (int*)0x7D3964;
int* CResourceManager::g_pTexture_Shard = (int*)0x7D3968;
int* CResourceManager::g_pTexture_Bottle = (int*)0x7D396C;
int* CResourceManager::g_pTexture_Pipe = (int*)0x7D3970;
int* CResourceManager::g_pTexture_Cleaver = (int*)0x7D3974;
int* CResourceManager::g_pTexture_Crowbar = (int*)0x7D3978;
int* CResourceManager::g_pTexture_Sickle = (int*)0x7D397C;
int* CResourceManager::g_pTexture_Nightstick = (int*)0x7D3980;
int* CResourceManager::g_pTexture_Cane = (int*)0x7D3984;
int* CResourceManager::g_pTexture_Unknown1 = (int*)0x7D3988;
int* CResourceManager::g_pTexture_IcePick = (int*)0x7D398C;
int* CResourceManager::g_pTexture_Machete = (int*)0x7D3990;
int* CResourceManager::g_pTexture_SmallBat = (int*)0x7D3994;
int* CResourceManager::g_pTexture_Hammer = (int*)0x7D3998;
int* CResourceManager::g_pTexture_Baseball = (int*)0x7D399C;
int* CResourceManager::g_pTexture_WBaseball = (int*)0x7D39A0;
int* CResourceManager::g_pTexture_BatBlades = (int*)0x7D39A8;
int* CResourceManager::g_pTexture_Revolver = (int*)0x7D39AC;
int* CResourceManager::g_pTexture_Glock = (int*)0x7D39B0;
int* CResourceManager::g_pTexture_Unknown2 = (int*)0x7D39B4;
int* CResourceManager::g_pTexture_Shotgun = (int*)0x7D39B8;
int* CResourceManager::g_pTexture_ShotgunLamp = (int*)0x7D39BC;
int* CResourceManager::g_pTexture_Desert = (int*)0x7D39C0;
int* CResourceManager::g_pTexture_ColtCom = (int*)0x7D39C4;
int* CResourceManager::g_pTexture_Sniper = (int*)0x7D39C8;
int* CResourceManager::g_pTexture_TranqRifle = (int*)0x7D39CC;
int* CResourceManager::g_pTexture_SawnOff = (int*)0x7D39D0;
int* CResourceManager::g_pTexture_Brick = (int*)0x7D39D4;
int* CResourceManager::g_pTexture_Unknown3 = (int*)0x7D39D8;
int* CResourceManager::g_pTexture_Head = (int*)0x7D39DC;
int* CResourceManager::g_pTexture_Chainsaw = (int*)0x7D39E0;
int* CResourceManager::g_pTexture_Nailgun = (int*)0x7D39E4;
int* CResourceManager::g_pTexture_Wire = (int*)0x7D39E8;
int* CResourceManager::g_pTexture_Unknown4 = (int*)0x7D39EC;
int* CResourceManager::g_pTexture_WoodSpike = (int*)0x7D39F0;
int* CResourceManager::g_pTexture_SniperSil = (int*)0x7D39F4;
int* CResourceManager::g_pTexture_ShardPig = (int*)0x7D39F8;
int* CResourceManager::g_pTexture_WirePig = (int*)0x7D39FC;

WORD CResourceManager::word_7C9B7C[128] = { 0 };
int& CResourceManager::dword_7C9C80 = *(int*)0x7C9C80;
int& CResourceManager::dword_7C9B78 = *(int*)0x7C9B78;

CResourceManager::tLoadTexture CResourceManager::oLoadTexture = (tLoadTexture)0x62F660;
SafetyHookInline CResourceManager::g_LoadTextureHook;

CResourceManager::tTexturesLoad CResourceManager::oTexturesLoad = nullptr;
SafetyHookInline CResourceManager::g_TexturesLoadHook;

CResourceManager::tResourceLoad CResourceManager::oResourceLoad = nullptr;
SafetyHookInline CResourceManager::g_ResourceLoadHook;

CResourceManager::tGetWeaponIcon CResourceManager::oGetWeaponIcon = nullptr;
SafetyHookInline CResourceManager::g_GetWeaponIconHook;

CResourceManager::tGetWeaponKeyName CResourceManager::GetWeaponKeyName = (tGetWeaponKeyName)0x4C5870;
CResourceManager::tStringCopyWide CResourceManager::StringCopyWide = (tStringCopyWide)0x5FC150;

//tLoadPlayerModel CResourceManager::oLoadPlayerModel = nullptr;
//SafetyHookInline CResourceManager::g_LoadPlayerModelHook;

int CResourceManager::g_PlaceholderTexture[4] = { 0, 0, 0, 0 };
const char* CResourceManager::aFeTexDict = "(FE tex. dict.) \"";
const char* CResourceManager::aQuote = "\"";
char CResourceManager::g_ErrorBuffer[512];

const CResourceManager::TextureEntry CResourceManager::g_Textures[] = {
    { g_pTexture_PCMouse, "pcmouse", "pcmousem", true },
    { g_pTexture_Lightcon, "lightcon", "lightconm", true },
    { g_pTexture_Scope, "scope", "scopem", true },
    { g_pTexture_Corona, "corona", "coronam", true },
    { g_pTexture_Corona2, "corona2", nullptr, false },
    { g_pTexture_CamFx, "cam_fx", "cam_fxm", true },
    { g_pTexture_Halo, "halo", nullptr, false },
    { g_pTexture_Fuzz, "fuzz", nullptr, false },
    { g_pTexture_Noise, "noise", "noisem", true },
    { g_pTexture_Lockon, "lockon", "lockonm", true },
    { g_pTexture_GenPoint, "gen_point", "gen_pointm", true },
    { g_pTexture_Swap, "swap", nullptr, false },
    { g_pTexture_DamageDir, "damagedir", nullptr, false },
    { g_pTexture_MapPlayer, "mapplayer", "mapplayerm", true },
    { g_pTexture_MapGoal, "mapgoal", "mapgoalm", true },
    { g_pTexture_MapPos, "mappos", "mapposm", true },
    { g_pTexture_MapDir, "mapdir", "mapdirm", true },
    { g_pTexture_MapTri, "maptri", "maptrim", true },
    { g_pTexture_MapNoise, "mapnoise", "mapnoisem", true },
    { g_pTexture_MapNoiseEnt, "mapnoiseent", nullptr, false },
    { g_pTexture_VideoLine, "videoline", nullptr, false },
    { g_pTexture_Clear, "clear", "clearm", true },
    { g_pTexture_Filled, "filled", nullptr, false },
    { g_pTexture_FogGTA, "foggta", nullptr, false },
    { g_pTexture_Newspaper01, "newspaper01", nullptr, false },
    { g_pTexture_Newspaper02, "newspaper02", nullptr, false },
    { g_pTexture_Newspaper03, "newspaper03", "newspaper03_A", true },
    { g_pTexture_Newspaper04, "newspaper04", "newspaper04_A", true },
    { g_pTexture_Cloud, "cloud", "cloudm", true },
    { g_pTexture_Moon, "moon", nullptr, false },
    { g_pTexture_Star, "star", nullptr, false },
    { g_pTexture_Rain, "rain", "rainm", true },
    { g_pTexture_FogPitch, "fogptch", "fogptchm", true },
    { g_pTexture_Damage01, "damage01", nullptr, false },
    { g_pTexture_Damage02, "damage02", nullptr, false },
    { g_pTexture_Damage03, "damage03", nullptr, false },
    { g_pTexture_Damage04, "damage04", nullptr, false },
    { g_pTexture_Damage05, "damage05", nullptr, false },
    { g_pTexture_Damage06, "damage06", nullptr, false },
    { g_pTexture_Damage07, "damage07", nullptr, false },
    { g_pTexture_Damage08, "damage08", nullptr, false },
    { g_pTexture_Damage09, "damage09", nullptr, false },
    { g_pTexture_Damage10, "damage10", nullptr, false },
    { g_pTexture_Damage11, "damage11", nullptr, false },
    { g_pTexture_Damage12, "damage12", nullptr, false },
    { g_pTexture_Damage13, "damage13", nullptr, false },
    { g_pTexture_Damage14, "damage14", nullptr, false },
    { g_pTexture_Damage15, "damage15", nullptr, false },
    { g_pTexture_Damage16, "damage16", nullptr, false },
    { g_pTexture_DamagePlayer, "damageplayer", nullptr, false },
    { g_pTexture_Player00, "player00", "player00m", true },
    { g_pTexture_Player01, "player01", "player01m", true },
    { g_pTexture_Player02, "player02", "player02m", true },
    { g_pTexture_Player03, "player03", "player03m", true },
    { g_pTexture_Player04, "player04", "player04m", true },
    { g_pTexture_Player05, "player05", "player05m", true },
    { g_pTexture_Player06, "player06", "player06m", true },
    { g_pTexture_Player07, "player07", "player07m", true },
    { g_pTexture_Player08, "player08", "player08m", true },
    { g_pTexture_Hunter00, "hunter00", "hunter00m", true },
    { g_pTexture_Hunter01, "hunter01", "hunter01m", true },
    { g_pTexture_Hunter02, "hunter02", "hunter02m", true },
    { g_pTexture_Hunter03, "hunter03", "hunter03m", true },
    { g_pTexture_Hunter04, "hunter04", "hunter04m", true },
    { g_pTexture_Hunter05, "hunter05", "hunter05m", true },
    { g_pTexture_Hunter06, "hunter06", "hunter06m", true },
    { g_pTexture_Hunter07, "hunter07", "hunter07m", true },
    { g_pTexture_Hunter08, "hunter08", "hunter08m", true },
    { g_pTexture_PasphereA, "paspherea", "paspheream", true },
    { g_pTexture_Manhunt, "manhunt", "manhuntm", true },
    { g_pTexture_Console, "console", "consolem", true },
    { g_pTexture_Test, "test", "testm", true },
    { g_pTexture_Blood, "blood", "bloodm", true },
    { g_pTexture_Blood2, "blood2", "blood2m", true },
    { g_pTexture_Blood3, "blood3", "blood3m", true },
    { g_pTexture_BloodDead, "blood_dead", "blood_deadm", true },
    { g_pTexture_Melee, "melee", "meleem", true },
    { g_pTexture_Explos, "explos", "explosm", true },
    { g_pTexture_Fluid, "fluid", "fluidm", true },
    { g_pTexture_BH_Wood, "bh_wood", "bh_woodm", true },
    { g_pTexture_BH_Glass, "bh_glass", "bh_glassm", true },
    { g_pTexture_BH_Metal, "bh_metal", "bh_metalm", true },
    { g_pTexture_BH_Stone, "bh_stone", "bh_stonem", true },
    { g_pTexture_BH_Fabric, "bh_fabric", "bh_fabricm", true },
    { g_pTexture_InvStrap, "invstrap", "invstrapm", true },
    { g_pTexture_HS_Bar, "hs_bar", "hs_barm", true },
    { g_pTexture_HS_BarFill, "hs_barfill", nullptr, false },
    { g_pTexture_ManTri, "mantri", "mantrim", true },
    { g_pTexture_ManSneak, "mansneak", "mansneakm", true },
    { g_pTexture_ManRun, "manrun", "manrunm", true },
    { g_pTexture_ManPickup, "manpickup", "manpickupm", true },
    { g_pTexture_ManDrop, "mandrop", "mandropm", true },
    { g_pTexture_ManSquashSt, "mansquashst", "mansquashstm", true },
    { g_pTexture_ManSquashEn, "mansquashen", "mansquashenm", true },
    { g_pTexture_ManFollow, "manFollow", "manFollowm", true },
    { g_pTexture_ManStop, "manStop", "manStopm", true },
    { g_pTexture_ManUse, "manUse", "manUsem", true },
    { g_pTexture_ManKick, "manKick", "manKickm", true },
    { g_pTexture_Radar, "radar", "radarm", true },
    { g_pTexture_Empty, "_empty", nullptr, false },
    { g_pTexture_NA, "na", nullptr, false },
    { g_pTexture_Fists, "fists", nullptr, false },
    { g_pTexture_Knife, "knife", nullptr, false },
    { g_pTexture_Shard, "shard", nullptr, false },
    { g_pTexture_Bottle, "bottle", nullptr, false },
    { g_pTexture_Pipe, "pipe", nullptr, false },
    { g_pTexture_Cleaver, "cleaver", nullptr, false },
    { g_pTexture_Crowbar, "crowbar", nullptr, false },
    { g_pTexture_Sickle, "sickle", nullptr, false },
    { g_pTexture_Nightstick, "nightstick", nullptr, false },
    { g_pTexture_Cane, "cane", nullptr, false },
    { g_pTexture_Unknown1, (const char*)0x7CDDFF, nullptr, false },
    { g_pTexture_IcePick, "icepick", nullptr, false },
    { g_pTexture_Machete, "machete", nullptr, false },
    { g_pTexture_SmallBat, "smallbat", nullptr, false },
    { g_pTexture_Hammer, "hammer", nullptr, false },
    { g_pTexture_Baseball, "baseball", nullptr, false },
    { g_pTexture_WBaseball, "wbaseball", nullptr, false },
    { g_pTexture_BatBlades, "batblades", nullptr, false },
    { g_pTexture_Revolver, "revolver", nullptr, false },
    { g_pTexture_Glock, "glock", nullptr, false },
    { g_pTexture_Unknown2, (const char*)0x7CDE5F, nullptr, false },
    { g_pTexture_Shotgun, "shotgun", nullptr, false },
    { g_pTexture_ShotgunLamp, "shotgunlamp", nullptr, false },
    { g_pTexture_Desert, "desert", nullptr, false },
    { g_pTexture_ColtCom, "coltcom", nullptr, false },
    { g_pTexture_Sniper, "sniper", nullptr, false },
    { g_pTexture_TranqRifle, "tranqrifle", nullptr, false },
    { g_pTexture_SawnOff, "sawnoff", nullptr, false },
    { g_pTexture_Brick, "brick", nullptr, false },
    { g_pTexture_Unknown3, (const char*)0x7CDEAB, nullptr, false },
    { g_pTexture_Head, "head", nullptr, false },
    { g_pTexture_Chainsaw, "chainsaw", nullptr, false },
    { g_pTexture_Nailgun, "nailgun", nullptr, false },
    { g_pTexture_Wire, "wire", nullptr, false },
    { g_pTexture_Unknown4, (const char*)0x7CDED3, nullptr, false },
    { g_pTexture_WoodSpike, "woodspike", nullptr, false },
    { g_pTexture_SniperSil, "snipersil", nullptr, false },
    { g_pTexture_ShardPig, "shardpig", nullptr, false },
    { g_pTexture_WirePig, "wirepig", nullptr, false },
};

const CResourceManager::ResourceEntry CResourceManager::g_Resources[] = {
    { (void*)0x739474, "./levels/global/data/", (void*)0x820E18 },
    { (void*)0x73947C, "global/collisions/", (void*)0x820E24 },
    { (void*)0x739484, "global/textures/", (void*)0x820E30 },
    { (void*)0x73948C, "./levels/global/animations/", (void*)0x820E3C },
    { (void*)0x739494, "global/models/", (void*)0x820E48 },
    { (void*)0x73949C, "global/pak/", (void*)0x820E54 },
    { (void*)0x7394A4, "./levels/", (void*)0x820E60 },
    { (void*)0x7394AC, "Scripts/", (void*)0x820E6C },
    { (void*)0x7394B4, "./ScreenShots/", (void*)0x820E78 },
    { (void*)0x7394BC, "aiTypeData.ini", (void*)0x820E84 },
    { (void*)0x7394C4, "Communications.ini", (void*)0x820E90 },
    { (void*)0x7394CC, "aiTest.ini", (void*)0x820E9C },
    { (void*)0x7394D4, "AnimTest.ini", (void*)0x820EA8 },
    { (void*)0x7394DC, "entityTypeData.ini", (void*)0x820EB4 },
    { (void*)0x7394E4, "physicsTypeData.ini", (void*)0x820EC0 },
    { (void*)0x7394EC, "navTypeData.ini", (void*)0x820ECC },
    { (void*)0x7394F4, "collisions.col", (void*)0x820ED8 },
    { (void*)0x7394FC, "entity.inst", (void*)0x820EE4 },
    { (void*)0x739504, "entity2.inst", (void*)0x820EF0 },
    { (void*)0x73950C, "mapAI.grf", (void*)0x820EFC },
    { (void*)0x739514, "sniper.grf", (void*)0x820F08 },
    { (void*)0x73951C, "AISounds.ini", (void*)0x820F14 },
    { (void*)0x739524, "EntityStateSounds.ini", (void*)0x820F20 },
    { (void*)0x73952C, "WeaponTypeData.ini", (void*)0x820F2C },
    { (void*)0x739534, "ShotTypeData.ini", (void*)0x820F38 },
    { (void*)0x73953C, ".mls", (void*)0x820F44 },
    { (void*)0x739544, "levelSetup.ini", (void*)0x820F50 },
    { (void*)0x73954C, "splines.ini", (void*)0x820F5C },
    { (void*)0x739554, "/spl/", (void*)0x820F68 },
    { (void*)0x73955C, ".spl", (void*)0x820F74 },
    { (void*)0x739564, "./levels/global/tvp/", (void*)0x820F80 },
    { (void*)0x73956C, "TimedVectorPairs.ini", (void*)0x820F8C },
    { (void*)0x739574, ".ifp", (void*)0x820F98 },
    { (void*)0x73957C, "AllAnims", (void*)0x820FA4 },
    { (void*)0x739584, "ParticleEffects.INI", (void*)0x820FB0 },
    { (void*)0x73958C, "MODELSPS2.TXD", (void*)0x820FBC },
    { (void*)0x739594, "MODELSPS2.DFF", (void*)0x820FC8 },
    { (void*)0x73959C, "SPLINES.SPL", (void*)0x820FD4 },
    { (void*)0x7395A4, "./levels/global/GAME.SCC", (void*)0x820FE0 },
    { (void*)0x7395AC, "TOC.TXT", (void*)0x820FEC },
    { (void*)0x7395B4, "./levels/global/data/MAT.BIN", (void*)0x820FF8 },
    { (void*)0x7395BC, "./levels/global", (void*)0x821004 },
    { (void*)0x7395C4, "/global/pak/GMODELS.DFF", (void*)0x821010 },
    { (void*)0x7395CC, "/global/pak/GMODELS.TXD", (void*)0x82101C },
    { (void*)0x7395D4, "./levels/global/WEATHER.INI", (void*)0x821028 },
    { (void*)0x7395DC, "/global/charpak/BUN_PC.DFF", (void*)0x821034 },
    { (void*)0x7395E4, "/global/charpak/BUN_PC.TXD", (void*)0x821040 },
    { (void*)0x7395EC, "/global/charpak/HEL_PC.DFF", (void*)0x82104C },
    { (void*)0x7395F4, "/global/charpak/HEL_PC.TXD", (void*)0x821058 },
    { (void*)0x7395FC, "/global/charpak/PIG_PC.DFF", (void*)0x821064 },
    { (void*)0x739604, "/global/charpak/PIG_PC.TXD", (void*)0x821070 },
    { (void*)0x73960C, "/global/charpak/TRMP_PC.DFF", (void*)0x82107C },
    { (void*)0x739614, "/global/charpak/TRMP_PC.TXD", (void*)0x821088 },
    { (void*)0x73961C, "/global/charpak/CASH_PC.DFF", (void*)0x821094 },
    { (void*)0x739624, "/global/charpak/CASH_PC.TXD", (void*)0x8210A0 },
    { (void*)0x73962C, "./levels/global/SFX/SFX_PC.txd", (void*)0x8210AC },
    { (void*)0x739634, "/global/sfx/MH_FX_PC.FXP", (void*)0x8210B8 },
    { (void*)0x73963C, "/global/sfx/MH_FX_PC.TXD", (void*)0x8210C4 },
    { (void*)0x739644, "\\Manhunt User Files", (void*)0x8210D0 },
    { (void*)0x73964C, "\\SaveGames", (void*)0x8210DC },
    { (void*)0x739654, ".\\levels\\global\\data\\ManHunt.Pak", (void*)0x8210E8 },
    { (void*)0x73965C, "\\Settings.dat", (void*)0x8210F4 },
    { (void*)0x739664, "GAME.GXT", (void*)0x821100 },
    { (void*)0x73966C, "GAME_GER.GXT", (void*)0x82110C },
    { (void*)0x739674, "GAME_FRE.GXT", (void*)0x821118 },
    { (void*)0x73967C, "GAME_ITA.GXT", (void*)0x821124 },
    { (void*)0x739684, "GAME_SPA.GXT", (void*)0x821130 },
    { (void*)0x73968C, "pictures/title/TITLE_PC.TXD", (void*)0x82113C },
    { (void*)0x739694, "pictures/load/load_mod.TXD", (void*)0x821148 },
    { (void*)0x73969C, "/PICLOAD_PC.TXD", (void*)0x821154 },
    { (void*)0x7396A4, "/PICMAP_PC.TXD", (void*)0x821160 },
    { (void*)0x7396AC, "/PICMMAP_PC.TXD", (void*)0x82116C },
    { (void*)0x7396B4, "pictures/menu/BPIC1_EP.TXD", (void*)0x821178 },
    { (void*)0x7396BC, "pictures/menu/BPIC2_EP.TXD", (void*)0x821184 },
    { (void*)0x7396C4, "pictures/menu/BPIC3_EP.TXD", (void*)0x821190 },
    { (void*)0x7396CC, "pictures/menu/BPIC4_EP.TXD", (void*)0x82119C },
    { (void*)0x7396D4, "pictures/menu/BPIC5_EP.TXD", (void*)0x8211A8 },
    { (void*)0x7396DC, "pictures/menu/BPIC6_EP.TXD", (void*)0x8211B4 },
    { (void*)0x7396E4, "pictures/menu/BPIC7_EP.TXD", (void*)0x8211C0 },
    { (void*)0x7396EC, "pictures/menu/BPIC8_EP.TXD", (void*)0x8211CC },
    { (void*)0x7396F4, "pictures/menu/BPIC9_EP.TXD", (void*)0x8211D8 },
    { (void*)0x7396FC, "pictures/menu/BPIC10_EP.TXD", (void*)0x8211E4 },
    { (void*)0x739704, "pictures/menu/BPIC11_EP.TXD", (void*)0x8211F0 },
    { (void*)0x73970C, "pictures/menu/BPIC12_EP.TXD", (void*)0x8211FC },
    { (void*)0x739714, "pictures/menu/BPIC13_EP.TXD", (void*)0x821208 },
    { (void*)0x73971C, "pictures/menu/BPIC14_EP.TXD", (void*)0x821214 },
    { (void*)0x739724, "pictures/menu/BPIC15_EP.TXD", (void*)0x821220 },
    { (void*)0x73972C, "pictures/menu/BPIC16_EP.TXD", (void*)0x82122C },
    { (void*)0x739734, "pictures/menu/BPIC17_EP.TXD", (void*)0x821238 },
    { (void*)0x73973C, "pictures/menu/BPIC18_EP.TXD", (void*)0x821244 },
    { (void*)0x739744, "pictures/menu/BPIC19_EP.TXD", (void*)0x821250 },
    { (void*)0x73974C, "pictures/menu/BPIC20_EP.TXD", (void*)0x82125C },
    { (void*)0x739754, "pictures/menu/MAIN_EP.TXD", (void*)0x821268 },
    { (void*)0x73975C, "pictures/menu/SCENE_EP.TXD", (void*)0x821274 },
    { (void*)0x739764, "pictures/menu/SET_EP.TXD", (void*)0x821280 },
    { (void*)0x73976C, "pictures/menu/SET_A_EP.TXD", (void*)0x82128C },
    { (void*)0x739774, "pictures/menu/SET_V_EP.TXD", (void*)0x821298 },
    { (void*)0x73977C, "pictures/menu/BONUS_EP.TXD", (void*)0x8212A4 },
    { (void*)0x739784, "pictures/menu/IGAME_EP.TXD", (void*)0x8212B0 },
    { (void*)0x73978C, "pictures/menu/TESTP_EP.TXD", (void*)0x8212BC },
    { (void*)0x739794, "pictures/menu/CTRL_EP.TXD", (void*)0x8212C8 },
    { (void*)0x73979C, "pictures/menu/DEF_EP.TXD", (void*)0x8212D4 },
    { (void*)0x7397A4, "pictures/frontend_pc.txd", (void*)0x8212E0 },
    { (void*)0x7397AC, "initscripts/fonts/FONT.DAT", (void*)0x8212EC },
    { (void*)0x7397B4, "initscripts/frontend/settings.txt", (void*)0x8212F8 },
    { (void*)0x7397BC, "initscripts/frontend/_charJap.txt", (void*)0x821304 },
    { (void*)0x7397C4, "initscripts/frontend/_key1.txt", (void*)0x821310 },
    { (void*)0x7397CC, "initscripts/frontend/_key2.txt", (void*)0x82131C },
    { (void*)0x7397D4, "initscripts/frontend/_key3.txt", (void*)0x821328 },
    { (void*)0x7397DC, "initscripts/levels/levels.txt", (void*)0x821334 },
    { (void*)0x7397E4, "initscripts/frontend/languages/_eng.txt", (void*)0x821340 },
    { (void*)0x7397EC, "initscripts/fx/fxsphere.txt", (void*)0x82134C },
    { (void*)0x7397F4, "levels/ps2files/ps2view.ico", (void*)0x821358 },
    { (void*)0x7397FC, "levels/ps2files/ps2copy.ico", (void*)0x821364 },
    { (void*)0x739804, "levels/ps2files/ps2del.ico", (void*)0x821370 },
    { (void*)0x73980C, "pictures/misc/damage.bmp", (void*)0x82137C },
    { (void*)0x739814, "pictures/menu/SHARED/calib/CALIB.DFF", (void*)0x821388 },
    { (void*)0x73981C, "pictures/menu/font.raw", (void*)0x821394 },
    { (void*)0x739824, "pictures/menu/fontm.raw", (void*)0x8213A0 },
};

int* __cdecl CResourceManager::hkLoadTexture(int dict, const char* name)
{
    int* result = oLoadTexture(dict, name);
    if (result == NULL || result == (int*)-1) {
        Console::Printf("[LoadTexture] Missing texture: %s", name);
        return g_PlaceholderTexture;
    }
    return result;
}

int __cdecl CResourceManager::GetWeaponIcon(int weaponId, int initFlag)
{
    if (initFlag)
    {
        dword_7C9C80 = 0;
        dword_7C9B78 = 1;

        wchar_t* weaponName = (wchar_t*)GetWeaponKeyName(weaponId);
        if (weaponName)
            StringCopyWide((int)word_7C9B7C, (WORD*)weaponName);
    }

    int* result = nullptr;

    switch (weaponId)
    {
    case 16:  result = (int*)*g_pTexture_Fists; break;
    case 18:  result = (int*)*g_pTexture_Knife; break;
    case 19:  result = (int*)*g_pTexture_Shard; break;
    case 22:  result = (int*)*g_pTexture_Bottle; break;
    case 24:  result = (int*)*g_pTexture_Cleaver; break;
    case 26:  result = (int*)*g_pTexture_Crowbar; break;
    case 27:  result = (int*)*g_pTexture_Sickle; break;
    case 28:  result = (int*)*g_pTexture_Nightstick; break;
    case 30:  result = (int*)*g_pTexture_Unknown1; break;
    case 31:  result = (int*)*g_pTexture_IcePick; break;
    case 32:  result = (int*)*g_pTexture_Machete; break;
    case 33:  result = (int*)*g_pTexture_SmallBat; break;
    case 34:  result = (int*)*g_pTexture_Baseball; break;
    case 35:  result = (int*)*g_pTexture_WBaseball; break;
    case 38:  result = (int*)*g_pTexture_BatBlades; break;
    case 39:  result = (int*)*g_pTexture_Revolver; break;
    case 40:  result = (int*)*g_pTexture_Glock; break;
    case 43:  result = (int*)*g_pTexture_Unknown2; break;
    case 44:  result = (int*)*g_pTexture_Shotgun; break;
    case 45:  result = (int*)*g_pTexture_ShotgunLamp; break;
    case 46:  result = (int*)*g_pTexture_Desert; break;
    case 47:  result = (int*)*g_pTexture_ColtCom; break;
    case 48:  result = (int*)*g_pTexture_Sniper; break;
    case 49:  result = (int*)*g_pTexture_TranqRifle; break;
    case 50:  result = (int*)*g_pTexture_SawnOff; break;
    case 56:  result = (int*)*g_pTexture_Brick; break;
    case 58:  result = (int*)*g_pTexture_Unknown3; break;
    case 88:
    case 108: result = (int*)*g_pTexture_Chainsaw; break;
    case 89:  result = (int*)*g_pTexture_Nailgun; break;
    case 90:  result = (int*)*g_pTexture_Wire; break;
    case 91:  result = (int*)*g_pTexture_Unknown4; break;
    case 92:
    case 96:  result = (int*)*g_pTexture_WoodSpike; break;
    case 93:  result = (int*)*g_pTexture_Sniper; break;
    case 94:  result = (int*)*g_pTexture_ShardPig; break;
    case 95:  result = (int*)*g_pTexture_WirePig; break;
    case 97:  result = (int*)*g_pTexture_Hammer; break;
    case 101: result = (int*)*g_pTexture_Head; break;
    default:  result = (int*)*g_pTexture_NA; break;
    }

    return (int)result;
}

void CResourceManager::hkTexturesLoad()
{
    Console::Printf("[CResourceManager::hkTexturesLoad] Loading textures...");

    int v1[4];
    v1[0] = *(int*)0x7CD65F;
    v1[1] = *(int*)0x7CD663;
    v1[2] = *(int*)0x7CD667;
    *(short*)((char*)v1 + 12) = *(short*)0x7CD66B;
    *(char*)((char*)v1 + 14) = *(char*)0x7CD66D;

    __try {
        for (int i = 0; i < sizeof(g_Textures) / sizeof(g_Textures[0]); i++) {
            const TextureEntry& tex = g_Textures[i];
            *tex.pDest = (int)CVisual::Load_Texture(*(int*)0x7D366C, tex.name);

            if (!*tex.pDest) {
                strcat((char*)v1, aFeTexDict);
                strcat((char*)v1, tex.name);
                strcat((char*)v1, aQuote);
                Console::Printf("[CResourceManager::hkTexturesLoad] Failed to load texture: %s", tex.name);
            }

            if (tex.pDest == g_pTexture_InvStrap) {
                Console::Printf("[DEBUG] InvStrap loaded: *g_pTexture_InvStrap = 0x%X", *g_pTexture_InvStrap);
            }
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        Console::Printf("[CResourceManager::hkTexturesLoad] Exception!");
    }

    Console::Printf("[CResourceManager::hkTexturesLoad] Textures loaded.");
}

int CResourceManager::hkResourceLoad()
{
    Console::Printf("[ResourceLoader::hkResourceLoad] Resources Loading...");

    void* sub_4F2520 = (void*)0x4F2520;

    for (int i = 0; i < sizeof(g_Resources) / sizeof(g_Resources[0]); i++) {
        const ResourceEntry& res = g_Resources[i];
        InitializeResource(res.pDest, res.path);
        RegistryResource((FileRegistryNode*)res.registryNode, sub_4F2520, res.pDest);
    }

    Console::Printf("[ResourceLoader::hkResourceLoad] Resources Loaded!");
    return 1;
}

void CResourceManager::InitializeResource(void* dest, const char* src)
{
    Console::Printf("[ResourceLoader::InitializeResource] Initializing resource [%s]...", src);
    ((void(__thiscall*)(void*, const char*))0x4F2550)(dest, src);
}

int CResourceManager::RegistryResource(FileRegistryNode* node, void* callback, void* pathStruct)
{
    return ((int(__cdecl*)(void*, void*, FileRegistryNode*))0x6116B0)(pathStruct, callback, node);
}

int __cdecl CResourceManager::hkLoadPlayerModel(int skinType)
{

}




void CResourceManager::InstallHook()
{
    g_TexturesLoadHook = safetyhook::create_inline((void*)0x5EA540, (void*)CResourceManager::hkTexturesLoad);
    g_ResourceLoadHook = safetyhook::create_inline((void*)0x4D6500, (void*)CResourceManager::hkResourceLoad);
    oResourceLoad = g_ResourceLoadHook.original<tResourceLoad>();

    //g_LoadPlayerModelHook = safetyhook::create_inline((void*)0x437FB0, (void*)&CPlayer::hkLoadPlayerModel);
    //oLoadPlayerModel = g_LoadPlayerModelHook.original<tLoadPlayerModel>();

    g_GetWeaponIconHook = safetyhook::create_inline((void*)0x5DF9A0, (void*)CResourceManager::GetWeaponIcon);
    oGetWeaponIcon = g_GetWeaponIconHook.original<tGetWeaponIcon>();
}