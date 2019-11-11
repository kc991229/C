#include "Function.h"
int main()
{
	char p[] = "deabc";
	char q[] = "abcde";
	int count = 0;
	count = judge_fun1(q, p);
	printf("%d", count);
	return 0;
}