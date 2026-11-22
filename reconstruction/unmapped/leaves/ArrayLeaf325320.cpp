// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x325320 ArrayLeaf325320::~ArrayLeaf325320
// Adapted bodies: none
// CI hash: 0x325320 ??1ArrayLeaf325320@@QEAA@XZ
#include "ArrayLeaf325320.h"

ArrayLeaf325320::~ArrayLeaf325320()
{
    if (data) {
        FreeArrayLeaf325320(this);
        size = 0;
    }
}
