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
// GPL declaration source: powerof3/CommonLibSSE; full pin 654e55f7979c1733033d5dbef176e43827bac944.
// Build: sse-steam-1-7-104; task p172; private draft, no acceptance.
// Source exposure: mixed; binary-analysis and community declarations.
// Drafted by GPT-6.1 Sol (p172); original C++ bodies.
// Evidence: findings/p92-unit-supply-selection.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Compared: RVA 0x26d480, 3 bytes; RVA 0x26d4b0, 3 bytes; RVA 0x26d4c0, 3 bytes.
// ResearchReturns, BSGeometryReturns: GUESS(low) STANDIN
// Adapted bodies: none. Community declarations inform signatures only.
// Labels: v2
// BSGeometry, BSMultiIndexTriShape, BSSkinnedDecalTriShape, AsMultiIndexTriShape,
// AsSkinnedDecalTriShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetVisibleGroupsTriangleCount: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// ABI view declares only the selected methods; no original class layout is claimed.
// Original reconstruction; no external implementation copied. A pass proves code only.
#pragma once
#include <cstdint>
class BSMultiIndexTriShape;
class BSSkinnedDecalTriShape;
namespace ResearchReturns {
class BSGeometryReturns {
public:
    virtual std::uint32_t GetVisibleGroupsTriangleCount();
    virtual BSMultiIndexTriShape* AsMultiIndexTriShape();
    virtual BSSkinnedDecalTriShape* AsSkinnedDecalTriShape();
};
}
