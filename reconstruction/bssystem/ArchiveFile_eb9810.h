// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ArchiveFile: STANDIN GUESS(low); the class is the placeholder owner
// hkpAllRayHitTempCollector::AddRayHit: CRASHLOGGER_PDB(59818@2026.10.24); placeholder name of the compared function
// _readFn, _writeFn: GUESS(low); named after the members of the community stream base class at the same offsets
// ArchiveFile::InstallStreamFunctions, ArchiveFile::InstallAlternate, ArchiveFile::ReadBytes, ArchiveFile::WriteBytes, unk00, unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ArchiveFile
{
public:
    using ReadFn = std::uint32_t(ArchiveFile*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using WriteFn = std::uint32_t(ArchiveFile*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    void InstallStreamFunctions(bool a_alternate);
    void InstallAlternate(bool a_alternate);
    static std::uint32_t ReadBytes(ArchiveFile* a_file, void* a_buffer, std::uint32_t a_size, std::uint32_t* a_width, std::uint32_t a_count);
    static std::uint32_t WriteBytes(ArchiveFile* a_file, const void* a_buffer, std::uint32_t a_size, std::uint32_t* a_width, std::uint32_t a_count);

    void* unk00;
    std::uint64_t unk08;
    ReadFn* _readFn;
    WriteFn* _writeFn;
};
static_assert(offsetof(ArchiveFile, _writeFn) == 0x18, "write function offset");
