// PathingCell, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x4e04b0, 34 bytes: PathingCell::Func8.
// MIT License
// Copyright (c) 2018 Ryan-rsm-McKenzie
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// PathingCell, BSPathingCell, TESObjectCELL, TESForm, TESFullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent, BSSpinLock, cellState, cellFlags, cellGameFlags, formFlags, formID, inGameFormFlags, formType, pad1B, pad1C, sourceFiles, fullName, grassCreateLock, grassTaskLock, _refCount, unk0C, unk10, cellID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetCell, IsAttached: GUESS(low)
#pragma once
#include <cstdint>
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
class TESFullName : public BaseFormComponent { public: const char* fullName; };
struct BSSpinLock { std::uint32_t owningThread; std::uint32_t lockCount; };
class TESObjectCELL : public TESForm, public TESFullName { public: BSSpinLock grassCreateLock; BSSpinLock grassTaskLock; std::uint16_t cellFlags; std::uint16_t cellGameFlags; std::uint8_t cellState; };
class BSPathingCell { public: virtual ~BSPathingCell(); std::uint32_t _refCount; std::uint32_t unk0C; };
class PathingCell : public BSPathingCell { public: bool IsAttached(); TESObjectCELL* GetCell(); std::uint32_t unk10; std::uint32_t cellID; };
