# Makefile for 8085 Assembler

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = 

# Target executable
TARGET = assembler

# Source files
SOURCES = main.c register_utils.c instruction_ops.c utils.c instruction_handlers.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Header files
HEADERS = assembler.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Clean everything including backup files
distclean: clean
	rm -f *~ *.bak main_original.c

# Install (optional)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Uninstall (optional)
uninstall:
	rm -f /usr/local/bin/$(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CFLAGS += -DDEBUG -O0
debug: $(TARGET)

# Release build
release: CFLAGS += -O2
release: $(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all       - Build the assembler (default)"
	@echo "  clean     - Remove object files and executable"
	@echo "  distclean - Remove all generated files"
	@echo "  run       - Build and run the assembler"
	@echo "  debug     - Build with debug flags"
	@echo "  release   - Build with optimization flags"
	@echo "  install   - Install to /usr/local/bin"
	@echo "  uninstall - Remove from /usr/local/bin"
	@echo "  help      - Show this help message"

# Declare phony targets
.PHONY: all clean distclean install uninstall run debug release help
