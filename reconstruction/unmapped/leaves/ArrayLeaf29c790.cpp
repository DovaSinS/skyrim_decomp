// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x29c790 ArrayLeaf29c790::~ArrayLeaf29c790
// Adapted bodies: none
// CI hash: 0x29c790 ??1ArrayLeaf29c790@@QEAA@XZ
#include "ArrayLeaf29c790.h"

ArrayLeaf29c790::~ArrayLeaf29c790()
{
    if (data) {
        FreeArrayLeaf29c790(this);
        size = 0;
    }
}
