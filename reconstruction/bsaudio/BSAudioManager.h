// Source exposure: mixed (pinned image listing, community names and sibling source).
// Code origin: original declarations and the labelled sibling method.
// Sibling source: fo4-private@1b765c70 src/BSAudio/BSAudioManager.cpp:75
// BSAudioManager::QPlatformInstance: SIBLING(fo4-private@1b765c70, author-permission)
// BSAudioManager, BSAudio, platformInstance, audioManagerInstance: GUESS(low)
// BSAudioManager::QInitialized: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstdint>
class BSAudio;

// AudioStateF8, Functionccb0a0, pad00, stateF8: GUESS(low)
struct AudioStateF8
{
    std::uint8_t pad00[0x64];  // 00
    std::uint32_t value64;  // 64
};
extern BSAudio* platformInstance;
extern void* audioManagerInstance;
class BSAudioManager {
public:
    static BSAudio& QPlatformInstance();
    static bool QInitialized();
    void Functionccb0a0(std::uint32_t a_value);  // compared: 0xccb0a0

    std::uint8_t pad00[0xF8];  // 00
    AudioStateF8* stateF8;  // F8
};
