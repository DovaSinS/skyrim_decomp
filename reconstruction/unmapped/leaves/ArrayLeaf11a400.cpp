// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x11a400 ArrayLeaf11a400::~ArrayLeaf11a400
// Adapted bodies: none
// CI hash: 0x11a400 ??1ArrayLeaf11a400@@QEAA@XZ
#include "ArrayLeaf11a400.h"

ArrayLeaf11a400::~ArrayLeaf11a400()
{
    if (data) {
        FreeArrayLeaf11a400(this);
        size = 0;
    }
}
