// TESEscortPackageData, build sse-steam-1-7-104: RVA 0x4a0ac0, 119 bytes Compare; RVA 0x4a0b50, 115 bytes SaveGame.
// Labels: v2
// Source exposure: mixed (pinned image listing, public declarations and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// TESEscortPackageData::Compare: SIBLING(fo4-private@1b765c70, author-permission); adapted comparison.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataEscort.cpp:52
// TESEscortPackageData::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted save sequence.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataEscort.cpp:76
// Drafted by gpt-6.1-sol.
// Evidence: findings/ghidra-import.md; Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// TESPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) GUESS(low); adapted declaration, target type identity unverified.
// TESEscortPackageData: GUESS(low); qualified-name hint, target type identity unverified.
// TESEscortPackageData::searchLocation, TESEscortPackageData::followRadius, Location, Location::Compare, Location::SaveGame, BGSSaveFormBuffer, BGSSaveFormBuffer::SaveData: GUESS(low); inferred from target accesses and sibling.
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
#include "TESEscortPackageData.h"
bool TESEscortPackageData::Compare(TESPackageData* src) { auto* p = dynamic_cast<TESEscortPackageData*>(src); if (!p) return true; if (searchLocation) { if (searchLocation->Compare(p->searchLocation)) return true; } else if (p->searchLocation) return true; if (followRadius != p->followRadius) return true; return false; }
void TESEscortPackageData::SaveGame(BGSSaveFormBuffer* b) { b->SaveData(&followRadius, 4, 4, false); bool hasLocation = searchLocation != nullptr; b->SaveData(&hasLocation, 1, 1, false); if (hasLocation) searchLocation->SaveGame(b); }
