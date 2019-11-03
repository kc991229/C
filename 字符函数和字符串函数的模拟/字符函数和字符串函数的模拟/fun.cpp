#include "fun.h"
/******************************
函数功能：测量字符串长度函数
入口参数：字符串指针
返回值：测量的数字
*******************************/
unsigned int my_strlen(const char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
/******************************
函数功能：测量字符串长度函数(递归写法)
入口参数：字符串指针
返回值：测量得到的数字
*******************************/
unsigned int my_strlen1(const char *str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + my_strlen1(str + 1);
}
/******************************
函数功能：字符串拷贝函数
入口参数：目标字符串和原字符串
返回值：目标地址
*******************************/
char* my_strcpy(char *destination, const char* source)
{
	char* ret = destination;
	assert(source != NULL);
	assert(destination != NULL);
	while ((*destination++ = *source++) != '\0')
	{
		;
	}
	return ret;
}
/******************************
函数功能：字符串拷贝函数,,可设定数目
入口参数：目标字符串和原字符串
返回值：目标地址
*******************************/
char* my_strncpy(char* destination, const char* source, size_t count)
{
	char* ret = destination;
	assert(destination);
	assert(source);
	while (count--)
	{
		*destination = *source;
		destination++;
		source++;
	}
	return ret;
}
/******************************
函数功能：字符串追加
入口参数：目标字符串和原字符串
返回值：目标地址
*******************************/
char* my_strcat(char* destination, const char* source)
{
	char* ret = destination;
	assert(source != NULL);
	assert(source != NULL);
	while (*destination != 0)
	{
		destination++;
	}
	while ((*destination++ = *source++) != '\0')
	{
		;
	}
	return ret;
}
/******************************
函数功能：字符串追加,可设定数目
入口参数：目标字符串和原字符串
返回值：目标地址
*******************************/
char* my_strncat(char* destination, const char* source, size_t count)
{
	char* ret = destination;
	assert(destination);
	assert(source);
	while (*destination != '\0')
	{
		destination++;
	}
	while (count--)
	{
		*destination = *source;
		destination++;
		source++;
	}
	return ret;
}
/******************************
函数功能：字符串比较
入口参数：两个不可修改的字符串
返回值：0、1、-1
*******************************/
int my_strcmp(const char* str1, const char* str2)
{
	int count = 0;
	assert(str1 != NULL);
	assert(str2 != NULL);
	while ((*str1) && (*str2) && (!(count = *(unsigned int*)str1 - *(unsigned int*)str2)))
	{
		str1++;
		str2++;
	}
	if (count > 0)
		return 1;
	else if (count < 0)
		return -1;
	else
		return 0;
}
/******************************
函数功能：字符串比较,可设定数目
入口参数：两个不可修改的字符串
返回值：0、1、-1
*******************************/
int my_strncmp(const char* str1, const char* str2, size_t count)
{
	int num = 0;
	assert(str1);
	assert(str2);
	while ((*str1) && (*str2) && count && (!(num = *(unsigned char*)str1 - *(unsigned char*)str2)))
	{
		str1++;
		str2++;
		count--;
	}
	if (num > 0)
		return 1;
	else if (num < 0)
		return -1;
	else
		return 0;
}
/******************************
函数功能：寻找字符串2在字符串1的地址
入口参数：两个不可修改的字符串
返回值：一个地址
*******************************/
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	char* cp = (char*)str1;
	char* sub = (char*)str2;
	char* s1 = NULL;
	if (*str2 == '\0')
		return NULL;
	while (*cp)
	{
		s1 = cp;
		sub = (char*)str2;
		while (sub&&s1 && (*sub == *s1))
		{
			sub++;
			s1++;
		}
		if (*sub == '\0')
			return cp;
		cp++;
	}
}
/******************************
函数功能：拷贝函数
入口参数：一个可修改、一个不可修改的指针、长度
返回值：一个地址
*******************************/
void* my_memcpy(void* dest, const void* source, unsigned int count)
{
	void* ret = dest;
	assert(dest);
	assert(source);
	while (count--)
	{
		*(char*)dest = *(char*)source;
		dest = (char*)dest + 1;
		source = (char*)source + 1;
	}
	return ret;
}
/******************************
函数功能：兼容覆盖区域的拷贝函数
入口参数：一个可修改、一个不可修改的指针、拷贝长度
返回值：一个地址
*******************************/
void* my_memmove(void* dest, const char* src, unsigned int count)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	if (dest < src || (char*)dest >= ((char*)src + count))
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dest = (char*)dest + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}