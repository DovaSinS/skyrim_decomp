// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x2805f0 ArrayLeaf2805f0::~ArrayLeaf2805f0
// Adapted bodies: none
// CI hash: 0x2805f0 ??1ArrayLeaf2805f0@@QEAA@XZ
#include "ArrayLeaf2805f0.h"

ArrayLeaf2805f0::~ArrayLeaf2805f0()
{
    if (data) {
        FreeArrayLeaf2805f0(this);
        size = 0;
    }
}
