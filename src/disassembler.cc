/*    
    *codebuffer is a valid pointer to 8080 assembly code    
    pc is the current offset into the code    

    returns the number of bytes of the op    
*/    

#include <fstream>
#include <iostream>

using namespace std;

int disassemble(unsigned char *codebuffer, int pc) {
    unsigned char *code = &codebuffer[pc];
    int opbytes = 1;
    cout << "%04x " << pc << endl;

    switch (*code) {
        case 0x00: printf("NOP"); break;    
        case 0x01: printf("LXI    B,#$%02x%02x", code[2], code[1]); opbytes=3; break;    
    }

    cout << endl;
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
    
    // Get the file size and read it into a memory buffer
    file.seekg(0, ios::end);
    streampos fsize = file.tellg();
    file.seekg(0, ios::beg);

    unsigned char *buffer = new unsigned char[fsize];
    // vector<unsigned char> buffer(fsize); // TODO To automatically manage the memory and provide additional safety

    cout << "fsize of given input: " << fsize << endl;

    return 0;
}
