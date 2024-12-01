# Define the compiler
CC = gcc

# Define the compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Define the linker flags (if any)
LDFLAGS =

# Define the source files
SRCS = main.c serialize.c

# Define the object files
OBJS = $(SRCS:.c=.o)

# Define the name of the executable
TARGET = myprogram

# The default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean
