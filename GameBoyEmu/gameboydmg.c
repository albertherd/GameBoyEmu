#include "stdafx.h"
#include "gameboydmg.h"
#include "memory.h"

void Boot()
{
	//As stated, we'll use the native boot sequence rather than writing it out ourselves.
	memcpy(ROMBank0, gameBoyBootRom, sizeof(gameBoyBootRom));
}