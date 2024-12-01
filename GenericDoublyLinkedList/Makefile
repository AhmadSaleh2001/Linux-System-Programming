# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -I.

# Directories
STUDENT_DIR = student
EMPLOYEE_DIR = employee
LINKEDLIST_DIR = linkedlist

# Object files for the static library
OBJS = $(STUDENT_DIR)/student.o $(EMPLOYEE_DIR)/employee.o $(LINKEDLIST_DIR)/linkedlist.o

# Static library
LIBRARY = libmodules.a

# Target executable
TARGET = app

# Rule to build the target executable
$(TARGET): $(LIBRARY) application.o
	$(CC) -o $(TARGET) application.o -L. -lmodules

# Rule to build the static library
$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

# Rule to compile application.c
application.o: application.c
	$(CC) $(CFLAGS) -c application.c

# Rules to compile the modules
$(STUDENT_DIR)/student.o: $(STUDENT_DIR)/student.c $(STUDENT_DIR)/student.h
	$(CC) $(CFLAGS) -c $(STUDENT_DIR)/student.c -o $(STUDENT_DIR)/student.o

$(EMPLOYEE_DIR)/employee.o: $(EMPLOYEE_DIR)/employee.c $(EMPLOYEE_DIR)/employee.h
	$(CC) $(CFLAGS) -c $(EMPLOYEE_DIR)/employee.c -o $(EMPLOYEE_DIR)/employee.o

$(LINKEDLIST_DIR)/linkedlist.o: $(LINKEDLIST_DIR)/linkedlist.c $(LINKEDLIST_DIR)/linkedlist.h
	$(CC) $(CFLAGS) -c $(LINKEDLIST_DIR)/linkedlist.c -o $(LINKEDLIST_DIR)/linkedlist.o

# Rule to clean up object files, the library, and the executable
clean:
	rm -f $(OBJS) $(LIBRARY) application.o $(TARGET)
