#pragma once
void debugLog(LPCWSTR msg);
void debugLogError(LPCWSTR msg); 
void GetLastErrorStr(LPCSTR strErrorMessage);
void EnsureConsoleAllocated();