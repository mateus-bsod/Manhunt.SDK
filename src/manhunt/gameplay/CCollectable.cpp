//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CCollectable.h"

tCollectableParse CCollectable::oCollectableParse = nullptr;
SafetyHookInline CCollectable::g_CollectableHook;

char __fastcall CCollectable::hkCollectableParse(void* pThis, void* _, int property)
{
    Console::Printf("===== sub_440100 =====");
    Console::Printf("this     = %p", pThis);
    Console::Printf("property = %08X", property);

    __try
    {
        auto base = reinterpret_cast<uintptr_t>(pThis);

        Console::Printf("Slot = %d", *(int*)(base + 0x168));
        Console::Printf("Pos = %.3f %.3f %.3f",
            *(float*)(base + 0x1AC),
            *(float*)(base + 0x1B0),
            *(float*)(base + 0x1B4));
        Console::Printf("Rot = %.3f %.3f %.3f",
            *(float*)(base + 0x1A0),
            *(float*)(base + 0x1A4),
            *(float*)(base + 0x1A8));
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        Console::Printf("Failed reading collectable data");
    }

    return CCollectable::oCollectableParse(pThis, _, property);
}

void CCollectable::InstallHook()
{
    /*
    g_CollectableHook = safetyhook::create_inline(
        reinterpret_cast<void*>(0x00440100),
        reinterpret_cast<void*>(&CCollectable::hkCollectableParse)
    );

    oCollectableParse = g_CollectableHook.original<tCollectableParse>();
    */
}