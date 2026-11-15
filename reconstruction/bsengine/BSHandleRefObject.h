// Shared inline reconstruction declarations, build sse-steam-1-7-104.
// Labels: v2
// BSHandleRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// Source exposure: mixed (binary-analysis, community-headers).
// Engineer: GPT-6.1 Sol high; owner awarebayes; task p145.
// Evidence: private pinned-image function analysis; no whole-class layout claim.
// Community source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Minimal declarations from NiRefObject.h and BSHandleRefObject.h.
// Reference release bodies adapt the
// community NiRefObject.cpp and BSHandleRefObject.cpp algorithms with MSVC atomics.
// Host destructor bodies are original reconstructions. Only entries named by
// each host are compared; shared methods inline.
// No FNV implementation was used or read by the drafting Engineer.
// Body origin: original reconstruction with the community adaptations stated above.
// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#pragma once
#include <cstdint>
#include <intrin.h>
namespace p145 {
// NiRefObject, DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
struct NiRefObject {
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long refCount;
    unsigned reserved;
    void DecRefCount() {
        // References cross threads; the final releaser owns deletion.
        if (_InterlockedExchangeAdd(&refCount, -1) == 1) DeleteThis();
    }
};
// refCount, reserved: GUESS(low) STANDIN
// BSHandleRefObject, DecRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
struct BSHandleRefObject : NiRefObject {
    void DecRefCount() {
        // The atomic count shares its word with handle-state flags.
        if (((_InterlockedExchangeAdd(&refCount, -1) - 1) & 0x3ff) == 0) DeleteThis();
    }
};
}
