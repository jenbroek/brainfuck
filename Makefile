.POSIX:

CFLAGS = -std=c99 -pedantic -Wall -Os
LDFLAGS = -static

brainfuck:

clean:
	rm -f brainfuck

.PHONY: clean
