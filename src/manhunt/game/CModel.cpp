//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CModel.h"

void CModel::LoadModel(DWORD* this_, void* modelName)
{
    Call<0x59B7C0, DWORD*, void*>(this_, modelName);
}

void CModel::UnloadModel(DWORD* this_)
{
    Call<0x61B380, DWORD*>(this_);
}