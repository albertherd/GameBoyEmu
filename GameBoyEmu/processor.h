#pragma once
#include "registers.h"

#define PCDefaultValue 0x100
#define SPDefaultValue 0xFFFE
#define AFDefaultValueCGB 0x11B0
#define AFDefaultValueNoCGB 0x01B0
#define BCDefaultValue 0x0013
#define DEDefaultValue 0x00D8
#define HLDefaultValue 0x014D

#define InstructionUnimplemented 0x00
#define InstructionNOP 0x01
#define InstructionLoad 0x02
#define InstructionXOR 0x03

#define AddendTypeNoAddend 0x00
#define AddendType8BitData 0x01
#define AddendType16BitData 0x02
#define AddendType16BitAddress 0x03
#define AddendType8BitUnsignedAddedData 0x04
#define AddendType8BitSignedAddedData 0x05

typedef struct Processor
{
	BOOL isInCbMode;
	EightBitReg Flags;
	SixteenBitReg AF;
	SixteenBitReg BC;
	SixteenBitReg DE;
	SixteenBitReg HL;
	SixteenBitReg SP;
	SixteenBitReg PC;
	size_t Cycles;
} Processor;

typedef struct Operand {
	union {
		SixteenBitReg* SixteenBitReg;
		EightBitReg* EightBitReg;
	};
} Operand;

typedef struct Instruction
{
	unsigned char InstructionType;
	Operand LeftOperand;
	Operand RightOperand;
	unsigned char AddendType;
	unsigned char AddendsCount;
	unsigned char ByteLength;
	unsigned char Cycles;
	unsigned char Flags;
} Instruction;

Processor processor;
void ProcessorExecute();

