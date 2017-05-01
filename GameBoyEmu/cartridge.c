#include "stdafx.h"
#include "cartridge.h"
#include "log.h"
#include "memory.h"
#include "math.h"

BOOL InsertCartridge(LPCWSTR filePath)
{
	if (!LoadCartridge(filePath)) 
	{
		return FALSE;
	}
	if (!VerifyCartridge())
	{
		debugLog(TEXT("Cartridge is invalid - validation with Nintendo logo failed"));
		return FALSE;
	}
	PopulateCartridgeMetadata();
	return TRUE;
}

BOOL LoadCartridge(LPCWSTR filePath)
{
	DWORD bytesRead;
	LARGE_INTEGER romSize;

	HANDLE hROM = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hROM == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	if (!GetFileSizeEx(hROM, &romSize))
	{
		return ErrorAndCloseHeaderHandle(hROM, "Could not get file size");
	}

	if (romSize.LowPart < ROMHeaderSize)
	{
		return ErrorAndCloseHeaderHandle(hROM, "File is too small (smaller than header)");
	}

	cartridge = malloc(romSize.LowPart);

	if (!ReadFile(hROM, cartridge, romSize.LowPart, &bytesRead, NULL))
	{
		return ErrorAndCloseHeaderHandle(hROM, "Could not load ROM to memory");
	}

	CloseHandle(hROM);
	return TRUE;
}

BOOL VerifyCartridge()
{
	return memcmp(cartridge + NintendoLogoOffset, nintendoLogo, sizeof(nintendoLogo)) == 0;
}


void PopulateCartridgeMetadata()
{
	memset(&romMetadata, 0, sizeof(romMetadata));

	if (cartridge[CGBFlagOffset] == CGBFlagSupportsCGBFunctions || cartridge[CGBFlagOffset] == CGBFlagCGBOnly) 
	{
		memcpy(romMetadata.title, cartridge + TitleOffset, TitleSizeCGBFlag);
		romMetadata.cgbOnly = cartridge[CGBFlagOffset] == CGBFlagCGBOnly ? TRUE : FALSE;
		romMetadata.supportCgbFunc = cartridge[CGBFlagOffset] == CGBFlagSupportsCGBFunctions ? TRUE : FALSE;
	}
	else
	{		
		memcpy(romMetadata.title, cartridge + TitleOffset, TitleSizeNoCGBFlag);
		romMetadata.cgbOnly = FALSE;
		romMetadata.supportCgbFunc = FALSE;
	}

	romMetadata.sgb = cartridge[SGBFlagOffset] == SGBSupportsSGB ? TRUE : FALSE;
	romMetadata.mbcType = GetCartridgeType();
	romMetadata.romBanks = GetRomBanks();
	romMetadata.ramBanks = GetRamBanks();
}

enum MBCTypes GetCartridgeType()
{
	switch (cartridge[CartridgeTypeOffset])
	{
		case 0x00:
		case 0x08:
		case 0x09:
			return MBC_SIMPLE;
		case 0x01:
		case 0x02:
		case 0x03:
			return MBC_MBC1;
		case 0x05:
		case 0x06:
			return MBC_MBC2;
		case 0x0B:
		case 0x0D:
		case 0x0F:
			return MBC_MMM01;
		case 0x10:
		case 0x11:
		case 0x12:
		case 0x13:
			return MBC_MBC3;
		case 0x15:
		case 0x16:
		case 0x17:
			return MBC_MBC4;
		case 0x19:
		case 0x1A:
		case 0x1B:
		case 0x1C:
		case 0x1D:
		case 0x1E:
			return MBC_MBC5;
		case 0x20:
			return MBC_MBC6;
		case 0x22:
			return MBC_MBC6;
		default:
			return MBC_UNKNOWN;
	}
}

char GetRomBanks() 
{
	char romSizeFlag = cartridge[ROMBankOffset];
	switch (romSizeFlag)
	{
		case 0x52:
			return 72;
		case 0x53:
			return 80;
		case 0x54:
			return 96;
		default:
			return (char)pow(romSizeFlag + 1, 2);
	}
}

char GetRamBanks()
{
	switch (cartridge[RAMBankOffset])
	{
		case 0x00:
			return 0;
		case 0x01:
		case 0x02:
			return 1;
		case 0x03:
			return 4;
		case 0x04:
			return 16;
		case 0x05:
			return 8;
		default:
				return 0;
	}
}

void UnloadRom()
{
	if (IsValidPtr(cartridge))
	{
		free(cartridge);
	}
}

BOOL ErrorAndCloseHeaderHandle(HANDLE hROM, const char* message)
{
	debugLogError(TEXT("File is too small (smaller than header)"));
	CloseHandle(hROM);
	return FALSE;
}
