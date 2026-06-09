// CLoadGameWorld.h
#pragma once

#include "../../framework.h"
#include "CPlayer.h"
#include "../game.sdk.h"

// ============================================================================
// Engine
// ============================================================================

typedef bool(__cdecl* tInitialiseEngine)(int);
extern tInitialiseEngine InitialiseEngine;

typedef void(__cdecl* tResetGameSystems)();
extern tResetGameSystems ResetGameSystems;

typedef void(__cdecl* tInitialiseGlobalManagers)();
extern tInitialiseGlobalManagers InitialiseGlobalManagers;

// ============================================================================
// Loading
// ============================================================================

typedef void(__cdecl* tLoadingStep)(int);
extern tLoadingStep LoadingStep;

// ============================================================================
// Mission / World
// ============================================================================

typedef void(__cdecl* tLoadMission)(int missionId);
extern tLoadMission LoadMission;

typedef void(__cdecl* tInitialiseMission)();
extern tInitialiseMission InitialiseMission;

typedef bool(__cdecl* tSetWorld)(const char*);
extern tSetWorld SetWorld;

// ============================================================================
// Animation
// ============================================================================

typedef bool(__cdecl* tAnimManagerInitialise)(const char*);
extern tAnimManagerInitialise AnimManager_Initialise;

// ============================================================================
// Weapons
// ============================================================================

typedef void(__cdecl* tWeaponManagerInitialise)(const char*);
extern tWeaponManagerInitialise WeaponManager_Initialise;

typedef void(__cdecl* tWeaponManagerLoadDefinitions)();
extern tWeaponManagerLoadDefinitions WeaponManager_LoadDefinitions;

// ============================================================================
// Scripts
// ============================================================================

typedef void(__cdecl* tScriptLoaderInitialise)(const char*);
extern tScriptLoaderInitialise ScriptLoader_Initialise;

// ============================================================================
// Entities
// ============================================================================

typedef bool(__cdecl* tEntityManagerInitialise)(const char*);
extern tEntityManagerInitialise EntityManager_Initialise;

// ============================================================================
// Collision
// ============================================================================

typedef void(__cdecl* tCollisionDataInitialise)(const char*);
extern tCollisionDataInitialise CollisionData_Initialise;

// ============================================================================
// Effects
// ============================================================================

typedef void(__cdecl* tBreakingGlassInitialise)(const char*);
extern tBreakingGlassInitialise BreakingGlass_Initialise;

typedef void(__cdecl* tDecalManagerInitialise)(const char*);
extern tDecalManagerInitialise DecalManager_Initialise;

typedef void(__cdecl* tLightConeManagerInitialise)(const char*);
extern tLightConeManagerInitialise LightConeManager_Initialise;

// ============================================================================
// Map
// ============================================================================

typedef void(__cdecl* tGameMapInitialise)(const char*);
extern tGameMapInitialise GameMap_Initialise;

typedef bool(__cdecl* tMapAIInitialise)(const char*);
extern tMapAIInitialise MapAI_Initialise;

// ============================================================================
// Inventory
// ============================================================================

typedef void(__cdecl* tInventoryManagerInitialise)(const char*);
extern tInventoryManagerInitialise InventoryManager_Initialise;

// ============================================================================
// Player
// ============================================================================

typedef bool(__cdecl* tCreatePlayer)(int);
extern tCreatePlayer CreatePlayer;

typedef void(__cdecl* tInitialisePlayer)(int player);
extern tInitialisePlayer InitialisePlayer;

typedef void(__cdecl* tPostPlayerInitialise)(int);
extern tPostPlayerInitialise PostPlayerInitialise;

// ============================================================================
// Globals
// ============================================================================

extern int& g_LoadErrorCode;

extern int& g_LoadTimerStart;
extern int& g_LoadTimerCurrent;
extern int& g_LoadTimerDelta;
extern int& g_LoadTimerFrame;
extern int& g_LoadTimerFrame2;

extern int& g_SaveGameActive;
extern int& g_CPlayer;

// ============================================================================
// Strings
// ============================================================================


namespace CLoadGameWorld
{
    bool LoadGameWorld(int missionId);
    void InstallHook();
}