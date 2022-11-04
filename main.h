#ifndef main_h
#define main_h

typedef struct print_format
{
	char *frmt
	int (*f)(char *str);

} format;

int (*get_format(char *str))(*void);
int s_string(char *str);
int c_char(char *c);
void prueba(void *s);

#endif
