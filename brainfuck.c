#include <stdio.h>
#include <stdlib.h>

#define JUMP(C1, C2, O) for (; *i == C1 ? ++b : *i == C2 ? --b : 1; (i)O)

int
main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s INPUT\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (char b = 0, *i = argv[1], *p = (char[30000]){0}; *i; i++) {
		switch (*i) {
		case '>': p++;                         break;
		case '<': p--;                         break;
		case '+': (*p)++;                      break;
		case '-': (*p)--;                      break;
		case '.': putchar(*p);                 break;
		case ',': *p = getchar();              break;
		case '[': if (!*p) JUMP('[', ']', ++); break;
		case ']': if (*p) JUMP(']', '[', --);  break;
		}
	}
}
