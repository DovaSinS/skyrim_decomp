// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); signatures and type names are hypotheses.
// IngredientItem::CopyMagicItemData: SIBLING(fo4-private@1b765c70, author-permission); adapted data copying.
// IngredientItem::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted reset.
// IngredientItem::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted loading.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:341
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:258
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:250
// IngredientItem and bases: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// RVA 0x14f870, 39 bytes; RVA 0x14f450, 46 bytes; RVA 0x14f400, 63 bytes.
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
#include "IngredientItem.h"
void IngredientItem::CopyMagicItemData(MagicItem* other) {
    if (other && other->formType == formType) {
        auto* ingredient = static_cast<IngredientItem*>(other);
        data.costOverride = ingredient->data.costOverride;
        data.flags = ingredient->data.flags;
    }
}
void IngredientItem::Revert(BGSLoadFormBuffer* buffer) {
    TESForm::Revert(buffer);
    if (static_cast<std::int32_t>(buffer->oldChangeFlags) < 0) {
        gamedata.knownEffectFlags = 0;
        gamedata.playerUses = 0;
    }
}
void IngredientItem::LoadGame(BGSLoadFormBuffer* buffer) {
    TESForm::LoadGame(buffer);
    if (static_cast<std::int32_t>(buffer->changeFlags) < 0)
        buffer->LoadDataEndian(&gamedata, 4, 1);
}
