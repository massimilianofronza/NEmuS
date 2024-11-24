#include <State6502.h>
#include <disassembler6502.h>

State6502::State6502() {
    this->RAM.fill(0);
    this->P.fill(0);
}

void State6502::emulate6502op() {
    const unsigned char *code = &this->RAM[this->PC];
    int opbytes = 1;

    switch (*code) {
        case 0x00:
            disassemble6502op(code, this->PC);
            this->P[flag_B]=1;
            opbytes=2;
            break;    // TODO should I put the break flag of the Processor Status to 1?
        /*....*/
        default:
            ostringstream errorMsg;
            errorMsg << "emulate6502op() -> Unexpected opcode: 0x" << setw(2) << setfill('0') << hex << static_cast<int>(code[0]) << dec;
            throw runtime_error(errorMsg.str());
    }

    this->PC += opbytes;
}
