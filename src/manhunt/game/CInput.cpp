//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "CInput.h"


bool CInput::g_DialogThreadRunning = true;

int CInput::IsUpKeyPressed()
{
    return CallAndReturn<int, 0x5D8A10>();
}

int CInput::IsDownKeyPressed()
{
    return CallAndReturn<int, 0x5D8AA0>();
}

int CInput::IsConfirmKeyPressed()
{
    return CallAndReturn<int, 0x5DACC0>();
}

int CInput::IsActionKeyPressed()
{
    return CallAndReturn<int, 0x5D8B30>();
}

int CInput::IsExitKeyPressed()
{
    return CallAndReturn<int, 0x5D8C60>();
}

int CInput::IsKeyReleased()
{
    return CallAndReturn<int, 0x5D87A0>();
}

bool CInput::IsUsingMouse()
{
    return CallAndReturn<bool, 0x5D5580>();
}

void* CInput::GetLocalizedString(void* pStringId)
{
    return CallAndReturn<void*, 0x4937E0, void*>(pStringId);
}

int CInput::GetSelectedOptionFromMouse()
{
    return CallAndReturn<int, 0x5DAD00>();
}

void CInput::ResetMenuState()
{
    Call<0x5EF820>();
}

void CInput::DialogThreadFunc()
{
    while (g_DialogThreadRunning)
    {
        if (CVisual::InDialogBox && CVisual::VisibleDialog)
        {
            if ((GetAsyncKeyState(VK_RETURN) & 1) || (GetAsyncKeyState(VK_SPACE) & 1) || (GetAsyncKeyState(VK_LBUTTON) & 1))
            {
                CVisual::UpdateDialogBox();
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void CInput::InstallHook()
{
    std::thread dialogThread(DialogThreadFunc);
    dialogThread.detach();
}

void CInput::Shutdown()
{
    g_DialogThreadRunning = false;
}