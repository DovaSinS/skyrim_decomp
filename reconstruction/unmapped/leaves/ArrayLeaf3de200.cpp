// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x3de200 ArrayLeaf3de200::~ArrayLeaf3de200
// Adapted bodies: none
// CI hash: 0x3de200 ??1ArrayLeaf3de200@@QEAA@XZ
#include "ArrayLeaf3de200.h"

ArrayLeaf3de200::~ArrayLeaf3de200()
{
    if (data) {
        FreeArrayLeaf3de200(this);
        size = 0;
    }
}
