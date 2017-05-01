#define ROMHeaderSize 0x180
#define ROMNameMaxLength 16
#define ROMNameHeaderOffset 0x134
#define CGBFlag 0x143

BOOL ErrorAndCloseHeaderHandle(HANDLE hROM, const char* message);