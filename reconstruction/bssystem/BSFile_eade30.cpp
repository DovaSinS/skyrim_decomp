// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xeade30 BSFile::FlushBuffer
// Adapted bodies: none
#include "BSFile_eade30.h"

extern "C" __declspec(dllimport) unsigned long long __cdecl fwrite(const void* buffer, unsigned long long size, unsigned long long count, void* file);

bool BSFile::FlushBuffer()
{
    if (writing40 == 0) {
        bufferFill24 = 0;
    } else if (std::uint32_t pending = bufferUsed28) {
        if (static_cast<std::uint32_t>(fwrite(buffer30, 1, pending, file38)) != bufferUsed28) {
            good44 = false;
            return false;
        }
    }
    bufferUsed28 = 0;
    return true;
}
