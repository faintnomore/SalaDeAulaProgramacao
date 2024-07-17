# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Iinclude -Wall -Wextra -Werror -std=c11

# Target executable
TARGET = outputs/GregorianCalendarHtmlGenerator

# Source files
SRCS = src/main.c src/calendar.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
