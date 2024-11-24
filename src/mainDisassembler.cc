#include <disassembler6502.h>

int main (int argc, char **argv) {
    
    if (argc != 4) {
        cerr << "\nUsage: " << argv[0] << " file start end\n\n";
        cerr << "\tfile  : input file to be disassembled\n";
        cerr << "\tstart : set program counter to start reading from this position\n";
        cerr << "\tend   : disassemble until this position in the file, set to -1 to read the entire file\n\n";
        return 1;
    }

    // read arguments
    ifstream file(argv[1], ios::binary);
    unsigned int start_pos = stoi(argv[2]);
    int end_pos = stoi(argv[3]);
    
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
    
    // set buffer and start/ending
    unsigned char *this_buffer = buffer.data();
    unsigned int pc = start_pos;
    fsize = (end_pos == -1 ? fsize : static_cast<streampos>(end_pos));

    // switch to hexadecimals for all the following outputs
    cout << hex;

    while (pc < fsize) {
        pc += disassemble6502op(&this_buffer[pc], pc);
        /*if (pc>10) {
            return 0;
        }*/
    }

    // switch to decimals for all the following outputs
    cout << dec;

    /*for (const auto &elem : buffer) {
        cout << elem << " ";
    }
    cout << endl;*/

    return 0;
}
