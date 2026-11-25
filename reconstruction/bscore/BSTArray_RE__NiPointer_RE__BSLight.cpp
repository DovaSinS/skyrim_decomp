// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the sibling BSTArray::Add body; the allocator functor and counted element follow it
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSCore/BSTArray.h:332
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// 0x15123a0 BSTArray<NiPointer<BSLight>, BSTArrayHeapAllocator>::Add
// 0x1512470 BSTArray<NiPointer<BSShadowLight>, BSTArrayHeapAllocator>::Add
// 0x1512410 BSTArray<BSShadowLight*, BSTArrayHeapAllocator>::Add
// 0x15124e0 BSTArray<BSLight*, BSTArrayHeapAllocator>::Add
// Adapted bodies: BSTArray::Add from fo4-private@1b765c70 src/BSCore/BSTArray.h:332
#include "BSTArray_RE__NiPointer_RE__BSLight.h"

template std::uint32_t BSTArray<NiPointer<BSLight>, BSTArrayHeapAllocator>::Add<BSLight*>(BSLight*);
template std::uint32_t BSTArray<NiPointer<BSShadowLight>, BSTArrayHeapAllocator>::Add<BSShadowLight*>(BSShadowLight*);
template std::uint32_t BSTArray<BSShadowLight*, BSTArrayHeapAllocator>::Add<BSShadowLight*>(BSShadowLight*);
template std::uint32_t BSTArray<BSLight*, BSTArrayHeapAllocator>::Add<BSLight*>(BSLight*);
