#pragma once
#include "registers.h"
#include "memory.h"

#define FlagRegZeroFlagMask 0x80
#define FlagRegSubtractFlagMask 0x40
#define FlagRegHalfCarryFlagMask 0x20
#define FlagRegCarryFlagMask 0x10
#define FlagRegNoFlagMask 0x00

inline void InstructionLD16BitImmediate(SixteenBitReg* dst);
inline void InstructionLDFromRegToMemory(SixteenBitReg* dst, EightBitReg* src);
inline void InstructionXOR8BitReg(EightBitReg* reg);
inline void TestBit(char position, EightBitReg* reg);
inline void ApplyZeroFlag(short value);
inline ApplyFlag(char flagMask);
inline void ClearFlags();
inline void ProcessorIncrementPc();
inline void ProcessorAddCycles(char cycles);

inline void InstructionLD16BitImmediate(SixteenBitReg* dst)
{
	dst->EightBitLowReg.EightBitValue = MemoryGet8Bit(processor.PC.SixteenBitValue);
	ProcessorIncrementPc();
	dst->EightBitHighReg.EightBitValue = MemoryGet8Bit(processor.PC.SixteenBitValue);
	ProcessorIncrementPc();

	ProcessorAddCycles(12);
}

inline void InstructionLDFromRegToMemory(SixteenBitReg* dst, EightBitReg* src)
{
	MemoryWrite8Bit(dst->SixteenBitValue, src->EightBitValue);

	ProcessorAddCycles(8);
}

inline void InstructionXOR8BitReg(EightBitReg* reg)
{
	processor.AF.EightBitHighReg.EightBitValue = processor.AF.EightBitHighReg.EightBitValue ^ reg->EightBitValue;
	ClearFlags();
	ApplyZeroFlag(processor.AF.EightBitHighReg.EightBitValue);

	ProcessorAddCycles(4);
}


inline void TestBit(char position, EightBitReg* reg)
{
	ApplyZeroFlag((reg->EightBitValue >> position) & 0x01);
	UnapplyFlag(FlagRegSubtractFlagMask);
	ApplyFlag(FlagRegHalfCarryFlagMask);

	ProcessorAddCycles(8);
}

/* Flag Manipulations start */

inline void ApplyZeroFlag(short value)
{
	if (value == 0)
	{
		ApplyFlag(FlagRegZeroFlagMask);
	}	
	else 
	{
		UnapplyFlag(FlagRegZeroFlagMask);
	}
}

inline ApplyFlag(char flagMask)
{
	processor.AF.EightBitHighReg.EightBitValue |= flagMask;
}

inline UnapplyFlag(char flagMask)
{
	processor.AF.EightBitHighReg.EightBitValue &= ~flagMask;
}

inline void ClearFlags()
{
	processor.AF.EightBitHighReg.EightBitValue = 0;
}

/* Flag Manipulations End */

/* General Helper functions start */

inline void ProcessorIncrementPc()
{
	processor.PC.SixteenBitValue++;
}

inline void ProcessorAddCycles(char cycles)
{
	processor.Cycles += cycles;
}

/* General Helper functions end */