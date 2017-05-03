#include "stdafx.h"
#include "processor.h"
#include "memory.h"
#include "instructions.h"

inline void IncrementPc()
{
	processor.PC.SixteenBitValue++;
}

void ProcessorExecute()
{
	while (1)
	{
		Instruction instruction = instructions[MemoryGetChar(processor.PC.SixteenBitValue)];
		IncrementPc();

		if(instruction.InstructionType == InstructionLoad)
		{
			ParseLoadInstruction(&instruction);
		}
		else if (instruction.InstructionType == InstructionXOR)
		{
			ParseXORInstruction(&instruction);
		}
	}
}

void ParseLoadInstruction(Instruction* instruction)
{
	if (instruction->AddendType == AddendType16BitData) 
	{
		instruction->Augend.SixteenBitReg->EightBitLowReg.EightBitValue = MemoryGetChar(processor.PC.SixteenBitValue);
		IncrementPc();
		instruction->Augend.SixteenBitReg->EightBitHighReg.EightBitValue = MemoryGetChar(processor.PC.SixteenBitValue);
		IncrementPc();
	}

	processor.Cycles += instruction->Cycles;
}

void ParseXORInstruction(Instruction* instruction)
{
	processor.AF.EightBitHighReg.EightBitValue = processor.AF.EightBitHighReg.EightBitValue ^ instruction->Augend.EightBitReg->EightBitValue;
	processor.Cycles += instruction->Cycles;
}
