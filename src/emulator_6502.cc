#include <array>        // for array
#include <iomanip>      // for setw
#include <iostream>
#include <cstdint>      // for uint8_t, uint16_t
#include <memory>       // for smart pointers (unique_ptr, make_unique)
#include <sstream>      // for ostringstream
#include <stdexcept>    // for runtime_error

using namespace std;


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


struct State6502 {
    uint8_t A;                      // Accumulator register
    uint8_t X;                      // Index Register X
    uint8_t Y;                      // Index Register Y
    array<uint8_t, RAM_SIZE> RAM;   // Random Access Memory // TODO test speed between this, a smart pointer, a vector and a basic RAM[size] object
    uint8_t SP;                     // Stack Pointer, memory locations $0100-$01FF
    uint16_t PC;                    // Program Counter
    array<bool, 8> P;               // Processor Status
};

void unimplemented(unique_ptr<State6502>& state) {
    cerr << "Unimplemented instruction!";
    exit(1);
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

int main(int argc, char **argv) {

    // initialization
    unique_ptr<State6502> state = make_unique<State6502>();
    state->RAM.fill(0);
    state->P.fill(0);

    // initialize a demo CPU State
    state->RAM[0] = 0x00;
    state->RAM[1] = 0xff;
    state->RAM[2] = 0x01;
    state->PC = 2;

    try {
        emulate6502op(state);
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    state->A = 42;
    cout << static_cast<int>(state->A) << endl;

    return 0;
}