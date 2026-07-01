#pragma once

#include "../../game.sdk.h"

extern int& g_CameraFlyMode; // (g_CameraFlyMode && !g_Unk)
extern int& g_Unk;
extern float& g_CameraFlySpeed;
extern float& g_CameraFlySensitivity;

#define CAMERA_BASE 0x7A0FAC

class CCamera {
public:
	static float* Camera_GetBase(void);
	static float Camera_GetNoSignedTimerCount(void);
	static void Camera_SetNoSigned(bool state);
	static bool Camera_GetNoSigned(void);
	static void Camera_SetNoSignedTimerCount(float value);
	static float Camera_GetTremolo(void);
	static void Camera_SetTremolo(float value);
	static float Camera_GetZoomTemp(void);
	static void Camera_SetZoomTemp(float value);
	static float Camera_GetLeftPosition(void);
	static void Camera_SetLeftPosition(float value);
	static float Camera_GetPosition(void);
	static void Camera_SetPosition(float value);
	static float Camera_GetAimPos(void);
	static void Camera_SetAimPos(float value);
	static float Camera_GetAimLeftPosition(void);
	static void Camera_SetAimLeftPosition(float value);
	static double Camera_GetFrontRotation(void);
	static void Camera_SetFrontRotation(double value);
	static float Camera_GetFrontZoom(void);
	static void Camera_SetFrontZoom(float value);
	static double Camera_GetBackPos(void);
	static void Camera_SetBackPos(double value);
	static char* Camera_GetTCRString(void);
	static void Camera_SetTCRString(const char* str);

	static void ToggleCameraFlyMode(bool state);
	static void SetCameraFlySpeed(float speed);
	static void SetCameraFlySensitivity(float sensitivity);
	static void CCamera::InstallHook();
};