// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x3eb0c0 ArrayLeaf3eb0c0::~ArrayLeaf3eb0c0
// Adapted bodies: none
// CI hash: 0x3eb0c0 ??1ArrayLeaf3eb0c0@@QEAA@XZ
#include "ArrayLeaf3eb0c0.h"

ArrayLeaf3eb0c0::~ArrayLeaf3eb0c0()
{
    if (data) {
        FreeArrayLeaf3eb0c0(this);
        size = 0;
    }
}
