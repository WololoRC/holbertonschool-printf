#include <unistd.h>
int s_string(char *str)
{
	int cnt = 0;

	while (str[cnt] != '\0' || str[cnt] != '%')
	{
		cnt++;
	}

	return (write(1, str, cnt));
}
/**
 *
 *
 *
 */
int c_char(char *c)
{
	return ((write(1, &c, 1 )));
}
