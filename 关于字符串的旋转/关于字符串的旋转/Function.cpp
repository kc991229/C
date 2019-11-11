#include "Function.h"
/*
函数功能：将一个字符串左旋k次
入口参数：一个字符串、字符串长度、左旋次数
返回值：无
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
函数功能：逆置字符串
入口参数：该字符串的头、尾
返回值：无
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
函数功能：左旋len次字符串(优质解)
入口参数：字符串、左旋次数、长度
返回值：无
*/
void rotating1(char* p, int num, int len)
{
	assert(p);
	reserve(p, p + num - 1);
	reserve(p + num, p + len - 2);
	reserve(p, p + len - 2);
}
/*
函数功能：判断一个字符串是否是另一个旋转而来(空间换时间)
入口参数：源字符串、比较的字符串
返回值：是为1，不是为0
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
函数功能：判断一个字符串是否是另一个旋转而来
入口参数：源字符串、比较的字符串
返回值：是为1，不是为0
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