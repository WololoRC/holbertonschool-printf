#include "main.h"
int (*get_format(char *str))(*void)
{
	format srch[] = {

	{"s", s_string},
	{"c", c_char},
	
	};

	int cnt = 0;

	while (srch[cnt].frmt)
	{
		if (*(srch[cnt].frmt == *str))
		{
			return (srch[cnt].f);
		}
		
		cnt++;
	}

	return (NULL);
}
