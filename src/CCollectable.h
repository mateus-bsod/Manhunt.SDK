#pragma once

typedef char(__thiscall* tCollectableParse)(void* pThis, int property);


#ifndef C_COLLECTABLE_H
#define C_COLLECTABLE_H
    extern tCollectableParse oCollectableParse;
    extern SafetyHookInline g_CollectableHook;
#endif



char __fastcall hkCollectableParse(
    void* pThis,
    void*,
    int property);

void InstallCollectableHook();