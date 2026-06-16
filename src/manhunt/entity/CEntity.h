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

class CEntity
{
private:
    static DWORD* m_EntityList;

public:
    static void Shutdown();
    void InitializeEntity();
    void InitEntity(int* config);
    bool IsValidEntity();
    bool IsEntityDead();
    void SetEntityHealth(int health);
    void SetEntityInvincible(bool invincible);
    void SetEntityAnimation(int start, int end, char value);
    DWORD GetEntityMatrix();
    void ClearCurrentEntity(int value);
    void DestroyEntity();
    void RemoveHunter();
    bool IsHunter();
    void SetPosition(float x, float y, float z);
    void SetRotation(float rx, float ry, float rz);
    Vector* GetEntityPosition();
    Vector* GetEntityRotation();
    Vector* GetEntityBoundingBoxMin();
    Vector* GetEntityBoundingBoxMax();
    int DeleteAllHunters();
    float GetEntityHealthPercent();
    int GetEntityMaxHealth();
};