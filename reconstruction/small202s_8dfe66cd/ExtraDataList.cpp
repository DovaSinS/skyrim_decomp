// ExtraDataList, build sse-steam-1-7-104.
// Labels: v2
// ExtraDataList, ObjectRefHandle: GUESS(low) STANDIN
// Origin: original reconstruction; partial declarations adapt CommonLibSSE-NG, MIT.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSPointerHandle.h, include/RE/E/ExtraAshPileRef.h, include/RE/E/ExtraDataList.h.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-sol.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// The output-reference interface represents observed ABI storage; no original API identity is claimed.
// Compared functions:
// RVA 0x1672a0, 44 bytes: ExtraDataList::GetAshPileRef.
// RVA 0x169130, 44 bytes: ExtraDataList::GetOpenCloseActivateRef.
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
#include "ExtraDataList.h"
ObjectRefHandle& ExtraDataList::GetAshPileRef(ObjectRefHandle& result) {
  result.value = 0;
  auto data = static_cast<ExtraAshPileRef*>(GetByType(0x85));
  if (data) result = data->ashPileRef;
  return result;
}
ObjectRefHandle& ExtraDataList::GetOpenCloseActivateRef(ObjectRefHandle& result) {
  result.value = 0;
  auto data = static_cast<ExtraOpenCloseActivateRef*>(GetByType(0x68));
  if (data) result = data->activateRef;
  return result;
}
