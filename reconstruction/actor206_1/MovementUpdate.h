// MovementUpdate: STANDIN GUESS(low); receiver identity is provisional.
// Build sse-steam-1-7-104. Labels: v2
// Source exposure: mixed (binary-analysis and community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction; community declarations as noted.
// Compared: Function6a9570. RVA 0x6a9570, 35 bytes.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Ordinary receiver, argument and return identity remain unknown.
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
// MovementUpdate, MovementArgument, MovementController: STANDIN GUESS(low); types and semantics provisional.
struct MovementArgument { std::uint8_t unknown00[0x10]; std::uint8_t value; };
struct MovementController { void Apply(std::uint8_t); };
class MovementUpdate : public P206Target::ActorTargetPrefix<P206Target::ExtraDataListPrefix, P206Target::AIProcess, MovementController> {
public: int Function6a9570(MovementArgument* argument);
};
}
