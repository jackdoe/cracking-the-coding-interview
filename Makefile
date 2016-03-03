CC=gcc
CFLAGS=-I. -std=c99 -g -Wall

SRCS = $(wildcard *.c)

all: pre-build build

pre-build:
	mkdir -p bin/

build: $(SRCS:.c=)

.c:
	$(CC) $(CFLAGS) $< -o bin/$@.x

clean:
	rm -f bin/*.x
