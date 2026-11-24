// Source exposure: mixed
// Code origin: HorseCameraState::End was adapted from the anonymous fo4-private sibling as labelled (author permission); ~HorseCameraState and SetCameraHandle were written from the pinned image listing by Taylor Turner with Claude Sonnet 5.5 (first drafts by DeepSeek V4.1 Flash) with no adapted body; declarations from the pinned community headers. Stamped as a twin of matched 0x8f7100 (skyrim/camera/HorseCameraState): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function10db0b0, Owner10db0b0: GUESS(low) STANDIN
// ThirdPersonState: GUESS(low) STANDIN
#pragma once
#include "HorseCameraState.h"

class Owner10db0b0 : public ThirdPersonState { public: ~Owner10db0b0(); unsigned char padTwinE8[48]; unsigned horseRefHandle; float horseCurrentDirection; bool atMaxHorseAngle; void Function10db0b0(unsigned& a_handle); void End(); void Revert(BGSLoadFormBuffer*); };
static_assert(sizeof(Owner10db0b0) == 0x128, "Owner10db0b0 size");
