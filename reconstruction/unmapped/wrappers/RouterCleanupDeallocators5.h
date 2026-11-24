// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterCleanupDeallocators5, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct RouterCleanupDeallocators5BlockHeap
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void BlockFree(void* block, int size);
};

struct RouterCleanupDeallocators5MemoryRouter
{
    unsigned char unk00[0x58];
    RouterCleanupDeallocators5BlockHeap* heap;
};

struct RouterCleanupDeallocators5TaggedObject
{
    void* table;
    unsigned short memSizeAndFlags;
};

extern "C" unsigned int RouterTlsSlot325a844;
extern "C" void* (*const TlsGetValueSlot17c8418)(unsigned int slot);
extern "C" void GlobalDeallocTarget1177a80(void* object, unsigned long long size);
extern "C" void CleanupTargetb36b80(void* object);
extern "C" void CleanupTargetb374f0(void* object);
extern "C" void CleanupTargetb3c0d0(void* object);
extern "C" void CleanupTargetb3d9a0(void* object);
extern "C" void CleanupTargetb3da40(void* object);
extern "C" void CleanupTargetb3fa90(void* object);
extern "C" void CleanupTargetb40100(void* object);
extern "C" void CleanupTargetb40e10(void* object);
extern "C" void CleanupTargetb41370(void* object);
extern "C" void CleanupTargetb45150(void* object);
extern "C" void CleanupTargetb46df0(void* object);
extern "C" void CleanupTargetb4a430(void* object);
extern "C" void CleanupTargetb4a990(void* object);
extern "C" void CleanupTargetb4c240(void* object);
extern "C" void CleanupTargetb4cbb0(void* object);
extern "C" void CleanupTargetb4e440(void* object);
extern "C" void CleanupTargetb4f880(void* object);
extern "C" void CleanupTargetb50130(void* object);
extern "C" void CleanupTargetb517f0(void* object);
extern "C" void CleanupTargetb5b5e0(void* object);
extern "C" void CleanupTargetb622c0(void* object);
extern "C" void CleanupTargetb63740(void* object);
extern "C" void CleanupTargetb64520(void* object);
extern "C" void CleanupTargetb65010(void* object);
extern "C" void CleanupTargetb660e0(void* object);
extern "C" void CleanupTargetb66fd0(void* object);
extern "C" void CleanupTargetb6ccd0(void* object);
extern "C" void CleanupTargetb6f4f0(void* object);
extern "C" void CleanupTargetb70a50(void* object);
extern "C" void CleanupTargetb71850(void* object);
extern "C" void CleanupTargetb73710(void* object);
extern "C" void CleanupTargetb76080(void* object);
extern "C" void CleanupTargetb78480(void* object);
extern "C" void CleanupTargetb7a420(void* object);

struct RouterCleanupDeallocators5
{
    static void* Deleteb36e30(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb37500(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb3c530(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb3dcb0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb3dd30(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb3df10(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb3e040(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb3e250(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb3e2d0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb3f4a0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb3f720(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb40b30(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb410b0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb4c440(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb4c4c0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb4c540(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb4c5c0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb4c7f0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb4de10(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb4f180(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb4f200(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb4ffa0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb50350(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb51a10(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb51bb0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb51cd0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb51d50(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb52100(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb52180(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb52200(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb52310(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb52390(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb52650(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb527f0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb52870(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb528f0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb5ccd0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
    static void* Deleteb767a0(RouterCleanupDeallocators5TaggedObject* object, unsigned int flags);
};
