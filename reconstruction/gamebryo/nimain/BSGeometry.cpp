// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: community declarations; bodies written from the pinned listing
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xefc6e0 BSGeometry::UpdateDownwardPass
// 0xefc720 BSGeometry::UpdateSelectedDownwardPass
// 0xefc680 BSGeometry::SetSelectiveUpdateFlags
// 0xefc380 BSGeometry::RegisterStreamables
#include "BSGeometry.h"

// Body done: RVA 0xefc6e0, 49 bytes, BSGeometry::UpdateDownwardPass.
void BSGeometry::UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
    BaseUpdateDownwardPass(a_data, a_arg2);
    if ((a_data.flags & NiUpdateData::kDirty) != 0) {
        UpdateBoundFromFlags(a_data);
    }
}

// The CommonLibSSE-NG virtual slots identify these update methods. The conflicting
// CrashLogger movement-factory names do not describe their calls through NiAVObject.
// Body done: RVA 0xefc720, 56 bytes, BSGeometry::UpdateSelectedDownwardPass.
void BSGeometry::UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
    BaseUpdateSelectedDownwardPass(a_data, a_arg2);
    if (TestBit(flags, selectiveUpdateControllerBit)) {
        UpdateBoundFromFlags(a_data);
    }
}

// Body done: RVA 0xefc680, 75 bytes, BSGeometry::SetSelectiveUpdateFlags.
void BSGeometry::SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid)
{
    BaseSetSelectiveUpdateFlags(a_selectiveUpdate, a_selectiveUpdateTransforms, a_rigid);
    if (skinInstance.pointer) {
        flags |= kSelectiveUpdateTransforms;
        a_selectiveUpdate = true;
        flags |= kSelectiveUpdate;
        a_rigid = false;
    }
}

// Body done: RVA 0xefc380, 121 bytes, BSGeometry::RegisterStreamables.
bool BSGeometry::RegisterStreamables(NiStream& a_stream)
{
    if (!BaseRegisterStreamables(a_stream)) {
        return false;
    }
    if (skinInstance.pointer) {
        skinInstance.pointer->RegisterStreamables(a_stream);
    }
    if (shaderProperty.pointer) {
        shaderProperty.pointer->RegisterStreamables(a_stream);
    }
    if (alphaProperty.pointer) {
        alphaProperty.pointer->RegisterStreamables(a_stream);
    }
    return true;
}

