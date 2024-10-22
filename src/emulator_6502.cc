#include <iomanip> // for std::setw
#include <iostream>
#include <cstdint>
#include <sstream> // for ostringstream

using namespace std;

// Flags for the Processor Status
#define flag_C 0    // Carry
#define flag_Z 1    // Zero
#define flag_I 2    // Interrupt Disable
#define flag_D 3    // Decimal Mode
#define flag_B 4    // Break Command
//      flag_???    // bit 5 is unused
#define flag_V 6    // Overflow
#define flag_N 7    // Negative

struct State6502 {
    uint8_t A;          // Accumulator register
    uint8_t X;          // Index Register X
    uint8_t Y;          // Index Register Y
    uint8_t *RAM;       // Random Access Memory
    uint8_t SP;         // Stack Pointer, memory locations $0100-$01FF
    uint16_t PC;        // Program Counter
    bool *P;            // Processor Status
};

void unimplemented(State6502 *state) {
    cerr << "Unimplemented instruction!";
    exit(1);
}

void emulate6502op(State6502 *state) {
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
            errorMsg << "emulate_6502op() -> Unexpected opcode: 0x" << setw(2) << setfill('0') << hex << static_cast<int>(code[0]) << dec << endl;
            throw runtime_error(errorMsg.str());
    }

    state->PC += opbytes;
}

int main(int argc, char **argv) {

    // initialization
    State6502 *state = new State6502();
    state->RAM = new uint8_t[10];
    state->P = new bool[7];
    for (uint8_t i=0; i<7; i++) {
        state->P[i] = 0;
    }

    // initialize a demo CPU State
    state->RAM[0] = 0x00;
    state->RAM[1] = 0xff;
    state->RAM[2] = 0x01;
    state->PC = 2;

    emulate6502op(state);

    state->A = 42;
    cout << static_cast<int>(state->A) << endl;

    delete[] state->P;
    delete[] state->RAM;
    delete state;

    return 0;
}