#include "stdafx.h"
#include "log.h"

static BOOL consoleAllocated = FALSE;

void debugLog(LPCWSTR msg)
{
	EnsureConsoleAllocated();
	OutputDebugString(msg);
}

void debugLogError(LPCWSTR msg)
{
	LPCTSTR strErrorMessage = NULL;
	GetLastErrorStr(strErrorMessage);
	//OutputDebugString(strcat_s("GetLastError: ", strErrorMessage));
	HeapFree(GetProcessHeap(), NULL, strErrorMessage);
}

void GetLastErrorStr(LPCSTR strErrorMessage)
{
	DWORD dLastError = GetLastError();
	
	FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ARGUMENT_ARRAY | FORMAT_MESSAGE_ALLOCATE_BUFFER,
		NULL,
		dLastError,
		0,
		(LPWSTR)&strErrorMessage,
		0,
		NULL);
}

void EnsureConsoleAllocated()
{
	if (consoleAllocated)
		return;

	AllocConsole();
	consoleAllocated = TRUE;
}

