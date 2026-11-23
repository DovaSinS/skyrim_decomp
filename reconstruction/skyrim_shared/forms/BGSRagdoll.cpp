// Source exposure: mixed (community headers; the pinned image listing).
// 0x39e610 BGSRagdoll::InitItemImpl
// Code origin: original body from the pinned image listing; names and declarations follow CommonLibSSE-NG, except TestBit, which is close to the sibling helper named below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: TestBit is close to the sibling helper (tools/check_origin.py similarity 0.82).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// TestBit: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
#include "BGSRagdoll.h"

#include <cstdint>

namespace
{
    inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
    {
        return ((a_flags >> a_bit) & 1) != 0;
    }
}

class TESFile;
class TESForm;
class SourceForm
{
public:
    virtual ~SourceForm();
};

// RagdollRefForm, RagdollRefForm2: GUESS(low) STANDIN; the cast target's real type name is unknown, so it is not named TESForm.
class RagdollRefForm : public SourceForm {};
class RagdollRefForm2 : public SourceForm {};

extern TESFile* GetFile(TESForm* a_form, int a_arg);
extern void AddCompileIndex(std::uint32_t* a_id, TESFile* a_file);
extern SourceForm* LookupByID(std::uint32_t a_id);
extern void SetFormFlag(BGSRagdoll* a_self, bool a_set);

void BGSRagdoll::InitItemImpl()
{
    const std::uint32_t flags = *reinterpret_cast<const std::uint32_t*>(
        reinterpret_cast<const std::uint8_t*>(this) + 0x10);
    if (!TestBit(flags, 3)) {
        std::uint8_t* self = reinterpret_cast<std::uint8_t*>(this);
        std::uint32_t id = *reinterpret_cast<const std::uint32_t*>(self + 0x1A8);
        if (id) {
            TESFile* file = GetFile(reinterpret_cast<TESForm*>(this), -1);
            AddCompileIndex(&id, file);
            *reinterpret_cast<RagdollRefForm**>(self + 0x1A8) = dynamic_cast<RagdollRefForm*>(LookupByID(id));
        }
        id = *reinterpret_cast<const std::uint32_t*>(self + 0x1B0);
        if (id) {
            TESFile* file = GetFile(reinterpret_cast<TESForm*>(this), -1);
            AddCompileIndex(&id, file);
            *reinterpret_cast<RagdollRefForm2**>(self + 0x1B0) = dynamic_cast<RagdollRefForm2*>(LookupByID(id));
        }
        SetFormFlag(this, true);
    }
}
