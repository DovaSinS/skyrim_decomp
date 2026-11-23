// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5bc750 BGSLoadFormBuffer::Function5bc750
// Adapted bodies: none
#include "BGSLoadFormBuffer_5bc750.h"

void BGSLoadFormBuffer::Function5bc750(ListNode* head)
{
    for (ListNode* node = head; node; node = node->next) {
        if (node->item) {
            node->item->Visit(this);
        }
    }
}
