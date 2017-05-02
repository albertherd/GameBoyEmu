#pragma once

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

typedef struct Memory {
	union {
		struct {
			unsigned char RestartInterruptVector[RestartInterruptVectorEnd - RestartInterruptVectorStart];
			unsigned char CartridgeHeaderArea[CartridgeHeaderAreaEnd - CartridgeHeaderAreaStart];
			unsigned char CartridgeROMBank0[CartridgeROMBank0End - CartridgeROMBank0Start];
			unsigned char CartridgeROMSwitchableBank[CartridgeROMSwitchableBankEnd - CartridgeROMSwitchableBankStart];
			unsigned char CharacterRAM[CharacterRAMEnd - CharacterRAMStart];
			unsigned char BGMap1[BGMap1End - BGMap1Start];
			unsigned char BGMap2[BGMap2End - BGMap2Start];
			unsigned char CartridgeRAM[CartridgeHeaderAreaEnd - CartridgeHeaderAreaStart];
			unsigned char InternalRAM[InternalRAMBank0End - InternalRAMBank0Start];
		};
		unsigned char Memory[0xFFFF + 1];
	};
} Memory;

Memory memory;

