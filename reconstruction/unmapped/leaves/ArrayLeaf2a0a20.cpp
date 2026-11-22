// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x2a0a20 ArrayLeaf2a0a20::~ArrayLeaf2a0a20
// Adapted bodies: none
// CI hash: 0x2a0a20 ??1ArrayLeaf2a0a20@@QEAA@XZ
#include "ArrayLeaf2a0a20.h"

ArrayLeaf2a0a20::~ArrayLeaf2a0a20()
{
    if (data) {
        FreeArrayLeaf2a0a20(this);
        size = 0;
    }
}
