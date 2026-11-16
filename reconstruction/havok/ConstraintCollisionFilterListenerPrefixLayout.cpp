// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (included pinned community/FNV interface declarations and independent target RTTI/construction/storage analysis).
// Drafted by GPT-6.1 Sol; PairCollisionFilter field-group and trailing listener prefix recovery.
// Labels: v2
// Code origin: original physical storage declarations and defaulted prefix construction; no external implementation body reused.
// Declaration references and permissions for the collision/listener interfaces are retained in the included CollisionFilterLayout.h.
// hkpPairCollisionFilter, hkpConstraintCollisionFilter: EXE_RTTI
// PairFilterEntriesLayout, PairFilterTableStorageLayout, PairCollisionFilterStorageLayout, ConstraintCollisionFilterListenerPrefixLayout, ConstraintCollisionFilterListenerStorageLayout, entries, elementCount, indexMask, disabledPairs, childFilter: GUESS(medium) STANDIN
// Target construction independently writes a pointer at72, two separate32-bit words at80/84, and the incoming child object pointer at88; its destruction passes the address72 field group to an out-of-line cleanup and releases the pointer at88.
// The fields' source spellings, container interpretation and exact child pointee class are guesses; original container behavior/lifetime and source identity are unassessed. ReferencedObjectLayout is a storage-compatible base view, not a claimed exact original child-filter declaration.
// The96-byte primary storage follows the public72-byte collision storage plus these observed typed fields. Target RTTI separately places the constraint-listener subobject at96.
// No deletion-size argument supplies a field, gap or size. No explicit padding/byte array/helper body/emission attribute introduced.
// Only the listed compiler-generated offset96 secondary destructor adjustor is compared; all other methods, construction/destruction and container behavior remain outside the byte-match claim.
// The104-byte assertion covers this represented collision/table/child/listener prefix, not an original complete owner definition or instantiability/behavior claim.
// Size and offset assertions are layout checks, not function passes.
// RVA 0xb518b4; 9 bytes
#include "ConstraintCollisionFilterListenerPrefixLayout.h"
namespace ResearchLayouts {
ConstraintCollisionFilterListenerPrefixLayout::ConstraintCollisionFilterListenerPrefixLayout() = default;
}
