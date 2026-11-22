// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aeec0 ArrayLeaf1aeec0::~ArrayLeaf1aeec0
// Adapted bodies: none
// CI hash: 0x1aeec0 ??1ArrayLeaf1aeec0@@QEAA@XZ
#include "ArrayLeaf1aeec0.h"

ArrayLeaf1aeec0::~ArrayLeaf1aeec0()
{
    if (data) {
        FreeArrayLeaf1aeec0(this);
        size = 0;
    }
}
