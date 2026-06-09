// CInitialiseWorld.cpp
#include "CLoadGameWorld.h"


typedef void(__cdecl* tSub_5D4A50)();
tSub_5D4A50 sub_5D4A50 = (tSub_5D4A50)0x5D4A50;

typedef void(__cdecl* tSub_4753A0)();
tSub_4753A0 sub_4753A0 = (tSub_4753A0)0x4753A0;

typedef bool(__cdecl* tSub_4D62A0)(int);
tSub_4D62A0 sub_4D62A0 = (tSub_4D62A0)0x4D62A0;

typedef void(__cdecl* tLoadingStep)(int);
tLoadingStep LoadingStep = (tLoadingStep)0x5EF3B0;

typedef void(__thiscall* tSub_4932F0)(void*);
tSub_4932F0 sub_4932F0 = (tSub_4932F0)0x4932F0;

typedef void(__cdecl* tSub_5EF410)();
tSub_5EF410 sub_5EF410 = (tSub_5EF410)0x5EF410;

typedef void(__cdecl* tSub_5EEAD0)();
tSub_5EEAD0 sub_5EEAD0 = (tSub_5EEAD0)0x5EEAD0;

typedef void(__cdecl* tSub_5EF430)();
tSub_5EF430 sub_5EF430 = (tSub_5EF430)0x5EF430;

typedef void(__cdecl* tSub_5EF510)();
tSub_5EF510 sub_5EF510 = (tSub_5EF510)0x5EF510;

typedef void(__cdecl* tSub_5D9070)();
tSub_5D9070 sub_5D9070 = (tSub_5D9070)0x5D9070;

typedef void(__cdecl* tSub_5A9510)();
tSub_5A9510 sub_5A9510 = (tSub_5A9510)0x5A9510;

typedef void(__thiscall* tSub_5C4230)(void*);
tSub_5C4230 sub_5C4230 = (tSub_5C4230)0x5C4230;

typedef void(__thiscall* tSub_4F26B0)(void*, int);
tSub_4F26B0 sub_4F26B0 = (tSub_4F26B0)0x4F26B0;

typedef void(__cdecl* tSub_471E40)();
tSub_471E40 sub_471E40 = (tSub_471E40)0x471E40;

typedef void(__cdecl* tSub_4BCEC0)(const char*);
tSub_4BCEC0 sub_4BCEC0 = (tSub_4BCEC0)0x4BCEC0;

typedef bool(__thiscall* tSub_476C80)(void*);
tSub_476C80 sub_476C80 = (tSub_476C80)0x476C80;

typedef bool(__cdecl* tSub_496410)(const char*);
tSub_496410 sub_496410 = (tSub_496410)0x496410;

typedef bool(__cdecl* tSub_474F00)(const char*);
tSub_474F00 sub_474F00 = (tSub_474F00)0x474F00;

typedef void(__cdecl* tSub_4FA240)(const char*);
tSub_4FA240 sub_4FA240 = (tSub_4FA240)0x4FA240;

typedef void(__cdecl* tSub_4FA700)();
tSub_4FA700 sub_4FA700 = (tSub_4FA700)0x4FA700;

typedef void(__cdecl* tSub_47EFD0)(const char*);
tSub_47EFD0 sub_47EFD0 = (tSub_47EFD0)0x47EFD0;

typedef void(__thiscall* tSub_5D4E20)(void*);
tSub_5D4E20 sub_5D4E20 = (tSub_5D4E20)0x5D4E20;

typedef bool(__cdecl* tSub_4375A0)(const char*);
tSub_4375A0 sub_4375A0 = (tSub_4375A0)0x4375A0;

typedef void(__cdecl* tSub_4D9160)(const char*);
tSub_4D9160 sub_4D9160 = (tSub_4D9160)0x4D9160;

typedef void(__thiscall* tSub_433320)(int*, int*, float);
tSub_433320 sub_433320 = (tSub_433320)0x433320;

typedef void(__thiscall* tSub_42BB20)(int*, int, int*);
tSub_42BB20 sub_42BB20 = (tSub_42BB20)0x42BB20;

typedef void(__cdecl* tSub_6190B0)(int);
tSub_6190B0 sub_6190B0 = (tSub_6190B0)0x6190B0;

typedef void(__cdecl* tSub_618440)(int);
tSub_618440 sub_618440 = (tSub_618440)0x618440;

typedef void(__thiscall* tSub_5A7060)(void*);
tSub_5A7060 sub_5A7060 = (tSub_5A7060)0x5A7060;

typedef void(__cdecl* tSub_553390)(const char*);
tSub_553390 sub_553390 = (tSub_553390)0x553390;

typedef void(__cdecl* tSub_5DFD40)(const char*);
tSub_5DFD40 sub_5DFD40 = (tSub_5DFD40)0x5DFD40;

typedef void(__cdecl* tSub_482640)(const char*);
tSub_482640 sub_482640 = (tSub_482640)0x482640;

typedef void(__cdecl* tSub_5937B0)(const char*);
tSub_5937B0 sub_5937B0 = (tSub_5937B0)0x5937B0;

typedef void(__cdecl* tSub_5DDCD0)(const char*);
tSub_5DDCD0 sub_5DDCD0 = (tSub_5DDCD0)0x5DDCD0;

typedef void(__thiscall* tSub_4BB150)(void*);
tSub_4BB150 sub_4BB150 = (tSub_4BB150)0x4BB150;

typedef bool(__cdecl* tSub_474A20)(const char*);
tSub_474A20 sub_474A20 = (tSub_474A20)0x474A20;

typedef bool(__cdecl* tSub_437650)(int);
tSub_437650 sub_437650 = (tSub_437650)0x437650;

typedef void(__cdecl* tSub_5D2650)(int);
tSub_5D2650 sub_5D2650 = (tSub_5D2650)0x5D2650;

typedef void(__thiscall* tSub_45BB30)(void*);
tSub_45BB30 sub_45BB30 = (tSub_45BB30)0x45BB30;

typedef void(__cdecl* tSub_59BC20)(const char*);
tSub_59BC20 sub_59BC20 = (tSub_59BC20)0x59BC20;

typedef void(__cdecl* tSub_403080)(const char*);
tSub_403080 sub_403080 = (tSub_403080)0x403080;

typedef void(__cdecl* tSub_404180)();
tSub_404180 sub_404180 = (tSub_404180)0x404180;

typedef void(__cdecl* tSub_5421D0)();
tSub_5421D0 sub_5421D0 = (tSub_5421D0)0x5421D0;

typedef void(__cdecl* tSub_5DBDC0)(int);
tSub_5DBDC0 sub_5DBDC0 = (tSub_5DBDC0)0x5DBDC0;

typedef void(__cdecl* tSub_45BDE0)();
tSub_45BDE0 sub_45BDE0 = (tSub_45BDE0)0x45BDE0;

typedef void(__cdecl* tSub_5B5CD0)();
tSub_5B5CD0 sub_5B5CD0 = (tSub_5B5CD0)0x5B5CD0;

typedef void(__cdecl* tSub_608540)();
tSub_608540 sub_608540 = (tSub_608540)0x608540;

typedef void(__thiscall* tSub_4567A0)(void*, int);
tSub_4567A0 sub_4567A0 = (tSub_4567A0)0x4567A0;

typedef void(__cdecl* tSub_478170)();
tSub_478170 sub_478170 = (tSub_478170)0x478170;

typedef void(__cdecl* tSub_5EF480)();
tSub_5EF480 sub_5EF480 = (tSub_5EF480)0x5EF480;

typedef void(__cdecl* tSub_5D4AF0)();
tSub_5D4AF0 sub_5D4AF0 = (tSub_5D4AF0)0x5D4AF0;

typedef void(__cdecl* tNullsub_7)(const char*);
tNullsub_7 nullsub_7 = (tNullsub_7)0x42D3F0;

typedef void(__cdecl* tNullsub_56)(int, int, int);
tNullsub_56 nullsub_56 = (tNullsub_56)0x5A2AD0;

typedef void(__thiscall* tNullsub_1)(void*);
tNullsub_1 nullsub_1 = (tNullsub_1)0x401570;

// ----------------------------------------------------------------------------------------------

int& dword_715D0C = *reinterpret_cast<int*>(0x715D0C);
int& dword_67E25C = *reinterpret_cast<int*>(0x67E25C);
int& dword_728858 = *reinterpret_cast<int*>(0x728858);
char& byte_7A1219 = *reinterpret_cast<char*>(0x7A1219);
int& dword_7A1238 = *reinterpret_cast<int*>(0x7A1238);
int& g_LoadErrorCode = *reinterpret_cast<int*>(0x7E9084);
int& dword_736DB8 = *reinterpret_cast<int*>(0x736DB8);
int& dword_756268 = *reinterpret_cast<int*>(0x756268);
int& dword_756278 = *reinterpret_cast<int*>(0x756278);
int& dword_75626C = *reinterpret_cast<int*>(0x75626C);
int& dword_75627C = *reinterpret_cast<int*>(0x75627C);
int& dword_756270 = *reinterpret_cast<int*>(0x756270);
int& dword_756274 = *reinterpret_cast<int*>(0x756274);
int& dword_75628C = *reinterpret_cast<int*>(0x75628C);
int& dword_756280 = *reinterpret_cast<int*>(0x756280);
int& dword_725A4C = *reinterpret_cast<int*>(0x725A4C);
int& dword_7D358C = *reinterpret_cast<int*>(0x7D358C);
int& dword_7D3588 = *reinterpret_cast<int*>(0x7D3588);
int& dword_715CF4 = *reinterpret_cast<int*>(0x715CF4);
int& dword_715B94 = *reinterpret_cast<int*>(0x715B94);
int& dword_715B8C = *reinterpret_cast<int*>(0x715B8C);
short& word_7AA878 = *reinterpret_cast<short*>(0x7AA878);
int& dword_7D4EA4 = *reinterpret_cast<int*>(0x7D4EA4);
int& dword_715CA8 = *reinterpret_cast<int*>(0x715CA8);
int& dword_7C9E58 = *reinterpret_cast<int*>(0x7C9E58);
int& dword_7D34C8 = *reinterpret_cast<int*>(0x7D34C8);
int& dword_725678 = *reinterpret_cast<int*>(0x725678);
int& dword_725674 = *reinterpret_cast<int*>(0x725674);
int& dword_725680 = *reinterpret_cast<int*>(0x725680);
int& dword_72567C = *reinterpret_cast<int*>(0x72567C);
int& dword_725688 = *reinterpret_cast<int*>(0x725688);
int& dword_725684 = *reinterpret_cast<int*>(0x725684);
int& dword_725690 = *reinterpret_cast<int*>(0x725690);
int& dword_72568C = *reinterpret_cast<int*>(0x72568C);
int& dword_725694 = *reinterpret_cast<int*>(0x725694);
int& dword_734360 = *reinterpret_cast<int*>(0x734360);
int& dword_715720 = *reinterpret_cast<int*>(0x715720);
int& dword_7E9084 = *reinterpret_cast<int*>(0x7E9084);


// --------------------------------------------------------------------------------
// ARRAYS
// --------------------------------------------------------------------------------

int dword_69BCA0[3456];
int dword_69BCA4[3456];
int dword_69BCA8[3456];
int dword_69BCAC[3456];
int dword_7D93A0[3456];
int dword_7D93A4[3456];
int dword_7D93A8[3456];
int dword_7D93AC[3456];

// --------------------------------------------------------------------------------
// PONTEIROS PARA MEMBROS
// --------------------------------------------------------------------------------

void*& unk_7BA930 = *reinterpret_cast<void**>(0x7BA930);
void*& unk_715740 = *reinterpret_cast<void**>(0x715740);
void*& dword_715BA4 = *reinterpret_cast<void**>(0x715BA4);
char& byte_715BB8 = *reinterpret_cast<char*>(0x715BB8);
char& byte_67E265 = *reinterpret_cast<char*>(0x67E265);
char& byte_67E264 = *reinterpret_cast<char*>(0x67E264);
void*& unk_7C8500 = *reinterpret_cast<void**>(0x7C8500);
void*& unk_7D92F8 = *reinterpret_cast<void**>(0x7D92F8);
void*& unk_67D000 = *reinterpret_cast<void**>(0x67D000);
void*& unk_7A9EBC = *reinterpret_cast<void**>(0x7A9EBC);
int& dword_6C5244 = *reinterpret_cast<int*>(0x6C5244);

// --------------------------------------------------------------------------------
// STRINGS
// --------------------------------------------------------------------------------

const char* aConsoleCreate = "Console Create";
const char* aLevelsetupfrom = "levelSetupFromIni";
const char* aTesterHookInit = "Tester Hook Init";
const char* aSetworld = "SetWorld";
const char* aInitTheLightFl_0 = "Init the light flare FX";
const char* aGraphDarknessC = "Graph Darkness Calc";


const char* aAnimManagerIni = "AnimManager.ini";
const char* aWeaponManInit = "WeaponManInit";
const char* aScriptLoaderIn = "ScriptLoader.Init";
const char* aEntityManagerI = "EntityManager.Init";
const char* aColDataInit = "Coldata.Init";

const char* aBreakingGlassI = "BreakingGlass.Init";
const char* aGameMapInit = "GameMap.Init";
const char* aLightConeInit = "LightCone.Init";
const char* aGameInventoryI = "GameInventory.Init";
const char* aMapAI = "Map.ai";

// --------------------------------------------------------------------------------
// CONSTANTES
// --------------------------------------------------------------------------------

const float flt_715834 = *reinterpret_cast<float*>(0x715834);

// --------------------------------------------------------------------------------
// HOOK
// --------------------------------------------------------------------------------

typedef signed int(__cdecl* tInitialiseWorld)(int missionid);
tInitialiseWorld oInitialiseWorld = nullptr;
SafetyHookInline g_InitialiseWorldHook;

void Log(const char* fmt, ...)
{
    static FILE* log = NULL;
    if (!log) log = fopen("InitialiseWorld.txt", "w");

    char buffer[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    fprintf(log, "%s", buffer);
    fflush(log);

    printf("%s", buffer); 
}

namespace CLoadGameWorld
{
    signed int __cdecl hkInitialiseWorld(int missionid)
    {
        static FILE* log = NULL;
        if (!log) {
            log = fopen("InitialiseWorld.txt", "w");
        }

        Log("\n========== hkInitialiseWorld ==========\n");
        Log("missionid = %d\n", missionid);
        

        signed int result;
        int v2, v4, v5, v8, v9, v10;
        unsigned int v3;
        DWORD* v6;
        signed int v7;
        int v11, v14, v15, v16 = 0, v17 = 0, v18;
        float v12, v13, v19, v20;

        // --------------------------------------------------------------------

        Log("[001] sub_5D4A50()\n"); 
        sub_5D4A50();
        Log("[001] OK\n"); 

        Log("[002] dword_715D0C = dword_67E25C (%d)\n", dword_67E25C); 
        dword_715D0C = dword_67E25C;
        Log("[002] OK -> dword_715D0C = %d\n", dword_715D0C); 

        Log("[003] sub_4753A0()\n"); 
        sub_4753A0();
        Log("[003] OK\n"); 

        Log("[004] Zerando vars\n"); 
        dword_728858 = 0;
        byte_7A1219 = 0;
        dword_7A1238 = 0;
        Log("[004] OK\n"); 

        Log("[005] sub_4D62A0(0)\n"); 
        if (!sub_4D62A0(0))
        {
            Log("[005] ERRO! sub_4D62A0 falhou\n"); 
            result = 0;
            dword_7E9084 = 9;
            return result;
        }
        Log("[005] OK\n"); 

        // --------------------------------------------------------------------

        Log("[006] Timer +44\n"); 
        (*(void(__cdecl**)(void))(**(DWORD**)(dword_736DB8 + 12) + 44))();
        Log("[006] OK\n"); 

        Log("[007] Timer +28 (primeiro)\n"); 
        v2 = (*(int(__cdecl**)(void))(**(DWORD**)(dword_736DB8 + 12) + 28))();
        dword_756268 = v2;
        dword_756278 = v2;
        Log("[007] OK -> v2=%d, dword_756268=%d\n", v2, dword_756268); 

        Log("[008] Timer +28 (segundo)\n"); 
        v3 = (*(int (**)(void))(**(DWORD**)(dword_736DB8 + 12) + 28))();
        Log("[008] OK -> v3=%u\n", v3); 

        Log("[009] Calculando v4\n"); 
        if (v3 >= (unsigned int)dword_756268)
            v4 = v3 - dword_756268;
        else
            v4 = -1 - dword_756268 + v3;
        Log("[009] OK -> v4=%d\n", v4); 

        dword_75626C = v4 + dword_75627C;
        dword_756270 = v4 + dword_75627C + 1;
        dword_756274 = v4 + dword_75627C + 1;
        dword_75628C = 0;
        dword_756280 = 1;
        Log("[010] dword_756274=%d\n", dword_756274); 

        Log("[011] Timer +40\n"); 
        (*(void(__cdecl**)(void))(**(DWORD**)(dword_736DB8 + 12) + 40))();
        Log("[011] OK\n"); 

        // --------------------------------------------------------------------

        Log("[012] sub_4932F0\n"); 
        sub_4932F0(&dword_725A4C);
        Log("[012] OK\n"); 

        Log("[013] sub_5EF410, sub_5EEAD0, sub_5EF430\n"); 
        sub_5EF410();
        sub_5EEAD0();
        sub_5EF430();
        Log("[013] OK\n"); 

        Log("[014] dword_7D358C, dword_7D3588, dword_715CF4\n"); 
        dword_7D358C = 0;
        dword_7D3588 = 39;
        dword_715CF4 = 0;
        Log("[014] OK\n"); 

        Log("[015] sub_5EF510, sub_5D9070, sub_5A9510\n"); 
        sub_5EF510();
        sub_5D9070();
        sub_5A9510();
        Log("[015] OK\n"); 

        Log("[016] sub_5C4230\n"); 
        sub_5C4230(&unk_7BA930);
        Log("[016] OK\n"); 

        Log("[017] LoadingStep(dword_715B94=%d)\n", dword_715B94); 
        LoadingStep(dword_715B94);
        Log("[017] OK\n"); 

        Log("[018] sub_4F26B0(missionid=%d)\n", missionid); 
        sub_4F26B0(&dword_715BA4, missionid);
        Log("[018] OK\n"); 

        Log("[019] sub_471E40\n"); 
        sub_471E40();
        Log("[019] OK\n"); 

        Log("[020] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[020] OK\n"); 

        Log("[021] sub_4BCEC0(aConsoleCreate=%s)\n", aConsoleCreate); 
        sub_4BCEC0(aConsoleCreate);
        Log("[021] OK\n"); 

        Log("[022] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[022] OK\n"); 

        Log("[023] sub_476C80\n"); 
        if (!sub_476C80(&byte_715BB8))
        {
            Log("[023] ERRO! sub_476C80 falhou\n"); 
            return 0;
        }
        Log("[023] OK\n"); 

        Log("[024] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[024] OK\n"); 

        Log("[025] sub_496410(aAnimManagerIni=%s)\n", aAnimManagerIni); 
        if (!sub_496410(aAnimManagerIni))
        {
            Log("[025] ERRO! sub_496410 falhou\n"); 
            return 0;
        }
        Log("[025] OK\n"); 

        Log("[026] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[026] OK\n"); 

        Log("[027] sub_474F00(aSetworld=%s)\n", aSetworld); 
        if (!sub_474F00(aSetworld))
        {
            Log("[027] ERRO! sub_474F00 falhou\n"); 
            result = 0;
            dword_7E9084 = 9;
            return result;
        }
        Log("[027] OK\n"); 

        Log("[028] LoadingStep x2\n"); 
        LoadingStep(dword_715B94);
        LoadingStep(dword_715B94);
        Log("[028] OK\n"); 

        Log("[029] sub_4FA240(aWeaponManInit=%s)\n", aWeaponManInit); 
        sub_4FA240(aWeaponManInit);
        Log("[029] OK\n"); 

        Log("[030] sub_4FA700\n"); 
        sub_4FA700();
        Log("[030] OK\n"); 

        Log("[031] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[031] OK\n"); 

        Log("[032] sub_47EFD0(aScriptLoaderIn=%s)\n", aScriptLoaderIn); 
        sub_47EFD0(aScriptLoaderIn);
        Log("[032] OK\n"); 

        Log("[033] sub_5D4E20\n"); 
        sub_5D4E20(&unk_7C8500);
        Log("[033] OK\n"); 

        Log("[034] byte_67E265 = byte_67E264 (%d), byte_67E264 = 1\n", byte_67E264); 
        byte_67E265 = byte_67E264;
        byte_67E264 = 1;
        Log("[034] OK -> byte_67E264=%d, byte_67E265=%d\n", byte_67E264, byte_67E265); 

        Log("[035] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[035] OK\n"); 

        Log("[036] sub_4375A0(aEntityManagerI=%s)\n", aEntityManagerI); 
        if (!sub_4375A0(aEntityManagerI))
        {
            Log("[036] ERRO! sub_4375A0 falhou\n"); 
            return 0;
        }
        Log("[036] OK\n"); 

        Log("[037] byte_67E264 = byte_67E265 (%d)\n", byte_67E265); 
        byte_67E264 = byte_67E265;
        Log("[037] OK\n"); 

        Log("[038] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[038] OK\n"); 

        Log("[039] sub_4D9160(aColDataInit=%s)\n", aColDataInit); 
        sub_4D9160(aColDataInit);
        Log("[039] OK\n"); 

        Log("[040] LoadingStep x2\n"); 
        LoadingStep(dword_715B94);
        LoadingStep(dword_715B94);
        Log("[040] OK\n"); 

        Log("[041] nullsub_7(%s)\n", aTesterHookInit); 
        nullsub_7(aTesterHookInit);
        Log("[041] OK\n"); 

        Log("[042] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[042] OK\n"); 

        // --------------------------------------------------------------------
        // CAMERA SETUP

        Log("[043] Camera setup\n"); 
        v5 = dword_715B8C + 80;
        v18 = *(int*)(dword_715B8C + 80);
        v19 = *(float*)(dword_715B8C + 84);
        v20 = *(float*)(dword_715B8C + 88);
        v11 = v18;
        v12 = v19;
        v13 = v20;
        *(float*)&v11 = *(float*)&v18 - *(float*)(dword_715B8C + 92);
        v12 = v19 - *(float*)(dword_715B8C + 96);
        v13 = v20 - *(float*)(dword_715B8C + 100);
        Log("[043] OK -> v5=%d, v11=%d\n", v5, v11); 

        Log("[044] sub_433320 - parametros: &v14=0x%X, &v11=0x%X, flt_715834=%f\n", &v14, &v11, flt_715834);
        __try
        {
            sub_433320(&v14, &v11, flt_715834);
            Log("[044] sub_433320 OK\n");
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            Log("[044] sub_433320 EXCEPTION_EXECUTE_HANDLER\n");
        }


        Log("[045] sub_42BB20\n"); 
        sub_42BB20(&v15, v5 + 12, &v14);
        Log("[045] OK -> v15=%d\n", v15); 

        Log("[046] Aplicando transform\n"); 
        v6 = (DWORD*)(*(DWORD*)(dword_715B94 + 4) + 64);
        *v6 = v15;
        v6[1] = v16;
        v6[2] = v17;
        Log("[046] OK\n"); 

        Log("[047] sub_6190B0 e sub_618440\n"); 
        sub_6190B0(*(DWORD*)(dword_715B94 + 4) + 16);
        sub_618440(*(DWORD*)(dword_715B94 + 4));
        Log("[047] OK\n"); 

        Log("[048] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[048] OK\n"); 

        Log("[049] sub_5A7060\n"); 
        sub_5A7060(&word_7AA878);
        Log("[049] OK\n"); 

        Log("[050] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[050] OK\n"); 

        Log("[051] sub_553390(%s)\n", aBreakingGlassI); 
        sub_553390(aBreakingGlassI);
        Log("[051] OK\n"); 

        Log("[052] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[052] OK\n"); 

        Log("[053] sub_5DFD40(%s)\n", aGameMapInit); 
        sub_5DFD40(aGameMapInit);
        Log("[053] OK\n"); 

        Log("[054] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[054] OK\n"); 

        Log("[055] sub_482640(DecalsInit)\n"); 
        sub_482640("DecalsInit");
        Log("[055] OK\n"); 

        Log("[056] LoadingStep x3\n"); 
        LoadingStep(dword_715B94);
        LoadingStep(dword_715B94);
        LoadingStep(dword_715B94);
        Log("[056] OK\n"); 

        Log("[057] sub_5937B0(%s)\n", aLightConeInit); 
        sub_5937B0(aLightConeInit);
        Log("[057] OK\n"); 

        Log("[058] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[058] OK\n"); 

        Log("[059] sub_5DDCD0(%s)\n", aGameInventoryI); 
        sub_5DDCD0(aGameInventoryI);
        Log("[059] OK\n"); 

        Log("[060] LoadingStep x4\n"); 
        LoadingStep(dword_715B94);
        LoadingStep(dword_715B94);
        LoadingStep(dword_715B94);
        LoadingStep(dword_715B94);
        Log("[060] OK\n"); 

        Log("[061] sub_4BB150\n"); 
        sub_4BB150(&dword_734360);
        Log("[061] OK\n"); 

        Log("[062] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[062] OK\n"); 

        Log("[063] sub_474A20(%s)\n", aMapAI); 
        if (!sub_474A20(aMapAI))
        {
            Log("[063] ERRO! sub_474A20 falhou\n"); 
            return 0;
        }
        Log("[063] OK\n"); 

        Log("[064] byte_67E265 = byte_67E264 (%d), byte_67E264 = 1\n", byte_67E264); 
        byte_67E265 = byte_67E264;
        byte_67E264 = 1;
        Log("[064] OK\n"); 

        Log("[065] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[065] OK\n"); 

        // --------------------------------------------------------------------
        // PLAYER CREATION

        Log("[066] Player Creation - dword_7D4EA4=%d\n", dword_7D4EA4); 

        if (dword_7D4EA4)
        {
            Log("[067] Modo SAVE GAME - copiando arrays\n"); 
            v7 = 0;
            do
            {
                dword_69BCA0[v7] = dword_7D93A0[v7];
                dword_69BCA4[v7] = dword_7D93A4[v7];
                dword_69BCA8[v7] = dword_7D93A8[v7];
                dword_69BCAC[v7] = dword_7D93AC[v7];
                v7 += 4;
            } while (v7 < 13824);
            Log("[067] OK - arrays copiados\n"); 

            Log("[068] sub_437650(0)\n"); 
            sub_437650(0);
            Log("[068] OK\n"); 

            Log("[069] sub_5D2650\n"); 
            sub_5D2650((int)&unk_7D92F8);
            Log("[069] OK\n"); 

            Log("[070] sub_45BB30(CPlayer::GetPlayer())\n"); 
            sub_45BB30((void*)CPlayer::GetPlayer());
            Log("[070] OK\n"); 
        }
        else if (!sub_437650(1))
        {
            Log("[071] ERRO! sub_437650(1) falhou\n"); 
            result = 0;
            dword_7E9084 = 9;
            return result;
        }

        Log("[072] byte_67E264 = byte_67E265 (%d)\n", byte_67E265); 
        byte_67E264 = byte_67E265;
        Log("[072] OK\n"); 

        Log("[073] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[073] OK\n"); 

        Log("[074] sub_59BC20(%s)\n", aInitTheLightFl_0); 
        sub_59BC20(aInitTheLightFl_0);
        Log("[074] OK\n"); 

        Log("[075] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[075] OK\n"); 

        Log("[076] sub_403080(%s)\n", aGraphDarknessC); 
        sub_403080(aGraphDarknessC);
        Log("[076] OK\n"); 

        Log("[077] sub_404180\n"); 
        sub_404180();
        Log("[077] OK\n"); 

        Log("[078] LoadingStep\n"); 
        LoadingStep(dword_715B94);
        Log("[078] OK\n"); 

        Log("[079] sub_5421D0\n"); 
        sub_5421D0();
        Log("[079] OK\n"); 

        Log("[080] dword_715CA8=5, sub_5DBDC0(0), dword_7C9E58=0, sub_45BDE0\n"); 
        dword_715CA8 = 5;
        sub_5DBDC0(0);
        dword_7C9E58 = 0;
        sub_45BDE0();
        Log("[080] OK\n"); 

        // --------------------------------------------------------------------
        // PLAYER FINAL SETUP

        Log("[081] Player final setup\n"); 
        CPlayer::GetPlayer()->dwUnknown840 = 0;
        CPlayer::GetPlayer()->dwUnknown83C = CPlayer::GetPlayer()->dwUnknown840;
        CPlayer::GetPlayer()->dwUnknown83C = dword_756274;
        Log("[081] OK\n"); 

        Log("[082] sub_5B5CD0\n"); 
        sub_5B5CD0();
        Log("[082] OK\n"); 

        Log("[083] sub_608540 (se save game)\n"); 
        if (dword_7D4EA4)
            sub_608540();
        Log("[083] OK\n"); 

        Log("[084] sub_4567A0\n"); 
        sub_4567A0(&dword_6C5244, 1);
        Log("[084] OK\n"); 

        Log("[085] nullsub_56\n"); 
        nullsub_56(-1, dword_715720, dword_715720);
        Log("[085] OK\n"); 

        Log("[086] sub_478170\n"); 
        sub_478170();
        Log("[086] OK\n"); 

        Log("[087] dword_7D34C8 = 1\n"); 
        dword_7D34C8 = 1;
        Log("[087] OK\n"); 

        Log("[088] sub_5EF480\n"); 
        sub_5EF480();
        Log("[088] OK\n"); 

        Log("[089] nullsub_1\n"); 
        nullsub_1(&unk_67D000);
        Log("[089] OK\n"); 

        // --------------------------------------------------------------------
        // CLEANUP

        Log("[090] Zerando debug vars\n"); 
        dword_725678 = 0;
        dword_725674 = 0;
        dword_725680 = 0;
        dword_72567C = 0;
        dword_725688 = dword_725684;
        dword_725684 = 0;
        dword_725690 = 0;
        dword_72568C = 0;
        dword_725694 = 0;
        Log("[090] OK\n"); 

        Log("[091] sub_5D4AF0\n"); 
        sub_5D4AF0();
        Log("[091] OK\n"); 

        Log("========== hkInitialiseWorld SUCCESS ==========\n\n"); 

        return 1;
    }

    // --------------------------------------------------------------------------------

    void InstallHook()
    {
        g_InitialiseWorldHook = safetyhook::create_inline(
            (void*)0x474330,
            (void*)hkInitialiseWorld
        );
    }
}