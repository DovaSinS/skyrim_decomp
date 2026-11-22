// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1fd470 ArrayLeaf1fd470::~ArrayLeaf1fd470
// Adapted bodies: none
// CI hash: 0x1fd470 ??1ArrayLeaf1fd470@@QEAA@XZ
#include "ArrayLeaf1fd470.h"

ArrayLeaf1fd470::~ArrayLeaf1fd470()
{
    if (data) {
        FreeArrayLeaf1fd470(this);
        size = 0;
    }
}
