// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aefe0 ArrayLeaf1aefe0::~ArrayLeaf1aefe0
// Adapted bodies: none
// CI hash: 0x1aefe0 ??1ArrayLeaf1aefe0@@QEAA@XZ
#include "ArrayLeaf1aefe0.h"

ArrayLeaf1aefe0::~ArrayLeaf1aefe0()
{
    if (data) {
        FreeArrayLeaf1aefe0(this);
        size = 0;
    }
}
