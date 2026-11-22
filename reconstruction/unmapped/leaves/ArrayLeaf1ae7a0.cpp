// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1ae7a0 ArrayLeaf1ae7a0::~ArrayLeaf1ae7a0
// Adapted bodies: none
// CI hash: 0x1ae7a0 ??1ArrayLeaf1ae7a0@@QEAA@XZ
#include "ArrayLeaf1ae7a0.h"

ArrayLeaf1ae7a0::~ArrayLeaf1ae7a0()
{
    if (data) {
        FreeArrayLeaf1ae7a0(this);
        size = 0;
    }
}
