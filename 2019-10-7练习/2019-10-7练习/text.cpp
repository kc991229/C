#include <stdio.h>
#include <windows.h> 
/*��С�˵��ж�
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
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}
*/

//����Խ������
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}

//����������%u��10���������������0���ǲ�1ȡ������λ
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

//Խ�����⣬����-1��ʱ��Ϊ1111 1111 1111 1111 1111 1111 1111 1111����Ϊ���޷��ţ�ֱ����ΪԴ��
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

//ʹ�û�Բ��
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

//��Բ�Ĺ�������Բ����������Χ
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