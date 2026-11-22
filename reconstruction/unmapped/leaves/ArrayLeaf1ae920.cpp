// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1ae920 ArrayLeaf1ae920::~ArrayLeaf1ae920
// Adapted bodies: none
// CI hash: 0x1ae920 ??1ArrayLeaf1ae920@@QEAA@XZ
#include "ArrayLeaf1ae920.h"

ArrayLeaf1ae920::~ArrayLeaf1ae920()
{
    if (data) {
        FreeArrayLeaf1ae920(this);
        size = 0;
    }
}
