// Source exposure: mixed (names and declarations from community headers; base classes, sizes and the compared functions from the pinned image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCONT: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject, TESBoundAnimObject: STANDIN EXE_RTTI
// TESObjectCONT::InitializeData, TESObjectCONT::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20, unkB9, unknownBA, unkC0, unkC8: GUESS(low)
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESObject : public TESForm
{
public:
};

class TESBoundObject : public TESObject
{
public:
};

class TESBoundAnimObject : public TESBoundObject
{
public:
    // TESBoundAnimObject::~TESBoundAnimObject: GUESS(low); out-of-line destructor so the derived destructor calls it instead of inlining the form destructor.
    ~TESBoundAnimObject() override;
};

// TESObjectREFR, TESObjectREFR::OpenContainer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the called method is declared
class TESObjectREFR
{
public:
    void OpenContainer(std::int32_t a_openType) const;
};

// g_containerOpener: GUESS(low); the reference pointer the activator is compared against
extern TESObjectREFR* g_containerOpener;

// ContPrimary: GUESS(low); 0x10 bytes after TESBoundAnimObject to place the secondary bases at the listing offsets.
class ContPrimary : public TESBoundAnimObject
{
public:
    std::uint8_t pad20[0x10];  // 20
};
static_assert(sizeof(ContPrimary) == 0x30, "ContPrimary size");

// Secondary polymorphic bases: GUESS(low); stand-ins sized to place their vftables at the listing offsets.
class ContSub30 {
public:
    virtual ~ContSub30();
    std::uint8_t pad08[0x10];  // 08
};
static_assert(sizeof(ContSub30) == 0x18, "ContSub30 size");

// ContStringMember: GUESS(low); 8-byte member with an out-of-line destructor at offset 0x50.
class ContStringMember
{
public:
    ~ContStringMember();
    std::uint64_t data;
};
static_assert(sizeof(ContStringMember) == 0x8, "ContStringMember size");

// ContBase48: GUESS(low); polymorphic base whose empty destructor is inlined by the compared destructor.
class ContBase48 {
public:
    virtual ~ContBase48() {}
};
static_assert(sizeof(ContBase48) == 0x8, "ContBase48 size");

class ContSub48 : public ContBase48 {
public:
    virtual ~ContSub48() {}
    ContStringMember field;  // 08
};
static_assert(sizeof(ContSub48) == 0x10, "ContSub48 size");

class ContSub58 {
public:
    virtual ~ContSub58();
    std::uint8_t pad08[0x30];  // 08
};
static_assert(sizeof(ContSub58) == 0x38, "ContSub58 size");

class ContSub90 {
public:
    virtual ~ContSub90();
    std::uint8_t pad08[0x8];  // 08
};
static_assert(sizeof(ContSub90) == 0x10, "ContSub90 size");

class ContSubA0 {
public:
    virtual ~ContSubA0();
    std::uint8_t pad08[0x8];  // 08
};
static_assert(sizeof(ContSubA0) == 0x10, "ContSubA0 size");

class ContSubB0 {
public:
    virtual ~ContSubB0() {}
};
static_assert(sizeof(ContSubB0) == 0x8, "ContSubB0 size");

class TESObjectCONT : public ContPrimary, public ContSub30, public ContSub48,
                      public ContSub58, public ContSub90, public ContSubA0, public ContSubB0
{
public:
    // TESObjectCONT::TESObjectCONT: GUESS(low); defined to emit the vftables and the deleting destructor.
    TESObjectCONT();
    // TESObjectCONT::~TESObjectCONT: CRASHLOGGER_PDB(59818@2026.10.24); slot 0
    ~TESObjectCONT() override;
    virtual void InitializeData();  // compared: 0x281530
    void InitItemImpl() override;  // compared: 0x281a30
    // OpenForActivator: GUESS(low); opens the container reference when the activator is the expected reference
    void OpenForActivator(TESObjectREFR* a_container, TESObjectREFR* a_activator);

    // Members written by the compared body, split out of the padding; the total size is not known from the listing.
    std::uint8_t padB8;            // B8
    std::uint8_t unkB9;            // B9
    std::uint8_t unknownBA[0x6];   // BA
    std::uint64_t unkC0;           // C0
    std::uint64_t unkC8;           // C8
};
