// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1ae860 ArrayLeaf1ae860::~ArrayLeaf1ae860
// Adapted bodies: none
// CI hash: 0x1ae860 ??1ArrayLeaf1ae860@@QEAA@XZ
#include "ArrayLeaf1ae860.h"

ArrayLeaf1ae860::~ArrayLeaf1ae860()
{
    if (data) {
        FreeArrayLeaf1ae860(this);
        size = 0;
    }
}
