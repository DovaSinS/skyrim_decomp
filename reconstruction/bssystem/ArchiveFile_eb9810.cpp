// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xeb9810 ArchiveFile::InstallStreamFunctions
// Adapted bodies: none
#include "ArchiveFile_eb9810.h"

void ArchiveFile::InstallStreamFunctions(bool a_alternate)
{
    if (a_alternate) {
        InstallAlternate(a_alternate);
        return;
    }
    _readFn = &ReadBytes;
    _writeFn = &WriteBytes;
}
