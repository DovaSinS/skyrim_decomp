// Anonymous sibling-guided reconstruction, build sse-steam-1-7-104.
// Source exposure: mixed (Skyrim binary analysis, community declarations, fo4-private reconstruction).
// Labels: v2
// Drafted by gpt-6.1-sol (historical p127 pilot; prepared by p177), human owner awarebayes.
// Origin: adapted from the cited anonymous permitted sibling body; partial Skyrim class view.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Licence: fo4-private reused with author permission conditional on anonymity (awarebayes, 2026-11-14).
// TESImageSpaceModifiableForm: SIBLING(fo4-private@1b765c70, author-permission)
// CopyComponent: SIBLING(fo4-private@1b765c70, author-permission)
// Padding and incomplete declarations: STANDIN GUESS(low); no complete-layout or behaviour claim.
// Layout status: partial stand-ins; small-function offsets use Skyrim listings and NG SE declarations.
// Larger-function dependencies include unmeasured layout/API hypotheses; their fields are not verified.
// FO4 declarations and offsets are hypotheses only, never Skyrim evidence.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESImageSpaceModifiableForm.cpp:58
// RVA 0x1e8720, 63 bytes, TESImageSpaceModifiableForm::CopyComponent.
// Public declaration-source licence (NG b93280e):
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
#include "TESImageSpaceModifiableForm.h"

void TESImageSpaceModifiableForm::CopyComponent(BaseFormComponent *apCopyFC)
{
    TESImageSpaceModifiableForm *pCopy = dynamic_cast<TESImageSpaceModifiableForm *>(apCopyFC);
    if (pCopy)
        pFormImageSpaceModifying = pCopy->pFormImageSpaceModifying;

}
