// HandleQuery: STANDIN GUESS(low); receiver and helper identities are provisional.
// Build sse-steam-1-7-104. Labels: v2
// Source exposure: mixed (binary-analysis, community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction, community declarations as noted.
// Compared: Function69c120. RVA 0x69c120, 52 bytes.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Unaccessed regions are unknown; no complete layout is asserted.
// CommonLibSSE-NG MIT licence notice:
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
namespace P2061 {
// HandleQuery, supporting interfaces: STANDIN GUESS(low); names and ABI are provisional.
class HandleQuery;
struct ProcessQuery { void Query(std::uint32_t*); }; extern std::uint32_t invalidHandle;
class HandleQuery : public P206Target::ActorTargetPrefix<P206Target::ExtraDataListPrefix, ProcessQuery> { public: std::uint32_t* Function69c120(std::uint32_t*); };
}
