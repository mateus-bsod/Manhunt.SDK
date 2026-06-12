#include "CResourceManager.h"

namespace CResourceManager
{
    typedef int* (__cdecl* tLoadTexture)(int dict, const char* name);
    tLoadTexture oLoadTexture = (tLoadTexture)0x62F660;
    SafetyHookInline g_LoadTextureHook;

    typedef void(__thiscall* tTexturesLoad)();
    tTexturesLoad oTexturesLoad = nullptr;
    SafetyHookInline g_TexturesLoadHook;

    typedef int(__thiscall* tResourceLoad)();
    tResourceLoad oResourceLoad = nullptr;
    SafetyHookInline g_ResourceLoadHook;

    static int g_PlaceholderTexture[4] = { 0, 0, 0, 0 };

    struct TextureEntry {
        int* pDest;
        const char* name;
        const char* nameAlt;
        bool dualLog;
    };

    static const TextureEntry g_Textures[] = {
        { (int*)0x7D37B4, "pcmouse", "pcmousem", true },
        { (int*)0x7D37B8, "lightcon", "lightconm", true },
        { (int*)0x7D37BC, "scope", "scopem", true },
        { (int*)0x7D37C0, "corona", "coronam", true },
        { (int*)0x7D37C4, "corona2", nullptr, false },
        { (int*)0x7D37C8, "cam_fx", "cam_fxm", true },
        { (int*)0x7D37CC, "halo", nullptr, false },
        { (int*)0x7D37D0, "fuzz", nullptr, false },
        { (int*)0x7D37D4, "noise", "noisem", true },
        { (int*)0x7D37D8, "lockon", "lockonm", true },
        { (int*)0x7D37DC, "gen_point", "gen_pointm", true },
        { (int*)0x7D37E0, "swap", nullptr, false },
        { (int*)0x7D37E4, "damagedir", nullptr, false },
        { (int*)0x7D37E8, "mapplayer", "mapplayerm", true },
        { (int*)0x7D37EC, "mapgoal", "mapgoalm", true },
        { (int*)0x7D37F0, "mappos", "mapposm", true },
        { (int*)0x7D37F4, "mapdir", "mapdirm", true },
        { (int*)0x7D37F8, "maptri", "maptrim", true },
        { (int*)0x7D37FC, "mapnoise", "mapnoisem", true },
        { (int*)0x7D3800, "mapnoiseent", nullptr, false },
        { (int*)0x7D3804, "videoline", nullptr, false },
        { (int*)0x7D3808, "clear", "clearm", true },
        { (int*)0x7D380C, "filled", nullptr, false },
        { (int*)0x7D3810, "foggta", nullptr, false },
        { (int*)0x7D3814, "newspaper01", nullptr, false },
        { (int*)0x7D3818, "newspaper02", nullptr, false },
        { (int*)0x7D381C, "newspaper03", "newspaper03_A", true },
        { (int*)0x7D3820, "newspaper04", "newspaper04_A", true },
        { (int*)0x7D3824, "cloud", "cloudm", true },
        { (int*)0x7D3828, "moon", nullptr, false },
        { (int*)0x7D382C, "star", nullptr, false },
        { (int*)0x7D3830, "rain", "rainm", true },
        { (int*)0x7D3834, "fogptch", "fogptchm", true },
        { (int*)0x7D3838, "damage01", nullptr, false },
        { (int*)0x7D383C, "damage02", nullptr, false },
        { (int*)0x7D3840, "damage03", nullptr, false },
        { (int*)0x7D3844, "damage04", nullptr, false },
        { (int*)0x7D3848, "damage05", nullptr, false },
        { (int*)0x7D384C, "damage06", nullptr, false },
        { (int*)0x7D3850, "damage07", nullptr, false },
        { (int*)0x7D3854, "damage08", nullptr, false },
        { (int*)0x7D3858, "damage09", nullptr, false },
        { (int*)0x7D385C, "damage10", nullptr, false },
        { (int*)0x7D3860, "damage11", nullptr, false },
        { (int*)0x7D3864, "damage12", nullptr, false },
        { (int*)0x7D3868, "damage13", nullptr, false },
        { (int*)0x7D386C, "damage14", nullptr, false },
        { (int*)0x7D3870, "damage15", nullptr, false },
        { (int*)0x7D3874, "damage16", nullptr, false },
        { (int*)0x7D3888, "damageplayer", nullptr, false },
        { (int*)0x7D388C, "player00", "player00m", true },
        { (int*)0x7D3890, "player01", "player01m", true },
        { (int*)0x7D3894, "player02", "player02m", true },
        { (int*)0x7D3898, "player03", "player03m", true },
        { (int*)0x7D389C, "player04", "player04m", true },
        { (int*)0x7D38A0, "player05", "player05m", true },
        { (int*)0x7D38A4, "player06", "player06m", true },
        { (int*)0x7D38A8, "player07", "player07m", true },
        { (int*)0x7D38AC, "player08", "player08m", true },
        { (int*)0x7D38B0, "hunter00", "hunter00m", true },
        { (int*)0x7D38B4, "hunter01", "hunter01m", true },
        { (int*)0x7D38B8, "hunter02", "hunter02m", true },
        { (int*)0x7D38BC, "hunter03", "hunter03m", true },
        { (int*)0x7D38C0, "hunter04", "hunter04m", true },
        { (int*)0x7D38C4, "hunter05", "hunter05m", true },
        { (int*)0x7D38C8, "hunter06", "hunter06m", true },
        { (int*)0x7D38CC, "hunter07", "hunter07m", true },
        { (int*)0x7D38D0, "hunter08", "hunter08m", true },
        { (int*)0x7D38D4, "paspherea", "paspheream", true },
        { (int*)0x7D38D8, "manhunt", "manhuntm", true },
        { (int*)0x7D38DC, "console", "consolem", true },
        { (int*)0x7D38E8, "test", "testm", true },
        { (int*)0x7D38EC, "blood", "bloodm", true },
        { (int*)0x7D38F0, "blood2", "blood2m", true },
        { (int*)0x7D38F4, "blood3", "blood3m", true },
        { (int*)0x7D38F8, "blood_dead", "blood_deadm", true },
        { (int*)0x7D38FC, "melee", "meleem", true },
        { (int*)0x7D3900, "explos", "explosm", true },
        { (int*)0x7D3904, "fluid", "fluidm", true },
        { (int*)0x7D3908, "bh_wood", "bh_woodm", true },
        { (int*)0x7D390C, "bh_glass", "bh_glassm", true },
        { (int*)0x7D3910, "bh_metal", "bh_metalm", true },
        { (int*)0x7D3914, "bh_stone", "bh_stonem", true },
        { (int*)0x7D3918, "bh_fabric", "bh_fabricm", true },
        { (int*)0x7D391C, "invstrap", "invstrapm", true },
        { (int*)0x7D3920, "hs_bar", "hs_barm", true },
        { (int*)0x7D3924, "hs_barfill", nullptr, false },
        { (int*)0x7D3928, "mantri", "mantrim", true },
        { (int*)0x7D392C, "mansneak", "mansneakm", true },
        { (int*)0x7D3930, "manrun", "manrunm", true },
        { (int*)0x7D3934, "manpickup", "manpickupm", true },
        { (int*)0x7D3938, "mandrop", "mandropm", true },
        { (int*)0x7D393C, "mansquashst", "mansquashstm", true },
        { (int*)0x7D3940, "mansquashen", "mansquashenm", true },
        { (int*)0x7D3944, "manFollow", "manFollowm", true },
        { (int*)0x7D3948, "manStop", "manStopm", true },
        { (int*)0x7D394C, "manUse", "manUsem", true },
        { (int*)0x7D3950, "manKick", "manKickm", true },
        { (int*)0x7D3954, "radar", "radarm", true },
        { (int*)0x7D3958, "_empty", nullptr, false },
        { (int*)0x7D395C, "na", nullptr, false },
        { (int*)0x7D3960, "fists", nullptr, false },
        { (int*)0x7D3964, "knife", nullptr, false },
        { (int*)0x7D3968, "shard", nullptr, false },
        { (int*)0x7D396C, "bottle", nullptr, false },
        { (int*)0x7D3970, "pipe", nullptr, false },
        { (int*)0x7D3974, "cleaver", nullptr, false },
        { (int*)0x7D3978, "crowbar", nullptr, false },
        { (int*)0x7D397C, "sickle", nullptr, false },
        { (int*)0x7D3980, "nightstick", nullptr, false },
        { (int*)0x7D3984, "cane", nullptr, false },
        { (int*)0x7D3988, (const char*)0x7CDDFF, nullptr, false },
        { (int*)0x7D398C, "icepick", nullptr, false },
        { (int*)0x7D3990, "machete", nullptr, false },
        { (int*)0x7D3994, "smallbat", nullptr, false },
        { (int*)0x7D3998, "hammer", nullptr, false },
        { (int*)0x7D399C, "baseball", nullptr, false },
        { (int*)0x7D39A0, "wbaseball", nullptr, false },
        { (int*)0x7D39A8, "batblades", nullptr, false },
        { (int*)0x7D39AC, "revolver", nullptr, false },
        { (int*)0x7D39B0, "glock", nullptr, false },
        { (int*)0x7D39B4, (const char*)0x7CDE5F, nullptr, false },
        { (int*)0x7D39B8, "shotgun", nullptr, false },
        { (int*)0x7D39BC, "shotgunlamp", nullptr, false },
        { (int*)0x7D39C0, "desert", nullptr, false },
        { (int*)0x7D39C4, "coltcom", nullptr, false },
        { (int*)0x7D39C8, "sniper", nullptr, false },
        { (int*)0x7D39CC, "tranqrifle", nullptr, false },
        { (int*)0x7D39D0, "sawnoff", nullptr, false },
        { (int*)0x7D39D4, "brick", nullptr, false },
        { (int*)0x7D39D8, (const char*)0x7CDEAB, nullptr, false },
        { (int*)0x7D39DC, "head", nullptr, false },
        { (int*)0x7D39E0, "chainsaw", nullptr, false },
        { (int*)0x7D39E4, "nailgun", nullptr, false },
        { (int*)0x7D39E8, "wire", nullptr, false },
        { (int*)0x7D39EC, (const char*)0x7CDED3, nullptr, false },
        { (int*)0x7D39F0, "woodspike", nullptr, false },
        { (int*)0x7D39F4, "snipersil", nullptr, false },
        { (int*)0x7D39F8, "shardpig", nullptr, false },
        { (int*)0x7D39FC, "wirepig", nullptr, false },
    };

    static const char* aFeTexDict = "(FE tex. dict.) \"";
    static const char* aQuote = "\"";
    static char g_ErrorBuffer[512];

    int* __cdecl hkLoadTexture(int dict, const char* name)
    {
        int* result = oLoadTexture(dict, name);
        if (result == NULL || result == (int*)-1) {
            printf("[LoadTexture] Missing texture: %s\n", name);
            return g_PlaceholderTexture;
        }
        return result;
    }

    void hkTexturesLoad()
    {
        printf("[CResourceManager::hkTexturesLoad] Loading textures...\n");

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
                }

                if (tex.dualLog && tex.nameAlt) {
                    printf("[CResourceManager::hkTexturesLoad] Loading %s %s\n", tex.name, tex.nameAlt);
                }
                else {
                    printf("[CResourceManager::hkTexturesLoad] Loading %s\n", tex.name);
                }
            }
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            printf("[CResourceManager::hkTexturesLoad] Exception!\n");
        }

        printf("[CResourceManager::hkTexturesLoad] Textures loaded.\n");
    }

    void InitializeResource(void* dest, const char* src)
    {
        printf("[ResourceLoader::InitializeResource] Initializing resource [%s]...\n", src);
        ((void(__thiscall*)(void*, const char*))0x4F2550)(dest, src);
    }

    int RegistryResource(FileRegistryNode* node, void* callback, void* pathStruct)
    {
        return ((int(__cdecl*)(void*, void*, FileRegistryNode*))0x6116B0)(pathStruct, callback, node);
    }

    struct ResourceEntry {
        void* pDest;
        const char* path;
        void* registryNode;
    };

    static const ResourceEntry g_Resources[] = {
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

    int hkResourceLoad()
    {
        printf("[ResourceLoader::hkResourceLoad] Resources Loading...\n");

        void* sub_4F2520 = (void*)0x4F2520;

        for (int i = 0; i < sizeof(g_Resources) / sizeof(g_Resources[0]); i++) {
            const ResourceEntry& res = g_Resources[i];
            InitializeResource(res.pDest, res.path);
            RegistryResource((FileRegistryNode*)res.registryNode, sub_4F2520, res.pDest);
        }

        printf("[ResourceLoader::hkResourceLoad] Resources Loaded!\n");
        return 1;
    }

    void InstallHook()
    {
        g_TexturesLoadHook = safetyhook::create_inline((void*)0x5EA540, (void*)hkTexturesLoad);
        g_ResourceLoadHook = safetyhook::create_inline((void*)0x4D6500, (void*)hkResourceLoad);
        oResourceLoad = g_ResourceLoadHook.original<tResourceLoad>();
    }
}