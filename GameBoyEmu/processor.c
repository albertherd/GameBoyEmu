#include "stdafx.h"
#include "processor.h"
#include "cartridge.h"
#include "bootrom.h"
#include "memory.h"

void SetSixteenBitVal(SixteenBitReg reg, const unsigned short value)
{
	reg.Val = value;
}

void SetEightBitVal(SixteenBitReg reg, const unsigned char value)
{
	reg.Low.Val = value;
}
