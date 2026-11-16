// ExtraDataList, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// ExtraDataList: EXE_RTTI
// Compared functions:
// RVA 0x173340, 45 bytes: ExtraDataList::Function173340.
// RVA 0x172b40, 46 bytes: ExtraDataList::Function172b40.
// RVA 0x172f60, 46 bytes: ExtraDataList::Function172f60.
// RVA 0x16fd20, 49 bytes: ExtraDataList::Function16fd20.
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
const char* ExtraDataList::Function173340() {
 auto data = static_cast<ExtraCellWaterEnvMap*>(GetByType(0xa6));
 if (data && data->waterEnvMap.textureName && *data->waterEnvMap.textureName) return data->waterEnvMap.textureName;
 return defaultTexture;
}
void ExtraDataList::Function172b40(void* value) {
 auto data = static_cast<ExtraAliasInstanceArray*>(GetByType(0x88));
 if (data) data->ApplyFirst(value);
}
void ExtraDataList::Function172f60(void* value) {
 auto data = static_cast<ExtraAliasInstanceArray*>(GetByType(0x88));
 if (data) data->ApplySecond(value);
}
void ExtraDataList::Function16fd20() {
 auto data = GetByType(0x57);
 if (data) RemoveData(data, true);
}
