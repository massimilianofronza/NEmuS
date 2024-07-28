#include <iostream>

using namespace std;

// Flags for the Processor Status
#define flag_C 0    // Carry
#define flag_Z 1    // Zero
#define flag_I 2    // Interrupt Disable
#define flag_D 3    // Decimal Mode
#define flag_B 4    // Break Command
#define flag_V 5    // Overflow
#define flag_N 6    // Negative

struct State6502 {
    uint8_t A;          // Accumulator register
    uint8_t X;          // Index Register X
    uint8_t Y;          // Index Register Y
    uint8_t *memory;    // RAM
    uint8_t sp;         // Stack Pointer
    uint16_t pc;        // Program Counter
    bool *P;            // Processor Status
};

void unimplemented(State6502 *state) {
    cerr << "Unimplemented instruction!";
    exit(1);
}

void emulate6502op(State6502 *state) {
    const unsigned char *code = &state->memory[state->pc];
    int opbytes = 1;

    switch (*code) {
        case 0x00: state->P[flag_B]=1; opbytes=2; break;
        /*....*/
        case 0xff: unimplemented(state); break;
    }

    state->pc += opbytes;
}

int main(int argc, char **argv) {
    State6502 *state = new State6502();
    state->P = new bool[7];
    for (uint8_t i=0; i<7; i++) {
        state->P[i] = 0;
    }

    state->A = 42;
    cout << static_cast<int>(state->A) << endl;

    delete state->P;
    delete state;

    return 0;
}