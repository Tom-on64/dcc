# Tools
CC = cc
LD = cc
AS = cc

# Flags
CFLAGS = -O2 -g -Wall -Wextra -Wpedantic
LDFLAGS =

# Directories
BIN = ./bin
SRC = ./src

# Files etc.
SRCS = $(shell find $(SRC) -name '*.c')
OBJS = $(patsubst $(SRC)/%.c, $(BIN)/%.o, $(SRCS))
TARGET = $(BIN)/dcc

.PHONY: all test clean

all: $(TARGET)
$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

$(BIN)/%.o: $(SRC)/%.c | $(BIN)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN):
	mkdir -p $(BIN)

test: $(TARGET)
	@./tests/tester.sh

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
	rm -rf $(BIN)

