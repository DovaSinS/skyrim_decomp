// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x39a4f0 ArrayLeaf39a4f0::~ArrayLeaf39a4f0
// Adapted bodies: none
// CI hash: 0x39a4f0 ??1ArrayLeaf39a4f0@@QEAA@XZ
#include "ArrayLeaf39a4f0.h"

ArrayLeaf39a4f0::~ArrayLeaf39a4f0()
{
    if (data) {
        FreeArrayLeaf39a4f0(this);
        size = 0;
    }
}
