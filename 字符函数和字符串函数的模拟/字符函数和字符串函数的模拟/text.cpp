#include "fun.h"
#include <string.h>
int main()
{
	char *str = "This is a \0 simple string";
	char q[40];
	my_memcpy(q, str, 25);
	puts(q);
	return 0;
}