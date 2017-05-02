#pragma once
#define ROMHeaderSize 0x14F
#define TitleSizeNoCGBFlag 16 //Old title, uses all space http://gbdev.gg8.se/wiki/articles/The_Cartridge_Header
#define TitleSizeCGBFlag 11 //May be 15 or 11, according to http://gbdev.gg8.se/wiki/articles/The_Cartridge_Header

#define NintendoLogoOffset 0x104
#define TitleOffset 0x134
#define CGBFlagOffset 0x143
#define SGBFlagOffset 0x146
#define CartridgeTypeOffset 0x147
#define ROMBankOffset 0x148
#define RAMBankOffset 0x149

#define CGBFlagSupportsCGBFunctions 0x80
#define CGBFlagCGBOnly 0xC0

#define SGBSupportsSGB 0x3

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

typedef struct RomMetadata {
	BOOL supportCgbFunc;
	BOOL cgbOnly;
	BOOL sgb;
	enum MBCTypes mbcType;
	int romBanks;
	int ramBanks;
	char title[16];
} RomMetadata;

RomMetadata romMetadata;
char* cartridge;

BOOL InsertCartridge(LPCWSTR filePath);
BOOL LoadCartridge(LPCWSTR filePath);
BOOL VerifyCartridge();
void PopulateCartridgeMetadata();
enum MBCTypes GetCartridgeType();
char GetRomBanks();
char GetRamBanks();
void UnloadRom();
BOOL ErrorAndCloseHeaderHandle(HANDLE hROM, const char* message);