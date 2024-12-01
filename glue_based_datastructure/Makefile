# Makefile for compiling main.c and glue_list.c into main.exe

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Output executable name
TARGET = main.exe

# Source files
SRC = main.c list/glue_list.c emp/emp.c std/student.c

# Default target
all: $(TARGET)

# Rule to compile source files into main.exe
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
