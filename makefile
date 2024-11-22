# Compiler and flags
CC := clang
CFLAGS := -Wall -Iincludes `pkg-config --cflags gtk+-3.0`
LDFLAGS := `pkg-config --libs gtk+-3.0`

# Directories
SRC_DIR := src
OBJ_DIR := obj
INCLUDES := includes

# Collect all .c files in the src directory
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Generate corresponding .o files in the obj directory
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Target executable name
TARGET := main_program  # Change this to your preferred executable name

# Default target
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure obj directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets to avoid conflicts with file names
.PHONY: all clean
