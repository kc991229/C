#ifndef _FUNCTION_H_
#define _FUNCTION_H_


#include <stdio.h>
#include <string.h>

char * toLowerCase(char * str);//右旋 时间复杂度高

void rotate_help(int *left, int *right);//旋转函数
void rotate1(int* nums, int numsSize, int k); //借助旋转函数完成右旋

int searchInsert(int* nums, int numsSize, int target);//搜索插入位置

int removeElement(int* nums, int numsSize, int val);//移除val并返回数目

bool isPalindrome(int x);//判断回文数

int lengthOfLastWord(char * s);//得到最后一个单词的长度
#endif