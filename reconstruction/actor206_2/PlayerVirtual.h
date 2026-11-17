// Build: sse-steam-1-7-104.
// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Drafted by gpt-6.1-terra.
// RVA 0x747af0, 53 bytes; RVA 0x748c50, 54 bytes;
// Evidence: findings/community-resources.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Target-bound primary slots have public names; numbered slots are unknown scaffolding.
// Labels: v2
// PlayerVirtual: STANDIN GUESS(low); partial receiver view, not a complete class.
// Get3D2, GetBiped2, Is3rdPersonVisible, SetDelete, SetAltered, GetDecalGroup: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BipedPointer, DecalGroup, ExtraListVirtual, Apply3D, Reset, Finish, Clear, Function2f54f0, Function2f3980, Function2e4040, GetBase3D, GetBaseBiped, Slot: STANDIN GUESS(low); inferred support declarations.
//
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
#include "VirtualREFR.h"
namespace P2062 {
class PlayerVirtual : public VirtualREFR {
  std::uint64_t unknownA0[0x10b];
  BipedPointer largeBiped;
  NiAVObject* firstPerson3D;
public:
  NiAVObject* Get3D2() const override;
  const BipedPointer& GetBiped2() const override;
  NiAVObject* GetBase3D() const;
  const BipedPointer& GetBaseBiped() const;
};
}
