#include "text.h"
#include <stdlib.h>
#include <time.h>
/*********************
函数功能：打印菜单
输入值：无
输出值：无
*********************/
void menu()
{
	printf("**********   0.exit    **********\n");
	printf("**********   1.play    **********\n");
	printf("*********************************\n");
}
/**********************************
函数功能：初始化棋盘
输入值：一个二维数组、行、列、设置的初值
输出值：无
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
函数功能;打印棋盘
输入值：经过初始化的二维数组、行、列
输出值：无
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
函数功能：井字棋游戏的主要运行函数
输入值：无
输出值：无
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
		printf("玩家移动：\n");
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
		printf("电脑移动：\n");
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
		printf("游戏结束，平局\n");
	}
	if (ret == '0')
	{
		printf("您输了QAQ\n");
	}
	else
	{
		printf("您赢了QWQ\n");
	}
}
/********************************
函数功能：判断是否输赢
输入值：初始化过的二维数组、行列
输出值：'O'||'X'||' '
*********************************/
char IsWin(char board[][ROW], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]
			&&board[i][0]!=' ')//判断横行
		{
			return board[i][0];
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]
			&&board[0][i]!=' ')//判断竖行
		{
			return board[0][i];
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
			&& board[0][0] != ' ')//判断对角线
		{
			return board[0][0];
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]
			&& board[0][2] != ' ')//判断对角线
		{
			return board[0][2];
		}
	}
	return ' ';
}
/***********************
函数功能：电脑移动
输入值：初始化的二维数组
输出值：无
************************/
void ComputerMove(char board[][ROW], int row, int col)
{
	srand((unsigned int)time(NULL)); //随机数种子产生
	while (1)
	{
		int x = 0, y = 0;
		x = rand() % row;    //产生随机数
		y = rand() % row;   
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
}
/**********************
函数功能：玩家移动
输入值：初始化的二维数组，行，列
输出值：无
***********************/
void PlayerMove(char board[][ROW],int row,int col)
{
	int x, y;
	printf("请您输入坐标：(x，y),1-3\n");
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
				printf("这个坐标已经占过了，请重新输入\n");
			}
		}
		else
		{
			printf("输入有误，请输入正确坐标\n");
		}
	}
}
/**********************
函数功能：判断棋盘是否满了
输入值：初始化的二维数组、行、列
输出值：0或1,0代表没有满，1代表满了
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
