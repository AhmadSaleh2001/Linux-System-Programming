# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRCS = evaluation.c diff.c dll.c

# Header files
HEADERS = dll.h

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable (Windows .exe format)
TARGET = evaluation.exe

# Default rule
all: $(TARGET)

# Rule to build the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program (if running in an environment that supports .exe)
run: $(TARGET)
	./$(TARGET)
