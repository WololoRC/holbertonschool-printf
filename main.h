#ifndef main_h
#define main_h

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 *struct frmt - This is a struct to call printf functions by format i.e "%s"
 *
 *@type: Format specifier
 *@f: Function pointer
 */
typedef struct frmt
{
	char *type;
	int (*f)();
} frmt;

int s_string(va_list aValue);
int c_char(va_list aValue);
int _printf(const char * const format, ...);
void print_format(char c);
int _putchar(char c);
int checkForChar(int);
int getSize(long int);
void prInteger(int *, int);
void prCharacter(char);
int prInt(long int num);
int get_value(va_list aValue);
int nothing(void);

#endif
