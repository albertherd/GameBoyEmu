#pragma once
#include "registers.h"

#define FlagRegZeroFlagMask 0x80
#define FlagRegSubtractFlagMask 0x40
#define FlagRegHalfCarryFlagMask 0x20
#define FlagRegCarryFlagMask 0x10
#define FlagRegNoFlagMask 0x00

inline void InstructionLD16BitMem(SixteenBitReg* dst);
inline void InstructionLD8BitReg(SixteenBitReg* dst, EightBitReg* src);
inline void InstructionXOR8BitReg(EightBitReg* reg);
inline void ApplyZeroFlag(short value);
inline ApplyFlag(char flagMask);
inline void ClearFlags();
inline void ProcessorIncrementPc();
inline void ProcessorAddCycles(char cycles);

inline void InstructionLD16BitMem(SixteenBitReg* dst)
{
	dst->EightBitLowReg.EightBitValue = MemoryGet8Bit(processor.PC.SixteenBitValue);
	ProcessorIncrementPc();
	dst->EightBitHighReg.EightBitValue = MemoryGet8Bit(processor.PC.SixteenBitValue);
	ProcessorIncrementPc();
}

inline void InstructionLD8BitReg(SixteenBitReg* dst, EightBitReg* src)
{
	dst->EightBitHighReg.EightBitValue = src->EightBitValue;
}

inline void InstructionXOR8BitReg(EightBitReg* reg)
{
	processor.AF.EightBitHighReg.EightBitValue = processor.AF.EightBitHighReg.EightBitValue ^ reg->EightBitValue;
	ClearFlags();
	ApplyZeroFlag(processor.AF.EightBitHighReg.EightBitValue);
}


inline void TestBit(unsigned char value, char position)
{
	ApplyZeroFlag((value >> position) & 0x01);
	UnapplyFlag(FlagRegSubtractFlagMask);
	ApplyFlag(FlagRegHalfCarryFlagMask);
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
	processor.Flags.EightBitValue |= flagMask;
}

inline UnapplyFlag(char flagMask)
{
	processor.Flags.EightBitValue &= ~flagMask;
}

inline void ClearFlags()
{
	processor.Flags.EightBitValue = 0;
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