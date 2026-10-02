CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -std=c11
SAN     := -g -fsanitize=address,undefined
INCLUDE := -Iinclude

LIB_SRC := src/string.c
TEST_SRC := src/main.c
BIN     := main

.PHONY: all test clean

all: $(BIN)

# Plain build of the library (mirrors the README's "Building" section).
$(LIB_SRC:.c=.o): $(LIB_SRC)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Build and run the tests with sanitizers enabled.
$(BIN): $(LIB_SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) $(SAN) $(INCLUDE) $(LIB_SRC) $(TEST_SRC) -o $(BIN)

test: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN) $(LIB_SRC:.c=.o)
