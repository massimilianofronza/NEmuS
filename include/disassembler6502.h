#include <fstream>
#include <iomanip> // for setw
#include <iostream>
#include <vector>

using namespace std;

// The NES is an 8-bit console. 8 bits -> 2 hex digits
// 2 hex digits make 1 byte
// The first couple of bytes is 454e
// Little-endian machines like the NES store data with the most significant byte as second
// This means that 4e is going to be in position 0, and 45 in position 1 of the pc
int disassemble6502op(const unsigned char *code, const unsigned int &pc);
