// CVisual.cpp
#include "CVisual.h"
#include "CInput.h"

int& selectedDialog = *reinterpret_cast<int*>(0x7C8774);
int& InDialogBox = *reinterpret_cast<int*>(0x7C8758);
int& VisibleDialog = *reinterpret_cast<int*>(0x7C875C);
int& dword_7C8760 = *reinterpret_cast<int*>(0x7C8760);
int& dword_7C8764 = *reinterpret_cast<int*>(0x7C8764);
int& TitleDialogBox = *reinterpret_cast<int*>(0x7C8768);
int& Btn1DialogBox = *reinterpret_cast<int*>(0x7C876C);
int& Btn2DialogBox = *reinterpret_cast<int*>(0x7C8770);
int& Btn1Pos = *reinterpret_cast<int*>(0x7C8774);
int& Btn2Pos = *reinterpret_cast<int*>(0x7C8778);

DialogState g_Dialog = { false, nullptr };

namespace CVisual
{
    // CVisual.cpp - Adicione estas funções

    int LoadTexture(int txd, const char* texture)
    {
        return CallAndReturn<int, 0x5EA520, int, const char*>(txd, texture);
    }

    void DrawImage(float posX, float posY, float scaleX, float scaleY, int red, int green, int blue, int alpha, int pTexture)
    {
        Call<0x5F96F0>(posX, posY, scaleX, scaleY, red, green, blue, alpha, pTexture);
    }

    void DrawMenuItem(wchar_t* text, float x, float y, int a4, float a5, int selected)
    {
        Call<0x5D55C0>(text, x, y, a4, a5, selected);
    }

    /*
    
        DrawString(
            L"JOGAR",
            0.58f,
            0.40f,
            0.70f,
            0.70f
        );
    
    */

    void DrawString(wchar_t* text, float x, float y, int a4, float a5)
    {
        Call<0x5D5B30>(text, x, y, a4, a5);
    }

    //

    void GameText(const char* text)
    {
        ((void(__cdecl*)(const char*))0x005E5410)(text);
    }

    // --------------------------------------------------------------------------------------------------------------

    void ShowDialogBox(void* pMessageText, void* pBtn1, void* pBtn2, int pBtn1_Column, int pBtn2_Column)
    {
        if (InDialogBox) return;

        InDialogBox = 1;
        VisibleDialog = 1;
        dword_7C8760 = 0;
        dword_7C8764 = 1;
        TitleDialogBox = (int)pMessageText;
        Btn1DialogBox = (int)pBtn1;
        Btn2DialogBox = (int)pBtn2;
        Btn1Pos = pBtn1_Column - 1;
        Btn2Pos = pBtn2_Column - 1;
    }

    void HideDialogBox()
    {
        if (!InDialogBox && !VisibleDialog) return;
        InDialogBox = 0;
        VisibleDialog = 0;
        g_Dialog.waiting = false;
    }

    void ShowDialogBoxEx(void* pMessageText, void* pBtn1, void* pBtn2, tDialogCallback callback, int pBtn1_Column, int pBtn2_Column)
    {
        if (InDialogBox) return;

        ShowDialogBox(pMessageText, pBtn1, pBtn2, pBtn1_Column, pBtn2_Column);
        g_Dialog.waiting = true;
        g_Dialog.callback = callback;
    }

    void UpdateDialogBox()
    {
        if (!g_Dialog.waiting) return;
        if (!InDialogBox || !VisibleDialog) return;

        int button = (selectedDialog == 0) ? 1 : 2;

        if (g_Dialog.callback)
            g_Dialog.callback(button);

        HideDialogBox();
    }

    // --------------------------------------------------------------------------------------------------------------

    void InstallHook()
    {
        // Nada por enquanto
    }
}