#include "CCamera.h"

int& g_CameraFlyMode = *reinterpret_cast<int*>(0x715BB0);
int& g_Unk = *reinterpret_cast<int*>(0x715BB4);
float& g_CameraFlySpeed = *reinterpret_cast<float*>(0x715ABC);
float& g_CameraFlySensitivity = *reinterpret_cast<float*>(0x715AC4);


// 7A1418 - ??
// ModeCameraRec()
// 

// unused
float* CCamera::Camera_GetBase(void) {
    return (float*)CAMERA_BASE;
}

// A value is added to this function every frame; there isn't much use for it.
float CCamera::Camera_GetNoSignedTimerCount(void) {
    return *(float*)(CAMERA_BASE + 0x68);
}

void CCamera::Camera_SetNoSigned(bool state) {
    *(bool*)(0x7A13DD) = state ? 1 : 0;
}

bool CCamera::Camera_GetNoSigned(void) {
    return *(bool*)(0x7A13DD) != 0;
}

// If you set the value to zero, a "no signal" camera screen will appear for a few seconds—which is pretty useless; 
// if you want better control, it is better to use SetCameraNoSigned.
void CCamera::Camera_SetNoSignedTimerCount(float value) {
    *(float*)(CAMERA_BASE + 0x68) = value;
}

// I believe it's something like a tremolo, but it likely operates on the same principle as the 
// "Set/Get ZoomTemp" function, where the value returns to its initial state.
float CCamera::Camera_GetTremolo(void) {
    return *(float*)(CAMERA_BASE + 0x78);
}

void CCamera::Camera_SetTremolo(float value) {
    *(float*)(CAMERA_BASE + 0x78) = value;
}

float CCamera::Camera_GetZoomTemp(void) {
    return *(float*)(CAMERA_BASE + 0x7C);
}

void CCamera::Camera_SetZoomTemp(float value) {
    *(float*)(CAMERA_BASE + 0x7C) = value;
}

float CCamera::Camera_GetLeftPosition(void) {
    return *(float*)(CAMERA_BASE + 0x80);
}

void CCamera::Camera_SetLeftPosition(float value) {
    *(float*)(CAMERA_BASE + 0x80) = value;
}

float CCamera::Camera_GetPosition(void) {
    return *(float*)(CAMERA_BASE + 0x84);
}

void CCamera::Camera_SetPosition(float value) {
    *(float*)(CAMERA_BASE + 0x84) = value;
}

float CCamera::Camera_GetAimPos(void) {
    return *(float*)(CAMERA_BASE + 0xA8);
}

void CCamera::Camera_SetAimPos(float value) {
    *(float*)(CAMERA_BASE + 0xA8) = value;
}

float CCamera::Camera_GetAimLeftPosition(void) {
    return *(float*)(CAMERA_BASE + 0xAC);
}

void CCamera::Camera_SetAimLeftPosition(float value) {
    *(float*)(CAMERA_BASE + 0xAC) = value;
}

// Front -> When you press F and the camera moves to the front of you.
double CCamera::Camera_GetFrontRotation(void) {
    return *(double*)(CAMERA_BASE + 0xB8);
}

void CCamera::Camera_SetFrontRotation(double value) {
    *(double*)(CAMERA_BASE + 0xB8) = value;
}

float CCamera::Camera_GetFrontZoom(void) {
    return *(float*)(CAMERA_BASE + 0xC0);
}

void CCamera::Camera_SetFrontZoom(float value) {
    *(float*)(CAMERA_BASE + 0xC0) = value;
}


// Back -> rear camera, the standard one.
double CCamera::Camera_GetBackPos(void) {
    return *(double*)(CAMERA_BASE + 0xC8);
}

void CCamera::Camera_SetBackPos(double value) {
    *(double*)(CAMERA_BASE + 0xC8) = value;
}

// unused
char* CCamera::Camera_GetTCRString(void) {
    return (char*)(CAMERA_BASE + 0x4A8);
}

void CCamera::Camera_SetTCRString(const char* str) {
    strcpy((char*)(CAMERA_BASE + 0x4A8), str);
}

void CCamera::ToggleCameraFlyMode(bool state) {
    if (state)
    {
        g_CameraFlyMode = 1;
        g_Unk = 0;
    }
    else
    {
        g_CameraFlyMode = g_Unk = 0;
    }
}

void CCamera::SetCameraFlySpeed(float speed) {
    g_CameraFlySpeed = speed;
}

void CCamera::SetCameraFlySensitivity(float sensitivity = 200) { // 200 = default
    g_CameraFlySensitivity = sensitivity;
}

// ----

void CCamera::InstallHook() {
	//PATCH(0x4628B2, 0x90, 5); // disable camera reset press x

    /*
    
    .text:0047646E                 cmp     eax, 3FBh      
    .text:004764B6                 cmp     ebx, 3FCh      
    .text:004764F9                 cmp     eax, 3FDh      
    .text:0047653A                 cmp     ecx, 3FEh      
    
    */

    /*
    BYTE patch_up[] = { 0x57, 0x00 };
    PATCH_DATA(0x00476470, patch_up, sizeof(patch_up));  // ← ENDEREÇO DO OPERANDO!

    BYTE patch_down[] = { 0x53, 0x00 };
    PATCH_DATA(0x004764B8, patch_down, sizeof(patch_down));

    BYTE patch_left[] = { 0x41, 0x00 };
    PATCH_DATA(0x004764FB, patch_left, sizeof(patch_left));

    BYTE patch_right[] = { 0x44, 0x00 };
    PATCH_DATA(0x0047653C, patch_right, sizeof(patch_right));
    */
}