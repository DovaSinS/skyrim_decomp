// BSEffectShaderProperty, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted NiBinaryStream prefix declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// BSEffectShaderProperty: STANDIN GUESS(low)
// Compared functions:
// RVA 0x152a9a0, 46 bytes: BSEffectShaderProperty::Function152a9a0.
// RVA 0x152a9d0, 46 bytes: BSEffectShaderProperty::Function152a9d0.
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
// NiBinaryStream, _absoluteCurrentPos, _pad0C, _readFn, _writeFn, ReadFn, WriteFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSEffectShaderProperty, Function152a9a0, Function152a9d0: STANDIN GUESS(low)
class NiBinaryStream {
public:
 virtual ~NiBinaryStream();
 using ReadFn = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
 using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
 std::uint32_t _absoluteCurrentPos;
 std::uint32_t _pad0C;
 ReadFn* _readFn;
 WriteFn* _writeFn;
};
class BSEffectShaderProperty { public:
 static void Function152a9a0(NiBinaryStream* stream, void* buffer, std::uint32_t count);
 static void Function152a9d0(NiBinaryStream* stream, void* buffer, std::uint32_t count);
};
