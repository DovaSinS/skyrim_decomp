// NiPathInterpolator, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted NiBinaryStream prefix declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// NiPathInterpolator: STANDIN GUESS(low)
// Compared functions:
// RVA 0xf66e30, 45 bytes: NiPathInterpolator::Functionf66e30.
// RVA 0xf66eb0, 45 bytes: NiPathInterpolator::Functionf66eb0.
// RVA 0xf66ee0, 48 bytes: NiPathInterpolator::Functionf66ee0.
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
#include "NiPathInterpolator.h"
void NiPathInterpolator::Functionf66e30(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 2;
 stream->_absoluteCurrentPos += stream->_readFn(stream, buffer, count * 2, &size, 1);
}

void NiPathInterpolator::Functionf66eb0(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 2;
 stream->_absoluteCurrentPos += stream->_writeFn(stream, buffer, count * 2, &size, 1);
}

void NiPathInterpolator::Functionf66ee0(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 4;
 stream->_absoluteCurrentPos += stream->_writeFn(stream, buffer, size, &size, 1);
}
