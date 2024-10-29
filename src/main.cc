#include "State6502.h"

using namespace std;


int main(int argc, char **argv) {

    unique_ptr<State6502> state = make_unique<State6502>();
    
    // initialize a demo CPU State
    state->RAM[0] = 0x00;
    state->RAM[1] = 0xff;
    state->RAM[2] = 0x01;
    state->PC = 0;

    try {
        state->emulate6502op(state);
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    state->A = 42;
    cout << static_cast<int>(state->A) << endl;

    return 0;
}