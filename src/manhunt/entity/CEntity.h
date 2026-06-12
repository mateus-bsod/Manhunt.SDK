#pragma once

#include "../../game.sdk.h"
#include "../../../framework.h"


struct Vector {
    float x;
    float y;
    float z;
};

extern DWORD* CEntityList;
namespace CEntity
{
    void Shutdown();  // fake

    //
    void DestroyEntity(DWORD entity);
    void RemoveHunter(DWORD entity);
    bool IsHunter(DWORD entity);
    void InitEntity(DWORD entity);
    void ClearCurrentEntity(int val = 0);
    void PlaySound(DWORD soundIndex);
    void ApplySoundEffect(DWORD idx);
    void ClearAudioSources();
    void ClearAudioChannels();
    void ClearParticleSystems();
    int WorldUpdateReturn(int val = 1);
    int DeleteAllHunters();

    Vector* GetEntityPosition(DWORD entity);
    Vector* GetEntityRotation(DWORD entity);

    Vector* GetEntityBoundingBoxMax(DWORD entity);
    Vector* GetEntityBoundingBoxMin(DWORD entity);

}