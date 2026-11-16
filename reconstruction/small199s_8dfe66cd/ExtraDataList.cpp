// ExtraDataList action flag accessor, build sse-steam-1-7-104, RVA 0x170910, 38 bytes.
// Labels: v2
// Origin: original reconstruction; declarations adapted from CommonLibSSE-NG at the pin below.
// Source exposure: mixed (local binary analysis and public declarations).
// Drafted by gpt-6.1-sol.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Only ReadActionFlags is compared. Names, signatures and layouts remain inferred.
// Inferred names: GUESS(low)
// Public declarations: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, include/RE/E/ExtraAction.h and include/RE/B/BSExtraData.h.
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

std::uint32_t ExtraDataList::ReadActionFlags()
{
    const auto* entry = static_cast<ExtraAction*>(GetByType(13));
    return entry ? static_cast<std::uint8_t>(entry->action) : 1;
}
