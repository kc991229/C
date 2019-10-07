#include <stdio.h>
#include <windows.h> 
/*大小端的判断
int check_sys()
{
	int i = 1;
	return (*(char *)&i);
}
int check_sys1()
{
	union
	{
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
*/

//数据越界问题
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}

//整形提升，%u以10进制整形输出，补0还是补1取决符号位
//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	return 0;
//}
//int main()
//{
//	char a = 128;
//	printf("%u\n", a);
//	return 0;
//}

//越界问题，当到-1的时候，为1111 1111 1111 1111 1111 1111 1111 1111，因为是无符号，直接作为源码
//int main()
//{
//	unsigned int i;
//	
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(500);
//	}
//}

//使用画圆法
//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i<1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));
//	return 0;
//}

//画圆的规则：整个圆代表整个范围
//unsigned char i = 0;
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("hello world\n");
//		Sleep(100);
//	}
//	return 0;
//}