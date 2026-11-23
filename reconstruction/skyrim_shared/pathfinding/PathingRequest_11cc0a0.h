// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PathingRequest, PathingRequest::sub_1410B9F40: CRASHLOGGER_PDB(59818@2026.10.24); the unit keeps the placeholder class and method Function11cc0a0
// PathingRequest::Function11cc0a0, PathField, PathField::Read, PathingRequest::flags82, PathingRequest::flagsD0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct PathField
{
    std::uint64_t* Read();
};

class PathingRequest
{
public:
    bool Function11cc0a0();

    unsigned char pad00[0x10];
    PathField field10;  // 10
    unsigned char pad11[0x58 - 0x11];
    PathField field58;  // 58
    unsigned char pad59[0x82 - 0x59];
    std::uint8_t flags82;  // 82
    unsigned char pad83[0xD0 - 0x83];
    std::uint8_t flagsD0;  // D0
};
