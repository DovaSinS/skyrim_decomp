// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterCleanupDeallocators1, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterCleanupDeallocators1BlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterCleanupDeallocators1MemoryRouter
{
    unsigned char unk00[0x58];
    RouterCleanupDeallocators1BlockHeap* heap;
};

struct RouterCleanupDeallocators1TaggedObject
{
    void* table;
    unsigned short memSizeAndFlags;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetaac380(void* object);
extern "C" void CleanupTargetaac9a0(void* object);
extern "C" void CleanupTargetaace50(void* object);
extern "C" void CleanupTargetaad1c0(void* object);
extern "C" void CleanupTargetaaeed0(void* object);
extern "C" void CleanupTargetaaf4d0(void* object);
extern "C" void CleanupTargetaaf590(void* object);
extern "C" void CleanupTargetab0950(void* object);
extern "C" void CleanupTargetab2e40(void* object);
extern "C" void CleanupTargetab4b40(void* object);
extern "C" void CleanupTargetab4f80(void* object);
extern "C" void CleanupTargetab52e0(void* object);
extern "C" void CleanupTargetab65b0(void* object);
extern "C" void CleanupTargetab78d0(void* object);
extern "C" void CleanupTargetab82b0(void* object);
extern "C" void CleanupTargetab9340(void* object);
extern "C" void CleanupTargetabaad0(void* object);
extern "C" void CleanupTargetac3890(void* object);
extern "C" void CleanupTargetac40f0(void* object);
extern "C" void CleanupTargetac6a00(void* object);
extern "C" void CleanupTargetacb5a0(void* object);
extern "C" void CleanupTargetacc7e0(void* object);
extern "C" void CleanupTargetad1a70(void* object);
extern "C" void CleanupTargetad1ae0(void* object);
extern "C" void CleanupTargetad2240(void* object);
extern "C" void CleanupTargetad7500(void* object);
extern "C" void CleanupTargetad9310(void* object);
extern "C" void CleanupTargetae0180(void* object);
extern "C" void CleanupTargetae0230(void* object);
extern "C" void CleanupTargetae02c0(void* object);
extern "C" void CleanupTargetae0370(void* object);
extern "C" void CleanupTargetae70b0(void* object);
extern "C" void CleanupTargetaf37c0(void* object);
extern "C" void CleanupTargetaf3a50(void* object);
extern "C" void CleanupTargetaf9a30(void* object);
extern "C" void CleanupTargetb005c0(void* object);
extern "C" void CleanupTargetb01690(void* object);

struct RouterCleanupDeallocators1
{
    static void* Deleteaa70c0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteaaa400(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteaac840(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteaacd60(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteaacfd0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteaad2f0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteaaf620(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteaaf6a0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteaaf720(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteab0a50(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteab3220(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteab4ff0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteab5070(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteab69c0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteab7ee0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteab8330(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteab9a20(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteabb2f0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteac42a0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteac4560(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteacacd0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deletead1bf0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deletead1c70(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deletead1cf0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deletead1f40(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deletead7080(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deletead8180(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deletead8200(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteadb990(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteae1750(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteae17d0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteae1850(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteae18d0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteae1ab0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteae1b30(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteae1bb0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteae1c30(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
    static void* Deleteae1cb0(RouterCleanupDeallocators1TaggedObject* object, unsigned int flags);
};
