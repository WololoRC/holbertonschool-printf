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
int _putchart(int c);
int prInt(va_list);
int checkForChar(int);
int getSize(long int);
void prInteger(int *, int, int);
void prCharacter(char);
int get_value(va_list aValue);
int nothing(void);
int modMod(void);
int valCheck(char charz);

#endif
