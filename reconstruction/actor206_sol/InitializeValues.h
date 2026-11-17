// InitializeValues: build sse-steam-1-7-104, RVA 0x6ad3b0, 43 bytes.
// Labels: v2
// InitializeValues: STANDIN GUESS(low); target-bound partial ABI view, original method spelling unknown.
// Source exposure: mixed (target access observations and public type declarations).
// Origin: original reconstruction; typed prefix declarations adapted under the source notice below.
// Drafted by gpt-6.1-sol.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Only the named entry is compared; callees are declarations and names/signatures remain inferred.
// No complete size, ownership, original name or behaviour claim.
// Supporting declaration names: GUESS(low); descriptive spelling for independently bound callees.
// Prefix type names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
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
#include "actors/ActorTargetPrefix.h"
#include "actors/PlayerCharacterTargetMembers.h"
namespace P206Target { class TESBoundObject { public: void InitializeValues(bool); }; }
namespace P206Sol {
class InitializeValues : public P206Target::ActorTargetPrefix<> { public: void Initialize(); void Reset(bool); void Finish(); };
}
