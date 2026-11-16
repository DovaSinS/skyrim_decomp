// TESObjectBOOK, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x2805a0, 36 bytes: TESObjectBOOK::Function2805a0.
// TESObjectBOOK: STANDIN EXE_RTTI
// BookRequest, BookManager, GetManager, HandleRequest, Function2805a0: GUESS(low)
#pragma once
class TESObjectBOOK;
struct BookRequest { TESObjectBOOK* book; bool flag; };
class BookManager { public: void HandleRequest(BookRequest&); };
class TESObjectBOOK { public: BookManager* GetManager(); void Function2805a0(bool); };
