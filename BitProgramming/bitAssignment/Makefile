# Define the compiler to use
CC = gcc

# Define the flags to pass to the compiler
CFLAGS = -Wall -Wextra -std=c11

# Define the name of the executable
TARGET = main

# Define the object files to produce
OBJS = main.o bitsop.o

# Default target to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Rule to compile bitsop.c
bitsop.o: bitsop.c
	$(CC) $(CFLAGS) -c bitsop.c

# Clean up the build directory
clean:
	rm -f $(OBJS) $(TARGET)
