// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x20aa40 ArrayLeaf20aa40::~ArrayLeaf20aa40
// Adapted bodies: none
// CI hash: 0x20aa40 ??1ArrayLeaf20aa40@@QEAA@XZ
#include "ArrayLeaf20aa40.h"

ArrayLeaf20aa40::~ArrayLeaf20aa40()
{
    if (data) {
        FreeArrayLeaf20aa40(this);
        size = 0;
    }
}
