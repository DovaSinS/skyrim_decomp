// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x397ee0 ArrayLeaf397ee0::~ArrayLeaf397ee0
// Adapted bodies: none
// CI hash: 0x397ee0 ??1ArrayLeaf397ee0@@QEAA@XZ
#include "ArrayLeaf397ee0.h"

ArrayLeaf397ee0::~ArrayLeaf397ee0()
{
    if (data) {
        FreeArrayLeaf397ee0(this);
        size = 0;
    }
}
