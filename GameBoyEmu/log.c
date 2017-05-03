#include "stdafx.h"
#include "log.h"

static BOOL consoleAllocated = FALSE;

void debugLog(LPCWSTR msg)
{
	EnsureConsoleAllocated();
	OutputDebugString(msg);
}

void EnsureConsoleAllocated()
{
	if (consoleAllocated)
		return;

	AllocConsole();
	consoleAllocated = TRUE;
}

