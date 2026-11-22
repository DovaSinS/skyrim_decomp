// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// PathingCell: GUESS(low); the class is the placeholder owner; layout is a minimal stand-in
// Func4: CRASHLOGGER_PDB(59818@2026.10.24)
// PathingCellInfo: CRASHLOGGER_PDB(59818@2026.10.24); the two words at 0x10 and 0x14 are its fields
// ValueVisitor, Visit: GUESS(low); a callee object whose slot 1 takes a pointer to a 32-bit value
// unk10: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk14: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ValueVisitor
{
public:
    virtual void unk00();
    virtual void Visit(std::uint32_t* a_value);
};

class PathingCell
{
public:
    void Func4(ValueVisitor* a_visitor);

    std::uint8_t  pad00[0x10];
    std::uint32_t unk10;  // 10
    std::uint32_t unk14;  // 14
};
