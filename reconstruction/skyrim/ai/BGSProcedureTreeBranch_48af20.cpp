// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x48af20 BGSProcedureTreeBranch::Unk_05
// Adapted bodies: none
#include "BGSProcedureTreeBranch_48af20.h"

void BGSProcedureTreeBranch::Unk_05(void* a_arg, bool a_flag)
{
    const std::uint32_t count = conditions.size;
    for (std::uint32_t i = 0; i < count; ++i) {
        conditions.data[i]->Unk_05(a_arg, a_flag);
    }
}
