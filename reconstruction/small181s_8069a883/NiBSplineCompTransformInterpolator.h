// NiBSplineCompTransformInterpolator reconstruction, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// Drafted by: gpt-6.1-sol
// NiBSplineCompTransformInterpolator names and signatures: GUESS(low)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0xf79af0 (19 bytes).
// Names and signatures are unverified guesses. Supporting declarations compile the compared functions.
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

#pragma once
// NiBSplineCompTransformInterpolator, NiBSplineTransformInterpolator: EXE_RTTI
// NiStream, NiBSplineCompTransformInterpolator::RegisterStreamables, NiBSplineTransformInterpolator::RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiStream;
class NiBSplineTransformInterpolator { public: bool RegisterStreamables(NiStream&); };
class NiBSplineCompTransformInterpolator : public NiBSplineTransformInterpolator { public: bool RegisterStreamables(NiStream&); };
