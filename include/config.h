#include <cstdint>      // for uint8_t, uint16_t


// Flags for the Processor Status - constexpr is generally better than #define flag_C 0, which just places a 0 where you write a flag_C
constexpr uint8_t flag_C = 0;    // Carry
constexpr uint8_t flag_Z = 1;    // Zero
constexpr uint8_t flag_I = 2;    // Interrupt Disable
constexpr uint8_t flag_D = 3;    // Decimal Mode
constexpr uint8_t flag_B = 4;    // Break Command
//                flag_???       // bit 5 is unused
constexpr uint8_t flag_V = 6;    // Overflow
constexpr uint8_t flag_N = 7;    // Negative


// Physical hardware dimensions
constexpr uint32_t RAM_SIZE = 65536;    // 64KB for the 6502
