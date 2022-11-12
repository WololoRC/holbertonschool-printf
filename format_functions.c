#include "main.h"
/**
 *nothing - prints nothing
 *
 * Return: empty char
 */
int nothing(void)
{
	_putchar(0);
	return (-1);
	/* in case of NULL prints nothing */
}
/**
 *s_string - Print char by char a string with the expetion of '\0'
 *
 *@aValue: String argument passed by the printf main function.
 * Return: lenght(cnt)
 */
int s_string(va_list aValue)
{
	char *str = va_arg(aValue, char *);
	int cnt, fail;

	cnt = 0;
	fail = 0;

	if (!str)
	{
		str = "(null)";
		fail = 0;
	}

	while (str[cnt] != '\0')
	{
		_putchar(str[cnt]);
		cnt++;
	}

	return ((cnt + fail));
}
/**
 *c_char - Print chars
 *
 *@aValue: Char arument passed by the printf main function
 * Return: lenght
 */
int c_char(va_list aValue)
{
	int cnt;

	cnt = 1;

	_putchar(va_arg(aValue, int));

	return (cnt);
}
/**
 *print_format - Print char by char the format string argument
 *
 *@c: Char
 */
void print_format(char c)
{
	write(1, &c, 1);
}
/**
 *_putchar - Holberton classic purtchar
 *@c: char
 * Return: the nBytes of the content of &c in the standard output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
