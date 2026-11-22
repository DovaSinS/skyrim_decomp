// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3efcb0 TESTopic::ResetTopics
// Adapted bodies: TESTopic::ResetTopics (similar in shape to the sibling body; written from the listing)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/TESTopic.cpp:328
// TESTopic::ResetTopics: SIBLING(fo4-private@1b765c70, author-permission); the name and the loop shape
#include "TESTopic_3efcb0.h"

void TESTopic::ResetTopics()
{
    priorityAndJournalIndex &= 0xFF000000;
    for (std::uint32_t i = 0; i < numTopicInfos; ++i) {
        topicInfos[i]->SetAltered(false);
    }
}
