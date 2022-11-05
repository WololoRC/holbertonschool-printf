#ifndef main_h
#define main_h

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct frmt
{
	char *type;
	void (*f)();
} frmt;   

void s_string(va_list aValue);
void c_char(va_list aValue);
void _printf(const char * const format, ...);
void print_format(char c);
int _putchar(char c);

#endif
