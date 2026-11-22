// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x27d340 ArrayLeaf27d340::~ArrayLeaf27d340
// Adapted bodies: none
// CI hash: 0x27d340 ??1ArrayLeaf27d340@@QEAA@XZ
#include "ArrayLeaf27d340.h"

ArrayLeaf27d340::~ArrayLeaf27d340()
{
    if (data) {
        FreeArrayLeaf27d340(this);
        size = 0;
    }
}
