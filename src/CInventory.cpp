#include "../framework.h"

typedef int(__thiscall* tSub_4C7140)(
    void* _this,
    DWORD* player,
    int a3,
    int a4,
    int a5);

tSub_4C7140 oSub_4C7140 =
(tSub_4C7140)0x4C7140;

int __fastcall hkSub_4C7140(
    void* _this,
    void*,
    DWORD* player,
    int a3,
    int a4,
    int a5)
{
    int itemData = *(int*)((char*)_this + 124);

    int itemId = -1;
    int slot = -1;

    if (itemData)
    {
        itemId = *(int*)(itemData + 356);
        slot = *(int*)(itemData + 360);
    }

    printf(
        "[4C7140] this=%p item=%d slot=%d "
        "a3=%d a4=%d a5=%d\n",
        _this,
        itemId,
        slot,
        a3,
        a4,
        a5);

    int ret = oSub_4C7140(
        _this,
        player,
        a3,
        a4,
        a5);

    printf(
        "[4C7140] ret=%d\n",
        ret);

    return ret;
}

typedef int(__thiscall* tSub_4CAA10)(
    void* _this,
    DWORD* player,
    int a3,
    int a4,
    int a5);

tSub_4CAA10 oSub_4CAA10 =
(tSub_4CAA10)0x4CAA10;

int __fastcall hkSub_4CAA10(
    void* _this,
    void*,
    DWORD* player,
    int a3,
    int a4,
    int a5)
{
    int itemData = *(int*)((char*)_this + 124);

    int itemId = -1;
    int slot = -1;

    if (itemData)
    {
        itemId = *(int*)(itemData + 356);
        slot = *(int*)(itemData + 360);
    }

    int obj428 =
        *(int*)((char*)_this + 428);

    int type428 = -1;

    if (obj428)
    {
        type428 =
            ((int(__thiscall*)(int))
                0x4F8150)(obj428);
    }

    printf(
        "[4CAA10] this=%p item=%d slot=%d "
        "a3=%d a4=%d a5=%d "
        "obj428=%08X type=%d\n",
        _this,
        itemId,
        slot,
        a3,
        a4,
        a5,
        obj428,
        type428);

    int ret = oSub_4CAA10(
        _this,
        player,
        a3,
        a4,
        a5);

    printf(
        "[4CAA10] ret=%d\n",
        ret);

    return ret;
}