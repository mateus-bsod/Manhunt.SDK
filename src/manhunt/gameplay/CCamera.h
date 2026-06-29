#pragma once

#include "../../game.sdk.h"

extern int& g_CameraFlyMode; // (g_CameraFlyMode && !g_Unk)
extern int& g_Unk;
extern float& g_CameraFlySpeed;
extern float& g_CameraFlySensitivity;

class CCamera {
public:
	static void ToggleCameraFlyMode(bool state);
	static void SetCameraFlySpeed(float speed);
	static void SetCameraFlySensitivity(float sensitivity);
	static void CCamera::InstallHook();
};