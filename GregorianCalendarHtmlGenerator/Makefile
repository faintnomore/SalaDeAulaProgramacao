# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -O0 -Wall -Wextra -Werror -std=c11
INC = -Iinclude

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
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
