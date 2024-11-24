#include <disassembler6502.h>

int disassemble6502op(const unsigned char *code, const unsigned int &pc) {
    int opbytes = 1;

    // The 6502 has 151 valid opcodes out of a possible 256(8 bits/2 hex per code)
    // The rest are undocumented opcodes
    switch (*code) {
        case 0x00:
            cout << pc << ": BRK" << endl; break;
        case 0x01:
            cout << pc << ": ORA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),X" << endl;
            opbytes = 2; break;
        case 0x02:
            cout << pc << ": JAM" << endl; break;
        case 0x03:
            cout << pc << ": SLO (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0x04:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x05:
            cout << pc << ": ORA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x06:
            cout << pc << ": ASL " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x07:
            cout << pc << ": SLO " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x08:
            cout << pc << ": PHP" << endl; break;
        case 0x09:
            cout << pc << ": ORA #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x0a:
            cout << pc << ": ASL A" << endl; break;
        case 0x0b:
            cout << pc << ": ANC #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x0c:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                                  << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x0d:
            cout << pc << ": ORA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x0e:
            cout << pc << ": ASL " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x0f:
            cout << pc << ": SLO " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x10:
            cout << pc << ": BPL " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x11:
            cout << pc << ": ORA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x12:
            cout << pc << ": JAM" << endl; break;
        case 0x13:
            cout << pc << ": SLO (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x14:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x15:
            cout << pc << ": ORA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x16:
            cout << pc << ": ASL " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x17:
            cout << pc << ": SLO " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x18:
            cout << pc << ": CLC" << endl; break;
        case 0x19:
            cout << pc << ": ORA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x1a:
            cout << pc << ": NOP (undocumented)" << endl; break;
        case 0x1b:
            cout << pc << ": SLO " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x1c:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                                  << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x1d:
            cout << pc << ": ORA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x1e:
            cout << pc << ": ASL " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x1f:
            cout << pc << ": SLO " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x20:
            cout << pc << ": JSR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x21:
            cout << pc << ": AND (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),X" << endl;
            opbytes = 2; break;
        case 0x22:
            cout << pc << ": JAM" << endl; break;
        case 0x23:
            cout << pc << ": RLA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),X" << endl;
            opbytes = 2; break;
        case 0x24:
            cout << pc << ": BIT " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x25:
            cout << pc << ": AND " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x26:
            cout << pc << ": ROL " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x27:
            cout << pc << ": RLA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x28:
            cout << pc << ": PLP" << endl; break;
        case 0x29:
            cout << pc << ": AND #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x2a:
            cout << pc << ": ROL A" << endl; break;
        case 0x2b:
            cout << pc << ": ANC #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x2c:
            cout << pc << ": BIT " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x2d:
            cout << pc << ": AND " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x2e:
            cout << pc << ": ROL " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x2f:
            cout << pc << ": RLA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x30:
            cout << pc << ": BMI " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x31:
            cout << pc << ": AND (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x32:
            cout << pc << ": JAM" << endl; break;
        case 0x33:
            cout << pc << ": RLA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x34:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x35:
            cout << pc << ": AND " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x36:
            cout << pc << ": ROL " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x37:
            cout << pc << ": RLA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x38:
            cout << pc << ": SEC" << endl; break;
        case 0x39:
            cout << pc << ": AND " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x3a:
            cout << pc << ": NOP (undocumented)" << endl; break;
        case 0x3b:
            cout << pc << ": RLA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x3c:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                                  << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x3d:
            cout << pc << ": AND " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x3e:
            cout << pc << ": ROL " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x3f:
            cout << pc << ": RLA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x40:
            cout << pc << ": RTI" << endl; break;
        case 0x41:
            cout << pc << ": EOR (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0x42:
            cout << pc << ": JAM" << endl; break;
        case 0x43:
            cout << pc << ": SRE (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0x44:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x45:
            cout << pc << ": EOR " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x46:
            cout << pc << ": LSR " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x47:
            cout << pc << ": SRE " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x48:
            cout << pc << ": PHA" << endl; break;
        case 0x49:
            cout << pc << ": EOR #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x4a:
            cout << pc << ": LSR A" << endl; break;
        case 0x4b:
            cout << pc << ": ALR #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x4c:
            cout << pc << ": JMP " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x4d:
            cout << pc << ": EOR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x4e:
            cout << pc << ": LSR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x4f:
            cout << pc << ": SRE " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x50:
            cout << pc << ": BVC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x51:
            cout << pc << ": EOR (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x52:
            cout << pc << ": JAM" << endl; break;
        case 0x53:
            cout << pc << ": SRE (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x54:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x55:
            cout << pc << ": EOR " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x56:
            cout << pc << ": LSR " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x57:
            cout << pc << ": SRE " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x58:
            cout << pc << ": CLI" << endl; break;
        case 0x59:
            cout << pc << ": EOR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x5a:
            cout << pc << ": NOP (undocumented)" << endl; break;
        case 0x5b:
            cout << pc << ": SRE " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x5c:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                                  << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x5d:
            cout << pc << ": EOR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x5e:
            cout << pc << ": LSR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x5f:
            cout << pc << ": SRE " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x60:
            cout << pc << ": RTS" << endl; break;
        case 0x61:
            cout << pc << ": ADC (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),X" << endl;
            opbytes = 2; break;
        case 0x62:
            cout << pc << ": JAM" << endl; break;
        case 0x63:
            cout << pc << ": RRA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0x64:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x65:
            cout << pc << ": ADC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x66:
            cout << pc << ": ROR " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x67:
            cout << pc << ": RRA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x68:
            cout << pc << ": PLA" << endl; break;
        case 0x69:
            cout << pc << ": ADC #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x6a:
            cout << pc << ": ROR A" << endl; break;
        case 0x6b:
            cout << pc << ": ARR #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x6c:
            cout << pc << ": JMP (" << setw(2) << setfill('0') << static_cast<int>(code[1])
                                    << setw(2) << setfill('0') << static_cast<int>(code[2]) << ")" << endl;
            opbytes = 3; break;
        case 0x6d:
            cout << pc << ": ADC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x6e:
            cout << pc << ": ROR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x6f:
            cout << pc << ": RRA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x70:
            cout << pc << ": BVS " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x71:
            cout << pc << ": ADC (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x72:
            cout << pc << ": JAM" << endl; break;
        case 0x73:
            cout << pc << ": RRA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x74:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x75:
            cout << pc << ": ADC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x76:
            cout << pc << ": ROR " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x77:
            cout << pc << ": RRA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x78:
            cout << pc << ": SEI" << endl; break;
        case 0x79:
            cout << pc << ": ADC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x7a:
            cout << pc << ": NOP (undocumented)" << endl; break;
        case 0x7b:
            cout << pc << ": RRA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x7c:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                                  << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x7d:
            cout << pc << ": ADC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x7e:
            cout << pc << ": ROR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x7f:
            cout << pc << ": RRA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x80:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x81:
            cout << pc << ": STA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),X" << endl;
            opbytes = 2; break;
        case 0x82:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x83:
            cout << pc << ": SAX (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0x84:
            cout << pc << ": STY " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x85:
            cout << pc << ": STA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x86:
            cout << pc << ": STX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x87:
            cout << pc << ": SAX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x88:
            cout << pc << ": DEY" << endl; break;
        case 0x89:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x8a:
            cout << pc << ": TXA" << endl; break;
        case 0x8b:
            cout << pc << ": (highly unstable) ANE #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x8c:
            cout << pc << ": STY " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x8d:
            cout << pc << ": STA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x8e:
            cout << pc << ": STX " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x8f:
            cout << pc << ": SAX " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x90:
            cout << pc << ": BCC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x91:
            cout << pc << ": STA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x92:
            cout << pc << ": JAM" << endl; break;
        case 0x93:
            cout << pc << ": (unstable) SHA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x94:
            cout << pc << ": STY " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x95:
            cout << pc << ": STA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x96:
            cout << pc << ": STX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",Y" << endl;
            opbytes = 2; break;
        case 0x97:
            cout << pc << ": SAX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",Y" << endl;
            opbytes = 2; break;
        case 0x98:
            cout << pc << ": TYA" << endl; break;
        case 0x99:
            cout << pc << ": STA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x9a:
            cout << pc << ": TXS" << endl; break;
        case 0x9b:
            cout << pc << ": (unstable) TAS " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                              << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x9c:
            cout << pc << ": (unstable) SHY " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                              << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x9d:
            cout << pc << ": STA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x9e:
            cout << pc << ": (unstable) SHX " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                              << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x9f:
            cout << pc << ": SHA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0xa0:
            cout << pc << ": LDY #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xa1:
            cout << pc << ": LDA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0xa2:
            cout << pc << ": LDX #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xa3:
            cout << pc << ": LAX (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0xa4:
            cout << pc << ": LDY " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xa5:
            cout << pc << ": LDA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xa6:
            cout << pc << ": LDX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xa7:
            cout << pc << ": LAX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xa8:
            cout << pc << ": TAY" << endl; break;
        case 0xa9:
            cout << pc << ": LDA #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xaa:
            cout << pc << ": TAX" << endl; break;
        case 0xab:
            cout << pc << ": (highly unstable) LXA #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xac:
            cout << pc << ": LDY " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xad:
            cout << pc << ": LDA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xae:
            cout << pc << ": LDX " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xaf:
            cout << pc << ": LAX " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xb0:
            cout << pc << ": BCS " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xb1:
            cout << pc << ": LDA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0xb2:
            cout << pc << ": JAM" << endl; break;
        case 0xb3:
            cout << pc << ": LAX (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0xb4:
            cout << pc << ": LDY " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xb5:
            cout << pc << ": LDA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xb6:
            cout << pc << ": LDX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",Y" << endl;
            opbytes = 2; break;
        case 0xb7:
            cout << pc << ": LAX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",Y" << endl;
            opbytes = 2; break;
        case 0xb8:
            cout << pc << ": CLV" << endl; break;
        case 0xb9:
            cout << pc << ": LDA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0xba:
            cout << pc << ": TSX" << endl; break;
        case 0xbb:
            cout << pc << ": LAS " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0xbc:
            cout << pc << ": LDY " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0xbd:
            cout << pc << ": LDA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0xbe:
            cout << pc << ": LDX " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0xbf:
            cout << pc << ": LAX " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0xc0:
            cout << pc << ": CPY #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xc1:
            cout << pc << ": CMP (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0xc2:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xc3:
            cout << pc << ": DCP (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0xc4:
            cout << pc << ": CPY " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xc5:
            cout << pc << ": CMP " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xc6:
            cout << pc << ": DEC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xc7:
            cout << pc << ": DCP " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xc8:
            cout << pc << ": INY" << endl; break;
        case 0xc9:
            cout << pc << ": CMP #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xca:
            cout << pc << ": DEX" << endl; break;
        case 0xcb:
            cout << pc << ": SBX #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xcc:
            cout << pc << ": CPY " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xcd:
            cout << pc << ": CMP " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xce:
            cout << pc << ": DEC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xcf:
            cout << pc << ": DCP " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xd0:
            cout << pc << ": BNE " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xd1:
            cout << pc << ": CMP (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0xd2:
            cout << pc << ": JAM" << endl; break;
        case 0xd3:
            cout << pc << ": DCP (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0xd4:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xd5:
            cout << pc << ": CMP " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xd6:
            cout << pc << ": DEC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xd7:
            cout << pc << ": DCP " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xd8:
            cout << pc << ": CLD" << endl; break;
        case 0xd9:
            cout << pc << ": CMP " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0xda:
            cout << pc << ": NOP (undocumented)" << endl; break;
        case 0xdb:
            cout << pc << ": DCP " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0xdc:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                                  << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xdd:
            cout << pc << ": CMP " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0xde:
            cout << pc << ": DEC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0xdf:
            cout << pc << ": DCP " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0xe0:
            cout << pc << ": CPX #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xe1:
            cout << pc << ": SBC (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0xe2:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xe3:
            cout << pc << ": ISC (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X)" << endl;
            opbytes = 2; break;
        case 0xe4:
            cout << pc << ": CPX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xe5:
            cout << pc << ": SBC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xe6:
            cout << pc << ": INC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xe7:
            cout << pc << ": ISC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xe8:
            cout << pc << ": INX" << endl; break;
        case 0xe9:
            cout << pc << ": SBC #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xea:
            cout << pc << ": NOP (undocumented)" << endl; break;
        case 0xeb:
            cout << pc << ": USBC #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xec:
            cout << pc << ": CPX " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xed:
            cout << pc << ": SBC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xee:
            cout << pc << ": INC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xef:
            cout << pc << ": ISC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xf0:
            cout << pc << ": BEQ " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xf1:
            cout << pc << ": SBC (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0xf2:
            cout << pc << ": JAM" << endl; break;
        case 0xf3:
            cout << pc << ": ISC (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0xf4:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xf5:
            cout << pc << ": SBC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xf6:
            cout << pc << ": INC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xf7:
            cout << pc << ": ISC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xf8:
            cout << pc << ": SED" << endl; break;
        case 0xf9:
            cout << pc << ": SBC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0xfa:
            cout << pc << ": NOP (undocumented)" << endl; break;
        case 0xfb:
            cout << pc << ": ISC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0xfc:
            cout << pc << ": NOP (undocumented) " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                                  << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xfd:
            cout << pc << ": SBC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0xfe:
            cout << pc << ": INC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0xff:
            cout << pc << ": ISC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ","
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        default:
            cout << pc << ": todo: " << setw(2) << setfill('0') << static_cast<int>(*code) << endl; return 131088; break;
    }

    return opbytes;
}
