CC = gcc
CFLAGS = -Wall -Iinclude

SRC = $(wildcard src/*.c)
TESTS = $(wildcard tests/*.c)

all: build run_tests

build: $(SRC)
	$(CC) $(CFLAGS) -o main $(SRC)

run_tests: build $(TESTS)
	$(CC) $(CFLAGS) -o run_tests $(TESTS) $(SRC)
	./run_tests

clean:
	rm -f main run_tests
