#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;
	char a = 'a';

	a--;
	while (a++ < 'z')
		_printf("Ascii: %d | Char: %c - Example: %s%c %s%c %s%c %s%c %s%c\n ", a, a, "hah", a, "heh", a, "hih", a, "hoh", a, "huh", a);
	a = 'A';
	a--;
	while (a++ < 'Z')
		_printf("Ascii: %d | Char: %c - Example: %s%c %s%c %s%c %s%c %s%c\n ", a, a, "hah", a, "heh", a, "hih", a, "hoh", a, "huh", a);

	return (0);
}
