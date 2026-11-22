// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aea40 ArrayLeaf1aea40::~ArrayLeaf1aea40
// Adapted bodies: none
// CI hash: 0x1aea40 ??1ArrayLeaf1aea40@@QEAA@XZ
#include "ArrayLeaf1aea40.h"

ArrayLeaf1aea40::~ArrayLeaf1aea40()
{
    if (data) {
        FreeArrayLeaf1aea40(this);
        size = 0;
    }
}
