#include "stdafx.h"
#include "memory.h"

unsigned char MemoryGet8Bit(unsigned short address)
{
	if (address >= ROMBank0Start && address <= ROMBank0End)
	{
		return ROMBank0[address];
	}
}





