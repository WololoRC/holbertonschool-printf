#include "main.h"
/**
 *_printf - printf main function
 *
 *@format: String argument
 * Return: lenght ((cnt + cnt2) - 2)
 */
int _printf(const char * const format, ...)
{
	if (!format)
	{
		return (-1);
	}

	unsigned int cnt, cnt_t, cnt_ret;
	va_list args;
	frmt typez[] = {
		{ "i", prInt },
		{ "d", prInt },
		{ "c", c_char },
		{ "s", s_string },
		{ "%", modMod },
		{NULL, nothing}
	};
	cnt_ret = 0;
	cnt = cnt2 = cnt_t = 0;
	va_start(args, format);
	while (format != NULL && format[cnt])
	{
		if (format[cnt] != '%')
		{
			print_format(format[cnt]);
			cnt_ret++;
		}
		else
		{
			cnt++;
			for (cnt_t = 0, cnt2 = 0; typez[cnt_t].type != NULL; cnt_t++)
			{
				if (format[cnt] == (*typez[cnt_t].type))
				{
					cnt_ret += typez[cnt_t].f(args);
				}
			}
		}
		cnt++;
	}
	va_end(args);
	return (cnt_ret);
}
