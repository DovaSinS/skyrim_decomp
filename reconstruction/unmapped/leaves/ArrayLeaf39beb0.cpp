// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x39beb0 ArrayLeaf39beb0::~ArrayLeaf39beb0
// Adapted bodies: none
// CI hash: 0x39beb0 ??1ArrayLeaf39beb0@@QEAA@XZ
#include "ArrayLeaf39beb0.h"

ArrayLeaf39beb0::~ArrayLeaf39beb0()
{
    if (data) {
        FreeArrayLeaf39beb0(this);
        size = 0;
    }
}
