#pragma once

char* cartridge;

BOOL InsertCartridge(LPCWSTR filePath);
BOOL LoadCartridge(LPCWSTR filePath);
void UnloadRom();
BOOL ErrorAndCloseHeaderHandle(HANDLE hROM, LPCWSTR message);