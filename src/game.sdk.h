//----------------------------------------------------------
//
// Manhunt.SDK Modification For Manhunt 1 (2003)
// Copyright © Manhunt.SDK team
//
//                 Mateus "maph0rip" Mesquita
//
//----------------------------------------------------------

#pragma once
#include "../framework.h"

#define EXCEPTION_SDK ( MyExceptionFilter(GetExceptionInformation()) )

#define PATCH(addr, value, size) do { \
    DWORD old; \
    VirtualProtect((PVOID)(addr), size, PAGE_EXECUTE_READWRITE, &old); \
    memset((PVOID)(addr), value, size); \
    VirtualProtect((PVOID)(addr), size, old, &old); \
} while(0)

//

struct Vector {
	float x;
	float y;
	float z;
};


//

template <unsigned int address, typename... Args>
static void Call(Args... args) {
	reinterpret_cast<void(__cdecl*)(Args...)>(address)(args...);
}

template <typename Ret, unsigned int address, typename... Args>
static Ret CallAndReturn(Args... args) {
	return reinterpret_cast<Ret(__cdecl*)(Args...)>(address)(args...);
}

template <unsigned int address, typename C, typename... Args>
static void CallMethod(C _this, Args... args) {
	reinterpret_cast<void(__thiscall*)(C, Args...)>(address)(_this, args...);
}

template <typename Ret, unsigned int address, typename C, typename... Args>
static Ret CallMethodAndReturn(C _this, Args... args) {
	return reinterpret_cast<Ret(__thiscall*)(C, Args...)>(address)(_this, args...);
}

// -----------------------------------------------------------

void ClearConsole();

// -----------------------------------------------------------

int MyExceptionFilter(EXCEPTION_POINTERS* ep);
