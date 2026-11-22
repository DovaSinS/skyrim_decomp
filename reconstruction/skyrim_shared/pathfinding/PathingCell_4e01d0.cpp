// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x4e01d0 PathingCell::Func4
// Adapted bodies: none
#include "PathingCell_4e01d0.h"

// 0x4e01d0 PathingCell::Func4
void PathingCell::Func4(ValueVisitor* a_visitor)
{
    std::uint32_t value = unk10;
    if (value) {
        a_visitor->Visit(&value);
        unk10 = value;
    } else {
        value = unk14;
        a_visitor->Visit(&value);
        unk14 = value;
    }
}
