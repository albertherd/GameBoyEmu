#pragma once

enum MBCTypes ROMHeaderGetCartridgeType();
char ROMHeaderGetRomBanks();
char ROMHeaderGetRamBanks();
BOOL IsCGBOnly();
BOOL SupportsCGBFunctions();
BOOL IsSGB();
char* ROMHeaderGetROMTitle();