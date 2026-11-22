// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1ae980 ArrayLeaf1ae980::~ArrayLeaf1ae980
// Adapted bodies: none
// CI hash: 0x1ae980 ??1ArrayLeaf1ae980@@QEAA@XZ
#include "ArrayLeaf1ae980.h"

ArrayLeaf1ae980::~ArrayLeaf1ae980()
{
    if (data) {
        FreeArrayLeaf1ae980(this);
        size = 0;
    }
}
