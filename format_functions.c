#include "main.h"
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
 *
 *
 *
 */
void c_char(va_list aValue)
{
	_putchar(va_arg(aValue, int));
}
/**
 *
 *
 *
 */
void print_format(char c)
{
	write(1, &c, 1);
}
/**
 *
 *
 *
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
