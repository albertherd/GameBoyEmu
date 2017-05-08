#pragma once
#include "registers.h"

#define FlagRegZeroFlagMask 0x80
#define FlagRegSubtractFlagMask 0x40
#define FlagRegHalfCarryFlagMask 0x20
#define FlagRegCarryFlagMask 0x10
#define FlagRegNoFlagMask 0x00

inline void InstructionLD16BitMem(SixteenBitReg* dst, char cycles);
inline void InstructionLD8BitReg(SixteenBitReg* dst, EightBitReg* src, char cycles);
inline void InstructionXOR8BitReg(EightBitReg* reg, char cycles);
inline void ApplyZeroFlag(short value);
inline ApplyFlag(char flagMask);
inline void ClearFlags();
inline void ProcessorIncrementPc();
inline void ProcessorAddCycles(char cycles);

inline void InstructionLD16BitMem(SixteenBitReg* dst, char cycles)
{
	dst->EightBitLowReg.EightBitValue = MemoryGet8Bit(processor.PC.SixteenBitValue);
	ProcessorIncrementPc();
	dst->EightBitHighReg.EightBitValue = MemoryGet8Bit(processor.PC.SixteenBitValue);
	ProcessorIncrementPc();
	ProcessorAddCycles(cycles);
}

inline void InstructionLD8BitReg(SixteenBitReg* dst, EightBitReg* src, char cycles)
{
	dst->EightBitHighReg.EightBitValue = src->EightBitValue;
	ProcessorAddCycles(cycles);
}

inline void InstructionXOR8BitReg(EightBitReg* reg, char cycles)
{
	processor.AF.EightBitHighReg.EightBitValue = processor.AF.EightBitHighReg.EightBitValue ^ reg->EightBitValue;
	ClearFlags();
	ApplyZeroFlag(processor.AF.EightBitHighReg.EightBitValue);
	ProcessorAddCycles(cycles);
}

inline void ApplyZeroFlag(short value)
{
	if (value == 0)
		ApplyFlag(FlagRegZeroFlagMask);
}

inline ApplyFlag(char flagMask)
{
	processor.Flags.EightBitValue = processor.Flags.EightBitValue | flagMask;
}

inline void ClearFlags()
{
	processor.Flags.EightBitValue = 0;
}

inline void ProcessorIncrementPc()
{
	processor.PC.SixteenBitValue++;
}

inline void ProcessorAddCycles(char cycles)
{
	processor.Cycles += cycles;
}
