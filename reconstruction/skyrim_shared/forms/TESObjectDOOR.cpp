// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); body written from the listing of the pinned image, except InitializeData, which is close to the sibling body named below
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: TESObjectDOOR::InitializeData is close to the sibling body (tools/check_origin.py similarity 0.75).
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObjectDOOR.cpp:77
// TESObjectDOOR::InitializeData: SIBLING(fo4-private@1b765c70, author-permission)
// 0x282a30 TESObjectDOOR::InitializeData
// 0x2831c0 TESObjectDOOR::IsSliding
// 0x2830d0 TESObjectDOOR::Function2830d0
// 0x283170 TESObjectDOOR::Function283170
// 0x284a70 TESObjectDOOR::Function284a70
// TESObjectDOOR::IsSliding: GUESS(low)
// TESObjectDOOR::Function2830d0, Function283170, Function284a70: GUESS(low)
#include "TESObjectDOOR.h"

bool TESObjectDOOR::IsSliding() const
{
    return (flags & kSliding) != 0;
}

void TESObjectDOOR::InitializeData()
{
    openSound = nullptr;
    closeSound = nullptr;
    loopSound = nullptr;
    flags = 0;
}

bool TESObjectDOOR::Function283170() const
{
    return (flags >> 3) & 1;
}

bool TESObjectDOOR::Function2830d0() const
{
    return (flags >> 1) & 1;
}

bool TESObjectDOOR::Function284a70() const
{
    return randomTeleports._size > 0;
}
