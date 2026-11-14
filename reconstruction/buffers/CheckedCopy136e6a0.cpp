// Build: sse-steam-1-7-104; RVA 0x136e6a0; 171 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// Drafted by GPT-6.1 Sol, checked-copy template.
// Labels: v2
// CheckedCopy136e6a0, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// Original name and ownership unknown; class is an ABI stand-in with no storage.
// Only compiled code is compared; no original class identity is claimed.
#include "CheckedCopy136e6a0.h"
#include <string.h>
int CheckedCopy136e6a0::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
