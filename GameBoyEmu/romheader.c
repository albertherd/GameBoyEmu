#include "stdafx.h"
#include "memory.h"
#include "romheader.h"

enum MBCTypes ROMHeaderGetCartridgeType()
{
	switch (ROMBank0[CartridgeTypeOffset])
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

char ROMHeaderGetRomBanks()
{
	char romSizeFlag = ROMBank0[ROMBankOffset];
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

char ROMHeaderGetRamBanks()
{
	switch (ROMBank0[RAMBankOffset])
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

BOOL IsCGBOnly() 
{
	return ROMBank0[CGBFlagOffset] == CGBFlagCGBOnly ? TRUE : FALSE;
}

BOOL SupportsCGBFunctions()
{
	return ROMBank0[CGBFlagOffset] == CGBFlagSupportsCGBFunctions ? TRUE : FALSE;
}

BOOL IsSGB() 
{
	return ROMBank0[SGBFlagOffset] == SGBSupportsSGB ? TRUE : FALSE;
}

BOOL ValidateCartridgeHeader() 
{
	return memcmp(ROMBank0 + NintendoLogoOffset, nintendoLogo, sizeof(nintendoLogo)) == 0;
}

char* ROMHeaderGetROMTitle() 
{
	int titleLength = strnlen_s(ROMBank0[TitleOffset], 0xF);
	char* title = malloc(titleLength);
	strcpy_s(title, titleLength, ROMBank0[TitleOffset]);
	return title;
}
