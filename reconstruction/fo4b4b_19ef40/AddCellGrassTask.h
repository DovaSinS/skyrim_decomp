// Build: sse-steam-1-7-104; RVA 0x19ef40; 20 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// AddCellGrassTask::Run: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:76
// AddCellGrassTask, QueuedFile, IOTask, BSTask: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0); declarations adapted from include/RE/A/AddCellGrassTask.h, include/RE/Q/QueuedFile.h, include/RE/I/IOTask.h and include/RE/B/BSTask.h.
// The declarations derived from powerof3/CommonLibSSE are GPL-3.0.
// BGSGrassManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/B/BGSGrassManager.h.
// names: GUESS(low); names and original signatures are tentative.
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
class TESObjectCELL;
class BSTask { public: virtual ~BSTask(); int refCount; unsigned unknown0c; unsigned long long unknown10; };
class IOTask : public BSTask {};
class QueuedFile : public IOTask { public: unsigned long long unknown18; QueuedFile* parent; unsigned long long children, unknown30; };
class BGSGrassManager { public: void AddCellGrass(TESObjectCELL*, bool*); };
extern BGSGrassManager* grassManager;
class AddCellGrassTask : public QueuedFile { public: TESObjectCELL* cell; int x,y; bool cancel; void Run(); };
