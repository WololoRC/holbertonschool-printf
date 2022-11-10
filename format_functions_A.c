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
/**
 * valCheck - checks whether a char is valid or null for printing
 *
 * @chrz: value to be checked
 *
 * Return: 1 for true, 2 for erroneous char, -1 for error.
 */
int valCheck(char chrz)
{
	char comp[] = {'d', 'c', 's', '%'};
	int  cnt = 0;

	while (cnt < 4)
	{
		if (comp[cnt] == chrz)
			return (1);
		cnt++;
	}
	if (chrz)
	{
		_putchar('%');
		_putchar(chrz);
		return (2);
	}
	else
	return (-1);
}
