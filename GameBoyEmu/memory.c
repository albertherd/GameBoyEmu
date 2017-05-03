#include "stdafx.h"
#include "memory.h"

unsigned char MemoryGetChar(unsigned short address)
{
	if (address >= ROMBank0Start && address <= ROMBank0End)
	{
		return ROMBank0[address];
	}
}
