#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
//初始化   头结点
void InitList(Plist plist)
{
	if (plist == NULL)
	{
		return;
	}
	plist->next = NULL;
}

//得到一个节点  malloc 用来动态开辟内存的
Node * GetNode(int val)
{
	Node *pGet = (Node *)malloc(sizeof(Node));
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}
//头插法   
void InsertHead(Plist plist, int val)
{
	Node *pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
}
//尾插法
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

//得到长度
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

//打印函数
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
Node *LastKNode(Plist plist, int num)   //求倒数第N个节点
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


