//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#include "game.sdk.h"


int MyExceptionFilter(EXCEPTION_POINTERS* ep)
{
    Console::Printf("Code: %08X",
        ep->ExceptionRecord->ExceptionCode);

    Console::Printf("EIP: %08X",
        ep->ContextRecord->Eip);

    return EXCEPTION_EXECUTE_HANDLER;
}

// --------------------------------------------------------------------------------

void ClearConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD count;

    FillConsoleOutputCharacter(
        hConsole,
        ' ',
        cellCount,
        { 0, 0 },
        &count
    );

    FillConsoleOutputAttribute(
        hConsole,
        csbi.wAttributes,
        cellCount,
        { 0, 0 },
        &count
    );

    SetConsoleCursorPosition(hConsole, { 0, 0 });
}