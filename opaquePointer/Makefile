# Makefile for compiling and linking list.c and main.c

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Executable name
TARGET = program

# Source files
SRCS = list.c main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
