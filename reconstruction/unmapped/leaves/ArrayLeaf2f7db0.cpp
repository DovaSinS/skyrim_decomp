// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x2f7db0 ArrayLeaf2f7db0::~ArrayLeaf2f7db0
// Adapted bodies: none
// CI hash: 0x2f7db0 ??1ArrayLeaf2f7db0@@QEAA@XZ
#include "ArrayLeaf2f7db0.h"

ArrayLeaf2f7db0::~ArrayLeaf2f7db0()
{
    if (data) {
        FreeArrayLeaf2f7db0(this);
        size = 0;
    }
}
