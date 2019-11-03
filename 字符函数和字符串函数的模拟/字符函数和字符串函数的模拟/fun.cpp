#include "fun.h"
/******************************
�������ܣ������ַ������Ⱥ���
��ڲ������ַ���ָ��
����ֵ������������
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
�������ܣ������ַ������Ⱥ���(�ݹ�д��)
��ڲ������ַ���ָ��
����ֵ�������õ�������
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
�������ܣ��ַ�����������
��ڲ�����Ŀ���ַ�����ԭ�ַ���
����ֵ��Ŀ���ַ
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
�������ܣ��ַ�����������,,���趨��Ŀ
��ڲ�����Ŀ���ַ�����ԭ�ַ���
����ֵ��Ŀ���ַ
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
�������ܣ��ַ���׷��
��ڲ�����Ŀ���ַ�����ԭ�ַ���
����ֵ��Ŀ���ַ
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
�������ܣ��ַ���׷��,���趨��Ŀ
��ڲ�����Ŀ���ַ�����ԭ�ַ���
����ֵ��Ŀ���ַ
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
�������ܣ��ַ����Ƚ�
��ڲ��������������޸ĵ��ַ���
����ֵ��0��1��-1
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
�������ܣ��ַ����Ƚ�,���趨��Ŀ
��ڲ��������������޸ĵ��ַ���
����ֵ��0��1��-1
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
�������ܣ�Ѱ���ַ���2���ַ���1�ĵ�ַ
��ڲ��������������޸ĵ��ַ���
����ֵ��һ����ַ
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
�������ܣ���������
��ڲ�����һ�����޸ġ�һ�������޸ĵ�ָ�롢����
����ֵ��һ����ַ
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
�������ܣ����ݸ�������Ŀ�������
��ڲ�����һ�����޸ġ�һ�������޸ĵ�ָ�롢��������
����ֵ��һ����ַ
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