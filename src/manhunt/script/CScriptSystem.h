//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#pragma once

#include "../../../framework.h"
#include "../../../lib/lua/lua.hpp"

class CScriptSystem
{
private:
    static CScriptSystem* pInstance;
    static lua_State* L;

public:
    CScriptSystem();
    ~CScriptSystem();

    static void Initialize();
    static void LoadAllScripts();
    static int lua_PrintLog(lua_State* L);
};