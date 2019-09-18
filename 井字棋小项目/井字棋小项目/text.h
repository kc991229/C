#define _CRT_SECURE_NO_WARNINGS 1
#ifndef  __TEXT__H_
#define  __TEXT__H_

#define ROW 3     //宏定义的棋盘行数
#define COL 3     //宏定义的棋盘列数
#include<stdio.h>

void menu();  //打印菜单函数
void InitBoard(char board[][ROW], int row, int col, int set);  //初始化棋盘函数
void ShowBoard(char board[][ROW], int row, int col);//打印棋盘函数
char IsWin(char board[][ROW], int row, int col); //判断输赢函数
void ComputerMove(char board[][ROW], int row, int col);//电脑移动函数
void PlayerMove(char board[][ROW], int row, int col); //玩家移动函数
static int IsFull(char board[][ROW], int row, int col); //判断棋盘是否以满函数
void game();//游戏进行主要函数
void game();
#endif
