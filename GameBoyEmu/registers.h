#pragma once

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
