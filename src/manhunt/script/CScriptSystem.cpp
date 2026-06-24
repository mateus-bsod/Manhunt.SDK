//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CScriptSystem.h"
#include <windows.h>
#include <cstdio>

CScriptSystem* CScriptSystem::pInstance = nullptr;
lua_State* CScriptSystem::L = nullptr;

CScriptSystem::CScriptSystem()
{
    pInstance = this;
    L = nullptr;
}

CScriptSystem::~CScriptSystem()
{
    if (L)
    {
        lua_close(L);
        L = nullptr;
    }
    pInstance = nullptr;
}

void CScriptSystem::Initialize()
{
    if (pInstance) return;
    new CScriptSystem();

    AllocConsole();
    freopen("CONOUT$", "w", stdout);

    printf("[LuaLoader] Inicializando...\n");

    L = luaL_newstate();
    if (L)
    {
        luaL_openlibs(L);
        lua_register(L, "PrintLog", lua_PrintLog);
        LoadAllScripts();
    }

    printf("[LuaLoader] Pronto!\n");
}

void CScriptSystem::LoadAllScripts()
{
    if (!L) return;

    char dllPath[MAX_PATH];
    GetModuleFileNameA(nullptr, dllPath, MAX_PATH);
    char* slash = strrchr(dllPath, '\\');
    if (slash) *(slash + 1) = '\0';

    char searchPath[MAX_PATH];
    sprintf(searchPath, "%sManhunt.SDK\\scripts\\*.lua", dllPath);

    WIN32_FIND_DATAA fd;
    HANDLE hFind = FindFirstFileA(searchPath, &fd);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        sprintf(searchPath, "%sscripts\\*.lua", dllPath);
        hFind = FindFirstFileA(searchPath, &fd);
    }

    if (hFind == INVALID_HANDLE_VALUE)
    {
        sprintf(searchPath, "..\\Manhunt.SDK\\scripts\\*.lua");
        hFind = FindFirstFileA(searchPath, &fd);
    }

    if (hFind == INVALID_HANDLE_VALUE)
    {
        printf("[LuaLoader] Pasta scripts/ nao encontrada!\n");
        return;
    }

    int ok = 0, err = 0;

    do
    {
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;

        char fullPath[MAX_PATH];
        if (strstr(searchPath, "Manhunt.SDK"))
            sprintf(fullPath, "%sManhunt.SDK\\scripts\\%s", dllPath, fd.cFileName);
        else
            sprintf(fullPath, "%sscripts\\%s", dllPath, fd.cFileName);

        if (luaL_dofile(L, fullPath) == 0)
        {
            printf("[LuaLoader] [OK] %s\n", fd.cFileName);
            ok++;
        }
        else
        {
            printf("[LuaLoader] [ERRO] %s: %s\n", fd.cFileName, lua_tostring(L, -1));
            lua_pop(L, 1);
            err++;
        }

    } while (FindNextFileA(hFind, &fd));

    FindClose(hFind);
    printf("[LuaLoader] %d carregados, %d erros\n", ok, err);
}

int CScriptSystem::lua_PrintLog(lua_State* L)
{
    printf("[Lua] %s\n", luaL_checkstring(L, 1));
    return 0;
}