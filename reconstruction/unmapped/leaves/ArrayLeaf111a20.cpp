// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x111a20 ArrayLeaf111a20::~ArrayLeaf111a20
// Adapted bodies: none
// CI hash: 0x111a20 ??1ArrayLeaf111a20@@QEAA@XZ
#include "ArrayLeaf111a20.h"

ArrayLeaf111a20::~ArrayLeaf111a20()
{
    if (data) {
        FreeArrayLeaf111a20(this);
        size = 0;
    }
}
