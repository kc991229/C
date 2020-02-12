#include "function.h"


int main()
{
	int a = 10, b = 10;
	a = b = ++b;
	printf("%d %d", a,b);
	return 0;
}