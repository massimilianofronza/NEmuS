#include <fstream>
#include <iomanip> // for std::setw
#include <iostream>
#include <vector>

using namespace std;

    // The NES is an 8-bit console. 8 bits -> 2 hex digits
    // 2 hex digits make 1 byte
    // The first couple of bytes is 454e
    // Little-endian machines like the NES store data with the most significant byte as second
    // This means that 4e is going to be in position 0, and 45 in position 1 of the pc
int disassemble6502op(const unsigned char *buffer, const unsigned int pc) {
    const unsigned char *code = &buffer[pc];
    int opbytes = 1;

    // The 6502 has 151 valid opcodes out of a possible 256(8 bits/2 hex per code)
    // The rest are undocumented opcodes
    switch (*code) {
        case 0x00:
            cout << pc << ": BRK" << endl; break;
        case 0x01:
            cout << pc << ": ORA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),X" << endl;
            opbytes = 2; break;
        case 0x06:
            cout << pc << ": ASL " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x08:
            cout << pc << ": PHP" << endl; break;
        case 0x0e:
            cout << pc << ": ASL " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x10:
            cout << pc << ": BPL " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x11:
            cout << pc << ": ORA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x12:
            cout << pc << ": JAM" << endl; break;
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
            cout << pc << ": NOP (undocumented)" << endl;
            opbytes = 3; break;
        case 0x1d:
            cout << pc << ": ORA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x1e:
            cout << pc << ": ASL " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x20:
            cout << pc << ": JSR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x22:
            cout << pc << ": JAM" << endl; break;
        case 0x23:
            cout << pc << ": RLA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),X" << endl;
            opbytes = 2; break;
        case 0x24:
            cout << pc << ": BIT " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x27:
            cout << pc << ": RLA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x28:
            cout << pc << ": PLP" << endl; break;
        case 0x2a:
            cout << pc << ": ROL A" << endl; break;
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
        case 0x32:
            cout << pc << ": JAM" << endl; break;
        case 0x34:
            cout << pc << ": NOP (undocumented)" << endl;
            opbytes = 2; break;
        case 0x36:
            cout << pc << ": ROL " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x38:
            cout << pc << ": SEC" << endl; break;
        case 0x39:
            cout << pc << ": AND " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x3b:
            cout << pc << ": RLA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x3c:
            cout << pc << ": NOP (undocumented)" << endl;
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
        case 0x44:
            cout << pc << ": NOP (undocumented)" << endl;
            opbytes = 2; break;
        case 0x45:
            cout << pc << ": EOR " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x46:
            cout << pc << ": LSR " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x4c:
            cout << pc << ": JMP " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x4e:
            cout << pc << ": LSR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x50:
            cout << pc << ": BVC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x53:
            cout << pc << ": SRE (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0x61:
            cout << pc << ": ADC (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),X" << endl;
            opbytes = 2; break;
        case 0x6b:
            cout << pc << ": ARR #" << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x6c:
            cout << pc << ": JMP (" << setw(2) << setfill('0') << static_cast<int>(code[1])
                                    << setw(2) << setfill('0') << static_cast<int>(code[2]) << ")" << endl;
            opbytes = 3; break;
        case 0x6e:
            cout << pc << ": ROR " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x75:
            cout << pc << ": ADC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x78:
            cout << pc << ": SEI" << endl; break;
        case 0x7b:
            cout << pc << ": RRA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0x7c:
            cout << pc << ": NOP " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0x7d:
            cout << pc << ": ADC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x80:
            cout << pc << ": NOP " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0x81:
            cout << pc << ": STA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),X" << endl;
            opbytes = 2; break;
        case 0x82:
            cout << pc << ": NOP (undocumented)" << endl;
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
        case 0x87:
            cout << pc << ": SAX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
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
        case 0x95:
            cout << pc << ": STA " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0x9d:
            cout << pc << ": STA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0x9f:
            cout << pc << ": SHA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",Y" << endl;
            opbytes = 3; break;
        case 0xa7:
            cout << pc << ": LAX " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xa8:
            cout << pc << ": TAY" << endl; break;
        case 0xad:
            cout << pc << ": LDA " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xb1:
            cout << pc << ": LDA (" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),Y" << endl;
            opbytes = 2; break;
        case 0xb4:
            cout << pc << ": LDY " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xc5:
            cout << pc << ": CMP " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xc8:
            cout << pc << ": INY" << endl; break;
        case 0xd0:
            cout << pc << ": BNE " << setw(2) << setfill('0') << static_cast<int>(code[1]) << endl;
            opbytes = 2; break;
        case 0xd2:
            cout << pc << ": JAM" << endl; break;
        case 0xd5:
            cout << pc << ": CMP " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xd8:
            cout << pc << ": CLD" << endl; break;
        case 0xde:
            cout << pc << ": DEC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << ",X" << endl;
            opbytes = 3; break;
        case 0xed:
            cout << pc << ": SBC " << setw(2) << setfill('0') << static_cast<int>(code[1])
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        case 0xf5:
            cout << pc << ": SBC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ",X" << endl;
            opbytes = 2; break;
        case 0xff:
            cout << pc << ": ISC " << setw(2) << setfill('0') << static_cast<int>(code[1]) << ","
                                   << setw(2) << setfill('0') << static_cast<int>(code[2]) << endl;
            opbytes = 3; break;
        default:
            cout << pc << ": todo: " << setw(2) << setfill('0') << static_cast<int>(*code) << endl; return 131088; break;
    }

    return opbytes;
}

int main (int argc, char **argv) {
    
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " input.txt\n";
        return 1;
    }

    ifstream file(argv[1], ios::binary);

    if (!file.is_open()) {
        cerr << "Error opening the file.\n";
        return 1;
    }

    // get size of input file
    file.seekg(0, ios::end);            // move the get pointer at the end of the file
    streampos fsize = file.tellg();     // get its position(size fo the file)
    file.seekg(0, ios::beg);            // move it back at the beginning
    cout << "fsize of given input: " << fsize << " bytes" << endl;
    
    // create a buffer to read the file
    vector<unsigned char> buffer(fsize);
    // unsigned char *buffer = new unsigned char[fsize];  // doesn't automatically manage the memory. Vector is also safer
    
    // read binary data into the buffer - reinterpret_cast<char*> is for low-level memory operations that intepret memory contents as a dfferent type
    if (file.read(reinterpret_cast<char*>(buffer.data()), fsize)) {
        cout << "Buffer filled successfully!\n";
    }
    else {
        cerr << "Error while filling the buffer!\n";
    }
    file.close();
    
    unsigned char *this_buffer = buffer.data();
    unsigned int pc = 0;

    // switch to hexadecimals for all the following outputs
    cout << hex;

    while (pc < fsize) {
        pc += disassemble6502op(this_buffer, pc);
        /*if (pc>10) {
            return 0;
        }*/
    }

    // switch to decimals for all the following outputs
    cout << dec;

    /*
    for (const auto &elem : buffer) {
        cout << elem << " ";
    }
    cout << endl;*/

    return 0;
}
