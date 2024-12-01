# Define the compiler to use
CC = gcc

# Define the flags to pass to the compiler
CFLAGS = -Wall -Wextra -std=c11

# Define the name of the executable
TARGET = main

# Define the object files to produce
OBJS = main.o bitsop.o bitmap.o

# Default target to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Rule to compile bitsop.c
bitsop.o: bitsop.c
	$(CC) $(CFLAGS) -c bitsop.c

# Rule to compile bitmap.c
bitmap.o: bitsop.c
	$(CC) $(CFLAGS) -c bitmap.c

# Clean up the build directory
clean:
	rm -f $(OBJS) $(TARGET)
