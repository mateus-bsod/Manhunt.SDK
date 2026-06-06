#pragma once

void __cdecl hkPrint(void* logger, const char* text);
int __fastcall hkLoadTexture(void* ecx, void*, const char* str);

void InitHooks();
