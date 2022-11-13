#include "main.h"
/**
 *_printf - printf main function
 *
 *@format: String argument
 * Return: lenght, if function fails return -1
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
	cnt = cnt_t = cnt_ret = valRet = 0;
	va_start(args, format);
	while (format != NULL && format[cnt])
	{
		if (format[cnt] != '%')
		{
			print_format(format[cnt]);
			cnt_ret++; /* @cnt_ret: counter for lenght return */
		}
		else if (format[cnt + 1]) /* format[cnt] memory check */
		{
			cnt++;
			valRet = valCheck(format[cnt]); /* @valRet: holds return of valCheck */
			if (valRet == 1)
			{
				for (cnt_t = 0; typez[cnt_t].type != NULL; cnt_t++)
					if (format[cnt] == (*typez[cnt_t].type)) /* @cnt_t: type counter */
						cnt_ret += typez[cnt_t].f(args);
			}
			else
				cnt_ret += valRet;
		}
		else
			return (-1);
		cnt++;
	}
	va_end(args);
	return (cnt_ret);
}
