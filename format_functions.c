#include "main.h"

/**
 *nothing - prints nothing
 *
 * Return: empty char
 */
int nothing(void)
{
	return (_putchar(0));
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

	int cnt = 0;

	while (str[cnt] != '\0')
	{
		_putchar(str[cnt]);
		cnt++;
	}

	return (cnt);
}
/**
 *c_char - Print chars
 *
 *@aValue: Char arument passed by the printf main function
 * Return: lenght
 */
int c_char(va_list aValue)
{
	_putchar(va_arg(aValue, int));

	return (1);
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
 *_putchar - Holberton's classic purtchar
 *@c: char
 * Return: the nBytes of the contenct of &c in the standard output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putchart - in charge of writing 1 char to stdout
 *
 * @c: char to print
 */
int _putchart(int c)
{
        return (write(1, &c, 1));
}
