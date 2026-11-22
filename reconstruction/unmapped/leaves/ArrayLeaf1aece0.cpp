// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aece0 ArrayLeaf1aece0::~ArrayLeaf1aece0
// Adapted bodies: none
// CI hash: 0x1aece0 ??1ArrayLeaf1aece0@@QEAA@XZ
#include "ArrayLeaf1aece0.h"

ArrayLeaf1aece0::~ArrayLeaf1aece0()
{
    if (data) {
        FreeArrayLeaf1aece0(this);
        size = 0;
    }
}
