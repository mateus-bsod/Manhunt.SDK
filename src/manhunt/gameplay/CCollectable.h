//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#pragma once

#include "../../game.sdk.h"
#include "../../../framework.h"

typedef char(__fastcall* tCollectableParse)(void* pThis, void* _, int property);

class CCollectable
{
private:
    static tCollectableParse oCollectableParse;
    static SafetyHookInline g_CollectableHook;

    static char __fastcall hkCollectableParse(void* pThis, void* _, int property);

public:
    static void InstallHook();
};