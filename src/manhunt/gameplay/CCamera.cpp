#include "CCamera.h"

int& g_CameraFlyMode = *reinterpret_cast<int*>(0x715BB0);
int& g_Unk = *reinterpret_cast<int*>(0x715BB4);
float& g_CameraFlySpeed = *reinterpret_cast<float*>(0x715ABC);
float& g_CameraFlySensitivity = *reinterpret_cast<float*>(0x715AC4);


// 7A1418 - ??
// ModeCameraRec()
// 

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