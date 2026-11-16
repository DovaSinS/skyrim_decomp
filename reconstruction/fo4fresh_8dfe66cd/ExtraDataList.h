// ExtraDataList partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x169c30, 36 bytes: ExtraDataList::GetPoison
// GetPoison: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:727
// ExtraDataList::GetPoison: SIBLING(fo4-private@1b765c70, author-permission)
// AlchemyItem, QPoison: STANDIN GUESS(low)
// GetPersistentCell: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:1766
// GetEncounterZone: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:2795
// GetPrimitive: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:2289
// GetCombatStyle: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3240
// GetEnchantment: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3250
// GetRank: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:605
// GetCount: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:677
// RemoveSavedAnimation: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3052
// RemoveSavedHavokData: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3092
// RVA 0x16ff80, 10 bytes: ExtraDataList::RemoveSavedAnimation
// RVA 0x1701b0, 10 bytes: ExtraDataList::RemoveSavedHavokData
// RVA 0x164e50, 33 bytes: ExtraDataList::GetPersistentCell
// RVA 0x16a0a0, 33 bytes: ExtraDataList::GetEncounterZone
// RVA 0x16d850, 33 bytes: ExtraDataList::GetPrimitive
// RVA 0x171550, 33 bytes: ExtraDataList::GetCombatStyle
// RVA 0x1732b0, 33 bytes: ExtraDataList::GetEnchantment
// RVA 0x164600, 37 bytes: ExtraDataList::GetRank
// RVA 0x1648f0, 38 bytes: ExtraDataList::GetCount
// ExtraDataList, ExtraDataList::RemoveSavedAnimation, ExtraDataList::RemoveSavedHavokData, ExtraDataList::GetPersistentCell, ExtraDataList::GetEncounterZone, ExtraDataList::GetPrimitive, ExtraDataList::GetCombatStyle, ExtraDataList::GetEnchantment, ExtraDataList::GetRank, ExtraDataList::GetCount: SIBLING(fo4-private@1b765c70, author-permission)
// Names, signatures, and layout are unverified.
// ExtraData, unknown00, value, GetExtraData, RemoveExtra: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class TESObjectCELL;
class BGSEncounterZone;
class BGSPrimitive;
class TESCombatStyle;
class EnchantmentItem;
class AlchemyItem;
struct ExtraData { AlchemyItem* QPoison(); std::uint64_t unknown00[2]; union { void* value; int rank; short count; }; };
class ExtraDataList {
public:
    TESObjectCELL* GetPersistentCell() const;
    BGSEncounterZone* GetEncounterZone() const;
    BGSPrimitive* GetPrimitive() const;
    TESCombatStyle* GetCombatStyle() const;
    EnchantmentItem* GetEnchantment() const;
    AlchemyItem* GetPoison() const;
    int GetRank() const;
    short GetCount() const;
    void RemoveSavedAnimation();
    void RemoveSavedHavokData();
private:
    ExtraData* GetExtraData(unsigned int) const;
    void RemoveExtra(unsigned int);
};
