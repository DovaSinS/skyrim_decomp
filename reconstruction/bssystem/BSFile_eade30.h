// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSFile::FlushBuffer: CRASHLOGGER_PDB(59818@2026.10.24); the PDB class is NiFile
// BSFile: STANDIN GUESS(low); only the members FlushBuffer touches
// BSFile::bufferFill24, BSFile::bufferUsed28, BSFile::buffer30, BSFile::file38, BSFile::writing40, BSFile::good44: GUESS(low)
#pragma once

#include <cstdint>

class BSFile
{
public:
    bool FlushBuffer();

private:
    std::uint8_t unk00[0x24];
    std::uint32_t bufferFill24;
    std::uint32_t bufferUsed28;
    std::uint8_t unk2C[4];
    void* buffer30;
    void* file38;
    std::uint32_t writing40;
    bool good44;
};
