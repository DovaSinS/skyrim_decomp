// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x39e6f0 ArrayLeaf39e6f0::~ArrayLeaf39e6f0
// Adapted bodies: none
// CI hash: 0x39e6f0 ??1ArrayLeaf39e6f0@@QEAA@XZ
#include "ArrayLeaf39e6f0.h"

ArrayLeaf39e6f0::~ArrayLeaf39e6f0()
{
    if (data) {
        FreeArrayLeaf39e6f0(this);
        size = 0;
    }
}
