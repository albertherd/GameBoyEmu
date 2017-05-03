#pragma once

//http://gameboy.mongenel.com/dmg/asmmemmap.html
//http://bgb.bircd.org/pandocs.htm
//http://www.chrisantonellis.com/files/gameboy/gb-programming-manual.pdf

//Memory Size
#define RomBank0Length 0x4000
#define RomBankNLength 0x4000
#define VRAMLength 0x2000
#define ExternalRAMLength 0x2000
#define InternalRAM0Length 0x1000
#define InternalRAMNLength 0x1000
#define EchoRAMLength 0x1000
#define OAMLength 0x00A0
#define UnusableLength 0x0060
#define HardwareIoRegistersLength 0x0080
#define HighRAMLength 0x0127
#define InterruptEnableFlagRAM 0x001


//Memory Locations
#define RestartInterruptVectorStart 0x0000
#define RestartInterruptVectorEnd 0x00FF

#define CartridgeHeaderAreaStart 0x0100
#define CartridgeHeaderAreaEnd 0x014f

#define CartridgeROMBank0Start 0x0150
#define CartridgeROMBank0End 0x3FFF

#define CartridgeROMSwitchableBankStart 0x4000
#define CartridgeROMSwitchableBankEnd 0x7FFF

#define CharacterRAMStart 0x8000
#define CharacterRAMEnd 0x97ff

#define BGMap1Start 0x9800
#define BGMap1End 0x9BFF

#define BGMap2Start 0x9C00
#define BGMap2End 0x9FFF

#define CartridgeRAMStart 0xA000
#define CartridgeRAMEnd 0xBFFF

#define InternalRAMBank0Start 0xC000
#define InternalRAMBank0End 0xCFFF

#define InternalRAMBank1To7Start 0xD000
#define InternalRAMBank1To7End 0xDFFF

#define EchoRamStart 0xE000
#define EchoRamEnd 0xFDFF

#define OAMStart 0xFE00
#define OAMEnd 0xFE9F

#define UnusableStart 0xFEA0
#define UsusableEnd 0xFEFF

#define HardwareIoRegistersStart 0xFF00
#define HardwareIoRegistersEnd 0xFF7F

#define HighRAMStart 0xFF80
#define HighRAMEnd 0xFFFE

#define InterruptEnableFlag 0xFFFF

//Header Addresses
#define ROMHeaderSize 0x14F

#define NintendoLogoOffset 0x104
#define TitleOffset 0x134
#define CGBFlagOffset 0x143
#define SGBFlagOffset 0x146
#define CartridgeTypeOffset 0x147
#define ROMBankOffset 0x148
#define RAMBankOffset 0x149

#define CGBFlagSupportsCGBFunctions 0x80
#define CGBFlagCGBOnly 0xC0

#define SGBSupportsSGB 0x3

unsigned char ROMBank0[RomBank0Length];
unsigned char ROMBankN[RomBankNLength];
unsigned char VRAM[VRAMLength];
unsigned char ExternalRAM[ExternalRAMLength];
unsigned char InternalRAM0[InternalRAM0Length];
unsigned char InternalRAMN[InternalRAMNLength];
unsigned char OAM[OAMLength];
unsigned char HighRAM[HighRAMLength];

enum MBCTypes {
	MBC_SIMPLE,
	MBC_MBC1,
	MBC_MMM01,
	MBC_MBC2,
	MBC_MBC3,
	MBC_MBC4,
	MBC_MBC5,
	MBC_MBC6,
	MBC_MBC7,
	MBC_UNKNOWN
};
