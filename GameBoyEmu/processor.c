#include "stdafx.h"
#include "processor.h"

void SetSixteenBitVal(SixteenBitReg reg, const unsigned short value)
{
	reg.Val = value;
}

void SetEightBitVal(SixteenBitReg reg, const unsigned char value)
{
	reg.Low.Val = value;
}

void Reset() 
{
	SetSixteenBitVal(processor.AF, AFDefaultValueNoCGB);
	SetSixteenBitVal(processor.BC, BCDefaultValue);
	SetSixteenBitVal(processor.DE, DEDefaultValue);
	SetSixteenBitVal(processor.HL, HLDefaultValue);
	SetSixteenBitVal(processor.PC, PCDefaultValue);
	SetSixteenBitVal(processor.SP, SPDefaultValue);
}