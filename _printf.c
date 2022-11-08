#include "main.h"
/**
 *_printf - printf main function
 *
 *@format: String argument
 * Return: lenght ((cnt + cnt2) - 2)
 */
int _printf(const char * const format, ...)
{
	unsigned int cnt, cnt_t, cnt2;
	va_list args;

	frmt typez[] = {
		{ "i", prInt },
		{ "d", prInt },
		{ "c", c_char },
		{ "s", s_string },
		{NULL, nothing}
	};

	cnt = cnt_t = cnt2 = 0;
	va_start(args, format);

	while (format != NULL && format[cnt] != '\0')
	{
		if (format[cnt] != '%')
		{
			print_format(format[cnt]);
		}
		else
		{
			cnt++;
			if (format[cnt] == '%')
			{
				_putchar('%');
			}
			while (typez[cnt_t].type != NULL)
			{
				if (format[cnt] == (*typez[cnt_t].type))
				{
					cnt2 = typez[cnt_t].f(args);
				}
				cnt_t++;
			}
		}
		cnt++;
	}
	va_end(args);
	return ((cnt + cnt2) - 2);
}
