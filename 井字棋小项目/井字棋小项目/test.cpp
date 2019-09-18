#include "text.h"
#include <stdlib.h>
#include <time.h>
/*********************
�������ܣ���ӡ�˵�
����ֵ����
���ֵ����
*********************/
void menu()
{
	printf("**********   0.exit    **********\n");
	printf("**********   1.play    **********\n");
	printf("*********************************\n");
}
/**********************************
�������ܣ���ʼ������
����ֵ��һ����ά���顢�С��С����õĳ�ֵ
���ֵ����
**********************************/
void InitBoard(char board[][ROW], int row, int col,int set)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}
/*****************************
��������;��ӡ����
����ֵ��������ʼ���Ķ�ά���顢�С���
���ֵ����
******************************/
void ShowBoard(char board[][ROW], int row, int col)
{
	int i = 0,j=0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%c  ", board[i][j]);
			if (j<row-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row-1)
		{
			for (j = 0; j < row; j++)
			{
				printf("---");
				if (j < row - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
/*******************
�������ܣ���������Ϸ����Ҫ���к���
����ֵ����
���ֵ����
*******************/
void game()
{
	char ret;
	int num=0;
	char board[ROW][COL] = { 0 };
	InitBoard( board, ROW, ROW, ' ');
	ShowBoard(board, ROW, COL);
	while (1)
	{
		
		PlayerMove( board, ROW, COL);
		printf("����ƶ���\n");
		ShowBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		num=IsFull( board, ROW, COL);
		if (num == 1)
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		printf("�����ƶ���\n");
		ShowBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		num = IsFull(board, ROW, COL);
		if (num == 1)
		{
			break;
		}
	}
	if (num == 1)
	{
		printf("��Ϸ������ƽ��\n");
	}
	if (ret == '0')
	{
		printf("������QAQ\n");
	}
	else
	{
		printf("��Ӯ��QWQ\n");
	}
}
/********************************
�������ܣ��ж��Ƿ���Ӯ
����ֵ����ʼ�����Ķ�ά���顢����
���ֵ��'O'||'X'||' '
*********************************/
char IsWin(char board[][ROW], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]
			&&board[i][0]!=' ')//�жϺ���
		{
			return board[i][0];
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]
			&&board[0][i]!=' ')//�ж�����
		{
			return board[0][i];
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
			&& board[0][0] != ' ')//�ж϶Խ���
		{
			return board[0][0];
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]
			&& board[0][2] != ' ')//�ж϶Խ���
		{
			return board[0][2];
		}
	}
	return ' ';
}
/***********************
�������ܣ������ƶ�
����ֵ����ʼ���Ķ�ά����
���ֵ����
************************/
void ComputerMove(char board[][ROW], int row, int col)
{
	srand((unsigned int)time(NULL)); //��������Ӳ���
	while (1)
	{
		int x = 0, y = 0;
		x = rand() % row;    //���������
		y = rand() % row;   
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
}
/**********************
�������ܣ�����ƶ�
����ֵ����ʼ���Ķ�ά���飬�У���
���ֵ����
***********************/
void PlayerMove(char board[][ROW],int row,int col)
{
	int x, y;
	printf("�����������꣺(x��y),1-3\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if ((x == 1 || x == 2 || x == 3) && (y == 1 || y == 2 || y == 3))
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = 'X';
				break;
			}
			else
			{
				printf("��������Ѿ�ռ���ˣ�����������\n");
			}
		}
		else
		{
			printf("����������������ȷ����\n");
		}
	}
}
/**********************
�������ܣ��ж������Ƿ�����
����ֵ����ʼ���Ķ�ά���顢�С���
���ֵ��0��1,0����û������1��������
***********************/
static int IsFull(char board[][ROW], int row, int col)
{
	int i = 0, j = 0;
	for (; i < row; i++)
	{
		for (; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
				break;
			}
		}
	}
	return 1;
}
