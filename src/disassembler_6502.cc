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
        case 0x08:
            cout << pc << ": PHP" << endl; break;
        case 0x12:
            cout << pc << ": JAM" << endl; break;
        case 0x1a:
            cout << pc << ": NOP (undocumented)" << endl; break;
        case 0x4e:
            cout << pc << ": LSR oper(" << setw(2) << setfill('0') << static_cast<int>(code[1])
                                        << setw(2) << setfill('0') << static_cast<int>(code[2]) << ")" << endl;
            opbytes = 3; break;
        case 0x6e:
            cout << pc << ": ROR oper(" << setw(2) << setfill('0') << static_cast<int>(code[1])
                                        << setw(2) << setfill('0') << static_cast<int>(code[2]) << ")" << endl;
            opbytes = 3; break;
        case 0x75:
            cout << pc << ": ADC oper(" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),X" << endl;
            opbytes = 2; break;
        case 0x85:
            cout << pc << ": STA oper(" << setw(2) << setfill('0') << static_cast<int>(code[1]) << ")" << endl;
            opbytes = 2; break;
        case 0xad:
            cout << pc << ": LDA oper(" << setw(2) << setfill('0') << static_cast<int>(code[1])
                                        << setw(2) << setfill('0') << static_cast<int>(code[2]) << ")" << endl;
            opbytes = 3; break;
        case 0xff:
            cout << pc << ": ISC oper(" << setw(2) << setfill('0') << static_cast<int>(code[1]) << "),"
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
