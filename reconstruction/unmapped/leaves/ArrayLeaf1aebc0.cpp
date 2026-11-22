// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aebc0 ArrayLeaf1aebc0::~ArrayLeaf1aebc0
// Adapted bodies: none
// CI hash: 0x1aebc0 ??1ArrayLeaf1aebc0@@QEAA@XZ
#include "ArrayLeaf1aebc0.h"

ArrayLeaf1aebc0::~ArrayLeaf1aebc0()
{
    if (data) {
        FreeArrayLeaf1aebc0(this);
        size = 0;
    }
}
