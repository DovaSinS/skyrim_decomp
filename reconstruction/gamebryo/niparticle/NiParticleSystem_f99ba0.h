// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// NiParticleSystem, NiParticleSystem::SetSelectiveUpdateFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the class view stands in for the NiAVObject base
// flags, kSelectiveUpdate, kSelectiveUpdateTransforms, kSelectiveUpdateController, kSelectiveUpdateRigid: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiAVObject::flags at 0xF4 in this build
// SetSelectiveUpdate, SetSelectiveUpdateTransforms, SetSelectiveUpdateController, SetSelectiveUpdateRigid: GUESS(low); flag setters the body is written with
// unk00: GUESS(low); unrecovered storage
#pragma once

#include <cstdint>

class NiParticleSystem
{
public:
    void SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);  // compared: 0xf99ba0

    std::uint8_t unk00[0xF4];
    std::uint32_t flags;

private:
    static const std::uint32_t kSelectiveUpdate = 1 << 1;
    static const std::uint32_t kSelectiveUpdateTransforms = 1 << 2;
    static const std::uint32_t kSelectiveUpdateController = 1 << 3;
    static const std::uint32_t kSelectiveUpdateRigid = 1 << 4;

    void SetFlag(std::uint32_t a_mask, bool a_set)
    {
        if (a_set) {
            flags |= a_mask;
        } else {
            flags &= ~a_mask;
        }
    }

public:
    void SetSelectiveUpdate(bool a_set) { SetFlag(kSelectiveUpdate, a_set); }
    void SetSelectiveUpdateTransforms(bool a_set) { SetFlag(kSelectiveUpdateTransforms, a_set); }
    void SetSelectiveUpdateController(bool a_set) { SetFlag(kSelectiveUpdateController, a_set); }
    void SetSelectiveUpdateRigid(bool a_set) { SetFlag(kSelectiveUpdateRigid, a_set); }
};
