// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aeaa0 ArrayLeaf1aeaa0::~ArrayLeaf1aeaa0
// Adapted bodies: none
// CI hash: 0x1aeaa0 ??1ArrayLeaf1aeaa0@@QEAA@XZ
#include "ArrayLeaf1aeaa0.h"

ArrayLeaf1aeaa0::~ArrayLeaf1aeaa0()
{
    if (data) {
        FreeArrayLeaf1aeaa0(this);
        size = 0;
    }
}
