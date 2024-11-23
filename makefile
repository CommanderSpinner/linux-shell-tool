# Compiler and flags
CC = clang
CFLAGS = -Wall -g -Iincludes `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`

# Directories
SRC_DIR = src
INCLUDE_DIR = includes
OBJ_DIR = obj

# Output executable
TARGET = shell_tool

# Find all source files (.c) in the src directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Generate object file names from source files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target: build the executable
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET) $(LDFLAGS) -g

# Rule to compile .c files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean the project: remove generated object files and the executable
clean:
	rm -rf $(OBJ_DIR)

# Phony targets (not actual files)
.PHONY: all clean debug

# Debug target: run the program inside gdb
debug: $(TARGET)
	@echo "Running the program inside gdb..."
	gdb ./$(TARGET)
