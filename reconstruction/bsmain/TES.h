// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Code origin: original declarations with the cited sibling adaptations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:158 (TES::GetLandMaterialType)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:702 (TES::ResumeMasterFileLoads)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:695 (TES::CancelMasterFileLoads)
// TES::GetLandMaterialType, TES::ResumeMasterFileLoads, TES::CancelMasterFileLoads: SIBLING(fo4-private@1b765c70, author-permission)
// BGSDynamicPersistenceManager, instance, Pause, Resume, ExteriorCellLoader, loader, CancelAllCellLoads: GUESS(low)
// TES, GetLandMaterialType, NiPoint3, TESLandTexture, GetLandTexture, GetHavokMaterialType, coord: GUESS(low)
// TES::GetWorldSpace: GUESS(low); getter identified by the field it reads
// TESWorldSpace, worldSpace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk000, unk13D, unk150, unk2AC: GUESS(low); unaccessed regions between the named members
// Function1a9280, Function1aa2d0, field13C, field2A8: GUESS(low)
#pragma once

#include <cstddef>
class NiPoint3;
class TESWorldSpace;
class TESLandTexture { public: unsigned int GetHavokMaterialType(); };
class BGSDynamicPersistenceManager { public: static BGSDynamicPersistenceManager* instance; void Pause(); void Resume(); };
class ExteriorCellLoader { public: void CancelAllCellLoads(); };
extern ExteriorCellLoader* loader;
// Function1a2200, Function1a2200Arg, kind, a_flag: GUESS(low); the receiver, the argument type and the byte at 0x44 are unidentified
struct Function1a2200Arg { unsigned char unk00[0x44]; unsigned char kind; };
class TES {
public:
    TESWorldSpace* GetWorldSpace() const;
    bool Function1a2200(const Function1a2200Arg* a_arg, bool a_flag) const;
    void ResumeMasterFileLoads();
    void CancelMasterFileLoads();
    TESLandTexture* GetLandTexture(const NiPoint3& coord);
    unsigned int GetLandMaterialType(const NiPoint3& coord);
    TES* ScalarDeletingDestructor(unsigned a_flags);
    void Function1a9280(unsigned char value);
    void Function1aa2d0();

    unsigned char unk000[0x13C];
    unsigned char field13C;
    unsigned char unk13D[0x148 - 0x13D];
    TESWorldSpace* worldSpace;
    unsigned char unk150[0x2A8 - 0x150];
    unsigned int field2A8;
    unsigned char unk2AC[0x2C0 - 0x2AC];
};
static_assert(offsetof(TES, worldSpace) == 0x148, "TES worldspace offset");
static_assert(offsetof(TES, field13C) == 0x13C, "TES field13C offset");
static_assert(offsetof(TES, field2A8) == 0x2A8, "TES field2A8 offset");
static_assert(sizeof(TES) == 0x2C0, "TES size");

void DestroyTES(TES* a_world);
void FreeTES(TES* a_world, std::size_t a_size);
