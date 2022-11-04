int _printf(const char *format, ...)
{
	int cnt = 0;
	char *s = NULL;

	va_list args;

	va_start(args, format);

	while (format[cnt] != '\0')
	{	
		s = format[cnt];

		c_char(s);

		if (format[cnt] == '%')
		{
			cnt += 1;
			s = format[cnt];
			*get_format(s, va_arg(args, char *));
		}
		
		cnt++;
	}

	return (0);	
}
