#pragma once

//http://gbdev.gg8.se/wiki/articles/The_Cartridge_Header
#define ROMHeaderTitleSizeNoCGBFlagLength 16 //Old title, uses all space 
#define ROMHeaderTitleSizeCGBFlagLength 11 //May be 15 or 11
#define ROMHeaderTitleLength 17 //Documentation says max of 16 (plus null terminator) 

unsigned const char nintendoLogo[] = {
	0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
	0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
	0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
};

enum MBCTypes {
	MBC_SIMPLE,
	MBC_MBC1,
	MBC_MMM01,
	MBC_MBC2,
	MBC_MBC3,
	MBC_MBC4,
	MBC_MBC5,
	MBC_MBC6,
	MBC_MBC7,
	MBC_UNKNOWN
};

enum MBCTypes ROMHeaderGetCartridgeType();
char ROMHeaderGetRomBanks();
char ROMHeaderGetRamBanks();
BOOL IsCGBOnly();
BOOL SupportsCGBFunctions();
BOOL IsSGB();
BOOL ROMHeaderGetROMTitle(char* buffer, char length);