#ifndef _FUNCTION_H_
#define _FUNCTION_H_


#include <stdio.h>

char * toLowerCase(char * str);//���� ʱ�临�Ӷȸ�

void rotate_help(int *left, int *right);//��ת����
void rotate1(int* nums, int numsSize, int k); //������ת�����������

int searchInsert(int* nums, int numsSize, int target);//��������λ��

int removeElement(int* nums, int numsSize, int val);//�Ƴ�val��������Ŀ
#endif