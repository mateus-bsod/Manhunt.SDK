#include "CEntity.h"

DWORD* CEntityList = (DWORD*)(0x69BBE4);

/*

	Delete All Hunters

    DWORD node = *CEntityList;
    int count = 0;

    while (node) {
        DWORD entity = *(DWORD*)node;
        if (entity) {
            DWORD typePtr = *(DWORD*)(entity + 124);
            if (typePtr) {
                DWORD type = *(DWORD*)(typePtr + 4) & 0x1F;
                if (type == 31) {
                    // Seta flag de morte
                    DWORD flags = *(DWORD*)(entity + 200);
                    *(DWORD*)(entity + 200) = flags | 0x2;
                    count++;
                }
            }
        }
        node = *(DWORD*)(node + 8);
    }


*/

namespace CEntity
{
    void Shutdown()  // fake
    { 
        Call<0x437710>();
	}

    //
    void DestroyEntity(DWORD entity) 
    { 
        Call<0x4813B0, DWORD>(entity); 
    }

    void RemoveHunter(DWORD entity)
    {
        Call<0x4EDA30, DWORD>(entity);
    }

    bool IsHunter(DWORD entity) 
    { 
        DWORD* e = (DWORD*)entity;
        return (*(DWORD*)(e[31] + 4) & 0xF) == 15;
        // return CallAndReturn<bool, 0x431860>(entity); 
    }

    void InitEntity(DWORD entity) 
    { 
        Call<0x437110, DWORD>(entity);
    }
    
    void ClearCurrentEntity(int val)
    { 
        Call<0x4AC1B0, int>(val); 
    }

    // Áudio
    void PlaySound(DWORD soundIndex) 
    { 
        Call<0x618440, DWORD>(soundIndex); 
    }
    void ApplySoundEffect(DWORD idx) 
    { 
        Call<0x621B70, DWORD>(idx); 
    }
    void ClearAudioSources() 
    { 
        Call<0x4CDAD0>(); 
    }
    void ClearAudioChannels() 
    { 
        Call<0x4CDB70>(); 
    }

    void ClearParticleSystems()
    { 
        Call<0x49ACD0>();
    }

    int WorldUpdateReturn(int val) 
    { 
        return CallAndReturn<int, 0x480D30>(val); 
    }

    Vector* GetEntityPosition(DWORD entity) 
    {
        __asm
        {
            mov     ecx, entity
            mov     eax, [ecx + 0x80]
            mov     eax, [eax + 0x4]
            add     eax, 0x40
        }
    }

    Vector* GetEntityRotation(DWORD entity)
    {
        __asm
        {
            mov     ecx, entity
            mov     eax, [ecx + 0x80]
            mov     eax, [eax + 0x4]
            add     eax, 0x10
        }
    }

    // --------------------------------------------------------------------------------

    Vector* GetEntityBoundingBoxMin(DWORD entity)
    {
        __asm
        {
			mov     ecx, entity
            mov     eax, [ecx + 0x80]
            mov     eax, [eax + 0x4]
            add     eax, 0x30
        }
    }
    
    Vector* GetEntityBoundingBoxMax(DWORD entity)
    {
        __asm
        {
            mov     ecx, entity
            mov     eax, [ecx + 0x80]
            mov     eax, [eax + 0x4]
            add     eax, 0x20
        }
    }

    // debug
    int DeleteAllHunters() {
        DWORD* listHead = (DWORD*)CEntityList;
        DWORD node = *listHead;
        int killed = 0;

        while (node) {
            DWORD entity = *(DWORD*)node;
            if (entity && IsHunter(entity)) {
                DestroyEntity(entity);
                killed++;
            }
            node = *(DWORD*)(node + 8);
        }

        return killed;
    }
}