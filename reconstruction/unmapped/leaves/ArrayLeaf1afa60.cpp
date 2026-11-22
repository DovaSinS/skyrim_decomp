// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1afa60 ArrayLeaf1afa60::~ArrayLeaf1afa60
// Adapted bodies: none
// CI hash: 0x1afa60 ??1ArrayLeaf1afa60@@QEAA@XZ
#include "ArrayLeaf1afa60.h"

ArrayLeaf1afa60::~ArrayLeaf1afa60()
{
    if (data) {
        FreeArrayLeaf1afa60(this);
        size = 0;
    }
}
