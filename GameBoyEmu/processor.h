#pragma once

#define PCDefaultValue 0x100
#define SPDefaultValue 0xFFFE
#define AFDefaultValueCGB 0x11B0
#define AFDefaultValueNoCGB 0x01B0
#define BCDefaultValue 0x0013
#define DEDefaultValue 0x00D8
#define HLDefaultValue 0x014D


typedef struct EightBitReg
{
	unsigned char Val;
} EightBitReg;

typedef struct SixteenBitReg
{
	union
	{
		struct {
			EightBitReg High;
			EightBitReg Low;
		};
		unsigned short Val;
	};
}SixteenBitReg;

typedef struct Processor
{
	SixteenBitReg AF;
	SixteenBitReg BC;
	SixteenBitReg DE;
	SixteenBitReg HL;
	SixteenBitReg SP;
	SixteenBitReg PC;
} Processor;

Processor processor;