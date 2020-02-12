#include "function.h"
/*
�������ܣ���һ���ַ��еĴ�д��ĸת��ΪСд
����ֵ���ַ�ָ��
����ֵ���ַ�ָ��
*/
char* toLowerCase(char * str)
{
	if (str == NULL)
	{
		return str;
	}
	char* temp = str;
	while (*str != '\0')
	{
		if (*str >= 65 && *str <= 90)
		{
			*str += 32;
		}
		str++;
	}
	return temp;
}
/*
�������ܣ�����
ʱ�临�Ӷȸ�
*/
void rotate(int* nums, int numsSize, int k){
	if (nums == NULL || numsSize == 1)
		return;
	k = k%numsSize;   //����Ϊ��С�ķ�ת����
	int tmp;
	int i = 0;
	while (k--)  //һ������k��
	{
		tmp = nums[numsSize - 1];  //��¼�˴η�ת��ֵ
		for (i = numsSize - 1; i >0; i--) 
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = tmp;   //��ɷ�ת
	}
}
/*
�������ܣ���ת����
*/
void rotate_help(int *left, int *right)
{
	while (left<right)
	{
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
		left++;
		right--;
	}
}
/*
�������ܣ�������ת�����������
ʱ�临�Ӷȵ�
*/
void rotate1(int* nums, int numsSize, int k)
{
	if (nums == NULL || numsSize == 1)
	{
		return;
	}
	k = k%numsSize;
	rotate_help(nums, nums + numsSize - k - 1);
	rotate_help(nums + numsSize - k, nums + numsSize - 1);
	rotate_help(nums, nums + numsSize - 1);
}
/*
�������ܣ�
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
*/
int searchInsert(int* nums, int numsSize, int target)
{
	if (nums == NULL)
	{
		return 0;
	}
	int count = 0, i = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (target <= nums[i])
		{
			break;
		}
	}
	return i;
}
/*
�Ƴ�val��������Ŀ
*/
int removeElement(int* nums, int numsSize, int val)
{
	if (nums == NULL || numsSize == 0)
	{
		return 0;
	}
	int i = 0, j = numsSize - 1;
	for (i = 0; i<j; i++)
	{
		if (nums[i] == val)
		{
			for (; j>i; j--)
			{
				if (nums[j] != val)
				{
					break;
				}
			}
			if (j != i)
			{
				nums[i] ^= nums[j];
				nums[j] ^= nums[i];
				nums[i] ^= nums[j];
				j--;
			}
			else
			{
				break;
			}
		}
	}
	if (nums[i] == val)
	{
		return i;
	}
	else
	{
		return i + 1;
	}
}