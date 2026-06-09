#include "../framework.h"
#include "CPlayer.h"
//

tForcedAnim oForcedPlayAnim = nullptr;
SafetyHookInline g_ForcedPlayAnimHook;
int __fastcall hkForcedPlayAnim(void* pThis, void*, char* anim)
{
    printf(
        "[ForcedPlayAnim] this=%p anim=%s\n",
        pThis,
        anim ? anim : "NULL");
    
   return oForcedPlayAnim(pThis, nullptr, anim);
}

//

namespace CPlayer
{
    void SetPlayerCameraMode(CAMERA_MODE mode)
    {
        int& gCameraMode = *reinterpret_cast<int*>(0x715BB0);
        int& gCameraMode2 = *reinterpret_cast<int*>(0x715BB4);

        switch (mode)
        {
        case CAMERA_MODE_FIRST_PERSON:
            gCameraMode = 0;
            gCameraMode2 = 0;
            break;

        case CAMERA_MODE_FLYMODE:
            gCameraMode = 1;
            gCameraMode2 = 0;
            break;

        case CAMERA_MODE_THIRD_PERSON:
            gCameraMode = 1;
            gCameraMode2 = 1;
            break;
        }
    }

    CAMERA_MODE GetPlayerCameraMode()
    {
        int& gCameraMode = *reinterpret_cast<int*>(0x715BB0);
        int& gCameraMode2 = *reinterpret_cast<int*>(0x715BB4);

        if (!gCameraMode && !gCameraMode2) return CAMERA_MODE_FIRST_PERSON;
        else if (gCameraMode && !gCameraMode2) return CAMERA_MODE_FLYMODE;
        else if (gCameraMode && gCameraMode2) return CAMERA_MODE_THIRD_PERSON;
        return CAMERA_MODE_INVALID;
    }

    //

    PLAYER_STATE GetPlayerState() {

        const int in_game = *reinterpret_cast<float*>(0x7D34F8); // dword_7D34F8
        switch (in_game) {
        case 0: return PLAYER_MENU;
        case 1: return PLAYER_CUTSCENE;
        case 2: return PLAYER_INGAME;
        }
        return PLAYER_INVALID;
    }

    void SetPlayerFogColor(DWORD color)
    {
        DWORD& gFogColor = *reinterpret_cast<DWORD*>(0x715BB8);
        gFogColor = color;
	}

    DWORD GetPlayerFogColor()
    {
        DWORD& gFogColor = *reinterpret_cast<DWORD*>(0x715BB8);
        return gFogColor;
	}
}

void InstallPlayerHooks()
{
    g_ForcedPlayAnimHook = safetyhook::create_inline(
        reinterpret_cast<void*>(0x4C8B20),
        reinterpret_cast<void*>(&hkForcedPlayAnim)
    );
    oForcedPlayAnim =
        g_ForcedPlayAnimHook.original<tForcedAnim>();
}