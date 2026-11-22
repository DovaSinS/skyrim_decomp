// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MapMarkerData, MapMarkerData::locationName, MapMarkerData::flags, MapMarkerData::type: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MapMarkerData::Copy: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// BaseFormComponent, BaseFormComponent::CopyComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slots up to CopyComponent
// TESFullName: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name text omitted
// TESFullName::unk08: GUESS(low); the name string
#pragma once

#include <cstdint>
#include <cstddef>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent();                               // 00
    virtual void InitializeDataComponent();                     // 01
    virtual void ClearDataComponent();                          // 02
    virtual void CopyComponent(BaseFormComponent* rhs);         // 03
};

class TESFullName : public BaseFormComponent
{
public:
    void* unk08;  // 08
};

class MapMarkerData
{
public:
    void Copy(MapMarkerData* other);  // compared: 0x190a00

    TESFullName locationName;  // 00
    std::uint8_t flags;        // 10
    std::uint8_t pad11;        // 11
    std::uint16_t type;        // 12
};
