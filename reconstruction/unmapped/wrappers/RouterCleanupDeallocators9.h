// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterCleanupDeallocators9, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterCleanupDeallocators9BlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterCleanupDeallocators9MemoryRouter
{
    unsigned char unk00[0x58];
    RouterCleanupDeallocators9BlockHeap* heap;
};

struct RouterCleanupDeallocators9TaggedObject
{
    void* table;
    unsigned short memSizeAndFlags;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetc28fa0(void* object);
extern "C" void CleanupTargetc47bf0(void* object);
extern "C" void CleanupTargetc47c90(void* object);
extern "C" void CleanupTargetc47d30(void* object);
extern "C" void CleanupTargetc47db0(void* object);
extern "C" void CleanupTargetc47ed0(void* object);
extern "C" void CleanupTargetc47f70(void* object);
extern "C" void CleanupTargetc48050(void* object);
extern "C" void CleanupTargetc480e0(void* object);
extern "C" void CleanupTargetc48180(void* object);
extern "C" void CleanupTargetc48250(void* object);
extern "C" void CleanupTargetc50c20(void* object);
extern "C" void CleanupTargetc52460(void* object);
extern "C" void CleanupTargetc57280(void* object);
extern "C" void CleanupTargetc58cf0(void* object);
extern "C" void CleanupTargetc59eb0(void* object);
extern "C" void CleanupTargetc5b960(void* object);
extern "C" void CleanupTargetc64040(void* object);
extern "C" void CleanupTargetc6e0e0(void* object);
extern "C" void CleanupTargetc72a30(void* object);
extern "C" void CleanupTargetc75450(void* object);
extern "C" void CleanupTargetca1b20(void* object);
extern "C" void CleanupTargetca2950(void* object);
extern "C" void CleanupTargetca2aa0(void* object);
extern "C" void CleanupTargetca2ff0(void* object);
extern "C" void CleanupTargetca35e0(void* object);
extern "C" void CleanupTargetca40e0(void* object);
extern "C" void CleanupTargetca41f0(void* object);
extern "C" void CleanupTargetca48d0(void* object);
extern "C" void CleanupTargetcb9e50(void* object);
extern "C" void CleanupTargetcba110(void* object);
extern "C" void CleanupTargetcba570(void* object);
extern "C" void CleanupTargetcbf630(void* object);
extern "C" void CleanupTargetcc01b0(void* object);
extern "C" void CleanupTargetcc0580(void* object);
extern "C" void CleanupTargetcc08a0(void* object);
extern "C" void CleanupTarget10a5840(void* object);

struct RouterCleanupDeallocators9
{
    static void* Deletec48880(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec48900(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec48a10(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec48b60(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec48be0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec48c60(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec48ce0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec48d60(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec48de0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec48e60(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec48f80(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec49000(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec49120(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec50da0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec52b50(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec56880(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec58aa0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec59ab0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec5a4e0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec5e910(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec64860(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec74620(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletec766b0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deleteca1c30(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deleteca29f0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deleteca3680(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deleteca4150(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deleteca4660(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletecba350(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletecba450(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletecba7d0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletecc0090(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletecc03f0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletecc0770(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletecc0bf0(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Deletecc1920(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
    static void* Delete10a5f30(RouterCleanupDeallocators9TaggedObject* object, unsigned int flags);
};
