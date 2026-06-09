#include "CText.h"

namespace CText
{
    wchar_t* GetKey(const char* key)
    {
        return CallMethodAndReturn<wchar_t*, 0x4937E0, int, const char*>(0x725A38, key);
    }

    wchar_t* KeyEx(const char* str)
    {
        int len = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
        wchar_t* out = (wchar_t*)malloc(len * sizeof(wchar_t));
        MultiByteToWideChar(CP_ACP, 0, str, -1, out, len);
        return out;
    }
}