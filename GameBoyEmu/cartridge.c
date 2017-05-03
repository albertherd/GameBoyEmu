#include "stdafx.h"
#include "cartridge.h"
#include "log.h"
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
		return ErrorAndCloseHeaderHandle(hROM, TEXT("Could not get file size"));
	}

	cartridge = malloc(romSize.LowPart);
	if (!ReadFile(hROM, cartridge, romSize.LowPart, &bytesRead, NULL))
	{
		return ErrorAndCloseHeaderHandle(hROM, TEXT("Could not load ROM to memory"));
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

BOOL ErrorAndCloseHeaderHandle(HANDLE hROM, LPCWSTR message)
{
	debugLog(message);
	CloseHandle(hROM);
	return FALSE;
}
