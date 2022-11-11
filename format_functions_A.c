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
 * modMod - prints '%' when the user inputs "%%"
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
{ /** comp is a list of possible valid chars to check */
	char comp[] = {'d', 'c', 's', '%', 'i'};
	int  cnt = 0;

	while (cnt < 5)
	{ /** If the given char is valid, we return true */
		if (comp[cnt] == chrz)
			return (1);
		cnt++;
	}
	if (chrz) /** if the given char is not null and invalid we print it */
	{
		_putchar('%');
		_putchar(chrz);
		return (2);
	} /** if the char is null, return error */
	else
	return (-1);
}
