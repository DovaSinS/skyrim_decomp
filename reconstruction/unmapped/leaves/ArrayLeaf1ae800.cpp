// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1ae800 ArrayLeaf1ae800::~ArrayLeaf1ae800
// Adapted bodies: none
// CI hash: 0x1ae800 ??1ArrayLeaf1ae800@@QEAA@XZ
#include "ArrayLeaf1ae800.h"

ArrayLeaf1ae800::~ArrayLeaf1ae800()
{
    if (data) {
        FreeArrayLeaf1ae800(this);
        size = 0;
    }
}
