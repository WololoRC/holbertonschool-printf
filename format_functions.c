#include "main.h"
/**
 *s_string - Print char by char a string with the expetion of '\0'
 *
 *@aValue: String argument passed by the printf main function.
 */
void s_string(va_list aValue)
{
	char *str = va_arg(aValue, char *);

	int cnt = 0;

	while (str[cnt] != '\0')
	{
		_putchar(str[cnt]);
		cnt++;
	}
}
/**
 *c_char - Print chars
 *
 *@aValue: Char arument passed by the printf main function
 */
void c_char(va_list aValue)
{
	_putchar(va_arg(aValue, int));
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
