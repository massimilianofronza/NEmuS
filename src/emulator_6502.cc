#include <iostream>

using namespace std;

struct State6502 {
    uint8_t A;      // Accumulator register
    uint8_t X;      // Index Register X
    uint8_t Y;      // Index Register Y
    uint8_t P;      // Processor Status: [NV BDIZC], see doc
    uint8_t SP;     // Stack Pointer
    uint16_t PC;    // Program Counter
};

int emulate6502op(State6502 *state) {
    return 0;
}

int main(int argc, char **argv) {
    State6502 *state = new State6502();

    state->A = 42;
    cout << static_cast<int>(state->A) << endl;

    delete state;
    return 0;
}