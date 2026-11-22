// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1ae8c0 ArrayLeaf1ae8c0::~ArrayLeaf1ae8c0
// Adapted bodies: none
// CI hash: 0x1ae8c0 ??1ArrayLeaf1ae8c0@@QEAA@XZ
#include "ArrayLeaf1ae8c0.h"

ArrayLeaf1ae8c0::~ArrayLeaf1ae8c0()
{
    if (data) {
        FreeArrayLeaf1ae8c0(this);
        size = 0;
    }
}
