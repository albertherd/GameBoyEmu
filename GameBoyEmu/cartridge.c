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
