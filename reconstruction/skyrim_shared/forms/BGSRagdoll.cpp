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

// The flags word of TESForm sits in the shared declaration's padding; this view names it.
struct FormFlagsView
{
    std::uint8_t pad00[0x10];
    std::uint32_t formFlags;
};

void BGSRagdoll::InitItemImpl()
{
    if (!TestBit(reinterpret_cast<const FormFlagsView*>(this)->formFlags, 3)) {
        std::uint32_t id = unk1A8Id;
        if (id) {
            TESFile* file = GetFile(reinterpret_cast<TESForm*>(this), -1);
            AddCompileIndex(&id, file);
            unk1A8 = dynamic_cast<RagdollRefForm*>(LookupByID(id));
        }
        id = unk1B0Id;
        if (id) {
            TESFile* file = GetFile(reinterpret_cast<TESForm*>(this), -1);
            AddCompileIndex(&id, file);
            unk1B0 = dynamic_cast<RagdollRefForm2*>(LookupByID(id));
        }
        SetFormFlag(this, true);
    }
}
