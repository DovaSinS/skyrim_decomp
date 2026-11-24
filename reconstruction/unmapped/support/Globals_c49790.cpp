// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00e01710.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00e00000_od_o2_nood_variant.cpp:123
// 0xc49790 Func00e01710
#include "Globals_c49790.h"

void* Func00e01710()
{
    union
    {
        hkObjectE01710* pAligned;
        __declspec(align(16)) unsigned int auiStorage[sizeof(hkObjectE01710) / sizeof(unsigned int)];
    } u;
    FinishingFlag flag;
    new (u.auiStorage) hkObjectE01710(flag);
    return *(void**)u.auiStorage;
}
