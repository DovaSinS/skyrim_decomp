// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/BSCore/BSSafeSleep.h:7
// Sibling source: fo4-private@1b765c70 src/BSCore/BSSafeSleep.h:12
// BSReadWriteLock, BSReadWriteLock::_writerThread, ::_lock, ::LockForWrite: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSReadWriteLock::kLockWrite, ::kLockCountMask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSSafeSleep, BSSafeSleep::Sleep: SIBLING(fo4-private@1b765c70, author-permission)
// BSSafeSleep::uiCounter: SIBLING(fo4-private@1b765c70, author-permission); used by the inline bodies in src/BSCore/BSSafeSleep.h
// GetCurrentThreadId, Sleep: OBSERVED; kernel32 imports called by the target
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);

class BSSafeSleep
{
public:
    BSSafeSleep();
    void Sleep();

private:
    std::uint32_t uiCounter;  // 0
};

inline BSSafeSleep::BSSafeSleep()
    : uiCounter()
{
}

inline void BSSafeSleep::Sleep()
{
    if (uiCounter < 10000) {
        ++uiCounter;
        ::Sleep(0);
    } else {
        ::Sleep(1);
    }
}

class BSReadWriteLock
{
public:
    enum : std::uint32_t
    {
        kLockWrite = 0x80000000,
        kLockCountMask = 0xFFFFFFF
    };

    void LockForWrite();  // compared: 0xce32d0

private:
    std::uint32_t _writerThread;   // 0
    volatile std::uint32_t _lock;  // 4
};
