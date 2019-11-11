#include "Function.h"
/*
�������ܣ���һ���ַ�������k��
��ڲ�����һ���ַ������ַ������ȡ���������
����ֵ����
*/
void rotating(char *p, int len, int k)
{
	k = k%len;
	char tmp;
	int i = 0;
	while (k--)
	{
		tmp = p[0];
		for (i = 0; i < len - 1; i++)
		{
			p[i] = p[i + 1];
		}
		p[len - 2] = tmp;
	}
}
/*
�������ܣ������ַ���
��ڲ��������ַ�����ͷ��β
����ֵ����
*/
void reserve(char *start, char *end)
{
	while (start<end)
	{
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		start++;
		end--;
	}
}
/*
�������ܣ�����len���ַ���(���ʽ�)
��ڲ������ַ�������������������
����ֵ����
*/
void rotating1(char* p, int num, int len)
{
	assert(p);
	reserve(p, p + num - 1);
	reserve(p + num, p + len - 2);
	reserve(p, p + len - 2);
}
/*
�������ܣ��ж�һ���ַ����Ƿ�����һ����ת����(�ռ任ʱ��)
��ڲ�����Դ�ַ������Ƚϵ��ַ���
����ֵ����Ϊ1������Ϊ0
*/
int judge_fun(const char* src, const char* dest)
{
	char* p = (char*)malloc(strlen(src) + strlen(src) + 1);
	strcpy(p, src);
	strcat(p, src);
	if (strstr(p, dest) == NULL)
	{
		return 0;
	}
	else
		return 1;
}
/*
�������ܣ��ж�һ���ַ����Ƿ�����һ����ת����
��ڲ�����Դ�ַ������Ƚϵ��ַ���
����ֵ����Ϊ1������Ϊ0
*/
int judge_fun1(char* src, char* dest)
{
	int len = strlen(src);
	char str;
	for (int i = 0; i < len - 1; i++)
	{
		str = *src;
		for (int j = 0; j < len - 1; j++)
		{
			*src = *(src + 1);
			src++;
		}
		*src = str;
		src = src - len + 1;
		if (!(strcmp(dest, src)))
		{
			return 1;
		}
	}
	return 0;
}