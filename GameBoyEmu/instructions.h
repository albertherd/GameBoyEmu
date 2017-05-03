#pragma once

#include "processor.h"

#define ZeroFlagMask 0x80
#define SubtractFlagMask 0x40
#define HalfCarryFlagMask 0x20
#define CarryFlagMask 0x10
#define NoFlagMask 0x00

#define InstructionNop 0x00
#define InstructionLoad 0x01
#define InstructionXOR 0x02

#define AddendTypeNoAddend 0x00
#define AddendType8BitData 0x01
#define AddendType16BitData 0x02
#define AddendType16BitAddress 0x03
#define AddendType8BitUnsignedAddedData 0x04
#define AddendType8BitSignedAddedData 0x05

typedef struct Augend {
	union {
		SixteenBitReg* SixteenBitReg;
		EightBitReg* EightBitReg;
	};
} Augend;

typedef struct Instruction
{
	unsigned char InstructionType;
	Augend Augend;
	unsigned char AddendType;
	unsigned char AddendsCount;
	unsigned char ByteLength;
	unsigned char Cycles;
	unsigned char Flags;
} Instruction;

Instruction instructions[256] =
{
	{ InstructionNop, NULL, AddendTypeNoAddend, 0, 1, 4, NoFlagMask }, //0x00
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x01
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x02
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x03
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x04
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x05
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x06
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x07
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x08
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x09
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x10
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x11
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x12
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x13
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x14
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x15
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x16
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x17
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x18
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x19
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x20
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x21
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x22
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x23
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x24
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x25
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x26
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x27
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x28
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x29
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x30
	{ InstructionLoad, &processor.SP, AddendType16BitData, 2, 3, 12, NoFlagMask }, //0x31
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x32
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x33
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x34
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x35
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x36
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x37
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x38
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x39
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x40
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x41
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x42
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x43
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x44
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x45
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x46
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x47
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x48
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x49
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x50
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x51
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x52
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x53
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x54
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x55
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x56
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x57
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x58
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x59
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x60
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x61
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x62
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x63
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x64
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x65
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x66
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x67
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x68
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x69
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x70
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x71
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x72
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x73
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x74
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x75
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x76
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x77
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x78
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x79
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x80
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x81
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x82
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x83
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x84
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x85
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x86
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x87
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x88
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x89
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x90
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x91
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x92
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x93
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x94
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x95
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x96
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x97
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x98
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x99
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAD
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAE
	{ InstructionXOR, &processor.AF, AddendType8BitData, 1, 1, 4, ZeroFlagMask }, //0xAF

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBD
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBF

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCD
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCF

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDD
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDF

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xEA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xEB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xEC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xED
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xEE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xEF

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFD
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFF
};

Instruction CBInstructions[256] =
{
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x00
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x01
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x02
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x03
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x04
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x05
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x06
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x07
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x08
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x09
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x0F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x10
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x11
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x12
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x13
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x14
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x15
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x16
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x17
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x18
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x19
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x1F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x20
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x21
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x22
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x23
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x24
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x25
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x26
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x27
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x28
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x29
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x2F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x30
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x31
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x32
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x33
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x34
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x35
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x36
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x37
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x38
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x39
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x3F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x40
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x41
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x42
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x43
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x44
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x45
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x46
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x47
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x48
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x49
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x4F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x50
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x51
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x52
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x53
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x54
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x55
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x56
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x57
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x58
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x59
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x5F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x60
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x61
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x62
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x63
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x64
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x65
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x66
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x67
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x68
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x69
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x6F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x70
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x71
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x72
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x73
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x74
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x75
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x76
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x77
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x78
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x79
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x7F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x80
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x81
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x82
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x83
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x84
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x85
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x86
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x87
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x88
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x89
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x8F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x90
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x91
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x92
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x93
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x94
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x95
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x96
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x97
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x98
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x99
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9A
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9B
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9C
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9D
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9E
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0x9F

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xA9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAD
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xAF

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xB9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBD
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xBF

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xC9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCD
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xCF

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xD9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDD
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xDF

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xE9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xEA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xEB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xEC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xED
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xEE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xEF

	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF0
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF1
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF2
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF3
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF4
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF5
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF6
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF7
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF8
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xF9
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFA
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFB
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFC
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFD
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFE
	{ InstructionNop, 0, 0, 0, 1, 4, NoFlagMask }, //0xFF
};