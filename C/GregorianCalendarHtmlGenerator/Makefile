# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c17
INC = -Iinclude -I/usr/include/CUnit

# Target executables
TARGET = bin/calendar
TEST_TARGET = bin/test_calendar

# Source files
SRCS = src/main.c src/calendar.c
TEST_SRCS = tests/test_calendar.c

# Object files (automatically generated from SRCS)
OBJS = $(SRCS:src/%.c=build/%.o)
TEST_OBJS = $(TEST_SRCS:tests/%.c=build/%.o) build/calendar.o

# Default target
all: $(TARGET)

# Linking for the main executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Linking for the test executable
$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $(TEST_TARGET) -lcunit

# Compilation rule for source files
build/%.o: src/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Compilation rule for test source files
build/%.o: tests/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Clean up
clean:
	rm -f build/*.o $(TARGET) $(TEST_TARGET)

# Phony targets
.PHONY: all clean test

# Run tests
test: $(TEST_TARGET)
	$(TEST_TARGET)
