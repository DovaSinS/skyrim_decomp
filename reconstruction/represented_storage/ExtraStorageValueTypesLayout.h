// Build: sse-steam-1-7-104
// Source exposure: community-headers
// Labels: v2
// Code origin: public lock fields and enum widths adapted to storage-only declarations; no method bodies.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BSAtomic.h,M/MagicSystem.h,E/EffectArchetypes.h,D/DisguiseEffect.h,A/ActionInput.h,B/BSStorage.h}; MIT.
// BSReadWriteLock, SpellType, EffectArchetype: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DisguiseStateStorageLayout, ExtraStorageValueTypesLayout: GUESS(medium) STANDIN
// Enum values, lock operations and ownership behavior are outside this data-storage claim.
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
#include "LayoutValueTypes.h"
namespace ResearchLayouts {
using uint16_t=std::uint16_t;
using uint32_t=std::uint32_t;
namespace MagicSystem { enum class SpellType : std::int32_t {}; }
enum class EffectArchetype : std::int32_t {};
enum class DisguiseStateStorageLayout : std::int32_t {};
struct BSReadWriteLock { volatile std::uint32_t _writerThread; volatile std::uint32_t _lock; };
static_assert(sizeof(BSReadWriteLock)==8,"public lock storage");
static_assert(offsetof(BSReadWriteLock,_writerThread)==0,"public writer identity offset");
static_assert(offsetof(BSReadWriteLock,_lock)==4,"public lock word offset");
static_assert(sizeof(MagicSystem::SpellType)==4,"public enum width");
static_assert(sizeof(EffectArchetype)==4,"public enum width");
static_assert(sizeof(DisguiseStateStorageLayout)==4,"public enum width");
class ExtraStorageValueTypesLayout {};
}
