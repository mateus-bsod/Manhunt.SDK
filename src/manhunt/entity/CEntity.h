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
public:
    static DWORD* m_EntityList;
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

class CEntityData : public CEntity
{
public:
    void* vtable;
    DWORD field_4;
    DWORD field_8;
    DWORD field_C;
    DWORD field_10;
    DWORD field_14;
    DWORD model;
    BYTE hasModel;
    DWORD field_1C;
    DWORD field_20;
    DWORD collisionData;
    BYTE hasCollision;
    DWORD field_28;
    DWORD animationBlock;
    DWORD field_30;
    DWORD field_34;
    DWORD physics;
    DWORD field_38;
    DWORD field_3C;
    DWORD field_40;
    DWORD stateSounds;
    DWORD field_48;
    DWORD field_4C;
    DWORD lodDistance;
    int lodCount;
    float lodData[3][3];
    DWORD field_70;
    DWORD field_74;
    DWORD field_78;
    DWORD field_7C;
    DWORD field_80;
    DWORD field_84;
    DWORD field_88;
    DWORD field_8C;
    DWORD field_90;
    DWORD flags;
    float lightAnchorX;
    float lightAnchorY;
    float lightAnchorZ;
    DWORD spawn;
    DWORD field_A8;
    DWORD damageSpawn;
    DWORD field_B0;
    float spawnPosX;
    float spawnPosY;
    float spawnPosZ;
    float spawnVelX;
    float spawnVelY;
    float spawnVelZ;
    float bndSphBoost;
    DWORD damageFx;
    DWORD field_D4;
    DWORD field_D8;
    DWORD field_DC;
    DWORD field_E0;
    DWORD field_E4;
    DWORD field_E8;
    DWORD field_EC;
    BYTE cameraCollidable;
};

class HunterEntity : public CEntityData
{
public:
    int entityId;
    char name[32];
    float posX;
    float posY;
    float posZ;
    float rotX;
    float rotY;
    float rotZ;
    int health;
    int maxHealth;
    int armor;
    int maxArmor;
    int state;
    int previousState;
    int actionState;
    int actionTimer;
    int stateFlags;
    int isStunned;
    int isDead;
    int isSearching;
    int isAttacking;
    int isPatrolling;
    int aiState;
    int aiAction;
    int aiTimer;
    int aiFlags;
    int aiTarget;
    int aiTargetId;
    int aiPath[10];
    float distanceToTarget;
    float minDistance;
    float maxDistance;
    float attackDistance;
    float chaseDistance;
    int currentAnim;
    int previousAnim;
    int animTimer;
    int animFlags;
    int animSpeed;
    int weaponId;
    int ammo;
    int maxAmmo;
    int attackPower;
    int attackTimer;
    int attackCooldown;
    int sightLevel;
    int hearingLevel;
    int detectionTimer;
    int detectionFlags;
    float moveSpeed;
    float runSpeed;
    float walkSpeed;
    float turnSpeed;
    int behaviorId;
    int behaviorTimer;
    int behaviorFlags;
    int physicsId;
    float gravity;
    float mass;
    float friction;
    int soundId;
    int soundTimer;
    int soundFlags;
    int persistFlags;
    int spawnTimer;
    int respawnTimer;
    int renderFlags;
    int modelId;
    int textureId;
    int scriptContext;
    int scriptId;
    int scriptTimer;
    int matrixPtr;
    int matrixFlags;
    int goreEntity;
    int goreTimer;
    int goreFlags;
    int stateTimeout;
    int stateCounter;
    int stateData[4];
    float healthRegen;
    float healthTimer;
    int combatMode;
    int combatTimer;
    int combatFlags;
    int patrolPoints[10];
    int patrolIndex;
    int patrolTimer;
    int chaseTimer;
    int chaseFlags;
    int chaseCounter;
    int attackId;
    int attackFlags;
    int attackCounter;
    float moveTargetX;
    float moveTargetY;
    float moveTargetZ;
    float moveTimer;
    int aiThinkTimer;
    int aiReactionTimer;
    int aiDecisionTimer;
    int detectionX;
    int detectionY;
    int detectionZ;
    int scriptData;
    int scriptFlags;
    int matrixData[16];
    int animData;
    int animId;
    int animFrame;
    int combatData;
    int combatCounter;
    float velocityX;
    float velocityY;
    float velocityZ;
    int physicsData;
    int physicsFlags;
    int soundData;
    int soundVolume;
    int stateMachine;
    int stateMachineTimer;
    int persistData;
    int persistTimer;
};