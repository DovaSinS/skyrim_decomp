// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x3eb120 ArrayLeaf3eb120::~ArrayLeaf3eb120
// Adapted bodies: none
// CI hash: 0x3eb120 ??1ArrayLeaf3eb120@@QEAA@XZ
#include "ArrayLeaf3eb120.h"

ArrayLeaf3eb120::~ArrayLeaf3eb120()
{
    if (data) {
        FreeArrayLeaf3eb120(this);
        size = 0;
    }
}
