#pragma once

#define PCDefaultValue 0x100
#define SPDefaultValue 0xFFFE
#define AFDefaultValueCGB 0x11B0
#define AFDefaultValueNoCGB 0x01B0
#define BCDefaultValue 0x0013
#define DEDefaultValue 0x00D8
#define HLDefaultValue 0x014D

#define ZeroFlagMask 0x80
#define SubtractFlagMask 0x40
#define HalfCarryFlagMask 0x20
#define CarryFlagMask 0x10
#define NoFlagMask 0x00

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


typedef struct EightBitReg {
	unsigned char EightBitValue;
} EightBitReg;

typedef struct SixteenBitReg
{
	union
	{
		struct {
			EightBitReg EightBitLowReg;
			EightBitReg EightBitHighReg;
		};
		unsigned short SixteenBitValue;
	};
} SixteenBitReg;

typedef struct Processor
{
	SixteenBitReg AF;
	SixteenBitReg BC;
	SixteenBitReg DE;
	SixteenBitReg HL;
	SixteenBitReg SP;
	SixteenBitReg PC;
	EightBitReg Flags;
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

static Instruction instructions[256] =
{
	{ InstructionNOP, NULL, NULL, AddendTypeNoAddend, 0, 1, 4, NoFlagMask }, //0x00
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x01
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x02
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x03
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x04
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x05
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x06
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x07
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x08
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x09
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x10
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x11
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x12
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x13
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x14
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x15
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x16
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x17
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x18
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x19
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x20
	{ InstructionLoad, &processor.HL, NULL, AddendType16BitData, 2, 3, 12, NoFlagMask }, //0x21
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x22
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x23
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x24
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x25
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x26
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x27
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x28
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x29
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x30
	{ InstructionLoad, &processor.SP, NULL, AddendType16BitData, 2, 3, 12, NoFlagMask }, //0x31
	{ InstructionLoad, 0, 0, 0, 1, 4, NoFlagMask }, //0x32
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x33
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x34
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x35
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x36
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x37
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x38
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x39
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x40
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x41
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x42
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x43
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x44
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x45
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x46
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x47
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x48
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x49
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x50
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x51
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x52
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x53
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x54
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x55
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x56
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x57
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x58
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x59
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x60
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x61
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x62
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x63
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x64
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x65
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x66
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x67
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x68
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x69
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x70
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x71
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x72
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x73
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x74
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x75
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x76
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x77
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x78
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x79
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x80
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x81
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x82
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x83
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x84
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x85
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x86
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x87
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x88
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x89
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x90
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x91
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x92
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x93
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x94
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x95
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x96
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x97
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x98
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x99
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAD
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAE
	{ InstructionXOR, &processor.AF, AddendType8BitData, 1, 1, 4, ZeroFlagMask }, //0xAF

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBD
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBF

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCD
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCF

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDD
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDF

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xEA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xEB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xEC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xED
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xEE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xEF

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFD
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFF
};

static Instruction CBInstructions[256] =
{
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x00
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x01
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x02
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x03
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x04
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x05
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x06
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x07
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x08
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x09
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x0F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x10
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x11
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x12
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x13
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x14
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x15
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x16
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x17
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x18
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x19
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x1F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x20
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x21
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x22
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x23
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x24
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x25
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x26
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x27
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x28
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x29
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x2F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x30
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x31
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x32
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x33
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x34
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x35
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x36
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x37
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x38
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x39
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x3F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x40
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x41
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x42
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x43
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x44
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x45
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x46
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x47
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x48
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x49
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x4F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x50
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x51
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x52
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x53
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x54
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x55
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x56
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x57
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x58
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x59
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x5F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x60
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x61
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x62
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x63
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x64
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x65
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x66
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x67
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x68
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x69
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x6F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x70
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x71
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x72
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x73
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x74
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x75
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x76
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x77
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x78
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x79
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x7F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x80
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x81
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x82
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x83
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x84
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x85
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x86
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x87
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x88
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x89
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x8F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x90
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x91
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x92
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x93
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x94
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x95
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x96
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x97
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x98
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x99
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9A
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9B
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9C
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9D
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9E
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0x9F

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xA9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAD
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xAF

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xB9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBD
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xBF

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xC9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCD
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xCF

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xD9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDD
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xDF

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xE9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xEA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xEB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xEC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xED
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xEE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xEF

	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF0
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF1
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF2
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF3
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF4
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF5
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF6
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF7
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF8
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xF9
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFA
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFB
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFC
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFD
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFE
	{ InstructionUnimplemented, NULL, NULL, 0, 1, 4, NoFlagMask }, //0xFF
};

void ProcessorExecute();

void ParseNOPInstruction(Instruction* instruction);
void ParseLoadInstruction(Instruction* instruction);
void ParseXORInstruction(Instruction* instruction);