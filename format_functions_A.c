#include "main.h"
/**
 * _putchart - in charge of writing 1 char to stdout
 *
 * @c: char to print
 *
 * Return: 1 byte
 */
int _putchart(int c)
{
	return (write(1, &c, 1));
}
/**
 *modMod - print '%' if the user putrs "%%"
 *
 * Return: 1 for lenght reassons
 */
int modMod(void)
{
	_putchar('%');

	return (1);
}
