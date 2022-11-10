#include "main.h"
/**
 *_printf - printf main function
 *
 *@format: String argument
 * Return: lenght ((cnt + cnt2) - 2)
 */
int _printf(const char * const format, ...)
{
	int cnt, cnt_t, cnt_ret, valRet;
	va_list args;
	frmt typez[] = {
		{ "i", prInt },
		{ "d", prInt },
		{ "c", c_char },
		{ "s", s_string },
		{ "%", modMod },
		{NULL, nothing}
	};

		if (!format)
			return (-1);
	cnt_ret = 0;
	cnt = cnt_t = 0;
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
			valRet = valCheck(format[cnt]);
			if (valRet == 1)
			{
				for (cnt_t = 0; typez[cnt_t].type != NULL; cnt_t++)
					if (format[cnt] == (*typez[cnt_t].type))
						cnt_ret += typez[cnt_t].f(args);
			}
			else
				cnt_ret += valRet;
		}
		cnt++;
	}
	va_end(args);
	return (cnt_ret);
}
