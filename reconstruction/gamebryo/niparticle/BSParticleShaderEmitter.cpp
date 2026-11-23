// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in; no external declaration or body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2a0ba0 BSParticleShaderEmitter::~BSParticleShaderEmitter
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
#include "BSParticleShaderEmitter.h"

// The complete destructor stays undefined so that the deleting destructor calls it out of line,
// as the target does. Defining the constructor makes the compiler emit the vftable.
BSParticleShaderEmitter::BSParticleShaderEmitter()
{
}
