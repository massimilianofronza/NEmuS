#include <iomanip>      // for setw
#include <iostream>
#include <cstdint>      // for uint8_t, uint16_t
#include <memory>       // for smart pointers (unique_ptr, make_unique)
#include <sstream>      // for ostringstream
#include <stdexcept>    // for runtime_error
#include "State6502.h"

using namespace std;


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

    // initialization - TODO test with init and non-init RAM, it shouldn't matter
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