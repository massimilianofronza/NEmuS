#include <array>        // for array
#include "config.h"

using namespace std;

// struct members are public by default, unlike classes where they are private
class State6502 {
    public:
        uint8_t A;                      // Accumulator register
        uint8_t X;                      // Index Register X
        uint8_t Y;                      // Index Register Y
        array<uint8_t, RAM_SIZE> RAM;   // Random Access Memory // TODO test speed between this, a smart pointer, a vector and a basic RAM[size] object
        uint8_t SP;                     // Stack Pointer, memory locations $0100-$01FF, 256-511
        uint16_t PC;                    // Program Counter
        array<bool, 8> P;               // Processor Status
};
