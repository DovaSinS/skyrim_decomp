// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterCleanupDeallocators8, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterCleanupDeallocators8BlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterCleanupDeallocators8MemoryRouter
{
    unsigned char unk00[0x58];
    RouterCleanupDeallocators8BlockHeap* heap;
};

struct RouterCleanupDeallocators8TaggedObject
{
    void* table;
    unsigned short memSizeAndFlags;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetb50130(void* object);
extern "C" void CleanupTargetb5c710(void* object);
extern "C" void CleanupTargetb768a0(void* object);
extern "C" void CleanupTargetb77ce0(void* object);
extern "C" void CleanupTargetb787f0(void* object);
extern "C" void CleanupTargetb79ae0(void* object);
extern "C" void CleanupTargetb7bb50(void* object);
extern "C" void CleanupTargetb7c950(void* object);
extern "C" void CleanupTargetb7d2c0(void* object);
extern "C" void CleanupTargetb7ded0(void* object);
extern "C" void CleanupTargetb7e560(void* object);
extern "C" void CleanupTargetb8d9d0(void* object);
extern "C" void CleanupTargetb97840(void* object);
extern "C" void CleanupTargetb97b50(void* object);
extern "C" void CleanupTargetb9ba00(void* object);
extern "C" void CleanupTargetb9bab0(void* object);
extern "C" void CleanupTargetb9bbb0(void* object);
extern "C" void CleanupTargetba1a90(void* object);
extern "C" void CleanupTargetba3cb0(void* object);
extern "C" void CleanupTargetba49e0(void* object);
extern "C" void CleanupTargetba56a0(void* object);
extern "C" void CleanupTargetba5b10(void* object);
extern "C" void CleanupTargetba6510(void* object);
extern "C" void CleanupTargetba68b0(void* object);
extern "C" void CleanupTargetba69d0(void* object);
extern "C" void CleanupTargetba6b20(void* object);
extern "C" void CleanupTargetba70a0(void* object);
extern "C" void CleanupTargetba8760(void* object);
extern "C" void CleanupTargetba8c70(void* object);
extern "C" void CleanupTargetbb0810(void* object);
extern "C" void CleanupTargetbb1e40(void* object);
extern "C" void CleanupTargetc2e4f0(void* object);

struct RouterCleanupDeallocators8
{
    static void* Deleteb76dd0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb78310(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb79730(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb79d60(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb7c190(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb7cef0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb7e090(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb7e110(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb7ec80(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb81be0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb8daa0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb97ad0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb983d0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9bd00(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9be30(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9beb0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9bfc0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c040(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c0c0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c140(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c280(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c300(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c380(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c400(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c480(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c500(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c610(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c690(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteb9c710(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteba4880(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteba6ec0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteba75c0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteba8690(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteba9060(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deleteba90e0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deletebb1a00(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
    static void* Deletebb28d0(RouterCleanupDeallocators8TaggedObject* object, unsigned int flags);
};
