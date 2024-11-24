#include <array>        // for array
#include <iomanip>      // for setw
#include <iostream>
// #include <sstream>      // for ostringstream
// #include <stdexcept>    // for runtime_error

#include "config.h"

using namespace std;

// Learning note: struct members are public by default, unlike classes where they are private
class State6502 {
    
    public:
        uint8_t A;                      // Accumulator register, stores the results of arithmetic and logic operations
        uint8_t X;                      // Index Register X, counter/offset, can affect the SP
        uint8_t Y;                      // Index Register Y, counter/offset
        array<uint8_t, RAM_SIZE> RAM;   // Random Access Memory // TODO test speed between this, a smart pointer, a vector and a basic RAM[size] object
        uint8_t SP;                     // Stack Pointer, memory locations $0100-$01FF, 256-511
        uint16_t PC;                    // Program Counter
        array<bool, 8> P;               // Processor Status

        // initialization - TODO test with init and non-init RAM, it shouldn't matter
        State6502();

        // Learning note: I had a (unique_ptr<State6502>& state) before: passing the smart pointer by reference and not simply by
        // value was correct, because you can't just transfer the ownership of a unique_ptr, they are meant to have a unique owner
        // A shared_ptr would have been ok with a pass by value
        void emulate6502op();
};
