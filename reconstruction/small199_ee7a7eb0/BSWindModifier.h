// BSWindModifier, build sse-steam-1-7-104.
// Labels: v2
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0xfd8ba0, 38 bytes: BSWindModifier::Functionfd8ba0.
// MIT License
// Copyright (c) 2018 Ryan-rsm-McKenzie
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// BSWindModifier, NiPSysModifier, strength: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMembers, CopyBase: GUESS(low)
#pragma once
#include <cstdint>
// NiRefObject, _refCount, _pad0C, NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiExtraData, name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyBase: GUESS(low)
class NiRefObject { public: virtual ~NiRefObject(); std::uint32_t _refCount; std::uint32_t _pad0C; };
class NiObject : public NiRefObject {};
class NiExtraData : public NiObject { public: const char* name; };
// NiPSysModifier, name, order, target, active: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// pad1C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiParticleSystem;
class NiPSysModifier : public NiObject { public: const char* name; std::uint32_t order; std::uint32_t pad1C; NiParticleSystem* target; bool active; };

class BSWindModifier : public NiPSysModifier {
public:
    void CopyMembers(BSWindModifier* a_dest);
    float strength;
};
void CopyBase(NiPSysModifier* a_source, NiPSysModifier* a_dest);
