#include <array>        // for array
#include <iomanip>      // for setw
#include <iostream>
#include <memory>       // for smart pointers (unique_ptr, make_unique)
// #include <sstream>      // for ostringstream
// #include <stdexcept>    // for runtime_error

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

        // initialization - TODO test with init and non-init RAM, it shouldn't matter
        State6502() {
            RAM.fill(0);
            P.fill(0);
        }

        // reference for the smart pointer because just passing it by value would result in an error: you can't transfer the ownership of a unique_ptr
        // because they are meant to have a unique ownership
        void emulate6502op(unique_ptr<State6502>& state) {
            const unsigned char *code = &state->RAM[state->PC];
            int opbytes = 1;

            switch (*code) {
                case 0x00:
                    cout << "0x00\n";
                    state->P[flag_B]=1;
                    opbytes=2;
                    break;    // TODO should I put the break flag of the Processor Status to 1?
                /*....*/
                case 0xff: unimplemented(state); break;
                default:
                    ostringstream errorMsg;
                    errorMsg << "emulate_6502op() -> Unexpected opcode: 0x" << setw(2) << setfill('0') << hex << static_cast<int>(code[0]) << dec;
                    throw runtime_error(errorMsg.str());
            }

            state->PC += opbytes;
        }
    
    private:
        
        void unimplemented(unique_ptr<State6502>& state) {
            cerr << "Unimplemented instruction!";
            exit(1);
        }
};
