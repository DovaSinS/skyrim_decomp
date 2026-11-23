// Source exposure: mixed (pinned image listing, community names and sibling source).
// Code origin: original reconstruction with a labelled sibling adaptation.
// Sibling source: fo4-private@1b765c70 src/BSAudio/BSAudioManager.cpp:75
// Adapted bodies: QPlatformInstance from fo4-private@1b765c70 (author-permission).
// BSAudioManager::QInitialized: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xcca620 BSAudioManager::QPlatformInstance
// 0xcca630 BSAudioManager::QInitialized
// 0xccb0a0 BSAudioManager::Functionccb0a0
// Code origin: Functionccb0a0 original, from the listing and community declarations only
#include "BSAudioManager.h"
BSAudio& BSAudioManager::QPlatformInstance() { return *platformInstance; }

// Audio requires both the platform and manager instances.
bool BSAudioManager::QInitialized()
{
    return platformInstance != nullptr && audioManagerInstance != nullptr;
}

void BSAudioManager::Functionccb0a0(std::uint32_t a_value)
{
    if (stateF8) {
        stateF8->value64 = a_value;
    }
}
