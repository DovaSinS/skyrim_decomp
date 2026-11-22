// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSProjectile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the body reads
// GetCollisionLayer: SYMBOLS(fo4-pdb)
// BGSCollisionLayer, BGSCollisionLayer::collisionIdx: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSProjectileData, BGSProjectileData::collisionLayer, BGSProjectile::data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// flagsAndType: GUESS(low); the flags and type halfwords of BGSProjectileData read as one 32-bit word
#pragma once

#include <cstdint>
#include <cstddef>

class BGSCollisionLayer
{
public:
    unsigned char unk00[0x30];
    std::uint32_t collisionIdx;  // 30
};

struct BGSProjectileData
{
    std::uint32_t flagsAndType;        // 00
    unsigned char unk04[0x7C];
    BGSCollisionLayer* collisionLayer; // 80
};

class BGSProjectile
{
public:
    std::uint32_t GetCollisionLayer() const;  // compared: 0x2660b0

    unsigned char unk00[0x80];
    BGSProjectileData data;                   // 80
};
