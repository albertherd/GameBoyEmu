#include "stdafx.h"
#include "instructions.h"
#include "processor.h"
#include "instructions_inline.h"

void Opcode_0x21()
{
	InstructionLD16BitMem(&processor.HL, 12);
}

void Opcode_0x32()
{
	InstructionLD8BitReg(&processor.HL, &processor.AF.EightBitHighReg, 8);
	processor.HL.SixteenBitValue--;
}

void Opcode_0x31()
{
	InstructionLD16BitMem(&processor.SP, 12);
}

void Opcode_0xAF()
{
	InstructionXOR8BitReg(&processor.AF, 4);
}

void Opcode_0xCB()
{
	processor.IsCbMode = TRUE;
}