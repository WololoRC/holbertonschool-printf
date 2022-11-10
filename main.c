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

	len = _printf("%i - %i = %i\n", 1028, 2048, -1024);
	len2 = printf("%i - %i = %i\n", 1028, 2048, -1024);
	printf("_printf: %d\n printf: %d\n",len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
