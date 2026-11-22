// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// NiFogProperty, m_uFlags, m_fDepth, m_kNearColor, m_kFarColor: SYMBOLS(fo4-pdb)
// NiFogProperty::NiFogProperty: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObjectNET: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only its constructor and size are declared
// NiColor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); r, g, b only
// BLACK: GUESS(low); the pack names the global only by address
#pragma once

#include <cstdint>
#include <cstddef>

struct NiColor
{
    NiColor() : r(0.0f), g(0.0f), b(0.0f) {}

    float r;
    float g;
    float b;

    static const NiColor BLACK;
};

class NiObjectNET
{
public:
    NiObjectNET();
    virtual ~NiObjectNET();

    unsigned char unk08[0x28];
};
static_assert(sizeof(NiObjectNET) == 0x30, "NiObjectNET stand-in size");

class NiFogProperty : public NiObjectNET
{
public:
    NiFogProperty();
    ~NiFogProperty() override;

    std::uint16_t m_uFlags;
    std::uint16_t pad32;
    float m_fDepth;
    NiColor m_kNearColor;
    NiColor m_kFarColor;
};
static_assert(sizeof(NiFogProperty) == 0x50, "NiFogProperty size");
