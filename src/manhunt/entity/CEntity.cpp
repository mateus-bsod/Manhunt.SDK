//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CEntity.h"

DWORD* CEntity::m_EntityList = (DWORD*)(0x69BBEC);

void CEntity::Shutdown()
{
    DWORD func = 0x437710;
    __asm call func
}

void CEntity::InitializeEntity()
{
    DWORD func = 0x437110;
    __asm
    {
        mov ecx, this
        call func
    }
}

void CEntity::InitEntity(int* config)
{
    DWORD func = 0x49BA50;
    __asm
    {
        mov ecx, this
        push config
        call func
    }
}

bool CEntity::IsValidEntity()
{
    return CallAndReturn<bool, 0x431AE0, CEntity*>(this);
}

bool CEntity::IsEntityDead()
{
    DWORD func = 0x424090;
    __asm
    {
        mov ecx, this
        call func
    }
}

void CEntity::SetEntityHealth(int health)
{
    DWORD func = 0x4A3EE0;
    __asm
    {
        mov ecx, this
        mov edi, health
        push 0
        push 1
        call func
    }
}

void CEntity::SetEntityInvincible(bool invincible)
{
    DWORD func = 0x4B2580;
    DWORD inv = invincible ? 1 : 0;
    __asm
    {
        mov ecx, this
        push 0
        push inv
        call func
    }
}

void CEntity::SetEntityAnimation(int start, int end, char value)
{
    DWORD func = 0x5A96B0;
    __asm
    {
        mov ecx, this
        add ecx, 116
        push value
        push end
        push start
        call func
    }
}


DWORD CEntity::GetEntityMatrix() // falta terminar
{
    DWORD func = 0x4313B0;
    __asm
    {
        mov ecx, this
        call func
    }
    //Call<0x4313B0, CEntity*>(this);
}

void CEntity::ClearCurrentEntity(int value)
{
    Call<0x4AC1B0, CEntity*, int>(this, value);
}

void CEntity::DestroyEntity()
{
    Call<0x4813B0, CEntity*>(this);
}

void CEntity::RemoveHunter()
{
    DWORD func = 0x4EDA30;
    __asm
    {
        mov ecx, this
        call func
    }
}

bool CEntity::IsHunter()
{
    __asm
    {
        mov ecx, this
        mov eax, [ecx + 0x7C]
        mov edx, [eax + 4]
        and edx, 0x1F
        cmp edx, 31
        setz al
        movzx eax, al
    }
}

void CEntity::SetPosition(float x, float y, float z)
{
    Vector* pos = this->GetEntityPosition();
    if (pos)
    {
        pos->x = x;
        pos->y = y;
        pos->z = z;
    }
}

void CEntity::SetRotation(float rx, float ry, float rz)
{
    Vector* rot = this->GetEntityRotation();
    if (rot)
    {
        rot->x = rx;
        rot->y = ry;
        rot->z = rz;
    }
}

Vector* CEntity::GetEntityPosition()
{
    __asm
    {
        mov     ecx, this
        mov     eax, [ecx + 0x80]
        mov     eax, [eax + 0x4]
        add     eax, 0x40
    }
}

Vector* CEntity::GetEntityRotation()
{
    __asm
    {
        mov     ecx, this
        mov     eax, [ecx + 0x80]
        mov     eax, [eax + 0x4]
        add     eax, 0x10
    }
}

Vector* CEntity::GetEntityBoundingBoxMin()
{
    __asm
    {
        mov     ecx, this
        mov     eax, [ecx + 0x80]
        mov     eax, [eax + 0x4]
        add     eax, 0x30
    }
}

Vector* CEntity::GetEntityBoundingBoxMax()
{
    __asm
    {
        mov     ecx, this
        mov     eax, [ecx + 0x80]
        mov     eax, [eax + 0x4]
        add     eax, 0x20
    }
}

int CEntity::DeleteAllHunters()
{
    DWORD node = *m_EntityList;
    int killed = 0;

    while (node)
    {
        CEntity* entity = (CEntity*)node;
        if (entity && entity->IsHunter())
        {
            entity->DestroyEntity();
            killed++;
        }
        node = *(DWORD*)(node + 8);
    }

    return killed;
}

float CEntity::GetEntityHealthPercent()
{
    DWORD func = 0x5E78A0;
    __asm
    {
        mov ecx, this
        call func
    }
}

int CEntity::GetEntityMaxHealth()
{
    DWORD func = 0x5E7890;
    __asm
    {
        mov ecx, this
        call func
    }
}