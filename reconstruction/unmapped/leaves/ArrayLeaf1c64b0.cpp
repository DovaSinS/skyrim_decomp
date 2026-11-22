// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1c64b0 ArrayLeaf1c64b0::~ArrayLeaf1c64b0
// Adapted bodies: none
// CI hash: 0x1c64b0 ??1ArrayLeaf1c64b0@@QEAA@XZ
#include "ArrayLeaf1c64b0.h"

ArrayLeaf1c64b0::~ArrayLeaf1c64b0()
{
    if (data) {
        FreeArrayLeaf1c64b0(this);
        size = 0;
    }
}
