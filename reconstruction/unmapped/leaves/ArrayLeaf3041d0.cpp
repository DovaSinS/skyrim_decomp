// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x3041d0 ArrayLeaf3041d0::~ArrayLeaf3041d0
// Adapted bodies: none
// CI hash: 0x3041d0 ??1ArrayLeaf3041d0@@QEAA@XZ
#include "ArrayLeaf3041d0.h"

ArrayLeaf3041d0::~ArrayLeaf3041d0()
{
    if (data) {
        FreeArrayLeaf3041d0(this);
        size = 0;
    }
}
