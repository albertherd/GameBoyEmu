#include "stdafx.h"
#include "memory.h"

unsigned char MemoryGet8Bit(unsigned short address)
{

}

void MemoryWrite8Bit(unsigned short address, char value)
{
	*GetMemoryAt(address) = value;
}

char* GetMemoryAt(unsigned short address)
{
	if (address >= ROMBank0Start && address <= ROMBank0End)
	{
		return &ROMBank0[address];
	}

	if (address >= CharacterRAMStart && address <= BGMap2End)
	{
		return &VRAM[address];
	}
}





