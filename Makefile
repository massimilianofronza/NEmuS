# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Wall
# About CXXFLAGS:
# -Wextra for additional warnings
# -g if you want to debug with gdb, compile and run gdb ./my_program

# Source files
SRC_MAIN = src/main.cc
SRC_MAIN_DISASSEMBLER = src/mainDisassembler.cc

SRC_DISASSEMBLER = src/disassembler6502.cc
SRC_STATE = src/State6502.cc

# Object files
OBJ_MAIN = $(SRC_MAIN:.cc=.o)
OBJ_MAIN_DISASSEMBLER = $(SRC_MAIN_DISASSEMBLER:.cc=.o)

OBJ_DISASSEMBLER = $(SRC_DISASSEMBLER:.cc=.o)
OBJ_STATE = $(SRC_STATE:.cc=.o)

# Executable names
TARGET_MAIN = run_main
TARGET_DISASSEMBLER = run_disassembler

# Default target
all: $(TARGET_MAIN) $(TARGET_DISASSEMBLER)

# Build main target
$(TARGET_MAIN): $(OBJ_MAIN) $(OBJ_DISASSEMBLER) $(OBJ_STATE)
	$(CXX) $(OBJ_MAIN) $(OBJ_DISASSEMBLER) $(OBJ_STATE) -o $(TARGET_MAIN)

# Build disassembler target
$(TARGET_DISASSEMBLER): $(OBJ_MAIN_DISASSEMBLER) $(OBJ_DISASSEMBLER)
	$(CXX) $(OBJ_MAIN_DISASSEMBLER) $(OBJ_DISASSEMBLER) -o $(TARGET_DISASSEMBLER)

# Compile each .cc to .o
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ_MAIN) $(OBJ_MAIN_DISASSEMBLER) $(OBJ_DISASSEMBLER) $(OBJ_STATE) $(TARGET_MAIN) $(TARGET_DISASSEMBLER)

# Clean up and re-compile
rebuild: clean all
