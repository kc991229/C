#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
//��ʼ��   ͷ���
void InitList(Plist plist)
{
	if (plist == NULL)
	{
		return;
	}
	plist->next = NULL;
}

//�õ�һ���ڵ�  malloc ������̬�����ڴ��
Node * GetNode(int val)
{
	Node *pGet = (Node *)malloc(sizeof(Node));
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}
//ͷ�巨   
void InsertHead(Plist plist, int val)
{
	Node *pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
}
//β�巨
void InsertTail(Plist plist, int val)
{
	Node *pCur = plist;
	Node *pGet = GetNode(val);
	while (pCur->next != NULL)
	{
		pCur = pCur->next;
	}
	pCur->next = pGet;
}

//�õ�����
int GetLength(Plist plist)
{
	int count = 0;
	Node *pCur = plist->next;
	while (pCur != NULL)
	{
		count++;
		pCur = pCur->next;
	}
	return count;
}

//��ӡ����
void Show(Plist plist)
{
	Node *pCur = plist->next;

	while (pCur != NULL)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}
Node *LastKNode(Plist plist, int num)   //������N���ڵ�
{
	int i = 2;
	Node *p1 = plist->next;
	Node *p2 = p1->next;
	for (; i < num; i++)
	{
		if (p2->next != NULL)
		{
			p2 = p2->next;
		}
		else
			return NULL;
	}
	while (p2->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}


