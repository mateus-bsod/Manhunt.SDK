#pragma once

#pragma once

#include "../framework.h"

typedef int(__thiscall* tSub_4C7140)(
    void* _this,
    DWORD* player,
    int a3,
    int a4,
    int a5);

typedef int(__thiscall* tSub_4CAA10)(
    void* _this,
    DWORD* player,
    int a3,
    int a4,
    int a5);

extern tSub_4C7140 oSub_4C7140;
extern tSub_4CAA10 oSub_4CAA10;

extern SafetyHookInline g_Sub4C7140;
extern SafetyHookInline g_Sub4CAA10;

int __fastcall hkSub_4C7140(
    void* _this,
    void* edx,
    DWORD* player,
    int a3,
    int a4,
    int a5);

int __fastcall hkSub_4CAA10(
    void* _this,
    void* edx,
    DWORD* player,
    int a3,
    int a4,
    int a5);

void InitPickupHooks();