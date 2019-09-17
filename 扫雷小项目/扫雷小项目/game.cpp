#include "game.h"
int row = 0, col = 0;
/**********************
函数功能：打印菜单
输入值：无
输出值：无
***********************/
void menu()
{
	printf("**************1 play****************\n");
	printf("**************0 exit****************\n");
}
/**********************
函数功能：游戏主要进行函数
输入值：无
输出值：无
***********************/
void game()
{
	int result=0,num=0;
	char board[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };
	InitBoard(board, mine, ROWS, COLS);
	SetMine(mine, ROW, COL, MINE_NUM);
	while (1)
	{
		Show(board, ROW, COL);
		result=FindMine(mine, board);
		if (result == 1)
		{
			break;
		}
		else
		{
			num=GetMineCount(mine, row, col);
			board[row][col] = num+'0';  //字符1-字符0=数字1
		}
	}
	if (result == 1)
	{
		printf("你被炸死了，难受\n");
		Show(board, ROW, COL);
	}
}
/********************
函数功能：初始化雷盘
输入值：一个二维数组、行、列
输出值：无
*********************/
void InitBoard(char board[][COLS],char mine[][COLS],int row,int col)
{
	int i = 0 ,j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = '*';
			mine[i][j] = '*';
		}
	}

}
/***********************
函数功能：打印雷盘
输入值：初始化过的二维数组、行、列
输出值：无
************************/
void Show(char board[][ROWS],int row,int col)
{
	int i = 1, j = 1;
	for (i=1; i <= row; i++)
	{
		for (j=1; j <= col; j++)
		{
			printf("%-2c", board[i][j]);
		}
		printf("\n");
	}
}
/********************
函数功能：设置雷
输入值：初始化过的二维数组
输出值：无
*********************/
void SetMine( char mine[][COLS], int row, int col, int num)
{
	int x = 0, y = 0,count=0;
	int i = 1,arr[100],brr[100];
	srand((unsigned int)time(NULL));
	x = rand() % ROW + 1;
	y = rand() % COL + 1;
	mine[x][y] = 'X';
	arr[0] = x, brr[0] = y;           //保证设置的雷不会重叠
	while (i < num)
	{
		do
		{
			x = rand() % ROW + 1;
			y = rand() % COL + 1;
		} while (count=Set_Assist( i,arr, brr, x,y));
		mine[x][y] = 'X';
		arr[i] = x; brr[i] = y;
		i++;
	}
}
/************************
函数功能：判断该点周围的雷数
输入值：初始化过的二维数组、行、列
输出值：无
*************************/
int GetMineCount(char mine[][ROWS], int x, int y)
{
	int count = 0;
	int i = x + 1, j = y + 1;
	for (x = x - 1; x<=i; x++)
	{
		for (y = y - 1; y <=j; y++)
		{
			if (mine[x][y] == 'X')
			{
				count++;
			}
		}
	}
	return count ;
}
/****************
函数功能：玩家进行扫雷
输入值：初始化过的二维数组、行、列
输出值：无
*****************/
int FindMine(char mine[][ROWS],char board[][ROWS] )
{
		int count = 0;
		printf("请输入坐标：");
		scanf("%d%d", &row,&col);
		if (mine[row][col] == 'X')
		{
			board[row][col] = 'X';
			return 1;
		}
		else
		{
			return 0;
		}
}
/*******************************
函数功能：设置雷的辅助函数
输入值：当下的i、两个数组、当下x、y的值
输出值：0或1
********************************/
int Set_Assist(int i,int arr[],int brr[],int x,int y) 
{
	int j = 0;
	for (j = 0; j < i; j++)
	{
		if (arr[j] == x&&brr[j] == y)
		{
			return 1;
			break;
		}
    }
	return 0;
}
