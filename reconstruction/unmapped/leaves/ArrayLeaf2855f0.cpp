// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x2855f0 ArrayLeaf2855f0::~ArrayLeaf2855f0
// Adapted bodies: none
// CI hash: 0x2855f0 ??1ArrayLeaf2855f0@@QEAA@XZ
#include "ArrayLeaf2855f0.h"

ArrayLeaf2855f0::~ArrayLeaf2855f0()
{
    if (data) {
        FreeArrayLeaf2855f0(this);
        size = 0;
    }
}
