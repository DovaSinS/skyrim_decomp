// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x29c850 ArrayLeaf29c850::~ArrayLeaf29c850
// Adapted bodies: none
// CI hash: 0x29c850 ??1ArrayLeaf29c850@@QEAA@XZ
#include "ArrayLeaf29c850.h"

ArrayLeaf29c850::~ArrayLeaf29c850()
{
    if (data) {
        FreeArrayLeaf29c850(this);
        size = 0;
    }
}
