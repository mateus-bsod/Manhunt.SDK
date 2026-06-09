#include "CCollectable.h"

tCollectableParse oCollectableParse = nullptr;
SafetyHookInline g_CollectableHook;

namespace CCollectable
{

    char __fastcall hkCollectableParse(
        void* pThis,
        void*,
        int property)
    {
        printf("\n===== sub_440100 =====\n");
        printf("this     = %p\n", pThis);
        printf("property = %08X\n", property);

        auto base = reinterpret_cast<uintptr_t>(pThis);

        __try
        {
            auto base = reinterpret_cast<uintptr_t>(pThis);

            printf("Slot = %d\n",
                *(int*)(base + 0x168));

            printf(
                "Pos = %.3f %.3f %.3f\n",
                *(float*)(base + 0x1AC),
                *(float*)(base + 0x1B0),
                *(float*)(base + 0x1B4));

            printf(
                "Rot = %.3f %.3f %.3f\n",
                *(float*)(base + 0x1A0),
                *(float*)(base + 0x1A4),
                *(float*)(base + 0x1A8));
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            printf("Failed reading collectable data\n");
        }

        return oCollectableParse(
            pThis,
            property);
    }

    void InstallHook()
    {
        /*
        g_CollectableHook = safetyhook::create_inline(
            reinterpret_cast<void*>(0x00440100),
            reinterpret_cast<void*>(&hkCollectableParse)
        );

        oCollectableParse =
            g_CollectableHook.original<tCollectableParse>();
        */
    }
};