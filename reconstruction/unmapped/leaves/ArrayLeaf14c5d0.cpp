// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x14c5d0 ArrayLeaf14c5d0::~ArrayLeaf14c5d0
// Adapted bodies: none
// CI hash: 0x14c5d0 ??1ArrayLeaf14c5d0@@QEAA@XZ
#include "ArrayLeaf14c5d0.h"

ArrayLeaf14c5d0::~ArrayLeaf14c5d0()
{
    if (data) {
        FreeArrayLeaf14c5d0(this);
        size = 0;
    }
}
