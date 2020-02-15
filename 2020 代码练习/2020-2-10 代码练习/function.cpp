#include "function.h"
/*
函数功能：将一串字符中的大写字母转换为小写
输入值：字符指针
返回值：字符指针
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
函数功能：右旋
时间复杂度高
*/
void rotate(int* nums, int numsSize, int k){
	if (nums == NULL || numsSize == 1)
		return;
	k = k%numsSize;   //化简为最小的翻转次数
	int tmp;
	int i = 0;
	while (k--)  //一共进行k次
	{
		tmp = nums[numsSize - 1];  //记录此次翻转的值
		for (i = numsSize - 1; i >0; i--) 
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = tmp;   //完成翻转
	}
}
/*
函数功能：旋转函数
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
函数功能：借助旋转函数完成右旋
时间复杂度低
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
函数功能：
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
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
移除val并返回数目
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
/*
函数功能：判断回文数
*/
bool isPalindrome(int x)
{
	if (x == 0)
		return true;
	if (x<0 || x % 10 == 0)
		return false;
	long long num = x, tmp = 0;//避免溢出

	//逆置一个输
	while (num != 0)
	{
		tmp = tmp * 10 + num % 10;
		num /= 10;
	}
	if (tmp == x)
		return true;
	else
		return false;
}
/*
函数功能：得到最后一个单词的长度
*/
int lengthOfLastWord(char * s)
{
	int length = strlen(s);//得到数组长度
	int i, count = 0;
	while (length>0 && s[length - 1] == ' ')//排除末尾是空格的情况
		length--;
	for (i = length - 1; i>-1; i--)
	{
		if (s[i] != ' ')
			count++;
		else
			return count;
	}
	return count;
}