# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -O0 -Wall -Wextra -Werror -std=c11
INC = -Iinclude -I/usr/include/CUnit

# Library flags
LDFLAGS = -lcunit

# Target executable for the main application
TARGET = bin/GregorianCalendarHtmlGenerator

# Target executable for the test
TEST_TARGET = bin/test_calendar

# Source files for the main application
SRCS = src/main.c src/calendar.c

# Source files for the tests
TEST_SRCS = tests/test_calendar.c

# Object files for the main application
OBJS = $(SRCS:.c=.o)

# Object files for the tests
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Default target
all: $(TARGET)

# Linking for main application
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compilation rule for main application
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Linking for tests
test: $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $(TEST_TARGET) $(LDFLAGS)

# Compilation rule for tests
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Clean up
clean:
	rm -f build/*.o $(TARGET) $(TEST_TARGET)

# Phony targets
.PHONY: all clean test
