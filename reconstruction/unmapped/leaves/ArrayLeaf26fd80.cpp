// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x26fd80 ArrayLeaf26fd80::~ArrayLeaf26fd80
// Adapted bodies: none
// CI hash: 0x26fd80 ??1ArrayLeaf26fd80@@QEAA@XZ
#include "ArrayLeaf26fd80.h"

ArrayLeaf26fd80::~ArrayLeaf26fd80()
{
    if (data) {
        FreeArrayLeaf26fd80(this);
        size = 0;
    }
}
