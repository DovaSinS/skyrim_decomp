// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

// Only the callback address is stored here. Its call signature is unknown.
using SboPayloadBinders2CleanupFunction = void();

struct SboPayloadBinders2SboBinding
{
    void* instance;
    SboPayloadBinders2CleanupFunction* cleanup;
};

struct SboPayloadBinders2PayloadBox
{
    void* table;
    void* payload;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" unsigned int gLogChannel_20d5024;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12586a0(int level, const char* fmt, ...);
extern "C" void LogSink_12586e0(int level, const char* fmt, ...);
extern "C" unsigned char Table_1ae0d90[];
extern "C" unsigned char Table_1ae0db8[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12ceb90;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12cd3d0;
extern "C" const char Text_1acd8d0[];
extern "C" unsigned char Table_1ae19a8[];
extern "C" unsigned char Table_1ae19d0[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d3a70;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d0640;
extern "C" unsigned char Table_1ae1958[];
extern "C" unsigned char Table_1ae1980[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d3a80;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d0680;
extern "C" unsigned char Table_1ae18b8[];
extern "C" unsigned char Table_1ae18e0[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d3a90;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d06c0;
extern "C" unsigned char Table_1ae1908[];
extern "C" unsigned char Table_1ae1930[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d3ab0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d0740;
extern "C" unsigned char Table_1ae4048[];
extern "C" unsigned char Table_1ae4070[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12ec6f0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12eb380;
extern "C" unsigned char Table_1ae3ff8[];
extern "C" unsigned char Table_1ae4020[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12ec700;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12eb3c0;
extern "C" unsigned char Table_1ae4a80[];
extern "C" unsigned char Table_1ae4aa0[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12f07e0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12ede10;
extern "C" unsigned char Table_1ae4ac0[];
extern "C" unsigned char Table_1ae4ae0[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12f07f0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12ede50;
extern "C" unsigned char Table_1ae6cc8[];
extern "C" unsigned char Table_1ae6ce8[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12fd0b0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12f7da0;
extern "C" unsigned char Table_1ae6d08[];
extern "C" unsigned char Table_1ae6d28[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12fd0d0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12f7e20;
extern "C" unsigned char Table_1ae6d48[];
extern "C" unsigned char Table_1ae6d68[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12fd0e0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12f7e60;
extern "C" unsigned char Table_1ae9398[];
extern "C" unsigned char Table_1ae93b8[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_130f110;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_130b7e0;
extern "C" unsigned char Table_1ae9358[];
extern "C" unsigned char Table_1ae9378[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_130f120;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_130b820;
extern "C" unsigned char Table_1aefd08[];
extern "C" unsigned char Table_1aefd30[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_133b750;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1331e70;
extern "C" unsigned char Table_1aefc68[];
extern "C" unsigned char Table_1aefc90[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_133b770;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1331ef0;
extern "C" unsigned char Table_1af01b8[];
extern "C" unsigned char Table_1af01e0[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_133b810;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1332170;
extern "C" unsigned char Table_1aefd58[];
extern "C" unsigned char Table_1aefd80[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_133b850;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1332270;
extern "C" unsigned char Table_1afe2b0[];
extern "C" unsigned char Table_1afe2d0[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1388500;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1386080;
extern "C" unsigned char Table_1b00bd8[];
extern "C" unsigned char Table_1b00bf8[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1398740;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_138bc50;

struct SboPayloadBinders2
{
    static SboPayloadBinders2SboBinding Wrap12cd410(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12d0780(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12d0880(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12d0980(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12d0b40(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12eb400(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12eb500(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12edf10(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12ee010(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12f82d0(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12f8490(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap12f8590(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap130bbb0(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap130bcb0(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap1332470(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap1332690(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap1333070(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap13333b0(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap1386340(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders2SboBinding Wrap138c560(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap);
};
