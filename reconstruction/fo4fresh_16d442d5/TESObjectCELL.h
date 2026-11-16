// TESObjectCELL, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x2c4c20, 24 bytes: TESObjectCELL::IsFormTypeChild
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectCELL.cpp:2801 (TESObjectCELL::IsFormTypeChild)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// TESObjectCELL, IsFormTypeChild, type: GUESS(low)
#pragma once

class TESObjectCELL
{
public:
    bool IsFormTypeChild(unsigned char type);
};
