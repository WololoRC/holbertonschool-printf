#include <unistd.c>
void prueba(void *s)
{
	return (write(1, s, sizeof(int)));
}
