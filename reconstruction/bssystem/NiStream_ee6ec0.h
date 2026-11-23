// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStream, NiStream::SaveObjectSizeTable, objectSizes, oStr: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares a 64-bit size parameter, the listing uses only 32 bits, as the 2013 map prototype does
// NiBinaryStream, NiBinaryStream::seek, ::tell, ::_absoluteCurrentPos, ::_writeFn: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream::SaveObjectSizeTable: SYMBOLS(tesv-2013-map); the same name, 32-bit parameter
// NiStream::Func22_140C5C700: CRASHLOGGER_PDB(59818@2026.10.24); placeholder name of the compared function
// unk00, unk08, unk0C, unk10, sizesData, sizesCapacity, sizesCount, unk250: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiBinaryStream
{
public:
    using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    virtual void unk00();
    virtual void unk01();
    virtual void seek(std::int32_t a_offset);
    virtual std::uint32_t tell() const;

    std::uint32_t _absoluteCurrentPos;
    std::uint32_t unk0C;
    void* unk10;
    WriteFn* _writeFn;
};

class NiStream
{
public:
    bool SaveObjectSizeTable(std::uint32_t a_size);

    unsigned char unk00[0x240];
    std::uint32_t* sizesData;
    std::uint32_t sizesCapacity;
    std::uint32_t sizesCount;
    unsigned char unk250[0x50];
    NiBinaryStream* oStr;
};
static_assert(offsetof(NiStream, sizesCount) == 0x24C, "count offset");
static_assert(offsetof(NiStream, oStr) == 0x2A0, "output stream offset");
