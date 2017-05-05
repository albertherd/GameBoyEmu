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
		
		if (instruction.InstructionType == InstructionNOP)
		{
			ParseNOPInstruction(&instruction);
		}
		else if(instruction.InstructionType == InstructionLoad)
		{
			ParseLoadInstruction(&instruction);
		}
		else if (instruction.InstructionType == InstructionXOR)
		{
			ParseXORInstruction(&instruction);
		}
	}
}

void TempGetInstruction()
{

}


void ParseNOPInstruction(Instruction* instruction)
{
	processor.Cycles += instruction->Cycles;
}

void ParseLoadInstruction(Instruction* instruction)
{
	if (instruction->AddendType == AddendType16BitData) 
	{
		instruction->LeftOperand.SixteenBitReg->EightBitLowReg.EightBitValue = MemoryGetChar(processor.PC.SixteenBitValue);
		IncrementPc();
		instruction->LeftOperand.SixteenBitReg->EightBitHighReg.EightBitValue = MemoryGetChar(processor.PC.SixteenBitValue);
		IncrementPc();
	}

	processor.Cycles += instruction->Cycles;
}

void ParseXORInstruction(Instruction* instruction)
{
	processor.AF.EightBitHighReg.EightBitValue = processor.AF.EightBitHighReg.EightBitValue ^ instruction->Augend.EightBitReg->EightBitValue;
	processor.Cycles += instruction->Cycles;
}
