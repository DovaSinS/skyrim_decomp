// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysStripUpdateModifier::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24); the PDB spells the name with a suffix
// BSPSysStripUpdateModifier::fUpdateDeltaTime: SYMBOLS(fo4-pdb)
// NiPSysModifier, NiStreamBinarySource: STANDIN GUESS(low); only the members LoadBinary touches
// NiPSysModifier::LoadBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only, the stand-in is non-virtual
// BSPSysStripUpdateModifier::unk18, NiStreamBinarySource::position08, NiStreamBinarySource::read10: GUESS(low)
#pragma once

#include <cstdint>

class NiStream;

class NiStreamBinarySource
{
public:
    using ReadFn = std::int32_t (*)(NiStreamBinarySource*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    std::uint8_t unk00[8];
    std::uint32_t position08;
    std::uint32_t unk0C;
    ReadFn read10;
};

class NiStream
{
public:
    std::uint8_t unk00[0x298];
    NiStreamBinarySource* source298;
};

class NiPSysModifier
{
public:
    void LoadBinary(NiStream& stream);

    std::uint8_t unk00[0x18];
    std::uint32_t unk18;
    std::uint8_t unk1C[0x14];
};

class BSPSysStripUpdateModifier : public NiPSysModifier
{
public:
    void LoadBinary(NiStream& stream);

    float fUpdateDeltaTime;
    std::uint8_t unk34[4];
};
