# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -O0 -S -Iinclude -Wall -Wextra -Werror -std=c11

# Target executable
TARGET = outputs/GregorianCalendarHtmlGenerator

# Source files
SRCS = src/main.c src/calendar.c

# Object files (automatically generated from SRCS)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compilation rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(SRCS:.c=.o)  # Remove .o files generated from source files

# Phony targets
.PHONY: all clean
