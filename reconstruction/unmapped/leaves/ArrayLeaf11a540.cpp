// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x11a540 ArrayLeaf11a540::~ArrayLeaf11a540
// Adapted bodies: none
// CI hash: 0x11a540 ??1ArrayLeaf11a540@@QEAA@XZ
#include "ArrayLeaf11a540.h"

ArrayLeaf11a540::~ArrayLeaf11a540()
{
    if (data) {
        FreeArrayLeaf11a540(this);
        size = 0;
    }
}
