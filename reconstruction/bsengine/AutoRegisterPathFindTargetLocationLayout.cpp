// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (community and permitted sibling declarations; target RTTI and construction analysis).
// Drafted by GPT-6.1 Sol; p175 represented registration hierarchy.
// Labels: v2
// Code origin: original declarations and defaulted owner construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IBSTCreator.h and include/RE/A/AutoRegisterFactory.h; MIT.
// Declaration source: fo4-private@1b765c70 src/BSSystem/BSTCreateFactory.h and src/BSPathfinding/BSTPathingFactory.h; game-code only, author-permission.
// IBSTCreator, AutoRegisterFactory: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AutoRegisterCreator, AutoRegisterSmartPtrDerivedPathingType: SIBLING(fo4-private@1b765c70, author-permission)
// IPathBuilderFactoryBase, CombatPathingRequestBuilder, AutoRegisterCombatPathingRequestGeneric: EXE_RTTI
// PathRegistrationCreatorLayout, PathBuilderRegistrationLayout, PathRegistrationBasesLayout: GUESS(medium) STANDIN
// Product, Identity, Create, Destroy: GUESS(low) STANDIN
// The represented contracts omit unassessed methods and flatten fieldless creator layers.
// Skyrim RTTI independently binds three nonvirtual direct bases and both secondary destructor slots.
// This representation contains no data fields or padding; no size is synthesized from deletion arguments.
// Only compiler-emitted secondary adjustors are compared; constructor, destructor and registration operations remain outside that claim.
// Layout agreement does not prove complete original definitions, behavior or an original-source identity.
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
// AutoRegisterPathFindTargetLocationLayout: GUESS(medium) STANDIN
// RVA 0x8582c4; 9 bytes
// RVA 0x8582d0; 9 bytes
#include "AutoRegisterPathFindTargetLocationLayout.h"
namespace ResearchLayouts {
AutoRegisterPathFindTargetLocationLayout::AutoRegisterPathFindTargetLocationLayout() = default;
}
