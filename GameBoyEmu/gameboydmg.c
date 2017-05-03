#include "stdafx.h"
#include "gameboydmg.h"
#include "memory.h"
#include "processor.h"

void TurnOnGameBoy()
{
	//As stated, we'll use the native boot sequence rather than writing it out ourselves.
	memcpy(ROMBank0, gameBoyBootRom, sizeof(gameBoyBootRom));
	memset(&processor, 0, sizeof(processor));
	ProcessorExecute();
}

