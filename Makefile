# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Wall
# About CXXFLAGS:
# -Wextra for additional warnings
# -g if you want to debug with gdb, compile and run gdb ./my_program

# Files with a main() definition
SRC_MAIN = src/main.cc
SRC_DISASSEMBLER = src/disassembler_6502.cc

# Object files
OBJ_MAIN = $(SRC_MAIN:.cc=.o)
OBJ_DISASSEMBLER = $(SRC_DISASSEMBLER:.cc=.o)

# Executable names
TARGET_MAIN = run_main
TARGET_DISASSEMBLER = run_disassembler

# Default target
all: $(TARGET_MAIN) $(TARGET_DISASSEMBLER)

# Build main target
$(TARGET_MAIN): $(OBJ_MAIN)
	$(CXX) $(OBJ_MAIN) -o $(TARGET_MAIN)

# Build disassembler target
$(TARGET_DISASSEMBLER): $(OBJ_DISASSEMBLER)
	$(CXX) $(OBJ_DISASSEMBLER) -o $(TARGET_DISASSEMBLER)

# Compile each .cc to .o
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ_MAIN) $(OBJ_DISASSEMBLER) $(TARGET_MAIN) $(TARGET_DISASSEMBLER)
