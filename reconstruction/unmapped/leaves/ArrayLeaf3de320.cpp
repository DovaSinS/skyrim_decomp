// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x3de320 ArrayLeaf3de320::~ArrayLeaf3de320
// Adapted bodies: none
// CI hash: 0x3de320 ??1ArrayLeaf3de320@@QEAA@XZ
#include "ArrayLeaf3de320.h"

ArrayLeaf3de320::~ArrayLeaf3de320()
{
    if (data) {
        FreeArrayLeaf3de320(this);
        size = 0;
    }
}
