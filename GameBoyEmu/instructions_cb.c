#include "stdafx.h"
#include "instructions_cb.h"
#include "processor.h"
#include "instructions_inline.h"

/*
BIT 7,H
 2  8
Z 0 1 -
*/

void Opcode_CD_0x7c() 
{
	TestBit(7, &processor.HL.EightBitHighReg);
	processor.IsCbMode = FALSE;
}