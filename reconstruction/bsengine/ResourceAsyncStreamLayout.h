// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (community declarations and target copy/construction/RTTI analysis).
// Drafted by GPT-6.1 Sol; p175 resource stream storage recovery.
// Labels: v2
// Code origin: original empty destructor stand-ins using independently represented fields; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/StreamBase.h and include/RE/A/AsyncStream.h; MIT.
// StreamBase, AsyncStream, totalSize, flags, minPacketSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ResourceStreamBaseLayout, ResourceAsyncStreamLayout: GUESS(medium) STANDIN
// object: GUESS(low)
// The pinned community totalSize is narrower than the target: target copy/clone code independently accesses a qword at 8 and a dword of flags at 16.
// Async clone code separately copies a dword at 24. Names follow community declarations; target member widths/offsets are independently observed.
// Compiler alignment supplies trailing space; no explicit padding or allocation-sized storage array is used.
// Only the listed scalar deleting code is compared; omitted methods, original type names and gameplay behavior are not claimed.
// Empty destructor bodies are inferred stand-ins for the compared leaf code, not copied upstream bodies.
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
#include "ResourceStreamBaseLayout.h"
namespace ResearchLayouts {
class ResourceAsyncStreamLayout : public ResourceStreamBaseLayout {
public:
    ~ResourceAsyncStreamLayout() override {}
    std::uint32_t minPacketSize;
};
static_assert(sizeof(ResourceAsyncStreamLayout) == 32, "represented async resource stream");
static_assert(offsetof(ResourceAsyncStreamLayout, minPacketSize) == 24, "observed target packet field");
}
