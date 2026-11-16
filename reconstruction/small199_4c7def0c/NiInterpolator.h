// NiInterpolator, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Base declarations are partial stand-ins; no complete vtable layout is claimed.
// Compared functions:
// RVA 0xf6cd70, 40 bytes: NiInterpolator::Functionf6cd70.
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
// NiInterpolator, NiObject, NiRefObject, lastTime, pad14, _refCount, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiInterpolator::NiInterpolator: GUESS(low)
#pragma once
#include <cstdint>
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); std::uint32_t _refCount; std::uint32_t _pad0C; };
class NiObject : public NiRefObject { public: NiObject(); virtual ~NiObject(); };
class NiInterpolator : public NiObject { public: NiInterpolator(); float lastTime; std::uint32_t pad14; };
