/*    
    *codebuffer is a valid pointer to 8080 assembly code    
    pc is the current offset into the code    

    returns the number of bytes of the op    
*/    

#include <fstream>
#include <iostream>
#include <vector>

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

    file.seekg(0, ios::end);            // move the get pointer at the end of the file
    streampos fsize = file.tellg();     // get its position(size fo the file)
    file.seekg(0, ios::beg);            // move it back at the beginning

    cout << "fsize of given input: " << fsize << endl;

    // create a buffer to read the file
    vector<unsigned char> buffer(fsize);
    // unsigned char *buffer = new unsigned char[fsize];  // doesn't automatically manage the memory. Vector is also safer

    // read binary data into the buffer - reinterpret_cast<char*> is basically the "better" C++ version of (char*)
    if (file.read(reinterpret_cast<char*>(buffer.data()), fsize)) {
        cout << "Buffer filled successfully!\n";
    }
    else {
        cerr << "Error while filling the buffer!\n";
    }
    file.close();

    unsigned int pc = 0;

    for (const auto &elem : buffer) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
