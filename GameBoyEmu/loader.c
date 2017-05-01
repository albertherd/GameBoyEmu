#pragma once
#include "stdafx.h"
#include "loader.h"
#include "log.h"
#include "memory.h"

BOOL InitEmulation(LPCWSTR filePath)
{
	if (!IsValidPtr(filePath))
	{
		return FALSE;
	}
	return LoadCartridge(filePath);
}

BOOL LoadCartridge(LPCWSTR filePath)
{
	unsigned char romName[ROMNameMaxLength + 1] = { 0 };
	unsigned int romNameLength = 0;

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

	if (romSize.QuadPart < ROMHeaderSize)
	{
		return ErrorAndCloseHeaderHandle(hROM, "File is too small (smaller than header)");
	}

	rom = malloc(sizeof(romSize.QuadPart));

	if (!ReadFile(hROM, rom, romSize.QuadPart, &bytesRead, NULL))
	{
		ErrorAndCloseHeaderHandle(hROM, "Could not load ROM to memory");
	}

	while (1)
	{
		if (romNameLength > ROMNameMaxLength)
		{
			ErrorAndCloseHeaderHandle(hROM, "ROM Name is too long (or invalid)");
		}
		if (rom[ROMNameHeaderOffset + romNameLength] == 0x80 || header[ROMNameHeaderOffset + romNameLength] == 0xc0)
		{
			memcpy(romName, header + ROMNameHeaderOffset, romNameLength - 1);
			romName[romNameLength] = '\0';
			break;
		}
		else 
		{
			romNameLength++;
		}
	}

	if (rom[CGBFlag] == 0x80 || rom[CGBFlag] == 0xc0)
	{

	}

	return TRUE;


}

void UnloadRom() 
{
	if (IsValidPtr(rom)) 
	{
		free(rom);
	}
}

BOOL ErrorAndCloseHeaderHandle(HANDLE hROM, const char* message)
{
	logError(TEXT("File is too small (smaller than header)"));
	CloseHandle(hROM);
	return FALSE;
}
