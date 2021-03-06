#include "stdafx.h"
#include "instructions.h"
#include "processor.h"
#include "instructions_inline.h"

/*
LD HL,d16
 3  12
- - - -
*/
void Opcode_0x21()
{
	InstructionLD16BitImmediate(&processor.HL);
}

/*
LD SP,d16
 3  12
- - - -
*/
void Opcode_0x31()
{
	InstructionLD16BitImmediate(&processor.SP);
}


/*
LD (HL-),A
 1  8
- - - -
*/
void Opcode_0x32()
{
	InstructionLDFromRegToMemory(&processor.HL, &processor.AF.EightBitHighReg);
	processor.HL.SixteenBitValue--;
}

/*
XOR A
 1  4
Z 0 0 0
*/
void Opcode_0xAF()
{
	InstructionXOR8BitReg(&processor.AF);
}

/*PREFIX CB
   1  4
- - - -*/
void Opcode_0xCB()
{
	processor.IsCbMode = TRUE;
	ProcessorAddCycles(4);
}